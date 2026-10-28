#include "ui/main_window/main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    main_window w;
    w.show();
    return a.exec();
}
