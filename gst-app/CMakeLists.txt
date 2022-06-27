project(gsttestapp
    LANGUAGES C
    VERSION "0.0.1"
)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC
    gstreamer
)
