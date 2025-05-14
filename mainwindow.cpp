#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentMode(Sequential)
{
    settings = new QSettings("MyApp", "MusicPlayer", this);
    ui->setupUi(this);
    this->setWindowTitle("绪音");
    // 检查 QSettings 是否正确初始化
    if (settings == nullptr) {
        qDebug() << "QSettings initialization failed!";
    }
    media_path=DEFAULT_PATH;

    init();
}
MainWindow::~MainWindow()
{
    delete ui;
    if (process->state() == QProcess::Running) {
        process->terminate();
        process->waitForFinished(3000);
    }
    delete process;
}

void MainWindow::init()
{
    start_flag = 0;
    pause_keep_flag = 0;
    is_playing_flag = false;
    //设置无边框
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect* shadow=new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setColor(QColor(0x00,0x00,0x00,255));
    shadow->setOffset(0);
    setGraphicsEffect(shadow);
    /*========全屏/关闭/缩小=========*/
    // 系统按钮
    btn_min = new QPushButton(this);
    btn_max = new QPushButton(this);
    btn_close = new QPushButton(this);

    QIcon iconMin = QIcon(":/qic/svg/mini.svg");
    QIcon iconMax = QIcon(":/qic/svg/ch_max.svg");
    QIcon iconClose = QIcon(":/qic/svg/close.svg");

    btn_min->setIcon(iconMin);
    btn_max->setIcon(iconMax);
    btn_close->setIcon(iconClose);

    btn_min->setFixedSize(40, 30);
    btn_max->setFixedSize(40, 30);
    btn_close->setFixedSize(40, 30);

    btn_min->setIconSize(QSize(20, 20));
    btn_max->setIconSize(QSize(20, 20));
    btn_close->setIconSize(QSize(20, 20));

    btn_min->setFlat(true);
    btn_max->setFlat(true);
    btn_close->setFlat(true);
    QString ss = R"(
    QPushButton {
        background-color: transparent;
        border: none;
        border-radius: 15px;
        min-width: 30px;
        min-height: 30px;
    }
    QPushButton:hover {
        background-color: rgb(239, 41, 41);
    }
    QPushButton:pressed {
        background-color: rgb(238, 238, 236);
        padding-top: 2px;
        padding-left: 2px;
    }
)";
    btn_close->move(width()-btn_close->width()-5,5);
    btn_max->move(btn_close->x()-btn_max->width()-5,5);
    btn_min->move(btn_max->x()-btn_min->width()-5,5);

    btn_close->raise();
    btn_min->raise();
    btn_max->raise();
    btn_close->setStyleSheet(ss);
    btn_min->setStyleSheet(ss);
    btn_max->setStyleSheet(ss);
    // 按钮连接
    connect(btn_close, &QPushButton::clicked, this, &MainWindow::close);
    connect(btn_min, &QPushButton::clicked, this, &MainWindow::showMinimized);
    connect(btn_max, &QPushButton::clicked, [=]() {
        if (isFullScreen()) {
            showNormal();
        } else {
            showFullScreen();
        }
    });



    playlist = new QMediaPlaylist(this);
    player = new QMediaPlayer(this);
    //videoWidget = new QVideoWidget(ui->VideoWidget);
    vp=new VideoPlay(this,getPlayer());
    vp->hide();
    // 初始化 QAudioProbe
    audioProbe = new QAudioProbe(this);

    //设置视频输出
    // player->setVideoOutput(videoWidget);
    // videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
//    // 获取UI中的QSplitter对象，假设它的objectName是splitter
    //QSplitter *splitter = ui->splitter;
    // 设置分隔条初始大小
    //splitter->setSizes({400, 300});  // 例如左侧400px，右侧300px

    // // 设置最小尺寸
    // ui->left_widget->setMinimumSize(200, 200);  // 设置视频区域最小尺寸
    // ui->right_widget->setMinimumSize(150, 200);  // 设置listWidget的最小尺寸

    // // 设置sizePolicy来确保控件大小可自适应
    // ui->left_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // ui->right_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //UI
    // videoLayout = new QVBoxLayout(ui->VideoWidget);
    // videoLayout->setSizeConstraint(QLayout::SetNoConstraint);
    // videoLayout->addWidget(videoWidget);
    // videoWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    // 构造函数中初始化播放模式
    // 设置ComboBox
    ui->comboBox_playMode->addItem("顺序播放");
    ui->comboBox_playMode->addItem("随机播放");
    ui->comboBox_playMode->addItem("单个播放");
    ui->comboBox_playMode->addItem("单个循环");
    //ui->comboBox_playMode->addItem("列表循环");
    ui->comboBox_theme->addItem("深色");
    ui->comboBox_theme->addItem("浅色");
    ui->comboBox_theme->addItem("自定义");
    ui->comboBox_theme->addItem("跟随情绪");
    ui->comboBox_theme->addItem("逆转情绪");
    ui->comboBox_theme->addItem("自动推荐");
    ui->comboBox_theme->setEditable(0);
    //ui->VideoWidget->setLayout(videoLayout);
    // ui->widget->setLayout(ui->videoLayout);
    ui->horizontalSlider->setRange(0,100);
    ui->horizontalSlider->setValue(0);
    ui->label_2->setText("0");
    ui->label_progress->adjustSize();
    ui->label_progress->setText("00:00/00:00");
    ui->label_title->setText("暂未播放");

    // ui->VideoWidget->setMouseTracking(true);
    // ui->VideoWidget->installEventFilter(this);
    //按钮提示词
    ui->btn_speed->setToolTip("倍速");
    ui->btn_next->setToolTip("下一曲");
    ui->btn_prev->setToolTip("上一曲");
    ui->btn_pause_keep->setToolTip("播放/暂停");
    ui->btn_open_folder->setToolTip("导入文件");
    ui->comboBox_playMode->setToolTip("播放模式");
    ui->comboBox_theme->setToolTip("主题切换");
    ui->btn_emotion->setToolTip("情绪检测");
    ui->search_box->setToolTip("搜索");
    ui->btn_shrink_expand->setToolTip("收缩/展开");
    ui->btn_voice_to_text->setToolTip("字幕");
    // 监听事件
    //ui->VideoWidget->installEventFilter(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::update_position);
    connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::on_player_state_changed);
    connect(ui->search_box, &QLineEdit::textChanged, this, &MainWindow::search_list);

    // 加载历史记录
    load_history();
    // 右键菜单
    ui->listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_2, &QListWidget::customContextMenuRequested, this, &MainWindow::show_context_menu);
    this->setFocusPolicy(Qt::StrongFocus);
    //videoWidget->show();

    connect(audioProbe, &QAudioProbe::audioBufferProbed, this, &MainWindow::process_audio_buffer_emotion);
    connect(ui->listWidget_2, &QListWidget::itemClicked, [this](QListWidgetItem *item) {
        // 获取可见行号（根据当前可见项计算）
        int visibleRow = 0;
        for (int i = 0; i < ui->listWidget_2->count(); ++i) {
            QListWidgetItem *current = ui->listWidget_2->item(i);
            if (current == item) break;
            if (!current->isHidden()) visibleRow++;
        }
        play_selected_media(visibleRow);
    });
    connect(ui->comboBox_playMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_comboBox_playMode_currentIndexChanged);
