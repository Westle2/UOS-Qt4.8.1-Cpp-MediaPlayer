#include "videoplay.h"
#include "ui_videoplay.h"

#include <qaction.h>
#include <qmenu.h>

VideoPlay::VideoPlay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoPlay)
{
    ui->setupUi(this);
    uiInit();
}

VideoPlay::~VideoPlay()
{
    delete ui;
}

void VideoPlay::PlayVideo(QString path)
{
    player->setMedia(QUrl::fromLocalFile(path));

}

void VideoPlay::uiInit()
{
    video=new QVideoWidget(ui->Video);
    player->setVideoOutput(video);
    ui->label_progress->adjustSize();
    ui->label_progress->setText("00:00/00:00");
    ui->label_title->setText("暂未播放");
    //按钮提示词
    ui->btn_speed->setToolTip("倍速");
    ui->btn_next->setToolTip("下一曲");
    ui->btn_prev->setToolTip("上一曲");
    ui->btn_pause_keep->setToolTip("播放/暂停");
}

void VideoPlay::on_btn_speed_clicked()
{
    qDebug() << "倍速按钮被点击了";  // 调试日志
    // 创建倍速菜单
    QMenu *speedMenu = new QMenu(this);
    QAction *speed_075 = new QAction("0.75x", this);
    QAction *speed_1x = new QAction("1x", this);
    QAction *speed_15x = new QAction("1.5x", this);
    QAction *speed_2x = new QAction("2x", this);

    // 设置倍速选项的连接
    connect(speed_075, &QAction::triggered, [this](){

        if (player->state() == QMediaPlayer::PlayingState) {
            player->stop();  // 停止当前播放
            player->setPlaybackRate(0.75);  // 设置播放速率
            player->play();  // 重新播放以应用倍速
        }
        else player->setPlaybackRate(0.75);  // 设置播放速率
    });
    connect(speed_1x, &QAction::triggered, [this](){

        if (player->state() == QMediaPlayer::PlayingState) {
            player->stop();  // 停止当前播放
            player->setPlaybackRate(1.0);
            player->play();  // 重新播放以应用倍速
        }
        else player->setPlaybackRate(1.0);
    });
    connect(speed_15x, &QAction::triggered, [this](){

        if (player->state() == QMediaPlayer::PlayingState) {
            player->stop();  // 停止当前播放
            player->setPlaybackRate(1.5);
            player->play();  // 重新播放以应用倍速
        }
        else player->setPlaybackRate(1.5);
    });
    connect(speed_2x, &QAction::triggered, [this](){
        if (player->state() == QMediaPlayer::PlayingState) {
            player->stop();  // 停止当前播放
            player->setPlaybackRate(2.0);

            player->play();  // 重新播放以应用倍速
        }
        else player->setPlaybackRate(2.0);
    });

    // 将倍速选项添加到菜单中
    speedMenu->addAction(speed_075);
    speedMenu->addAction(speed_1x);
    speedMenu->addAction(speed_15x);
    speedMenu->addAction(speed_2x);

    // 显示倍速菜单，基于按钮位置
    speedMenu->exec(ui->btn_speed->mapToGlobal(QPoint(0, ui->btn_speed->height())));
}

void VideoPlay::on_comboBox_playMode_currentIndexChanged(int index)
{
    //disconnectPlayerSignals();
    //PlayMode currentMode = Sequential;  // 默认顺序播放
    switch (index) {
    case 0:
        currentMode = Sequential;
        break;
    case 1:
        currentMode = Shuffle;
        break;
    case 2:
        currentMode = Single;
        break;
    case 3:
        currentMode = SingleLoop;
        break;
    }

    qDebug() << "c当前播放模式：" << currentMode;
}
