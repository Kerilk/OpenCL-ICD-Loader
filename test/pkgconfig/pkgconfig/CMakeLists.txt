cmake_minimum_required(VERSION 3.1)
find_package(PkgConfig REQUIRED)

project(PkgConfigTest
  LANGUAGES C
)

pkg_check_modules(OPENCL REQUIRED OpenCL)

# NOTE: Only CMake 3.12 introduces <XPREFIX>_LINK_LIBRARIES, which holds
#       the full path to the libraries. Previous versions require setting
#       -L or /L flags to find them. The folder without the flag is stored
#       in <XPREFIX>_LIBRARY_DIRS, but setting that on a per-target basis
#       (without setting linker flags manually) can only be done using
#       target_link_directories from 3.13, at which point we might as well
#       use <XPREFIX>_LINK_LIBRARIES.
#
#       Supporting CMake versions older than 3.12 and polluting directory-wide
#       linker search settings is perhaps best done using a genexpr.
if(CMAKE_VERSION VERSION_LESS 3.12)
  link_directories("${OPENCL_LIBRARY_DIRS}")
endif()

add_executable(${PROJECT_NAME}
  ../pkgconfig.c
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    "${OPENCL_INCLUDE_DIRS}"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    $<$<VERSION_LESS:${CMAKE_VERSION},3.12>:"${OPENCL_LIBRARIES}">
    $<$<NOT:$<VERSION_LESS:${CMAKE_VERSION},3.12>>:"${OPENCL_LINK_LIBRARIES}">
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CL_TARGET_OPENCL_VERSION=120
)

include(CTest)

add_test(
  NAME ${PROJECT_NAME}
  COMMAND ${PROJECT_NAME}
)

set_tests_properties(${PROJECT_NAME}
  PROPERTIES
    ENVIRONMENT "OCL_ICD_FILENAMES=${DRIVER_STUB_PATH}"
)
