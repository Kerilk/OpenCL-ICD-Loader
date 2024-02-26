/*
 * Copyright (c) 2016-2026 The Khronos Group Inc.
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

#include <CL/cl.h>

#if !defined(CL_PLATFORM_UNLOADABLE_KHR)
#define CL_PLATFORM_UNLOADABLE_KHR 0x0921
#endif

#if defined(CL_ENABLE_LAYERS) && !defined(CL_LAYER_PROPERTIES_LIST_END)
typedef cl_properties cl_layer_properties;

#define CL_LAYER_PROPERTIES_LIST_END         ((cl_layer_properties)0)

typedef cl_int CL_API_CALL
clInitLayerWithProperties_t(
    cl_uint num_entries,
    const cl_icd_dispatch *target_dispatch,
    cl_uint *num_entries_ret,
    const cl_icd_dispatch **layer_dispatch_ret,
    const cl_layer_properties *properties);

typedef clInitLayerWithProperties_t *pfn_clInitLayerWithProperties;

typedef cl_int CL_API_CALL
clDeinitLayer_t(void);

typedef clDeinitLayer_t *pfn_clDeinitLayer;
#endif //defined(CL_ENABLE_LAYERS) && !defined(CL_LAYER_PROPERTIES_LIST_END)

#if !defined(CL_ICD2_TAG_KHR)
#if INTPTR_MAX == INT32_MAX
#define CL_ICD2_TAG_KHR ((intptr_t)0x434C3331)
#else
#define CL_ICD2_TAG_KHR ((intptr_t)0x4F50454E434C3331)
#endif

typedef void * CL_API_CALL
clIcdGetFunctionAddressForPlatformKHR_t(
    cl_platform_id platform,
    const char* func_name);

typedef clIcdGetFunctionAddressForPlatformKHR_t *
clIcdGetFunctionAddressForPlatformKHR_fn;

typedef cl_int CL_API_CALL
clIcdSetPlatformDispatchDataKHR_t(
    cl_platform_id platform,
    void *disp_data);

typedef clIcdSetPlatformDispatchDataKHR_t *
clIcdSetPlatformDispatchDataKHR_fn;
#endif // !defined(CL_ICD2_TAG_KHR)

#if !defined(CL_INSTANCE_PLATFORM_PROPERTIES_LIST_END_KHR)
#define CL_INSTANCE_PLATFORM_PROPERTIES_LIST_END_KHR ((cl_instance_platform_properties_khr)0)

typedef cl_properties cl_instance_platform_properties_khr;

typedef cl_platform_id CL_API_CALL
clIcdCreateInstancePlatformKHR_t(
    cl_platform_id platform,
    const cl_instance_platform_properties_khr *properties,
    cl_int *errcode_ret);

typedef clIcdCreateInstancePlatformKHR_t *
clIcdCreateInstancePlatformKHR_fn;

typedef cl_int CL_API_CALL
clIcdDestroyInstancePlatformKHR_t(
    cl_platform_id platform);

typedef clIcdDestroyInstancePlatformKHR_t *
clIcdDestroyInstancePlatformKHR_fn;
#endif //!defined(CL_INSTANCE_PLATFORM_PROPERTIES_LIST_END_KHR)

#if !defined(CL_INVALID_INSTANCE_KHR)
#define CL_INVALID_INSTANCE_KHR                         -1154
#define CL_INVALID_INSTANCE_LAYER_KHR                   -1155

#define CL_INSTANCE_PROPERTIES_LAYERS_KHR              0x4250
#define CL_INSTANCE_PROPERTIES_LAYERS_LIST_END_KHR          0
#define CL_INSTANCE_PROPERTIES_LIST_END_KHR ((cl_instance_properties_khr)0)

typedef struct _cl_instance_khr *cl_instance_khr;
typedef cl_properties cl_instance_properties_khr;

typedef cl_instance_khr CL_API_CALL
clCreateInstanceKHR_t(
    const cl_instance_properties_khr *properties,
    cl_int *errcode_ret);

typedef clCreateInstanceKHR_t *
clCreateInstanceKHR_fn;

typedef cl_int CL_API_CALL
clDestroyInstanceKHR_t(
    cl_instance_khr instance);

typedef clDestroyInstanceKHR_t *
clDestroyInstanceKHR_fn;

typedef cl_int CL_API_CALL
clGetPlatformIDsForInstanceKHR_t(
    cl_instance_khr instance,
    cl_uint num_entries,
    cl_platform_id *platforms,
    cl_uint *num_platforms);

typedef clGetPlatformIDsForInstanceKHR_t *
clGetPlatformIDsForInstanceKHR_fn;

#endif // !defined(CL_INVALID_INSTANCE_KHR)
