#include "main_window.h"

#include "ui_main_window.h"

#include <memory>

// ---------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(std::make_unique<Ui::MainWindow>())
{
    _ui->setupUi(this);
}

// ---------------------------------------------------------------------------

MainWindow::~MainWindow() = default;
