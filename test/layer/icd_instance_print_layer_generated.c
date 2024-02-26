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

#include "icd_instance_print_layer.h"

static cl_int CL_API_CALL
clGetPlatformIDsForInstanceKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_instance_khr instance,
    cl_uint num_entries,
    cl_platform_id *platforms,
    cl_uint *num_platforms)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetPlatformIDsForInstanceKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetPlatformIDsForInstanceKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetPlatformIDsForInstanceKHR),
        instance,
        num_entries,
        platforms,
        num_platforms);
}

///////////////////////////////////////////////////////////////////////////////
// Core APIs:
static cl_int CL_API_CALL clGetPlatformInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_platform_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetPlatformInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetPlatformInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetPlatformInfo),
        platform,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetDeviceIDs_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_device_type device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceIDs\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceIDs)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceIDs),
        platform,
        device_type,
        num_entries,
        devices,
        num_devices);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetDeviceInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_device_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceInfo),
        device,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_context CL_API_CALL clCreateContext_wrap(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateContext\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateContext)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateContext),
        properties,
        num_devices,
        devices,
        pfn_notify,
        user_data,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_context CL_API_CALL clCreateContextFromType_wrap(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_device_type device_type,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateContextFromType\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateContextFromType)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateContextFromType),
        properties,
        device_type,
        pfn_notify,
        user_data,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainContext_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainContext\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainContext)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainContext),
        context);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseContext_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseContext\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseContext)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseContext),
        context);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetContextInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetContextInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetContextInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetContextInfo),
        context,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainCommandQueue_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainCommandQueue\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainCommandQueue)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainCommandQueue),
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseCommandQueue_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseCommandQueue\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseCommandQueue)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseCommandQueue),
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetCommandQueueInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_command_queue_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetCommandQueueInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetCommandQueueInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetCommandQueueInfo),
        command_queue,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateBuffer),
        context,
        flags,
        size,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainMemObject_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainMemObject\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainMemObject)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainMemObject),
        memobj);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseMemObject_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseMemObject\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseMemObject)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseMemObject),
        memobj);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetSupportedImageFormats_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_mem_object_type image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetSupportedImageFormats\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetSupportedImageFormats)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetSupportedImageFormats),
        context,
        flags,
        image_type,
        num_entries,
        image_formats,
        num_image_formats);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetMemObjectInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_mem_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetMemObjectInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetMemObjectInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetMemObjectInfo),
        memobj,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetImageInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem image,
    cl_image_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetImageInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetImageInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetImageInfo),
        image,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainSampler_wrap(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainSampler\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainSampler)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainSampler),
        sampler);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseSampler_wrap(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseSampler\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseSampler)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseSampler),
        sampler);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetSamplerInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_sampler sampler,
    cl_sampler_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetSamplerInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetSamplerInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetSamplerInfo),
        sampler,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_program CL_API_CALL clCreateProgramWithSource_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateProgramWithSource\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateProgramWithSource)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateProgramWithSource),
        context,
        count,
        strings,
        lengths,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_program CL_API_CALL clCreateProgramWithBinary_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateProgramWithBinary\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateProgramWithBinary)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateProgramWithBinary),
        context,
        num_devices,
        device_list,
        lengths,
        binaries,
        binary_status,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainProgram),
        program);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseProgram),
        program);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clBuildProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clBuildProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clBuildProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clBuildProgram),
        program,
        num_devices,
        device_list,
        options,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetProgramInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_program_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetProgramInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetProgramInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetProgramInfo),
        program,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetProgramBuildInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_device_id device,
    cl_program_build_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetProgramBuildInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetProgramBuildInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetProgramBuildInfo),
        program,
        device,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_kernel CL_API_CALL clCreateKernel_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    const char* kernel_name,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateKernel),
        program,
        kernel_name,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clCreateKernelsInProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateKernelsInProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateKernelsInProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateKernelsInProgram),
        program,
        num_kernels,
        kernels,
        num_kernels_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainKernel_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainKernel),
        kernel);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseKernel_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseKernel),
        kernel);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetKernelArg_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetKernelArg\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetKernelArg)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetKernelArg),
        kernel,
        arg_index,
        arg_size,
        arg_value);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetKernelInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_kernel_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetKernelInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetKernelInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetKernelInfo),
        kernel,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetKernelWorkGroupInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_work_group_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetKernelWorkGroupInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetKernelWorkGroupInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetKernelWorkGroupInfo),
        kernel,
        device,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clWaitForEvents_wrap(
    const cl_icd_instance_layer *layer,
    cl_uint num_events,
    const cl_event* event_list)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clWaitForEvents\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clWaitForEvents)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clWaitForEvents),
        num_events,
        event_list);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetEventInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_event_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetEventInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetEventInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetEventInfo),
        event,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainEvent_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainEvent\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainEvent)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainEvent),
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseEvent_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseEvent\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseEvent)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseEvent),
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetEventProfilingInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_profiling_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetEventProfilingInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetEventProfilingInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetEventProfilingInfo),
        event,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clFlush_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clFlush\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clFlush)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clFlush),
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clFinish_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clFinish\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clFinish)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clFinish),
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueReadBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReadBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReadBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReadBuffer),
        command_queue,
        buffer,
        blocking_read,
        offset,
        size,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueWriteBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueWriteBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueWriteBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueWriteBuffer),
        command_queue,
        buffer,
        blocking_write,
        offset,
        size,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueCopyBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueCopyBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueCopyBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueCopyBuffer),
        command_queue,
        src_buffer,
        dst_buffer,
        src_offset,
        dst_offset,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueReadImage_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReadImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReadImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReadImage),
        command_queue,
        image,
        blocking_read,
        origin,
        region,
        row_pitch,
        slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueWriteImage_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueWriteImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueWriteImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueWriteImage),
        command_queue,
        image,
        blocking_write,
        origin,
        region,
        input_row_pitch,
        input_slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueCopyImage_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueCopyImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueCopyImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueCopyImage),
        command_queue,
        src_image,
        dst_image,
        src_origin,
        dst_origin,
        region,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueCopyImageToBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueCopyImageToBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueCopyImageToBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueCopyImageToBuffer),
        command_queue,
        src_image,
        dst_buffer,
        src_origin,
        region,
        dst_offset,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueCopyBufferToImage_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueCopyBufferToImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueCopyBufferToImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueCopyBufferToImage),
        command_queue,
        src_buffer,
        dst_image,
        src_offset,
        dst_origin,
        region,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static void* CL_API_CALL clEnqueueMapBuffer_wrap(
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
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueMapBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueMapBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueMapBuffer),
        command_queue,
        buffer,
        blocking_map,
        map_flags,
        offset,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static void* CL_API_CALL clEnqueueMapImage_wrap(
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
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueMapImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueMapImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueMapImage),
        command_queue,
        image,
        blocking_map,
        map_flags,
        origin,
        region,
        image_row_pitch,
        image_slice_pitch,
        num_events_in_wait_list,
        event_wait_list,
        event,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueUnmapMemObject_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueUnmapMemObject\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueUnmapMemObject)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueUnmapMemObject),
        command_queue,
        memobj,
        mapped_ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueNDRangeKernel_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueNDRangeKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueNDRangeKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueNDRangeKernel),
        command_queue,
        kernel,
        work_dim,
        global_work_offset,
        global_work_size,
        local_work_size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueNativeKernel_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueNativeKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueNativeKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueNativeKernel),
        command_queue,
        user_func,
        args,
        cb_args,
        num_mem_objects,
        mem_list,
        args_mem_loc,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetCommandQueueProperty_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetCommandQueueProperty\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetCommandQueueProperty)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetCommandQueueProperty),
        command_queue,
        properties,
        enable,
        old_properties);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateImage2D_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void* host_ptr,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateImage2D\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateImage2D)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateImage2D),
        context,
        flags,
        image_format,
        image_width,
        image_height,
        image_row_pitch,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateImage3D_wrap(
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
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateImage3D\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateImage3D)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateImage3D),
        context,
        flags,
        image_format,
        image_width,
        image_height,
        image_depth,
        image_row_pitch,
        image_slice_pitch,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueMarker_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueMarker\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueMarker)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueMarker),
        command_queue,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueWaitForEvents_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueWaitForEvents\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueWaitForEvents)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueWaitForEvents),
        command_queue,
        num_events,
        event_list);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueBarrier_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueBarrier\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueBarrier)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueBarrier),
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_command_queue CL_API_CALL clCreateCommandQueue_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateCommandQueue\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateCommandQueue)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateCommandQueue),
        context,
        device,
        properties,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_sampler CL_API_CALL clCreateSampler_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateSampler\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateSampler)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateSampler),
        context,
        normalized_coords,
        addressing_mode,
        filter_mode,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueTask_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueTask\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueTask)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueTask),
        command_queue,
        kernel,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateSubBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateSubBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateSubBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateSubBuffer),
        buffer,
        flags,
        buffer_create_type,
        buffer_create_info,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetMemObjectDestructorCallback_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetMemObjectDestructorCallback\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetMemObjectDestructorCallback)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetMemObjectDestructorCallback),
        memobj,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_event CL_API_CALL clCreateUserEvent_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateUserEvent\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateUserEvent)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateUserEvent),
        context,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetUserEventStatus_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_int execution_status)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetUserEventStatus\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetUserEventStatus)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetUserEventStatus),
        event,
        execution_status);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetEventCallback_wrap(
    const cl_icd_instance_layer *layer,
    cl_event event,
    cl_int command_exec_callback_type,
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int event_command_status, void *user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetEventCallback\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetEventCallback)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetEventCallback),
        event,
        command_exec_callback_type,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueReadBufferRect_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReadBufferRect\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReadBufferRect)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReadBufferRect),
        command_queue,
        buffer,
        blocking_read,
        buffer_origin,
        host_origin,
        region,
        buffer_row_pitch,
        buffer_slice_pitch,
        host_row_pitch,
        host_slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueWriteBufferRect_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueWriteBufferRect\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueWriteBufferRect)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueWriteBufferRect),
        command_queue,
        buffer,
        blocking_write,
        buffer_origin,
        host_origin,
        region,
        buffer_row_pitch,
        buffer_slice_pitch,
        host_row_pitch,
        host_slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueCopyBufferRect_wrap(
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
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueCopyBufferRect\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueCopyBufferRect)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueCopyBufferRect),
        command_queue,
        src_buffer,
        dst_buffer,
        src_origin,
        dst_origin,
        region,
        src_row_pitch,
        src_slice_pitch,
        dst_row_pitch,
        dst_slice_pitch,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clCreateSubDevices_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint* num_devices_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateSubDevices\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateSubDevices)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateSubDevices),
        in_device,
        properties,
        num_devices,
        out_devices,
        num_devices_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clRetainDevice_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainDevice\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainDevice)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainDevice),
        device);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clReleaseDevice_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseDevice\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseDevice)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseDevice),
        device);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateImage_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateImage),
        context,
        flags,
        image_format,
        image_desc,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_program CL_API_CALL clCreateProgramWithBuiltInKernels_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateProgramWithBuiltInKernels\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateProgramWithBuiltInKernels)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateProgramWithBuiltInKernels),
        context,
        num_devices,
        device_list,
        kernel_names,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clCompileProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCompileProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCompileProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCompileProgram),
        program,
        num_devices,
        device_list,
        options,
        num_input_headers,
        input_headers,
        header_include_names,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_program CL_API_CALL clLinkProgram_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clLinkProgram\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clLinkProgram)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clLinkProgram),
        context,
        num_devices,
        device_list,
        options,
        num_input_programs,
        input_programs,
        pfn_notify,
        user_data,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clUnloadPlatformCompiler_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clUnloadPlatformCompiler\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clUnloadPlatformCompiler)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clUnloadPlatformCompiler),
        platform);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetKernelArgInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    cl_kernel_arg_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetKernelArgInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetKernelArgInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetKernelArgInfo),
        kernel,
        arg_index,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueFillBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueFillBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueFillBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueFillBuffer),
        command_queue,
        buffer,
        pattern,
        pattern_size,
        offset,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueFillImage_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueFillImage\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueFillImage)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueFillImage),
        command_queue,
        image,
        fill_color,
        origin,
        region,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueMigrateMemObjects_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueMigrateMemObjects\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueMigrateMemObjects)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueMigrateMemObjects),
        command_queue,
        num_mem_objects,
        mem_objects,
        flags,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueMarkerWithWaitList_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueMarkerWithWaitList\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueMarkerWithWaitList)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueMarkerWithWaitList),
        command_queue,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueBarrierWithWaitList_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueBarrierWithWaitList\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueBarrierWithWaitList)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueBarrierWithWaitList),
        command_queue,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static void* CL_API_CALL clGetExtensionFunctionAddressForPlatform_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    const char* func_name)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetExtensionFunctionAddressForPlatform\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetExtensionFunctionAddressForPlatform)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetExtensionFunctionAddressForPlatform),
        platform,
        func_name);
}

