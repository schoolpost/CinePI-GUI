cmake_minimum_required(VERSION 3.12.4)

project(ui)

FILE(GLOB MyCSources *.c)

add_library(ui ${MyCSources})
install(TARGETS ui LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})