//    connect(this, &MainWindow::asrResultReceived, this, &MainWindow::update_subtitles);
//    mRTASRCallbacks = new SparkChain::RtAsrCallbacksImpl(this);  // 使用命名空间 SparkChain

//    connect(mRTASRCallbacks, &SparkChain::RtAsrCallbacksImpl::asrResultReceived,
//            this, &MainWindow::update_subtitles);
    // 绑定 probe 到 player
    if (!audioProbe->setSource(player)) {
        qDebug() << "无法连接 QAudioProbe 到播放器！";
    }
    start_flag = 1;
    is_playing_flag = false;//防止初始化时自动播放
    search_list(""); // 显示所有项
    // vp=new VideoPlay(this,player);
    // vp->show();
    update_emo_rank();
    ui->unused->setVisible(false);
}

int MainWindow::getCurrentVisibleRow() {
    QListWidgetItem* currentItem = ui->listWidget_2->currentItem();

    // 如果当前没有选中项或列表为空
    if (!currentItem || visibleRowToSourceRow.isEmpty()) {
        return -1;
    }

    // 获取实际行号
    int actualRow = ui->listWidget_2->row(currentItem);

    // 遍历映射表查找对应的可见行号
    for (auto it = visibleRowToSourceRow.begin(); it != visibleRowToSourceRow.end(); ++it) {
        if (it.value() == actualRow) {
            return it.key(); // 返回可见行号
        }
    }
    // 如果当前项被隐藏
    return -1;
}

//播放器状态
void MainWindow::on_player_state_changed(QMediaPlayer::State newState)
{

    if (newState == QMediaPlayer::PlayingState) {
        is_playing_flag = true;
    } else {
        is_playing_flag = false;
    }
    // 输出当前播放模式
    qDebug() << "c当前播放模式：" << currentMode;
    // 如果播放器停止了，根据当前播放模式决定是否播放下一首
    if (newState == QMediaPlayer::StoppedState) {
        if (player->mediaStatus() == QMediaPlayer::EndOfMedia) {  // 仅当播放自然结束时切换
            switch (currentMode) {
                case Sequential:
                    playNextSequential(QMediaPlayer::EndOfMedia);
                    break;
                case Shuffle:
                    playRandom(QMediaPlayer::EndOfMedia);
                    break;
                case Single:
                    // 在 Single 模式下，不需要做任何处理
                    break;
                case SingleLoop:
                    loopCurrentFile(QMediaPlayer::EndOfMedia);
                    break;

            }
        }
    }
}


void MainWindow::on_comboBox_playMode_currentIndexChanged(int index)
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
// 顺序播放
void MainWindow::playNextSequential(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        // 获取当前选中的行号（实际显示的行号）
        int currentVisibleRow = -1;
        QListWidgetItem *currentItem = ui->listWidget_2->currentItem();
        for (int i = 0; i < ui->listWidget_2->count(); ++i) {
            if (ui->listWidget_2->item(i) == currentItem) {
                currentVisibleRow = i;
                break;
            }
        }

        // 计算下一首可见行号
        if (currentVisibleRow != -1 && currentVisibleRow < ui->listWidget_2->count()) {
            int nextVisibleRow = (currentVisibleRow + 1) % ui->listWidget_2->count();

            // 通过 visibleRowToSourceRow 获取下一首的实际行号
            int nextSourceRow = visibleRowToSourceRow[nextVisibleRow];

            // 播放下一首
            play_selected_media(nextSourceRow);
        }
    }
}


// 随机播放
void MainWindow::playRandom(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        int count = ui->listWidget_2->count();
        if (count <= 1) {
            play_selected_media(0);  // 只有一首歌，就播放它
            return;
        }

        int currentRow = ui->listWidget_2->currentRow();
        int randomRow;

        do {
            randomRow = qrand() % count;
        } while (randomRow == currentRow);  // 避免重复播放当前歌曲

        play_selected_media(randomRow);
    }
}

// 单个循环
void MainWindow::loopCurrentFile(QMediaPlayer::MediaStatus status)
{
   // disconnectPlayerSignals();
    if (status == QMediaPlayer::EndOfMedia) {
        player->play();  // 重复播放当前文件
    }
}

//时长
QString MainWindow::get_time_str(int msec)
{
    int min, sec;
    sec = msec / 1000;
    min = sec / 60;
    sec = sec % 60;

    QString minute = min > 10 ? QString("%1").arg(min) : QString("0%1").arg(min);
    QString second = sec > 10 ? QString("%1").arg(sec) : QString("0%1").arg(sec);
    QString str = QString("%1:%2").arg(minute).arg(second);
    return str;
}
//上一首
void MainWindow::on_btn_prev_clicked()
{
    if (is_playing_flag && player->state() == QMediaPlayer::PlayingState) {
        player->stop();  // 停止当前播放
    }

    int count = ui->listWidget_2->count();
    if (count == 0) return;  // 防止空列表时出错

    int currentRow = ui->listWidget_2->currentRow();
    int newRow = currentRow; // 默认保持不变

    switch (currentMode) {
        case Sequential: // 顺序播放
            newRow = (currentRow == 0) ? (count - 1) : (currentRow - 1);
            break;
        case Shuffle: // 随机播放（不重复当前）
        {
            int randomRow;
            do {
                randomRow = qrand() % count;
            } while (randomRow == currentRow); // 避免重复当前歌曲
            newRow = randomRow;
            break;
        }
        case Single: // 单曲播放，上一曲仍然是自己
            newRow = currentRow;
            break;
        case SingleLoop: // 单曲循环，上一曲仍然是自己
            newRow = currentRow;
            break;
    }

    // 设置当前选中的行
    ui->listWidget_2->setCurrentRow(newRow);

    // 自动播放选中的歌曲
    play_selected_media(newRow);
}


//暂停/开始
void MainWindow::on_btn_pause_keep_clicked()
{
    QString keepIcon, pauseIcon;
    // 根据当前主题选择不同格式的图标
    if (currentTheme == LIGHT) {
        keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
        pauseIcon = ":/qic/images/pause.png";
    }
    else if(currentTheme==DARK){
        keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
        pauseIcon = ":/qic/svg/pause.svg";
    }
    else {
        if(isDarkColor(currentColor)){
            keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
            pauseIcon = ":/qic/svg/pause.svg";
        }
        else{
            keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
            pauseIcon = ":/qic/images/pause.png";
        }
    }

    if (pause_keep_flag == 0) {
        pause_keep_flag = 1;
        ui->btn_pause_keep->setIcon(QIcon(keepIcon));
        player->play();
    } else {
        pause_keep_flag = 0;
        ui->btn_pause_keep->setIcon(QIcon(pauseIcon));
        player->pause();
    }
}

