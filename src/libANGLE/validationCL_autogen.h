// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from cl.xml.
//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// validationCL_autogen.h:
//   Validation functions for the CL entry points.

#ifndef LIBANGLE_VALIDATION_CL_AUTOGEN_H_
#define LIBANGLE_VALIDATION_CL_AUTOGEN_H_

#include "libANGLE/validationCL.h"

namespace cl
{

// CL 1.0
cl_int ValidateGetPlatformIDs(cl_uint num_entries, const cl_platform_id* platforms, const cl_uint* num_platforms);
cl_int ValidateGetPlatformInfo(cl_platform_id platform, PlatformInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateGetDeviceIDs(cl_platform_id platform, DeviceType device_typePacked, cl_uint num_entries, const cl_device_id* devices, const cl_uint* num_devices);
cl_int ValidateGetDeviceInfo(cl_device_id device, DeviceInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateCreateContext(const cl_context_properties* properties, cl_uint num_devices, const cl_device_id* devices, void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data), const void* user_data);
cl_int ValidateCreateContextFromType(const cl_context_properties* properties, DeviceType device_typePacked, void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data), const void* user_data);
cl_int ValidateRetainContext(cl_context context);
cl_int ValidateReleaseContext(cl_context context);
cl_int ValidateGetContextInfo(cl_context context, ContextInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateRetainCommandQueue(cl_command_queue command_queue);
cl_int ValidateReleaseCommandQueue(cl_command_queue command_queue);
cl_int ValidateGetCommandQueueInfo(cl_command_queue command_queue, CommandQueueInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateCreateBuffer(cl_context context, MemFlags flagsPacked, size_t size, const void* host_ptr);
cl_int ValidateRetainMemObject(cl_mem memobj);
cl_int ValidateReleaseMemObject(cl_mem memobj);
cl_int ValidateGetSupportedImageFormats(cl_context context, MemFlags flagsPacked, MemObjectType image_typePacked, cl_uint num_entries, const cl_image_format* image_formats, const cl_uint* num_image_formats);
cl_int ValidateGetMemObjectInfo(cl_mem memobj, MemInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateGetImageInfo(cl_mem image, ImageInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateRetainSampler(cl_sampler sampler);
cl_int ValidateReleaseSampler(cl_sampler sampler);
cl_int ValidateGetSamplerInfo(cl_sampler sampler, SamplerInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateCreateProgramWithSource(cl_context context, cl_uint count, const char** strings, const size_t* lengths);
cl_int ValidateCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id* device_list, const size_t* lengths, const unsigned char** binaries, const cl_int* binary_status);
cl_int ValidateRetainProgram(cl_program program);
cl_int ValidateReleaseProgram(cl_program program);
cl_int ValidateBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id* device_list, const char* options, void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data), const void* user_data);
cl_int ValidateGetProgramInfo(cl_program program, ProgramInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateGetProgramBuildInfo(cl_program program, cl_device_id device, ProgramBuildInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateCreateKernel(cl_program program, const char* kernel_name);
cl_int ValidateCreateKernelsInProgram(cl_program program, cl_uint num_kernels, const cl_kernel* kernels, const cl_uint* num_kernels_ret);
cl_int ValidateRetainKernel(cl_kernel kernel);
cl_int ValidateReleaseKernel(cl_kernel kernel);
cl_int ValidateSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value);
cl_int ValidateGetKernelInfo(cl_kernel kernel, KernelInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, KernelWorkGroupInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateWaitForEvents(cl_uint num_events, const cl_event* event_list);
cl_int ValidateGetEventInfo(cl_event event, EventInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateRetainEvent(cl_event event);
cl_int ValidateReleaseEvent(cl_event event);
cl_int ValidateGetEventProfilingInfo(cl_event event, ProfilingInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateFlush(cl_command_queue command_queue);
cl_int ValidateFinish(cl_command_queue command_queue);
cl_int ValidateEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t size, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueWriteBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t size, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueCopyBuffer(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueReadImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, const size_t* origin, const size_t* region, size_t row_pitch, size_t slice_pitch, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueWriteImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, const size_t* origin, const size_t* region, size_t input_row_pitch, size_t input_slice_pitch, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueCopyImage(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, const size_t* src_origin, const size_t* dst_origin, const size_t* region, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueCopyImageToBuffer(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, const size_t* src_origin, const size_t* region, size_t dst_offset, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueCopyBufferToImage(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, const size_t* dst_origin, const size_t* region, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, MapFlags map_flagsPacked, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueMapImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, MapFlags map_flagsPacked, const size_t* origin, const size_t* region, const size_t* image_row_pitch, const size_t* image_slice_pitch, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueUnmapMemObject(cl_command_queue command_queue, cl_mem memobj, const void* mapped_ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueNDRangeKernel(cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, const size_t* global_work_offset, const size_t* global_work_size, const size_t* local_work_size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueNativeKernel(cl_command_queue command_queue, void (CL_CALLBACK* user_func)(void*), const void* args, size_t cb_args, cl_uint num_mem_objects, const cl_mem* mem_list, const void** args_mem_loc, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateSetCommandQueueProperty(cl_command_queue command_queue, CommandQueueProperties propertiesPacked, cl_bool enable, const cl_command_queue_properties* old_properties);
cl_int ValidateCreateImage2D(cl_context context, MemFlags flagsPacked, const cl_image_format* image_format, size_t image_width, size_t image_height, size_t image_row_pitch, const void* host_ptr);
cl_int ValidateCreateImage3D(cl_context context, MemFlags flagsPacked, const cl_image_format* image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, const void* host_ptr);
cl_int ValidateEnqueueMarker(cl_command_queue command_queue, const cl_event* event);
cl_int ValidateEnqueueWaitForEvents(cl_command_queue command_queue, cl_uint num_events, const cl_event* event_list);
cl_int ValidateEnqueueBarrier(cl_command_queue command_queue);
cl_int ValidateUnloadCompiler();
cl_int ValidateGetExtensionFunctionAddress(const char* func_name);
cl_int ValidateCreateCommandQueue(cl_context context, cl_device_id device, CommandQueueProperties propertiesPacked);
cl_int ValidateCreateSampler(cl_context context, cl_bool normalized_coords, AddressingMode addressing_modePacked, FilterMode filter_modePacked);
cl_int ValidateEnqueueTask(cl_command_queue command_queue, cl_kernel kernel, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);

// CL 1.1
cl_int ValidateCreateSubBuffer(cl_mem buffer, MemFlags flagsPacked, cl_buffer_create_type buffer_create_type, const void* buffer_create_info);
cl_int ValidateSetMemObjectDestructorCallback(cl_mem memobj, void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data), const void* user_data);
cl_int ValidateCreateUserEvent(cl_context context);
cl_int ValidateSetUserEventStatus(cl_event event, cl_int execution_status);
cl_int ValidateSetEventCallback(cl_event event, cl_int command_exec_callback_type, void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int event_command_status, void *user_data), const void* user_data);
cl_int ValidateEnqueueReadBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, const size_t* buffer_origin, const size_t* host_origin, const size_t* region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueWriteBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, const size_t* buffer_origin, const size_t* host_origin, const size_t* region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void* ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueCopyBufferRect(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, const size_t* src_origin, const size_t* dst_origin, const size_t* region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);

// CL 1.2
cl_int ValidateCreateSubDevices(cl_device_id in_device, const cl_device_partition_property* properties, cl_uint num_devices, const cl_device_id* out_devices, const cl_uint* num_devices_ret);
cl_int ValidateRetainDevice(cl_device_id device);
cl_int ValidateReleaseDevice(cl_device_id device);
cl_int ValidateCreateImage(cl_context context, MemFlags flagsPacked, const cl_image_format* image_format, const cl_image_desc* image_desc, const void* host_ptr);
cl_int ValidateCreateProgramWithBuiltInKernels(cl_context context, cl_uint num_devices, const cl_device_id* device_list, const char* kernel_names);
cl_int ValidateCompileProgram(cl_program program, cl_uint num_devices, const cl_device_id* device_list, const char* options, cl_uint num_input_headers, const cl_program* input_headers, const char** header_include_names, void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data), const void* user_data);
cl_int ValidateLinkProgram(cl_context context, cl_uint num_devices, const cl_device_id* device_list, const char* options, cl_uint num_input_programs, const cl_program* input_programs, void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data), const void* user_data);
cl_int ValidateUnloadPlatformCompiler(cl_platform_id platform);
cl_int ValidateGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index, KernelArgInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateEnqueueFillBuffer(cl_command_queue command_queue, cl_mem buffer, const void* pattern, size_t pattern_size, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueFillImage(cl_command_queue command_queue, cl_mem image, const void* fill_color, const size_t* origin, const size_t* region, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueMigrateMemObjects(cl_command_queue command_queue, cl_uint num_mem_objects, const cl_mem* mem_objects, MemMigrationFlags flagsPacked, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueMarkerWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueBarrierWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateGetExtensionFunctionAddressForPlatform(cl_platform_id platform, const char* func_name);

// CL 2.0
cl_int ValidateCreateCommandQueueWithProperties(cl_context context, cl_device_id device, const cl_queue_properties* properties);
cl_int ValidateCreatePipe(cl_context context, MemFlags flagsPacked, cl_uint pipe_packet_size, cl_uint pipe_max_packets, const cl_pipe_properties* properties);
cl_int ValidateGetPipeInfo(cl_mem pipe, PipeInfo param_namePacked, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateSVMAlloc(cl_context context, SVM_MemFlags flagsPacked, size_t size, cl_uint alignment);
cl_int ValidateSVMFree(cl_context context, const void* svm_pointer);
cl_int ValidateCreateSamplerWithProperties(cl_context context, const cl_sampler_properties* sampler_properties);
cl_int ValidateSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value);
cl_int ValidateSetKernelExecInfo(cl_kernel kernel, KernelExecInfo param_namePacked, size_t param_value_size, const void* param_value);
cl_int ValidateEnqueueSVMFree(cl_command_queue command_queue, cl_uint num_svm_pointers, void*const  svm_pointers[], void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data), const void* user_data, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueSVMMemcpy(cl_command_queue command_queue, cl_bool blocking_copy, const void* dst_ptr, const void* src_ptr, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueSVMMemFill(cl_command_queue command_queue, const void* svm_ptr, const void* pattern, size_t pattern_size, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueSVMMap(cl_command_queue command_queue, cl_bool blocking_map, MapFlags flagsPacked, const void* svm_ptr, size_t size, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);
cl_int ValidateEnqueueSVMUnmap(cl_command_queue command_queue, const void* svm_ptr, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);

// CL 2.1
cl_int ValidateSetDefaultDeviceCommandQueue(cl_context context, cl_device_id device, cl_command_queue command_queue);
cl_int ValidateGetDeviceAndHostTimer(cl_device_id device, const cl_ulong* device_timestamp, const cl_ulong* host_timestamp);
cl_int ValidateGetHostTimer(cl_device_id device, const cl_ulong* host_timestamp);
cl_int ValidateCreateProgramWithIL(cl_context context, const void* il, size_t length);
cl_int ValidateCloneKernel(cl_kernel source_kernel);
cl_int ValidateGetKernelSubGroupInfo(cl_kernel kernel, cl_device_id device, KernelSubGroupInfo param_namePacked, size_t input_value_size, const void* input_value, size_t param_value_size, const void* param_value, const size_t* param_value_size_ret);
cl_int ValidateEnqueueSVMMigrateMem(cl_command_queue command_queue, cl_uint num_svm_pointers, const void** svm_pointers, const size_t* sizes, MemMigrationFlags flagsPacked, cl_uint num_events_in_wait_list, const cl_event* event_wait_list, const cl_event* event);

// CL 2.2
cl_int ValidateSetProgramReleaseCallback(cl_program program, void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data), const void* user_data);
cl_int ValidateSetProgramSpecializationConstant(cl_program program, cl_uint spec_id, size_t spec_size, const void* spec_value);

// CL 3.0
cl_int ValidateSetContextDestructorCallback(cl_context context, void (CL_CALLBACK* pfn_notify)(cl_context context, void* user_data), const void* user_data);
cl_int ValidateCreateBufferWithProperties(cl_context context, const cl_mem_properties* properties, MemFlags flagsPacked, size_t size, const void* host_ptr);
cl_int ValidateCreateImageWithProperties(cl_context context, const cl_mem_properties* properties, MemFlags flagsPacked, const cl_image_format* image_format, const cl_image_desc* image_desc, const void* host_ptr);

// cl_khr_icd
cl_int ValidateIcdGetPlatformIDsKHR(cl_uint num_entries, const cl_platform_id* platforms, const cl_uint* num_platforms);
}  // namespace cl

#endif  // LIBANGLE_VALIDATION_CL_AUTOGEN_H_
