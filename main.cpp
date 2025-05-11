#include "mainwindow.h"
//#include "videoplayer.h"
#include "chat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    ChatWindow w;
    m.show();
    w.show();
    return a.exec();
}
