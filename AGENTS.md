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

### Brace style

- Opening `{` and closing `}` must always be on their own line.
  Exception: array/struct initializer lists.

### Indentation

- Code inside a `{}` block must be indented by 4 spaces.
  Exception: array/struct initializer lists.

### Namespace

- Opening `namespace {` follows the same brace style rule (brace on its own line).
- Namespaces should be closed with an inline comment: `} // namespace Foo`.
- Unnamed namespaces and `namespace foo { ... }` on a single line are discouraged.
