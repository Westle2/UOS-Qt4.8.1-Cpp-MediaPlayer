/********************************************************************************
** Form generated from reading UI file 'dockwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKWIDGET_H
#define UI_DOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>

QT_BEGIN_NAMESPACE

class Ui_DockWidget
{
public:

    void setupUi(QDockWidget *DockWidget)
    {
        if (DockWidget->objectName().isEmpty())
            DockWidget->setObjectName(QString::fromUtf8("DockWidget"));
        DockWidget->resize(785, 641);

        retranslateUi(DockWidget);

        QMetaObject::connectSlotsByName(DockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *DockWidget)
    {
        DockWidget->setWindowTitle(QCoreApplication::translate("DockWidget", "DockWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DockWidget: public Ui_DockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKWIDGET_H
