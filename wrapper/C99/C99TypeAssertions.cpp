/*
 * C99TypeAssertions.cpp
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#include <LLGL/Types.h>
#include <LLGL-C/Types.h>

#include <LLGL/RenderSystemFlags.h>
#include <LLGL-C/RenderSystemFlags.h>

#include <LLGL/SwapChainFlags.h>
#include <LLGL-C/SwapChainFlags.h>

#include <LLGL/PipelineStateFlags.h>
#include <LLGL-C/PipelineStateFlags.h>

#include <LLGL/CommandBufferFlags.h>
#include <LLGL-C/CommandBufferFlags.h>

#include <LLGL/SystemValue.h>
#include <LLGL-C/SystemValue.h>

#include <LLGL/Format.h>
#include <LLGL-C/Format.h>

#include <LLGL/ResourceFlags.h>
#include <LLGL-C/ResourceFlags.h>

#include <LLGL/BufferFlags.h>
#include <LLGL-C/BufferFlags.h>

#include <LLGL/TextureFlags.h>
#include <LLGL-C/TextureFlags.h>

#include <LLGL/ImageFlags.h>
#include <LLGL-C/ImageFlags.h>

#include <LLGL/SamplerFlags.h>
#include <LLGL-C/SamplerFlags.h>

#include <LLGL/ResourceHeapFlags.h>
#include <LLGL-C/ResourceHeapFlags.h>

#include <LLGL/ShaderFlags.h>
#include <LLGL-C/ShaderFlags.h>

#include <LLGL/ShaderReflection.h>
#include <LLGL-C/ShaderReflection.h>

#include <LLGL/RenderTargetFlags.h>
#include <LLGL-C/RenderTargetFlags.h>

#include <LLGL/RenderPassFlags.h>
#include <LLGL-C/RenderPassFlags.h>

#include <LLGL/PipelineLayoutFlags.h>
#include <LLGL-C/PipelineLayoutFlags.h>

#include <LLGL/QueryHeapFlags.h>
#include <LLGL-C/QueryHeapFlags.h>

#include <LLGL/WindowFlags.h>
#include <LLGL-C/WindowFlags.h>

#include <LLGL/DisplayFlags.h>
#include <LLGL-C/DisplayFlags.h>

#include <LLGL/Key.h>
#include <LLGL-C/Key.h>

#include <LLGL/IndirectArguments.h>
#include <LLGL-C/IndirectArguments.h>

#include <LLGL/Log.h>
#include <LLGL-C/Log.h>


#define LLGL_STATIC_ASSERT_ENUM(TYPE, VALUE) \
    static_assert(TYPE::VALUE == (TYPE)(LLGL ## TYPE ## VALUE), "LLGL" #TYPE #VALUE " does not equal enumeration value of LLGL::" #TYPE "::" #VALUE)

#define LLGL_STATIC_ASSERT_FLAG(TYPE, VALUE) \
    static_assert(TYPE ## Flags::VALUE == LLGL ## TYPE ## VALUE, "LLGL" #TYPE #VALUE " does not equal flags value of LLGL::" #TYPE "Flags::" #VALUE)

#define LLGL_STATIC_ASSERT_SIZE(TYPE) \
    static_assert(sizeof(LLGL::TYPE) == sizeof(LLGL ## TYPE), "LLGL" #TYPE " does not match size of LLGL::" #TYPE)

#define LLGL_STATIC_ASSERT_OFFSET(TYPE, FIELD) \
    static_assert(offsetof(LLGL::TYPE, FIELD) == offsetof(LLGL ## TYPE, FIELD), "LLGL" #TYPE "::" #FIELD " does not match offset of LLGL::" #TYPE "::" #FIELD)


using namespace LLGL;

// namespace LLGL {


/* ----- Enumerations ----- */

LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_110);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_120);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_130);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_140);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_150);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_330);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_400);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_410);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_420);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_430);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_440);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_450);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, GLSL_460);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, ESSL);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, ESSL_100);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, ESSL_300);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, ESSL_310);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, ESSL_320);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_2_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_2_0a);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_2_0b);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_3_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_4_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_4_1);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_5_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_5_1);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_6_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_6_1);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_6_2);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_6_3);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, HLSL_6_4);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal_1_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal_1_1);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal_1_2);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal_2_0);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, Metal_2_1);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, SPIRV);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, SPIRV_100);
LLGL_STATIC_ASSERT_ENUM(ShadingLanguage, VersionBitmask);

LLGL_STATIC_ASSERT_ENUM(ScreenOrigin, LowerLeft);
LLGL_STATIC_ASSERT_ENUM(ScreenOrigin, UpperLeft);

LLGL_STATIC_ASSERT_ENUM(ClippingRange, MinusOneToOne);
LLGL_STATIC_ASSERT_ENUM(ClippingRange, ZeroToOne);

LLGL_STATIC_ASSERT_ENUM(CPUAccess, ReadOnly);
LLGL_STATIC_ASSERT_ENUM(CPUAccess, WriteOnly);
LLGL_STATIC_ASSERT_ENUM(CPUAccess, WriteDiscard);
LLGL_STATIC_ASSERT_ENUM(CPUAccess, ReadWrite);

LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, PointList);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, LineList);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, LineStrip);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, LineListAdjacency);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, LineStripAdjacency);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, TriangleList);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, TriangleStrip);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, TriangleListAdjacency);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, TriangleStripAdjacency);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches1);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches2);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches3);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches4);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches5);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches6);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches7);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches8);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches9);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches10);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches11);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches12);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches13);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches14);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches15);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches16);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches17);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches18);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches19);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches20);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches21);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches22);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches23);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches24);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches25);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches26);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches27);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches28);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches29);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches30);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches31);
LLGL_STATIC_ASSERT_ENUM(PrimitiveTopology, Patches32);

LLGL_STATIC_ASSERT_ENUM(CompareOp, NeverPass);
LLGL_STATIC_ASSERT_ENUM(CompareOp, Less);
LLGL_STATIC_ASSERT_ENUM(CompareOp, Equal);
LLGL_STATIC_ASSERT_ENUM(CompareOp, LessEqual);
LLGL_STATIC_ASSERT_ENUM(CompareOp, Greater);
LLGL_STATIC_ASSERT_ENUM(CompareOp, NotEqual);
LLGL_STATIC_ASSERT_ENUM(CompareOp, GreaterEqual);
LLGL_STATIC_ASSERT_ENUM(CompareOp, AlwaysPass);