// 下一首
void MainWindow::on_btn_next_clicked()
{
    if (is_playing_flag && player->state() == QMediaPlayer::PlayingState) {
        player->stop();  // 停止当前播放
    }

    int count = ui->listWidget_2->count();
    if (count == 0) return;  // 防止空列表时出错

    int currentRow = ui->listWidget_2->currentRow();
    int newRow = currentRow; // 默认保持不变

    switch (currentMode) {
        case Sequential: // 顺序播放
            newRow = (currentRow == count - 1) ? 0 : (currentRow + 1);
            break;
        case Shuffle: // 随机播放（不重复当前）
        {
            int randomRow;
            do {
                randomRow = qrand() % count;
            } while (randomRow == currentRow); // 避免重复当前歌曲
            newRow = randomRow;
            break;
        }
        case Single: // 单曲播放，下一曲仍然是自己
            newRow = currentRow;
            break;
        case SingleLoop: // 单曲循环，下一曲仍然是自己
            newRow = currentRow;
            break;
    }

    // 设置当前选中的行
    ui->listWidget_2->setCurrentRow(newRow);

    // 自动播放选中的歌曲
    play_selected_media(newRow);
}


//倍速
void MainWindow::on_btn_speed_clicked()
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

void MainWindow::play_selected_media(int row)
{
    // 双重保险：确保不会在无意义的情况下触发
    if (row < 0 || row >= ui->listWidget_2->count()) return;

    // 使用 QSignalBlocker 替代 blockSignals(true/false)，更安全
    const QSignalBlocker blocker(ui->listWidget_2); // 作用域内自动阻塞信号
    // 直接通过 item 获取数据，而非依赖行号
    if (!visibleRowToSourceRow.contains(row)) {
        qDebug() << "无效的可见行号：" << row;
        return;
    }
    int actualRow = visibleRowToSourceRow[row];
    //int actualRow = getCurrentVisibleRow();
    // 设置选中项（实际行号）
    QListWidgetItem *item = ui->listWidget_2->item(actualRow);
    ui->listWidget_2->setCurrentItem(item);
    ui->listWidget_2->setCurrentRow(actualRow);
    QString filePath = item->data(Qt::UserRole).toString();
    if (filePath.isEmpty() || !QFile::exists(filePath)) {
        qDebug() << "无效的文件路径：" << filePath;
        return;
    }

    // 如果正在播放同一文件且处于播放状态，无需重复操作
    if (player->media().canonicalUrl().toLocalFile() == filePath
        && player->state() == QMediaPlayer::PlayingState) {
        return;
    }

    // 停止当前播放并重置媒体
    player->stop();
    // player->setVideoOutput(static_cast<QVideoWidget*>(nullptr));
    // videoWidget->update();
    player->setMedia(QUrl::fromLocalFile(filePath));
    // player->setVideoOutput(videoWidget);
    // ui->label_title->setText(item ? item->text() : "null");
    // videoWidget->updateGeometry();
    // if(status==QM)
    // if(player->isVideoAvailable()){
    //         VideoPlay* vp=new VideoPlay(this,getPlayer());
    //         vp->show();
    //     }
    // videoLayout->invalidate();
    // videoLayout->activate();
    player->play();
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        //if (status == QMediaPlayer::LoadedMedia) { // 媒体加载完成
            // 此处执行延迟的逻辑（判断音视频、更新界面、切换歌曲后的操作）
            bool isVideo = player->isVideoAvailable();
            if (isVideo) {
                vp->show();
                qDebug()<<"video ok";
            } else {
                vp->hide();
                qDebug()<<"no video";
            }
            // 其他需要媒体就绪后执行的操作（如获取时长、更新进度条等）
        //}
    });
    // 确保先断开所有旧连接
    disconnectPlayerSignals();
    qDebug() << "select请求播放行号：" << row
             << "，实际项文本：" << (item ? item->text() : "null")
             << "，文件路径：" << filePath;
    // 根据播放模式连接信号（使用 Qt::UniqueConnection 防止重复连接）
    switch (currentMode) {
    case Sequential:
        connect(player, &QMediaPlayer::mediaStatusChanged,
                this, &MainWindow::playNextSequential, Qt::UniqueConnection);
        break;
    case Shuffle:
        connect(player, &QMediaPlayer::mediaStatusChanged,
                this, &MainWindow::playRandom, Qt::UniqueConnection);
        break;
    case SingleLoop:
        connect(player, &QMediaPlayer::mediaStatusChanged,
                this, &MainWindow::loopCurrentFile, Qt::UniqueConnection);
        break;
//    case ListLoop:
//        connect(player, &QMediaPlayer::mediaStatusChanged,
//                this, &MainWindow::loopPlaylist, Qt::UniqueConnection);
//        break;
    default: // Single 模式无需连接
        break;
    }
}



//音量改变
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    player->setVolume(value);
    ui->label_2->setText(QString::number(value));
    if (value > 0) {
        if (currentTheme == LIGHT) {
            ui->label->setStyleSheet("border-image: url(:/qic/images/voice_open.png);");
        }else {
            ui->label->setStyleSheet("border-image: url(:/qic/svg/voice_open.svg);");
        }
    }
    else if (value == 0) {
        ui->label->setStyleSheet("border-image: url(:/qic/images/voice_close.png);");
    }
}

