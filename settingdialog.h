#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include<QSettings>
#include<QDebug>
namespace Ui {
class SettingDialog;
}
enum THEME{
    DARK,
    LIGHT,
    COLORFUL,
    FOLLOW_EMOTION,
    REVERSE_EMOTION,
    AUTO_EMOTION
};
enum PlayMode {
    Sequential,   // 顺序播放
    Shuffle,      // 随机播放
    Single,       // 单个播放
    SingleLoop,   // 单个循环
};
enum SPEED{
    sp_1,
    sp_075,
    sp_15,
    sp_2
};
class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();
    QSettings* settings;
    THEME theme;
    SPEED speedRate;
    PlayMode playmode;
    void loadConfig();
    void saveConfig();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*)override;
    void mouseReleaseEvent(QMouseEvent*) override;
    bool isDrag;
    QPointF dVal;
// signals:
//     void saveConfig();
private slots:
    void on_ThemeComb_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_speedComb_currentIndexChanged(int index);

    void on_playModeComb_currentIndexChanged(int index);

    void on_buttonBox_rejected();

    void on_closeBut_clicked();

    void on_miniBut_clicked();

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