LLGL_STATIC_ASSERT_ENUM(StencilOp, Keep);
LLGL_STATIC_ASSERT_ENUM(StencilOp, Zero);
LLGL_STATIC_ASSERT_ENUM(StencilOp, Replace);
LLGL_STATIC_ASSERT_ENUM(StencilOp, IncClamp);
LLGL_STATIC_ASSERT_ENUM(StencilOp, DecClamp);
LLGL_STATIC_ASSERT_ENUM(StencilOp, Invert);
LLGL_STATIC_ASSERT_ENUM(StencilOp, IncWrap);
LLGL_STATIC_ASSERT_ENUM(StencilOp, DecWrap);

LLGL_STATIC_ASSERT_ENUM(BlendOp, Zero);
LLGL_STATIC_ASSERT_ENUM(BlendOp, One);
LLGL_STATIC_ASSERT_ENUM(BlendOp, SrcColor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvSrcColor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, SrcAlpha);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvSrcAlpha);
LLGL_STATIC_ASSERT_ENUM(BlendOp, DstColor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvDstColor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, DstAlpha);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvDstAlpha);
LLGL_STATIC_ASSERT_ENUM(BlendOp, SrcAlphaSaturate);
LLGL_STATIC_ASSERT_ENUM(BlendOp, BlendFactor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvBlendFactor);
LLGL_STATIC_ASSERT_ENUM(BlendOp, Src1Color);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvSrc1Color);
LLGL_STATIC_ASSERT_ENUM(BlendOp, Src1Alpha);
LLGL_STATIC_ASSERT_ENUM(BlendOp, InvSrc1Alpha);

LLGL_STATIC_ASSERT_ENUM(BlendArithmetic, Add);
LLGL_STATIC_ASSERT_ENUM(BlendArithmetic, Subtract);
LLGL_STATIC_ASSERT_ENUM(BlendArithmetic, RevSubtract);
LLGL_STATIC_ASSERT_ENUM(BlendArithmetic, Min);
LLGL_STATIC_ASSERT_ENUM(BlendArithmetic, Max);

LLGL_STATIC_ASSERT_ENUM(PolygonMode, Fill);
LLGL_STATIC_ASSERT_ENUM(PolygonMode, Wireframe);
LLGL_STATIC_ASSERT_ENUM(PolygonMode, Points);

LLGL_STATIC_ASSERT_ENUM(CullMode, Disabled);
LLGL_STATIC_ASSERT_ENUM(CullMode, Front);
LLGL_STATIC_ASSERT_ENUM(CullMode, Back);

LLGL_STATIC_ASSERT_ENUM(LogicOp, Disabled);
LLGL_STATIC_ASSERT_ENUM(LogicOp, Clear);
LLGL_STATIC_ASSERT_ENUM(LogicOp, Set);
LLGL_STATIC_ASSERT_ENUM(LogicOp, Copy);
LLGL_STATIC_ASSERT_ENUM(LogicOp, CopyInverted);
LLGL_STATIC_ASSERT_ENUM(LogicOp, NoOp);
LLGL_STATIC_ASSERT_ENUM(LogicOp, Invert);
LLGL_STATIC_ASSERT_ENUM(LogicOp, AND);
LLGL_STATIC_ASSERT_ENUM(LogicOp, ANDReverse);
LLGL_STATIC_ASSERT_ENUM(LogicOp, ANDInverted);
LLGL_STATIC_ASSERT_ENUM(LogicOp, NAND);
LLGL_STATIC_ASSERT_ENUM(LogicOp, OR);
LLGL_STATIC_ASSERT_ENUM(LogicOp, ORReverse);
LLGL_STATIC_ASSERT_ENUM(LogicOp, ORInverted);
LLGL_STATIC_ASSERT_ENUM(LogicOp, NOR);
LLGL_STATIC_ASSERT_ENUM(LogicOp, XOR);
LLGL_STATIC_ASSERT_ENUM(LogicOp, Equiv);

LLGL_STATIC_ASSERT_ENUM(TessellationPartition, Undefined);
LLGL_STATIC_ASSERT_ENUM(TessellationPartition, Integer);
LLGL_STATIC_ASSERT_ENUM(TessellationPartition, Pow2);
LLGL_STATIC_ASSERT_ENUM(TessellationPartition, FractionalOdd);
LLGL_STATIC_ASSERT_ENUM(TessellationPartition, FractionalEven);

LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, Wait);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, NoWait);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, ByRegionWait);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, ByRegionNoWait);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, WaitInverted);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, NoWaitInverted);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, ByRegionWaitInverted);
LLGL_STATIC_ASSERT_ENUM(RenderConditionMode, ByRegionNoWaitInverted);

LLGL_STATIC_ASSERT_ENUM(StencilFace, FrontAndBack);
LLGL_STATIC_ASSERT_ENUM(StencilFace, Front);
LLGL_STATIC_ASSERT_ENUM(StencilFace, Back);

LLGL_STATIC_ASSERT_ENUM(Format, Undefined);
LLGL_STATIC_ASSERT_ENUM(Format, A8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, R8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, R8SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, R8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, R8SInt);
LLGL_STATIC_ASSERT_ENUM(Format, R16UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, R16SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, R16UInt);
LLGL_STATIC_ASSERT_ENUM(Format, R16SInt);
LLGL_STATIC_ASSERT_ENUM(Format, R16Float);
LLGL_STATIC_ASSERT_ENUM(Format, R32UInt);
LLGL_STATIC_ASSERT_ENUM(Format, R32SInt);
LLGL_STATIC_ASSERT_ENUM(Format, R32Float);
LLGL_STATIC_ASSERT_ENUM(Format, R64Float);
LLGL_STATIC_ASSERT_ENUM(Format, RG8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RG8SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RG8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG8SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG16UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RG16SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RG16UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG16SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG16Float);
LLGL_STATIC_ASSERT_ENUM(Format, RG32UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG32SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG32Float);
LLGL_STATIC_ASSERT_ENUM(Format, RG64Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGB8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGB8UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, RGB8SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGB8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB8SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB16UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGB16SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGB16UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB16SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB16Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGB32UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB32SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB32Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGB64Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA8UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA8SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA8SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA16UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA16SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA16UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA16SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA16Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA32UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA32SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA32Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGBA64Float);
LLGL_STATIC_ASSERT_ENUM(Format, BGRA8UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BGRA8UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, BGRA8SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BGRA8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, BGRA8SInt);
LLGL_STATIC_ASSERT_ENUM(Format, RGB10A2UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, RGB10A2UInt);
LLGL_STATIC_ASSERT_ENUM(Format, RG11B10Float);
LLGL_STATIC_ASSERT_ENUM(Format, RGB9E5Float);
LLGL_STATIC_ASSERT_ENUM(Format, D16UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, D24UNormS8UInt);
LLGL_STATIC_ASSERT_ENUM(Format, D32Float);
LLGL_STATIC_ASSERT_ENUM(Format, D32FloatS8X24UInt);
LLGL_STATIC_ASSERT_ENUM(Format, BC1UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC1UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, BC2UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC2UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, BC3UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC3UNorm_sRGB);
LLGL_STATIC_ASSERT_ENUM(Format, BC4UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC4SNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC5UNorm);
LLGL_STATIC_ASSERT_ENUM(Format, BC5SNorm);

