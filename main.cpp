#include "mainwindow.h"
//#include "videoplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();
}