///////////////////////////////////////////////////////////////////////////////
static cl_command_queue CL_API_CALL clCreateCommandQueueWithProperties_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateCommandQueueWithProperties\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateCommandQueueWithProperties)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateCommandQueueWithProperties),
        context,
        device,
        properties,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreatePipe_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreatePipe\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreatePipe)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreatePipe),
        context,
        flags,
        pipe_packet_size,
        pipe_max_packets,
        properties,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetPipeInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem pipe,
    cl_pipe_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetPipeInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetPipeInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetPipeInfo),
        pipe,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static void* CL_API_CALL clSVMAlloc_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSVMAlloc\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSVMAlloc)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSVMAlloc),
        context,
        flags,
        size,
        alignment);
}

///////////////////////////////////////////////////////////////////////////////
static void CL_API_CALL clSVMFree_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    void* svm_pointer)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSVMFree\n", *(int*)data);
    CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSVMFree)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSVMFree),
        context,
        svm_pointer);
}

///////////////////////////////////////////////////////////////////////////////
static cl_sampler CL_API_CALL clCreateSamplerWithProperties_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateSamplerWithProperties\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateSamplerWithProperties)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateSamplerWithProperties),
        context,
        sampler_properties,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetKernelArgSVMPointer_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetKernelArgSVMPointer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetKernelArgSVMPointer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetKernelArgSVMPointer),
        kernel,
        arg_index,
        arg_value);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetKernelExecInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void* param_value)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetKernelExecInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetKernelExecInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetKernelExecInfo),
        kernel,
        param_name,
        param_value_size,
        param_value);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMFree_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMFree\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMFree)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMFree),
        command_queue,
        num_svm_pointers,
        svm_pointers,
        pfn_free_func,
        user_data,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMMemcpy_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMMemcpy\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMMemcpy)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMMemcpy),
        command_queue,
        blocking_copy,
        dst_ptr,
        src_ptr,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMMemFill_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMMemFill\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMMemFill)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMMemFill),
        command_queue,
        svm_ptr,
        pattern,
        pattern_size,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMMap_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMMap\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMMap)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMMap),
        command_queue,
        blocking_map,
        flags,
        svm_ptr,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMUnmap_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMUnmap\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMUnmap)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMUnmap),
        command_queue,
        svm_ptr,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetDefaultDeviceCommandQueue_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetDefaultDeviceCommandQueue\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetDefaultDeviceCommandQueue)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetDefaultDeviceCommandQueue),
        context,
        device,
        command_queue);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetDeviceAndHostTimer_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceAndHostTimer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceAndHostTimer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceAndHostTimer),
        device,
        device_timestamp,
        host_timestamp);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetHostTimer_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device,
    cl_ulong* host_timestamp)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetHostTimer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetHostTimer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetHostTimer),
        device,
        host_timestamp);
}

