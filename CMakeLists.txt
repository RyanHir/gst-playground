cmake_minimum_required(VERSION 3.10...3.10)
project(gst-test C)

set(GST_MIN_VERSION 1.14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED
    gstreamer-1.0>=${GST_MIN_VERSION}
    gstreamer-base-1.0>=${GST_MIN_VERSION}
)

add_library(gstreamer INTERFACE)

target_link_libraries(gstreamer INTERFACE
    ${GSTREAMER_LIBRARIES}
)
target_include_directories(gstreamer INTERFACE
    ${GSTREAMER_INCLUDE_DIRS}
)

set(PLUGIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/gstreamer-1.0/")

add_subdirectory(gst-app)
add_subdirectory(gst-plugin)
