cmake_minimum_required(VERSION 3.12)
project(Gameboy)

set(CMAKE_CXX_STANDARD 14)


set(SFML_INCLUDE_DIR "/usr/local/include")
set(SFML_LIBRARY_DIR "/usr/local/lib/lib")


link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Gameboy main.cpp CPU.cpp CPU.h)
target_link_libraries (Gameboy sfml-graphics sfml-window sfml-system sfml-audio)