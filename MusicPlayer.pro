QT += core gui
QT += multimedia
QT += multimediawidgets
QT += core websockets
QT += webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += /usr/include/x86_64-linux-gnu
LIBS += -L/usr/include/x86_64-linux-gnu -lavcodec -lavformat -lavutil -lswscale
#LIBS += /home/srh/Downloads/OpenVokaturi-4-0/OpenVokaturi-4-0/lib/open/linux/OpenVokaturi-4-0-linux.o
LIBS += $$PWD/lib/OpenVokaturi-4-0-linux.o
#LIBS += $$PWD/lib/libSparkChain.so
INCLUDEPATH += $$PWD/include  # 头文件路径
LIBS += -L$$PWD/lib -lSparkChain  # 指定 .so 库所在路径和库名（去掉 `lib` 前缀）
QMAKE_RPATHDIR += $$PWD/lib

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    main.cpp \
    mainwindow.cpp \
    fullscreen.cpp \
    settingdialog.cpp \
    sparkchain.cpp \
    videoplay.cpp


HEADERS += \
    chat.h \
    mainwindow.h \
    fullscreen.h \
    Vokaturi.h \
    RtAsrCallbacksImpl.h \
    settingdialog.h \
    videoplay.h


FORMS += \
    chat.ui \
    dockwidget.ui \
    mainwindow.ui \
    dockwidget.ui \
    settingdialog.ui \
    videoplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qic.qrc

#DISTFILES += \
#    ../../../../OpenVokaturi-4-0/OpenVokaturi-4-0/lib/open/linux/OpenVokaturi-4-0-linux.o

DISTFILES += \
    colorPre/colorChoose.py \
    colorPre/ds.py \
    colorPre/main.py \
    colorPre/model.pkl \
    star.py

