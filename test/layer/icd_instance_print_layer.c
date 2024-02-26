/*
 * Copyright (c) 2020 The Khronos Group Inc.
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
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static cl_instance_layer_api_version api_version = CL_INSTANCE_LAYER_API_VERSION_100;
static const char name[] = "print_layer";
static int layer_counter = 0;

static inline cl_int
set_param_value(
    size_t      param_value_size,
    void       *param_value,
    size_t     *param_value_size_ret,
    size_t      src_size,
    const void *src) {
  if (param_value && param_value_size < src_size)
    return CL_INVALID_VALUE;
  if (param_value)
    memcpy(param_value, src, src_size);
  if (param_value_size_ret)
    *param_value_size_ret = src_size;
  return CL_SUCCESS;
}

CL_API_ENTRY cl_int CL_API_CALL
clGetInstanceLayerInfo(
    cl_instance_layer_info  param_name,
    size_t                  param_value_size,
    void                   *param_value,
    size_t                 *param_value_size_ret) {
  size_t sz = 0;
  const void *src = NULL;
  if (param_value_size && !param_value)
    return CL_INVALID_VALUE;
  if (!param_value && !param_value_size_ret)
    return CL_INVALID_VALUE;
  switch (param_name) {
  case CL_INSTANCE_LAYER_API_VERSION:
    sz = sizeof(api_version);
    src = &api_version;
    break;
  case CL_INSTANCE_LAYER_NAME:
    sz = sizeof(name);
    src = name;
    break;
  default:
    return CL_INVALID_VALUE;
  }
  return set_param_value(param_value_size, param_value, param_value_size_ret, sz, src);
}

CL_API_ENTRY cl_int CL_API_CALL
clInitInstanceLayer(
    cl_uint                                  num_entries,
    const cl_icd_instance_layer             *layer,
    cl_uint                                 *num_entries_out,
    const struct _cl_icd_instance_dispatch **layer_dispatch_ret,
    void                                   **data_ret)
{
  if (!layer || !layer_dispatch_ret || !num_entries_out || !data_ret || num_entries < sizeof(dispatch)/sizeof(dispatch.clGetPlatformIDsForInstanceKHR))
    return CL_INVALID_VALUE;

  int *data = malloc(sizeof(int));
  if (!data)
    return CL_OUT_OF_HOST_MEMORY;

  *data = layer_counter++;
  *data_ret = (void*)data;

  *layer_dispatch_ret = &dispatch;
  *num_entries_out = sizeof(dispatch)/sizeof(dispatch.clGetPlatformIDsForInstanceKHR);

  return CL_SUCCESS;
}

CL_API_ENTRY cl_int CL_API_CALL
clDeinitInstanceLayer(
    const cl_icd_instance_layer *layer,
    void                        *data
)
{
  (void)layer;
  free(data);
  return CL_SUCCESS;
}
