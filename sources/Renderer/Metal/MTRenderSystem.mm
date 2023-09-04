/*
 * MTRenderSystem.mm
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#include "MTRenderSystem.h"
#include "../CheckedCast.h"
#include "../TextureUtils.h"
#include "../../Core/CoreUtils.h"
#include "../../Core/Exception.h"
#include "../../Core/Vendor.h"
#include "Command/MTDirectCommandBuffer.h"
#include "Command/MTMultiSubmitCommandBuffer.h"
#include "MTFeatureSet.h"
#include "MTTypes.h"
#include "RenderState/MTGraphicsPSO.h"
#include "RenderState/MTComputePSO.h"
#include "RenderState/MTBuiltinPSOFactory.h"
#include <LLGL/ImageFlags.h>
#include <LLGL/Platform/Platform.h>
#include <LLGL/Backend/Metal/NativeHandle.h>
#include <AvailabilityMacros.h>


namespace LLGL
{


/* ----- Common ----- */

MTRenderSystem::MTRenderSystem()
{
    CreateDeviceResources();
    QueryRenderingCaps();
}

MTRenderSystem::~MTRenderSystem()
{
    [device_ release];
}

/* ----- Swap-chain ----- */

SwapChain* MTRenderSystem::CreateSwapChain(const SwapChainDescriptor& swapChainDesc, const std::shared_ptr<Surface>& surface)
{
    return swapChains_.emplace<MTSwapChain>(device_, swapChainDesc, surface);
}

void MTRenderSystem::Release(SwapChain& swapChain)
{
    swapChains_.erase(&swapChain);
}

/* ----- Command queues ----- */

CommandQueue* MTRenderSystem::GetCommandQueue()
{
    return commandQueue_.get();
}

/* ----- Command buffers ----- */

CommandBuffer* MTRenderSystem::CreateCommandBuffer(const CommandBufferDescriptor& commandBufferDesc)
{
    if ((commandBufferDesc.flags & (CommandBufferFlags::MultiSubmit | CommandBufferFlags::Secondary)) != 0)
        return commandBuffers_.emplace<MTMultiSubmitCommandBuffer>(device_, commandBufferDesc);
    else
        return commandBuffers_.emplace<MTDirectCommandBuffer>(device_, *commandQueue_, commandBufferDesc);
}

void MTRenderSystem::Release(CommandBuffer& commandBuffer)
{
    commandBuffers_.erase(&commandBuffer);
}

/* ----- Buffers ------ */

Buffer* MTRenderSystem::CreateBuffer(const BufferDescriptor& bufferDesc, const void* initialData)
{
    RenderSystem::AssertCreateBuffer(bufferDesc, device_.maxBufferLength);
    return buffers_.emplace<MTBuffer>(device_, bufferDesc, initialData);
}

BufferArray* MTRenderSystem::CreateBufferArray(std::uint32_t numBuffers, Buffer* const * bufferArray)
{
    RenderSystem::AssertCreateBufferArray(numBuffers, bufferArray);
    return bufferArrays_.emplace<MTBufferArray>(numBuffers, bufferArray);
}

void MTRenderSystem::Release(Buffer& buffer)
{
    buffers_.erase(&buffer);
}

void MTRenderSystem::Release(BufferArray& bufferArray)
{
    bufferArrays_.erase(&bufferArray);
}

void MTRenderSystem::WriteBuffer(Buffer& buffer, std::uint64_t offset, const void* data, std::uint64_t dataSize)
{
    commandQueue_->WaitIdle();
    auto& bufferMT = LLGL_CAST(MTBuffer&, buffer);
    bufferMT.Write(static_cast<NSUInteger>(offset), data, static_cast<NSUInteger>(dataSize));
}

void MTRenderSystem::ReadBuffer(Buffer& buffer, std::uint64_t offset, void* data, std::uint64_t dataSize)
{
    commandQueue_->WaitIdle();
    auto& bufferMT = LLGL_CAST(MTBuffer&, buffer);
    bufferMT.Read(static_cast<NSUInteger>(offset), data, static_cast<NSUInteger>(dataSize));
}

