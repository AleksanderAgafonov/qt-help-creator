# AGENTS.md — qt-help-creator

## Contents

- [Coding conventions](#coding-conventions)
  - [Naming](#naming)
    - [File naming](#file-naming)
    - [Class naming](#class-naming)
    - [GUI element names](#gui-element-names)
    - [Private member variables](#private-member-variables)
  - [Style](#style)
    - [Brace style](#brace-style)
    - [Indentation](#indentation)
    - [Namespace](#namespace)
  - [Includes](#includes)
    - [Order and sorting](#order-and-sorting)
    - [Widget .cpp files](#widget-cpp-files)
    - [No duplication](#no-duplication)
    - [Forward declarations](#forward-declarations)
  - [Qt-specific](#qt-specific)
    - [UI](#ui)
    - [Signals and slots](#signals-and-slots)
    - [User-visible strings](#user-visible-strings)
    - [Memory ownership](#memory-ownership)
  - [Project structure](#project-structure)
    - [CMakeLists.txt](#cmakeliststxt)
    - [Resources](#resources)

## Coding conventions

### Naming

#### File naming

- **MUST** all files use `snake_case`: `main_window.h`, `main_window.cpp`, `main_window.ui`.
- **MUST** nested directories also use `snake_case`: `src/ui/main_window/`.

#### Class naming

- **MUST** classes use `PascalCase`: `MainWindow`, `HelpEditor`, `DocumentModel`.

#### GUI element names

- **MUST** all graphical widget names in `.ui` files use `camelCase`: `centralWidget`, `menuBar`, `menuFile`, `fileToolbar`, `statusBar`, `actionExit`.

#### Private member variables

- **MUST** private member variables be prefixed with `_`: `_ui`, `_model`, `_editor`.

### Style

#### Brace style

- **MUST** opening `{` and closing `}` always be on their own line.
  Exception: array/struct initializer lists.

#### Indentation

- **MUST** code inside a `{}` block be indented by 4 spaces.
  Exception: array/struct initializer lists.

#### Namespace

- **MUST** opening `namespace {` follow the same brace style rule (brace on its own line).
- **MUST** namespaces be closed with an inline comment: `} // namespace Foo`.
- **SHOULD NOT** use unnamed namespaces in header files; unnamed namespaces in `.cpp` are fine.

### Includes

#### Order and sorting

- `#include` directives are grouped into three blocks in this order:
  1. Qt headers (`<QtModule/...>` or `<...>`)
  2. C++ standard library headers (`<...>`)
  3. Project local headers (`"..."`)
  An empty line separates each block.
- Within each block, headers are sorted alphabetically by full path.

#### Widget .cpp files

- Every `.cpp` file for a widget generated from a `.ui` file starts with exactly these two includes, without a blank line between them:
  ```cpp
  #include "main_window.h"
  #include "ui_main_window.h"

  ```
  After this pair, an empty line follows, then the remaining blocks (Qt → C++ → local) follow per rules above.

#### No duplication

- If a header is already `#include`d in the corresponding `.h` file, it must NOT be repeated in the `.cpp`.

#### Forward declarations

- **SHOULD** prefer forward declarations over `#include` whenever a full type definition is not needed at the point of use.
- **MUST** forward declarations be placed after all `#include` blocks and `QT_BEGIN_NAMESPACE` / `QT_END_NAMESPACE` wrappers, separated by blank lines before and after.
- **MUST** forward declarations be sorted alphabetically, the same way as include blocks.

### Qt-specific

#### UI

- **MUST** always use `.ui` files (Qt Designer XML) to describe the GUI.
  Source code must not contain `setWindowTitle`, `resize`, `addMenu`, `addAction`, `addToolBar`, `showMessage` or similar GUI-building calls — only business logic.

#### Signals and slots

- **MUST** connections use explicit `connect()` calls.
  Auto-connect (`on_<objectName>_<signal>`) is prohibited.
  `connect()` may be placed anywhere in the class implementation.

#### User-visible strings

- **MUST** all user-visible strings go through `tr()` in C++ code.
- **MUST** the source language be English.
- In `.ui` files, all `property` values that the user sees **MUST** be translatable (marked with `tr()` in Designer).

#### Memory ownership

- **MUST** `QObject`-derived widgets use parent-child ownership (raw pointers, no `new` with manual `delete`).
- **MUST** `Ui::*` objects be owned by `std::unique_ptr`.
- **MUST** model objects (`Block`, `Document`, etc.) be owned by `std::unique_ptr` and must not inherit from `QObject`.

### Project structure

#### CMakeLists.txt

- **MUST** group source files into typed variables (`SOURCES`, `HEADERS`, `UI`) with a project-prefixed name (e.g. `QT_HELP_CREATOR_SOURCES`) before passing them to `qt_add_executable`.

#### Resources

- **SHOULD** icons, styles, and other static resources live in `resources/`.
- Each logical group (icons, translations, etc.) has its own `.qrc` file.
- Resource paths in code are prefixed with `/`.
