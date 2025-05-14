#include "videoplay.h"
#include "ui_videoplay.h"

#include <QMouseEvent>
#include <qaction.h>
#include <qmenu.h>

VideoPlay::VideoPlay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoPlay)
{
    ui->setupUi(this);
    uiInit();
    eventInit();
}

VideoPlay::VideoPlay(QWidget *parent, QMediaPlayer* mplayer)    : QWidget(parent)
    , ui(new Ui::VideoPlay)
{
    ui->setupUi(this);
    getPlayer(mplayer);
    uiInit();
    eventInit();
    player->play();
}

VideoPlay::~VideoPlay()
{
    delete ui;
}

void VideoPlay::PlayVideo(QString path)
{
    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    isPlaying=1;
}
//从主界面获取player
void VideoPlay::getPlayer(QMediaPlayer * mplayer)
{
    player=mplayer;
}

void VideoPlay::on_player_state_changed(QMediaPlayer::State newState)
{
    if (newState == QMediaPlayer::PlayingState) {
        isPlaying = true;
    } else {
        isPlaying = false;
    }
    // 如果播放器停止了，根据当前播放模式决定是否播放下一首
    if (newState == QMediaPlayer::StoppedState) {
        if (player->mediaStatus() == QMediaPlayer::EndOfMedia) {  // 仅当播放自然结束时切换
            this->hide();
            }
        }
}


void VideoPlay::uiInit()
{
    video=new QVideoWidget(ui->Video);
    QVBoxLayout *layout=new QVBoxLayout(ui->Video);
    layout->addWidget(video);
    player->setVideoOutput(video);
    ui->label_progress->adjustSize();
    ui->label_progress->setText("00:00/00:00");
    ui->label_title->setText("暂未播放");
    //按钮提示词
    ui->speedComb->setToolTip("倍速");
    ui->btn_pause_keep->setToolTip("播放/暂停");
}
void VideoPlay::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        dVal=ev->globalPos()-pos();
        isDrag=1;
    }
}
void VideoPlay::mouseMoveEvent(QMouseEvent *ev)
{
    if(isDrag){
        move((ev->globalPos()-dVal).toPoint());
    }
}

void VideoPlay::mouseReleaseEvent(QMouseEvent *ev)
{
    isDrag=0;
}

void VideoPlay::eventInit()
{
    connect(player, &QMediaPlayer::stateChanged, this, &VideoPlay::on_player_state_changed);
    connect(ui->chMaxBut, &QPushButton::clicked, [=]() {
        if (isMaximized()) {
            showNormal();
        } else {
            showMaximized();
        }
    });
    isPlaying=0;
}


void VideoPlay::on_speedComb_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        curSpeed=1.0;
        break;
    case 1:
        curSpeed=0.75;
        break;
    case 2:
        curSpeed=1.5;
        break;
    case 3:
        curSpeed=2.0;
        break;
    }
    player->stop();  // 停止当前播放
    player->setPlaybackRate(curSpeed);
    player->play();  // 重新播放以应用倍速
}


void VideoPlay::on_btn_pause_keep_clicked()
{
    if(isPlaying){
        isPlaying=0;
        ui->btn_pause_keep->setIcon(QIcon(":/qic/svg/pause.svg"));
        player->pause();
    }
    else{
        isPlaying=1;
        ui->btn_pause_keep->setIcon(QIcon(":/qic/svg/keep.svg"));
        player->play();
    }
}


void VideoPlay::on_voiceSlider_valueChanged(int value)
{
    player->setVolume(value);
    ui->curVoiceLab->setText(QString::number(value));
    if (value > 0) {
        ui->pic_voice_lab->setStyleSheet("border-image: url(:/qic/svg/voice_open.svg);");
    }
    else if (value == 0) {
        ui->pic_voice_lab->setStyleSheet("border-image: url(:/qic/images/voice_close.png);");
    }
}


void VideoPlay::on_closeBut_clicked()
{
    this->hide();
}


void VideoPlay::on_miniBut_clicked()
{
    this->showMinimized();
}


void VideoPlay::on_fullscreen_btn_clicked()
{
    this->showFullScreen();
}


void VideoPlay::on_chMaxBut_clicked()
{
    if(!this->isFullScreen())this->showFullScreen();
    else this->showNormal();
}

