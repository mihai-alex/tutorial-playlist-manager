#include <QtWidgets/QApplication>
#include "controller.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller ctrl;
    GUI w{ ctrl };
    w.show();
    return a.exec();
}
