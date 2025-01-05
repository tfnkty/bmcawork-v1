/********************************************************************************
** Form generated from reading UI file 'devices.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICES_H
#define UI_DEVICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Devices
{
public:
    QPushButton *cmdSearch;
    QPushButton *cmdOpen;
    QPushButton *cmdCancel;
    QListWidget *lbDevices;

    void setupUi(QDialog *Devices)
    {
        if (Devices->objectName().isEmpty())
            Devices->setObjectName(QStringLiteral("Devices"));
        Devices->resize(395, 356);
        cmdSearch = new QPushButton(Devices);
        cmdSearch->setObjectName(QStringLiteral("cmdSearch"));
        cmdSearch->setGeometry(QRect(260, 10, 121, 31));
        cmdOpen = new QPushButton(Devices);
        cmdOpen->setObjectName(QStringLiteral("cmdOpen"));
        cmdOpen->setGeometry(QRect(260, 50, 121, 31));
        cmdCancel = new QPushButton(Devices);
        cmdCancel->setObjectName(QStringLiteral("cmdCancel"));
        cmdCancel->setGeometry(QRect(260, 90, 121, 31));
        lbDevices = new QListWidget(Devices);
        lbDevices->setObjectName(QStringLiteral("lbDevices"));
        lbDevices->setGeometry(QRect(10, 10, 231, 331));
        QWidget::setTabOrder(cmdSearch, cmdOpen);
        QWidget::setTabOrder(cmdOpen, cmdCancel);

        retranslateUi(Devices);

        QMetaObject::connectSlotsByName(Devices);
    } // setupUi

    void retranslateUi(QDialog *Devices)
    {
        Devices->setWindowTitle(QApplication::translate("Devices", "Devices", nullptr));
        cmdSearch->setText(QApplication::translate("Devices", "Search", nullptr));
        cmdOpen->setText(QApplication::translate("Devices", "Open", nullptr));
        cmdCancel->setText(QApplication::translate("Devices", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Devices: public Ui_Devices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICES_H
