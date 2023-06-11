cmake_minimum_required(VERSION 3.1)

project(lvgl_fb)

include_directories(.)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(ui)

set(CMAKE_C_FLAGS -pthread)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::drivers ui i2c hiredis)
