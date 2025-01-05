#include "settings.h"
#include "ui_settings.h"
#include "advanced.h"
#include <qstring.h>
#include <qmessagebox.h>

Settings::Settings(QWidget *parent) : QDialog(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);

    // Connect events

    // Lineedit
    connect(ui->txtPresetTime, SIGNAL(editingFinished()), this, SLOT(txtPresetTime_editingFinished()));
    connect(ui->txtPresetCounts, SIGNAL(editingFinished()), this, SLOT(txtPresetCounts_editingFinished()));
    connect(ui->txtDwellTime, SIGNAL(editingFinished()), this, SLOT(txtDwellTime_editingFinished()));

    // Radiobuttons
    connect(ui->rbPHA, SIGNAL(toggled(bool)), this, SLOT(rbPHA_rbMCS_toggled(const bool)));
    connect(ui->rbMCS, SIGNAL(toggled(bool)), this, SLOT(rbPHA_rbMCS_toggled(const bool)));
    connect(ui->rbPositive, SIGNAL(toggled(bool)), this, SLOT(rbPositive_rbNegative_toggled(const bool)));
    connect(ui->rbNegative, SIGNAL(toggled(bool)), this, SLOT(rbPositive_rbNegative_toggled(const bool)));

    // Checkbox
    connect(ui->chkPresetTime, SIGNAL(toggled(bool)), this, SLOT(chkPresetTime_toggled(const bool)));
    connect(ui->chkPresetCounts, SIGNAL(toggled(bool)), this, SLOT(chkPresetCounts_toggled(const bool)));
    connect(ui->chkBLR, SIGNAL(toggled(bool)), this, SLOT(chkBLR_toggled(const bool)));
    connect(ui->chkPUR, SIGNAL(toggled(bool)), this, SLOT(chkPUR_toggled(const bool)));
    connect(ui->chkHVON, SIGNAL(toggled(bool)), this, SLOT(chkHVON_toggled(const bool)));

    // Spinbox
    connect(ui->nmrMCSLLD, SIGNAL(valueChanged(int)), this, SLOT(nmrMCSLLD_valueChanged(const int)));
    connect(ui->nmrMCSULD, SIGNAL(valueChanged(int)), this, SLOT(nmrMCSULD_valueChanged(const int)));
    connect(ui->nmrLLD, SIGNAL(valueChanged(int)), this, SLOT(nmrLLD_valueChanged(const int)));
    connect(ui->nmrULD, SIGNAL(valueChanged(int)), this, SLOT(nmrULD_valueChanged(const int)));
    connect(ui->nmrPresetCountsLLD, SIGNAL(valueChanged(int)), this, SLOT(nmrPresetCountsLLD_valueChanged(const int)));
    connect(ui->nmrPresetCountsULD, SIGNAL(valueChanged(int)), this, SLOT(nmrPresetCountsULD_valueChanged(const int)));
    connect(ui->nmrThreshold, SIGNAL(valueChanged(int)), this, SLOT(nmrThreshold_valueChanged(const int)));
    // DoubleSpinbox
    connect(ui->nmrVolt, SIGNAL(valueChanged(double)), this, SLOT(nmrVolt_valueChanged(const double)));

    // Combobox
    connect(ui->cmbPresetTime, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbPresetTime_currentIndexChanged(const int)));
    connect(ui->cmbPHAChannels, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbPHAChannels_currentIndexChanged(const int)));
    connect(ui->cmbMCSChannels, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbMCSChannels_currentIndexChanged(const int)));
    connect(ui->cmbCoarseGain, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbCoarseGain_currentIndexChanged(const int)));
    connect(ui->cmbDigitalGain, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbDigitalGain_currentIndexChanged(const int)));
    connect(ui->cmbRT, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbRT_currentIndexChanged(const int)));
    connect(ui->cmbFT, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbFT_currentIndexChanged(const int)));
    connect(ui->cmbPZ, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbPZ_currentIndexChanged(const int)));

    // Slider
    connect(ui->sldrFineGain, SIGNAL(valueChanged(int)), this, SLOT(sldrFineGain_valueChanged(const int)));

    // Buttons
    connect(ui->cmdAdvanced, SIGNAL(clicked()), this, SLOT(cmdAdvanced_clicked()));
    connect(ui->cmdApply, SIGNAL(clicked()), this, SLOT(cmdApply_clicked()));
    connect(ui->cmdStore, SIGNAL(clicked()), this, SLOT(cmdStore_clicked()));
    connect(ui->cmdClose, SIGNAL(clicked()), this, SLOT(cmdClose_clicked()));
}
Settings::~Settings()
{
    delete ui;
}