///////////////////////////////////////////////////////////////////////////////
static cl_program CL_API_CALL clCreateProgramWithIL_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateProgramWithIL\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateProgramWithIL)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateProgramWithIL),
        context,
        il,
        length,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_kernel CL_API_CALL clCloneKernel_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel source_kernel,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCloneKernel\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCloneKernel)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCloneKernel),
        source_kernel,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clGetKernelSubGroupInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetKernelSubGroupInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetKernelSubGroupInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetKernelSubGroupInfo),
        kernel,
        device,
        param_name,
        input_value_size,
        input_value,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clEnqueueSVMMigrateMem_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void** svm_pointers,
    const size_t* sizes,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueSVMMigrateMem\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueSVMMigrateMem)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueSVMMigrateMem),
        command_queue,
        num_svm_pointers,
        svm_pointers,
        sizes,
        flags,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetProgramSpecializationConstant_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    cl_uint spec_id,
    size_t spec_size,
    const void* spec_value)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetProgramSpecializationConstant\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetProgramSpecializationConstant)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetProgramSpecializationConstant),
        program,
        spec_id,
        spec_size,
        spec_value);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetProgramReleaseCallback_wrap(
    const cl_icd_instance_layer *layer,
    cl_program program,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetProgramReleaseCallback\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetProgramReleaseCallback)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetProgramReleaseCallback),
        program,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_int CL_API_CALL clSetContextDestructorCallback_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    void (CL_CALLBACK* pfn_notify)(cl_context context, void* user_data),
    void* user_data)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clSetContextDestructorCallback\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clSetContextDestructorCallback)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clSetContextDestructorCallback),
        context,
        pfn_notify,
        user_data);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateBufferWithProperties_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateBufferWithProperties\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateBufferWithProperties)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateBufferWithProperties),
        context,
        properties,
        flags,
        size,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////