void* MTRenderSystem::MapBuffer(Buffer& buffer, const CPUAccess access)
{
    commandQueue_->WaitIdle();
    auto& bufferMT = LLGL_CAST(MTBuffer&, buffer);
    return bufferMT.Map(access);
}

void* MTRenderSystem::MapBuffer(Buffer& buffer, const CPUAccess access, std::uint64_t offset, std::uint64_t length)
{
    commandQueue_->WaitIdle();
    auto& bufferMT = LLGL_CAST(MTBuffer&, buffer);
    return bufferMT.Map(access, static_cast<NSUInteger>(offset), static_cast<NSUInteger>(length));
}

void MTRenderSystem::UnmapBuffer(Buffer& buffer)
{
    auto& bufferMT = LLGL_CAST(MTBuffer&, buffer);
    return bufferMT.Unmap();
}

/* ----- Textures ----- */

Texture* MTRenderSystem::CreateTexture(const TextureDescriptor& textureDesc, const SrcImageDescriptor* imageDesc)
{
    auto* textureMT = textures_.emplace<MTTexture>(device_, textureDesc);

    if (imageDesc)
    {
        textureMT->WriteRegion(
            //TextureRegion{ Offset3D{ 0, 0, 0 }, textureMT->GetMipExtent(0) },
            TextureRegion
            {
                TextureSubresource{ 0, textureDesc.arrayLayers, 0, 1 },
                Offset3D{ 0, 0, 0 },
                textureDesc.extent
            },
            *imageDesc
        );

        /* Generate MIP-maps if enabled */
        if (MustGenerateMipsOnCreate(textureDesc) && textureDesc.format != Format::A8UNorm)
        {
            id<MTLCommandBuffer> cmdBuffer = [commandQueue_->GetNative() commandBuffer];
            {
                id<MTLBlitCommandEncoder> blitCmdEncoder = [cmdBuffer blitCommandEncoder];
                [blitCmdEncoder generateMipmapsForTexture:textureMT->GetNative()];
                [blitCmdEncoder endEncoding];
            }
            [cmdBuffer commit];
        }
    }

    return textureMT;
}

void MTRenderSystem::Release(Texture& texture)
{
    textures_.erase(&texture);
}

void MTRenderSystem::WriteTexture(Texture& texture, const TextureRegion& textureRegion, const SrcImageDescriptor& imageDesc)
{
    commandQueue_->WaitIdle();
    auto& textureMT = LLGL_CAST(MTTexture&, texture);
    textureMT.WriteRegion(textureRegion, imageDesc);
}

void MTRenderSystem::ReadTexture(Texture& texture, const TextureRegion& textureRegion, const DstImageDescriptor& imageDesc)
{
    commandQueue_->WaitIdle();
    auto& textureMT = LLGL_CAST(MTTexture&, texture);
    textureMT.ReadRegion(textureRegion, imageDesc, commandQueue_->GetNative(), intermediateBuffer_.get());
}

/* ----- Sampler States ---- */

Sampler* MTRenderSystem::CreateSampler(const SamplerDescriptor& samplerDesc)
{
    return samplers_.emplace<MTSampler>(device_, samplerDesc);
}

void MTRenderSystem::Release(Sampler& sampler)
{
    samplers_.erase(&sampler);
}

/* ----- Resource Heaps ----- */

ResourceHeap* MTRenderSystem::CreateResourceHeap(const ResourceHeapDescriptor& resourceHeapDesc, const ArrayView<ResourceViewDescriptor>& initialResourceViews)
{
    return resourceHeaps_.emplace<MTResourceHeap>(resourceHeapDesc, initialResourceViews);
}

void MTRenderSystem::Release(ResourceHeap& resourceHeap)
{
    resourceHeaps_.erase(&resourceHeap);
}

