cmake_minimum_required(VERSION 3.16...3.16)
project(gst-test C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED
    gstreamer-1.0>=1.14
)

set(PLUGIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/gstreamer-1.0/")

add_subdirectory(gst-plugin)