static cl_mem CL_API_CALL clCreateImageWithProperties_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateImageWithProperties\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateImageWithProperties)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateImageWithProperties),
        context,
        properties,
        flags,
        image_format,
        image_desc,
        host_ptr,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////

// cl_ext_device_fission
static cl_int CL_API_CALL clReleaseDeviceEXT_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clReleaseDeviceEXT\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clReleaseDeviceEXT)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clReleaseDeviceEXT),
        device);
}
static cl_int CL_API_CALL clRetainDeviceEXT_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id device)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clRetainDeviceEXT\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clRetainDeviceEXT)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clRetainDeviceEXT),
        device);
}
static cl_int CL_API_CALL clCreateSubDevicesEXT_wrap(
    const cl_icd_instance_layer *layer,
    cl_device_id in_device,
    const cl_device_partition_property_ext* properties,
    cl_uint num_entries,
    cl_device_id* out_devices,
    cl_uint* num_devices)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateSubDevicesEXT\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateSubDevicesEXT)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateSubDevicesEXT),
        in_device,
        properties,
        num_entries,
        out_devices,
        num_devices);
}

///////////////////////////////////////////////////////////////////////////////

// cl_khr_d3d10_sharing

#if defined(_WIN32)
static cl_int CL_API_CALL clGetDeviceIDsFromD3D10KHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_d3d10_device_source_khr d3d_device_source,
    void* d3d_object,
    cl_d3d10_device_set_khr d3d_device_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceIDsFromD3D10KHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceIDsFromD3D10KHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceIDsFromD3D10KHR),
        platform,
        d3d_device_source,
        d3d_object,
        d3d_device_set,
        num_entries,
        devices,
        num_devices);
}
static cl_mem CL_API_CALL clCreateFromD3D10BufferKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Buffer* resource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D10BufferKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D10BufferKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D10BufferKHR),
        context,
        flags,
        resource,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromD3D10Texture2DKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Texture2D* resource,
    UINT subresource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D10Texture2DKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D10Texture2DKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D10Texture2DKHR),
        context,
        flags,
        resource,
        subresource,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromD3D10Texture3DKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D10Texture3D* resource,
    UINT subresource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D10Texture3DKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D10Texture3DKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D10Texture3DKHR),
        context,
        flags,
        resource,
        subresource,
        errcode_ret);
}
static cl_int CL_API_CALL clEnqueueAcquireD3D10ObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueAcquireD3D10ObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueAcquireD3D10ObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueAcquireD3D10ObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_int CL_API_CALL clEnqueueReleaseD3D10ObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReleaseD3D10ObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReleaseD3D10ObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReleaseD3D10ObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_d3d11_sharing

