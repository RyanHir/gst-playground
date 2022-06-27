project(fakeplugin
    LANGUAGES C
    VERSION "0.0.1"
)

set(SOURCES
    gstplugin.c
    gstfakefilter.c
    gstfakevideofilter.c
)
configure_file(config.h.in config.h)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC
    gstreamer
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_compile_features(${PROJECT_NAME} PUBLIC
    c_std_11
)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR})
