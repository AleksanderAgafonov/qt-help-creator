# AGENTS.md — qt-help-creator

## Coding conventions

### UI

- Always use `.ui` files (Qt Designer XML) to describe the GUI.
  Source code must not contain `setWindowTitle`, `resize`, `addMenu`, `addAction`, `addToolBar`, `showMessage` or similar GUI-building calls — only business logic.

### File naming

- All files use `snake_case`: `main_window.h`, `main_window.cpp`, `main_window.ui`.
- Nested directories also use `snake_case`: `src/ui/main_window/`.

### Class naming

- Classes use `PascalCase`: `MainWindow`, `HelpEditor`, `DocumentModel`.

### Private member variables

- Private member variables are prefixed with `_`: `_ui`, `_model`, `_editor`.

### GUI element names

- All graphical widget names in `.ui` files use `camelCase`: `centralWidget`, `menuBar`, `menuFile`, `fileToolbar`, `statusBar`, `actionExit`.

### CMakeLists.txt

- Group source files into typed variables (`SOURCES`, `HEADERS`, `UI`) with a project-prefixed name (e.g. `QT_HELP_CREATOR_SOURCES`) before passing them to `qt_add_executable`.