void MainWindow::on_listWidget_2_currentTextChanged(const QString &currentText)
{
    // 阻止信号递归触发
    ui->listWidget_2->blockSignals(true);

    // 获取当前选中的项
    QListWidgetItem *item = ui->listWidget_2->currentItem();
    if (!item) {
        qDebug() << "错误: 当前选中项为空";
        ui->listWidget_2->blockSignals(false);
        return;
    }

    // 获取当前可见的行号
    int visibleRow = ui->listWidget_2->currentRow();
    // 转换为实际存储的行号
    int actualRow = visibleRowToSourceRow[visibleRow];
    if (actualRow < 0 || actualRow >= ui->listWidget_2->count()) {
        qDebug() << "错误: actualRow 越界";
        ui->listWidget_2->blockSignals(false);
        return;
    }

    // 获取文件路径
    QString filePath = ui->listWidget_2->item(actualRow)->data(Qt::UserRole).toString();
    if (filePath.isEmpty() || !QFileInfo::exists(filePath)) {
        qDebug() << "错误: 文件不存在 -> " << filePath;
        ui->listWidget_2->blockSignals(false);
        return;
    }

    qDebug() << "onlist正在播放 (行号:" << actualRow << ") -> " << filePath;

    // 设置媒体源并播放

    // player->setMedia(QUrl::fromLocalFile(filePath));
    // player->play();

    // player->setMedia(QUrl::fromLocalFile(filePath));
    // player->play();

    pause_keep_flag=1;
    QString keepIcon, pauseIcon;
    // 根据当前主题选择不同格式的图标
    if (currentTheme == LIGHT) {
        keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
    }
    else if(currentTheme==COLORFUL){
        if(isDarkColor(currentColor)){
            keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
        }
        else{
            keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
        }
    }
    else {
        keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
    }
    ui->btn_pause_keep->setIcon(QIcon(keepIcon));

    // 更新 UI 显示
    ui->label_title->setText(item ? item->text() : "null");

    // 恢复信号触发
    ui->listWidget_2->blockSignals(false);
}


void MainWindow::update_position()
{
    if (player->duration() > 0) { // 避免除零错误
        int progress = int(((player->position() * 1.0) / (player->duration() * 1.0)) * 100);
        ui->horizontalSlider_2->setValue(progress);
    }
    ui->label_progress->setText(QString("%1/%2")
                                    .arg(get_time_str(player->position()))
                                    .arg(get_time_str(player->duration())));
    ui->label_progress->adjustSize();
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    player->setPosition(qint64(player->duration() * (position * 1.0 / 100)));
}

//导入文件
void MainWindow::on_btn_open_folder_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(
        this,
        tr("选择媒体文件"),
        QDir::homePath(),
        tr("媒体文件 (*.mp3 *.wav *.mp4 *.avi *.mkv)")
    );

    if (fileNames.isEmpty()) {
        qDebug() << "没有选择任何文件";
        return;
    }

    static QSet<QString> addedFileNames; // 记录已添加的文件名

    for (const QString &filePath : fileNames) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();

        if (addedFileNames.contains(fileName)) {
            qDebug() << "文件名重复，已跳过：" << filePath;
            continue;
        }

        addedFileNames.insert(fileName);
        playListMap[fileName] = filePath;  // 更新 playListMap

        QListWidgetItem *item = new QListWidgetItem(fileName);
        item->setData(Qt::UserRole, filePath);  // 设置文件路径
        ui->listWidget_2->addItem(item);
        qDebug() << "添加文件：" << filePath;

        int visibleRow = 0;

        for (int sourceRow = 0; sourceRow < ui->listWidget_2->count(); ++sourceRow) {
            QListWidgetItem *item = ui->listWidget_2->item(sourceRow);
            // 记录可见项的映射
            visibleRowToSourceRow[visibleRow] = sourceRow;
            visibleRow++;
        }
        save_history();
    }
}

//bool MainWindow::eventFilter(QObject *watched, QEvent *event)
// {
//    if (watched == ui->widget && event->type() == QEvent::MouseMove) {
//            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
//            int y = mouseEvent->pos().y();
//            int widgetHeight = ui->widget->height();

//            // 当鼠标接近底部边缘时，显示控制框
//            if (y > widgetHeight - 20) {
//                control_frame->show();
//            } else {
//                control_frame->hide();
//            }
//        }
//        return QObject::eventFilter(watched, event);
// }

// void MainWindow::on_btn_fullscreen_clicked() {
//    if (!videoWidget) return;

//    if (isFullScreenMode) return; // 防止重复创建

//    FullScreenWindow* fsc = new FullScreenWindow(this);
//    fsc->setAttribute(Qt::WA_DeleteOnClose); // 确保关闭时自动删除
//    connect(fsc, &FullScreenWindow::destroyed, [this]() {
//        isFullScreenMode = false;
//    });
//    fsc->showFullScreen();
//    isFullScreenMode = true;
// }



void MainWindow::on_exit_fullscreen()
{

   qDebug()<<"on_exit_fullscreen";
   QLayout *existingLayout = ui->VideoWidget->layout();
   if (existingLayout) {
       existingLayout->addWidget(videoWidget);
   }
   videoWidget->show();
   isFullScreenMode = false;
   player->pause();
   videoWidget->setParent(this);
   player->play();
   videoWidget->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Space: // 空格键：播放/暂停
            on_btn_pause_keep_clicked();
            break;

        case Qt::Key_Left: // 左箭头：快退4秒
            player->setPosition(qMax(qint64(0), player->position() - 4000));
            break;

        case Qt::Key_Right: // 右箭头：快进4秒
            player->setPosition(qMin(player->duration(), player->position() + 4000));
            break;
        default:
            QMainWindow::keyPressEvent(event); // 让父类处理其他按键
    }

}


// 关闭窗口时保存历史记录
void MainWindow::closeEvent(QCloseEvent *event)
{
    save_history();
    event->accept();
}
void MainWindow::save_history()
{
    QSettings settings("MyApp", "MusicPlayer");
    QStringList historyList;

    for (int i = 0; i < ui->listWidget_2->count(); ++i) {
        QListWidgetItem *item = ui->listWidget_2->item(i);
        QString filename = item->text();
        QString filepath = item->data(Qt::UserRole).toString();

        historyList.append(filename + ";" + filepath);
    }

    settings.setValue("history", historyList);
}


// 保存 listWidget 历史记录到 QSettings
void MainWindow::add_to_history(const QString &filepath)
{
    QStringList history = settings->value("history").toStringList();

    // 避免重复存储
    if (!history.contains(filepath)) {
        history.append(filepath);
        settings->setValue("history", history);
        settings->sync();  // 立即保存
    }

    // 仅显示文件名，但内部存储完整路径
    QListWidgetItem *item = new QListWidgetItem(QFileInfo(filepath).fileName());
    item->setData(Qt::UserRole, filepath);
    ui->listWidget_2->addItem(item);
}

// 加载历史记录
void MainWindow::load_history()
{
    QSettings settings("MyApp", "MusicPlayer");
    QStringList historyList = settings.value("history").toStringList();

    for (const QString &historyItem : historyList) {
        QStringList itemParts = historyItem.split(";");
        if (itemParts.size() == 2) {
            QString filename = itemParts[0];
            QString filepath = itemParts[1];

            QListWidgetItem *item = new QListWidgetItem(filename);
            item->setData(Qt::UserRole, filepath); // 关键：存储文件路径
            ui->listWidget_2->addItem(item);
        }
    }
}



