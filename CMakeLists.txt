cmake_minimum_required(VERSION 3.16)
project(Calculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(calculator
    src/main.cpp
)

target_link_libraries(calculator PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Set output directory
set_target_properties(calculator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
