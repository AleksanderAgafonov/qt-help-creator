# AGENTS.md — qt-help-creator

## Coding conventions

### UI

- Всегда используй `.ui` файлы (Qt Designer XML) для описания GUI.
  Программный код не должен содержать вызовов `setWindowTitle`, `resize`, `addMenu`, `addAction`, `addToolBar`, `showMessage` и подобных для построения интерфейса — только логика.

### Именование файлов

- Все файлы — в `snake_case`: `main_window.h`, `main_window.cpp`, `main_window.ui`.
- Вложенные каталоги — также в `snake_case`: `src/ui/main_window/`.

### Именование классов

- Классы — в `PascalCase`: `MainWindow`, `HelpEditor`, `DocumentModel`.