// 搜索框功能：根据搜索内容筛选 listWidget
void MainWindow::search_list(const QString &text)
{
    // for (int i = 0; i < ui->listWidget->count(); ++i) {
    //     QListWidgetItem *item = ui->listWidget->item(i);
    //     bool match = item->text().contains(text, Qt::CaseInsensitive);
    //     item->setHidden(!match);
    // }
    visibleRowToSourceRow.clear(); // 清空旧映射
    int visibleRow = 0;

    for (int sourceRow = 0; sourceRow < ui->listWidget_2->count(); ++sourceRow) {
        QListWidgetItem *item = ui->listWidget_2->item(sourceRow);
        bool match = item->text().contains(text, Qt::CaseInsensitive);
        item->setHidden(!match);

        // 记录可见项的映射
        if (match) {
            visibleRowToSourceRow[visibleRow] = sourceRow;
            visibleRow++;
        }
    }
}
//删除
void MainWindow::delete_item(QListWidgetItem *item)
{
    item = ui->listWidget_2->currentItem();
    if (!item) {
        qDebug() << "错误: 没有选中任何项，无法删除";
        return;
    }

    QString fileName = item->text().trimmed(); // 确保没有多余空格
    qDebug() << "尝试删除：" << fileName;
    qDebug() << "当前列表中的文件：";
    for (auto it = playListMap.begin(); it != playListMap.end(); ++it) {
        qDebug() << "文件名：" << it.key();
    }
    if (!playListMap.contains(fileName)) {
        qDebug() << "错误: 找不到 " << fileName;
    }

    QString filePath = playListMap[fileName];

    // 如果正在播放这个文件，就先停止播放
    if (is_playing_flag && player->media().canonicalUrl().toLocalFile() == filePath) {
        qDebug() << "正在播放该文件，停止播放";
        player->stop();
        is_playing_flag = false;
    }

    // 删除 map 中的路径
    playListMap.remove(fileName);
    qDebug() << "已从 playListMap 删除：" << fileName;

    // 删除 UI 中的 listWidget 项
    delete ui->listWidget_2->takeItem(ui->listWidget_2->row(item));
    qDebug() << "已从 UI 删除：" << fileName;
    save_history();
}

// 右键菜单
void MainWindow::show_context_menu(const QPoint &pos)
{
    QListWidgetItem *item = ui->listWidget_2->itemAt(pos);
        if (item) {
            QMenu contextMenu(this);
            QAction *deleteAction = contextMenu.addAction("删除历史记录");

            // 删除功能连接到 deleteItem
            connect(deleteAction, &QAction::triggered, this, [this, item]() {
                delete_item(item);
            });

            contextMenu.exec(ui->listWidget_2->mapToGlobal(pos));
        }
}

void MainWindow::disconnectPlayerSignals()
{
    disconnect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::playNextSequential);
    disconnect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::playRandom);
    disconnect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::loopCurrentFile);
    //disconnect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::loopPlaylist);
}

//void MainWindow::restoreVideoWidgetLayout(QVideoWidget *widget)
// {
//     ui->widget->layout()->addWidget(widget);
//     widget->show();
// }

QString MainWindow::loadStylesheet(const QString &templatePath, const QMap<QString, QString> &colors)
{

    QFile file(templatePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }
    QTextStream in(&file);
    QString templateContent = in.readAll();
    file.close();

    for (auto it = colors.begin(); it != colors.end(); ++it) {
        templateContent.replace("${" + it.key() + "}", it.value());
    }
    return templateContent;
}

//主题切换
void MainWindow::on_comboBox_theme_currentIndexChanged(int index)
{
    QString path;
    switch(index)
    {
    case LIGHT:
        path = ":/qic/styles/light.qss";
        qDebug() << "light";
        currentTheme = LIGHT;
        ui->btn_prev->setIcon(QIcon(":qic/images/prev.png"));
        ui->btn_next->setIcon(QIcon(":qic/images/next.png"));
        //ui->btn_pause_keep->setIcon(QIcon(":qic/images/pause.png"));
        ui->label->setStyleSheet("border-image: url(:/qic/svg/voice_open.png);");
        break;
    case DARK:
        path = ":/qic/styles/dark.qss";
        qDebug() << "Dark";
        currentTheme = DARK;
        ui->btn_prev->setIcon(QIcon(":qic/svg/prev.svg"));
        ui->btn_next->setIcon(QIcon(":qic/svg/next.svg"));
        //ui->btn_pause_keep->setIcon(QIcon(":qic/svg/pause.svg"));
        ui->label->setStyleSheet("border-image: url(:/qic/svg/voice_open.svg);");
        break;
    case COLORFUL:
        selectedColor=QColorDialog::getColor(Qt::white,this,"ChooseYourColor",QColorDialog::ShowAlphaChannel|QColorDialog::DontUseNativeDialog);
        //qDebug()<<selectedColor.name().toStdString().c_str();
        currentColor=selectedColor;
        // QMap<QString,QString> colors;
        colors["color"]=selectedColor.name();
        colors["window_background_color"]=selectedColor.name();
        colors["text_color"]=getContrastColor(selectedColor).name();
        //botton's color can be darker to distinguish
        colors["button_color"]=adjustButtonColor(selectedColor).name();
        qDebug()<<colors["color"]<<"    "<<
            colors["window_background_color"]<<"     "<<
            colors["text_color"]<<"     "  <<colors["button_color"];
        stylesheet =loadStylesheet(":/qic/styles/colorful.template.qss",colors);
        path=":/qic/styles/colorful.template.qss";
        qApp->setStyleSheet(stylesheet);
        currentTheme = COLORFUL;
        if(isDarkColor(currentColor)){
            ui->btn_prev->setIcon(QIcon(":qic/svg/prev.svg"));
            ui->btn_next->setIcon(QIcon(":qic/svg/next.svg"));
            //ui->btn_pause_keep->setIcon(QIcon(":qic/svg/pause.svg"));
        }
        else{
            ui->btn_prev->setIcon(QIcon(":qic/images/prev.png"));
            ui->btn_next->setIcon(QIcon(":qic/images/next.png"));
            //ui->btn_pause_keep->setIcon(QIcon(":qic/images/pause.png"));
        }
        ui->label->setStyleSheet("border-image: url(:/qic/svg/voice_open.svg);");
        break;
    case FOLLOW_EMOTION:
        modelPath = ":qic/colorPre/followModel.pkl";
        emotion_to_theme(modelPath);
        break;
    case REVERSE_EMOTION:
        modelPath = ":qic/colorPre/reverseModel.pkl";
        emotion_to_theme(modelPath);
        break;
    case AUTO_EMOTION:
        modelPath = ":qic/colorPre/model.pkl";
        emotion_to_theme(modelPath);
        break;
    }
    qDebug() << "Trying to open file:" << path;
    if(index!=COLORFUL && index!=FOLLOW_EMOTION){
        QFile file(path);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QString styleSheet = file.readAll();
            qApp->setStyleSheet(styleSheet);
            file.close();
        } else {
            qDebug() << "Failed to open file:" << path << "Error:" << file.errorString();
        }
    }

    QString keepIcon, pauseIcon;
    // 根据当前主题选择不同格式的图标
    if (currentTheme == LIGHT) {
        keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
        pauseIcon = ":/qic/images/pause.png";
    }
    else if(currentTheme==DARK){
        keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
        pauseIcon = ":/qic/svg/pause.svg";
    }
    else if(currentTheme==COLORFUL){
        if(isDarkColor(currentColor)){
            keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
            pauseIcon = ":/qic/svg/pause.svg";
        }
        else{
            keepIcon = ":/qic/images/keep.png";   // LIGHT 主题用 PNG
            pauseIcon = ":/qic/images/pause.png";
        }
    }
    else {
        keepIcon = ":/qic/svg/keep.svg";   // DARK 主题用 SVG
        pauseIcon = ":/qic/svg/pause.svg";
    }
    if (pause_keep_flag == 0) {
        ui->btn_pause_keep->setIcon(QIcon(pauseIcon));
    } else {
        ui->btn_pause_keep->setIcon(QIcon(keepIcon));
    }
}

