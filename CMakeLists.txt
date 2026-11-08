cmake_minimum_required(VERSION 3.16)

project(qt-help-creator VERSION 0.0.1 LANGUAGES CXX)

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
    resources/resources.qrc
)

target_include_directories(qt-help-creator PRIVATE src ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(qt-help-creator
    PRIVATE
        Qt6::Widgets
        Qt6::Help
        Qt6::QWindowsIntegrationPlugin
)

set_target_properties(qt-help-creator PROPERTIES
    WIN32_EXECUTABLE ON
    OUTPUT_NAME "qt-help-creator"
)

# ── Translation targets ──────────────────────────────────────────
find_program(QT_LRELEASE_EXECUTABLE
    NAMES lrelease lrelease6
    HINTS "${Qt6Core_DIR}/../../bin"
)
if (NOT QT_LRELEASE_EXECUTABLE)
    message(FATAL_ERROR "lrelease not found")
endif()

set(TS_FILE "${CMAKE_SOURCE_DIR}/resources/translation/qt_help_creator_en.ts")
set(QM_FILE "${CMAKE_BINARY_DIR}/resources/translation/qt_help_creator_en.qm")

add_custom_command(
    OUTPUT ${QM_FILE}
    COMMAND ${QT_LRELEASE_EXECUTABLE} -verbose "${TS_FILE}" -qm "${QM_FILE}"
    DEPENDS ${TS_FILE}
    COMMENT "Compiling translation: qt_help_creator_en.ts → .qm"
    VERBATIM
)

add_custom_target(QtHelpCreator_qm ALL
    DEPENDS ${QM_FILE}
)

# ── Install ──────────────────────────────────────────────────────
install(TARGETS qt-help-creator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
