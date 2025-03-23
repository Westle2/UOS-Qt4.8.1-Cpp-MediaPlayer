#include "fullscreen.h"
#include "mainwindow.h"
#include <QPushButton>

FullScreenWindow::FullScreenWindow(MainWindow *mainWin, QWidget *parent)
   : QWidget(parent), mainWindow(mainWin) {
   this->setAttribute(Qt::WA_DeleteOnClose);
   qDebug()<<"Created Full Screen";
   this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   this->setWindowState(Qt::WindowFullScreen);
   videoWidget = mainWindow->getVideoWidget();
   //videoWidget=new QVideoWidget(this);
   videoWidget->setParent(this);
   exitButton = new QPushButton("退出全屏", this);
   exitButton->setGeometry(20, 20, 100, 40);
   connect(exitButton, &QPushButton::clicked, this, &FullScreenWindow::on_exit_fullscreen_clicked);

   // Set layout for fullscreen window
   QVBoxLayout *layout = new QVBoxLayout();
   layout->addWidget(videoWidget);
   layout->addWidget(exitButton);
   this->setLayout(layout);
   // connect(exitButton, &QPushButton::clicked, parent, [parent]() {
   //     QMetaObject::invokeMethod(parent, "on_exit_fullscreen");
   // });
   connect(exitButton, &QPushButton::clicked, mainWindow, &MainWindow::on_exit_fullscreen);
   videoWidget->show();
}
FullScreenWindow::~FullScreenWindow() {
   qDebug()<<"~fullscreenWindow";
   if (videoWidget) {
       mainWindow->restoreVideoWidgetLayout(videoWidget);
   }
}
void FullScreenWindow::on_exit_fullscreen_clicked()
{
   // Close fullscreen window and show main window again
   this->close();
   mainWindow->show();
}

void FullScreenWindow::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Escape) {  // 按Esc退出全屏
       close();  // 关闭全屏窗口
   }
}
