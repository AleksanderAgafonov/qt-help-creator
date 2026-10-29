cmake_minimum_required(VERSION 3.16)
project(qt-help-creator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.10 REQUIRED COMPONENTS Widgets Help)

# ---------------------------------------------------------------------------
# Sources
# ---------------------------------------------------------------------------

set(QT_HELP_CREATOR_SOURCES
    src/main.cpp
    src/ui/main_window/main_window.cpp
)

set(QT_HELP_CREATOR_HEADERS
    src/ui/main_window/main_window.h
)

set(QT_HELP_CREATOR_UI
    src/ui/main_window/main_window.ui
)

# ---------------------------------------------------------------------------
# Executable
# ---------------------------------------------------------------------------

qt_add_executable(qt-help-creator
    ${QT_HELP_CREATOR_SOURCES}
    ${QT_HELP_CREATOR_HEADERS}
    ${QT_HELP_CREATOR_UI}
)

target_include_directories(qt-help-creator PRIVATE src ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(qt-help-creator
    PRIVATE Qt6::Widgets Qt6::Help
)

set_target_properties(qt-help-creator PROPERTIES
    WIN32_EXECUTABLE ON
    OUTPUT_NAME "qt-help-creator"
)