#if defined(_WIN32)
static cl_int CL_API_CALL clGetDeviceIDsFromD3D11KHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_d3d11_device_source_khr d3d_device_source,
    void* d3d_object,
    cl_d3d11_device_set_khr d3d_device_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceIDsFromD3D11KHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceIDsFromD3D11KHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceIDsFromD3D11KHR),
        platform,
        d3d_device_source,
        d3d_object,
        d3d_device_set,
        num_entries,
        devices,
        num_devices);
}
static cl_mem CL_API_CALL clCreateFromD3D11BufferKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Buffer* resource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D11BufferKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D11BufferKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D11BufferKHR),
        context,
        flags,
        resource,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromD3D11Texture2DKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Texture2D* resource,
    UINT subresource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D11Texture2DKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D11Texture2DKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D11Texture2DKHR),
        context,
        flags,
        resource,
        subresource,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromD3D11Texture3DKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    ID3D11Texture3D* resource,
    UINT subresource,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromD3D11Texture3DKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromD3D11Texture3DKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromD3D11Texture3DKHR),
        context,
        flags,
        resource,
        subresource,
        errcode_ret);
}
static cl_int CL_API_CALL clEnqueueAcquireD3D11ObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueAcquireD3D11ObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueAcquireD3D11ObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueAcquireD3D11ObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_int CL_API_CALL clEnqueueReleaseD3D11ObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReleaseD3D11ObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReleaseD3D11ObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReleaseD3D11ObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_dx9_media_sharing