LLGL_STATIC_ASSERT_ENUM(ImageFormat, Alpha);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, R);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, RG);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, RGB);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BGR);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, RGBA);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BGRA);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, ARGB);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, ABGR);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, Depth);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, DepthStencil);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BC1);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BC2);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BC3);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BC4);
LLGL_STATIC_ASSERT_ENUM(ImageFormat, BC5);

LLGL_STATIC_ASSERT_ENUM(DataType, Undefined);
LLGL_STATIC_ASSERT_ENUM(DataType, Int8);
LLGL_STATIC_ASSERT_ENUM(DataType, UInt8);
LLGL_STATIC_ASSERT_ENUM(DataType, Int16);
LLGL_STATIC_ASSERT_ENUM(DataType, UInt16);
LLGL_STATIC_ASSERT_ENUM(DataType, Int32);
LLGL_STATIC_ASSERT_ENUM(DataType, UInt32);
LLGL_STATIC_ASSERT_ENUM(DataType, Float16);
LLGL_STATIC_ASSERT_ENUM(DataType, Float32);
LLGL_STATIC_ASSERT_ENUM(DataType, Float64);

LLGL_STATIC_ASSERT_ENUM(SystemValue, Undefined);
LLGL_STATIC_ASSERT_ENUM(SystemValue, ClipDistance);
LLGL_STATIC_ASSERT_ENUM(SystemValue, Color);
LLGL_STATIC_ASSERT_ENUM(SystemValue, CullDistance);
LLGL_STATIC_ASSERT_ENUM(SystemValue, Depth);
LLGL_STATIC_ASSERT_ENUM(SystemValue, DepthGreater);
LLGL_STATIC_ASSERT_ENUM(SystemValue, DepthLess);
LLGL_STATIC_ASSERT_ENUM(SystemValue, FrontFacing);
LLGL_STATIC_ASSERT_ENUM(SystemValue, InstanceID);
LLGL_STATIC_ASSERT_ENUM(SystemValue, Position);
LLGL_STATIC_ASSERT_ENUM(SystemValue, PrimitiveID);
LLGL_STATIC_ASSERT_ENUM(SystemValue, RenderTargetIndex);
LLGL_STATIC_ASSERT_ENUM(SystemValue, SampleMask);
LLGL_STATIC_ASSERT_ENUM(SystemValue, SampleID);
LLGL_STATIC_ASSERT_ENUM(SystemValue, Stencil);
LLGL_STATIC_ASSERT_ENUM(SystemValue, VertexID);
LLGL_STATIC_ASSERT_ENUM(SystemValue, ViewportIndex);

LLGL_STATIC_ASSERT_ENUM(TextureType, Texture1D);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture2D);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture3D);
LLGL_STATIC_ASSERT_ENUM(TextureType, TextureCube);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture1DArray);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture2DArray);
LLGL_STATIC_ASSERT_ENUM(TextureType, TextureCubeArray);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture2DMS);
LLGL_STATIC_ASSERT_ENUM(TextureType, Texture2DMSArray);

LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, Zero);
LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, One);
LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, Red);
LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, Green);
LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, Blue);
LLGL_STATIC_ASSERT_ENUM(TextureSwizzle, Alpha);

LLGL_STATIC_ASSERT_ENUM(SamplerAddressMode, Repeat);
LLGL_STATIC_ASSERT_ENUM(SamplerAddressMode, Mirror);
LLGL_STATIC_ASSERT_ENUM(SamplerAddressMode, Clamp);
LLGL_STATIC_ASSERT_ENUM(SamplerAddressMode, Border);
LLGL_STATIC_ASSERT_ENUM(SamplerAddressMode, MirrorOnce);

LLGL_STATIC_ASSERT_ENUM(SamplerFilter, Nearest);
LLGL_STATIC_ASSERT_ENUM(SamplerFilter, Linear);

LLGL_STATIC_ASSERT_ENUM(ShaderType, Undefined);
LLGL_STATIC_ASSERT_ENUM(ShaderType, Vertex);
LLGL_STATIC_ASSERT_ENUM(ShaderType, TessControl);
LLGL_STATIC_ASSERT_ENUM(ShaderType, TessEvaluation);
LLGL_STATIC_ASSERT_ENUM(ShaderType, Geometry);
LLGL_STATIC_ASSERT_ENUM(ShaderType, Fragment);
LLGL_STATIC_ASSERT_ENUM(ShaderType, Compute);

LLGL_STATIC_ASSERT_ENUM(ShaderSourceType, CodeString);
LLGL_STATIC_ASSERT_ENUM(ShaderSourceType, CodeFile);
LLGL_STATIC_ASSERT_ENUM(ShaderSourceType, BinaryBuffer);
LLGL_STATIC_ASSERT_ENUM(ShaderSourceType, BinaryFile);

LLGL_STATIC_ASSERT_ENUM(UniformType, Undefined);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float1);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double1);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Int1);
LLGL_STATIC_ASSERT_ENUM(UniformType, Int2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Int3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Int4);
LLGL_STATIC_ASSERT_ENUM(UniformType, UInt1);
LLGL_STATIC_ASSERT_ENUM(UniformType, UInt2);
LLGL_STATIC_ASSERT_ENUM(UniformType, UInt3);
LLGL_STATIC_ASSERT_ENUM(UniformType, UInt4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Bool1);
LLGL_STATIC_ASSERT_ENUM(UniformType, Bool2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Bool3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Bool4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float2x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float2x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float2x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float3x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float3x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float3x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float4x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float4x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Float4x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double2x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double2x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double2x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double3x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double3x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double3x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double4x2);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double4x3);
LLGL_STATIC_ASSERT_ENUM(UniformType, Double4x4);
LLGL_STATIC_ASSERT_ENUM(UniformType, Sampler);
LLGL_STATIC_ASSERT_ENUM(UniformType, Image);
LLGL_STATIC_ASSERT_ENUM(UniformType, AtomicCounter);

LLGL_STATIC_ASSERT_ENUM(ResourceType, Undefined);
LLGL_STATIC_ASSERT_ENUM(ResourceType, Buffer);
LLGL_STATIC_ASSERT_ENUM(ResourceType, Texture);
LLGL_STATIC_ASSERT_ENUM(ResourceType, Sampler);

