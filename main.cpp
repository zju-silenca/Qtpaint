#include "easycad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    easyCAD w;
    w.show();
    return a.exec();
}