std::uint32_t MTRenderSystem::WriteResourceHeap(ResourceHeap& resourceHeap, std::uint32_t firstDescriptor, const ArrayView<ResourceViewDescriptor>& resourceViews)
{
    auto& resourceHeapMT = LLGL_CAST(MTResourceHeap&, resourceHeap);
    return resourceHeapMT.WriteResourceViews(firstDescriptor, resourceViews);
}

/* ----- Render Passes ----- */

RenderPass* MTRenderSystem::CreateRenderPass(const RenderPassDescriptor& renderPassDesc)
{
    return renderPasses_.emplace<MTRenderPass>(device_, renderPassDesc);
}

void MTRenderSystem::Release(RenderPass& renderPass)
{
    renderPasses_.erase(&renderPass);
}

/* ----- Render Targets ----- */

RenderTarget* MTRenderSystem::CreateRenderTarget(const RenderTargetDescriptor& renderTargetDesc)
{
    return renderTargets_.emplace<MTRenderTarget>(device_, renderTargetDesc);
}

void MTRenderSystem::Release(RenderTarget& renderTarget)
{
    renderTargets_.erase(&renderTarget);
}

/* ----- Shader ----- */

Shader* MTRenderSystem::CreateShader(const ShaderDescriptor& shaderDesc)
{
    RenderSystem::AssertCreateShader(shaderDesc);
    return shaders_.emplace<MTShader>(device_, shaderDesc);
}

void MTRenderSystem::Release(Shader& shader)
{
    shaders_.erase(&shader);
}

/* ----- Pipeline Layouts ----- */

PipelineLayout* MTRenderSystem::CreatePipelineLayout(const PipelineLayoutDescriptor& pipelineLayoutDesc)
{
    return pipelineLayouts_.emplace<MTPipelineLayout>(device_, pipelineLayoutDesc);
}

void MTRenderSystem::Release(PipelineLayout& pipelineLayout)
{
    pipelineLayouts_.erase(&pipelineLayout);
}

/* ----- Pipeline States ----- */

PipelineState* MTRenderSystem::CreatePipelineState(const Blob& /*serializedCache*/)
{
    return nullptr;//TODO
}

PipelineState* MTRenderSystem::CreatePipelineState(const GraphicsPipelineDescriptor& pipelineStateDesc, Blob* /*serializedCache*/)
{
    return pipelineStates_.emplace<MTGraphicsPSO>(device_, pipelineStateDesc, GetDefaultRenderPass());
}

PipelineState* MTRenderSystem::CreatePipelineState(const ComputePipelineDescriptor& pipelineStateDesc, Blob* /*serializedCache*/)
{
    return pipelineStates_.emplace<MTComputePSO>(device_, pipelineStateDesc);
}

void MTRenderSystem::Release(PipelineState& pipelineState)
{
    pipelineStates_.erase(&pipelineState);
}

/* ----- Queries ----- */

QueryHeap* MTRenderSystem::CreateQueryHeap(const QueryHeapDescriptor& queryHeapDesc)
{
    return nullptr;//todo
}

void MTRenderSystem::Release(QueryHeap& queryHeap)
{
    //todo
    //queryHeaps_.erase(&queryHeap);
}

/* ----- Fences ----- */

Fence* MTRenderSystem::CreateFence()
{
    return fences_.emplace<MTFence>(device_);
}

void MTRenderSystem::Release(Fence& fence)
{
    fences_.erase(&fence);
}

/* ----- Extensions ----- */

bool MTRenderSystem::GetNativeHandle(void* nativeHandle, std::size_t nativeHandleSize)
{
    if (nativeHandle != nullptr && nativeHandleSize == sizeof(Metal::RenderSystemNativeHandle))
    {
        auto* nativeHandleMT = reinterpret_cast<Metal::RenderSystemNativeHandle*>(nativeHandle);
        nativeHandleMT->device = device_;
        [nativeHandleMT->device retain];
        return true;
    }
    return false;
}