LLGL_STATIC_ASSERT_ENUM(Key, LButton);
LLGL_STATIC_ASSERT_ENUM(Key, RButton);
LLGL_STATIC_ASSERT_ENUM(Key, Cancel);
LLGL_STATIC_ASSERT_ENUM(Key, MButton);
LLGL_STATIC_ASSERT_ENUM(Key, XButton1);
LLGL_STATIC_ASSERT_ENUM(Key, XButton2);
LLGL_STATIC_ASSERT_ENUM(Key, Back);
LLGL_STATIC_ASSERT_ENUM(Key, Tab);
LLGL_STATIC_ASSERT_ENUM(Key, Clear);
LLGL_STATIC_ASSERT_ENUM(Key, Return);
LLGL_STATIC_ASSERT_ENUM(Key, Shift);
LLGL_STATIC_ASSERT_ENUM(Key, Control);
LLGL_STATIC_ASSERT_ENUM(Key, Menu);
LLGL_STATIC_ASSERT_ENUM(Key, Pause);
LLGL_STATIC_ASSERT_ENUM(Key, Capital);
LLGL_STATIC_ASSERT_ENUM(Key, Escape);
LLGL_STATIC_ASSERT_ENUM(Key, Space);
LLGL_STATIC_ASSERT_ENUM(Key, PageUp);
LLGL_STATIC_ASSERT_ENUM(Key, PageDown);
LLGL_STATIC_ASSERT_ENUM(Key, End);
LLGL_STATIC_ASSERT_ENUM(Key, Home);
LLGL_STATIC_ASSERT_ENUM(Key, Left);
LLGL_STATIC_ASSERT_ENUM(Key, Up);
LLGL_STATIC_ASSERT_ENUM(Key, Right);
LLGL_STATIC_ASSERT_ENUM(Key, Down);
LLGL_STATIC_ASSERT_ENUM(Key, Select);
LLGL_STATIC_ASSERT_ENUM(Key, Print);
LLGL_STATIC_ASSERT_ENUM(Key, Exe);
LLGL_STATIC_ASSERT_ENUM(Key, Snapshot);
LLGL_STATIC_ASSERT_ENUM(Key, Insert);
LLGL_STATIC_ASSERT_ENUM(Key, Delete);
LLGL_STATIC_ASSERT_ENUM(Key, Help);
LLGL_STATIC_ASSERT_ENUM(Key, D0);
LLGL_STATIC_ASSERT_ENUM(Key, D1);
LLGL_STATIC_ASSERT_ENUM(Key, D2);
LLGL_STATIC_ASSERT_ENUM(Key, D3);
LLGL_STATIC_ASSERT_ENUM(Key, D4);
LLGL_STATIC_ASSERT_ENUM(Key, D5);
LLGL_STATIC_ASSERT_ENUM(Key, D6);
LLGL_STATIC_ASSERT_ENUM(Key, D7);
LLGL_STATIC_ASSERT_ENUM(Key, D8);
LLGL_STATIC_ASSERT_ENUM(Key, D9);
LLGL_STATIC_ASSERT_ENUM(Key, A);
LLGL_STATIC_ASSERT_ENUM(Key, B);
LLGL_STATIC_ASSERT_ENUM(Key, C);
LLGL_STATIC_ASSERT_ENUM(Key, D);
LLGL_STATIC_ASSERT_ENUM(Key, E);
LLGL_STATIC_ASSERT_ENUM(Key, F);
LLGL_STATIC_ASSERT_ENUM(Key, G);
LLGL_STATIC_ASSERT_ENUM(Key, H);
LLGL_STATIC_ASSERT_ENUM(Key, I);
LLGL_STATIC_ASSERT_ENUM(Key, J);
LLGL_STATIC_ASSERT_ENUM(Key, K);
LLGL_STATIC_ASSERT_ENUM(Key, L);
LLGL_STATIC_ASSERT_ENUM(Key, M);
LLGL_STATIC_ASSERT_ENUM(Key, N);
LLGL_STATIC_ASSERT_ENUM(Key, O);
LLGL_STATIC_ASSERT_ENUM(Key, P);
LLGL_STATIC_ASSERT_ENUM(Key, Q);
LLGL_STATIC_ASSERT_ENUM(Key, R);
LLGL_STATIC_ASSERT_ENUM(Key, S);
LLGL_STATIC_ASSERT_ENUM(Key, T);
LLGL_STATIC_ASSERT_ENUM(Key, U);
LLGL_STATIC_ASSERT_ENUM(Key, V);
LLGL_STATIC_ASSERT_ENUM(Key, W);
LLGL_STATIC_ASSERT_ENUM(Key, X);
LLGL_STATIC_ASSERT_ENUM(Key, Y);
LLGL_STATIC_ASSERT_ENUM(Key, Z);
LLGL_STATIC_ASSERT_ENUM(Key, LWin);
LLGL_STATIC_ASSERT_ENUM(Key, RWin);
LLGL_STATIC_ASSERT_ENUM(Key, Apps);
LLGL_STATIC_ASSERT_ENUM(Key, Sleep);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad0);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad1);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad2);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad3);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad4);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad5);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad6);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad7);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad8);
LLGL_STATIC_ASSERT_ENUM(Key, Keypad9);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadMultiply);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadPlus);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadSeparator);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadMinus);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadDecimal);
LLGL_STATIC_ASSERT_ENUM(Key, KeypadDivide);
LLGL_STATIC_ASSERT_ENUM(Key, F1);
LLGL_STATIC_ASSERT_ENUM(Key, F2);
LLGL_STATIC_ASSERT_ENUM(Key, F3);
LLGL_STATIC_ASSERT_ENUM(Key, F4);
LLGL_STATIC_ASSERT_ENUM(Key, F5);
LLGL_STATIC_ASSERT_ENUM(Key, F6);
LLGL_STATIC_ASSERT_ENUM(Key, F7);
LLGL_STATIC_ASSERT_ENUM(Key, F8);
LLGL_STATIC_ASSERT_ENUM(Key, F9);
LLGL_STATIC_ASSERT_ENUM(Key, F10);
LLGL_STATIC_ASSERT_ENUM(Key, F11);
LLGL_STATIC_ASSERT_ENUM(Key, F12);
LLGL_STATIC_ASSERT_ENUM(Key, F13);
LLGL_STATIC_ASSERT_ENUM(Key, F14);
LLGL_STATIC_ASSERT_ENUM(Key, F15);
LLGL_STATIC_ASSERT_ENUM(Key, F16);
LLGL_STATIC_ASSERT_ENUM(Key, F17);
LLGL_STATIC_ASSERT_ENUM(Key, F18);
LLGL_STATIC_ASSERT_ENUM(Key, F19);
LLGL_STATIC_ASSERT_ENUM(Key, F20);
LLGL_STATIC_ASSERT_ENUM(Key, F21);
LLGL_STATIC_ASSERT_ENUM(Key, F22);
LLGL_STATIC_ASSERT_ENUM(Key, F23);
LLGL_STATIC_ASSERT_ENUM(Key, F24);
LLGL_STATIC_ASSERT_ENUM(Key, NumLock);
LLGL_STATIC_ASSERT_ENUM(Key, ScrollLock);
LLGL_STATIC_ASSERT_ENUM(Key, LShift);
LLGL_STATIC_ASSERT_ENUM(Key, RShift);
LLGL_STATIC_ASSERT_ENUM(Key, LControl);
LLGL_STATIC_ASSERT_ENUM(Key, RControl);
LLGL_STATIC_ASSERT_ENUM(Key, LMenu);
LLGL_STATIC_ASSERT_ENUM(Key, RMenu);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserBack);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserForward);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserRefresh);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserStop);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserSearch);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserFavorits);
LLGL_STATIC_ASSERT_ENUM(Key, BrowserHome);
LLGL_STATIC_ASSERT_ENUM(Key, VolumeMute);
LLGL_STATIC_ASSERT_ENUM(Key, VolumeDown);
LLGL_STATIC_ASSERT_ENUM(Key, VolumeUp);
LLGL_STATIC_ASSERT_ENUM(Key, MediaNextTrack);
LLGL_STATIC_ASSERT_ENUM(Key, MediaPrevTrack);
LLGL_STATIC_ASSERT_ENUM(Key, MediaStop);
LLGL_STATIC_ASSERT_ENUM(Key, MediaPlayPause);
LLGL_STATIC_ASSERT_ENUM(Key, LaunchMail);
LLGL_STATIC_ASSERT_ENUM(Key, LaunchMediaSelect);
LLGL_STATIC_ASSERT_ENUM(Key, LaunchApp1);
LLGL_STATIC_ASSERT_ENUM(Key, LaunchApp2);
LLGL_STATIC_ASSERT_ENUM(Key, Plus);
LLGL_STATIC_ASSERT_ENUM(Key, Comma);
LLGL_STATIC_ASSERT_ENUM(Key, Minus);
LLGL_STATIC_ASSERT_ENUM(Key, Period);
LLGL_STATIC_ASSERT_ENUM(Key, Exponent);
LLGL_STATIC_ASSERT_ENUM(Key, Attn);
LLGL_STATIC_ASSERT_ENUM(Key, CrSel);
LLGL_STATIC_ASSERT_ENUM(Key, ExSel);
LLGL_STATIC_ASSERT_ENUM(Key, ErEOF);
LLGL_STATIC_ASSERT_ENUM(Key, Play);
LLGL_STATIC_ASSERT_ENUM(Key, Zoom);
LLGL_STATIC_ASSERT_ENUM(Key, NoName);
LLGL_STATIC_ASSERT_ENUM(Key, PA1);
LLGL_STATIC_ASSERT_ENUM(Key, OEMClear);
LLGL_STATIC_ASSERT_ENUM(Key, Any);

