/*
 * Copyright (c) 2024 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */

#ifndef OPENCL_CL_INSTANCE_LAYER_H_
#define OPENCL_CL_INSTANCE_LAYER_H_

#include <CL/cl.h>

/* CL_NO_PROTOTYPES implies CL_NO_EXTENSION_PROTOTYPES: */
#if defined(CL_NO_PROTOTYPES) && !defined(CL_NO_EXTENSION_PROTOTYPES)
#define CL_NO_EXTENSION_PROTOTYPES
#endif

/* CL_NO_EXTENSION_PROTOTYPES implies
   CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES and
   CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES: */
#if defined(CL_NO_EXTENSION_PROTOTYPES) &&     !defined(CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif
#if defined(CL_NO_EXTENSION_PROTOTYPES) &&     !defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
* cl_loader_instance_layers
***************************************************************/
#define cl_loader_instance_layers 1
#define CL_LOADER_INSTANCE_LAYERS_EXTENSION_NAME     "cl_loader_instance_layers"

typedef cl_uint             cl_instance_layer_info;
typedef cl_uint             cl_instance_layer_api_version;

typedef struct _cl_icd_instance_dispatch cl_icd_instance_dispatch;
typedef struct _cl_icd_layer_dispatch    cl_icd_layer_dispatch;
typedef struct _cl_icd_instance_layer    cl_icd_instance_layer;

/* cl_layer_info */
#define CL_INSTANCE_LAYER_API_VERSION                      0x4240
#define CL_INSTANCE_LAYER_NAME                             0x4241

/* Misc API enums */
#define CL_INSTANCE_LAYER_API_VERSION_100                  100

typedef cl_int CL_API_CALL
clGetInstanceLayerInfo_t(
    cl_instance_layer_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef clGetInstanceLayerInfo_t *
clGetInstanceLayerInfo_fn;

typedef cl_int CL_API_CALL
clInitInstanceLayer_t(
    cl_uint num_entries,
    const cl_icd_instance_layer* layer,
    cl_uint* num_entries_ret,
    const cl_icd_instance_dispatch** layer_dispatch_ret,
    void** data_ret);

typedef clInitInstanceLayer_t *
clInitInstanceLayer_fn;

typedef cl_int CL_API_CALL
clDeinitInstanceLayer_t(
    const cl_icd_instance_layer* layer,
    void* data);

typedef clDeinitInstanceLayer_t *
clDeinitInstanceLayer_fn;

#if !defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES)

extern CL_API_ENTRY cl_int CL_API_CALL
clGetInstanceLayerInfo(
    cl_instance_layer_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

extern CL_API_ENTRY cl_int CL_API_CALL
clInitInstanceLayer(
    cl_uint num_entries,
    const cl_icd_instance_layer* layer,
    cl_uint* num_entries_ret,
    const cl_icd_instance_dispatch** layer_dispatch_ret,
    void** data_ret);

extern CL_API_ENTRY cl_int CL_API_CALL
clDeinitInstanceLayer(
    const cl_icd_instance_layer* layer,
    void* data);

#endif /* !defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES) */

typedef cl_int CL_API_CALL
clGetPlatformIDsForInstanceKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_instance_khr instance,
    cl_uint num_entries,
    cl_platform_id *platforms,
    cl_uint *num_platforms);

///////////////////////////////////////////////////////////////////////////////
// Core APIs:
typedef cl_int CL_API_CALL clGetPlatformInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_platform_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetDeviceIDs_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_device_type device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetDeviceInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_device_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_context CL_API_CALL clCreateContext_instance_t(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_context CL_API_CALL clCreateContextFromType_instance_t(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_device_type device_type,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainContext_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseContext_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetContextInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainCommandQueue_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseCommandQueue_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetCommandQueueInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_command_queue_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainMemObject_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseMemObject_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetSupportedImageFormats_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_mem_object_type image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetMemObjectInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_mem_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetImageInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem image,
    cl_image_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainSampler_instance_t(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseSampler_instance_t(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetSamplerInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler,
    cl_sampler_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_program CL_API_CALL clCreateProgramWithSource_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_program CL_API_CALL clCreateProgramWithBinary_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clBuildProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetProgramInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_program_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetProgramBuildInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_device_id device,
    cl_program_build_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_kernel CL_API_CALL clCreateKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    const char* kernel_name,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clCreateKernelsInProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetKernelArg_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetKernelInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_kernel_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetKernelWorkGroupInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_work_group_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clWaitForEvents_instance_t(
    const cl_icd_instance_layer *layer,
    cl_uint num_events,
    const cl_event* event_list);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetEventInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_event_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainEvent_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseEvent_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetEventProfilingInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_profiling_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clFlush_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clFinish_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueReadBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueWriteBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueCopyBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueReadImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_read,
    const size_t* origin,
    const size_t* region,
    size_t row_pitch,
    size_t slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueWriteImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_write,
    const size_t* origin,
    const size_t* region,
    size_t input_row_pitch,
    size_t input_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueCopyImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueCopyImageToBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueCopyBufferToImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef void* CL_API_CALL clEnqueueMapBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef void* CL_API_CALL clEnqueueMapImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    const size_t* origin,
    const size_t* region,
    size_t* image_row_pitch,
    size_t* image_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueUnmapMemObject_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueNDRangeKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueNativeKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    void (CL_CALLBACK* user_func)(void*),
    void* args,
    size_t cb_args,
    cl_uint num_mem_objects,
    const cl_mem* mem_list,
    const void** args_mem_loc,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetCommandQueueProperty_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateImage2D_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateImage3D_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_depth,
    size_t image_row_pitch,
    size_t image_slice_pitch,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueMarker_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueWaitForEvents_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueBarrier_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_command_queue CL_API_CALL clCreateCommandQueue_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_sampler CL_API_CALL clCreateSampler_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueTask_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateSubBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetMemObjectDestructorCallback_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_event CL_API_CALL clCreateUserEvent_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetUserEventStatus_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_int execution_status);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetEventCallback_instance_t(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_int command_exec_callback_type,
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int event_command_status, void *user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueReadBufferRect_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueWriteBufferRect_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueCopyBufferRect_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    size_t src_row_pitch,
    size_t src_slice_pitch,
    size_t dst_row_pitch,
    size_t dst_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clCreateSubDevices_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint* num_devices_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clRetainDevice_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clReleaseDevice_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_program CL_API_CALL clCreateProgramWithBuiltInKernels_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clCompileProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_program CL_API_CALL clLinkProgram_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clUnloadPlatformCompiler_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetKernelArgInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    cl_kernel_arg_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueFillBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueFillImage_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueMigrateMemObjects_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueMarkerWithWaitList_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueBarrierWithWaitList_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef void* CL_API_CALL clGetExtensionFunctionAddressForPlatform_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    const char* func_name);

///////////////////////////////////////////////////////////////////////////////
typedef cl_command_queue CL_API_CALL clCreateCommandQueueWithProperties_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreatePipe_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetPipeInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem pipe,
    cl_pipe_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef void* CL_API_CALL clSVMAlloc_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment);

///////////////////////////////////////////////////////////////////////////////
typedef void CL_API_CALL clSVMFree_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    void* svm_pointer);

///////////////////////////////////////////////////////////////////////////////
typedef cl_sampler CL_API_CALL clCreateSamplerWithProperties_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetKernelArgSVMPointer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetKernelExecInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void* param_value);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMFree_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMMemcpy_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMMemFill_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMMap_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMUnmap_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetDefaultDeviceCommandQueue_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetDeviceAndHostTimer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetHostTimer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_ulong* host_timestamp);

