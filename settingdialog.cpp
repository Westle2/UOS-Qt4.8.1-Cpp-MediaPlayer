#include "settingdialog.h"
#include "ui_settingdialog.h"

#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>

SettingDialog::SettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    //设置无边框
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect* shadow=new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setColor(QColor(0x00,0x00,0x00,255));
    shadow->setOffset(0);
    setGraphicsEffect(shadow);

    settings=new QSettings("MyApp", "MusicPlayer");
    loadConfig();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::loadConfig()
{
    if(!settings->contains("Theme")){
        settings->setValue("Theme",DARK);
    }
    if(!settings->contains("Speed")){
        settings->setValue("Speed",sp_1);
    }
    if(!settings->contains("PlayMode")){
        settings->setValue("PlayMode",Sequential);
    }
    theme=(THEME)settings->value("Theme",DARK).toInt();
    speedRate=(SPEED)settings->value("Speed",sp_1).toInt();
    playmode=(PlayMode)settings->value("PlayMode",Sequential).toInt();
    qDebug()<<theme<<speedRate<<playmode;
    ui->playModeComb->setCurrentIndex(playmode);
    ui->speedComb->setCurrentIndex(speedRate);
    ui->ThemeComb->setCurrentIndex(theme);
}

void SettingDialog::saveConfig()
{
    settings->setValue("Theme",theme);
    settings->setValue("Speed",speedRate);
    settings->setValue("PlayMode",playmode);
}

void SettingDialog::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton&& ev->pos().y()<0.8*this->width()){
        dVal=ev->globalPos()-pos();
        isDrag=1;
    }
}
void SettingDialog::mouseMoveEvent(QMouseEvent *ev)
{
    if(isDrag){
        move((ev->globalPos()-dVal).toPoint());
    }
}

void SettingDialog::mouseReleaseEvent(QMouseEvent *ev)
{
    isDrag=0;
}

void SettingDialog::on_ThemeComb_currentIndexChanged(int index)
{
    theme=(THEME)index;
}


void SettingDialog::on_buttonBox_accepted()
{
    saveConfig();
    this->close();
}


void SettingDialog::on_speedComb_currentIndexChanged(int index)
{
    speedRate=(SPEED)index;

}


void SettingDialog::on_playModeComb_currentIndexChanged(int index)
{
    playmode=(PlayMode)index;
}


void SettingDialog::on_buttonBox_rejected()
{
    this->close();
}


void SettingDialog::on_closeBut_clicked()
{
    saveConfig();
    this->close();
}


void SettingDialog::on_miniBut_clicked()
{
    this->showMinimized();
}