LLGL_STATIC_ASSERT_ENUM(StorageBufferType, Undefined);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, TypedBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, StructuredBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, ByteAddressBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, RWTypedBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, RWStructuredBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, RWByteAddressBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, AppendStructuredBuffer);
LLGL_STATIC_ASSERT_ENUM(StorageBufferType, ConsumeStructuredBuffer);

LLGL_STATIC_ASSERT_ENUM(QueryType, SamplesPassed);
LLGL_STATIC_ASSERT_ENUM(QueryType, AnySamplesPassed);
LLGL_STATIC_ASSERT_ENUM(QueryType, AnySamplesPassedConservative);
LLGL_STATIC_ASSERT_ENUM(QueryType, TimeElapsed);
LLGL_STATIC_ASSERT_ENUM(QueryType, StreamOutPrimitivesWritten);
LLGL_STATIC_ASSERT_ENUM(QueryType, StreamOutOverflow);
LLGL_STATIC_ASSERT_ENUM(QueryType, PipelineStatistics);

LLGL_STATIC_ASSERT_ENUM(AttachmentLoadOp, Undefined);
LLGL_STATIC_ASSERT_ENUM(AttachmentLoadOp, Load);
LLGL_STATIC_ASSERT_ENUM(AttachmentLoadOp, Clear);

LLGL_STATIC_ASSERT_ENUM(AttachmentStoreOp, Undefined);
LLGL_STATIC_ASSERT_ENUM(AttachmentStoreOp, Store);


/* ----- Flags ----- */

LLGL_STATIC_ASSERT_FLAG(CommandBuffer, Secondary);
LLGL_STATIC_ASSERT_FLAG(CommandBuffer, MultiSubmit);
LLGL_STATIC_ASSERT_FLAG(CommandBuffer, ImmediateSubmit);

LLGL_STATIC_ASSERT_FLAG(Clear, Color);
LLGL_STATIC_ASSERT_FLAG(Clear, Depth);
LLGL_STATIC_ASSERT_FLAG(Clear, Stencil);
LLGL_STATIC_ASSERT_FLAG(Clear, ColorDepth);
LLGL_STATIC_ASSERT_FLAG(Clear, DepthStencil);
LLGL_STATIC_ASSERT_FLAG(Clear, All);

LLGL_STATIC_ASSERT_FLAG(Format, HasDepth);
LLGL_STATIC_ASSERT_FLAG(Format, HasStencil);
LLGL_STATIC_ASSERT_FLAG(Format, IsColorSpace_sRGB);
LLGL_STATIC_ASSERT_FLAG(Format, IsCompressed);
LLGL_STATIC_ASSERT_FLAG(Format, IsNormalized);
LLGL_STATIC_ASSERT_FLAG(Format, IsInteger);
LLGL_STATIC_ASSERT_FLAG(Format, IsUnsigned);
LLGL_STATIC_ASSERT_FLAG(Format, IsPacked);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsRenderTarget);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsMips);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsGenerateMips);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsTexture1D);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsTexture2D);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsTexture3D);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsTextureCube);
LLGL_STATIC_ASSERT_FLAG(Format, SupportsVertex);
LLGL_STATIC_ASSERT_FLAG(Format, IsUnsignedInteger);
LLGL_STATIC_ASSERT_FLAG(Format, HasDepthStencil);

LLGL_STATIC_ASSERT_FLAG(Barrier, StorageBuffer);
LLGL_STATIC_ASSERT_FLAG(Barrier, StorageTexture);
LLGL_STATIC_ASSERT_FLAG(Barrier, Storage);

LLGL_STATIC_ASSERT_FLAG(ShaderCompile, Debug);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, NoOptimization);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, OptimizationLevel1);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, OptimizationLevel2);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, OptimizationLevel3);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, WarningsAreErrors);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, PatchClippingOrigin);
LLGL_STATIC_ASSERT_FLAG(ShaderCompile, SeparateShader);

