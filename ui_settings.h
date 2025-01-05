/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *fraMCAmode;
    QLabel *lblMode;
    QRadioButton *rbPHA;
    QRadioButton *rbMCS;
    QGroupBox *fraMCSPreset;
    QLabel *lblSeconds;
    QLineEdit *txtDwellTime;
    QGroupBox *fraMCSSettings;
    QLabel *lblMCSChannels;
    QComboBox *cmbMCSChannels;
    QSpinBox *nmrMCSLLD;
    QSpinBox *nmrMCSULD;
    QLabel *lblMCSLLD;
    QLabel *lblMCSULD;
    QGroupBox *fraPHAPreset;
    QCheckBox *chkPresetTime;
    QLineEdit *txtPresetTime;
    QComboBox *cmbPresetTime;
    QCheckBox *chkPresetCounts;
    QLineEdit *txtPresetCounts;
    QLabel *lblLowerChannel;
    QSpinBox *nmrPresetCountsLLD;
    QLabel *lblUpperChannel;
    QSpinBox *nmrPresetCountsULD;
    QGroupBox *fraAmplifier;
    QComboBox *cmbCoarseGain;
    QLabel *lblCoarseGain;
    QComboBox *cmbDigitalGain;
    QLabel *lblDigitalGain;
    QSlider *sldrFineGain;
    QRadioButton *rbNegative;
    QLabel *lblInputPolarity;
    QRadioButton *rbPositive;
    QLabel *lblFineGain;
    QLabel *lblFineGainVal;
    QGroupBox *fraHV;
    QLabel *lblVolts;
    QCheckBox *chkHVON;
    QDoubleSpinBox *nmrVolt;
    QGroupBox *fraPHASettings;
    QComboBox *cmbPHAChannels;
    QLabel *lblLLD;
    QLabel *lblULD;
    QLabel *lblChannels;
    QSpinBox *nmrLLD;
    QSpinBox *nmrULD;
    QGroupBox *fraFilter;
    QSpinBox *nmrThreshold;
    QLabel *lblThreshold;
    QComboBox *cmbRT;
    QLabel *lblRisetime;
    QComboBox *cmbFT;
    QLabel *lblFlatTop;
    QComboBox *cmbPZ;
    QLabel *lblPZ;
    QCheckBox *chkBLR;
    QCheckBox *chkPUR;
    QLabel *lblBLR;
    QLabel *lblPUR;
    QPushButton *cmdAdvanced;
    QPushButton *cmdApply;
    QPushButton *cmdStore;
    QPushButton *cmdClose;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(610, 501);
        fraMCAmode = new QGroupBox(Settings);
        fraMCAmode->setObjectName(QStringLiteral("fraMCAmode"));
        fraMCAmode->setGeometry(QRect(10, 0, 301, 51));
        lblMode = new QLabel(fraMCAmode);
        lblMode->setObjectName(QStringLiteral("lblMode"));
        lblMode->setGeometry(QRect(20, 20, 31, 16));
        rbPHA = new QRadioButton(fraMCAmode);
        rbPHA->setObjectName(QStringLiteral("rbPHA"));
        rbPHA->setGeometry(QRect(100, 20, 51, 17));
        rbMCS = new QRadioButton(fraMCAmode);
        rbMCS->setObjectName(QStringLiteral("rbMCS"));
        rbMCS->setGeometry(QRect(160, 20, 51, 17));
        fraMCSPreset = new QGroupBox(Settings);
        fraMCSPreset->setObjectName(QStringLiteral("fraMCSPreset"));
        fraMCSPreset->setGeometry(QRect(10, 50, 301, 71));
        lblSeconds = new QLabel(fraMCSPreset);
        lblSeconds->setObjectName(QStringLiteral("lblSeconds"));
        lblSeconds->setGeometry(QRect(20, 30, 47, 13));
        txtDwellTime = new QLineEdit(fraMCSPreset);
        txtDwellTime->setObjectName(QStringLiteral("txtDwellTime"));
        txtDwellTime->setGeometry(QRect(100, 30, 151, 20));
        fraMCSSettings = new QGroupBox(Settings);
        fraMCSSettings->setObjectName(QStringLiteral("fraMCSSettings"));
        fraMCSSettings->setGeometry(QRect(10, 120, 301, 121));
        lblMCSChannels = new QLabel(fraMCSSettings);
        lblMCSChannels->setObjectName(QStringLiteral("lblMCSChannels"));
        lblMCSChannels->setGeometry(QRect(20, 20, 47, 13));
        cmbMCSChannels = new QComboBox(fraMCSSettings);
        cmbMCSChannels->setObjectName(QStringLiteral("cmbMCSChannels"));
        cmbMCSChannels->setGeometry(QRect(100, 20, 151, 22));
        nmrMCSLLD = new QSpinBox(fraMCSSettings);
        nmrMCSLLD->setObjectName(QStringLiteral("nmrMCSLLD"));
        nmrMCSLLD->setGeometry(QRect(100, 50, 151, 22));
        nmrMCSULD = new QSpinBox(fraMCSSettings);
        nmrMCSULD->setObjectName(QStringLiteral("nmrMCSULD"));
        nmrMCSULD->setGeometry(QRect(100, 80, 151, 22));
        lblMCSLLD = new QLabel(fraMCSSettings);
        lblMCSLLD->setObjectName(QStringLiteral("lblMCSLLD"));
        lblMCSLLD->setGeometry(QRect(20, 50, 47, 13));
        lblMCSULD = new QLabel(fraMCSSettings);
        lblMCSULD->setObjectName(QStringLiteral("lblMCSULD"));
        lblMCSULD->setGeometry(QRect(20, 80, 47, 13));
        fraPHAPreset = new QGroupBox(Settings);
        fraPHAPreset->setObjectName(QStringLiteral("fraPHAPreset"));
        fraPHAPreset->setGeometry(QRect(320, 0, 281, 151));
        chkPresetTime = new QCheckBox(fraPHAPreset);
        chkPresetTime->setObjectName(QStringLiteral("chkPresetTime"));
        chkPresetTime->setGeometry(QRect(20, 20, 41, 20));
        txtPresetTime = new QLineEdit(fraPHAPreset);
        txtPresetTime->setObjectName(QStringLiteral("txtPresetTime"));
        txtPresetTime->setGeometry(QRect(90, 20, 81, 20));
        cmbPresetTime = new QComboBox(fraPHAPreset);
        cmbPresetTime->setObjectName(QStringLiteral("cmbPresetTime"));
        cmbPresetTime->setGeometry(QRect(180, 20, 81, 22));
        chkPresetCounts = new QCheckBox(fraPHAPreset);
        chkPresetCounts->setObjectName(QStringLiteral("chkPresetCounts"));
        chkPresetCounts->setGeometry(QRect(20, 50, 61, 20));
        txtPresetCounts = new QLineEdit(fraPHAPreset);
        txtPresetCounts->setObjectName(QStringLiteral("txtPresetCounts"));
        txtPresetCounts->setGeometry(QRect(90, 50, 171, 20));
        lblLowerChannel = new QLabel(fraPHAPreset);
        lblLowerChannel->setObjectName(QStringLiteral("lblLowerChannel"));
        lblLowerChannel->setGeometry(QRect(20, 80, 71, 16));
        nmrPresetCountsLLD = new QSpinBox(fraPHAPreset);
        nmrPresetCountsLLD->setObjectName(QStringLiteral("nmrPresetCountsLLD"));
        nmrPresetCountsLLD->setGeometry(QRect(110, 80, 151, 22));
        lblUpperChannel = new QLabel(fraPHAPreset);
        lblUpperChannel->setObjectName(QStringLiteral("lblUpperChannel"));
        lblUpperChannel->setGeometry(QRect(20, 110, 71, 16));
        nmrPresetCountsULD = new QSpinBox(fraPHAPreset);
        nmrPresetCountsULD->setObjectName(QStringLiteral("nmrPresetCountsULD"));
        nmrPresetCountsULD->setGeometry(QRect(110, 110, 151, 22));
        fraAmplifier = new QGroupBox(Settings);
        fraAmplifier->setObjectName(QStringLiteral("fraAmplifier"));
        fraAmplifier->setGeometry(QRect(10, 240, 301, 151));
        cmbCoarseGain = new QComboBox(fraAmplifier);
        cmbCoarseGain->setObjectName(QStringLiteral("cmbCoarseGain"));
        cmbCoarseGain->setGeometry(QRect(100, 20, 151, 22));
        lblCoarseGain = new QLabel(fraAmplifier);
        lblCoarseGain->setObjectName(QStringLiteral("lblCoarseGain"));
        lblCoarseGain->setGeometry(QRect(20, 20, 61, 20));
        cmbDigitalGain = new QComboBox(fraAmplifier);
        cmbDigitalGain->setObjectName(QStringLiteral("cmbDigitalGain"));
        cmbDigitalGain->setGeometry(QRect(100, 80, 151, 22));
        lblDigitalGain = new QLabel(fraAmplifier);
        lblDigitalGain->setObjectName(QStringLiteral("lblDigitalGain"));
        lblDigitalGain->setGeometry(QRect(20, 80, 61, 16));
        sldrFineGain = new QSlider(fraAmplifier);
        sldrFineGain->setObjectName(QStringLiteral("sldrFineGain"));
        sldrFineGain->setGeometry(QRect(100, 50, 151, 22));
        sldrFineGain->setOrientation(Qt::Horizontal);
        rbNegative = new QRadioButton(fraAmplifier);
        rbNegative->setObjectName(QStringLiteral("rbNegative"));
        rbNegative->setGeometry(QRect(180, 110, 71, 17));
        lblInputPolarity = new QLabel(fraAmplifier);
        lblInputPolarity->setObjectName(QStringLiteral("lblInputPolarity"));
        lblInputPolarity->setGeometry(QRect(20, 110, 71, 16));
        rbPositive = new QRadioButton(fraAmplifier);
        rbPositive->setObjectName(QStringLiteral("rbPositive"));
        rbPositive->setGeometry(QRect(110, 110, 61, 17));
        lblFineGain = new QLabel(fraAmplifier);
        lblFineGain->setObjectName(QStringLiteral("lblFineGain"));
        lblFineGain->setGeometry(QRect(20, 50, 61, 20));
        lblFineGainVal = new QLabel(fraAmplifier);
        lblFineGainVal->setObjectName(QStringLiteral("lblFineGainVal"));
        lblFineGainVal->setGeometry(QRect(260, 50, 31, 16));
        fraHV = new QGroupBox(Settings);
        fraHV->setObjectName(QStringLiteral("fraHV"));
        fraHV->setGeometry(QRect(10, 390, 301, 61));
        lblVolts = new QLabel(fraHV);
        lblVolts->setObjectName(QStringLiteral("lblVolts"));
        lblVolts->setGeometry(QRect(20, 20, 47, 16));
        chkHVON = new QCheckBox(fraHV);
        chkHVON->setObjectName(QStringLiteral("chkHVON"));
        chkHVON->setGeometry(QRect(250, 20, 41, 20));
        nmrVolt = new QDoubleSpinBox(fraHV);
        nmrVolt->setObjectName(QStringLiteral("nmrVolt"));
        nmrVolt->setGeometry(QRect(100, 20, 131, 22));
        fraPHASettings = new QGroupBox(Settings);
        fraPHASettings->setObjectName(QStringLiteral("fraPHASettings"));
        fraPHASettings->setGeometry(QRect(320, 150, 281, 111));
        cmbPHAChannels = new QComboBox(fraPHASettings);
        cmbPHAChannels->setObjectName(QStringLiteral("cmbPHAChannels"));
        cmbPHAChannels->setGeometry(QRect(110, 20, 151, 22));
        lblLLD = new QLabel(fraPHASettings);
        lblLLD->setObjectName(QStringLiteral("lblLLD"));
        lblLLD->setGeometry(QRect(30, 50, 47, 13));
        lblULD = new QLabel(fraPHASettings);
        lblULD->setObjectName(QStringLiteral("lblULD"));
        lblULD->setGeometry(QRect(30, 80, 47, 13));
        lblChannels = new QLabel(fraPHASettings);
        lblChannels->setObjectName(QStringLiteral("lblChannels"));
        lblChannels->setGeometry(QRect(30, 20, 47, 13));
        nmrLLD = new QSpinBox(fraPHASettings);
        nmrLLD->setObjectName(QStringLiteral("nmrLLD"));
        nmrLLD->setGeometry(QRect(110, 50, 151, 22));
        nmrULD = new QSpinBox(fraPHASettings);
        nmrULD->setObjectName(QStringLiteral("nmrULD"));
        nmrULD->setGeometry(QRect(110, 80, 151, 22));
        fraFilter = new QGroupBox(Settings);
        fraFilter->setObjectName(QStringLiteral("fraFilter"));
        fraFilter->setGeometry(QRect(320, 260, 281, 191));
        nmrThreshold = new QSpinBox(fraFilter);
        nmrThreshold->setObjectName(QStringLiteral("nmrThreshold"));
        nmrThreshold->setGeometry(QRect(110, 20, 151, 22));
        lblThreshold = new QLabel(fraFilter);
        lblThreshold->setObjectName(QStringLiteral("lblThreshold"));
        lblThreshold->setGeometry(QRect(30, 20, 61, 16));
        cmbRT = new QComboBox(fraFilter);
        cmbRT->setObjectName(QStringLiteral("cmbRT"));
        cmbRT->setGeometry(QRect(110, 50, 151, 22));
        lblRisetime = new QLabel(fraFilter);
        lblRisetime->setObjectName(QStringLiteral("lblRisetime"));
        lblRisetime->setGeometry(QRect(30, 50, 61, 16));
        cmbFT = new QComboBox(fraFilter);
        cmbFT->setObjectName(QStringLiteral("cmbFT"));
        cmbFT->setGeometry(QRect(110, 80, 151, 22));
        lblFlatTop = new QLabel(fraFilter);
        lblFlatTop->setObjectName(QStringLiteral("lblFlatTop"));
        lblFlatTop->setGeometry(QRect(30, 80, 61, 16));
        cmbPZ = new QComboBox(fraFilter);
        cmbPZ->setObjectName(QStringLiteral("cmbPZ"));
        cmbPZ->setGeometry(QRect(110, 110, 151, 22));
        lblPZ = new QLabel(fraFilter);
        lblPZ->setObjectName(QStringLiteral("lblPZ"));
        lblPZ->setGeometry(QRect(30, 110, 61, 16));
        chkBLR = new QCheckBox(fraFilter);
        chkBLR->setObjectName(QStringLiteral("chkBLR"));
        chkBLR->setGeometry(QRect(110, 140, 61, 20));
        chkPUR = new QCheckBox(fraFilter);
        chkPUR->setObjectName(QStringLiteral("chkPUR"));
        chkPUR->setGeometry(QRect(110, 160, 61, 20));
        lblBLR = new QLabel(fraFilter);
        lblBLR->setObjectName(QStringLiteral("lblBLR"));
        lblBLR->setGeometry(QRect(30, 140, 71, 16));
        lblPUR = new QLabel(fraFilter);
        lblPUR->setObjectName(QStringLiteral("lblPUR"));
        lblPUR->setGeometry(QRect(30, 160, 71, 16));
        cmdAdvanced = new QPushButton(fraFilter);
        cmdAdvanced->setObjectName(QStringLiteral("cmdAdvanced"));
        cmdAdvanced->setGeometry(QRect(180, 150, 81, 21));
        cmdAdvanced->setAutoDefault(false);
        cmdApply = new QPushButton(Settings);
        cmdApply->setObjectName(QStringLiteral("cmdApply"));
        cmdApply->setGeometry(QRect(10, 460, 91, 31));
        cmdApply->setAutoDefault(false);
        cmdStore = new QPushButton(Settings);
        cmdStore->setObjectName(QStringLiteral("cmdStore"));
        cmdStore->setGeometry(QRect(110, 460, 91, 31));
        cmdStore->setAutoDefault(false);
        cmdClose = new QPushButton(Settings);
        cmdClose->setObjectName(QStringLiteral("cmdClose"));
        cmdClose->setGeometry(QRect(210, 460, 91, 31));
        cmdClose->setAutoDefault(false);
        QWidget::setTabOrder(rbPHA, rbMCS);
        QWidget::setTabOrder(rbMCS, txtDwellTime);
        QWidget::setTabOrder(txtDwellTime, cmbMCSChannels);
        QWidget::setTabOrder(cmbMCSChannels, nmrMCSLLD);
        QWidget::setTabOrder(nmrMCSLLD, nmrMCSULD);
        QWidget::setTabOrder(nmrMCSULD, cmbCoarseGain);
        QWidget::setTabOrder(cmbCoarseGain, sldrFineGain);
        QWidget::setTabOrder(sldrFineGain, cmbDigitalGain);
        QWidget::setTabOrder(cmbDigitalGain, rbPositive);
        QWidget::setTabOrder(rbPositive, rbNegative);
        QWidget::setTabOrder(rbNegative, chkHVON);
        QWidget::setTabOrder(chkHVON, chkPresetTime);
        QWidget::setTabOrder(chkPresetTime, txtPresetTime);
        QWidget::setTabOrder(txtPresetTime, cmbPresetTime);
        QWidget::setTabOrder(cmbPresetTime, chkPresetCounts);
        QWidget::setTabOrder(chkPresetCounts, txtPresetCounts);
        QWidget::setTabOrder(txtPresetCounts, nmrPresetCountsLLD);
        QWidget::setTabOrder(nmrPresetCountsLLD, nmrPresetCountsULD);
        QWidget::setTabOrder(nmrPresetCountsULD, cmbPHAChannels);
        QWidget::setTabOrder(cmbPHAChannels, nmrLLD);
        QWidget::setTabOrder(nmrLLD, nmrULD);
        QWidget::setTabOrder(nmrULD, nmrThreshold);
        QWidget::setTabOrder(nmrThreshold, cmbRT);
        QWidget::setTabOrder(cmbRT, cmbFT);
        QWidget::setTabOrder(cmbFT, cmbPZ);
        QWidget::setTabOrder(cmbPZ, chkBLR);
        QWidget::setTabOrder(chkBLR, chkPUR);
        QWidget::setTabOrder(chkPUR, cmdAdvanced);
        QWidget::setTabOrder(cmdAdvanced, cmdApply);
        QWidget::setTabOrder(cmdApply, cmdStore);
        QWidget::setTabOrder(cmdStore, cmdClose);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "MCA Settings", nullptr));
        fraMCAmode->setTitle(QApplication::translate("Settings", "Acquisition mode", nullptr));
        lblMode->setText(QApplication::translate("Settings", "Mode:", nullptr));
        rbPHA->setText(QApplication::translate("Settings", "PHA", nullptr));
        rbMCS->setText(QApplication::translate("Settings", "MCS", nullptr));
        fraMCSPreset->setTitle(QApplication::translate("Settings", "Dwell time", nullptr));
        lblSeconds->setText(QApplication::translate("Settings", "Seconds:", nullptr));
        fraMCSSettings->setTitle(QApplication::translate("Settings", "MCS settings", nullptr));
        lblMCSChannels->setText(QApplication::translate("Settings", "Channels", nullptr));
        lblMCSLLD->setText(QApplication::translate("Settings", "LLD", nullptr));
        lblMCSULD->setText(QApplication::translate("Settings", "ULD", nullptr));
        fraPHAPreset->setTitle(QApplication::translate("Settings", "Acquisition preset", nullptr));
        chkPresetTime->setText(QApplication::translate("Settings", "Time", nullptr));
        chkPresetCounts->setText(QApplication::translate("Settings", "Counts", nullptr));
        lblLowerChannel->setText(QApplication::translate("Settings", "Lower channel", nullptr));
        lblUpperChannel->setText(QApplication::translate("Settings", "Upper channel", nullptr));
        fraAmplifier->setTitle(QApplication::translate("Settings", "Amplifier", nullptr));
        lblCoarseGain->setText(QApplication::translate("Settings", "Coarse gain:", nullptr));
        lblDigitalGain->setText(QApplication::translate("Settings", "Digital gain", nullptr));
        rbNegative->setText(QApplication::translate("Settings", "Negative", nullptr));
        lblInputPolarity->setText(QApplication::translate("Settings", "Input polarity", nullptr));
        rbPositive->setText(QApplication::translate("Settings", "Positive", nullptr));
        lblFineGain->setText(QApplication::translate("Settings", "Fine gain:", nullptr));
        lblFineGainVal->setText(QApplication::translate("Settings", "0", nullptr));
        fraHV->setTitle(QApplication::translate("Settings", "High Voltage", nullptr));
        lblVolts->setText(QApplication::translate("Settings", "Volts", nullptr));
        chkHVON->setText(QApplication::translate("Settings", "ON", nullptr));
        fraPHASettings->setTitle(QApplication::translate("Settings", "PHA settings", nullptr));
        lblLLD->setText(QApplication::translate("Settings", "LLD", nullptr));
        lblULD->setText(QApplication::translate("Settings", "ULD", nullptr));
        lblChannels->setText(QApplication::translate("Settings", "Channels", nullptr));
        fraFilter->setTitle(QApplication::translate("Settings", "Filter", nullptr));
        lblThreshold->setText(QApplication::translate("Settings", "Threshold", nullptr));
        lblRisetime->setText(QApplication::translate("Settings", "Rise time", nullptr));
        lblFlatTop->setText(QApplication::translate("Settings", "Flat top", nullptr));
        lblPZ->setText(QApplication::translate("Settings", "Poles/Zero", nullptr));
        chkBLR->setText(QApplication::translate("Settings", "Enable", nullptr));
        chkPUR->setText(QApplication::translate("Settings", "Enable", nullptr));
        lblBLR->setText(QApplication::translate("Settings", "Digital BLR", nullptr));
        lblPUR->setText(QApplication::translate("Settings", "Pile-up reject", nullptr));
        cmdAdvanced->setText(QApplication::translate("Settings", "Advanced...", nullptr));
        cmdApply->setText(QApplication::translate("Settings", "Apply", nullptr));
        cmdStore->setText(QApplication::translate("Settings", "Store", nullptr));
        cmdClose->setText(QApplication::translate("Settings", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
