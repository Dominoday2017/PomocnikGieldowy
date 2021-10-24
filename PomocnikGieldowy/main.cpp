#include "PomocnikGieldowy.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PomocnikGieldowy window;

    window.resize(400, 250);
    window.setWindowTitle("Pomocnik Gieldowy");

    window.show();
    return app.exec();
}
