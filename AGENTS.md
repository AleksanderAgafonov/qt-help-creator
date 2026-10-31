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

### Includes

1. **Order of blocks:** `#include` directives are grouped into three blocks in this order:
   - Qt headers (`<QtModule/...>` or `<...>`)
   - C++ standard library headers (`<...>`)
   - Project local headers (`"..."`)
   An empty line separates each block.

2. **Sorting:** Within each block, headers are sorted alphabetically by full path.

3. **Widget .cpp files:** Every `.cpp` file for a widget generated from a `.ui` file starts with exactly these two includes, without a blank line between them:
   ```cpp
   #include "main_window.h"
   #include "ui_main_window.h"

   ```
   After this pair, an empty line follows, then the remaining blocks (Qt → C++ → local) follow per rules 1–2.

4. **No duplication:** If a header is already `#include`d in the corresponding `.h` file, it must NOT be repeated in the `.cpp`.

5. **Forward declarations:** Prefer forward declarations over `#include` whenever a full type definition is not needed at the point of use.

6. **Placement:** Forward declarations are placed after all `#include` blocks and `QT_BEGIN_NAMESPACE` / `QT_END_NAMESPACE` wrappers, separated by blank lines before and after. They are sorted in the order they first appear in the `.cpp` file (same sorting rule as includes).
