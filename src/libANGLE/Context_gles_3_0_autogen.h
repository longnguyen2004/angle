// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Context_gles_3_0_autogen.h: Creates a macro for interfaces in Context.

#ifndef ANGLE_CONTEXT_GLES_3_0_AUTOGEN_H_
#define ANGLE_CONTEXT_GLES_3_0_AUTOGEN_H_

#define ANGLE_GLES_3_0_CONTEXT_API \
    void beginQuery(QueryType targetPacked, QueryID idPacked); \
    void beginTransformFeedback(PrimitiveMode primitiveModePacked); \
    void bindBufferBase(BufferBinding targetPacked, GLuint index, BufferID bufferPacked); \
    void bindBufferRange(BufferBinding targetPacked, GLuint index, BufferID bufferPacked, GLintptr offset, GLsizeiptr size); \
    void bindSampler(GLuint unit, SamplerID samplerPacked); \
    void bindTransformFeedback(GLenum target, TransformFeedbackID idPacked); \
    void bindVertexArray(VertexArrayID arrayPacked); \
    void blitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter); \
    void clearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil); \
    void clearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value); \
    void clearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value); \
    void clearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value); \
    GLenum clientWaitSync(SyncID syncPacked, GLbitfield flags, GLuint64 timeout); \
    void compressedTexImage3D(TextureTarget targetPacked, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data); \
    void compressedTexSubImage3D(TextureTarget targetPacked, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data); \
    void copyBufferSubData(BufferBinding readTargetPacked, BufferBinding writeTargetPacked, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size); \
    void copyTexSubImage3D(TextureTarget targetPacked, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height); \
    void deleteQueries(GLsizei n, const QueryID * idsPacked); \
    void deleteSamplers(GLsizei count, const SamplerID * samplersPacked); \
    void deleteSync(SyncID syncPacked); \
    void deleteTransformFeedbacks(GLsizei n, const TransformFeedbackID * idsPacked); \
    void deleteVertexArrays(GLsizei n, const VertexArrayID * arraysPacked); \
    void drawArraysInstanced(PrimitiveMode modePacked, GLint first, GLsizei count, GLsizei instancecount); \
    void drawBuffers(GLsizei n, const GLenum * bufs); \
    void drawElementsInstanced(PrimitiveMode modePacked, GLsizei count, DrawElementsType typePacked, const void * indices, GLsizei instancecount); \
    void drawRangeElements(PrimitiveMode modePacked, GLuint start, GLuint end, GLsizei count, DrawElementsType typePacked, const void * indices); \
    void endQuery(QueryType targetPacked); \
    void endTransformFeedback(); \
    GLsync fenceSync(GLenum condition, GLbitfield flags); \
    void flushMappedBufferRange(BufferBinding targetPacked, GLintptr offset, GLsizeiptr length); \
    void framebufferTextureLayer(GLenum target, GLenum attachment, TextureID texturePacked, GLint level, GLint layer); \
    void genQueries(GLsizei n, QueryID * idsPacked); \
    void genSamplers(GLsizei count, SamplerID * samplersPacked); \
    void genTransformFeedbacks(GLsizei n, TransformFeedbackID * idsPacked); \
    void genVertexArrays(GLsizei n, VertexArrayID * arraysPacked); \
    void getActiveUniformBlockName(ShaderProgramID programPacked, UniformBlockIndex uniformBlockIndexPacked, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName); \
    void getActiveUniformBlockiv(ShaderProgramID programPacked, UniformBlockIndex uniformBlockIndexPacked, GLenum pname, GLint * params); \
    void getActiveUniformsiv(ShaderProgramID programPacked, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params); \
    void getBufferParameteri64v(BufferBinding targetPacked, GLenum pname, GLint64 * params); \
    void getBufferPointerv(BufferBinding targetPacked, GLenum pname, void ** params); \
    GLint getFragDataLocation(ShaderProgramID programPacked, const GLchar * name); \
    void getInteger64i_v(GLenum target, GLuint index, GLint64 * data); \
    void getInteger64v(GLenum pname, GLint64 * data); \
    void getIntegeri_v(GLenum target, GLuint index, GLint * data); \
    void getInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params); \
    void getProgramBinary(ShaderProgramID programPacked, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary); \
    void getQueryObjectuiv(QueryID idPacked, GLenum pname, GLuint * params); \
    void getQueryiv(QueryType targetPacked, GLenum pname, GLint * params); \
    void getSamplerParameterfv(SamplerID samplerPacked, GLenum pname, GLfloat * params); \
    void getSamplerParameteriv(SamplerID samplerPacked, GLenum pname, GLint * params); \
    const GLubyte * getStringi(GLenum name, GLuint index); \
    void getSynciv(SyncID syncPacked, GLenum pname, GLsizei count, GLsizei * length, GLint * values); \
    void getTransformFeedbackVarying(ShaderProgramID programPacked, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name); \
    GLuint getUniformBlockIndex(ShaderProgramID programPacked, const GLchar * uniformBlockName); \
    void getUniformIndices(ShaderProgramID programPacked, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices); \
    void getUniformuiv(ShaderProgramID programPacked, UniformLocation locationPacked, GLuint * params); \
    void getVertexAttribIiv(GLuint index, GLenum pname, GLint * params); \
    void getVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params); \
    void invalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments); \
    void invalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height); \
    GLboolean isQuery(QueryID idPacked) const; \
    GLboolean isSampler(SamplerID samplerPacked) const; \
    GLboolean isSync(SyncID syncPacked) const; \
    GLboolean isTransformFeedback(TransformFeedbackID idPacked) const; \
    GLboolean isVertexArray(VertexArrayID arrayPacked) const; \
    void * mapBufferRange(BufferBinding targetPacked, GLintptr offset, GLsizeiptr length, GLbitfield access); \
    void pauseTransformFeedback(); \
    void programBinary(ShaderProgramID programPacked, GLenum binaryFormat, const void * binary, GLsizei length); \
    void programParameteri(ShaderProgramID programPacked, GLenum pname, GLint value); \
    void readBuffer(GLenum src); \
    void renderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height); \
    void resumeTransformFeedback(); \
    void samplerParameterf(SamplerID samplerPacked, GLenum pname, GLfloat param); \
    void samplerParameterfv(SamplerID samplerPacked, GLenum pname, const GLfloat * param); \
    void samplerParameteri(SamplerID samplerPacked, GLenum pname, GLint param); \
    void samplerParameteriv(SamplerID samplerPacked, GLenum pname, const GLint * param); \
    void texImage3D(TextureTarget targetPacked, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels); \
    void texStorage2D(TextureType targetPacked, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height); \
    void texStorage3D(TextureType targetPacked, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth); \
    void texSubImage3D(TextureTarget targetPacked, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels); \
    void transformFeedbackVaryings(ShaderProgramID programPacked, GLsizei count, const GLchar *const* varyings, GLenum bufferMode); \
    void uniform1ui(UniformLocation locationPacked, GLuint v0); \
    void uniform1uiv(UniformLocation locationPacked, GLsizei count, const GLuint * value); \
    void uniform2ui(UniformLocation locationPacked, GLuint v0, GLuint v1); \
    void uniform2uiv(UniformLocation locationPacked, GLsizei count, const GLuint * value); \
    void uniform3ui(UniformLocation locationPacked, GLuint v0, GLuint v1, GLuint v2); \
    void uniform3uiv(UniformLocation locationPacked, GLsizei count, const GLuint * value); \
    void uniform4ui(UniformLocation locationPacked, GLuint v0, GLuint v1, GLuint v2, GLuint v3); \
    void uniform4uiv(UniformLocation locationPacked, GLsizei count, const GLuint * value); \
    void uniformBlockBinding(ShaderProgramID programPacked, UniformBlockIndex uniformBlockIndexPacked, GLuint uniformBlockBinding); \
    void uniformMatrix2x3fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    void uniformMatrix2x4fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    void uniformMatrix3x2fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    void uniformMatrix3x4fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    void uniformMatrix4x2fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    void uniformMatrix4x3fv(UniformLocation locationPacked, GLsizei count, GLboolean transpose, const GLfloat * value); \
    GLboolean unmapBuffer(BufferBinding targetPacked); \
    void vertexAttribDivisor(GLuint index, GLuint divisor); \
    void vertexAttribIPointer(GLuint index, GLint size, VertexAttribType typePacked, GLsizei stride, const void * pointer); \
    void waitSync(SyncID syncPacked, GLbitfield flags, GLuint64 timeout); \

#endif // ANGLE_CONTEXT_API_3_0_AUTOGEN_H_