///////////////////////////////////////////////////////////////////////////////
typedef cl_program CL_API_CALL clCreateProgramWithIL_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_kernel CL_API_CALL clCloneKernel_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel source_kernel,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clGetKernelSubGroupInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clEnqueueSVMMigrateMem_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void** svm_pointers,
    const size_t* sizes,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetProgramSpecializationConstant_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint spec_id,
    size_t spec_size,
    const void* spec_value);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetProgramReleaseCallback_instance_t(
    const cl_icd_instance_layer *layer,
    cl_program program,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_int CL_API_CALL clSetContextDestructorCallback_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    void (CL_CALLBACK* pfn_notify)(cl_context context, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateBufferWithProperties_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////
typedef cl_mem CL_API_CALL clCreateImageWithProperties_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

// cl_ext_device_fission
typedef cl_int CL_API_CALL clReleaseDeviceEXT_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device);

typedef cl_int CL_API_CALL clRetainDeviceEXT_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id device);

typedef cl_int CL_API_CALL clCreateSubDevicesEXT_instance_t(
    const cl_icd_instance_layer *layer,
    cl_device_id in_device,
    const cl_device_partition_property_ext* properties,
    cl_uint num_entries,
    cl_device_id* out_devices,
    cl_uint* num_devices);


///////////////////////////////////////////////////////////////////////////////

// cl_khr_d3d10_sharing

#if defined(_WIN32)
typedef cl_int CL_API_CALL clGetDeviceIDsFromD3D10KHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_d3d10_device_source_khr d3d_device_source,
    void* d3d_object,
    cl_d3d10_device_set_khr d3d_device_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

typedef cl_mem CL_API_CALL clCreateFromD3D10BufferKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Buffer* resource,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromD3D10Texture2DKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Texture2D* resource,
    UINT subresource,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromD3D10Texture3DKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Texture3D* resource,
    UINT subresource,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueAcquireD3D10ObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReleaseD3D10ObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);


#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_d3d11_sharing

#if defined(_WIN32)
typedef cl_int CL_API_CALL clGetDeviceIDsFromD3D11KHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_d3d11_device_source_khr d3d_device_source,
    void* d3d_object,
    cl_d3d11_device_set_khr d3d_device_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

typedef cl_mem CL_API_CALL clCreateFromD3D11BufferKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Buffer* resource,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromD3D11Texture2DKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Texture2D* resource,
    UINT subresource,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromD3D11Texture3DKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Texture3D* resource,
    UINT subresource,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueAcquireD3D11ObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReleaseD3D11ObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);


#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_dx9_media_sharing