#if defined(_WIN32)
static cl_int CL_API_CALL clGetDeviceIDsFromDX9MediaAdapterKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_platform_id platform,
    cl_uint num_media_adapters,
    cl_dx9_media_adapter_type_khr* media_adapter_type,
    void* media_adapters,
    cl_dx9_media_adapter_set_khr media_adapter_set,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetDeviceIDsFromDX9MediaAdapterKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetDeviceIDsFromDX9MediaAdapterKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetDeviceIDsFromDX9MediaAdapterKHR),
        platform,
        num_media_adapters,
        media_adapter_type,
        media_adapters,
        media_adapter_set,
        num_entries,
        devices,
        num_devices);
}
static cl_mem CL_API_CALL clCreateFromDX9MediaSurfaceKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_dx9_media_adapter_type_khr adapter_type,
    void* surface_info,
    cl_uint plane,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromDX9MediaSurfaceKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromDX9MediaSurfaceKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromDX9MediaSurfaceKHR),
        context,
        flags,
        adapter_type,
        surface_info,
        plane,
        errcode_ret);
}
static cl_int CL_API_CALL clEnqueueAcquireDX9MediaSurfacesKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueAcquireDX9MediaSurfacesKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueAcquireDX9MediaSurfacesKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueAcquireDX9MediaSurfacesKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_int CL_API_CALL clEnqueueReleaseDX9MediaSurfacesKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReleaseDX9MediaSurfacesKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReleaseDX9MediaSurfacesKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReleaseDX9MediaSurfacesKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////

// cl_khr_egl_event
static cl_event CL_API_CALL clCreateEventFromEGLSyncKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    CLeglSyncKHR sync,
    CLeglDisplayKHR display,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateEventFromEGLSyncKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateEventFromEGLSyncKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateEventFromEGLSyncKHR),
        context,
        sync,
        display,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////

// cl_khr_egl_image
static cl_mem CL_API_CALL clCreateFromEGLImageKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    CLeglDisplayKHR egldisplay,
    CLeglImageKHR eglimage,
    cl_mem_flags flags,
    const cl_egl_image_properties_khr* properties,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromEGLImageKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromEGLImageKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromEGLImageKHR),
        context,
        egldisplay,
        eglimage,
        flags,
        properties,
        errcode_ret);
}
static cl_int CL_API_CALL clEnqueueAcquireEGLObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueAcquireEGLObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueAcquireEGLObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueAcquireEGLObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_int CL_API_CALL clEnqueueReleaseEGLObjectsKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReleaseEGLObjectsKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReleaseEGLObjectsKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReleaseEGLObjectsKHR),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}

///////////////////////////////////////////////////////////////////////////////

// cl_khr_gl_event
static cl_event CL_API_CALL clCreateEventFromGLsyncKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_GLsync sync,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateEventFromGLsyncKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateEventFromGLsyncKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateEventFromGLsyncKHR),
        context,
        sync,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////

// cl_khr_gl_sharing
static cl_int CL_API_CALL clGetGLContextInfoKHR_wrap(
    const cl_icd_instance_layer *layer,
    const cl_context_properties* properties,
    cl_gl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetGLContextInfoKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetGLContextInfoKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetGLContextInfoKHR),
        properties,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}
static cl_mem CL_API_CALL clCreateFromGLBuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLuint bufobj,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromGLBuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromGLBuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromGLBuffer),
        context,
        flags,
        bufobj,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromGLTexture_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromGLTexture\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromGLTexture)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromGLTexture),
        context,
        flags,
        target,
        miplevel,
        texture,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromGLRenderbuffer_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLuint renderbuffer,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromGLRenderbuffer\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromGLRenderbuffer)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromGLRenderbuffer),
        context,
        flags,
        renderbuffer,
        errcode_ret);
}
static cl_int CL_API_CALL clGetGLObjectInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_gl_object_type* gl_object_type,
    cl_GLuint* gl_object_name)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetGLObjectInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetGLObjectInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetGLObjectInfo),
        memobj,
        gl_object_type,
        gl_object_name);
}
static cl_int CL_API_CALL clGetGLTextureInfo_wrap(
    const cl_icd_instance_layer *layer,
    cl_mem memobj,
    cl_gl_texture_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetGLTextureInfo\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetGLTextureInfo)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetGLTextureInfo),
        memobj,
        param_name,
        param_value_size,
        param_value,
        param_value_size_ret);
}
static cl_int CL_API_CALL clEnqueueAcquireGLObjects_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueAcquireGLObjects\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueAcquireGLObjects)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueAcquireGLObjects),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_int CL_API_CALL clEnqueueReleaseGLObjects_wrap(
    const cl_icd_instance_layer *layer,
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clEnqueueReleaseGLObjects\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clEnqueueReleaseGLObjects)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clEnqueueReleaseGLObjects),
        command_queue,
        num_objects,
        mem_objects,
        num_events_in_wait_list,
        event_wait_list,
        event);
}
static cl_mem CL_API_CALL clCreateFromGLTexture2D_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromGLTexture2D\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromGLTexture2D)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromGLTexture2D),
        context,
        flags,
        target,
        miplevel,
        texture,
        errcode_ret);
}
static cl_mem CL_API_CALL clCreateFromGLTexture3D_wrap(
    const cl_icd_instance_layer *layer,
    cl_context context,
    cl_mem_flags flags,
    cl_GLenum target,
    cl_GLint miplevel,
    cl_GLuint texture,
    cl_int* errcode_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clCreateFromGLTexture3D\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clCreateFromGLTexture3D)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clCreateFromGLTexture3D),
        context,
        flags,
        target,
        miplevel,
        texture,
        errcode_ret);
}

