# Copyright (c) 2020 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from collections import OrderedDict
from collections import namedtuple

import argparse
import sys
import urllib
import xml.etree.ElementTree as etree
import urllib.request

# parse_xml - Helper function to parse the XML file from a URL or local file.
def parse_xml(path):
    file = urllib.request.urlopen(path) if path.startswith("http") else open(path, 'r')
    with file:
        tree = etree.parse(file)
        return tree

# noneStr - returns string argument, or "" if argument is None.
def noneStr(s):
    if s:
        return s
    return ""

def parse_args():
    parser = argparse.ArgumentParser()

    # To pull the latest registry file from GitHub, pass:
    # -registry "https://raw.githubusercontent.com/KhronosGroup/OpenCL-Docs/main/xml/cl.xml"

    parser.add_argument('-registry', action='store',
                        default='cl.xml',
                        help='Use specified registry file instead of cl.xml')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')

    args = parser.parse_args()
    return args

def load_spec(args):
    specpath = args.registry

    print('Parsing XML file from: ' + specpath)
    spec = parse_xml(specpath)
    return spec

def get_apisigs(spec):
    # Generate the API function signatures dictionary:
    apisigs = OrderedDict()
    ApiSignature = namedtuple('ApiSignature', 'Name RetType Params Suffix')
    ApiParam = namedtuple('ApiParam', 'Type TypeEnd Name')
    print('Generating API signatures dictionary...')
    for command in spec.findall('commands/command'):
        suffix = noneStr(command.get('suffix'))
        proto = command.find('proto')
        ret = noneStr(proto.text)
        name = ""
        params = ""
        for elem in proto:
            if elem.tag == 'name':
                name = noneStr(elem.text) + noneStr(elem.tail)
            else:
                ret = ret + noneStr(elem.text) + noneStr(elem.tail)
        ret = ret.strip()
        name = name.strip()

        plist = []
        for param in command.findall('param'):
            ptype = noneStr(param.text)
            ptypeend = ""
            pname = ""
            for elem in param:
                if elem.tag == 'name':
                    pname = noneStr(elem.text)
                    ptypeend = noneStr(elem.tail)
                else:
                    ptype = ptype + noneStr(elem.text) + noneStr(elem.tail)
            ptype = ptype.strip()
            ptypeend = ptypeend.strip()
            pname = pname.strip()
            plist.append(ApiParam(ptype, ptypeend, pname))

        # For an empty parameter list (for e.g. clUnloadCompiler), add a single
        # unnamed void parameter to make generation easier.
        if len(plist) == 0:
            plist.append(ApiParam("void", "", ""))

        apisigs[name] = ApiSignature(name, ret, plist, suffix)
    return apisigs

def get_apis(spec, apisigs):
    # Generate the core API dictionary:
    coreapis = OrderedDict()
    print('Generating core API dictionary...')
    for feature in spec.findall('feature'):
        version = noneStr(feature.get('name'))

        alist = []
        for function in feature.findall('require/command'):
            name = function.get('name')
            alist.append(apisigs[name])
        coreapis[version] = alist

    # Generate the extensions API dictionary:
    extapis = OrderedDict()
    print('Generating API extensions dictionary...')
    for feature in spec.findall('extensions/extension'):
        extension = noneStr(feature.get('name'))

        alist = []
        for function in feature.findall('require/command'):
            name = function.get('name')
            alist.append(apisigs[name])
        extapis[extension] = alist
    return (coreapis, extapis)

