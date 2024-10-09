#include "QApplication"
#include "MainWindow.h"
#include "QLabel"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}