//情感分析
void MainWindow::process_audio_buffer_emotion(const QAudioBuffer &buffer)
{
    QAudioFormat format = buffer.format();

    if (format.sampleType() == QAudioFormat::Float) {
        // 直接处理 Float 格式
        int sampleCount = buffer.frameCount();
        const float *data = buffer.constData<float>();

        for (int i = 0; i < sampleCount; ++i) {
            pcmSamples.append(data[i]);
        }
    }
    else if (format.sampleType() == QAudioFormat::SignedInt) {
        // 处理 Int16 或 Int32 格式
        int sampleCount = buffer.frameCount();
        if (format.sampleSize() == 16) {
            // 16-bit PCM 数据
            const qint16 *data = buffer.constData<qint16>();
            for (int i = 0; i < sampleCount; ++i) {
                pcmSamples.append(data[i] / 32768.0f);  // 归一化到 [-1, 1]
            }
        }
        else if (format.sampleSize() == 32) {
            // 32-bit PCM 数据
            const qint32 *data = buffer.constData<qint32>();
            for (int i = 0; i < sampleCount; ++i) {
                pcmSamples.append(data[i] / 2147483648.0f);  // 归一化到 [-1, 1]
            }
        }
        else {
            qDebug() << "不支持的 PCM 采样大小：" << format.sampleSize();
        }
    }
    else {
        qDebug() << "不支持的音频格式！";
    }

   // qDebug() << "已采样：" << pcmSamples.size() << " 个样本";
}



void MainWindow::on_btn_emotion_clicked()
{
    QSettings settings("MyApp", "MusicPlayer");
    // 确保有足够的 PCM 数据
    if (pcmSamples.isEmpty()) {
        QMessageBox::warning(this, "情感分析", "未检测到足够的音频数据！");
        return;
    }

    // 创建 VokaturiVoice 实例
    double sample_rate = 44100.0;
    VokaturiVoice voice = VokaturiVoice_create(sample_rate, pcmSamples.size(), 0);

    if (!voice) {
        QMessageBox::critical(this, "情感分析", "无法创建 VokaturiVoice 实例！");
        return;
    }

    // 填充数据
    VokaturiVoice_fill_float32array(voice, pcmSamples.size(), pcmSamples.data());

    // 进行情感分析
    VokaturiQuality quality;
    VokaturiEmotionProbabilities emotion;
    VokaturiVoice_extract(voice, &quality, &emotion);

    // 释放资源
    VokaturiVoice_destroy(voice);

    // 清空缓冲区，准备下一次分析
    pcmSamples.clear();

    // 生成情感分析结果
    QString result;
    if (quality.valid) {
        result = QString("情感分析结果：\n")
                 + QString("中性：%1%\n").arg(emotion.neutrality * 100, 0, 'f', 2)
                 + QString("快乐：%1%\n").arg(emotion.happiness * 100, 0, 'f', 2)
                 + QString("悲伤：%1%\n").arg(emotion.sadness * 100, 0, 'f', 2)
                 + QString("愤怒：%1%\n").arg(emotion.anger * 100, 0, 'f', 2)
                 + QString("恐惧：%1%\n").arg(emotion.fear * 100, 0, 'f', 2);
        settings.setValue("emotion/neutrality", emotion.neutrality);
        settings.setValue("emotion/happiness", emotion.happiness);
        settings.setValue("emotion/sadness", emotion.sadness);
        settings.setValue("emotion/anger", emotion.anger);
        settings.setValue("emotion/fear", emotion.fear);
    } else {
        result = "未检测到有效的情感数据。";
    }

    // 显示分析结果
    QMessageBox::information(this, "情感分析结果", result);
    update_emo_rank();
}