# Dispatch table function order as well as grouping if it exists only on
# Windows
def get_dispatch_table_desc():
    return [
    (
        'OpenCL 1.0',
        [
            'clGetPlatformIDs',
            'clGetPlatformInfo',
            'clGetDeviceIDs',
            'clGetDeviceInfo',
            'clCreateContext',
            'clCreateContextFromType',
            'clRetainContext',
            'clReleaseContext',
            'clGetContextInfo',
            'clCreateCommandQueue',
            'clRetainCommandQueue',
            'clReleaseCommandQueue',
            'clGetCommandQueueInfo',
            'clSetCommandQueueProperty',
            'clCreateBuffer',
            'clCreateImage2D',
            'clCreateImage3D',
            'clRetainMemObject',
            'clReleaseMemObject',
            'clGetSupportedImageFormats',
            'clGetMemObjectInfo',
            'clGetImageInfo',
            'clCreateSampler',
            'clRetainSampler',
            'clReleaseSampler',
            'clGetSamplerInfo',
            'clCreateProgramWithSource',
            'clCreateProgramWithBinary',
            'clRetainProgram',
            'clReleaseProgram',
            'clBuildProgram',
            'clUnloadCompiler',
            'clGetProgramInfo',
            'clGetProgramBuildInfo',
            'clCreateKernel',
            'clCreateKernelsInProgram',
            'clRetainKernel',
            'clReleaseKernel',
            'clSetKernelArg',
            'clGetKernelInfo',
            'clGetKernelWorkGroupInfo',
            'clWaitForEvents',
            'clGetEventInfo',
            'clRetainEvent',
            'clReleaseEvent',
            'clGetEventProfilingInfo',
            'clFlush',
            'clFinish',
            'clEnqueueReadBuffer',
            'clEnqueueWriteBuffer',
            'clEnqueueCopyBuffer',
            'clEnqueueReadImage',
            'clEnqueueWriteImage',
            'clEnqueueCopyImage',
            'clEnqueueCopyImageToBuffer',
            'clEnqueueCopyBufferToImage',
            'clEnqueueMapBuffer',
            'clEnqueueMapImage',
            'clEnqueueUnmapMemObject',
            'clEnqueueNDRangeKernel',
            'clEnqueueTask',
            'clEnqueueNativeKernel',
            'clEnqueueMarker',
            'clEnqueueWaitForEvents',
            'clEnqueueBarrier',
            'clGetExtensionFunctionAddress',
            'clCreateFromGLBuffer',
            'clCreateFromGLTexture2D',
            'clCreateFromGLTexture3D',
            'clCreateFromGLRenderbuffer',
            'clGetGLObjectInfo',
            'clGetGLTextureInfo',
            'clEnqueueAcquireGLObjects',
            'clEnqueueReleaseGLObjects',
            'clGetGLContextInfoKHR',
        ],
        False
    ),
    (
        'cl_khr_d3d10_sharing',
        [
            'clGetDeviceIDsFromD3D10KHR',
            'clCreateFromD3D10BufferKHR',
            'clCreateFromD3D10Texture2DKHR',
            'clCreateFromD3D10Texture3DKHR',
            'clEnqueueAcquireD3D10ObjectsKHR',
            'clEnqueueReleaseD3D10ObjectsKHR',
        ],
        True
    ),
    (
        'OpenCL 1.1',
        [
            'clSetEventCallback',
            'clCreateSubBuffer',
            'clSetMemObjectDestructorCallback',
            'clCreateUserEvent',
            'clSetUserEventStatus',
            'clEnqueueReadBufferRect',
            'clEnqueueWriteBufferRect',
            'clEnqueueCopyBufferRect',
        ],
        False
    ),
    (
        'cl_ext_device_fission',
        [
            'clCreateSubDevicesEXT',
            'clRetainDeviceEXT',
            'clReleaseDeviceEXT',
        ],
        False
    ),
    (
        'cl_khr_gl_event',
        [
            'clCreateEventFromGLsyncKHR',
        ],
        False
    ),
    (
        'OpenCL 1.2',
        [
            'clCreateSubDevices',
            'clRetainDevice',
            'clReleaseDevice',
            'clCreateImage',
            'clCreateProgramWithBuiltInKernels',
            'clCompileProgram',
            'clLinkProgram',
            'clUnloadPlatformCompiler',
            'clGetKernelArgInfo',
            'clEnqueueFillBuffer',
            'clEnqueueFillImage',
            'clEnqueueMigrateMemObjects',
            'clEnqueueMarkerWithWaitList',
            'clEnqueueBarrierWithWaitList',
            'clGetExtensionFunctionAddressForPlatform',
            'clCreateFromGLTexture',
        ],
        False
    ),
    (
        'cl_khr_d3d11_sharing',
        [
            'clGetDeviceIDsFromD3D11KHR',
            'clCreateFromD3D11BufferKHR',
            'clCreateFromD3D11Texture2DKHR',
            'clCreateFromD3D11Texture3DKHR',
            'clCreateFromDX9MediaSurfaceKHR',
            'clEnqueueAcquireD3D11ObjectsKHR',
            'clEnqueueReleaseD3D11ObjectsKHR',
        ],
        True
    ),
    (
        'cl_khr_dx9_media_sharing',
        [
            'clGetDeviceIDsFromDX9MediaAdapterKHR',
            'clEnqueueAcquireDX9MediaSurfacesKHR',
            'clEnqueueReleaseDX9MediaSurfacesKHR',
        ],
        True
    ),
    (
        'cl_khr_egl_image',
        [
            'clCreateFromEGLImageKHR',
            'clEnqueueAcquireEGLObjectsKHR',
            'clEnqueueReleaseEGLObjectsKHR',
        ],
        False
    ),
    (
        'cl_khr_egl_event',
        [
            'clCreateEventFromEGLSyncKHR',
        ],
        False
    ),
    (
        'OpenCL 2.0',
        [
            'clCreateCommandQueueWithProperties',
            'clCreatePipe',
            'clGetPipeInfo',
            'clSVMAlloc',
            'clSVMFree',
            'clEnqueueSVMFree',
            'clEnqueueSVMMemcpy',
            'clEnqueueSVMMemFill',
            'clEnqueueSVMMap',
            'clEnqueueSVMUnmap',
            'clCreateSamplerWithProperties',
            'clSetKernelArgSVMPointer',
            'clSetKernelExecInfo',
        ],
        False
    ),
    (
        'cl_khr_sub_groups',
        [
            'clGetKernelSubGroupInfoKHR',
        ],
        False
    ),
    (
        'OpenCL 2.1',
        [
            'clCloneKernel',
            'clCreateProgramWithIL',
            'clEnqueueSVMMigrateMem',
            'clGetDeviceAndHostTimer',
            'clGetHostTimer',
            'clGetKernelSubGroupInfo',
            'clSetDefaultDeviceCommandQueue',
        ],
        False
    ),
    (
        'OpenCL 2.2',
        [
            'clSetProgramReleaseCallback',
            'clSetProgramSpecializationConstant',
        ],
        False
    ),
    (
        'OpenCL 3.0',
        [
            'clCreateBufferWithProperties',
            'clCreateImageWithProperties',
            'clSetContextDestructorCallback',
        ],
        False
    ),
    ]
