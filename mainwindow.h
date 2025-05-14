#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fullscreen.h"
#include"qcolordialog.h"
#include "Vokaturi.h"
#include"videoplay.h"
#include "chat.h"
#include "waveformwidget.h"
#include"settingdialog.h"
#include <QAudioProbe>
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QTimer>
#include <QFileDialog>
#include <QDebug>
#include <QStandardItemModel>
#include <QString>
#include <QStringList>
#include <QScrollBar>
#include <QTextStream>
#include <QProcess>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QSettings>
#include <QMessageBox>
#include <QAudioFormat>
#include <QAudioBuffer>
#include <QPainter>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QSplitter>
#include <QProcess>
#include <QTextEdit>
#include <QtCore>
#include <QCryptographicHash>
#include <QDateTime>
#include <QMessageAuthenticationCode>
#include <QUrl>
#include <QUrlQuery>
#include <QWebSocket>
#include <QAudioInput>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include<QGraphicsDropShadowEffect>
#include <QWidgetAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
// //themes:
// enum THEME{
//     DARK,
//     LIGHT,
//     COLORFUL,
//     FOLLOW_EMOTION,
//     REVERSE_EMOTION,
//     AUTO_EMOTION
// };

//class FullScreenWindow;
//class RtAsrCallbacksImpl;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void init();
    QString get_time_str(int msec);
//    void show_media_name();
    void on_player_state_changed(QMediaPlayer::State newState);
    //void toggle_fullscreen();
    void search();
    // 将 Qt 资源文件提取到临时文件并返回临时文件路径
    QString extractResourceToTempFile(const QString& resourcePath);
    QVideoWidget* getVideoWidget() { return videoWidget; }  // 提供 videoWidget
    QMediaPlayer* getPlayer() { return player; }
    void enterFullScreen();
    void on_comboBox_playMode_currentIndexChanged(int index);
    void playNextSequential(QMediaPlayer::MediaStatus status);//顺序播放
    void playRandom(QMediaPlayer::MediaStatus status);//随机播放
    void loopCurrentFile(QMediaPlayer::MediaStatus status);//单曲循环
    void disconnectPlayerSignals();
    //void updateUIAndPlay(int index);
    //void restoreVideoWidgetLayout(QVideoWidget* widget);
    QProcess* process;
    void start_voice_to_text();
    QString loadStylesheet(const QString& templatePath, const QMap<QString, QString>& colors);
    QVBoxLayout *videoLayout;
    QColor getContrastColor(const QColor &baseColor);
    QColor adjustButtonColor(const QColor &baseColor);
    bool isDarkColor(const QColor &color);
    bool isDrag;
    QPointF dVal;
    VideoPlay* vp;
    QPushButton *btn_min;
    QPushButton *btn_max;
    QPushButton *btn_close;
public slots:
    void on_btn_prev_clicked();
    void on_btn_pause_keep_clicked();
    void on_btn_next_clicked();
    void on_btn_open_folder_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_listWidget_2_currentTextChanged(const QString &currentText);
    void update_position();
    void on_horizontalSlider_2_sliderMoved(int position);
    void play_selected_media(int index);
    void on_exit_fullscreen();
    //void on_btn_fullscreen_clicked();
    //void on_btn_speed_changed(); // 响应倍速选择的槽函数
    //void enter_fullscreen();
    void on_btn_speed_clicked();
    void add_to_history(const QString &filepath); // 存储文件路径
    void load_history();        // 加载历史记录
    void save_history();        // 保存历史记录
    void search_list(const QString &text);         // 搜索框功能
    void show_context_menu(const QPoint &pos); // 右键菜单
    void delete_item(QListWidgetItem *item);         // 删除选中的项
    void on_comboBox_theme_currentIndexChanged(int index);
    void on_btn_emotion_clicked();
    void emotion_to_theme(const QString &modelPath);
    void update_emo_rank();
    void process_audio_buffer_emotion(const QAudioBuffer &buffer);
    // void on_btn_shrink_expand_clicked();
    void on_btn_voice_to_text_toggled(bool checked);

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*)override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::MainWindow *ui;
    QMediaPlaylist *playlist;//播放列表
    QMediaPlayer *player;//播放器
    int pause_keep_flag;//暂停/继续标志位
    int total;//播放时间总长
    int start_flag;
    bool is_playing_flag = false;
    #define DEFAULT_PATH "/"  //可调整
    QString media_path;
    QStringList media_name_list;
    QStringList playListInfo;
    int index; //当前正在播放的音乐下标记
    QVideoWidget *videoWidget;//视频区
    bool isFullScreenMode = false;//记录全屏状态
    QVBoxLayout *layout;
    //QFrame *control_frame; //隐藏控制框
    //QPushButton *btn_fullscreen;
    QPushButton *speedButton;
    QMenu *speedMenu;  // 用于存放倍速选项的菜单

    //FullScreenWindow *fsWindow = nullptr;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QPushButton *exitButton;
    QSettings *settings;
    QMap<QString, QString> playListMap;
    // enum PlayMode {
    //     Sequential,   // 顺序播放
    //     Shuffle,      // 随机播放
    //     Single,       // 单个播放
    //     SingleLoop,   // 单个循环
    // };
    PlayMode currentMode;
   // bool is_auto_change = true;
    QPushButton *pushButton;
    QDialog *emotionDialog;  // 用于弹出的情感分析窗口
    QAudioProbe *audioProbe;
    //SparkChain::RTASR* rtasr;  // ASR 实例
    QVector<float> pcmSamples;  // 存储PCM数据
    VokaturiVoice vokaturiVoice;
    QMap<int, int> visibleRowToSourceRow; // 记录可见行号到实际行号的映射
    int getCurrentVisibleRow(); // 新增
    int currentTheme; //默认暗色主题，后续可修改为记录上一次主题状态
    QString stylesheet;  // 在switch外部声明
    QMap<QString, QString> colors;  // 在switch外部声明
    QColor selectedColor;  // 在switch外部声明
    QColor currentColor;//current color keep it for change of other widgets
    QString modelPath;
    QString installPath;
    QString qicPath;
    WaveformWidget *waveformWidget;  // 添加指针
    ChatWindow *chatDock = nullptr;
    QFrame *volumePopup = nullptr;
protected:
    //bool eventFilter(QObject *watched, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    //void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    //void paintEvent(QPaintEvent *event) override;

private slots:
    void on_fullscreen_btn_clicked();
    void on_pushButton_clicked();
    void on_search_but_clicked();
    void on_btn_setting_clicked();
    void on_btn_chat_clicked();
};
#endif // MAINWINDOW_H