void MainWindow::emotion_to_theme(const QString &modelPath)
{
    // 读取当前存储的情绪数据
    QStringList emotionHistory = settings->value("emotion/history").toStringList();
    float neutrality = settings->value("emotion/neutrality", 0.0).toFloat();
    float happiness = settings->value("emotion/happiness", 0.0).toFloat();
    float sadness = settings->value("emotion/sadness", 0.0).toFloat();
    float anger = settings->value("emotion/anger", 0.0).toFloat();
    float fear = settings->value("emotion/fear", 0.0).toFloat();

    qDebug() << "加载的情绪数据：" << neutrality << happiness << sadness << anger << fear;
    // 把情绪数据转换成字符串格式，空格分隔
    QString emotionStr = QString("%1 %2 %3 %4 %5")
                             .arg(neutrality)
                             .arg(happiness)
                             .arg(sadness)
                             .arg(anger)
                             .arg(fear);
    emotionHistory.append(emotionStr);
    // 限制存储数量，保留最近 20 条
    while (emotionHistory.size() > 20) {
        emotionHistory.removeFirst();  // 删除最早的记录
    }
    // 将更新后的列表存回 QSettings
    settings->setValue("emotion/history", emotionHistory);
    settings->sync();
    qDebug() << "modle路径：" << modelPath;
    // 用 QProcess 调用 Python
    QProcess process;
    QString program = "python3";  // 或 "python" 视系统而定

    QString scriptPath = extractResourceToTempFile(":qic/colorPre/colorChoose.py");
    QString model_path=extractResourceToTempFile(modelPath);
    QStringList arguments;
    arguments << scriptPath
              << QString::number(neutrality,'f',2)
              << QString::number(happiness,'f',2)
              << QString::number(sadness,'f',2)
              << QString::number(anger,'f',2)
              << QString::number(fear,'f',2)
            <<model_path;

    process.start(program, arguments);
    process.waitForFinished();

    // 获取 Python 输出的 RGB 值
    QString outputColor = process.readAllStandardOutput().trimmed(); // 可能是 "250 235 215"
    QString errorMsg = process.readAllStandardError().trimmed(); // 捕获错误信息
    qDebug() << "color:" << outputColor;
    qDebug() << "error:" << errorMsg;  // 打印错误信息
    // 检查输出是否符合 RGB 格式
    QStringList rgbValues = outputColor.split(" ");
    if (rgbValues.size() != 3) {
        QMessageBox::warning(this, "错误", "未能正确获取颜色！");
        return;
    }

    // 转换 RGB 数值
    bool ok1, ok2, ok3;
    int r = rgbValues[0].toInt(&ok1);
    int g = rgbValues[1].toInt(&ok2);
    int b = rgbValues[2].toInt(&ok3);

    if (!ok1 || !ok2 || !ok3) {
        QMessageBox::warning(this, "错误", "颜色转换失败！");
        return;
    }

    // 转换为十六进制颜色
    QString hexColor = QString("#%1%2%3")
                           .arg(r, 2, 16, QChar('0'))
                           .arg(g, 2, 16, QChar('0'))
                           .arg(b, 2, 16, QChar('0'))
                           .toUpper();

    // 更新窗口背景颜色
    currentColor=QColor(hexColor);
    selectedColor=QColor(hexColor);
    colors["color"]=selectedColor.name();
    colors["window_background_color"]=selectedColor.name();
    colors["text_color"]=getContrastColor(selectedColor).name();
    //botton's color can be darker to distinguish
    colors["button_color"]=adjustButtonColor(selectedColor).name();

    qDebug()<<colors["color"]<<"    "<<
        colors["window_background_color"]<<"     "<<
        colors["text_color"]<<"     "  <<colors["button_color"];


    stylesheet =loadStylesheet(":/qic/styles/colorful.template.qss",colors);
    qApp->setStyleSheet(stylesheet);
    if(isDarkColor(currentColor)){
        ui->btn_prev->setIcon(QIcon(":qic/svg/prev.svg"));
        ui->btn_next->setIcon(QIcon(":qic/svg/next.svg"));
    }
    else{
        ui->btn_prev->setIcon(QIcon(":qic/images/prev.png"));
        ui->btn_next->setIcon(QIcon(":qic/images/next.png"));
    }

    // 最终的情绪分析结果
    outputColor = QString("\n\n预测的颜色（RGB）：%1").arg(outputColor);
    outputColor += QString("\n预测的颜色（Hex）：%1").arg(hexColor);
}

//排行榜
void MainWindow::update_emo_rank()
{
    ui->emo_listwidget->clear();

    // 读取QSettings中的情绪数据
    QSettings settings("MyApp", "MusicPlayer");
    QMap<QString, float> emotionScores;
    emotionScores["中性"] = settings.value("emotion/neutrality", 0.0).toFloat();
    emotionScores["快乐"] = settings.value("emotion/happiness", 0.0).toFloat();
    emotionScores["悲伤"] = settings.value("emotion/sadness", 0.0).toFloat();
    emotionScores["愤怒"] = settings.value("emotion/anger", 0.0).toFloat();
    emotionScores["恐惧"] = settings.value("emotion/fear", 0.0).toFloat();

    // 按值降序排序
    QList<QPair<QString, float>> sortedEmotions;
    for (auto it = emotionScores.begin(); it != emotionScores.end(); ++it) {
        sortedEmotions.append(qMakePair(it.key(), it.value()));
    }
    std::sort(sortedEmotions.begin(), sortedEmotions.end(), [](const QPair<QString, float> &a, const QPair<QString, float> &b) {
        return a.second > b.second;
    });

    // 定义情绪对应颜色
    QMap<QString, QColor> emotionColors;
    emotionColors["快乐"] = QColor(0, 191, 255);
    emotionColors["中性"] = QColor(255, 224, 189);
    emotionColors["悲伤"] = QColor(100, 149, 237);
    emotionColors["愤怒"] = QColor(220, 20, 60);
    emotionColors["恐惧"] = QColor(148, 0, 211);
    QMap<QString, QString> emotionEmojis;
    emotionEmojis["快乐"] = "😊";
    emotionEmojis["中性"] = "😐";
    emotionEmojis["悲伤"] = "😢";
    emotionEmojis["愤怒"] = "😠";
    emotionEmojis["恐惧"] = "😱";

    for (int rank = 0; rank < sortedEmotions.size(); ++rank) {
        QString emotion = sortedEmotions[rank].first;
        float score = sortedEmotions[rank].second;  // 0.0 ~ 1.0

        QString percentText = QString::number(score * 100.0, 'f', 2) + "%";
        QString emoji = emotionEmojis.value(emotion, "");
        QString finalText = QString("%1. %2 %3  %4").arg(rank + 1).arg(emoji).arg(emotion).arg(percentText);

        QListWidgetItem *item = new QListWidgetItem;
        QWidget *messageWidget = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout(messageWidget);
        layout->setContentsMargins(10, 2, 10, 2);

        QLabel *label = new QLabel(finalText);
        label->setWordWrap(false);
        label->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        label->setTextInteractionFlags(Qt::TextSelectableByMouse);
        label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        QFontMetrics fm(label->font());
        int textWidth = fm.horizontalAdvance(finalText) + 20;  // 文字宽度 + padding

        int maxBubbleWidth = 400;
        int minBubbleWidth = 100;
        float scoreRatio = score;  // 0~1
        int dynamicWidth = minBubbleWidth + (maxBubbleWidth - minBubbleWidth) * scoreRatio;

        int finalWidth = std::max(textWidth, dynamicWidth);
        label->setMinimumWidth(finalWidth);
        label->setMaximumWidth(finalWidth);
        // 计算动态宽度
        //int bubbleWidth = qBound(50, static_cast<int>(score * maxBubbleWidth), maxBubbleWidth);

        QColor bgColor = emotionColors.value(emotion, QColor(200, 200, 200));
        label->setStyleSheet(QString("background-color: %1; color: black; border-radius: 8px; padding:3px;")
                                 .arg(bgColor.name()));
        //label->setFixedWidth(bubbleWidth);

        // 统一固定行高

        int rowHeight = fm.height() + 10;
        label->setFixedHeight(rowHeight);

        layout->addWidget(label, 0, Qt::AlignLeft);
        messageWidget->setLayout(layout);
        messageWidget->setFixedHeight(rowHeight);

        item->setSizeHint(QSize(0, rowHeight));

        ui->emo_listwidget->addItem(item);
        ui->emo_listwidget->setItemWidget(item, messageWidget);
    }
}

//收缩框
// void MainWindow::on_btn_shrink_expand_clicked()
// {
//     // 获取 QSplitter
//     QSplitter *splitter = findChild<QSplitter *>("splitter"); // 把"splitter_name"换成你的QSplitter对象名称