LLGL_STATIC_ASSERT_FLAG(Stage, VertexStage);
LLGL_STATIC_ASSERT_FLAG(Stage, TessControlStage);
LLGL_STATIC_ASSERT_FLAG(Stage, TessEvaluationStage);
LLGL_STATIC_ASSERT_FLAG(Stage, GeometryStage);
LLGL_STATIC_ASSERT_FLAG(Stage, FragmentStage);
LLGL_STATIC_ASSERT_FLAG(Stage, ComputeStage);
LLGL_STATIC_ASSERT_FLAG(Stage, AllTessStages);
LLGL_STATIC_ASSERT_FLAG(Stage, AllGraphicsStages);
LLGL_STATIC_ASSERT_FLAG(Stage, AllStages);

LLGL_STATIC_ASSERT_FLAG(Bind, VertexBuffer);
LLGL_STATIC_ASSERT_FLAG(Bind, IndexBuffer);
LLGL_STATIC_ASSERT_FLAG(Bind, ConstantBuffer);
LLGL_STATIC_ASSERT_FLAG(Bind, StreamOutputBuffer);
LLGL_STATIC_ASSERT_FLAG(Bind, IndirectBuffer);
LLGL_STATIC_ASSERT_FLAG(Bind, Sampled);
LLGL_STATIC_ASSERT_FLAG(Bind, Storage);
LLGL_STATIC_ASSERT_FLAG(Bind, ColorAttachment);
LLGL_STATIC_ASSERT_FLAG(Bind, DepthStencilAttachment);
LLGL_STATIC_ASSERT_FLAG(Bind, CombinedSampler);
LLGL_STATIC_ASSERT_FLAG(Bind, CopySrc);
LLGL_STATIC_ASSERT_FLAG(Bind, CopyDst);

LLGL_STATIC_ASSERT_FLAG(CPUAccess, Read);
LLGL_STATIC_ASSERT_FLAG(CPUAccess, Write);

LLGL_STATIC_ASSERT_FLAG(Misc, DynamicUsage);
LLGL_STATIC_ASSERT_FLAG(Misc, FixedSamples);
LLGL_STATIC_ASSERT_FLAG(Misc, GenerateMips);
LLGL_STATIC_ASSERT_FLAG(Misc, NoInitialData);
LLGL_STATIC_ASSERT_FLAG(Misc, Append);
LLGL_STATIC_ASSERT_FLAG(Misc, Counter);


/* ----- Structures ----- */

LLGL_STATIC_ASSERT_SIZE(Extent2D);
LLGL_STATIC_ASSERT_OFFSET(Extent2D, width);
LLGL_STATIC_ASSERT_OFFSET(Extent2D, height);

LLGL_STATIC_ASSERT_SIZE(Extent3D);
LLGL_STATIC_ASSERT_OFFSET(Extent3D, width);
LLGL_STATIC_ASSERT_OFFSET(Extent3D, height);
LLGL_STATIC_ASSERT_OFFSET(Extent3D, depth);

LLGL_STATIC_ASSERT_SIZE(Offset2D);
LLGL_STATIC_ASSERT_OFFSET(Offset2D, x);
LLGL_STATIC_ASSERT_OFFSET(Offset2D, y);

LLGL_STATIC_ASSERT_SIZE(Offset3D);
LLGL_STATIC_ASSERT_OFFSET(Offset3D, x);
LLGL_STATIC_ASSERT_OFFSET(Offset3D, y);
LLGL_STATIC_ASSERT_OFFSET(Offset3D, z);

LLGL_STATIC_ASSERT_SIZE(Viewport);
LLGL_STATIC_ASSERT_OFFSET(Viewport, x);
LLGL_STATIC_ASSERT_OFFSET(Viewport, y);
LLGL_STATIC_ASSERT_OFFSET(Viewport, width);
LLGL_STATIC_ASSERT_OFFSET(Viewport, height);
LLGL_STATIC_ASSERT_OFFSET(Viewport, minDepth);
LLGL_STATIC_ASSERT_OFFSET(Viewport, maxDepth);

LLGL_STATIC_ASSERT_SIZE(Scissor);
LLGL_STATIC_ASSERT_OFFSET(Scissor, x);
LLGL_STATIC_ASSERT_OFFSET(Scissor, y);
LLGL_STATIC_ASSERT_OFFSET(Scissor, width);
LLGL_STATIC_ASSERT_OFFSET(Scissor, height);

LLGL_STATIC_ASSERT_SIZE(DepthDescriptor);
LLGL_STATIC_ASSERT_OFFSET(DepthDescriptor, testEnabled);
LLGL_STATIC_ASSERT_OFFSET(DepthDescriptor, writeEnabled);
LLGL_STATIC_ASSERT_OFFSET(DepthDescriptor, compareOp);

LLGL_STATIC_ASSERT_SIZE(StencilFaceDescriptor);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, stencilFailOp);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, depthFailOp);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, depthPassOp);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, compareOp);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, readMask);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, writeMask);
LLGL_STATIC_ASSERT_OFFSET(StencilFaceDescriptor, reference);

LLGL_STATIC_ASSERT_SIZE(StencilDescriptor);
LLGL_STATIC_ASSERT_OFFSET(StencilDescriptor, testEnabled);
LLGL_STATIC_ASSERT_OFFSET(StencilDescriptor, referenceDynamic);
LLGL_STATIC_ASSERT_OFFSET(StencilDescriptor, front);
LLGL_STATIC_ASSERT_OFFSET(StencilDescriptor, back);

LLGL_STATIC_ASSERT_SIZE(DepthBiasDescriptor);
LLGL_STATIC_ASSERT_OFFSET(DepthBiasDescriptor, constantFactor);
LLGL_STATIC_ASSERT_OFFSET(DepthBiasDescriptor, slopeFactor);
LLGL_STATIC_ASSERT_OFFSET(DepthBiasDescriptor, clamp);

LLGL_STATIC_ASSERT_SIZE(RasterizerDescriptor);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, polygonMode);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, cullMode);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, depthBias);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, frontCCW);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, discardEnabled);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, depthClampEnabled);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, scissorTestEnabled);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, multiSampleEnabled);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, antiAliasedLineEnabled);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, conservativeRasterization);
LLGL_STATIC_ASSERT_OFFSET(RasterizerDescriptor, lineWidth);

LLGL_STATIC_ASSERT_SIZE(BlendTargetDescriptor);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, blendEnabled);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, srcColor);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, dstColor);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, colorArithmetic);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, srcAlpha);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, dstAlpha);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, alphaArithmetic);
LLGL_STATIC_ASSERT_OFFSET(BlendTargetDescriptor, colorMask);

LLGL_STATIC_ASSERT_SIZE(BlendDescriptor);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, alphaToCoverageEnabled);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, independentBlendEnabled);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, sampleMask);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, logicOp);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, blendFactor);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, blendFactorDynamic);
LLGL_STATIC_ASSERT_OFFSET(BlendDescriptor, targets);

