#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QVideoWidget>
namespace Ui {
class VideoPlay;
}

class VideoPlay : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlay(QWidget *parent = nullptr);
    ~VideoPlay();
    QMediaPlayer* player;
    QVideoWidget* video;
    void PlayVideo(QString path);
    enum PlayMode {
        Sequential,   // 顺序播放
        Shuffle,      // 随机播放
        Single,       // 单个播放
        SingleLoop,   // 单个循环
    };
    PlayMode currentMode;
public slots:
    void on_comboBox_playMode_currentIndexChanged(int index);
private:
    void uiInit();
private slots:
    void on_btn_speed_clicked();

private:
    Ui::VideoPlay *ui;
};

#endif // VIDEOPLAY_H