///////////////////////////////////////////////////////////////////////////////

// cl_khr_subgroups
static cl_int CL_API_CALL clGetKernelSubGroupInfoKHR_wrap(
    const cl_icd_instance_layer *layer,
    cl_kernel in_kernel,
    cl_device_id in_device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: clGetKernelSubGroupInfoKHR\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, clGetKernelSubGroupInfoKHR)(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, clGetKernelSubGroupInfoKHR),
        in_kernel,
        in_device,
        param_name,
        input_value_size,
        input_value,
        param_value_size,
        param_value,
        param_value_size_ret);
}

///////////////////////////////////////////////////////////////////////////////

struct _cl_icd_instance_dispatch dispatch = {
  &clGetPlatformIDsForInstanceKHR_wrap,
  /* OpenCL 1.0 */
  &clGetPlatformInfo_wrap,
  &clGetDeviceIDs_wrap,
  &clGetDeviceInfo_wrap,
  &clCreateContext_wrap,
  &clCreateContextFromType_wrap,
  &clRetainContext_wrap,
  &clReleaseContext_wrap,
  &clGetContextInfo_wrap,
  &clCreateCommandQueue_wrap,
  &clRetainCommandQueue_wrap,
  &clReleaseCommandQueue_wrap,
  &clGetCommandQueueInfo_wrap,
  &clSetCommandQueueProperty_wrap,
  &clCreateBuffer_wrap,
  &clCreateImage2D_wrap,
  &clCreateImage3D_wrap,
  &clRetainMemObject_wrap,
  &clReleaseMemObject_wrap,
  &clGetSupportedImageFormats_wrap,
  &clGetMemObjectInfo_wrap,
  &clGetImageInfo_wrap,
  &clCreateSampler_wrap,
  &clRetainSampler_wrap,
  &clReleaseSampler_wrap,
  &clGetSamplerInfo_wrap,
  &clCreateProgramWithSource_wrap,
  &clCreateProgramWithBinary_wrap,
  &clRetainProgram_wrap,
  &clReleaseProgram_wrap,
  &clBuildProgram_wrap,
  &clGetProgramInfo_wrap,
  &clGetProgramBuildInfo_wrap,
  &clCreateKernel_wrap,
  &clCreateKernelsInProgram_wrap,
  &clRetainKernel_wrap,
  &clReleaseKernel_wrap,
  &clSetKernelArg_wrap,
  &clGetKernelInfo_wrap,
  &clGetKernelWorkGroupInfo_wrap,
  &clWaitForEvents_wrap,
  &clGetEventInfo_wrap,
  &clRetainEvent_wrap,
  &clReleaseEvent_wrap,
  &clGetEventProfilingInfo_wrap,
  &clFlush_wrap,
  &clFinish_wrap,
  &clEnqueueReadBuffer_wrap,
  &clEnqueueWriteBuffer_wrap,
  &clEnqueueCopyBuffer_wrap,
  &clEnqueueReadImage_wrap,
  &clEnqueueWriteImage_wrap,
  &clEnqueueCopyImage_wrap,
  &clEnqueueCopyImageToBuffer_wrap,
  &clEnqueueCopyBufferToImage_wrap,
  &clEnqueueMapBuffer_wrap,
  &clEnqueueMapImage_wrap,
  &clEnqueueUnmapMemObject_wrap,
  &clEnqueueNDRangeKernel_wrap,
  &clEnqueueTask_wrap,
  &clEnqueueNativeKernel_wrap,
  &clEnqueueMarker_wrap,
  &clEnqueueWaitForEvents_wrap,
  &clEnqueueBarrier_wrap,
  &clCreateFromGLBuffer_wrap,
  &clCreateFromGLTexture2D_wrap,
  &clCreateFromGLTexture3D_wrap,
  &clCreateFromGLRenderbuffer_wrap,
  &clGetGLObjectInfo_wrap,
  &clGetGLTextureInfo_wrap,
  &clEnqueueAcquireGLObjects_wrap,
  &clEnqueueReleaseGLObjects_wrap,
  &clGetGLContextInfoKHR_wrap,

