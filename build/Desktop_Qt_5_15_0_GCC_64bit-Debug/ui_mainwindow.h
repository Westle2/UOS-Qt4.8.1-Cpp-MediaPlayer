/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QWidget *mainUpperWidget;
    QHBoxLayout *horizontalLayout_8;
    QWidget *funcWidget;
    QVBoxLayout *verticalLayout;
    QLabel *FuncLabel;
    QWidget *emo_Widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_emotion;
    QLabel *emo_Label;
    QWidget *Setting_Widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_setting;
    QLabel *setting_Label;
    QWidget *chat_Widget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_chat;
    QLabel *chat_Label;
    QSpacerItem *verticalSpacer;
    QWidget *RU_Widget;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *RU_stackedWidget;
    QWidget *Mainpage;
    QWidget *searchWidget;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *search_box;
    QPushButton *search_but;
    QLabel *CoolTitle;
    QLabel *label_4;
    QWidget *Search_resPage;
    QVBoxLayout *verticalLayout_3;
    QWidget *researchWidget;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *research_box;
    QPushButton *research_but;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QListWidget *listWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_7;
    QWidget *right_widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *LIBRARY_label;
    QPushButton *btn_open_folder;
    QPushButton *pushButton;
    QListWidget *listWidget_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *EMO_label;
    QListWidget *emo_listwidget;
    QWidget *cntWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_prev;
    QPushButton *btn_pause_keep;
    QPushButton *btn_next;
    QSlider *horizontalSlider_2;
    QLabel *label_progress;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *unused;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox_theme;
    QWidget *VideoWidget;
    QPushButton *btn_shrink_expand;
    QComboBox *comboBox_playMode;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_3;
    QTextEdit *textEdit_subtitles;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_speed;
    QPushButton *fullscreen_btn;
    QCheckBox *btn_voice_to_text;
    QFrame *line;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1336, 1124);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"border-radius:30px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        mainUpperWidget = new QWidget(centralwidget);
        mainUpperWidget->setObjectName(QString::fromUtf8("mainUpperWidget"));
        mainUpperWidget->setStyleSheet(QString::fromUtf8("#mainUpperWidget{\n"
"border-top-right-radius:30px;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(mainUpperWidget);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        funcWidget = new QWidget(mainUpperWidget);
        funcWidget->setObjectName(QString::fromUtf8("funcWidget"));
        verticalLayout = new QVBoxLayout(funcWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FuncLabel = new QLabel(funcWidget);
        FuncLabel->setObjectName(QString::fromUtf8("FuncLabel"));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        FuncLabel->setFont(font);
        FuncLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(FuncLabel);

        emo_Widget = new QWidget(funcWidget);
        emo_Widget->setObjectName(QString::fromUtf8("emo_Widget"));
        horizontalLayout = new QHBoxLayout(emo_Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_emotion = new QPushButton(emo_Widget);
        btn_emotion->setObjectName(QString::fromUtf8("btn_emotion"));
        btn_emotion->setMaximumSize(QSize(50, 50));
        btn_emotion->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qic/svg/emotion.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_emotion->setIcon(icon);
        btn_emotion->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(btn_emotion);

        emo_Label = new QLabel(emo_Widget);
        emo_Label->setObjectName(QString::fromUtf8("emo_Label"));
        emo_Label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(emo_Label);


        verticalLayout->addWidget(emo_Widget);

        Setting_Widget = new QWidget(funcWidget);
        Setting_Widget->setObjectName(QString::fromUtf8("Setting_Widget"));
        horizontalLayout_2 = new QHBoxLayout(Setting_Widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_setting = new QPushButton(Setting_Widget);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setMaximumSize(QSize(50, 50));
        btn_setting->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qic/images/setting_Light.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_setting->setIcon(icon1);
        btn_setting->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(btn_setting);

        setting_Label = new QLabel(Setting_Widget);
        setting_Label->setObjectName(QString::fromUtf8("setting_Label"));
        setting_Label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(setting_Label);


        verticalLayout->addWidget(Setting_Widget);

        chat_Widget = new QWidget(funcWidget);
        chat_Widget->setObjectName(QString::fromUtf8("chat_Widget"));
        horizontalLayout_9 = new QHBoxLayout(chat_Widget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btn_chat = new QPushButton(chat_Widget);
        btn_chat->setObjectName(QString::fromUtf8("btn_chat"));
        btn_chat->setMaximumSize(QSize(50, 50));
        btn_chat->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qic/svg/Smile.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_chat->setIcon(icon2);
        btn_chat->setIconSize(QSize(50, 50));

        horizontalLayout_9->addWidget(btn_chat);

        chat_Label = new QLabel(chat_Widget);
        chat_Label->setObjectName(QString::fromUtf8("chat_Label"));
        chat_Label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(chat_Label);


        verticalLayout->addWidget(chat_Widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_8->addWidget(funcWidget);

        RU_Widget = new QWidget(mainUpperWidget);
        RU_Widget->setObjectName(QString::fromUtf8("RU_Widget"));
        RU_Widget->setMaximumSize(QSize(1100, 1100));
        RU_Widget->setStyleSheet(QString::fromUtf8("#RU_Widget{\n"
"border-top-right-radius:30px;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(RU_Widget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        RU_stackedWidget = new QStackedWidget(RU_Widget);
        RU_stackedWidget->setObjectName(QString::fromUtf8("RU_stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RU_stackedWidget->sizePolicy().hasHeightForWidth());
        RU_stackedWidget->setSizePolicy(sizePolicy);
        RU_stackedWidget->setMinimumSize(QSize(0, 500));
        RU_stackedWidget->setMaximumSize(QSize(1100, 500));
        QFont font1;
        font1.setBold(false);
        RU_stackedWidget->setFont(font1);
        RU_stackedWidget->setStyleSheet(QString::fromUtf8("#Mainpage{\n"
"			background:url(:/qic/images/action-3195378 1.png);\n"
"border-top-right-radius:30px;\n"
"\n"
"}"));
        Mainpage = new QWidget();
        Mainpage->setObjectName(QString::fromUtf8("Mainpage"));
        searchWidget = new QWidget(Mainpage);
        searchWidget->setObjectName(QString::fromUtf8("searchWidget"));
        searchWidget->setGeometry(QRect(20, 30, 274, 71));
        horizontalLayout_5 = new QHBoxLayout(searchWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        search_box = new QLineEdit(searchWidget);
        search_box->setObjectName(QString::fromUtf8("search_box"));
        search_box->setMinimumSize(QSize(200, 53));
        search_box->setMaximumSize(QSize(250, 53));
        search_box->setStyleSheet(QString::fromUtf8("#search_box{\n"
"		border-radius:10px;\n"
"		background-color:rgb(186, 189, 182);\n"
"}"));

        horizontalLayout_5->addWidget(search_box);

        search_but = new QPushButton(searchWidget);
        search_but->setObjectName(QString::fromUtf8("search_but"));
        search_but->setMinimumSize(QSize(50, 44));
        search_but->setMaximumSize(QSize(50, 50));
        search_but->setStyleSheet(QString::fromUtf8("#search_but{\n"
"background-color:transparent;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qic/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_but->setIcon(icon3);
        search_but->setIconSize(QSize(50, 50));

        horizontalLayout_5->addWidget(search_but);

        CoolTitle = new QLabel(Mainpage);
        CoolTitle->setObjectName(QString::fromUtf8("CoolTitle"));
        CoolTitle->setGeometry(QRect(840, 30, 171, 131));
        QFont font2;
        font2.setPointSize(32);
        font2.setBold(true);
        CoolTitle->setFont(font2);
        CoolTitle->setWordWrap(true);
        label_4 = new QLabel(Mainpage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(680, 180, 281, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_4->setFont(font3);
        RU_stackedWidget->addWidget(Mainpage);
        Search_resPage = new QWidget();
        Search_resPage->setObjectName(QString::fromUtf8("Search_resPage"));
        Search_resPage->setStyleSheet(QString::fromUtf8("#Search_resPage{\n"
"border-top-right-radius:30px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(Search_resPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        researchWidget = new QWidget(Search_resPage);
        researchWidget->setObjectName(QString::fromUtf8("researchWidget"));
        horizontalLayout_6 = new QHBoxLayout(researchWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        research_box = new QLineEdit(researchWidget);
        research_box->setObjectName(QString::fromUtf8("research_box"));
        research_box->setMinimumSize(QSize(250, 0));
        research_box->setMaximumSize(QSize(250, 53));
        research_box->setStyleSheet(QString::fromUtf8("#research_box{\n"
"		border-radius:10px;\n"
"		background-color:rgb(186, 189, 182);\n"
"}"));

        horizontalLayout_6->addWidget(research_box);

        research_but = new QPushButton(researchWidget);
        research_but->setObjectName(QString::fromUtf8("research_but"));
        research_but->setMinimumSize(QSize(50, 44));
        research_but->setMaximumSize(QSize(50, 50));
        research_but->setStyleSheet(QString::fromUtf8("#search_but{\n"
"background-color:transparent;\n"
"}"));
        research_but->setIcon(icon3);
        research_but->setIconSize(QSize(50, 50));

        horizontalLayout_6->addWidget(research_but);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(researchWidget);

        label_3 = new QLabel(Search_resPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font4;
        font4.setPointSize(15);
        label_3->setFont(font4);

        verticalLayout_3->addWidget(label_3);

        listWidget = new QListWidget(Search_resPage);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background: transparent\n"
""));

        verticalLayout_3->addWidget(listWidget);

        RU_stackedWidget->addWidget(Search_resPage);

        verticalLayout_6->addWidget(RU_stackedWidget);

        widget_3 = new QWidget(RU_Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        right_widget = new QWidget(widget_3);
        right_widget->setObjectName(QString::fromUtf8("right_widget"));
        right_widget->setAutoFillBackground(false);
        right_widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(right_widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        LIBRARY_label = new QLabel(right_widget);
        LIBRARY_label->setObjectName(QString::fromUtf8("LIBRARY_label"));
        LIBRARY_label->setFont(font);
        LIBRARY_label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(LIBRARY_label);

        btn_open_folder = new QPushButton(right_widget);
        btn_open_folder->setObjectName(QString::fromUtf8("btn_open_folder"));
        btn_open_folder->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(btn_open_folder);

        pushButton = new QPushButton(right_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        listWidget_2 = new QListWidget(right_widget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setStyleSheet(QString::fromUtf8("background: transparent\n"
""));

        verticalLayout_4->addWidget(listWidget_2);


        horizontalLayout_7->addWidget(right_widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        EMO_label = new QLabel(widget_2);
        EMO_label->setObjectName(QString::fromUtf8("EMO_label"));
        EMO_label->setFont(font);
        EMO_label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(EMO_label);

        emo_listwidget = new QListWidget(widget_2);
        emo_listwidget->setObjectName(QString::fromUtf8("emo_listwidget"));

        verticalLayout_7->addWidget(emo_listwidget);


        horizontalLayout_7->addWidget(widget_2);


        verticalLayout_6->addWidget(widget_3);


        horizontalLayout_8->addWidget(RU_Widget);


        verticalLayout_8->addWidget(mainUpperWidget);

        cntWidget = new QWidget(centralwidget);
        cntWidget->setObjectName(QString::fromUtf8("cntWidget"));
        horizontalLayout_4 = new QHBoxLayout(cntWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_title = new QLabel(cntWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8("min-width:150px;\n"
"max-width:200px;"));

        horizontalLayout_4->addWidget(label_title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btn_prev = new QPushButton(cntWidget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qic/svg/prev.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_prev->setIcon(icon4);
        btn_prev->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(btn_prev);

        btn_pause_keep = new QPushButton(cntWidget);
        btn_pause_keep->setObjectName(QString::fromUtf8("btn_pause_keep"));
        btn_pause_keep->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qic/svg/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause_keep->setIcon(icon5);
        btn_pause_keep->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(btn_pause_keep);

        btn_next = new QPushButton(cntWidget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qic/svg/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon6);
        btn_next->setIconSize(QSize(20, 20));
        btn_next->setAutoDefault(false);

        horizontalLayout_4->addWidget(btn_next);

        horizontalSlider_2 = new QSlider(cntWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_2);

        label_progress = new QLabel(cntWidget);
        label_progress->setObjectName(QString::fromUtf8("label_progress"));
        label_progress->setMinimumSize(QSize(63, 0));

        horizontalLayout_4->addWidget(label_progress);

        label = new QLabel(cntWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/qic/svg/voice_open.svg);"));

        horizontalLayout_4->addWidget(label);

        horizontalSlider = new QSlider(cntWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(100, 0));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider);

        label_2 = new QLabel(cntWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_8->addWidget(cntWidget);

        unused = new QWidget(centralwidget);
        unused->setObjectName(QString::fromUtf8("unused"));
        verticalLayout_5 = new QVBoxLayout(unused);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        comboBox_theme = new QComboBox(unused);
        comboBox_theme->setObjectName(QString::fromUtf8("comboBox_theme"));
        comboBox_theme->setAutoFillBackground(false);
        comboBox_theme->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButt"
                        "on:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227"
                        "\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217"
                        "\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}"));
        comboBox_theme->setEditable(false);
        comboBox_theme->setInsertPolicy(QComboBox::NoInsert);
        comboBox_theme->setIconSize(QSize(50, 50));

        verticalLayout_5->addWidget(comboBox_theme);

        VideoWidget = new QWidget(unused);
        VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(VideoWidget->sizePolicy().hasHeightForWidth());
        VideoWidget->setSizePolicy(sizePolicy1);
        VideoWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(VideoWidget);

        btn_shrink_expand = new QPushButton(unused);
        btn_shrink_expand->setObjectName(QString::fromUtf8("btn_shrink_expand"));
        btn_shrink_expand->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(btn_shrink_expand);

        comboBox_playMode = new QComboBox(unused);
        comboBox_playMode->setObjectName(QString::fromUtf8("comboBox_playMode"));
        comboBox_playMode->setStyleSheet(QString::fromUtf8("/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
" \n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButt"
                        "on:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}"));

        verticalLayout_5->addWidget(comboBox_playMode);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        line_3 = new QFrame(unused);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        textEdit_subtitles = new QTextEdit(unused);
        textEdit_subtitles->setObjectName(QString::fromUtf8("textEdit_subtitles"));

        verticalLayout_2->addWidget(textEdit_subtitles);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_speed = new QPushButton(unused);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(btn_speed);

        fullscreen_btn = new QPushButton(unused);
        fullscreen_btn->setObjectName(QString::fromUtf8("fullscreen_btn"));
        fullscreen_btn->setMaximumSize(QSize(16777211, 16777215));

        horizontalLayout_3->addWidget(fullscreen_btn);

        btn_voice_to_text = new QCheckBox(unused);
        btn_voice_to_text->setObjectName(QString::fromUtf8("btn_voice_to_text"));

        horizontalLayout_3->addWidget(btn_voice_to_text);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line = new QFrame(unused);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        verticalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_8->addWidget(unused);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        RU_stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        FuncLabel->setText(QCoreApplication::translate("MainWindow", "FUNCTIONS", nullptr));
        btn_emotion->setText(QString());
        emo_Label->setText(QCoreApplication::translate("MainWindow", "EMOTION", nullptr));
        btn_setting->setText(QString());
        setting_Label->setText(QCoreApplication::translate("MainWindow", "SETTINGS", nullptr));
        btn_chat->setText(QString());
        chat_Label->setText(QCoreApplication::translate("MainWindow", "CHATMATE", nullptr));
#if QT_CONFIG(whatsthis)
        search_box->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>&quot;\346\220\234\347\264\242\345\216\206\345\217\262\350\256\260\345\275\225&quot;</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        search_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        search_but->setText(QString());
        CoolTitle->setText(QCoreApplication::translate("MainWindow", "WHAT'S NEW?", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\345\214\206\345\214\206\350\200\214\344\270\213\357\274\214\347\224\237\346\264\273\351\200\206\346\260\264\350\241\214\350\210\237", nullptr));
#if QT_CONFIG(whatsthis)
        research_box->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>&quot;\346\220\234\347\264\242\345\216\206\345\217\262\350\256\260\345\275\225&quot;</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        research_box->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        research_but->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\347\273\223\346\236\234", nullptr));
        LIBRARY_label->setText(QCoreApplication::translate("MainWindow", "LIBRARY", nullptr));
        btn_open_folder->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        EMO_label->setText(QCoreApplication::translate("MainWindow", "\346\203\205\347\273\252\346\216\222\350\241\214\346\246\234", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        btn_prev->setText(QString());
        btn_pause_keep->setText(QString());
        btn_next->setText(QString());
        label_progress->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_shrink_expand->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btn_speed->setText(QCoreApplication::translate("MainWindow", "\345\200\215\351\200\237", nullptr));
        fullscreen_btn->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
        btn_voice_to_text->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\271\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
