#include "MainWindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QMessageBox>

// ---------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    createMenus();
    createToolBars();
    setupStatusBar();
}

// ---------------------------------------------------------------------------

void MainWindow::setupUi()
{
    setWindowTitle(tr("Qt Help Creator"));
    resize(800, 600);
}

// ---------------------------------------------------------------------------

void MainWindow::createActions()
{
    // TODO: add application actions (new, open, save, etc.)
}

// ---------------------------------------------------------------------------

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setShortcut(QKeySequence::Quit);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
}

// ---------------------------------------------------------------------------

void MainWindow::createToolBars()
{
    QToolBar *fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(tr("E&xit"));
}

// ---------------------------------------------------------------------------

void MainWindow::setupStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