#if defined(_WIN32)
typedef cl_int CL_API_CALL clGetDeviceIDsFromDX9MediaAdapterKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_uint num_media_adapters,
    cl_dx9_media_adapter_type_khr* media_adapter_type,
    void* media_adapters,
    cl_dx9_media_adapter_set_khr media_adapter_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

typedef cl_mem CL_API_CALL clCreateFromDX9MediaSurfaceKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_dx9_media_adapter_type_khr adapter_type,
    void* surface_info,
    cl_uint plane,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueAcquireDX9MediaSurfacesKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReleaseDX9MediaSurfacesKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);


#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_egl_event
typedef cl_event CL_API_CALL clCreateEventFromEGLSyncKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    CLeglSyncKHR sync,
    CLeglDisplayKHR display,
    cl_int* errcode_ret);


///////////////////////////////////////////////////////////////////////////////

// cl_khr_egl_image
typedef cl_mem CL_API_CALL clCreateFromEGLImageKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    CLeglDisplayKHR egldisplay,
    CLeglImageKHR eglimage,
    cl_mem_flags flags,
    const cl_egl_image_properties_khr* properties,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueAcquireEGLObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReleaseEGLObjectsKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);


///////////////////////////////////////////////////////////////////////////////

// cl_khr_gl_event
typedef cl_event CL_API_CALL clCreateEventFromGLsyncKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_GLsync sync,
    cl_int* errcode_ret);


///////////////////////////////////////////////////////////////////////////////

// cl_khr_gl_sharing
typedef cl_int CL_API_CALL clGetGLContextInfoKHR_instance_t(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_gl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_mem CL_API_CALL clCreateFromGLBuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLuint bufobj,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromGLTexture_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromGLRenderbuffer_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLuint renderbuffer,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clGetGLObjectInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_gl_object_type* gl_object_type,
    cl_GLuint* gl_object_name);

