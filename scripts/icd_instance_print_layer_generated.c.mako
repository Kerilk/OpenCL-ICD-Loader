<%
from mako.template import Template

apiskip = {
    'clGetPlatformIDs',
    'clUnloadCompiler',
    'clGetExtensionFunctionAddress',
}

table_template = Template(filename='instance_dispatch_table.mako')
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
%for apis in coreapis.values():
%for api in apis:
%if not api.Name in apiskip:
static ${api.RetType} CL_API_CALL ${api.Name + "_wrap"}(
    const cl_icd_instance_layer *layer,
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
    ${param.Type} ${param.Name}${param.TypeEnd},
%  else:
    ${param.Type} ${param.Name}${param.TypeEnd})
%  endif
%endfor
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: ${api.Name}\n", *(int*)data);
%  if api.Name == "clSVMFree":
    CL_INSTANCE_LAYER_NEXT_ENTRY(layer, ${api.Name})(
%  else:
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, ${api.Name})(
%  endif
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, ${api.Name}),
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
        ${param.Name},
%  else:
        ${param.Name});
%  endif
%endfor
}

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
static ${api.RetType} CL_API_CALL ${api.Name + "_wrap"}(
    const cl_icd_instance_layer *layer,
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
    ${param.Type} ${param.Name}${param.TypeEnd},
%  else:
    ${param.Type} ${param.Name}${param.TypeEnd})
%  endif
%endfor
{
    void *data = CL_INSTANCE_LAYER_DATA(layer);
    printf("%d: ${api.Name}\n", *(int*)data);
    return CL_INSTANCE_LAYER_NEXT_ENTRY(layer, ${api.Name})(
        CL_INSTANCE_LAYER_NEXT_LAYER(layer, ${api.Name}),
%for i, param in enumerate(api.Params):
%  if i < len(api.Params)-1:
        ${param.Name},
%  else:
        ${param.Name});
%  endif
%endfor
}
%endfor

%if extension in win32extensions:
#endif // defined(_WIN32)

%endif
///////////////////////////////////////////////////////////////////////////////

%endfor
struct _cl_icd_instance_dispatch dispatch = ${table_template.render(suffix = 'wrap', type = False, type_name = None, guards = False)};