/*
 * ======= Private: =======
 */

void MTRenderSystem::CreateDeviceResources()
{
    /* Create Metal device */
    device_ = MTLCreateSystemDefaultDevice();
    if (device_ == nil)
        LLGL_TRAP("failed to create Metal device");

    /* Initialize renderer information */
    RendererInfo info;
    {
        info.rendererName           = "Metal " + std::string(QueryMetalVersion());
        info.deviceName             = [[device_ name] cStringUsingEncoding:NSUTF8StringEncoding];
        info.vendorName             = "Apple";
        info.shadingLanguageName    = "Metal Shading Language";
    }
    SetRendererInfo(info);

    /* Create command queue */
    commandQueue_ = MakeUnique<MTCommandQueue>(device_);

    /* Initialize builtin PSOs */
    MTBuiltinPSOFactory::Get().CreateBuiltinPSOs(device_);

    /* Initialize intermediate buffer */
    constexpr NSUInteger intermediateBufferAlignment = 256u;
    intermediateBuffer_ = MakeUnique<MTIntermediateBuffer>(device_, MTLResourceStorageModeShared, intermediateBufferAlignment);
}

void MTRenderSystem::QueryRenderingCaps()
{
    RenderingCapabilities caps;
    LoadFeatureSetCaps(device_, QueryHighestFeatureSet(), caps);
    SetRenderingCaps(caps);
}

const char* MTRenderSystem::QueryMetalVersion() const
{
    const auto featureSet = QueryHighestFeatureSet();

    #ifdef LLGL_OS_IOS

    //TODO:
    switch (featureSet)
    {
        case MTLFeatureSet_iOS_GPUFamily5_v1: return "GPU Family 5.v1";
        case MTLFeatureSet_iOS_GPUFamily4_v2: return "GPU Family 4.v2";
        case MTLFeatureSet_iOS_GPUFamily3_v4: return "GPU Family 3.v4";
        case MTLFeatureSet_iOS_GPUFamily2_v5: return "GPU Family 2.v5";
        case MTLFeatureSet_iOS_GPUFamily1_v5: return "GPU Family 1.v5";

        case MTLFeatureSet_iOS_GPUFamily4_v1: return "GPU Family 4.v1";
        case MTLFeatureSet_iOS_GPUFamily3_v3: return "GPU Family 3.v3";
        case MTLFeatureSet_iOS_GPUFamily2_v4: return "GPU Family 2.v4";
        case MTLFeatureSet_iOS_GPUFamily1_v4: return "GPU Family 1.v4";

        case MTLFeatureSet_iOS_GPUFamily3_v2: return "GPU Family 3.v2";
        case MTLFeatureSet_iOS_GPUFamily2_v3: return "GPU Family 2.v3";
        case MTLFeatureSet_iOS_GPUFamily1_v3: return "GPU Family 1.v3";

        case MTLFeatureSet_iOS_GPUFamily3_v1: return "GPU Family 3.v1";
        case MTLFeatureSet_iOS_GPUFamily2_v2: return "GPU Family 2.v2";
        case MTLFeatureSet_iOS_GPUFamily1_v2: return "GPU Family 1.v2";

        case MTLFeatureSet_iOS_GPUFamily2_v1: return "GPU Family 2.v1";
        case MTLFeatureSet_iOS_GPUFamily1_v1: return "GPU Family 1.v1";
    }

    #else

    #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_11
    switch (featureSet)
    {
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
        case MTLFeatureSet_macOS_GPUFamily2_v1: return "2.1";
        case MTLFeatureSet_macOS_GPUFamily1_v4: return "1.4";
        #endif
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_13
        case MTLFeatureSet_macOS_GPUFamily1_v3: return "1.3";
        #endif
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
        case MTLFeatureSet_macOS_GPUFamily1_v2: return "1.2";
        #endif
        case MTLFeatureSet_macOS_GPUFamily1_v1: return "1.1";
        default:                                break;
    }
    #endif

    #endif // /LLGL_OS_IOS
    return "1.0";
}

