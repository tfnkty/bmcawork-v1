/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(879, 509);
        fraSpectrum = new QGroupBox(Dialog);
        fraSpectrum->setObjectName(QStringLiteral("fraSpectrum"));
        fraSpectrum->setGeometry(QRect(9, 9, 861, 411));
        gridLayout = new QGridLayout(fraSpectrum);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        SpectrumPlot = new Graphplot(fraSpectrum);
        SpectrumPlot->setObjectName(QStringLiteral("SpectrumPlot"));
        SpectrumPlot->setAutoFillBackground(false);

        gridLayout->addWidget(SpectrumPlot, 0, 0, 1, 1);

        fraDetector = new QGroupBox(Dialog);
        fraDetector->setObjectName(QStringLiteral("fraDetector"));
        fraDetector->setGeometry(QRect(10, 420, 121, 81));
        cmdDetector = new QPushButton(fraDetector);
        cmdDetector->setObjectName(QStringLiteral("cmdDetector"));
        cmdDetector->setGeometry(QRect(10, 20, 101, 51));
        fraSettings = new QGroupBox(Dialog);
        fraSettings->setObjectName(QStringLiteral("fraSettings"));
        fraSettings->setGeometry(QRect(140, 420, 121, 81));
        cmdSettings = new QPushButton(fraSettings);
        cmdSettings->setObjectName(QStringLiteral("cmdSettings"));
        cmdSettings->setGeometry(QRect(10, 20, 101, 51));
        fraTiming = new QGroupBox(Dialog);
        fraTiming->setObjectName(QStringLiteral("fraTiming"));
        fraTiming->setGeometry(QRect(360, 420, 161, 81));
        lblRealtime = new QLabel(fraTiming);
        lblRealtime->setObjectName(QStringLiteral("lblRealtime"));
        lblRealtime->setGeometry(QRect(20, 50, 47, 13));
        txtRealtime = new QLineEdit(fraTiming);
        txtRealtime->setObjectName(QStringLiteral("txtRealtime"));
        txtRealtime->setGeometry(QRect(80, 50, 71, 20));
        lblLivetime = new QLabel(fraTiming);
        lblLivetime->setObjectName(QStringLiteral("lblLivetime"));
        lblLivetime->setGeometry(QRect(20, 20, 47, 13));
        txtLivetime = new QLineEdit(fraTiming);
        txtLivetime->setObjectName(QStringLiteral("txtLivetime"));
        txtLivetime->setGeometry(QRect(80, 20, 71, 20));
        fraControls = new QGroupBox(Dialog);
        fraControls->setObjectName(QStringLiteral("fraControls"));
        fraControls->setGeometry(QRect(530, 420, 341, 81));
        cmdStart = new QPushButton(fraControls);
        cmdStart->setObjectName(QStringLiteral("cmdStart"));
        cmdStart->setGeometry(QRect(10, 20, 101, 51));
        cmdStop = new QPushButton(fraControls);
        cmdStop->setObjectName(QStringLiteral("cmdStop"));
        cmdStop->setGeometry(QRect(120, 20, 101, 51));
        cmdClear = new QPushButton(fraControls);
        cmdClear->setObjectName(QStringLiteral("cmdClear"));
        cmdClear->setGeometry(QRect(230, 20, 101, 51));
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
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        fraSpectrum->setTitle(QApplication::translate("Dialog", "Spectrum", nullptr));
        fraDetector->setTitle(QApplication::translate("Dialog", "Detector", nullptr));
        cmdDetector->setText(QApplication::translate("Dialog", "Open", nullptr));
        fraSettings->setTitle(QApplication::translate("Dialog", "MCA settings", nullptr));
        cmdSettings->setText(QApplication::translate("Dialog", "Settings", nullptr));
        fraTiming->setTitle(QApplication::translate("Dialog", "Timing", nullptr));
        lblRealtime->setText(QApplication::translate("Dialog", "Realtime", nullptr));
        lblLivetime->setText(QApplication::translate("Dialog", "Livetime", nullptr));
        fraControls->setTitle(QApplication::translate("Dialog", "Detector", nullptr));
        cmdStart->setText(QApplication::translate("Dialog", "Start", nullptr));
        cmdStop->setText(QApplication::translate("Dialog", "Stop", nullptr));
        cmdClear->setText(QApplication::translate("Dialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
