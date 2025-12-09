# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

set(LV_CONF_PATH "${CMAKE_SOURCE_DIR}/main/lv_conf.h")
add_compile_definitions(LV_CONF_PATH="${LV_CONF_PATH}")
add_compile_definitions(LVGL_VERSION_MAJOR=9)

add_compile_options(
   $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-enum-enum-conversion>
   $<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-function>
   $<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-variable>
   $<$<COMPILE_LANGUAGE:CXX>:-Wno-error>
   $<$<COMPILE_LANGUAGE:CXX>:-Wno-error=type-limits>
   $<$<COMPILE_LANGUAGE:C>:-Wno-unused-function>
   $<$<COMPILE_LANGUAGE:C>:-Wno-unused-variable>
   $<$<COMPILE_LANGUAGE:C>:-Wno-error>
   $<$<COMPILE_LANGUAGE:C>:-Wno-error=type-limits>
)

set(EXTRA_COMPONENT_DIRS mylibs)

# chestii generale ccache
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
   message(STATUS "Using ccache: ${CCACHE_PROGRAM}")
   set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
   set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

##################################################
# aici se încarcă magia IDF
include($ENV{IDF_PATH}/tools/cmake/project.cmake)



idf_build_get_property(minimal_build_var MINIMAL_BUILD)
message(STATUS "@@@@ X1 @@@ : The MINIMAL_BUILD is: ${minimal_build_var}")
idf_build_set_property(MINIMAL_BUILD ON)
idf_build_get_property(minimal_build_var1 MINIMAL_BUILD)
message(STATUS "@@@@ X2 @@@ : The MINIMAL_BUILD is: ${minimal_build_var1}")

idf_build_get_property(comp_opt1 COMPILE_OPTIONS)
message(STATUS "@@@@ 1 @@@ : The COMPILE_OPTIONS is: ${comp_opt1}")

idf_build_set_property(COMPILE_OPTIONS "-Wno-error" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=type-limits" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-function" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=unused-but-set-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=deprecated-declarations" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=extra" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-unused-parameter" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-sign-compare" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-enum-conversion" APPEND)

project(LILYGO-T-QT-PRO-S3-ESP-IDF C CXX ASM)

idf_build_get_property(comp_opt2 COMPILE_OPTIONS)
message(STATUS "@@@@ 2 @@@ : The COMPILE_OPTIONS is: ${comp_opt2}")





