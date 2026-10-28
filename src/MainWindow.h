#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    void setupUi();
    void createActions();
    void createMenus();
    void createToolBars();
    void setupStatusBar();
};

#endif // MAINWINDOW_H