  /* cl_khr_d3d10_sharing */
#ifdef _WIN32
  &clGetDeviceIDsFromD3D10KHR_wrap,
  &clCreateFromD3D10BufferKHR_wrap,
  &clCreateFromD3D10Texture2DKHR_wrap,
  &clCreateFromD3D10Texture3DKHR_wrap,
  &clEnqueueAcquireD3D10ObjectsKHR_wrap,
  &clEnqueueReleaseD3D10ObjectsKHR_wrap,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif

  /* OpenCL 1.1 */
  &clSetEventCallback_wrap,
  &clCreateSubBuffer_wrap,
  &clSetMemObjectDestructorCallback_wrap,
  &clCreateUserEvent_wrap,
  &clSetUserEventStatus_wrap,
  &clEnqueueReadBufferRect_wrap,
  &clEnqueueWriteBufferRect_wrap,
  &clEnqueueCopyBufferRect_wrap,

  /* cl_ext_device_fission */
  &clCreateSubDevicesEXT_wrap,
  &clRetainDeviceEXT_wrap,
  &clReleaseDeviceEXT_wrap,

  /* cl_khr_gl_event */
  &clCreateEventFromGLsyncKHR_wrap,

  /* OpenCL 1.2 */
  &clCreateSubDevices_wrap,
  &clRetainDevice_wrap,
  &clReleaseDevice_wrap,
  &clCreateImage_wrap,
  &clCreateProgramWithBuiltInKernels_wrap,
  &clCompileProgram_wrap,
  &clLinkProgram_wrap,
  &clUnloadPlatformCompiler_wrap,
  &clGetKernelArgInfo_wrap,
  &clEnqueueFillBuffer_wrap,
  &clEnqueueFillImage_wrap,
  &clEnqueueMigrateMemObjects_wrap,
  &clEnqueueMarkerWithWaitList_wrap,
  &clEnqueueBarrierWithWaitList_wrap,
  &clGetExtensionFunctionAddressForPlatform_wrap,
  &clCreateFromGLTexture_wrap,

  /* cl_khr_d3d11_sharing and cl_khr_dx9_media_sharing */
#ifdef _WIN32
  &clGetDeviceIDsFromD3D11KHR_wrap,
  &clCreateFromD3D11BufferKHR_wrap,
  &clCreateFromD3D11Texture2DKHR_wrap,
  &clCreateFromD3D11Texture3DKHR_wrap,
  &clCreateFromDX9MediaSurfaceKHR_wrap,
  &clEnqueueAcquireD3D11ObjectsKHR_wrap,
  &clEnqueueReleaseD3D11ObjectsKHR_wrap,
  &clGetDeviceIDsFromDX9MediaAdapterKHR_wrap,
  &clEnqueueAcquireDX9MediaSurfacesKHR_wrap,
  &clEnqueueReleaseDX9MediaSurfacesKHR_wrap,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif

  /* cl_khr_egl_image */
  &clCreateFromEGLImageKHR_wrap,
  &clEnqueueAcquireEGLObjectsKHR_wrap,
  &clEnqueueReleaseEGLObjectsKHR_wrap,

  /* cl_khr_egl_event */
  &clCreateEventFromEGLSyncKHR_wrap,

  /* OpenCL 2.0 */
  &clCreateCommandQueueWithProperties_wrap,
  &clCreatePipe_wrap,
  &clGetPipeInfo_wrap,
  &clSVMAlloc_wrap,
  &clSVMFree_wrap,
  &clEnqueueSVMFree_wrap,
  &clEnqueueSVMMemcpy_wrap,
  &clEnqueueSVMMemFill_wrap,
  &clEnqueueSVMMap_wrap,
  &clEnqueueSVMUnmap_wrap,
  &clCreateSamplerWithProperties_wrap,
  &clSetKernelArgSVMPointer_wrap,
  &clSetKernelExecInfo_wrap,

  /* cl_khr_sub_groups */
  &clGetKernelSubGroupInfoKHR_wrap,

  /* OpenCL 2.1 */
  &clCloneKernel_wrap,
  &clCreateProgramWithIL_wrap,
  &clEnqueueSVMMigrateMem_wrap,
  &clGetDeviceAndHostTimer_wrap,
  &clGetHostTimer_wrap,
  &clGetKernelSubGroupInfo_wrap,
  &clSetDefaultDeviceCommandQueue_wrap,

  /* OpenCL 2.2 */
  &clSetProgramReleaseCallback_wrap,
  &clSetProgramSpecializationConstant_wrap,

  /* OpenCL 3.0 */
  &clCreateBufferWithProperties_wrap,
  &clCreateImageWithProperties_wrap,
  &clSetContextDestructorCallback_wrap,
}
;