//     if (!splitter) return;  // 防止获取失败

//     // 获取当前 splitter 里两个部分的大小
//     QList<int> sizes = splitter->sizes();

//     // 记录 right_widget 的初始宽度（你可以调整这个值）
//     static int initialWidth = sizes[1] > 0 ? sizes[1] : 200;

//     if (sizes[1] > 0) {  // right_widget 处于展开状态
//         sizes[1] = 0;  // 收缩 right_widget
//         ui->btn_shrink_expand->setText("<");  // 改为“展开”状态
//     } else {  // right_widget 处于收缩状态
//         sizes[1] = initialWidth;  // 恢复到原来的宽度
//         ui->btn_shrink_expand->setText(">");  // 改为“收缩”状态
//     }

//     // 设置 splitter 的新大小
//     splitter->setSizes(sizes);
// }

// 点击按钮后启动 WebSocket 连接
void MainWindow::on_btn_voice_to_text_toggled(bool checked) {
    // if (checked) {
    //     // 开启字幕
    //     start_voice_to_text();
    // } else {
    //     // 关闭字幕，清除文本
    //     ui->textEdit_subtitles->clear();
    // }
}

void MainWindow::start_voice_to_text() {
    // int visibleRow = ui->listWidget->currentRow();
    // int actualRow = visibleRowToSourceRow[visibleRow];
    // QString filePath = ui->listWidget->item(actualRow)->data(Qt::UserRole).toString();

    // if (filePath.isEmpty()) {
    //     qDebug() << "No file path provided!";
    //     return;
    // }

    // QString program = "python3";
    // QStringList arguments;
    // QString starPath=extractResourceToTempFile(":/qic/star.py");
    // arguments << starPath << filePath;
    // arguments << starPath << filePath;

    // QProcess *process = new QProcess(this);

    // // 监听标准输出，实时追加到 textEdit_subtitles
    // connect(process, &QProcess::readyReadStandardOutput, [=]() {
    //     QByteArray output = process->readAllStandardOutput();
    //     QString outputText = QString::fromUtf8(output);
    //     ui->textEdit_subtitles->setPlainText(outputText);
    // });

    // // 监听标准错误，输出错误信息
    // connect(process, &QProcess::readyReadStandardError, [=]() {
    //     QByteArray errorOutput = process->readAllStandardError();
    //     QString errorText = QString::fromUtf8(errorOutput);
    //     qDebug() << "Error: " << errorText;
    // });

    // // 进程结束后自动清理
    // connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
    //         process, &QProcess::deleteLater);

    // // 启动 Python 进程
    // process->start(program, arguments);

    // if (!process->waitForStarted()) {
    //     qDebug() << "Error: Could not start Python script.";
    //     return;
    // }
}

bool MainWindow::isDarkColor(const QColor &color)
{
    // 人眼对RGB的敏感度权重不同
    int brightness = (color.red() * 299 + color.green() * 587 + color.blue() * 114) / 1000;
    return brightness < 150; // 阈值可根据需求调整（范围0-255）
}

QColor MainWindow::getContrastColor(const QColor &baseColor)
{
    return isDarkColor(baseColor) ? Qt::white : Qt::black;
}

QColor MainWindow::adjustButtonColor(const QColor &baseColor)
{
    if (isDarkColor(baseColor)) {
        // 暗色主题：按钮比原色更亮（参数可调）
        return baseColor.lighter(200); // 300%亮度
    } else {
        // 亮色主题：按钮比原色更暗
        return baseColor.darker(200); // 降低亮度
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
        dVal=ev->globalPos()-pos();
        isDrag=1;
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(isDrag){
        move((ev->globalPos()-dVal).toPoint());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    isDrag=0;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    btn_close->move(width()-btn_close->width()-5,5);
    btn_max->move(btn_close->x()-btn_max->width()-5,5);
    btn_min->move(btn_max->x()-btn_min->width()-5,5);

    btn_close->raise();
    btn_min->raise();
    btn_max->raise();
}
void MainWindow::on_fullscreen_btn_clicked()
{
    if (!videoWidget) return;

    if (isFullScreenMode) return; // 防止重复创建

    FullScreenWindow* fsc = new FullScreenWindow(this);
    fsc->setAttribute(Qt::WA_DeleteOnClose); // 确保关闭时自动删除
    connect(fsc, &FullScreenWindow::destroyed, [this]() {
        isFullScreenMode = false;
    });
    fsc->showFullScreen();
    isFullScreenMode = true;
}

// 将 Qt 资源文件提取到临时文件并返回临时文件路径
QString MainWindow::extractResourceToTempFile(const QString &resourcePath)
{
    QTemporaryFile* tempFile = new QTemporaryFile;
    if (tempFile->open()) {
        QFile resourceFile(resourcePath);
        if (resourceFile.open(QIODevice::ReadOnly)) {
            tempFile->write(resourceFile.readAll());
            resourceFile.close();
            tempFile->close();
            // 设置文件权限为可读
            QFileInfo fileInfo(tempFile->fileName());
            QFile::setPermissions(tempFile->fileName(), fileInfo.permissions() | QFile::ReadUser);
            return tempFile->fileName();
        } else {
            qDebug() << "无法打开资源文件: " << resourceFile.errorString();
            delete tempFile;
        }
    } else {
        qDebug() << "无法创建临时文件: " << tempFile->errorString();
        delete tempFile;
    }
    return "";
}


void MainWindow::on_pushButton_clicked()
{
    // 停止当前播放的文件（如果有）
    if (is_playing_flag) {
        qDebug() << "停止播放并清空列表";
        player->stop();
        is_playing_flag = false;
    }

    // 清空 playListMap
    playListMap.clear();
    qDebug() << "已从 playListMap 清空所有项";

    // 清空 UI 中的所有项
    ui->listWidget_2->clear();
    qDebug() << "已从 UI 清空所有项";
    save_history();
}

void MainWindow::on_btn_chat_clicked()
{
    // 如果聊天窗口还没创建，就创建
    if (!chatDock) {
        chatDock = new ChatWindow(this);
        chatDock->setFloating(true);  // 让 DockWidget 一开始就是浮动的
        // 根据主窗口比例设置合理大小
        QSize mainSize = this->size();
        int w = mainSize.width() * 0.6;
        int h = mainSize.height() * 0.6;
        chatDock->resize(w, h);
    }

    // 切换显示/隐藏状态
    if (chatDock->isVisible()) {
        chatDock->hide();
    } else {
        chatDock->show();
        chatDock->raise();  // 保证显示在最上层
    }
}

void MainWindow::on_search_but_clicked()
{
    ui->RU_stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btn_setting_clicked()
{
    SettingDialog* sd=new SettingDialog(this);
    sd->exec();
}

