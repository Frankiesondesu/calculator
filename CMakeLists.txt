cmake_minimum_required(VERSION 3.16)
project(DictpenCalculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add executable
add_executable(calculator
    src/main.cpp
)

# Link libraries
target_link_libraries(calculator PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Include directories from dictpen-libs if available
if(EXISTS "${CMAKE_SOURCE_DIR}/dictpen-libs/include")
    target_include_directories(calculator PRIVATE
        ${CMAKE_SOURCE_DIR}/dictpen-libs/include
    )
endif()

# Library directories from dictpen-libs if available  
if(EXISTS "${CMAKE_SOURCE_DIR}/dictpen-libs")
    link_directories(${CMAKE_SOURCE_DIR}/dictpen-libs)
endif()

# Set RPATH for dictpen
set_target_properties(calculator PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"
    BUILD_WITH_INSTALL_RPATH TRUE
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install rules
install(TARGETS calculator
    RUNTIME DESTINATION bin
)
