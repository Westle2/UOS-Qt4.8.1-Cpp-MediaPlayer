#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QVideoWidget>
#include"settingdialog.h"
namespace Ui {
class VideoPlay;
}

class VideoPlay : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlay(QWidget *parent = nullptr);
    explicit VideoPlay(QWidget *parent = nullptr,QMediaPlayer* mplayer=nullptr);
    ~VideoPlay();
    QMediaPlayer* player;
    QVideoWidget* video;
    void PlayVideo(QString path);
    void getPlayer(QMediaPlayer*);
    double curSpeed;
    bool isPlaying;
    bool isDrag;
    QPointF dVal;
public slots:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*)override;
    void mouseReleaseEvent(QMouseEvent*) override;
private:
    void uiInit();
    void eventInit();
private slots:
    void on_speedComb_currentIndexChanged(int index);

    void on_btn_pause_keep_clicked();

    void on_voiceSlider_valueChanged(int value);

    void on_player_state_changed(QMediaPlayer::State newState);
    void on_closeBut_clicked();

    void on_miniBut_clicked();

    void on_fullscreen_btn_clicked();

    void on_chMaxBut_clicked();

private:
    Ui::VideoPlay *ui;
};

#endif // VIDEOPLAY_H