LLGL_STATIC_ASSERT_SIZE(TessellationDescriptor);
LLGL_STATIC_ASSERT_OFFSET(TessellationDescriptor, partition);
LLGL_STATIC_ASSERT_OFFSET(TessellationDescriptor, indexFormat);
LLGL_STATIC_ASSERT_OFFSET(TessellationDescriptor, maxTessFactor);
LLGL_STATIC_ASSERT_OFFSET(TessellationDescriptor, outputWindingCCW);

LLGL_STATIC_ASSERT_SIZE(ClearValue);
LLGL_STATIC_ASSERT_OFFSET(ClearValue, color);
LLGL_STATIC_ASSERT_OFFSET(ClearValue, depth);
LLGL_STATIC_ASSERT_OFFSET(ClearValue, stencil);

LLGL_STATIC_ASSERT_SIZE(AttachmentClear);
LLGL_STATIC_ASSERT_OFFSET(AttachmentClear, flags);
LLGL_STATIC_ASSERT_OFFSET(AttachmentClear, colorAttachment);
LLGL_STATIC_ASSERT_OFFSET(AttachmentClear, clearValue);

LLGL_STATIC_ASSERT_SIZE(CommandBufferDescriptor);
LLGL_STATIC_ASSERT_OFFSET(CommandBufferDescriptor, flags);
LLGL_STATIC_ASSERT_OFFSET(CommandBufferDescriptor, numNativeBuffers);
LLGL_STATIC_ASSERT_OFFSET(CommandBufferDescriptor, minStagingPoolSize);

LLGL_STATIC_ASSERT_SIZE(FormatAttributes);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, bitSize);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, blockWidth);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, blockHeight);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, components);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, format);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, dataType);
LLGL_STATIC_ASSERT_OFFSET(FormatAttributes, flags);

LLGL_STATIC_ASSERT_SIZE(TextureSwizzleRGBA);
//LLGL_STATIC_ASSERT_OFFSET(TextureSwizzleRGBA, r);
//LLGL_STATIC_ASSERT_OFFSET(TextureSwizzleRGBA, g);
//LLGL_STATIC_ASSERT_OFFSET(TextureSwizzleRGBA, b);
//LLGL_STATIC_ASSERT_OFFSET(TextureSwizzleRGBA, a);

LLGL_STATIC_ASSERT_SIZE(TextureSubresource);
LLGL_STATIC_ASSERT_OFFSET(TextureSubresource, baseArrayLayer);
LLGL_STATIC_ASSERT_OFFSET(TextureSubresource, numArrayLayers);
LLGL_STATIC_ASSERT_OFFSET(TextureSubresource, baseMipLevel);
LLGL_STATIC_ASSERT_OFFSET(TextureSubresource, numMipLevels);

LLGL_STATIC_ASSERT_SIZE(TextureLocation);
LLGL_STATIC_ASSERT_OFFSET(TextureLocation, offset);
LLGL_STATIC_ASSERT_OFFSET(TextureLocation, arrayLayer);
LLGL_STATIC_ASSERT_OFFSET(TextureLocation, mipLevel);

LLGL_STATIC_ASSERT_SIZE(TextureRegion);
LLGL_STATIC_ASSERT_OFFSET(TextureRegion, subresource);
LLGL_STATIC_ASSERT_OFFSET(TextureRegion, offset);
LLGL_STATIC_ASSERT_OFFSET(TextureRegion, extent);

LLGL_STATIC_ASSERT_SIZE(TextureDescriptor);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, type);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, bindFlags);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, miscFlags);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, extent);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, arrayLayers);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, mipLevels);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, samples);
LLGL_STATIC_ASSERT_OFFSET(TextureDescriptor, clearValue);

LLGL_STATIC_ASSERT_SIZE(TextureViewDescriptor);
LLGL_STATIC_ASSERT_OFFSET(TextureViewDescriptor, type);
LLGL_STATIC_ASSERT_OFFSET(TextureViewDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(TextureViewDescriptor, subresource);
LLGL_STATIC_ASSERT_OFFSET(TextureViewDescriptor, swizzle);

LLGL_STATIC_ASSERT_SIZE(SubresourceFootprint);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, size);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, rowAlignment);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, rowSize);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, rowStride);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, layerSize);
LLGL_STATIC_ASSERT_OFFSET(SubresourceFootprint, layerStride);

LLGL_STATIC_ASSERT_SIZE(SwapChainDescriptor);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, resolution);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, colorBits);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, depthBits);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, stencilBits);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, samples);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, swapBuffers);
LLGL_STATIC_ASSERT_OFFSET(SwapChainDescriptor, fullscreen);

LLGL_STATIC_ASSERT_SIZE(RenderingFeatures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasRenderTargets);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, has3DTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasCubeTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasArrayTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasCubeArrayTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasMultiSampleTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasMultiSampleArrayTextures);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasTextureViews);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasTextureViewSwizzle);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasBufferViews);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasSamplers);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasConstantBuffers);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasStorageBuffers);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasUniforms);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasGeometryShaders);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasTessellationShaders);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasTessellatorStage);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasComputeShaders);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasInstancing);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasOffsetInstancing);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasIndirectDrawing);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasViewportArrays);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasConservativeRasterization);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasStreamOutputs);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasLogicOp);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasPipelineStatistics);
LLGL_STATIC_ASSERT_OFFSET(RenderingFeatures, hasRenderCondition);

LLGL_STATIC_ASSERT_SIZE(RenderingLimits);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, lineWidthRange);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxTextureArrayLayers);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxColorAttachments);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxPatchVertices);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, max1DTextureSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, max2DTextureSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, max3DTextureSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxCubeTextureSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxAnisotropy);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxComputeShaderWorkGroups);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxComputeShaderWorkGroupSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxViewports);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxViewportSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxBufferSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxConstantBufferSize);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxStreamOutputs);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, maxTessFactor);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, minConstantBufferAlignment);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, minSampledBufferAlignment);
LLGL_STATIC_ASSERT_OFFSET(RenderingLimits, minStorageBufferAlignment);

LLGL_STATIC_ASSERT_SIZE(SrcImageDescriptor);
LLGL_STATIC_ASSERT_OFFSET(SrcImageDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(SrcImageDescriptor, dataType);
LLGL_STATIC_ASSERT_OFFSET(SrcImageDescriptor, data);
LLGL_STATIC_ASSERT_OFFSET(SrcImageDescriptor, dataSize);

LLGL_STATIC_ASSERT_SIZE(DstImageDescriptor);
LLGL_STATIC_ASSERT_OFFSET(DstImageDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(DstImageDescriptor, dataType);
LLGL_STATIC_ASSERT_OFFSET(DstImageDescriptor, data);
LLGL_STATIC_ASSERT_OFFSET(DstImageDescriptor, dataSize);

LLGL_STATIC_ASSERT_SIZE(SamplerDescriptor);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, addressModeU);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, addressModeV);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, addressModeW);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, minFilter);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, magFilter);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, mipMapFilter);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, mipMapEnabled);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, mipMapLODBias);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, minLOD);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, maxLOD);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, maxAnisotropy);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, compareEnabled);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, compareOp);
LLGL_STATIC_ASSERT_OFFSET(SamplerDescriptor, borderColor);

