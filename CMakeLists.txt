cmake_minimum_required(VERSION 3.16)
project(qt-help-creator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.10 REQUIRED COMPONENTS Widgets Help)

# qt_standard_project_setup  # removed — not available in static Qt 6.10.2

qt_add_executable(qt-help-creator
    src/main.cpp
    src/ui/main_window/main_window.cpp
    src/ui/main_window/main_window.h
    src/ui/main_window/main_window.ui
)

target_include_directories(qt-help-creator PRIVATE src ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(qt-help-creator
    PRIVATE Qt6::Widgets Qt6::Help
)

set_target_properties(qt-help-creator PROPERTIES
    WIN32_EXECUTABLE ON
    OUTPUT_NAME "qt-help-creator"
)
