<%
from mako.template import Template
apiskip = {
    'clGetPlatformIDs',
    'clUnloadCompiler',
    'clGetExtensionFunctionAddress',
    }

instance_table_template = Template(filename='instance_dispatch_table.mako')
%>/*
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
#if defined(CL_NO_EXTENSION_PROTOTYPES) && \
    !defined(CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif
#if defined(CL_NO_EXTENSION_PROTOTYPES) && \
    !defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
* cl_loader_instance_layers
***************************************************************/
#define cl_loader_instance_layers 1
#define CL_LOADER_INSTANCE_LAYERS_EXTENSION_NAME \
    "cl_loader_instance_layers"

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
%for apis in coreapis.values():
%for api in apis:
%if not api.Name in apiskip:
typedef ${api.RetType} CL_API_CALL ${api.Name + "_instance_t"}(
    const cl_icd_instance_layer *layer,
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
    ${param.Type} ${param.Name}${param.TypeEnd},
%  else:
    ${param.Type} ${param.Name}${param.TypeEnd});
%  endif
%endfor

///////////////////////////////////////////////////////////////////////////////
%endif
%endfor
%endfor
<%
icdextensions = [
    'cl_ext_device_fission',
    'cl_khr_d3d10_sharing',
    'cl_khr_d3d11_sharing',
    'cl_khr_dx9_media_sharing',
    'cl_khr_egl_event',
    'cl_khr_egl_image',
    'cl_khr_gl_event',
    'cl_khr_gl_sharing',
    'cl_khr_subgroups'
    ]
win32extensions = {
    'cl_khr_d3d10_sharing',
    'cl_khr_d3d11_sharing',
    'cl_khr_dx9_media_sharing',
    }
%>
%for extension in icdextensions:
<%
    apis = extapis[extension]
%>// ${extension}
%if extension in win32extensions:

#if defined(_WIN32)
%endif
%for api in apis:
typedef ${api.RetType} CL_API_CALL ${api.Name + "_instance_t"}(
    const cl_icd_instance_layer *layer,
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
    ${param.Type} ${param.Name}${param.TypeEnd},
%  else:
    ${param.Type} ${param.Name}${param.TypeEnd});
%  endif
%endfor

%endfor

%if extension in win32extensions:
#endif // defined(_WIN32)

%endif
///////////////////////////////////////////////////////////////////////////////

%endfor

struct _cl_icd_instance_dispatch ${instance_table_template.render(suffix = 'instance_t', type = True, type_name = None, guards = True)};

struct _cl_icd_layer_dispatch ${instance_table_template.render(suffix = None, type = True, type_name = 'cl_icd_instance_layer', guards = False)};

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