typedef cl_int CL_API_CALL clGetGLTextureInfo_instance_t(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_gl_texture_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clEnqueueAcquireGLObjects_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReleaseGLObjects_instance_t(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_mem CL_API_CALL clCreateFromGLTexture2D_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateFromGLTexture3D_instance_t(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret);


///////////////////////////////////////////////////////////////////////////////

// cl_khr_subgroups
typedef cl_int CL_API_CALL clGetKernelSubGroupInfoKHR_instance_t(
    const cl_icd_instance_layer *layer,
    cl_kernel in_kernel,
    cl_device_id in_device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);


///////////////////////////////////////////////////////////////////////////////


struct _cl_icd_instance_dispatch {
  clGetPlatformIDsForInstanceKHR_instance_t *clGetPlatformIDsForInstanceKHR;
  /* OpenCL 1.0 */
  clGetPlatformInfo_instance_t *clGetPlatformInfo;
  clGetDeviceIDs_instance_t *clGetDeviceIDs;
  clGetDeviceInfo_instance_t *clGetDeviceInfo;
  clCreateContext_instance_t *clCreateContext;
  clCreateContextFromType_instance_t *clCreateContextFromType;
  clRetainContext_instance_t *clRetainContext;
  clReleaseContext_instance_t *clReleaseContext;
  clGetContextInfo_instance_t *clGetContextInfo;
  clCreateCommandQueue_instance_t *clCreateCommandQueue;
  clRetainCommandQueue_instance_t *clRetainCommandQueue;
  clReleaseCommandQueue_instance_t *clReleaseCommandQueue;
  clGetCommandQueueInfo_instance_t *clGetCommandQueueInfo;
  clSetCommandQueueProperty_instance_t *clSetCommandQueueProperty;
  clCreateBuffer_instance_t *clCreateBuffer;
  clCreateImage2D_instance_t *clCreateImage2D;
  clCreateImage3D_instance_t *clCreateImage3D;
  clRetainMemObject_instance_t *clRetainMemObject;
  clReleaseMemObject_instance_t *clReleaseMemObject;
  clGetSupportedImageFormats_instance_t *clGetSupportedImageFormats;
  clGetMemObjectInfo_instance_t *clGetMemObjectInfo;
  clGetImageInfo_instance_t *clGetImageInfo;
  clCreateSampler_instance_t *clCreateSampler;
  clRetainSampler_instance_t *clRetainSampler;
  clReleaseSampler_instance_t *clReleaseSampler;
  clGetSamplerInfo_instance_t *clGetSamplerInfo;
  clCreateProgramWithSource_instance_t *clCreateProgramWithSource;
  clCreateProgramWithBinary_instance_t *clCreateProgramWithBinary;
  clRetainProgram_instance_t *clRetainProgram;
  clReleaseProgram_instance_t *clReleaseProgram;
  clBuildProgram_instance_t *clBuildProgram;
  clGetProgramInfo_instance_t *clGetProgramInfo;
  clGetProgramBuildInfo_instance_t *clGetProgramBuildInfo;
  clCreateKernel_instance_t *clCreateKernel;
  clCreateKernelsInProgram_instance_t *clCreateKernelsInProgram;
  clRetainKernel_instance_t *clRetainKernel;
  clReleaseKernel_instance_t *clReleaseKernel;
  clSetKernelArg_instance_t *clSetKernelArg;
  clGetKernelInfo_instance_t *clGetKernelInfo;
  clGetKernelWorkGroupInfo_instance_t *clGetKernelWorkGroupInfo;
  clWaitForEvents_instance_t *clWaitForEvents;
  clGetEventInfo_instance_t *clGetEventInfo;
  clRetainEvent_instance_t *clRetainEvent;
  clReleaseEvent_instance_t *clReleaseEvent;
  clGetEventProfilingInfo_instance_t *clGetEventProfilingInfo;
  clFlush_instance_t *clFlush;
  clFinish_instance_t *clFinish;
  clEnqueueReadBuffer_instance_t *clEnqueueReadBuffer;
  clEnqueueWriteBuffer_instance_t *clEnqueueWriteBuffer;
  clEnqueueCopyBuffer_instance_t *clEnqueueCopyBuffer;
  clEnqueueReadImage_instance_t *clEnqueueReadImage;
  clEnqueueWriteImage_instance_t *clEnqueueWriteImage;
  clEnqueueCopyImage_instance_t *clEnqueueCopyImage;
  clEnqueueCopyImageToBuffer_instance_t *clEnqueueCopyImageToBuffer;
  clEnqueueCopyBufferToImage_instance_t *clEnqueueCopyBufferToImage;
  clEnqueueMapBuffer_instance_t *clEnqueueMapBuffer;
  clEnqueueMapImage_instance_t *clEnqueueMapImage;
  clEnqueueUnmapMemObject_instance_t *clEnqueueUnmapMemObject;
  clEnqueueNDRangeKernel_instance_t *clEnqueueNDRangeKernel;
  clEnqueueTask_instance_t *clEnqueueTask;
  clEnqueueNativeKernel_instance_t *clEnqueueNativeKernel;
  clEnqueueMarker_instance_t *clEnqueueMarker;
  clEnqueueWaitForEvents_instance_t *clEnqueueWaitForEvents;
  clEnqueueBarrier_instance_t *clEnqueueBarrier;
  clCreateFromGLBuffer_instance_t *clCreateFromGLBuffer;
  clCreateFromGLTexture2D_instance_t *clCreateFromGLTexture2D;
  clCreateFromGLTexture3D_instance_t *clCreateFromGLTexture3D;
  clCreateFromGLRenderbuffer_instance_t *clCreateFromGLRenderbuffer;
  clGetGLObjectInfo_instance_t *clGetGLObjectInfo;
  clGetGLTextureInfo_instance_t *clGetGLTextureInfo;
  clEnqueueAcquireGLObjects_instance_t *clEnqueueAcquireGLObjects;
  clEnqueueReleaseGLObjects_instance_t *clEnqueueReleaseGLObjects;
  clGetGLContextInfoKHR_instance_t *clGetGLContextInfoKHR;

  /* cl_khr_d3d10_sharing */
#ifdef _WIN32
  clGetDeviceIDsFromD3D10KHR_instance_t *clGetDeviceIDsFromD3D10KHR;
  clCreateFromD3D10BufferKHR_instance_t *clCreateFromD3D10BufferKHR;
  clCreateFromD3D10Texture2DKHR_instance_t *clCreateFromD3D10Texture2DKHR;
  clCreateFromD3D10Texture3DKHR_instance_t *clCreateFromD3D10Texture3DKHR;
  clEnqueueAcquireD3D10ObjectsKHR_instance_t *clEnqueueAcquireD3D10ObjectsKHR;
  clEnqueueReleaseD3D10ObjectsKHR_instance_t *clEnqueueReleaseD3D10ObjectsKHR;
#else
  void *clGetDeviceIDsFromD3D10KHR;
  void *clCreateFromD3D10BufferKHR;
  void *clCreateFromD3D10Texture2DKHR;
  void *clCreateFromD3D10Texture3DKHR;
  void *clEnqueueAcquireD3D10ObjectsKHR;
  void *clEnqueueReleaseD3D10ObjectsKHR;
#endif

  /* OpenCL 1.1 */
#ifdef CL_VERSION_1_1
  clSetEventCallback_instance_t *clSetEventCallback;
  clCreateSubBuffer_instance_t *clCreateSubBuffer;
  clSetMemObjectDestructorCallback_instance_t *clSetMemObjectDestructorCallback;
  clCreateUserEvent_instance_t *clCreateUserEvent;
  clSetUserEventStatus_instance_t *clSetUserEventStatus;
  clEnqueueReadBufferRect_instance_t *clEnqueueReadBufferRect;
  clEnqueueWriteBufferRect_instance_t *clEnqueueWriteBufferRect;
  clEnqueueCopyBufferRect_instance_t *clEnqueueCopyBufferRect;
#else
  void *clSetEventCallback;
  void *clCreateSubBuffer;
  void *clSetMemObjectDestructorCallback;
  void *clCreateUserEvent;
  void *clSetUserEventStatus;
  void *clEnqueueReadBufferRect;
  void *clEnqueueWriteBufferRect;
  void *clEnqueueCopyBufferRect;
#endif

  /* cl_ext_device_fission */
  clCreateSubDevicesEXT_instance_t *clCreateSubDevicesEXT;
  clRetainDeviceEXT_instance_t *clRetainDeviceEXT;
  clReleaseDeviceEXT_instance_t *clReleaseDeviceEXT;

  /* cl_khr_gl_event */
  clCreateEventFromGLsyncKHR_instance_t *clCreateEventFromGLsyncKHR;

  /* OpenCL 1.2 */
#ifdef CL_VERSION_1_2
  clCreateSubDevices_instance_t *clCreateSubDevices;
  clRetainDevice_instance_t *clRetainDevice;
  clReleaseDevice_instance_t *clReleaseDevice;
  clCreateImage_instance_t *clCreateImage;
  clCreateProgramWithBuiltInKernels_instance_t *clCreateProgramWithBuiltInKernels;
  clCompileProgram_instance_t *clCompileProgram;
  clLinkProgram_instance_t *clLinkProgram;
  clUnloadPlatformCompiler_instance_t *clUnloadPlatformCompiler;
  clGetKernelArgInfo_instance_t *clGetKernelArgInfo;
  clEnqueueFillBuffer_instance_t *clEnqueueFillBuffer;
  clEnqueueFillImage_instance_t *clEnqueueFillImage;
  clEnqueueMigrateMemObjects_instance_t *clEnqueueMigrateMemObjects;
  clEnqueueMarkerWithWaitList_instance_t *clEnqueueMarkerWithWaitList;
  clEnqueueBarrierWithWaitList_instance_t *clEnqueueBarrierWithWaitList;
  clGetExtensionFunctionAddressForPlatform_instance_t *clGetExtensionFunctionAddressForPlatform;
  clCreateFromGLTexture_instance_t *clCreateFromGLTexture;
#else
  void *clCreateSubDevices;
  void *clRetainDevice;
  void *clReleaseDevice;
  void *clCreateImage;
  void *clCreateProgramWithBuiltInKernels;
  void *clCompileProgram;
  void *clLinkProgram;
  void *clUnloadPlatformCompiler;
  void *clGetKernelArgInfo;
  void *clEnqueueFillBuffer;
  void *clEnqueueFillImage;
  void *clEnqueueMigrateMemObjects;
  void *clEnqueueMarkerWithWaitList;
  void *clEnqueueBarrierWithWaitList;
  void *clGetExtensionFunctionAddressForPlatform;
  void *clCreateFromGLTexture;
#endif

  /* cl_khr_d3d11_sharing and cl_khr_dx9_media_sharing */
#ifdef _WIN32
  clGetDeviceIDsFromD3D11KHR_instance_t *clGetDeviceIDsFromD3D11KHR;
  clCreateFromD3D11BufferKHR_instance_t *clCreateFromD3D11BufferKHR;
  clCreateFromD3D11Texture2DKHR_instance_t *clCreateFromD3D11Texture2DKHR;
  clCreateFromD3D11Texture3DKHR_instance_t *clCreateFromD3D11Texture3DKHR;
  clCreateFromDX9MediaSurfaceKHR_instance_t *clCreateFromDX9MediaSurfaceKHR;
  clEnqueueAcquireD3D11ObjectsKHR_instance_t *clEnqueueAcquireD3D11ObjectsKHR;
  clEnqueueReleaseD3D11ObjectsKHR_instance_t *clEnqueueReleaseD3D11ObjectsKHR;
  clGetDeviceIDsFromDX9MediaAdapterKHR_instance_t *clGetDeviceIDsFromDX9MediaAdapterKHR;
  clEnqueueAcquireDX9MediaSurfacesKHR_instance_t *clEnqueueAcquireDX9MediaSurfacesKHR;
  clEnqueueReleaseDX9MediaSurfacesKHR_instance_t *clEnqueueReleaseDX9MediaSurfacesKHR;
#else
  void *clGetDeviceIDsFromD3D11KHR;
  void *clCreateFromD3D11BufferKHR;
  void *clCreateFromD3D11Texture2DKHR;
  void *clCreateFromD3D11Texture3DKHR;
  void *clCreateFromDX9MediaSurfaceKHR;
  void *clEnqueueAcquireD3D11ObjectsKHR;
  void *clEnqueueReleaseD3D11ObjectsKHR;
  void *clGetDeviceIDsFromDX9MediaAdapterKHR;
  void *clEnqueueAcquireDX9MediaSurfacesKHR;
  void *clEnqueueReleaseDX9MediaSurfacesKHR;
#endif

  /* cl_khr_egl_image */
  clCreateFromEGLImageKHR_instance_t *clCreateFromEGLImageKHR;
  clEnqueueAcquireEGLObjectsKHR_instance_t *clEnqueueAcquireEGLObjectsKHR;
  clEnqueueReleaseEGLObjectsKHR_instance_t *clEnqueueReleaseEGLObjectsKHR;

  /* cl_khr_egl_event */
  clCreateEventFromEGLSyncKHR_instance_t *clCreateEventFromEGLSyncKHR;

  /* OpenCL 2.0 */
#ifdef CL_VERSION_2_0
  clCreateCommandQueueWithProperties_instance_t *clCreateCommandQueueWithProperties;
  clCreatePipe_instance_t *clCreatePipe;
  clGetPipeInfo_instance_t *clGetPipeInfo;
  clSVMAlloc_instance_t *clSVMAlloc;
  clSVMFree_instance_t *clSVMFree;
  clEnqueueSVMFree_instance_t *clEnqueueSVMFree;
  clEnqueueSVMMemcpy_instance_t *clEnqueueSVMMemcpy;
  clEnqueueSVMMemFill_instance_t *clEnqueueSVMMemFill;
  clEnqueueSVMMap_instance_t *clEnqueueSVMMap;
  clEnqueueSVMUnmap_instance_t *clEnqueueSVMUnmap;
  clCreateSamplerWithProperties_instance_t *clCreateSamplerWithProperties;
  clSetKernelArgSVMPointer_instance_t *clSetKernelArgSVMPointer;
  clSetKernelExecInfo_instance_t *clSetKernelExecInfo;
#else
  void *clCreateCommandQueueWithProperties;
  void *clCreatePipe;
  void *clGetPipeInfo;
  void *clSVMAlloc;
  void *clSVMFree;
  void *clEnqueueSVMFree;
  void *clEnqueueSVMMemcpy;
  void *clEnqueueSVMMemFill;
  void *clEnqueueSVMMap;
  void *clEnqueueSVMUnmap;
  void *clCreateSamplerWithProperties;
  void *clSetKernelArgSVMPointer;
  void *clSetKernelExecInfo;
#endif

  /* cl_khr_sub_groups */
  clGetKernelSubGroupInfoKHR_instance_t *clGetKernelSubGroupInfoKHR;

  /* OpenCL 2.1 */
#ifdef CL_VERSION_2_1
  clCloneKernel_instance_t *clCloneKernel;
  clCreateProgramWithIL_instance_t *clCreateProgramWithIL;
  clEnqueueSVMMigrateMem_instance_t *clEnqueueSVMMigrateMem;
  clGetDeviceAndHostTimer_instance_t *clGetDeviceAndHostTimer;
  clGetHostTimer_instance_t *clGetHostTimer;
  clGetKernelSubGroupInfo_instance_t *clGetKernelSubGroupInfo;
  clSetDefaultDeviceCommandQueue_instance_t *clSetDefaultDeviceCommandQueue;
#else
  void *clCloneKernel;
  void *clCreateProgramWithIL;
  void *clEnqueueSVMMigrateMem;
  void *clGetDeviceAndHostTimer;
  void *clGetHostTimer;
  void *clGetKernelSubGroupInfo;
  void *clSetDefaultDeviceCommandQueue;
#endif

  /* OpenCL 2.2 */
#ifdef CL_VERSION_2_2
  clSetProgramReleaseCallback_instance_t *clSetProgramReleaseCallback;
  clSetProgramSpecializationConstant_instance_t *clSetProgramSpecializationConstant;
#else
  void *clSetProgramReleaseCallback;
  void *clSetProgramSpecializationConstant;
#endif

  /* OpenCL 3.0 */
#ifdef CL_VERSION_3_0
  clCreateBufferWithProperties_instance_t *clCreateBufferWithProperties;
  clCreateImageWithProperties_instance_t *clCreateImageWithProperties;
  clSetContextDestructorCallback_instance_t *clSetContextDestructorCallback;
#else
  void *clCreateBufferWithProperties;
  void *clCreateImageWithProperties;
  void *clSetContextDestructorCallback;
#endif
}
;

struct _cl_icd_layer_dispatch {
  cl_icd_instance_layer *clGetPlatformIDsForInstanceKHR;
  /* OpenCL 1.0 */
  cl_icd_instance_layer *clGetPlatformInfo;
  cl_icd_instance_layer *clGetDeviceIDs;
  cl_icd_instance_layer *clGetDeviceInfo;
  cl_icd_instance_layer *clCreateContext;
  cl_icd_instance_layer *clCreateContextFromType;
  cl_icd_instance_layer *clRetainContext;
  cl_icd_instance_layer *clReleaseContext;
  cl_icd_instance_layer *clGetContextInfo;
  cl_icd_instance_layer *clCreateCommandQueue;
  cl_icd_instance_layer *clRetainCommandQueue;
  cl_icd_instance_layer *clReleaseCommandQueue;
  cl_icd_instance_layer *clGetCommandQueueInfo;
  cl_icd_instance_layer *clSetCommandQueueProperty;
  cl_icd_instance_layer *clCreateBuffer;
  cl_icd_instance_layer *clCreateImage2D;
  cl_icd_instance_layer *clCreateImage3D;
  cl_icd_instance_layer *clRetainMemObject;
  cl_icd_instance_layer *clReleaseMemObject;
  cl_icd_instance_layer *clGetSupportedImageFormats;
  cl_icd_instance_layer *clGetMemObjectInfo;
  cl_icd_instance_layer *clGetImageInfo;
  cl_icd_instance_layer *clCreateSampler;
  cl_icd_instance_layer *clRetainSampler;
  cl_icd_instance_layer *clReleaseSampler;
  cl_icd_instance_layer *clGetSamplerInfo;
  cl_icd_instance_layer *clCreateProgramWithSource;
  cl_icd_instance_layer *clCreateProgramWithBinary;
  cl_icd_instance_layer *clRetainProgram;
  cl_icd_instance_layer *clReleaseProgram;
  cl_icd_instance_layer *clBuildProgram;
  cl_icd_instance_layer *clGetProgramInfo;
  cl_icd_instance_layer *clGetProgramBuildInfo;
  cl_icd_instance_layer *clCreateKernel;
  cl_icd_instance_layer *clCreateKernelsInProgram;
  cl_icd_instance_layer *clRetainKernel;
  cl_icd_instance_layer *clReleaseKernel;
  cl_icd_instance_layer *clSetKernelArg;
  cl_icd_instance_layer *clGetKernelInfo;
  cl_icd_instance_layer *clGetKernelWorkGroupInfo;
  cl_icd_instance_layer *clWaitForEvents;
  cl_icd_instance_layer *clGetEventInfo;
  cl_icd_instance_layer *clRetainEvent;
  cl_icd_instance_layer *clReleaseEvent;
  cl_icd_instance_layer *clGetEventProfilingInfo;
  cl_icd_instance_layer *clFlush;
  cl_icd_instance_layer *clFinish;
  cl_icd_instance_layer *clEnqueueReadBuffer;
  cl_icd_instance_layer *clEnqueueWriteBuffer;
  cl_icd_instance_layer *clEnqueueCopyBuffer;
  cl_icd_instance_layer *clEnqueueReadImage;
  cl_icd_instance_layer *clEnqueueWriteImage;
  cl_icd_instance_layer *clEnqueueCopyImage;
  cl_icd_instance_layer *clEnqueueCopyImageToBuffer;
  cl_icd_instance_layer *clEnqueueCopyBufferToImage;
  cl_icd_instance_layer *clEnqueueMapBuffer;
  cl_icd_instance_layer *clEnqueueMapImage;
  cl_icd_instance_layer *clEnqueueUnmapMemObject;
  cl_icd_instance_layer *clEnqueueNDRangeKernel;
  cl_icd_instance_layer *clEnqueueTask;
  cl_icd_instance_layer *clEnqueueNativeKernel;
  cl_icd_instance_layer *clEnqueueMarker;
  cl_icd_instance_layer *clEnqueueWaitForEvents;
  cl_icd_instance_layer *clEnqueueBarrier;
  cl_icd_instance_layer *clCreateFromGLBuffer;
  cl_icd_instance_layer *clCreateFromGLTexture2D;
  cl_icd_instance_layer *clCreateFromGLTexture3D;
  cl_icd_instance_layer *clCreateFromGLRenderbuffer;
  cl_icd_instance_layer *clGetGLObjectInfo;
  cl_icd_instance_layer *clGetGLTextureInfo;
  cl_icd_instance_layer *clEnqueueAcquireGLObjects;
  cl_icd_instance_layer *clEnqueueReleaseGLObjects;
  cl_icd_instance_layer *clGetGLContextInfoKHR;

  /* cl_khr_d3d10_sharing */
#ifdef _WIN32
  cl_icd_instance_layer *clGetDeviceIDsFromD3D10KHR;
  cl_icd_instance_layer *clCreateFromD3D10BufferKHR;
  cl_icd_instance_layer *clCreateFromD3D10Texture2DKHR;
  cl_icd_instance_layer *clCreateFromD3D10Texture3DKHR;
  cl_icd_instance_layer *clEnqueueAcquireD3D10ObjectsKHR;
  cl_icd_instance_layer *clEnqueueReleaseD3D10ObjectsKHR;
#else
  void *clGetDeviceIDsFromD3D10KHR;
  void *clCreateFromD3D10BufferKHR;
  void *clCreateFromD3D10Texture2DKHR;
  void *clCreateFromD3D10Texture3DKHR;
  void *clEnqueueAcquireD3D10ObjectsKHR;
  void *clEnqueueReleaseD3D10ObjectsKHR;
#endif

  /* OpenCL 1.1 */
  cl_icd_instance_layer *clSetEventCallback;
  cl_icd_instance_layer *clCreateSubBuffer;
  cl_icd_instance_layer *clSetMemObjectDestructorCallback;
  cl_icd_instance_layer *clCreateUserEvent;
  cl_icd_instance_layer *clSetUserEventStatus;
  cl_icd_instance_layer *clEnqueueReadBufferRect;
  cl_icd_instance_layer *clEnqueueWriteBufferRect;
  cl_icd_instance_layer *clEnqueueCopyBufferRect;

  /* cl_ext_device_fission */
  cl_icd_instance_layer *clCreateSubDevicesEXT;
  cl_icd_instance_layer *clRetainDeviceEXT;
  cl_icd_instance_layer *clReleaseDeviceEXT;

  /* cl_khr_gl_event */
  cl_icd_instance_layer *clCreateEventFromGLsyncKHR;

  /* OpenCL 1.2 */
  cl_icd_instance_layer *clCreateSubDevices;
  cl_icd_instance_layer *clRetainDevice;
  cl_icd_instance_layer *clReleaseDevice;
  cl_icd_instance_layer *clCreateImage;
  cl_icd_instance_layer *clCreateProgramWithBuiltInKernels;
  cl_icd_instance_layer *clCompileProgram;
  cl_icd_instance_layer *clLinkProgram;
  cl_icd_instance_layer *clUnloadPlatformCompiler;
  cl_icd_instance_layer *clGetKernelArgInfo;
  cl_icd_instance_layer *clEnqueueFillBuffer;
  cl_icd_instance_layer *clEnqueueFillImage;
  cl_icd_instance_layer *clEnqueueMigrateMemObjects;
  cl_icd_instance_layer *clEnqueueMarkerWithWaitList;
  cl_icd_instance_layer *clEnqueueBarrierWithWaitList;
  cl_icd_instance_layer *clGetExtensionFunctionAddressForPlatform;
  cl_icd_instance_layer *clCreateFromGLTexture;

  /* cl_khr_d3d11_sharing and cl_khr_dx9_media_sharing */
#ifdef _WIN32
  cl_icd_instance_layer *clGetDeviceIDsFromD3D11KHR;
  cl_icd_instance_layer *clCreateFromD3D11BufferKHR;
  cl_icd_instance_layer *clCreateFromD3D11Texture2DKHR;
  cl_icd_instance_layer *clCreateFromD3D11Texture3DKHR;
  cl_icd_instance_layer *clCreateFromDX9MediaSurfaceKHR;
  cl_icd_instance_layer *clEnqueueAcquireD3D11ObjectsKHR;
  cl_icd_instance_layer *clEnqueueReleaseD3D11ObjectsKHR;
  cl_icd_instance_layer *clGetDeviceIDsFromDX9MediaAdapterKHR;
  cl_icd_instance_layer *clEnqueueAcquireDX9MediaSurfacesKHR;
  cl_icd_instance_layer *clEnqueueReleaseDX9MediaSurfacesKHR;
#else
  void *clGetDeviceIDsFromD3D11KHR;
  void *clCreateFromD3D11BufferKHR;
  void *clCreateFromD3D11Texture2DKHR;
  void *clCreateFromD3D11Texture3DKHR;
  void *clCreateFromDX9MediaSurfaceKHR;
  void *clEnqueueAcquireD3D11ObjectsKHR;
  void *clEnqueueReleaseD3D11ObjectsKHR;
  void *clGetDeviceIDsFromDX9MediaAdapterKHR;
  void *clEnqueueAcquireDX9MediaSurfacesKHR;
  void *clEnqueueReleaseDX9MediaSurfacesKHR;
#endif

  /* cl_khr_egl_image */
  cl_icd_instance_layer *clCreateFromEGLImageKHR;
  cl_icd_instance_layer *clEnqueueAcquireEGLObjectsKHR;
  cl_icd_instance_layer *clEnqueueReleaseEGLObjectsKHR;

  /* cl_khr_egl_event */
  cl_icd_instance_layer *clCreateEventFromEGLSyncKHR;

  /* OpenCL 2.0 */
  cl_icd_instance_layer *clCreateCommandQueueWithProperties;
  cl_icd_instance_layer *clCreatePipe;
  cl_icd_instance_layer *clGetPipeInfo;
  cl_icd_instance_layer *clSVMAlloc;
  cl_icd_instance_layer *clSVMFree;
  cl_icd_instance_layer *clEnqueueSVMFree;
  cl_icd_instance_layer *clEnqueueSVMMemcpy;
  cl_icd_instance_layer *clEnqueueSVMMemFill;
  cl_icd_instance_layer *clEnqueueSVMMap;
  cl_icd_instance_layer *clEnqueueSVMUnmap;
  cl_icd_instance_layer *clCreateSamplerWithProperties;
  cl_icd_instance_layer *clSetKernelArgSVMPointer;
  cl_icd_instance_layer *clSetKernelExecInfo;

  /* cl_khr_sub_groups */
  cl_icd_instance_layer *clGetKernelSubGroupInfoKHR;

  /* OpenCL 2.1 */
  cl_icd_instance_layer *clCloneKernel;
  cl_icd_instance_layer *clCreateProgramWithIL;
  cl_icd_instance_layer *clEnqueueSVMMigrateMem;
  cl_icd_instance_layer *clGetDeviceAndHostTimer;
  cl_icd_instance_layer *clGetHostTimer;
  cl_icd_instance_layer *clGetKernelSubGroupInfo;
  cl_icd_instance_layer *clSetDefaultDeviceCommandQueue;

  /* OpenCL 2.2 */
  cl_icd_instance_layer *clSetProgramReleaseCallback;
  cl_icd_instance_layer *clSetProgramSpecializationConstant;

  /* OpenCL 3.0 */
  cl_icd_instance_layer *clCreateBufferWithProperties;
  cl_icd_instance_layer *clCreateImageWithProperties;
  cl_icd_instance_layer *clSetContextDestructorCallback;
}
;

struct _cl_icd_instance_layer {
    cl_icd_instance_dispatch *dispatch;
    cl_icd_layer_dispatch    *layer_dispatch;
    void                     *data;
};

#define CL_INSTANCE_LAYER_DATA(layer) ((layer)->data)

#define CL_INSTANCE_LAYER_NEXT_LAYER(layer, api) ((layer)->layer_dispatch->api)

#define CL_INSTANCE_LAYER_NEXT_LAYER_DISPATCH(layer, api) CL_INSTANCE_LAYER_NEXT_LAYER(layer, api)->dispatch

#define CL_INSTANCE_LAYER_NEXT_ENTRY(layer, api) CL_INSTANCE_LAYER_NEXT_LAYER_DISPATCH(layer, api)->api

#define CL_INSTANCE_LAYER_CALL_NEXT(layer, api, ...) CL_INSTANCE_LAYER_NEXT_ENTRY(layer, api)(CL_INSTANCE_LAYER_NEXT_LAYER(layer, api), __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif // OPENCL_CL_INSTANCE_LAYER_H_