void Settings::showEvent(QShowEvent *event)
{
    // Call parent function
    QDialog::showEvent(event);

    // Load MCA parameters
    ReadMCAParams(m_hMCA, m_oMCASettings);

    // Init controls
    bUpdateShowing = true;

    ui->nmrThreshold->setRange(0, 255);
    ui->nmrThreshold->setSingleStep(1);

    ui->nmrLLD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrLLD->setSingleStep(1);
    ui->nmrULD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrULD->setSingleStep(1);

    ui->nmrMCSLLD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrMCSLLD->setSingleStep(1);
    ui->nmrMCSULD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrMCSULD->setSingleStep(1);

    ui->nmrPresetCountsLLD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrPresetCountsLLD->setSingleStep(1);
    ui->nmrPresetCountsULD->setRange(0, m_oMCASettings.iNumChannelsMax);
    ui->nmrPresetCountsULD->setSingleStep(1);

    ui->nmrVolt->setRange(0, 5000);
    ui->nmrVolt->setSingleStep(1);

    ui->sldrFineGain->setRange(0, m_oMCASettings.iGainFineMax);
    ui->sldrFineGain->setSingleStep(1);

    ui->cmbPHAChannels->addItem("256");
    ui->cmbPHAChannels->addItem("512");
    ui->cmbPHAChannels->addItem("1024");
    ui->cmbPHAChannels->addItem("2048");
    ui->cmbPHAChannels->addItem("4096");
    if(m_oMCASettings.iNumChannelsMax >= 8192)
        ui->cmbPHAChannels->addItem("8192");
    if(m_oMCASettings.iNumChannelsMax >= 16384)
        ui->cmbPHAChannels->addItem("16384");

    ui->cmbMCSChannels->addItem("256");
    ui->cmbMCSChannels->addItem("512");
    ui->cmbMCSChannels->addItem("1024");
    ui->cmbMCSChannels->addItem("2048");
    ui->cmbMCSChannels->addItem("4096");
    if(m_oMCASettings.iNumChannelsMax >= 8192)
        ui->cmbMCSChannels->addItem("8192");
    if(m_oMCASettings.iNumChannelsMax >= 16384)
        ui->cmbMCSChannels->addItem("16384");

    ui->cmbPresetTime->addItem("RT");
    ui->cmbPresetTime->addItem("LT");

    ui->cmbCoarseGain->addItem("x1");
    ui->cmbCoarseGain->addItem("x2");
    ui->cmbCoarseGain->addItem("x4");
    ui->cmbCoarseGain->addItem("x8");
    if(m_oMCASettings.iGainCoarseMax >= 4)
        ui->cmbCoarseGain->addItem("x16");
    if(m_oMCASettings.iGainCoarseMax >= 5)
        ui->cmbCoarseGain->addItem("x32");
    if(m_oMCASettings.iGainCoarseMax >= 6)
        ui->cmbCoarseGain->addItem("x64");
    if(m_oMCASettings.iGainCoarseMax >= 7)
        ui->cmbCoarseGain->addItem("x128");

    ui->cmbDigitalGain->addItem("x1");
    ui->cmbDigitalGain->addItem("x2");
    ui->cmbDigitalGain->addItem("x4");
    ui->cmbDigitalGain->addItem("x8");
    ui->cmbDigitalGain->addItem("x16");
    ui->cmbDigitalGain->addItem("x32");
    ui->cmbDigitalGain->addItem("x64");
    ui->cmbDigitalGain->addItem("x128");
    ui->cmbDigitalGain->addItem("x256");
    ui->cmbDigitalGain->addItem("x512");
    ui->cmbDigitalGain->addItem("x1024");

    bUpdateShowing = false;

    // Update GUI
    UpdateGUI(m_oMCASettings);

    // Disable Apply
    ui->cmdApply->setEnabled(false);
}
void Settings::setMCAHandle(HANDLE hMCA)
{
    m_hMCA = hMCA;
}
HANDLE Settings::MCAHandle()
{
    return m_hMCA;
}
// LineEdit
void Settings::txtPresetTime_editingFinished()
{
    if(bUpdateShowing)
        return;

    if(ui->txtPresetTime->text().toFloat() >= 0)
    {
        m_oMCASettings.sAcqPreset = ui->txtPresetTime->text().toFloat();
    }

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::txtPresetCounts_editingFinished()
{
    if(bUpdateShowing)
        return;

    if(ui->txtPresetCounts->text().toInt() >= 0)
    {
        m_oMCASettings.iAcqCounts = ui->txtPresetCounts->text().toInt();
    }

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::txtDwellTime_editingFinished()
{
    if(bUpdateShowing)
        return;

    if(ui->txtDwellTime->text().toFloat() >= 0)
    {
        m_oMCASettings.sDwell = ui->txtDwellTime->text().toFloat();
    }

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Radiobutton
void Settings::rbPHA_rbMCS_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iMCAmode = ui->rbPHA->isChecked() ? 0 : 1;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::rbPositive_rbNegative_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iInpPolarity = ui->rbPositive->isChecked() ? 1 : 0;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Checkbox
void Settings::chkPresetTime_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    int iValue = ui->chkPresetTime->isChecked();
    // Set preset state
    if (iValue)
    {
        // Get preset mode
        iValue = ui->cmbPresetTime->currentIndex();
        if (iValue==1)
            m_oMCASettings.iAcqMode = m_oMCASettings.iAcqMode | (1 | 2);
        else
            m_oMCASettings.iAcqMode = (m_oMCASettings.iAcqMode & (~1)) | 2;
    }
    else
    {
        // Clear preset mode
        m_oMCASettings.iAcqMode &=~2;
    }

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::chkPresetCounts_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    int iValue = ui->chkPresetCounts->isChecked();
    // Set preset state
    if (iValue)
        m_oMCASettings.iAcqMode = m_oMCASettings.iAcqMode | 4;
    else
        // Clear preset mode
        m_oMCASettings.iAcqMode = m_oMCASettings.iAcqMode & ~4;

    // Update GUI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::chkBLR_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iBLRenable = ui->chkBLR->isChecked() ? 1 : 0;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::chkPUR_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iPURenable = ui->chkPUR->isChecked() ? 1 : 0;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::chkHVON_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iHVstatus = ui->chkHVON->isChecked() ? 1 : 0;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
// Spinbox
void Settings::nmrMCSLLD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iSCAL = ui->nmrMCSLLD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrMCSULD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iSCAH = ui->nmrMCSULD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrLLD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iLLD = ui->nmrLLD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrULD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iULD = ui->nmrULD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrPresetCountsLLD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iPHAL = ui->nmrPresetCountsLLD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrPresetCountsULD_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iPHAH = ui->nmrPresetCountsULD->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::nmrThreshold_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iThreshold = ui->nmrThreshold->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
// DoubleSpinbox
void Settings::nmrVolt_valueChanged(const double)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.sHVvalue = ui->nmrVolt->value();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
// Comboboxes
void Settings::cmbPresetTime_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get selected item
    int iValue = ui->cmbPresetTime->currentIndex();
    if (iValue==1)
        m_oMCASettings.iAcqMode = m_oMCASettings.iAcqMode | (1 | 2);
    else
        m_oMCASettings.iAcqMode = (m_oMCASettings.iAcqMode & (~1)) | 2;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbPHAChannels_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Set the new number of channels
    int iPwrTwo=256;
    int iValue = ui->cmbPHAChannels->currentIndex();
    for (int iLoop=0; iLoop < iValue; iLoop++)
        iPwrTwo*= 2;

    m_oMCASettings.iNumChannels = iPwrTwo;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbMCSChannels_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Set the new number of channels
    int iPwrTwo=256;
    int iValue = ui->cmbMCSChannels->currentIndex();
    for (int iLoop=0; iLoop < iValue; iLoop++)
        iPwrTwo*= 2;

    m_oMCASettings.iNumChannels = iPwrTwo;

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbCoarseGain_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get the coarse gain selection
    m_oMCASettings.iGainCoarse = ui->cmbCoarseGain->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbDigitalGain_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get the coarse gain selection
    m_oMCASettings.iGainDigital = ui->cmbDigitalGain->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbRT_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get the risetime selection
    m_oMCASettings.iRiseTime = ui->cmbRT->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbFT_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get the flattop selection
    m_oMCASettings.iFlatTop = ui->cmbFT->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Settings::cmbPZ_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    // Get the pole-zero selection
    m_oMCASettings.iPZcanc = ui->cmbPZ->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
// Slider
void Settings::sldrFineGain_valueChanged(const int iVal)
{
    if(bUpdateShowing)
        return;

    if(iVal > 0 && iVal < 4096)
        m_oMCASettings.iGainFine = iVal;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
// Buttons
void Settings::cmdAdvanced_clicked()
{
    Advanced *poAdvanced = new Advanced(this);
    poAdvanced->setSettings(m_oMCASettings);
    poAdvanced->setMCAHandle(m_hMCA);
    poAdvanced->exec();
    m_oMCASettings=poAdvanced->Settings();
}
void Settings::cmdApply_clicked()
{
    // Save MCA parameters
    WriteMCAParams(m_hMCA, m_oMCASettings);

    // Disable the apply button
    ui->cmdApply->setEnabled(false);
}
void Settings::cmdStore_clicked()
{
    // Save MCA parameters
    WriteMCAParams(m_hMCA, m_oMCASettings);

    // Save settings to eeprom
    int iRet=SaveSettings(m_hMCA);
    if (iRet == MCA_SUCCESS)
    {
        // Error
        QMessageBox msgBox;
        msgBox.setText("bMCA");
        msgBox.setInformativeText("Settings saved succesfully to EEPROM.");
        msgBox.exec();
    }

    // Disable the apply button
    ui->cmdApply->setEnabled(false);
}
void Settings::cmdClose_clicked()
{
    // Close form
    this->close();
}

bool Settings::UpdateGUI(MCASettings oSettings)
{
    int iPwrTwo=256;
    float sADCdwell;
    QString szValue;

    // Check if we're alrady updating
    if (bUpdateShowing)
        return false;

    // Set updating flag
    bUpdateShowing=true;

    for (int iLoop = 0; iPwrTwo <= oSettings.iNumChannelsMax; iLoop++)
    {
        if (oSettings.iNumChannels==iPwrTwo)
        {
            ui->cmbPHAChannels->setCurrentIndex(iLoop);
            ui->cmbMCSChannels->setCurrentIndex(iLoop);
        }
        iPwrTwo *= 2;
    }

    if(oSettings.iADCrate == 0)
        oSettings.iADCrate = 25000000;
    sADCdwell = (float)1000000 / (float)oSettings.iADCrate;

    ui->cmbRT->clear();
    ui->cmbFT->clear();
    ui->cmbPZ->clear();
    for (int iLoop = 0; iLoop < 512; iLoop++)
    {
        ui->cmbRT->addItem(QString("%1 µs").arg((float)(iLoop) * sADCdwell, 0, 'f', 2));
        ui->cmbFT->addItem(QString("%1 µs").arg((float)(iLoop) * sADCdwell, 0, 'f', 2));
        ui->cmbPZ->addItem(QString("%1 µs").arg((float)(iLoop) * sADCdwell, 0, 'f', 2));
    }
    // Select item
    ui->cmbRT->setCurrentIndex(0);
    ui->cmbFT->setCurrentIndex(0);
    ui->cmbPZ->setCurrentIndex(0);

    if(oSettings.iMCAmode)
    {
        // MCS mode
        ui->rbPHA->setChecked(false);
        ui->rbMCS->setChecked(true);

        // Disable all PHA settings
        ui->fraPHAPreset->setEnabled(false);
        ui->fraPHASettings->setEnabled(false);

        ui->chkPresetTime->setEnabled(false);
        ui->txtPresetTime->setEnabled(false);
        ui->cmbPresetTime->setEnabled(false);

        ui->chkPresetCounts->setEnabled(false);
        ui->txtPresetCounts->setEnabled(false);

        ui->nmrPresetCountsLLD->setEnabled(false);
        ui->nmrPresetCountsULD->setEnabled(false);

        ui->cmbPHAChannels->setEnabled(false);
        ui->nmrLLD->setEnabled(false);
        ui->nmrULD->setEnabled(false);

        // Enable all MCS settings
        ui->fraMCSPreset->setEnabled(true);
        ui->fraMCSSettings->setEnabled(true);

        ui->txtDwellTime->setEnabled(true);
        ui->cmbMCSChannels->setEnabled(true);

        ui->nmrMCSLLD->setEnabled(true);
        ui->nmrMCSULD->setEnabled(true);
    }
    else
    {
        ui->rbPHA->setChecked(true);
        ui->rbMCS->setChecked(false);

        // Enable all PHA settings
        ui->fraPHAPreset->setEnabled(true);
        ui->fraPHASettings->setEnabled(true);

        ui->chkPresetTime->setEnabled(true);
        // Enable preset time controls depending on acquisition mode
        ui->txtPresetTime->setEnabled((oSettings.iAcqMode & 2)!= 0);
        ui->cmbPresetTime->setEnabled((oSettings.iAcqMode & 2)!= 0);

        if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PRESET_COUNTS)==0)
        {
            ui->chkPresetCounts->setEnabled(false);
            ui->chkPresetTime->setEnabled(false);

            ui->txtPresetCounts->setEnabled(false);

            ui->nmrPresetCountsLLD->setEnabled(false);
            ui->nmrPresetCountsULD->setEnabled(false);
        }
        else
        {
            ui->chkPresetCounts->setEnabled(true);
            ui->chkPresetTime->setEnabled(true);

            ui->txtPresetCounts->setEnabled((oSettings.iAcqMode & 4)!= 0);

            ui->nmrPresetCountsLLD->setEnabled((oSettings.iAcqMode & 4)!= 0);
            ui->nmrPresetCountsULD->setEnabled((oSettings.iAcqMode & 4)!= 0);
        }

        ui->cmbPHAChannels->setEnabled(true);
        ui->nmrLLD->setEnabled(true);
        ui->nmrULD->setEnabled(true);

        // Disable all MCS settings
        ui->fraMCSPreset->setEnabled(false);
        ui->fraMCSSettings->setEnabled(false);

        ui->txtDwellTime->setEnabled(false);

        ui->cmbMCSChannels->setEnabled(false);
        ui->nmrMCSLLD->setEnabled(false);
        ui->nmrMCSULD->setEnabled(false);
    }

    ui->cmbPresetTime->setCurrentIndex(((oSettings.iAcqMode & 1)!=0) ? 1 : 0); // 1 = Live time, 0 = True time
    ui->chkPresetTime->setChecked(((oSettings.iAcqMode & 2)!= 0) ? true : false);
    ui->chkPresetCounts->setChecked(((oSettings.iAcqMode & 4)!= 0) ? true : false);
    ui->txtPresetTime->setText(QString("%1").arg(oSettings.sAcqPreset, 0, 'f', 2));
    ui->txtPresetCounts->setText(QString("%1").arg(oSettings.iAcqCounts));
    ui->nmrPresetCountsLLD->setValue(oSettings.iPHAL);
    ui->nmrPresetCountsULD->setValue(oSettings.iPHAH);
    ui->nmrLLD->setValue(oSettings.iLLD);
    ui->nmrULD->setValue(oSettings.iULD);

    // MCS
    ui->txtDwellTime->setText(QString("%1").arg(oSettings.sDwell, 0, 'f', 2));

    ui->nmrMCSLLD->setValue(oSettings.iSCAL);
    ui->nmrMCSULD->setValue(oSettings.iSCAH);

    // Amplifier
    ui->cmbCoarseGain->setCurrentIndex(oSettings.iGainCoarse);
    ui->sldrFineGain->setMaximum(oSettings.iGainFineMax);
    ui->sldrFineGain->setValue(oSettings.iGainFine);
    float sTemp = (((float)oSettings.iGainFine / (float)(oSettings.iGainFineMax-1)) + 1);
    ui->lblFineGainVal->setText(QString("%1").arg(sTemp, 0, 'f', 3));

    ui->cmbDigitalGain->setCurrentIndex(oSettings.iGainDigital);

    ui->nmrThreshold->setValue(oSettings.iThreshold);
    ui->cmbRT->setCurrentIndex(oSettings.iRiseTime);
    ui->cmbFT->setCurrentIndex(oSettings.iFlatTop);
    ui->cmbPZ->setCurrentIndex(oSettings.iPZcanc);

    ui->chkBLR->setChecked((oSettings.iBLRenable!=0) ? true : false);
    ui->chkPUR->setChecked((oSettings.iPURenable!=0) ? true : false);

    if (oSettings.iInpPolarity!=0)
    {
        ui->rbPositive->setChecked(true);
        ui->rbNegative->setChecked(false);	// negated (inverted) negative is positive (gotta make this clearer for the user)
    }
    else
    {
        ui->rbPositive->setChecked(false);
        ui->rbNegative->setChecked(true);
    }

    ui->nmrVolt->setValue(oSettings.sHVvalue);
    ui->chkHVON->setChecked(((oSettings.iHVstatus & DEF_MCA_HV_STATUS_ON) != 0) ? true : false);

    // Clear updating flag
    bUpdateShowing=false;

    return true;
}
