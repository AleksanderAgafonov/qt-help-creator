#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "ui/main_window/main_window.h"

namespace
{
    void loadStylesheet()
    {
        QFile styleFile(":/style/main.qss");
        if (!styleFile.open(QIODevice::ReadOnly))
        {
            qWarning() << "Cannot open stylesheet:" << styleFile.errorString();
            return;
        }

        const QByteArray data = styleFile.readAll();
        if (data.isEmpty())
        {
            qWarning() << "Stylesheet is empty.";
            return;
        }

        qApp->setStyleSheet(QString::fromUtf8(data));
    }
} // namespace

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setStyle("Fusion");
    application.setApplicationName("QtHelpCreator");
    application.setApplicationDisplayName("Qt Help Creator");
    application.setOrganizationName("QtHelpCreator");
    application.setOrganizationDomain("qt-help-creator.dev");

    loadStylesheet();

    MainWindow mainWindow;
    mainWindow.showMaximized();
    return application.exec();
}
