// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml and gl_angle_ext.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_enum_autogen.h:
//   Defines the GL/GLES entry points enumeration.

#ifndef COMMON_ENTRYPOINTSENUM_AUTOGEN_H_
#define COMMON_ENTRYPOINTSENUM_AUTOGEN_H_

namespace angle
{
enum class EntryPoint
{
    Invalid,
    CLBuildProgram,
    CLCloneKernel,
    CLCompileProgram,
    CLCreateBuffer,
    CLCreateBufferWithProperties,
    CLCreateCommandQueue,
    CLCreateCommandQueueWithProperties,
    CLCreateContext,
    CLCreateContextFromType,
    CLCreateImage,
    CLCreateImage2D,
    CLCreateImage3D,
    CLCreateImageWithProperties,
    CLCreateKernel,
    CLCreateKernelsInProgram,
    CLCreatePipe,
    CLCreateProgramWithBinary,
    CLCreateProgramWithBuiltInKernels,
    CLCreateProgramWithIL,
    CLCreateProgramWithSource,
    CLCreateSampler,
    CLCreateSamplerWithProperties,
    CLCreateSubBuffer,
    CLCreateSubDevices,
    CLCreateUserEvent,
    CLEnqueueBarrier,
    CLEnqueueBarrierWithWaitList,
    CLEnqueueCopyBuffer,
    CLEnqueueCopyBufferRect,
    CLEnqueueCopyBufferToImage,
    CLEnqueueCopyImage,
    CLEnqueueCopyImageToBuffer,
    CLEnqueueFillBuffer,
    CLEnqueueFillImage,
    CLEnqueueMapBuffer,
    CLEnqueueMapImage,
    CLEnqueueMarker,
    CLEnqueueMarkerWithWaitList,
    CLEnqueueMigrateMemObjects,
    CLEnqueueNDRangeKernel,
    CLEnqueueNativeKernel,
    CLEnqueueReadBuffer,
    CLEnqueueReadBufferRect,
    CLEnqueueReadImage,
    CLEnqueueSVMFree,
    CLEnqueueSVMMap,
    CLEnqueueSVMMemFill,
    CLEnqueueSVMMemcpy,
    CLEnqueueSVMMigrateMem,
    CLEnqueueSVMUnmap,
    CLEnqueueTask,
    CLEnqueueUnmapMemObject,
    CLEnqueueWaitForEvents,
    CLEnqueueWriteBuffer,
    CLEnqueueWriteBufferRect,
    CLEnqueueWriteImage,
    CLFinish,
    CLFlush,
    CLGetCommandQueueInfo,
    CLGetContextInfo,
    CLGetDeviceAndHostTimer,
    CLGetDeviceIDs,
    CLGetDeviceInfo,
    CLGetEventInfo,
    CLGetEventProfilingInfo,
    CLGetExtensionFunctionAddress,
    CLGetExtensionFunctionAddressForPlatform,
    CLGetHostTimer,
    CLGetImageInfo,
    CLGetKernelArgInfo,
    CLGetKernelInfo,
    CLGetKernelSubGroupInfo,
    CLGetKernelWorkGroupInfo,
    CLGetMemObjectInfo,
    CLGetPipeInfo,
    CLGetPlatformIDs,
    CLGetPlatformInfo,
    CLGetProgramBuildInfo,
    CLGetProgramInfo,
    CLGetSamplerInfo,
    CLGetSupportedImageFormats,
    CLIcdGetPlatformIDsKHR,
    CLLinkProgram,
    CLReleaseCommandQueue,
    CLReleaseContext,
    CLReleaseDevice,
    CLReleaseEvent,
    CLReleaseKernel,
    CLReleaseMemObject,
    CLReleaseProgram,
    CLReleaseSampler,
    CLRetainCommandQueue,
    CLRetainContext,
    CLRetainDevice,
    CLRetainEvent,
    CLRetainKernel,
    CLRetainMemObject,
    CLRetainProgram,
    CLRetainSampler,
    CLSVMAlloc,
    CLSVMFree,
    CLSetCommandQueueProperty,
    CLSetContextDestructorCallback,
    CLSetDefaultDeviceCommandQueue,
    CLSetEventCallback,
    CLSetKernelArg,
    CLSetKernelArgSVMPointer,
    CLSetKernelExecInfo,
    CLSetMemObjectDestructorCallback,
    CLSetProgramReleaseCallback,
    CLSetProgramSpecializationConstant,
    CLSetUserEventStatus,
    CLUnloadCompiler,
    CLUnloadPlatformCompiler,
    CLWaitForEvents,
    EGLAcquireExternalContextANGLE,
    EGLBindAPI,
    EGLBindTexImage,
    EGLChooseConfig,
    EGLClientWaitSync,
    EGLClientWaitSyncKHR,
    EGLCopyBuffers,
    EGLCopyMetalSharedEventANGLE,
    EGLCreateContext,
    EGLCreateDeviceANGLE,
    EGLCreateImage,
    EGLCreateImageKHR,
    EGLCreateNativeClientBufferANDROID,
    EGLCreatePbufferFromClientBuffer,
    EGLCreatePbufferSurface,
    EGLCreatePixmapSurface,
    EGLCreatePlatformPixmapSurface,
    EGLCreatePlatformPixmapSurfaceEXT,
    EGLCreatePlatformWindowSurface,
    EGLCreatePlatformWindowSurfaceEXT,
    EGLCreateStreamKHR,
    EGLCreateStreamProducerD3DTextureANGLE,
    EGLCreateSync,
    EGLCreateSyncKHR,
    EGLCreateWindowSurface,
    EGLDebugMessageControlKHR,
    EGLDestroyContext,
    EGLDestroyImage,
    EGLDestroyImageKHR,
    EGLDestroyStreamKHR,
    EGLDestroySurface,
    EGLDestroySync,
    EGLDestroySyncKHR,
    EGLDupNativeFenceFDANDROID,
    EGLExportVkImageANGLE,
    EGLForceGPUSwitchANGLE,
    EGLGetCompositorTimingANDROID,
    EGLGetCompositorTimingSupportedANDROID,
    EGLGetConfigAttrib,
    EGLGetConfigs,
    EGLGetCurrentContext,
    EGLGetCurrentDisplay,
    EGLGetCurrentSurface,
    EGLGetDisplay,
    EGLGetError,
    EGLGetFrameTimestampSupportedANDROID,
    EGLGetFrameTimestampsANDROID,
    EGLGetMscRateANGLE,
    EGLGetNativeClientBufferANDROID,
    EGLGetNextFrameIdANDROID,
    EGLGetPlatformDisplay,
    EGLGetPlatformDisplayEXT,
    EGLGetProcAddress,
    EGLGetSyncAttrib,
    EGLGetSyncAttribKHR,
    EGLGetSyncValuesCHROMIUM,
    EGLHandleGPUSwitchANGLE,
    EGLInitialize,
    EGLLabelObjectKHR,
    EGLLockSurfaceKHR,
    EGLMakeCurrent,
    EGLPostSubBufferNV,
    EGLPrepareSwapBuffersANGLE,
    EGLPresentationTimeANDROID,
    EGLProgramCacheGetAttribANGLE,
    EGLProgramCachePopulateANGLE,
    EGLProgramCacheQueryANGLE,
    EGLProgramCacheResizeANGLE,
    EGLQueryAPI,
    EGLQueryContext,
    EGLQueryDebugKHR,
    EGLQueryDeviceAttribEXT,
    EGLQueryDeviceStringEXT,
    EGLQueryDisplayAttribANGLE,
    EGLQueryDisplayAttribEXT,
    EGLQueryDmaBufFormatsEXT,
    EGLQueryDmaBufModifiersEXT,
    EGLQueryStreamKHR,
    EGLQueryStreamu64KHR,
    EGLQueryString,
    EGLQueryStringiANGLE,
    EGLQuerySupportedCompressionRatesEXT,
    EGLQuerySurface,
    EGLQuerySurface64KHR,
    EGLQuerySurfacePointerANGLE,
    EGLReacquireHighPowerGPUANGLE,
    EGLReleaseDeviceANGLE,
    EGLReleaseExternalContextANGLE,
    EGLReleaseHighPowerGPUANGLE,
    EGLReleaseTexImage,
    EGLReleaseThread,
    EGLSetBlobCacheFuncsANDROID,
    EGLSetDamageRegionKHR,
    EGLSetValidationEnabledANGLE,
    EGLSignalSyncKHR,
    EGLStreamAttribKHR,
    EGLStreamConsumerAcquireKHR,
    EGLStreamConsumerGLTextureExternalAttribsNV,
    EGLStreamConsumerGLTextureExternalKHR,
    EGLStreamConsumerReleaseKHR,
    EGLStreamPostD3DTextureANGLE,
    EGLSurfaceAttrib,
    EGLSwapBuffers,
    EGLSwapBuffersWithDamageKHR,
    EGLSwapBuffersWithFrameTokenANGLE,
    EGLSwapInterval,
    EGLTerminate,
    EGLToggleWindowed,
    EGLUnlockSurfaceKHR,
    EGLWaitClient,
    EGLWaitGL,
    EGLWaitNative,
    EGLWaitSync,
    EGLWaitSyncKHR,
    EGLWaitUntilWorkScheduledANGLE,
    GLAcquireTexturesANGLE,
    GLActiveShaderProgram,
    GLActiveShaderProgramEXT,
    GLActiveTexture,
    GLAlphaFunc,
    GLAlphaFuncx,
    GLAttachShader,
    GLBeginPerfMonitorAMD,
    GLBeginPixelLocalStorageANGLE,
    GLBeginQuery,
    GLBeginQueryEXT,
    GLBeginTransformFeedback,
    GLBindAttribLocation,
    GLBindBuffer,
    GLBindBufferBase,
    GLBindBufferRange,
    GLBindFragDataLocationEXT,
    GLBindFragDataLocationIndexedEXT,
    GLBindFramebuffer,
    GLBindFramebufferOES,
    GLBindImageTexture,
    GLBindProgramPipeline,
    GLBindProgramPipelineEXT,
    GLBindRenderbuffer,
    GLBindRenderbufferOES,
    GLBindSampler,
    GLBindTexture,
    GLBindTransformFeedback,
    GLBindUniformLocationCHROMIUM,
    GLBindVertexArray,
    GLBindVertexArrayOES,
    GLBindVertexBuffer,
    GLBlendBarrier,
    GLBlendBarrierKHR,
    GLBlendColor,
    GLBlendEquation,
    GLBlendEquationOES,
    GLBlendEquationSeparate,
    GLBlendEquationSeparatei,
    GLBlendEquationSeparateiEXT,
    GLBlendEquationSeparateiOES,
    GLBlendEquationi,
    GLBlendEquationiEXT,
    GLBlendEquationiOES,
    GLBlendFunc,
    GLBlendFuncSeparate,
    GLBlendFuncSeparatei,
    GLBlendFuncSeparateiEXT,
    GLBlendFuncSeparateiOES,
    GLBlendFunci,
    GLBlendFunciEXT,
    GLBlendFunciOES,
    GLBlitFramebuffer,
    GLBlitFramebufferANGLE,
    GLBlitFramebufferNV,
    GLBlobCacheCallbacksANGLE,
    GLBufferData,
    GLBufferStorageEXT,
    GLBufferStorageExternalEXT,
    GLBufferStorageMemEXT,
    GLBufferSubData,
    GLCheckFramebufferStatus,
    GLCheckFramebufferStatusOES,
    GLClear,
    GLClearBufferfi,
    GLClearBufferfv,
    GLClearBufferiv,
    GLClearBufferuiv,
    GLClearColor,
    GLClearColorx,
    GLClearDepthf,
    GLClearDepthx,
    GLClearStencil,
    GLClearTexImageEXT,
    GLClearTexSubImageEXT,
    GLClientActiveTexture,
    GLClientWaitSync,
    GLClipControlEXT,
    GLClipPlanef,
    GLClipPlanex,
    GLColor4f,
    GLColor4ub,
    GLColor4x,
    GLColorMask,
    GLColorMaski,
    GLColorMaskiEXT,
    GLColorMaskiOES,
    GLColorPointer,
    GLCompileShader,
    GLCompressedCopyTextureCHROMIUM,
    GLCompressedTexImage2D,
    GLCompressedTexImage2DRobustANGLE,
    GLCompressedTexImage3D,
    GLCompressedTexImage3DOES,
    GLCompressedTexImage3DRobustANGLE,
    GLCompressedTexSubImage2D,
    GLCompressedTexSubImage2DRobustANGLE,
    GLCompressedTexSubImage3D,
    GLCompressedTexSubImage3DOES,
    GLCompressedTexSubImage3DRobustANGLE,
    GLCopyBufferSubData,
    GLCopyImageSubData,
    GLCopyImageSubDataEXT,
    GLCopyImageSubDataOES,
    GLCopySubTexture3DANGLE,
    GLCopySubTextureCHROMIUM,
    GLCopyTexImage2D,
    GLCopyTexSubImage2D,
    GLCopyTexSubImage3D,
    GLCopyTexSubImage3DOES,
    GLCopyTexture3DANGLE,
    GLCopyTextureCHROMIUM,
    GLCoverageModulationCHROMIUM,
    GLCreateMemoryObjectsEXT,
    GLCreateProgram,
    GLCreateShader,
    GLCreateShaderProgramv,
    GLCreateShaderProgramvEXT,
    GLCullFace,
    GLCurrentPaletteMatrixOES,
    GLDebugMessageCallback,
    GLDebugMessageCallbackKHR,
    GLDebugMessageControl,
    GLDebugMessageControlKHR,
    GLDebugMessageInsert,
    GLDebugMessageInsertKHR,
    GLDeleteBuffers,
    GLDeleteFencesNV,
    GLDeleteFramebuffers,
    GLDeleteFramebuffersOES,
    GLDeleteMemoryObjectsEXT,
    GLDeletePerfMonitorsAMD,
    GLDeleteProgram,
    GLDeleteProgramPipelines,
    GLDeleteProgramPipelinesEXT,
    GLDeleteQueries,
    GLDeleteQueriesEXT,
    GLDeleteRenderbuffers,
    GLDeleteRenderbuffersOES,
    GLDeleteSamplers,
    GLDeleteSemaphoresEXT,
    GLDeleteShader,
    GLDeleteSync,
    GLDeleteTextures,
    GLDeleteTransformFeedbacks,
    GLDeleteVertexArrays,
    GLDeleteVertexArraysOES,
    GLDepthFunc,
    GLDepthMask,
    GLDepthRangef,
    GLDepthRangex,
    GLDetachShader,
    GLDisable,
    GLDisableClientState,
    GLDisableExtensionANGLE,
    GLDisableVertexAttribArray,
    GLDisablei,
    GLDisableiEXT,
    GLDisableiOES,
    GLDiscardFramebufferEXT,
    GLDispatchCompute,
    GLDispatchComputeIndirect,
    GLDrawArrays,
    GLDrawArraysIndirect,
    GLDrawArraysInstanced,
    GLDrawArraysInstancedANGLE,
    GLDrawArraysInstancedBaseInstanceANGLE,
    GLDrawArraysInstancedBaseInstanceEXT,
    GLDrawArraysInstancedEXT,
    GLDrawBuffers,
    GLDrawBuffersEXT,
    GLDrawElements,
    GLDrawElementsBaseVertex,
    GLDrawElementsBaseVertexEXT,
    GLDrawElementsBaseVertexOES,
    GLDrawElementsIndirect,
    GLDrawElementsInstanced,
    GLDrawElementsInstancedANGLE,
    GLDrawElementsInstancedBaseInstanceEXT,
    GLDrawElementsInstancedBaseVertex,
    GLDrawElementsInstancedBaseVertexBaseInstanceANGLE,
    GLDrawElementsInstancedBaseVertexBaseInstanceEXT,
    GLDrawElementsInstancedBaseVertexEXT,
    GLDrawElementsInstancedBaseVertexOES,
    GLDrawElementsInstancedEXT,
    GLDrawRangeElements,
    GLDrawRangeElementsBaseVertex,
    GLDrawRangeElementsBaseVertexEXT,
    GLDrawRangeElementsBaseVertexOES,
    GLDrawTexfOES,
    GLDrawTexfvOES,
    GLDrawTexiOES,
    GLDrawTexivOES,
    GLDrawTexsOES,
    GLDrawTexsvOES,
    GLDrawTexxOES,
    GLDrawTexxvOES,
    GLEGLImageTargetRenderbufferStorageOES,
    GLEGLImageTargetTexStorageEXT,
    GLEGLImageTargetTexture2DOES,
    GLEGLImageTargetTextureStorageEXT,
    GLEnable,
    GLEnableClientState,
    GLEnableVertexAttribArray,
    GLEnablei,
    GLEnableiEXT,
    GLEnableiOES,
    GLEndPerfMonitorAMD,
    GLEndPixelLocalStorageANGLE,
    GLEndQuery,
    GLEndQueryEXT,
    GLEndTilingQCOM,
    GLEndTransformFeedback,
    GLFenceSync,
    GLFinish,
    GLFinishFenceNV,
    GLFlush,
    GLFlushMappedBufferRange,
    GLFlushMappedBufferRangeEXT,
    GLFogf,
    GLFogfv,
    GLFogx,
    GLFogxv,
    GLFramebufferFetchBarrierEXT,
    GLFramebufferFoveationConfigQCOM,
    GLFramebufferFoveationParametersQCOM,
    GLFramebufferMemorylessPixelLocalStorageANGLE,
    GLFramebufferParameteri,
    GLFramebufferParameteriMESA,
    GLFramebufferPixelLocalClearValuefvANGLE,
    GLFramebufferPixelLocalClearValueivANGLE,
    GLFramebufferPixelLocalClearValueuivANGLE,
    GLFramebufferPixelLocalStorageInterruptANGLE,
    GLFramebufferPixelLocalStorageRestoreANGLE,
    GLFramebufferRenderbuffer,
    GLFramebufferRenderbufferOES,
    GLFramebufferTexture,
    GLFramebufferTexture2D,
    GLFramebufferTexture2DMultisampleEXT,
    GLFramebufferTexture2DOES,
    GLFramebufferTexture3DOES,
    GLFramebufferTextureEXT,
    GLFramebufferTextureLayer,
    GLFramebufferTextureMultiviewOVR,
    GLFramebufferTextureOES,
    GLFramebufferTexturePixelLocalStorageANGLE,
    GLFrontFace,
    GLFrustumf,
    GLFrustumx,
    GLGenBuffers,
    GLGenFencesNV,
    GLGenFramebuffers,
    GLGenFramebuffersOES,
    GLGenPerfMonitorsAMD,
    GLGenProgramPipelines,
    GLGenProgramPipelinesEXT,
    GLGenQueries,
    GLGenQueriesEXT,
    GLGenRenderbuffers,
    GLGenRenderbuffersOES,
    GLGenSamplers,
    GLGenSemaphoresEXT,
    GLGenTextures,
    GLGenTransformFeedbacks,
    GLGenVertexArrays,
    GLGenVertexArraysOES,
    GLGenerateMipmap,
    GLGenerateMipmapOES,
    GLGetActiveAttrib,
    GLGetActiveUniform,
    GLGetActiveUniformBlockName,
    GLGetActiveUniformBlockiv,
    GLGetActiveUniformBlockivRobustANGLE,
    GLGetActiveUniformsiv,
    GLGetAttachedShaders,
    GLGetAttribLocation,
    GLGetBooleani_v,
    GLGetBooleani_vRobustANGLE,
    GLGetBooleanv,
    GLGetBooleanvRobustANGLE,
    GLGetBufferParameteri64v,
    GLGetBufferParameteri64vRobustANGLE,
    GLGetBufferParameteriv,
    GLGetBufferParameterivRobustANGLE,
    GLGetBufferPointerv,
    GLGetBufferPointervOES,
    GLGetBufferPointervRobustANGLE,
    GLGetClipPlanef,
    GLGetClipPlanex,
    GLGetCompressedTexImageANGLE,
    GLGetDebugMessageLog,
    GLGetDebugMessageLogKHR,
    GLGetError,
    GLGetFenceivNV,
    GLGetFixedv,
    GLGetFloatv,
    GLGetFloatvRobustANGLE,
    GLGetFragDataIndexEXT,
    GLGetFragDataLocation,
    GLGetFramebufferAttachmentParameteriv,
    GLGetFramebufferAttachmentParameterivOES,
    GLGetFramebufferAttachmentParameterivRobustANGLE,
    GLGetFramebufferParameteriv,
    GLGetFramebufferParameterivMESA,
    GLGetFramebufferParameterivRobustANGLE,
    GLGetFramebufferPixelLocalStorageParameterfvANGLE,
    GLGetFramebufferPixelLocalStorageParameterfvRobustANGLE,
    GLGetFramebufferPixelLocalStorageParameterivANGLE,
    GLGetFramebufferPixelLocalStorageParameterivRobustANGLE,
    GLGetGraphicsResetStatus,
    GLGetGraphicsResetStatusEXT,
    GLGetGraphicsResetStatusKHR,
    GLGetInteger64i_v,
    GLGetInteger64i_vRobustANGLE,
    GLGetInteger64v,
    GLGetInteger64vEXT,
    GLGetInteger64vRobustANGLE,
    GLGetIntegeri_v,
    GLGetIntegeri_vRobustANGLE,
    GLGetIntegerv,
    GLGetIntegervRobustANGLE,
    GLGetInternalformativ,
    GLGetInternalformativRobustANGLE,
    GLGetLightfv,
    GLGetLightxv,
    GLGetMaterialfv,
    GLGetMaterialxv,
    GLGetMemoryObjectParameterivEXT,
    GLGetMultisamplefv,
    GLGetMultisamplefvANGLE,
    GLGetMultisamplefvRobustANGLE,
    GLGetObjectLabel,
    GLGetObjectLabelEXT,
    GLGetObjectLabelKHR,
    GLGetObjectPtrLabel,
    GLGetObjectPtrLabelKHR,
    GLGetPerfMonitorCounterDataAMD,
    GLGetPerfMonitorCounterInfoAMD,
    GLGetPerfMonitorCounterStringAMD,
    GLGetPerfMonitorCountersAMD,
    GLGetPerfMonitorGroupStringAMD,
    GLGetPerfMonitorGroupsAMD,
    GLGetPointerv,
    GLGetPointervANGLE,
    GLGetPointervKHR,
    GLGetPointervRobustANGLERobustANGLE,
    GLGetProgramBinary,
    GLGetProgramBinaryOES,
    GLGetProgramInfoLog,
    GLGetProgramInterfaceiv,
    GLGetProgramInterfaceivRobustANGLE,
    GLGetProgramPipelineInfoLog,
    GLGetProgramPipelineInfoLogEXT,
    GLGetProgramPipelineiv,
    GLGetProgramPipelineivEXT,
    GLGetProgramResourceIndex,
    GLGetProgramResourceLocation,
    GLGetProgramResourceLocationIndexEXT,
    GLGetProgramResourceName,
    GLGetProgramResourceiv,
    GLGetProgramiv,
    GLGetProgramivRobustANGLE,
    GLGetQueryObjecti64vEXT,
    GLGetQueryObjecti64vRobustANGLE,
    GLGetQueryObjectivEXT,
    GLGetQueryObjectivRobustANGLE,
    GLGetQueryObjectui64vEXT,
    GLGetQueryObjectui64vRobustANGLE,
    GLGetQueryObjectuiv,
    GLGetQueryObjectuivEXT,
    GLGetQueryObjectuivRobustANGLE,
    GLGetQueryiv,
    GLGetQueryivEXT,
    GLGetQueryivRobustANGLE,
    GLGetRenderbufferImageANGLE,
    GLGetRenderbufferParameteriv,
    GLGetRenderbufferParameterivOES,
    GLGetRenderbufferParameterivRobustANGLE,
    GLGetSamplerParameterIiv,
    GLGetSamplerParameterIivEXT,
    GLGetSamplerParameterIivOES,
    GLGetSamplerParameterIivRobustANGLE,
    GLGetSamplerParameterIuiv,
    GLGetSamplerParameterIuivEXT,
    GLGetSamplerParameterIuivOES,
    GLGetSamplerParameterIuivRobustANGLE,
    GLGetSamplerParameterfv,
    GLGetSamplerParameterfvRobustANGLE,
    GLGetSamplerParameteriv,
    GLGetSamplerParameterivRobustANGLE,
    GLGetSemaphoreParameterui64vEXT,
    GLGetShaderInfoLog,
    GLGetShaderPrecisionFormat,
    GLGetShaderSource,
    GLGetShaderiv,
    GLGetShaderivRobustANGLE,
    GLGetString,
    GLGetStringi,
    GLGetSynciv,
    GLGetTexEnvfv,
    GLGetTexEnviv,
    GLGetTexEnvxv,
    GLGetTexGenfvOES,
    GLGetTexGenivOES,
    GLGetTexGenxvOES,
    GLGetTexImageANGLE,
    GLGetTexLevelParameterfv,
    GLGetTexLevelParameterfvANGLE,
    GLGetTexLevelParameterfvRobustANGLE,
    GLGetTexLevelParameteriv,
    GLGetTexLevelParameterivANGLE,
    GLGetTexLevelParameterivRobustANGLE,
    GLGetTexParameterIiv,
    GLGetTexParameterIivEXT,
    GLGetTexParameterIivOES,
    GLGetTexParameterIivRobustANGLE,
    GLGetTexParameterIuiv,
    GLGetTexParameterIuivEXT,
    GLGetTexParameterIuivOES,
    GLGetTexParameterIuivRobustANGLE,
    GLGetTexParameterfv,
    GLGetTexParameterfvRobustANGLE,
    GLGetTexParameteriv,
    GLGetTexParameterivRobustANGLE,
    GLGetTexParameterxv,
    GLGetTransformFeedbackVarying,
    GLGetTranslatedShaderSourceANGLE,
    GLGetUniformBlockIndex,
    GLGetUniformIndices,
    GLGetUniformLocation,
    GLGetUniformfv,
    GLGetUniformfvRobustANGLE,
    GLGetUniformiv,
    GLGetUniformivRobustANGLE,
    GLGetUniformuiv,
    GLGetUniformuivRobustANGLE,
    GLGetUnsignedBytei_vEXT,
    GLGetUnsignedBytevEXT,
    GLGetVertexAttribIiv,
    GLGetVertexAttribIivRobustANGLE,
    GLGetVertexAttribIuiv,
    GLGetVertexAttribIuivRobustANGLE,
    GLGetVertexAttribPointerv,
    GLGetVertexAttribPointervRobustANGLE,
    GLGetVertexAttribfv,
    GLGetVertexAttribfvRobustANGLE,
    GLGetVertexAttribiv,
    GLGetVertexAttribivRobustANGLE,
    GLGetnUniformfv,
    GLGetnUniformfvEXT,
    GLGetnUniformfvKHR,
    GLGetnUniformfvRobustANGLE,
    GLGetnUniformiv,
    GLGetnUniformivEXT,
    GLGetnUniformivKHR,
    GLGetnUniformivRobustANGLE,
    GLGetnUniformuiv,
    GLGetnUniformuivKHR,
    GLGetnUniformuivRobustANGLE,
    GLHint,
    GLImportMemoryFdEXT,
    GLImportMemoryZirconHandleANGLE,
    GLImportSemaphoreFdEXT,
    GLImportSemaphoreZirconHandleANGLE,
    GLInsertEventMarkerEXT,
    GLInvalidateFramebuffer,
    GLInvalidateSubFramebuffer,
    GLInvalidateTextureANGLE,
    GLIsBuffer,
    GLIsEnabled,
    GLIsEnabledi,
    GLIsEnablediEXT,
    GLIsEnablediOES,
    GLIsFenceNV,
    GLIsFramebuffer,
    GLIsFramebufferOES,
    GLIsMemoryObjectEXT,
    GLIsProgram,
    GLIsProgramPipeline,
    GLIsProgramPipelineEXT,
    GLIsQuery,
    GLIsQueryEXT,
    GLIsRenderbuffer,
    GLIsRenderbufferOES,
    GLIsSampler,
    GLIsSemaphoreEXT,
    GLIsShader,
    GLIsSync,
    GLIsTexture,
    GLIsTransformFeedback,
    GLIsVertexArray,
    GLIsVertexArrayOES,
    GLLabelObjectEXT,
    GLLightModelf,
    GLLightModelfv,
    GLLightModelx,
    GLLightModelxv,
    GLLightf,
    GLLightfv,
    GLLightx,
    GLLightxv,
    GLLineWidth,
    GLLineWidthx,
    GLLinkProgram,
    GLLoadIdentity,
    GLLoadMatrixf,
    GLLoadMatrixx,
    GLLoadPaletteFromModelViewMatrixOES,
    GLLogicOp,
    GLLogicOpANGLE,
    GLLoseContextCHROMIUM,
    GLMapBufferOES,
    GLMapBufferRange,
    GLMapBufferRangeEXT,
    GLMaterialf,
    GLMaterialfv,
    GLMaterialx,
    GLMaterialxv,
    GLMatrixIndexPointerOES,
    GLMatrixMode,
    GLMaxShaderCompilerThreadsKHR,
    GLMemoryBarrier,
    GLMemoryBarrierByRegion,
    GLMemoryObjectParameterivEXT,
    GLMinSampleShading,
    GLMinSampleShadingOES,
    GLMultMatrixf,
    GLMultMatrixx,
    GLMultiDrawArraysANGLE,
    GLMultiDrawArraysIndirectEXT,
    GLMultiDrawArraysInstancedANGLE,
    GLMultiDrawArraysInstancedBaseInstanceANGLE,
    GLMultiDrawElementsANGLE,
    GLMultiDrawElementsBaseVertexEXT,
    GLMultiDrawElementsIndirectEXT,
    GLMultiDrawElementsInstancedANGLE,
    GLMultiDrawElementsInstancedBaseVertexBaseInstanceANGLE,
    GLMultiTexCoord4f,
    GLMultiTexCoord4x,
    GLNamedBufferStorageExternalEXT,
    GLNormal3f,
    GLNormal3x,
    GLNormalPointer,
    GLObjectLabel,
    GLObjectLabelKHR,
    GLObjectPtrLabel,
    GLObjectPtrLabelKHR,
    GLOrthof,
    GLOrthox,
    GLPatchParameteri,
    GLPatchParameteriEXT,
    GLPatchParameteriOES,
    GLPauseTransformFeedback,
    GLPixelLocalStorageBarrierANGLE,
    GLPixelStorei,
    GLPointParameterf,
    GLPointParameterfv,
    GLPointParameterx,
    GLPointParameterxv,
    GLPointSize,
    GLPointSizePointerOES,
    GLPointSizex,
    GLPolygonModeANGLE,
    GLPolygonModeNV,
    GLPolygonOffset,
    GLPolygonOffsetClampEXT,
    GLPolygonOffsetx,
    GLPopDebugGroup,
    GLPopDebugGroupKHR,
    GLPopGroupMarkerEXT,
    GLPopMatrix,
    GLPrimitiveBoundingBox,
    GLPrimitiveBoundingBoxEXT,
    GLPrimitiveBoundingBoxOES,
    GLProgramBinary,
    GLProgramBinaryOES,
    GLProgramParameteri,
    GLProgramParameteriEXT,
    GLProgramUniform1f,
    GLProgramUniform1fEXT,
    GLProgramUniform1fv,
    GLProgramUniform1fvEXT,
    GLProgramUniform1i,
    GLProgramUniform1iEXT,
    GLProgramUniform1iv,
    GLProgramUniform1ivEXT,
    GLProgramUniform1ui,
    GLProgramUniform1uiEXT,
    GLProgramUniform1uiv,
    GLProgramUniform1uivEXT,
    GLProgramUniform2f,
    GLProgramUniform2fEXT,
    GLProgramUniform2fv,
    GLProgramUniform2fvEXT,
    GLProgramUniform2i,
    GLProgramUniform2iEXT,
    GLProgramUniform2iv,
    GLProgramUniform2ivEXT,
    GLProgramUniform2ui,
    GLProgramUniform2uiEXT,
    GLProgramUniform2uiv,
    GLProgramUniform2uivEXT,
    GLProgramUniform3f,
    GLProgramUniform3fEXT,
    GLProgramUniform3fv,
    GLProgramUniform3fvEXT,
    GLProgramUniform3i,
    GLProgramUniform3iEXT,
    GLProgramUniform3iv,
    GLProgramUniform3ivEXT,
    GLProgramUniform3ui,
    GLProgramUniform3uiEXT,
    GLProgramUniform3uiv,
    GLProgramUniform3uivEXT,
    GLProgramUniform4f,
    GLProgramUniform4fEXT,
    GLProgramUniform4fv,
    GLProgramUniform4fvEXT,
    GLProgramUniform4i,
    GLProgramUniform4iEXT,
    GLProgramUniform4iv,
    GLProgramUniform4ivEXT,
    GLProgramUniform4ui,
    GLProgramUniform4uiEXT,
    GLProgramUniform4uiv,
    GLProgramUniform4uivEXT,
    GLProgramUniformMatrix2fv,
    GLProgramUniformMatrix2fvEXT,
    GLProgramUniformMatrix2x3fv,
    GLProgramUniformMatrix2x3fvEXT,
    GLProgramUniformMatrix2x4fv,
    GLProgramUniformMatrix2x4fvEXT,
    GLProgramUniformMatrix3fv,
    GLProgramUniformMatrix3fvEXT,
    GLProgramUniformMatrix3x2fv,
    GLProgramUniformMatrix3x2fvEXT,
    GLProgramUniformMatrix3x4fv,
    GLProgramUniformMatrix3x4fvEXT,
    GLProgramUniformMatrix4fv,
    GLProgramUniformMatrix4fvEXT,
    GLProgramUniformMatrix4x2fv,
    GLProgramUniformMatrix4x2fvEXT,
    GLProgramUniformMatrix4x3fv,
    GLProgramUniformMatrix4x3fvEXT,
    GLProvokingVertexANGLE,
    GLPushDebugGroup,
    GLPushDebugGroupKHR,
    GLPushGroupMarkerEXT,
    GLPushMatrix,
    GLQueryCounterEXT,
    GLQueryMatrixxOES,
    GLReadBuffer,
    GLReadPixels,
    GLReadPixelsRobustANGLE,
    GLReadnPixels,
    GLReadnPixelsEXT,
    GLReadnPixelsKHR,
    GLReadnPixelsRobustANGLE,
    GLReleaseShaderCompiler,
    GLReleaseTexturesANGLE,
    GLRenderbufferStorage,
    GLRenderbufferStorageMultisample,
    GLRenderbufferStorageMultisampleANGLE,
    GLRenderbufferStorageMultisampleEXT,
    GLRenderbufferStorageOES,
    GLRequestExtensionANGLE,
    GLResumeTransformFeedback,
    GLRotatef,
    GLRotatex,
    GLSampleCoverage,
    GLSampleCoveragex,
    GLSampleMaski,
    GLSampleMaskiANGLE,
    GLSamplerParameterIiv,
    GLSamplerParameterIivEXT,
    GLSamplerParameterIivOES,
    GLSamplerParameterIivRobustANGLE,
    GLSamplerParameterIuiv,
    GLSamplerParameterIuivEXT,
    GLSamplerParameterIuivOES,
    GLSamplerParameterIuivRobustANGLE,
    GLSamplerParameterf,
    GLSamplerParameterfv,
    GLSamplerParameterfvRobustANGLE,
    GLSamplerParameteri,
    GLSamplerParameteriv,
    GLSamplerParameterivRobustANGLE,
    GLScalef,
    GLScalex,
    GLScissor,
    GLSelectPerfMonitorCountersAMD,
    GLSemaphoreParameterui64vEXT,
    GLSetFenceNV,
    GLShadeModel,
    GLShaderBinary,
    GLShaderSource,
    GLShadingRateQCOM,
    GLSignalSemaphoreEXT,
    GLStartTilingQCOM,
    GLStencilFunc,
    GLStencilFuncSeparate,
    GLStencilMask,
    GLStencilMaskSeparate,
    GLStencilOp,
    GLStencilOpSeparate,
    GLTestFenceNV,
    GLTexBuffer,
    GLTexBufferEXT,
    GLTexBufferOES,
    GLTexBufferRange,
    GLTexBufferRangeEXT,
    GLTexBufferRangeOES,
    GLTexCoordPointer,
    GLTexEnvf,
    GLTexEnvfv,
    GLTexEnvi,
    GLTexEnviv,
    GLTexEnvx,
    GLTexEnvxv,
    GLTexGenfOES,
    GLTexGenfvOES,
    GLTexGeniOES,
    GLTexGenivOES,
    GLTexGenxOES,
    GLTexGenxvOES,
    GLTexImage2D,
    GLTexImage2DExternalANGLE,
    GLTexImage2DRobustANGLE,
    GLTexImage3D,
    GLTexImage3DOES,
    GLTexImage3DRobustANGLE,
    GLTexParameterIiv,
    GLTexParameterIivEXT,
    GLTexParameterIivOES,
    GLTexParameterIivRobustANGLE,
    GLTexParameterIuiv,
    GLTexParameterIuivEXT,
    GLTexParameterIuivOES,
    GLTexParameterIuivRobustANGLE,
    GLTexParameterf,
    GLTexParameterfv,
    GLTexParameterfvRobustANGLE,
    GLTexParameteri,
    GLTexParameteriv,
    GLTexParameterivRobustANGLE,
    GLTexParameterx,
    GLTexParameterxv,
    GLTexStorage1DEXT,
    GLTexStorage2D,
    GLTexStorage2DEXT,
    GLTexStorage2DMultisample,
    GLTexStorage2DMultisampleANGLE,
    GLTexStorage3D,
    GLTexStorage3DEXT,
    GLTexStorage3DMultisample,
    GLTexStorage3DMultisampleOES,
    GLTexStorageAttribs2DEXT,
    GLTexStorageAttribs3DEXT,
    GLTexStorageMem2DEXT,
    GLTexStorageMem2DMultisampleEXT,
    GLTexStorageMem3DEXT,
    GLTexStorageMem3DMultisampleEXT,
    GLTexStorageMemFlags2DANGLE,
    GLTexStorageMemFlags2DMultisampleANGLE,
    GLTexStorageMemFlags3DANGLE,
    GLTexStorageMemFlags3DMultisampleANGLE,
    GLTexSubImage2D,
    GLTexSubImage2DRobustANGLE,
    GLTexSubImage3D,
    GLTexSubImage3DOES,
    GLTexSubImage3DRobustANGLE,
    GLTextureFoveationParametersQCOM,
    GLTransformFeedbackVaryings,
    GLTranslatef,
    GLTranslatex,
    GLUniform1f,
    GLUniform1fv,
    GLUniform1i,
    GLUniform1iv,
    GLUniform1ui,
    GLUniform1uiv,
    GLUniform2f,
    GLUniform2fv,
    GLUniform2i,
    GLUniform2iv,
    GLUniform2ui,
    GLUniform2uiv,
    GLUniform3f,
    GLUniform3fv,
    GLUniform3i,
    GLUniform3iv,
    GLUniform3ui,
    GLUniform3uiv,
    GLUniform4f,
    GLUniform4fv,
    GLUniform4i,
    GLUniform4iv,
    GLUniform4ui,
    GLUniform4uiv,
    GLUniformBlockBinding,
    GLUniformMatrix2fv,
    GLUniformMatrix2x3fv,
    GLUniformMatrix2x4fv,
    GLUniformMatrix3fv,
    GLUniformMatrix3x2fv,
    GLUniformMatrix3x4fv,
    GLUniformMatrix4fv,
    GLUniformMatrix4x2fv,
    GLUniformMatrix4x3fv,
    GLUnmapBuffer,
    GLUnmapBufferOES,
    GLUseProgram,
    GLUseProgramStages,
    GLUseProgramStagesEXT,
    GLValidateProgram,
    GLValidateProgramPipeline,
    GLValidateProgramPipelineEXT,
    GLVertexAttrib1f,
    GLVertexAttrib1fv,
    GLVertexAttrib2f,
    GLVertexAttrib2fv,
    GLVertexAttrib3f,
    GLVertexAttrib3fv,
    GLVertexAttrib4f,
    GLVertexAttrib4fv,
    GLVertexAttribBinding,
    GLVertexAttribDivisor,
    GLVertexAttribDivisorANGLE,
    GLVertexAttribDivisorEXT,
    GLVertexAttribFormat,
    GLVertexAttribI4i,
    GLVertexAttribI4iv,
    GLVertexAttribI4ui,
    GLVertexAttribI4uiv,
    GLVertexAttribIFormat,
    GLVertexAttribIPointer,
    GLVertexAttribPointer,
    GLVertexBindingDivisor,
    GLVertexPointer,
    GLViewport,
    GLWaitSemaphoreEXT,
    GLWaitSync,
    GLWeightPointerOES
};

const char *GetEntryPointName(EntryPoint ep);
}  // namespace angle
#endif  // COMMON_ENTRY_POINTS_ENUM_AUTOGEN_H_
