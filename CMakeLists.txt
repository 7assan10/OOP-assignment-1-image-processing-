cmake_minimum_required(VERSION 3.21)

project(ImageProcessingGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ImageProcessingGUI
    gui.cpp
)

target_link_libraries(ImageProcessingGUI PRIVATE Qt6::Widgets)

target_include_directories(ImageProcessingGUI PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
