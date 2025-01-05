/********************************************************************************
** Form generated from reading UI file 'advanced.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCED_H
#define UI_ADVANCED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Advanced
{
public:
    QGroupBox *fraDSP;
    QLabel *lblLTtrim;
    QComboBox *cmbTRPguard;
    QComboBox *cmbBLRrate;
    QLabel *lblPURguard;
    QLabel *lblTRPguard;
    QSpinBox *nmrLTtrim;
    QComboBox *cmbPURguard;
    QLabel *lblBLRrate;
    QLabel *lblAnalogPZ;
    QSpinBox *nmrAnalogPZ;
    QGroupBox *fraGPIO;
    QCheckBox *chkExtAcqCtlEnable;
    QLabel *lblGPIO1;
    QComboBox *cmbGPIO1;
    QRadioButton *rbGPIO1neg;
    QRadioButton *rbGPIO1pos;
    QComboBox *cmbGPIO2;
    QLabel *lblGPIO2;
    QRadioButton *rbGPIO2pos;
    QRadioButton *rbGPIO2neg;
    QPushButton *cmdApply;
    QPushButton *cmdClose;

    void setupUi(QDialog *Advanced)
    {
        if (Advanced->objectName().isEmpty())
            Advanced->setObjectName("Advanced");
        Advanced->resize(312, 389);
        fraDSP = new QGroupBox(Advanced);
        fraDSP->setObjectName("fraDSP");
        fraDSP->setGeometry(QRect(10, 0, 291, 181));
        lblLTtrim = new QLabel(fraDSP);
        lblLTtrim->setObjectName("lblLTtrim");
        lblLTtrim->setGeometry(QRect(20, 20, 61, 16));
        cmbTRPguard = new QComboBox(fraDSP);
        cmbTRPguard->setObjectName("cmbTRPguard");
        cmbTRPguard->setGeometry(QRect(130, 110, 131, 22));
        cmbBLRrate = new QComboBox(fraDSP);
        cmbBLRrate->setObjectName("cmbBLRrate");
        cmbBLRrate->setGeometry(QRect(130, 50, 131, 22));
        lblPURguard = new QLabel(fraDSP);
        lblPURguard->setObjectName("lblPURguard");
        lblPURguard->setGeometry(QRect(20, 80, 61, 16));
        lblTRPguard = new QLabel(fraDSP);
        lblTRPguard->setObjectName("lblTRPguard");
        lblTRPguard->setGeometry(QRect(20, 110, 71, 16));
        nmrLTtrim = new QSpinBox(fraDSP);
        nmrLTtrim->setObjectName("nmrLTtrim");
        nmrLTtrim->setGeometry(QRect(130, 20, 131, 22));
        cmbPURguard = new QComboBox(fraDSP);
        cmbPURguard->setObjectName("cmbPURguard");
        cmbPURguard->setGeometry(QRect(130, 80, 131, 22));
        lblBLRrate = new QLabel(fraDSP);
        lblBLRrate->setObjectName("lblBLRrate");
        lblBLRrate->setGeometry(QRect(20, 50, 61, 16));
        lblAnalogPZ = new QLabel(fraDSP);
        lblAnalogPZ->setObjectName("lblAnalogPZ");
        lblAnalogPZ->setGeometry(QRect(20, 140, 71, 16));
        nmrAnalogPZ = new QSpinBox(fraDSP);
        nmrAnalogPZ->setObjectName("nmrAnalogPZ");
        nmrAnalogPZ->setGeometry(QRect(130, 140, 131, 22));
        fraGPIO = new QGroupBox(Advanced);
        fraGPIO->setObjectName("fraGPIO");
        fraGPIO->setGeometry(QRect(10, 180, 291, 171));
        chkExtAcqCtlEnable = new QCheckBox(fraGPIO);
        chkExtAcqCtlEnable->setObjectName("chkExtAcqCtlEnable");
        chkExtAcqCtlEnable->setGeometry(QRect(30, 20, 201, 20));
        lblGPIO1 = new QLabel(fraGPIO);
        lblGPIO1->setObjectName("lblGPIO1");
        lblGPIO1->setGeometry(QRect(40, 50, 81, 16));
        cmbGPIO1 = new QComboBox(fraGPIO);
        cmbGPIO1->setObjectName("cmbGPIO1");
        cmbGPIO1->setGeometry(QRect(130, 50, 131, 22));
        rbGPIO1neg = new QRadioButton(fraGPIO);
        rbGPIO1neg->setObjectName("rbGPIO1neg");
        rbGPIO1neg->setGeometry(QRect(200, 80, 51, 17));
        rbGPIO1pos = new QRadioButton(fraGPIO);
        rbGPIO1pos->setObjectName("rbGPIO1pos");
        rbGPIO1pos->setGeometry(QRect(140, 80, 51, 17));
        cmbGPIO2 = new QComboBox(fraGPIO);
        cmbGPIO2->setObjectName("cmbGPIO2");
        cmbGPIO2->setGeometry(QRect(130, 110, 131, 22));
        lblGPIO2 = new QLabel(fraGPIO);
        lblGPIO2->setObjectName("lblGPIO2");
        lblGPIO2->setGeometry(QRect(40, 110, 81, 16));
        rbGPIO2pos = new QRadioButton(fraGPIO);
        rbGPIO2pos->setObjectName("rbGPIO2pos");
        rbGPIO2pos->setGeometry(QRect(140, 140, 51, 17));
        rbGPIO2neg = new QRadioButton(fraGPIO);
        rbGPIO2neg->setObjectName("rbGPIO2neg");
        rbGPIO2neg->setGeometry(QRect(200, 140, 51, 17));
        cmdApply = new QPushButton(Advanced);
        cmdApply->setObjectName("cmdApply");
        cmdApply->setGeometry(QRect(140, 360, 75, 23));
        cmdApply->setAutoDefault(false);
        cmdClose = new QPushButton(Advanced);
        cmdClose->setObjectName("cmdClose");
        cmdClose->setGeometry(QRect(220, 360, 75, 23));
        cmdClose->setAutoDefault(false);
        QWidget::setTabOrder(nmrLTtrim, cmbBLRrate);
        QWidget::setTabOrder(cmbBLRrate, cmbPURguard);
        QWidget::setTabOrder(cmbPURguard, cmbTRPguard);
        QWidget::setTabOrder(cmbTRPguard, nmrAnalogPZ);
        QWidget::setTabOrder(nmrAnalogPZ, chkExtAcqCtlEnable);
        QWidget::setTabOrder(chkExtAcqCtlEnable, cmbGPIO1);
        QWidget::setTabOrder(cmbGPIO1, rbGPIO1pos);
        QWidget::setTabOrder(rbGPIO1pos, rbGPIO1neg);
        QWidget::setTabOrder(rbGPIO1neg, cmbGPIO2);
        QWidget::setTabOrder(cmbGPIO2, rbGPIO2pos);
        QWidget::setTabOrder(rbGPIO2pos, rbGPIO2neg);
        QWidget::setTabOrder(rbGPIO2neg, cmdApply);
        QWidget::setTabOrder(cmdApply, cmdClose);

        retranslateUi(Advanced);

        QMetaObject::connectSlotsByName(Advanced);
    } // setupUi

    void retranslateUi(QDialog *Advanced)
    {
        Advanced->setWindowTitle(QCoreApplication::translate("Advanced", "Dialog", nullptr));
        fraDSP->setTitle(QCoreApplication::translate("Advanced", "DSP", nullptr));
        lblLTtrim->setText(QCoreApplication::translate("Advanced", "LT fine-tune", nullptr));
        lblPURguard->setText(QCoreApplication::translate("Advanced", "PUR guard", nullptr));
        lblTRPguard->setText(QCoreApplication::translate("Advanced", "TRP guard", nullptr));
        lblBLRrate->setText(QCoreApplication::translate("Advanced", "BLR rate", nullptr));
        lblAnalogPZ->setText(QCoreApplication::translate("Advanced", "Analog P/Z", nullptr));
        fraGPIO->setTitle(QCoreApplication::translate("Advanced", "GPIO", nullptr));
        chkExtAcqCtlEnable->setText(QCoreApplication::translate("Advanced", "Enable external acquisition control", nullptr));
        lblGPIO1->setText(QCoreApplication::translate("Advanced", "GPIO1 function", nullptr));
        rbGPIO1neg->setText(QCoreApplication::translate("Advanced", "Neg", nullptr));
        rbGPIO1pos->setText(QCoreApplication::translate("Advanced", "Pos", nullptr));
        lblGPIO2->setText(QCoreApplication::translate("Advanced", "GPIO2 function", nullptr));
        rbGPIO2pos->setText(QCoreApplication::translate("Advanced", "Pos", nullptr));
        rbGPIO2neg->setText(QCoreApplication::translate("Advanced", "Neg", nullptr));
        cmdApply->setText(QCoreApplication::translate("Advanced", "Apply", nullptr));
        cmdClose->setText(QCoreApplication::translate("Advanced", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Advanced: public Ui_Advanced {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCED_H
