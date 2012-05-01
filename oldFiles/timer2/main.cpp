#include <QtGui/QApplication>
#include "timer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    timer w;
    w.show();

    return a.exec();
}
