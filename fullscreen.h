#ifndef FULLSCREEN_H
#define FULLSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QVideoWidget>
class QPushButton;
class MainWindow;

class FullScreenWindow : public QWidget {
   Q_OBJECT
public:
   explicit FullScreenWindow(MainWindow *mainWin, QWidget *parent = nullptr);
   ~FullScreenWindow() override;
signals:
   void exitFullScreen();
private slots:
   void on_exit_fullscreen_clicked();
protected:
   void keyPressEvent(QKeyEvent *event) override;
public:
   QVideoWidget *videoWidget;
private:
   MainWindow *mainWindow;
   QPushButton *exitButton;
};

#endif // FULLSCREEN_H
