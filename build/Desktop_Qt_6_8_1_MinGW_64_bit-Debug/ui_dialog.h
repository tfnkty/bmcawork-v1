/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "graphplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *fraSpectrum;
    QGridLayout *gridLayout;
    Graphplot *SpectrumPlot;
    QGroupBox *fraDetector;
    QPushButton *cmdDetector;
    QGroupBox *fraSettings;
    QPushButton *cmdSettings;
    QGroupBox *fraTiming;
    QLabel *lblRealtime;
    QLineEdit *txtRealtime;
    QLabel *lblLivetime;
    QLineEdit *txtLivetime;
    QGroupBox *fraControls;
    QPushButton *cmdStart;
    QPushButton *cmdStop;
    QPushButton *cmdClear;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(879, 509);
        fraSpectrum = new QGroupBox(Dialog);
        fraSpectrum->setObjectName("fraSpectrum");
        fraSpectrum->setGeometry(QRect(9, 9, 861, 411));
        gridLayout = new QGridLayout(fraSpectrum);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        SpectrumPlot = new Graphplot(fraSpectrum);
        SpectrumPlot->setObjectName("SpectrumPlot");
        SpectrumPlot->setMouseTracking(false);
        SpectrumPlot->setAutoFillBackground(false);

        gridLayout->addWidget(SpectrumPlot, 0, 0, 1, 1);

        fraDetector = new QGroupBox(Dialog);
        fraDetector->setObjectName("fraDetector");
        fraDetector->setGeometry(QRect(10, 420, 101, 81));
        cmdDetector = new QPushButton(fraDetector);
        cmdDetector->setObjectName("cmdDetector");
        cmdDetector->setGeometry(QRect(10, 20, 81, 51));
        fraSettings = new QGroupBox(Dialog);
        fraSettings->setObjectName("fraSettings");
        fraSettings->setGeometry(QRect(120, 420, 101, 81));
        cmdSettings = new QPushButton(fraSettings);
        cmdSettings->setObjectName("cmdSettings");
        cmdSettings->setGeometry(QRect(10, 20, 81, 51));
        fraTiming = new QGroupBox(Dialog);
        fraTiming->setObjectName("fraTiming");
        fraTiming->setGeometry(QRect(480, 420, 161, 81));
        lblRealtime = new QLabel(fraTiming);
        lblRealtime->setObjectName("lblRealtime");
        lblRealtime->setGeometry(QRect(20, 50, 47, 13));
        txtRealtime = new QLineEdit(fraTiming);
        txtRealtime->setObjectName("txtRealtime");
        txtRealtime->setGeometry(QRect(80, 50, 71, 20));
        lblLivetime = new QLabel(fraTiming);
        lblLivetime->setObjectName("lblLivetime");
        lblLivetime->setGeometry(QRect(20, 20, 47, 13));
        txtLivetime = new QLineEdit(fraTiming);
        txtLivetime->setObjectName("txtLivetime");
        txtLivetime->setGeometry(QRect(80, 20, 71, 20));
        fraControls = new QGroupBox(Dialog);
        fraControls->setObjectName("fraControls");
        fraControls->setGeometry(QRect(650, 420, 221, 81));
        cmdStart = new QPushButton(fraControls);
        cmdStart->setObjectName("cmdStart");
        cmdStart->setGeometry(QRect(10, 20, 61, 51));
        cmdStart->setMaximumSize(QSize(16777215, 16777215));
        cmdStop = new QPushButton(fraControls);
        cmdStop->setObjectName("cmdStop");
        cmdStop->setGeometry(QRect(80, 20, 61, 51));
        cmdClear = new QPushButton(fraControls);
        cmdClear->setObjectName("cmdClear");
        cmdClear->setGeometry(QRect(150, 20, 61, 51));
        QWidget::setTabOrder(cmdDetector, cmdSettings);
        QWidget::setTabOrder(cmdSettings, txtLivetime);
        QWidget::setTabOrder(txtLivetime, txtRealtime);
        QWidget::setTabOrder(txtRealtime, cmdStart);
        QWidget::setTabOrder(cmdStart, cmdStop);
        QWidget::setTabOrder(cmdStop, cmdClear);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        fraSpectrum->setTitle(QCoreApplication::translate("Dialog", "Spectrum", nullptr));
        fraDetector->setTitle(QCoreApplication::translate("Dialog", "Detector", nullptr));
        cmdDetector->setText(QCoreApplication::translate("Dialog", "Open", nullptr));
        fraSettings->setTitle(QCoreApplication::translate("Dialog", "MCA settings", nullptr));
        cmdSettings->setText(QCoreApplication::translate("Dialog", "Settings", nullptr));
        fraTiming->setTitle(QCoreApplication::translate("Dialog", "Timing", nullptr));
        lblRealtime->setText(QCoreApplication::translate("Dialog", "Realtime", nullptr));
        lblLivetime->setText(QCoreApplication::translate("Dialog", "Livetime", nullptr));
        fraControls->setTitle(QCoreApplication::translate("Dialog", "Detector", nullptr));
        cmdStart->setText(QCoreApplication::translate("Dialog", "Start", nullptr));
        cmdStop->setText(QCoreApplication::translate("Dialog", "Stop", nullptr));
        cmdClear->setText(QCoreApplication::translate("Dialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
