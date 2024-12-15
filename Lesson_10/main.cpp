#include "graphicstest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicsTest w;
    w.show();
    return a.exec();
}
