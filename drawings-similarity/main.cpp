#include "DrawTreeWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawTreeWindow w;
    w.show();

    return a.exec();
}
