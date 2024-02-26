<%
    def type_entry(t_name, name):
        return t_name + ' *' + name

    def entry(name):
        if type:
            if type_name is not None:
                return type_entry(type_name, name) + ';'
            else:
                return type_entry(name + '_' + suffix, name) + ';'
        else:
            if value is UNDEFINED or value is None:
                return '&' + name + '_' + suffix + ','
            else:
                return '&' + value + ','

    def void_entry(name):
        if type:
            return type_entry('void', name) + ';'
        else:
            return 'NULL,'
%>{
  ${entry('clGetPlatformIDsForInstanceKHR')}
  /* OpenCL 1.0 */
  ${entry('clGetPlatformInfo')}
  ${entry('clGetDeviceIDs')}
  ${entry('clGetDeviceInfo')}
  ${entry('clCreateContext')}
  ${entry('clCreateContextFromType')}
  ${entry('clRetainContext')}
  ${entry('clReleaseContext')}
  ${entry('clGetContextInfo')}
  ${entry('clCreateCommandQueue')}
  ${entry('clRetainCommandQueue')}
  ${entry('clReleaseCommandQueue')}
  ${entry('clGetCommandQueueInfo')}
  ${entry('clSetCommandQueueProperty')}
  ${entry('clCreateBuffer')}
  ${entry('clCreateImage2D')}
  ${entry('clCreateImage3D')}
  ${entry('clRetainMemObject')}
  ${entry('clReleaseMemObject')}
  ${entry('clGetSupportedImageFormats')}
  ${entry('clGetMemObjectInfo')}
  ${entry('clGetImageInfo')}
  ${entry('clCreateSampler')}
  ${entry('clRetainSampler')}
  ${entry('clReleaseSampler')}
  ${entry('clGetSamplerInfo')}
  ${entry('clCreateProgramWithSource')}
  ${entry('clCreateProgramWithBinary')}
  ${entry('clRetainProgram')}
  ${entry('clReleaseProgram')}
  ${entry('clBuildProgram')}
  ${entry('clGetProgramInfo')}
  ${entry('clGetProgramBuildInfo')}
  ${entry('clCreateKernel')}
  ${entry('clCreateKernelsInProgram')}
  ${entry('clRetainKernel')}
  ${entry('clReleaseKernel')}
  ${entry('clSetKernelArg')}
  ${entry('clGetKernelInfo')}
  ${entry('clGetKernelWorkGroupInfo')}
  ${entry('clWaitForEvents')}
  ${entry('clGetEventInfo')}
  ${entry('clRetainEvent')}
  ${entry('clReleaseEvent')}
  ${entry('clGetEventProfilingInfo')}
  ${entry('clFlush')}
  ${entry('clFinish')}
  ${entry('clEnqueueReadBuffer')}
  ${entry('clEnqueueWriteBuffer')}
  ${entry('clEnqueueCopyBuffer')}
  ${entry('clEnqueueReadImage')}
  ${entry('clEnqueueWriteImage')}
  ${entry('clEnqueueCopyImage')}
  ${entry('clEnqueueCopyImageToBuffer')}
  ${entry('clEnqueueCopyBufferToImage')}
  ${entry('clEnqueueMapBuffer')}
  ${entry('clEnqueueMapImage')}
  ${entry('clEnqueueUnmapMemObject')}
  ${entry('clEnqueueNDRangeKernel')}
  ${entry('clEnqueueTask')}
  ${entry('clEnqueueNativeKernel')}
  ${entry('clEnqueueMarker')}
  ${entry('clEnqueueWaitForEvents')}
  ${entry('clEnqueueBarrier')}
  ${entry('clCreateFromGLBuffer')}
  ${entry('clCreateFromGLTexture2D')}
  ${entry('clCreateFromGLTexture3D')}
  ${entry('clCreateFromGLRenderbuffer')}
  ${entry('clGetGLObjectInfo')}
  ${entry('clGetGLTextureInfo')}
  ${entry('clEnqueueAcquireGLObjects')}
  ${entry('clEnqueueReleaseGLObjects')}
  ${entry('clGetGLContextInfoKHR')}

  /* cl_khr_d3d10_sharing */
#ifdef _WIN32
  ${entry('clGetDeviceIDsFromD3D10KHR')}
  ${entry('clCreateFromD3D10BufferKHR')}
  ${entry('clCreateFromD3D10Texture2DKHR')}
  ${entry('clCreateFromD3D10Texture3DKHR')}
  ${entry('clEnqueueAcquireD3D10ObjectsKHR')}
  ${entry('clEnqueueReleaseD3D10ObjectsKHR')}
#else
  ${void_entry('clGetDeviceIDsFromD3D10KHR')}
  ${void_entry('clCreateFromD3D10BufferKHR')}
  ${void_entry('clCreateFromD3D10Texture2DKHR')}
  ${void_entry('clCreateFromD3D10Texture3DKHR')}
  ${void_entry('clEnqueueAcquireD3D10ObjectsKHR')}
  ${void_entry('clEnqueueReleaseD3D10ObjectsKHR')}
#endif

  /* OpenCL 1.1 */
%if guards:
#ifdef CL_VERSION_1_1
%endif
  ${entry('clSetEventCallback')}
  ${entry('clCreateSubBuffer')}
  ${entry('clSetMemObjectDestructorCallback')}
  ${entry('clCreateUserEvent')}
  ${entry('clSetUserEventStatus')}
  ${entry('clEnqueueReadBufferRect')}
  ${entry('clEnqueueWriteBufferRect')}
  ${entry('clEnqueueCopyBufferRect')}
%if guards:
#else
  ${void_entry('clSetEventCallback')}
  ${void_entry('clCreateSubBuffer')}
  ${void_entry('clSetMemObjectDestructorCallback')}
  ${void_entry('clCreateUserEvent')}
  ${void_entry('clSetUserEventStatus')}
  ${void_entry('clEnqueueReadBufferRect')}
  ${void_entry('clEnqueueWriteBufferRect')}
  ${void_entry('clEnqueueCopyBufferRect')}
#endif
%endif

  /* cl_ext_device_fission */
  ${entry('clCreateSubDevicesEXT')}
  ${entry('clRetainDeviceEXT')}
  ${entry('clReleaseDeviceEXT')}

  /* cl_khr_gl_event */
  ${entry('clCreateEventFromGLsyncKHR')}

  /* OpenCL 1.2 */
%if guards:
#ifdef CL_VERSION_1_2
%endif
  ${entry('clCreateSubDevices')}
  ${entry('clRetainDevice')}
  ${entry('clReleaseDevice')}
  ${entry('clCreateImage')}
  ${entry('clCreateProgramWithBuiltInKernels')}
  ${entry('clCompileProgram')}
  ${entry('clLinkProgram')}
  ${entry('clUnloadPlatformCompiler')}
  ${entry('clGetKernelArgInfo')}
  ${entry('clEnqueueFillBuffer')}
  ${entry('clEnqueueFillImage')}
  ${entry('clEnqueueMigrateMemObjects')}
  ${entry('clEnqueueMarkerWithWaitList')}
  ${entry('clEnqueueBarrierWithWaitList')}
  ${entry('clGetExtensionFunctionAddressForPlatform')}
  ${entry('clCreateFromGLTexture')}
%if guards:
#else
  ${void_entry('clCreateSubDevices')}
  ${void_entry('clRetainDevice')}
  ${void_entry('clReleaseDevice')}
  ${void_entry('clCreateImage')}
  ${void_entry('clCreateProgramWithBuiltInKernels')}
  ${void_entry('clCompileProgram')}
  ${void_entry('clLinkProgram')}
  ${void_entry('clUnloadPlatformCompiler')}
  ${void_entry('clGetKernelArgInfo')}
  ${void_entry('clEnqueueFillBuffer')}
  ${void_entry('clEnqueueFillImage')}
  ${void_entry('clEnqueueMigrateMemObjects')}
  ${void_entry('clEnqueueMarkerWithWaitList')}
  ${void_entry('clEnqueueBarrierWithWaitList')}
  ${void_entry('clGetExtensionFunctionAddressForPlatform')}
  ${void_entry('clCreateFromGLTexture')}
#endif
%endif

  /* cl_khr_d3d11_sharing and cl_khr_dx9_media_sharing */
#ifdef _WIN32
  ${entry('clGetDeviceIDsFromD3D11KHR')}
  ${entry('clCreateFromD3D11BufferKHR')}
  ${entry('clCreateFromD3D11Texture2DKHR')}
  ${entry('clCreateFromD3D11Texture3DKHR')}
  ${entry('clCreateFromDX9MediaSurfaceKHR')}
  ${entry('clEnqueueAcquireD3D11ObjectsKHR')}
  ${entry('clEnqueueReleaseD3D11ObjectsKHR')}
  ${entry('clGetDeviceIDsFromDX9MediaAdapterKHR')}
  ${entry('clEnqueueAcquireDX9MediaSurfacesKHR')}
  ${entry('clEnqueueReleaseDX9MediaSurfacesKHR')}
#else
  ${void_entry('clGetDeviceIDsFromD3D11KHR')}
  ${void_entry('clCreateFromD3D11BufferKHR')}
  ${void_entry('clCreateFromD3D11Texture2DKHR')}
  ${void_entry('clCreateFromD3D11Texture3DKHR')}
  ${void_entry('clCreateFromDX9MediaSurfaceKHR')}
  ${void_entry('clEnqueueAcquireD3D11ObjectsKHR')}
  ${void_entry('clEnqueueReleaseD3D11ObjectsKHR')}
  ${void_entry('clGetDeviceIDsFromDX9MediaAdapterKHR')}
  ${void_entry('clEnqueueAcquireDX9MediaSurfacesKHR')}
  ${void_entry('clEnqueueReleaseDX9MediaSurfacesKHR')}
#endif

  /* cl_khr_egl_image */
  ${entry('clCreateFromEGLImageKHR')}
  ${entry('clEnqueueAcquireEGLObjectsKHR')}
  ${entry('clEnqueueReleaseEGLObjectsKHR')}

  /* cl_khr_egl_event */
  ${entry('clCreateEventFromEGLSyncKHR')}

  /* OpenCL 2.0 */
%if guards:
#ifdef CL_VERSION_2_0
%endif
  ${entry('clCreateCommandQueueWithProperties')}
  ${entry('clCreatePipe')}
  ${entry('clGetPipeInfo')}
  ${entry('clSVMAlloc')}
  ${entry('clSVMFree')}
  ${entry('clEnqueueSVMFree')}
  ${entry('clEnqueueSVMMemcpy')}
  ${entry('clEnqueueSVMMemFill')}
  ${entry('clEnqueueSVMMap')}
  ${entry('clEnqueueSVMUnmap')}
  ${entry('clCreateSamplerWithProperties')}
  ${entry('clSetKernelArgSVMPointer')}
  ${entry('clSetKernelExecInfo')}
%if guards:
#else
  ${void_entry('clCreateCommandQueueWithProperties')}
  ${void_entry('clCreatePipe')}
  ${void_entry('clGetPipeInfo')}
  ${void_entry('clSVMAlloc')}
  ${void_entry('clSVMFree')}
  ${void_entry('clEnqueueSVMFree')}
  ${void_entry('clEnqueueSVMMemcpy')}
  ${void_entry('clEnqueueSVMMemFill')}
  ${void_entry('clEnqueueSVMMap')}
  ${void_entry('clEnqueueSVMUnmap')}
  ${void_entry('clCreateSamplerWithProperties')}
  ${void_entry('clSetKernelArgSVMPointer')}
  ${void_entry('clSetKernelExecInfo')}
#endif
%endif

  /* cl_khr_sub_groups */
  ${entry('clGetKernelSubGroupInfoKHR')}

  /* OpenCL 2.1 */
%if guards:
#ifdef CL_VERSION_2_1
%endif
  ${entry('clCloneKernel')}
  ${entry('clCreateProgramWithIL')}
  ${entry('clEnqueueSVMMigrateMem')}
  ${entry('clGetDeviceAndHostTimer')}
  ${entry('clGetHostTimer')}
  ${entry('clGetKernelSubGroupInfo')}
  ${entry('clSetDefaultDeviceCommandQueue')}
%if guards:
#else
  ${void_entry('clCloneKernel')}
  ${void_entry('clCreateProgramWithIL')}
  ${void_entry('clEnqueueSVMMigrateMem')}
  ${void_entry('clGetDeviceAndHostTimer')}
  ${void_entry('clGetHostTimer')}
  ${void_entry('clGetKernelSubGroupInfo')}
  ${void_entry('clSetDefaultDeviceCommandQueue')}
#endif
%endif

  /* OpenCL 2.2 */
%if guards:
#ifdef CL_VERSION_2_2
%endif
  ${entry('clSetProgramReleaseCallback')}
  ${entry('clSetProgramSpecializationConstant')}
%if guards:
#else
  ${void_entry('clSetProgramReleaseCallback')}
  ${void_entry('clSetProgramSpecializationConstant')}
#endif
%endif

  /* OpenCL 3.0 */
%if guards:
#ifdef CL_VERSION_3_0
%endif
  ${entry('clCreateBufferWithProperties')}
  ${entry('clCreateImageWithProperties')}
  ${entry('clSetContextDestructorCallback')}
%if guards:
#else
  ${void_entry('clCreateBufferWithProperties')}
  ${void_entry('clCreateImageWithProperties')}
  ${void_entry('clSetContextDestructorCallback')}
#endif
%endif
}
