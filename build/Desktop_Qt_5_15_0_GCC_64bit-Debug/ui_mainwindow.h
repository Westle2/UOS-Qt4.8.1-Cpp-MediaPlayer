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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *left_widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_playMode;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_theme;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_shrink_expand;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QTextEdit *textEdit_subtitles;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_prev;
    QPushButton *btn_pause_keep;
    QPushButton *btn_next;
    QSlider *horizontalSlider_2;
    QLabel *label_progress;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_speed;
    QPushButton *fullscreen_btn;
    QCheckBox *btn_voice_to_text;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *right_widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_emotion;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *btn_open_folder;
    QLineEdit *search_box;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(865, 632);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:rgb(96, 202, 145)\n"
"qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69))\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        splitter->setOrientation(Qt::Horizontal);
        left_widget = new QWidget(splitter);
        left_widget->setObjectName(QString::fromUtf8("left_widget"));
        left_widget->setAutoFillBackground(false);
        left_widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(left_widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox_playMode = new QComboBox(left_widget);
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

        horizontalLayout_4->addWidget(comboBox_playMode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        comboBox_theme = new QComboBox(left_widget);
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

        horizontalLayout_4->addWidget(comboBox_theme);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_shrink_expand = new QPushButton(left_widget);
        btn_shrink_expand->setObjectName(QString::fromUtf8("btn_shrink_expand"));
        btn_shrink_expand->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(btn_shrink_expand);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        widget = new QWidget(left_widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(widget);

        line_3 = new QFrame(left_widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        line = new QFrame(left_widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        textEdit_subtitles = new QTextEdit(left_widget);
        textEdit_subtitles->setObjectName(QString::fromUtf8("textEdit_subtitles"));

        verticalLayout_2->addWidget(textEdit_subtitles);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        line_2 = new QFrame(left_widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_prev = new QPushButton(left_widget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qic/svg/prev.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_prev->setIcon(icon);
        btn_prev->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(btn_prev);

        btn_pause_keep = new QPushButton(left_widget);
        btn_pause_keep->setObjectName(QString::fromUtf8("btn_pause_keep"));
        btn_pause_keep->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qic/svg/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause_keep->setIcon(icon1);
        btn_pause_keep->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(btn_pause_keep);

        btn_next = new QPushButton(left_widget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qic/svg/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon2);
        btn_next->setIconSize(QSize(20, 20));
        btn_next->setAutoDefault(false);

        horizontalLayout_2->addWidget(btn_next);

        horizontalSlider_2 = new QSlider(left_widget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);

        label_progress = new QLabel(left_widget);
        label_progress->setObjectName(QString::fromUtf8("label_progress"));
        label_progress->setMinimumSize(QSize(63, 0));

        horizontalLayout_2->addWidget(label_progress);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_title = new QLabel(left_widget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8("min-width:150px;\n"
"max-width:200px;"));

        horizontalLayout_3->addWidget(label_title);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_speed = new QPushButton(left_widget);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(btn_speed);

        fullscreen_btn = new QPushButton(left_widget);
        fullscreen_btn->setObjectName(QString::fromUtf8("fullscreen_btn"));
        fullscreen_btn->setMaximumSize(QSize(16777211, 16777215));

        horizontalLayout_3->addWidget(fullscreen_btn);

        btn_voice_to_text = new QCheckBox(left_widget);
        btn_voice_to_text->setObjectName(QString::fromUtf8("btn_voice_to_text"));

        horizontalLayout_3->addWidget(btn_voice_to_text);

        label = new QLabel(left_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/qic/svg/voice_open.svg);"));

        horizontalLayout_3->addWidget(label);

        horizontalSlider = new QSlider(left_widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(100, 0));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        label_2 = new QLabel(left_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        splitter->addWidget(left_widget);
        right_widget = new QWidget(splitter);
        right_widget->setObjectName(QString::fromUtf8("right_widget"));
        right_widget->setAutoFillBackground(false);
        right_widget->setStyleSheet(QString::fromUtf8("background: transparent\n"
""));
        verticalLayout_5 = new QVBoxLayout(right_widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_emotion = new QPushButton(right_widget);
        btn_emotion->setObjectName(QString::fromUtf8("btn_emotion"));
        btn_emotion->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btn_emotion);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(right_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        btn_open_folder = new QPushButton(right_widget);
        btn_open_folder->setObjectName(QString::fromUtf8("btn_open_folder"));
        btn_open_folder->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btn_open_folder);


        verticalLayout_5->addLayout(horizontalLayout);

        search_box = new QLineEdit(right_widget);
        search_box->setObjectName(QString::fromUtf8("search_box"));
        search_box->setStyleSheet(QString::fromUtf8("color: rgb(211, 234, 255);"));

        verticalLayout_5->addWidget(search_box);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listWidget = new QListWidget(right_widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background: transparent\n"
""));

        verticalLayout_4->addWidget(listWidget);


        verticalLayout_5->addLayout(verticalLayout_4);

        splitter->addWidget(right_widget);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_shrink_expand->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btn_prev->setText(QString());
        btn_pause_keep->setText(QString());
        btn_next->setText(QString());
        label_progress->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        btn_speed->setText(QCoreApplication::translate("MainWindow", "\345\200\215\351\200\237", nullptr));
        fullscreen_btn->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
        btn_voice_to_text->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\271\225", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_emotion->setText(QCoreApplication::translate("MainWindow", "\346\203\205\347\273\252\350\257\206\345\210\253", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        btn_open_folder->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
#if QT_CONFIG(whatsthis)
        search_box->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>&quot;\346\220\234\347\264\242\345\216\206\345\217\262\350\256\260\345\275\225&quot;</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
