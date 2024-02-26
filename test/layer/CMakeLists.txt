set (OPENCL_PRINT_LAYER_SOURCES
    icd_print_layer.c
    icd_print_layer.h
    icd_print_layer_generated.c)

if (WIN32)
    list (APPEND OPENCL_PRINT_LAYER_SOURCES icd_print_layer.def)
else ()
    if (NOT APPLE)
        list (APPEND OPENCL_PRINT_LAYER_SOURCES icd_print_layer.map)
    endif ()
endif ()

add_library (PrintLayer SHARED ${OPENCL_PRINT_LAYER_SOURCES})

target_include_directories(PrintLayer PRIVATE ${PARENT_DIR}/include)
target_link_libraries(PrintLayer PUBLIC OpenCL::Headers)
target_compile_definitions (PrintLayer PRIVATE CL_TARGET_OPENCL_VERSION=300)

if (NOT WIN32 AND NOT APPLE)
  set_target_properties (PrintLayer PROPERTIES LINK_FLAGS "-Wl,--version-script -Wl,${CMAKE_CURRENT_SOURCE_DIR}/icd_print_layer.map")
endif ()

set (OPENCL_INSTANCE_PRINT_LAYER_SOURCES
    ${CMAKE_SOURCE_DIR}/include/cl_khr_icd2.h
    ${CMAKE_SOURCE_DIR}/include/cl_instance_layer.h
    icd_instance_print_layer.c
    icd_instance_print_layer.h
    icd_instance_print_layer_generated.c)

if (WIN32)
    list (APPEND OPENCL_INSTANCE_PRINT_LAYER_SOURCES icd_instance_print_layer.def)
else ()
    if (NOT APPLE)
        list (APPEND OPENCL_INSTANCE_PRINT_LAYER_SOURCES icd_instance_print_layer.map)
    endif ()
endif ()

add_library (InstancePrintLayer SHARED ${OPENCL_INSTANCE_PRINT_LAYER_SOURCES})

target_include_directories(InstancePrintLayer PRIVATE ${PARENT_DIR}/include)
target_link_libraries(InstancePrintLayer PUBLIC OpenCL::Headers)
target_compile_definitions (InstancePrintLayer PRIVATE CL_TARGET_OPENCL_VERSION=300)

if (NOT WIN32 AND NOT APPLE)
  set_target_properties (InstancePrintLayer PROPERTIES LINK_FLAGS "-Wl,--version-script -Wl,${CMAKE_CURRENT_SOURCE_DIR}/icd_instance_print_layer.map")
endif ()