LLGL_STATIC_ASSERT_SIZE(ResourceViewDescriptor);
LLGL_STATIC_ASSERT_OFFSET(ResourceViewDescriptor, resource);
LLGL_STATIC_ASSERT_OFFSET(ResourceViewDescriptor, textureView);
LLGL_STATIC_ASSERT_OFFSET(ResourceViewDescriptor, bufferView);
LLGL_STATIC_ASSERT_OFFSET(ResourceViewDescriptor, initialCount);

LLGL_STATIC_ASSERT_SIZE(ResourceHeapDescriptor);
LLGL_STATIC_ASSERT_OFFSET(ResourceHeapDescriptor, pipelineLayout);
LLGL_STATIC_ASSERT_OFFSET(ResourceHeapDescriptor, numResourceViews);
LLGL_STATIC_ASSERT_OFFSET(ResourceHeapDescriptor, barrierFlags);

LLGL_STATIC_ASSERT_SIZE(ShaderMacro);
LLGL_STATIC_ASSERT_OFFSET(ShaderMacro, name);
LLGL_STATIC_ASSERT_OFFSET(ShaderMacro, definition);

LLGL_STATIC_ASSERT_SIZE(ComputeShaderAttributes);
LLGL_STATIC_ASSERT_OFFSET(ComputeShaderAttributes, workGroupSize);

LLGL_STATIC_ASSERT_SIZE(AttachmentDescriptor);
LLGL_STATIC_ASSERT_OFFSET(AttachmentDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(AttachmentDescriptor, texture);
LLGL_STATIC_ASSERT_OFFSET(AttachmentDescriptor, mipLevel);
LLGL_STATIC_ASSERT_OFFSET(AttachmentDescriptor, arrayLayer);

LLGL_STATIC_ASSERT_SIZE(RenderTargetDescriptor);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, renderPass);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, resolution);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, samples);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, colorAttachments);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, resolveAttachments);
LLGL_STATIC_ASSERT_OFFSET(RenderTargetDescriptor, depthStencilAttachment);

LLGL_STATIC_ASSERT_SIZE(BindingSlot);
LLGL_STATIC_ASSERT_OFFSET(BindingSlot, index);
LLGL_STATIC_ASSERT_OFFSET(BindingSlot, set);

LLGL_STATIC_ASSERT_SIZE(WindowBehavior);
LLGL_STATIC_ASSERT_OFFSET(WindowBehavior, disableClearOnResize);
LLGL_STATIC_ASSERT_OFFSET(WindowBehavior, moveAndResizeTimerID);

LLGL_STATIC_ASSERT_SIZE(QueryPipelineStatistics);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, inputAssemblyVertices);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, inputAssemblyPrimitives);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, vertexShaderInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, geometryShaderInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, geometryShaderPrimitives);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, clippingInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, clippingPrimitives);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, fragmentShaderInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, tessControlShaderInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, tessEvaluationShaderInvocations);
LLGL_STATIC_ASSERT_OFFSET(QueryPipelineStatistics, computeShaderInvocations);

LLGL_STATIC_ASSERT_SIZE(QueryHeapDescriptor);
LLGL_STATIC_ASSERT_OFFSET(QueryHeapDescriptor, type);
LLGL_STATIC_ASSERT_OFFSET(QueryHeapDescriptor, numQueries);
LLGL_STATIC_ASSERT_OFFSET(QueryHeapDescriptor, renderCondition);

LLGL_STATIC_ASSERT_SIZE(AttachmentFormatDescriptor);
LLGL_STATIC_ASSERT_OFFSET(AttachmentFormatDescriptor, format);
LLGL_STATIC_ASSERT_OFFSET(AttachmentFormatDescriptor, loadOp);
LLGL_STATIC_ASSERT_OFFSET(AttachmentFormatDescriptor, storeOp);

LLGL_STATIC_ASSERT_SIZE(RenderPassDescriptor);
LLGL_STATIC_ASSERT_OFFSET(RenderPassDescriptor, colorAttachments);
LLGL_STATIC_ASSERT_OFFSET(RenderPassDescriptor, depthAttachment);
LLGL_STATIC_ASSERT_OFFSET(RenderPassDescriptor, stencilAttachment);
LLGL_STATIC_ASSERT_OFFSET(RenderPassDescriptor, samples);

LLGL_STATIC_ASSERT_SIZE(DisplayModeDescriptor);
LLGL_STATIC_ASSERT_OFFSET(DisplayModeDescriptor, resolution);
LLGL_STATIC_ASSERT_OFFSET(DisplayModeDescriptor, refreshRate);

LLGL_STATIC_ASSERT_SIZE(DrawIndirectArguments);
LLGL_STATIC_ASSERT_OFFSET(DrawIndirectArguments, numVertices);
LLGL_STATIC_ASSERT_OFFSET(DrawIndirectArguments, numInstances);
LLGL_STATIC_ASSERT_OFFSET(DrawIndirectArguments, firstVertex);
LLGL_STATIC_ASSERT_OFFSET(DrawIndirectArguments, firstInstance);

LLGL_STATIC_ASSERT_SIZE(DrawIndexedIndirectArguments);
LLGL_STATIC_ASSERT_OFFSET(DrawIndexedIndirectArguments, numIndices);
LLGL_STATIC_ASSERT_OFFSET(DrawIndexedIndirectArguments, numInstances);
LLGL_STATIC_ASSERT_OFFSET(DrawIndexedIndirectArguments, firstIndex);
LLGL_STATIC_ASSERT_OFFSET(DrawIndexedIndirectArguments, vertexOffset);
LLGL_STATIC_ASSERT_OFFSET(DrawIndexedIndirectArguments, firstInstance);

LLGL_STATIC_ASSERT_SIZE(DrawPatchIndirectArguments);
LLGL_STATIC_ASSERT_OFFSET(DrawPatchIndirectArguments, numPatches);
LLGL_STATIC_ASSERT_OFFSET(DrawPatchIndirectArguments, numInstances);
LLGL_STATIC_ASSERT_OFFSET(DrawPatchIndirectArguments, firstPatch);
LLGL_STATIC_ASSERT_OFFSET(DrawPatchIndirectArguments, firstInstance);

LLGL_STATIC_ASSERT_SIZE(DispatchIndirectArguments);
LLGL_STATIC_ASSERT_OFFSET(DispatchIndirectArguments, numThreadGroups);


// } /namespace LLGL



// ================================================================================
