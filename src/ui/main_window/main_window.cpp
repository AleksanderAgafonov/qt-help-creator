#include "main_window.h"

#include "ui_main_window.h"

#include <memory>

// ---------------------------------------------------------------------------

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui_(std::make_unique<Ui::MainWindow>())
{
    ui_->setupUi(this);
}

// ---------------------------------------------------------------------------

main_window::~main_window() = default;