#ifdef LLGL_OS_IOS

static void GetFeatureSetsForIOS(const MTLFeatureSet*& fsets, std::size_t& count, MTLFeatureSet& fsetDefault)
{
    static const MTLFeatureSet g_featureSetsIOS[] =
    {
        MTLFeatureSet_iOS_GPUFamily5_v1,
        MTLFeatureSet_iOS_GPUFamily4_v2,
        MTLFeatureSet_iOS_GPUFamily3_v4,
        MTLFeatureSet_iOS_GPUFamily2_v5,
        MTLFeatureSet_iOS_GPUFamily1_v5,

        MTLFeatureSet_iOS_GPUFamily4_v1,
        MTLFeatureSet_iOS_GPUFamily3_v3,
        MTLFeatureSet_iOS_GPUFamily2_v4,
        MTLFeatureSet_iOS_GPUFamily1_v4,

        MTLFeatureSet_iOS_GPUFamily3_v2,
        MTLFeatureSet_iOS_GPUFamily2_v3,
        MTLFeatureSet_iOS_GPUFamily1_v3,

        MTLFeatureSet_iOS_GPUFamily3_v1,
        MTLFeatureSet_iOS_GPUFamily2_v2,
        MTLFeatureSet_iOS_GPUFamily1_v2,

        MTLFeatureSet_iOS_GPUFamily2_v1,
        MTLFeatureSet_iOS_GPUFamily1_v1,
    };

    fsets       = g_featureSetsIOS;
    count       = sizeof(g_featureSetsIOS)/sizeof(g_featureSetsIOS[0]);
    fsetDefault = MTLFeatureSet_iOS_GPUFamily1_v1;
}

#else

static void GetFeatureSetsForMacOS(const MTLFeatureSet*& fsets, std::size_t& count, MTLFeatureSet& fsetDefault)
{
    static const MTLFeatureSet g_featureSetsMacOS[] =
    {
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
        MTLFeatureSet_macOS_ReadWriteTextureTier2,
        MTLFeatureSet_macOS_GPUFamily2_v1,
        MTLFeatureSet_macOS_GPUFamily1_v4,
        #endif
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_13
        MTLFeatureSet_macOS_GPUFamily1_v3,
        #endif
        #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
        MTLFeatureSet_macOS_GPUFamily1_v2,
        #endif
        MTLFeatureSet_macOS_GPUFamily1_v1,
    };

    fsets       = g_featureSetsMacOS;
    count       = sizeof(g_featureSetsMacOS)/sizeof(g_featureSetsMacOS[0]);
    fsetDefault = MTLFeatureSet_macOS_GPUFamily1_v1;
}

#endif // /LLGL_OS_IOS

MTLFeatureSet MTRenderSystem::QueryHighestFeatureSet() const
{
    /* Get list of feature sets for macOS or iOS */
    const MTLFeatureSet* fsets;
    std::size_t count;
    MTLFeatureSet fsetDefault;

    #ifdef LLGL_OS_IOS
    GetFeatureSetsForIOS(fsets, count, fsetDefault);
    #else
    GetFeatureSetsForMacOS(fsets, count, fsetDefault);
    #endif // /LLGL_OS_IOS

    /* Find highest supported feature set */
    for (std::size_t i = 0; i < count; ++i)
    {
        if ([device_ supportsFeatureSet:fsets[i]])
            return fsets[i];
    }

    return fsetDefault;
}

const MTRenderPass* MTRenderSystem::GetDefaultRenderPass() const
{
    if (!swapChains_.empty())
    {
        if (auto renderPass = (*swapChains_.begin())->GetRenderPass())
            return LLGL_CAST(const MTRenderPass*, renderPass);
    }
    return nullptr;
}


} // /namespace LLGL



// ================================================================================
