/********************************************************************************
** Form generated from reading UI file 'videoplay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAY_H
#define UI_VIDEOPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlay
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *Video;
    QWidget *cntWidget;
    QVBoxLayout *verticalLayout;
    QWidget *progressWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_prev;
    QPushButton *btn_pause_keep;
    QPushButton *btn_next;
    QSlider *timeSlider;
    QLabel *label_progress;
    QWidget *otherfuncWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_title;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_speed;
    QPushButton *fullscreen_btn;
    QComboBox *comboBox_playMode;
    QLabel *pic_voice_lab;
    QSlider *voiceSlider;

    void setupUi(QWidget *VideoPlay)
    {
        if (VideoPlay->objectName().isEmpty())
            VideoPlay->setObjectName(QString::fromUtf8("VideoPlay"));
        VideoPlay->resize(983, 841);
        verticalLayout_2 = new QVBoxLayout(VideoPlay);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Video = new QWidget(VideoPlay);
        Video->setObjectName(QString::fromUtf8("Video"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Video->sizePolicy().hasHeightForWidth());
        Video->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(Video);

        cntWidget = new QWidget(VideoPlay);
        cntWidget->setObjectName(QString::fromUtf8("cntWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cntWidget->sizePolicy().hasHeightForWidth());
        cntWidget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(cntWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        progressWidget = new QWidget(cntWidget);
        progressWidget->setObjectName(QString::fromUtf8("progressWidget"));
        progressWidget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(progressWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_prev = new QPushButton(progressWidget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qic/svg/prev.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_prev->setIcon(icon);
        btn_prev->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_prev);

        btn_pause_keep = new QPushButton(progressWidget);
        btn_pause_keep->setObjectName(QString::fromUtf8("btn_pause_keep"));
        btn_pause_keep->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qic/svg/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause_keep->setIcon(icon1);
        btn_pause_keep->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_pause_keep);

        btn_next = new QPushButton(progressWidget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qic/svg/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon2);
        btn_next->setIconSize(QSize(20, 20));
        btn_next->setAutoDefault(false);

        horizontalLayout->addWidget(btn_next);

        timeSlider = new QSlider(progressWidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setMaximum(100);
        timeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(timeSlider);

        label_progress = new QLabel(progressWidget);
        label_progress->setObjectName(QString::fromUtf8("label_progress"));
        label_progress->setMinimumSize(QSize(63, 0));

        horizontalLayout->addWidget(label_progress);


        verticalLayout->addWidget(progressWidget);

        otherfuncWidget = new QWidget(cntWidget);
        otherfuncWidget->setObjectName(QString::fromUtf8("otherfuncWidget"));
        otherfuncWidget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(otherfuncWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(otherfuncWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8("min-width:150px;\n"
"max-width:200px;"));

        horizontalLayout_2->addWidget(label_title);

        nameLabel = new QLabel(otherfuncWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_2->addWidget(nameLabel);

        horizontalSpacer_4 = new QSpacerItem(276, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_speed = new QPushButton(otherfuncWidget);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(btn_speed);

        fullscreen_btn = new QPushButton(otherfuncWidget);
        fullscreen_btn->setObjectName(QString::fromUtf8("fullscreen_btn"));
        fullscreen_btn->setMaximumSize(QSize(16777211, 16777215));

        horizontalLayout_2->addWidget(fullscreen_btn);

        comboBox_playMode = new QComboBox(otherfuncWidget);
        comboBox_playMode->setObjectName(QString::fromUtf8("comboBox_playMode"));
        comboBox_playMode->setMinimumSize(QSize(0, 30));
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

        horizontalLayout_2->addWidget(comboBox_playMode);

        pic_voice_lab = new QLabel(otherfuncWidget);
        pic_voice_lab->setObjectName(QString::fromUtf8("pic_voice_lab"));
        pic_voice_lab->setMinimumSize(QSize(30, 30));
        pic_voice_lab->setStyleSheet(QString::fromUtf8("border-image: url(:/qic/svg/voice_open.svg);"));

        horizontalLayout_2->addWidget(pic_voice_lab);

        voiceSlider = new QSlider(otherfuncWidget);
        voiceSlider->setObjectName(QString::fromUtf8("voiceSlider"));
        voiceSlider->setMinimumSize(QSize(100, 0));
        voiceSlider->setMaximum(100);
        voiceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(voiceSlider);


        verticalLayout->addWidget(otherfuncWidget);


        verticalLayout_2->addWidget(cntWidget);


        retranslateUi(VideoPlay);

        QMetaObject::connectSlotsByName(VideoPlay);
    } // setupUi

    void retranslateUi(QWidget *VideoPlay)
    {
        VideoPlay->setWindowTitle(QCoreApplication::translate("VideoPlay", "Form", nullptr));
        btn_prev->setText(QString());
        btn_pause_keep->setText(QString());
        btn_next->setText(QString());
        label_progress->setText(QCoreApplication::translate("VideoPlay", "TextLabel", nullptr));
        label_title->setText(QCoreApplication::translate("VideoPlay", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        nameLabel->setText(QCoreApplication::translate("VideoPlay", "TextLabel", nullptr));
        btn_speed->setText(QCoreApplication::translate("VideoPlay", "\345\200\215\351\200\237", nullptr));
        fullscreen_btn->setText(QCoreApplication::translate("VideoPlay", "\345\205\250\345\261\217", nullptr));
        pic_voice_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoPlay: public Ui_VideoPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAY_H
