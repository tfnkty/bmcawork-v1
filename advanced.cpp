#include "advanced.h"
#include "ui_advanced.h"

#include <qstring.h>

Advanced::Advanced(QWidget *parent) : QDialog(parent), ui(new Ui::Advanced)
{
    ui->setupUi(this);

    // Connect events

    // Radiobuttons
    connect(ui->rbGPIO1pos, SIGNAL(toggled(bool)), this, SLOT(rbGPIO1pos_rbGPIO1neg_toggled(const bool)));
    connect(ui->rbGPIO1neg, SIGNAL(toggled(bool)), this, SLOT(rbGPIO1pos_rbGPIO1neg_toggled(const bool)));
    connect(ui->rbGPIO2pos, SIGNAL(toggled(bool)), this, SLOT(rbGPIO2pos_rbGPIO2neg_toggled(const bool)));
    connect(ui->rbGPIO2neg, SIGNAL(toggled(bool)), this, SLOT(rbGPIO2pos_rbGPIO2neg_toggled(const bool)));

    // Checkbox
    connect(ui->chkExtAcqCtlEnable, SIGNAL(toggled(bool)), this, SLOT(chkExtAcqCtlEnable_toggled(const bool)));

    // Spinbox
    connect(ui->nmrLTtrim, SIGNAL(valueChanged(int)), this, SLOT(nmrLTtrim_valueChanged(const int)));
    connect(ui->nmrAnalogPZ, SIGNAL(valueChanged(int)), this, SLOT(nmrAnalogPZ_valueChanged(const int)));

    // Combobox
    connect(ui->cmbBLRrate, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbBLRrate_currentIndexChanged(const int)));
    connect(ui->cmbPURguard, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbPURguard_currentIndexChanged(const int)));
    connect(ui->cmbTRPguard, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbTRPguard_currentIndexChanged(const int)));

    connect(ui->cmbGPIO1, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbGPIO1_currentIndexChanged(const int)));
    connect(ui->cmbGPIO2, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbGPIO2_currentIndexChanged(const int)));

    // Buttons
    connect(ui->cmdApply, SIGNAL(clicked()), this, SLOT(cmdApply_clicked()));
    connect(ui->cmdClose, SIGNAL(clicked()), this, SLOT(cmdClose_clicked()));
}

Advanced::~Advanced()
{
    delete ui;
}

void Advanced::showEvent(QShowEvent *event)
{
    // Parent function
    QDialog::showEvent(event);

    // Init controls
    ui->nmrLTtrim->setRange(0, 1000);
    ui->nmrLTtrim->setSingleStep(1);

    ui->nmrAnalogPZ->setRange(0, 4095);
    ui->nmrAnalogPZ->setSingleStep(1);

    // Load MCA parameters
    ReadMCAParams(m_hMCA, m_oMCASettings);

    // Show settings
    UpdateGUI(m_oMCASettings);

    // Disable Apply
    ui->cmdApply->setEnabled(false);
}
void Advanced::setMCAHandle(HANDLE hMCA)
{
    m_hMCA = hMCA;
}
HANDLE Advanced::MCAHandle()
{
    return m_hMCA;
}
void Advanced::setSettings(MCASettings oSettings)
{
    m_oMCASettings = oSettings;
}
MCASettings Advanced::Settings()
{
    return m_oMCASettings;
}

// Radiobuttons
void Advanced::rbGPIO1pos_rbGPIO1neg_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    if (ui->rbGPIO1pos->isChecked())
        m_oMCASettings.iGPIO1polarity = 1;
    else
        m_oMCASettings.iGPIO1polarity = 0;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::rbGPIO2pos_rbGPIO2neg_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    if (ui->rbGPIO2pos->isChecked())
        m_oMCASettings.iGPIO2polarity = 1;
    else
        m_oMCASettings.iGPIO2polarity = 0;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Checkbox
void Advanced::chkExtAcqCtlEnable_toggled(const bool)
{
    if(bUpdateShowing)
        return;

    if (ui->chkExtAcqCtlEnable->isChecked())
        m_oMCASettings.iAcqMode |= DEF_MCA_ACQ_MODE_EXT_CONTROL;
    else
        m_oMCASettings.iAcqMode &= ~DEF_MCA_ACQ_MODE_EXT_CONTROL;

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Spinbox
void Advanced::nmrLTtrim_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iLTtrim = ui->nmrLTtrim->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::nmrAnalogPZ_valueChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iAnalogPZ = ui->nmrAnalogPZ->value();

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Combobox
void Advanced::cmbBLRrate_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    //m_oMCASettings.iBLRrate = ui->cmbBLRrate->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::cmbPURguard_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iPURguard = ui->cmbPURguard->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::cmbTRPguard_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iTRPguard = ui->cmbTRPguard->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::cmbGPIO1_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iGPIO1mode = ui->cmbGPIO1->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}
void Advanced::cmbGPIO2_currentIndexChanged(const int)
{
    if(bUpdateShowing)
        return;

    m_oMCASettings.iGPIO2mode = ui->cmbGPIO2->currentIndex();

    // Enable the apply button
    ui->cmdApply->setEnabled(true);
}

// Buttons
void Advanced::cmdApply_clicked()
{
    // Save MCA parameters
    WriteMCAParams(m_hMCA, m_oMCASettings);

    // Reload UI
    UpdateGUI(m_oMCASettings);

    // Disable the apply button
    ui->cmdApply->setEnabled(false);
}
void Advanced::cmdClose_clicked()
{
    // Close form
    this->close();
}

bool Advanced::UpdateGUI(MCASettings oSettings)
{
    float sADCdwell;
    float sTemp;

    // Check if we're alrady updating
    if (bUpdateShowing)
        return false;

    // Set updating flag
    bUpdateShowing=true;

    if (oSettings.iADCrate == 0)
        oSettings.iADCrate = 25000000;
    sADCdwell = (float)1000000 / (float)oSettings.iADCrate;

    // Extended LT
    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_EXTENDED_LT) != 0)
    {
        ui->lblLTtrim->setEnabled(true);
        ui->nmrLTtrim->setEnabled(true);
        ui->nmrLTtrim->setValue(oSettings.iLTtrim);
    }
    else
    {
        ui->lblLTtrim->setEnabled(false);
        ui->nmrLTtrim->setEnabled(false);
        ui->nmrLTtrim->setValue(0);
    }

    // BLR rate - not implemented
    ui->cmbBLRrate->clear();

    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_BLR_RATE) != 0)
    {
        ui->lblBLRrate->setEnabled(true);
        ui->cmbBLRrate->setEnabled(true);
        ui->cmbBLRrate->setCurrentIndex(oSettings.iBLRrate);
    }
    else
    {
        ui->lblBLRrate->setEnabled(false);
        ui->cmbBLRrate->setEnabled(false);
        ui->cmbBLRrate->setCurrentIndex(0);
    }

    // PUR guard
    ui->cmbPURguard->clear();
    for (int iLoop = 0; iLoop < 2048; iLoop++)
    {
        sTemp = (float)(iLoop * sADCdwell);
        ui->cmbPURguard->addItem(QString("%1 µs").arg(sTemp, 0, 'f', 2));
    }

    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PUR_GUARD) != 0)
    {
        ui->lblPURguard->setEnabled(true);
        ui->cmbPURguard->setEnabled(true);
        ui->cmbPURguard->setCurrentIndex(oSettings.iPURguard);
    }
    else
    {
        ui->lblPURguard->setEnabled(false);
        ui->cmbPURguard->setEnabled(false);
        ui->cmbPURguard->setCurrentIndex(0);
    }

    // TRP guard
    ui->cmbTRPguard->clear();
    for (int iLoop = 0; iLoop < 1024; iLoop++)
    {
        sTemp = (float)(iLoop * sADCdwell);
        ui->cmbTRPguard->addItem(QString("%1 µs").arg(sTemp, 0, 'f', 2));
    }

    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_TRP_GUARD) != 0)
    {
        ui->lblTRPguard->setEnabled(true);
        ui->cmbTRPguard->setEnabled(true);
        ui->cmbTRPguard->setCurrentIndex(oSettings.iTRPguard);
    }
    else
    {
        ui->lblTRPguard->setEnabled(false);
        ui->cmbTRPguard->setEnabled(false);
        ui->cmbTRPguard->setCurrentIndex(0);
    }

    // Analog PZ
    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_ANALOG_PZ) != 0)
    {
        ui->lblAnalogPZ->setEnabled(true);
        ui->nmrAnalogPZ->setEnabled(true);
        ui->nmrAnalogPZ->setValue(oSettings.iAnalogPZ);
    }
    else
    {
        ui->lblAnalogPZ->setEnabled(false);
        ui->nmrAnalogPZ->setEnabled(false);
        ui->nmrAnalogPZ->setValue(0);
    }

    // GPIO
    ui->cmbGPIO1->clear();
    ui->cmbGPIO2->clear();
    if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_GPIO) != 0)
    {
        ui->cmbGPIO1->addItem("NOP");
        ui->cmbGPIO1->addItem("Ext counter 1 input");
        ui->cmbGPIO1->addItem("Ext counter 2 input");
        ui->cmbGPIO1->addItem("ROI 1 output");
        ui->cmbGPIO1->addItem("ROI 2 output");
        ui->cmbGPIO1->addItem("ICR output");
        ui->cmbGPIO1->addItem("OCR output");
        ui->cmbGPIO1->addItem("TRP input");
        ui->cmbGPIO1->addItem("TRP output");
        ui->cmbGPIO1->addItem("HV inhibit input");
        ui->cmbGPIO1->addItem("HV ON output");
        ui->cmbGPIO1->addItem("Acq start input");
        ui->cmbGPIO1->addItem("Acq stop input");
        ui->cmbGPIO1->addItem("Acq start/stop input");
        ui->cmbGPIO1->addItem("Acq suspend/resume input");
        ui->cmbGPIO1->addItem("Acq suspended output");
        ui->cmbGPIO1->addItem("Acq status output");
        ui->cmbGPIO1->addItem("Acq start/stop output");
        ui->cmbGPIO1->addItem("Acq start waiting output");
        ui->cmbGPIO1->addItem("MCS channel advance input");
        ui->cmbGPIO1->addItem("MCS channel advance output");
        ui->cmbGPIO1->addItem("MCS ready output");
        ui->cmbGPIO1->addItem("MCS sweep advance input");
        ui->cmbGPIO1->addItem("MCS sweep advance output");
        ui->cmbGPIO1->addItem("Coincidence input");
        ui->cmbGPIO1->addItem("Anticoincidence input");
        ui->cmbGPIO1->addItem("Live time gate output");
        ui->cmbGPIO1->addItem("TLIST sync input");
        ui->cmbGPIO1->addItem("TLIST sync output");
        ui->cmbGPIO1->addItem("Pulse generator 1 output");
        ui->cmbGPIO1->addItem("Pulse generator 2 output");
        ui->cmbGPIO1->addItem("Ext user input 1");
        ui->cmbGPIO1->addItem("Ext user input 2");
        ui->cmbGPIO1->addItem("Ext user output");
        //ui->cmbGPIO1->addItem("PHA group selection");

        ui->cmbGPIO2->addItem("NOP");
        ui->cmbGPIO2->addItem("Ext counter 2 input");
        ui->cmbGPIO2->addItem("Ext counter 2 input");
        ui->cmbGPIO2->addItem("ROI 2 output");
        ui->cmbGPIO2->addItem("ROI 2 output");
        ui->cmbGPIO2->addItem("ICR output");
        ui->cmbGPIO2->addItem("OCR output");
        ui->cmbGPIO2->addItem("TRP input");
        ui->cmbGPIO2->addItem("TRP output");
        ui->cmbGPIO2->addItem("HV inhibit input");
        ui->cmbGPIO2->addItem("HV ON output");
        ui->cmbGPIO2->addItem("Acq start input");
        ui->cmbGPIO2->addItem("Acq stop input");
        ui->cmbGPIO2->addItem("Acq start/stop input");
        ui->cmbGPIO2->addItem("Acq suspend/resume input");
        ui->cmbGPIO2->addItem("Acq suspended output");
        ui->cmbGPIO2->addItem("Acq status output");
        ui->cmbGPIO2->addItem("Acq start/stop output");
        ui->cmbGPIO2->addItem("Acq start waiting output");
        ui->cmbGPIO2->addItem("MCS channel advance input");
        ui->cmbGPIO2->addItem("MCS channel advance output");
        ui->cmbGPIO2->addItem("MCS ready output");
        ui->cmbGPIO2->addItem("MCS sweep advance input");
        ui->cmbGPIO2->addItem("MCS sweep advance output");
        ui->cmbGPIO2->addItem("Coincidence input");
        ui->cmbGPIO2->addItem("Anticoincidence input");
        ui->cmbGPIO2->addItem("Live time gate output");
        ui->cmbGPIO2->addItem("TLIST sync input");
        ui->cmbGPIO2->addItem("TLIST sync output");
        ui->cmbGPIO2->addItem("Pulse generator 2 output");
        ui->cmbGPIO2->addItem("Pulse generator 2 output");
        ui->cmbGPIO2->addItem("Ext user input 2");
        ui->cmbGPIO2->addItem("Ext user input 2");
        ui->cmbGPIO2->addItem("Ext user output");
        //ui->cmbGPIO2->addItem("PHA group selection");
    }
    else
    {
        ui->cmbGPIO1->addItem("Ext counter input");
        ui->cmbGPIO1->addItem("ROI output");

        ui->cmbGPIO2->addItem("Ext counter input");
        ui->cmbGPIO2->addItem("ROI output");
    }

    if ((oSettings.iMCAcaps & (DEF_MCACAPS_SUPPORTS_EXT_COUNTER | DEF_MCACAPS_SUPPORTS_GPIO)) != 0)
    {
        ui->fraGPIO->setEnabled(true);
        if ((oSettings.iMCAcaps & DEF_MCACAPS_SUPPORTS_GPIO) != 0)
        {
            // Topaz-X
            ui->chkExtAcqCtlEnable->setEnabled(true);
            ui->chkExtAcqCtlEnable->setChecked((oSettings.iAcqMode & DEF_MCA_ACQ_MODE_EXT_CONTROL) != 0);

            ui->lblGPIO1->setEnabled(true);
            ui->cmbGPIO1->setEnabled(true);
            ui->cmbGPIO1->setCurrentIndex(oSettings.iGPIO1mode);
            ui->rbGPIO1pos->setEnabled(true);
            ui->rbGPIO1pos->setChecked(oSettings.iGPIO1polarity == 0);
            ui->rbGPIO1neg->setEnabled(true);
            ui->rbGPIO1neg->setChecked(oSettings.iGPIO1polarity != 0);

            ui->lblGPIO2->setEnabled(true);
            ui->cmbGPIO2->setEnabled(true);
            ui->cmbGPIO2->setCurrentIndex(oSettings.iGPIO2mode);
            ui->rbGPIO2pos->setEnabled(true);
            ui->rbGPIO2pos->setChecked(oSettings.iGPIO2polarity == 0);
            ui->rbGPIO2neg->setEnabled(true);
            ui->rbGPIO2neg->setChecked(oSettings.iGPIO2polarity != 0);
        }
        else
        {
            // Topaz pico
            ui->chkExtAcqCtlEnable->setEnabled(false);
            ui->chkExtAcqCtlEnable->setChecked(false);

            ui->lblGPIO1->setEnabled(true);
            ui->cmbGPIO1->setEnabled(true);
            ui->cmbGPIO1->setCurrentIndex(oSettings.iGPIO1mode);
            ui->rbGPIO1pos->setEnabled(false);
            ui->rbGPIO1neg->setEnabled(false);

            ui->lblGPIO2->setEnabled(false);
            ui->cmbGPIO2->setEnabled(false);
            ui->cmbGPIO2->setCurrentIndex(0);
            ui->rbGPIO2pos->setEnabled(false);
            ui->rbGPIO2neg->setEnabled(false);
        }
    }
    else
    {
        ui->fraGPIO->setEnabled(false);

        ui->chkExtAcqCtlEnable->setEnabled(false);
        ui->chkExtAcqCtlEnable->setChecked(false);

        ui->lblGPIO1->setEnabled(false);
        ui->cmbGPIO1->setEnabled(false);
        ui->cmbGPIO1->setCurrentIndex(0);
        ui->rbGPIO1pos->setEnabled(false);
        ui->rbGPIO1neg->setEnabled(false);

        ui->lblGPIO2->setEnabled(false);
        ui->cmbGPIO2->setEnabled(false);
        ui->cmbGPIO2->setCurrentIndex(0);
        ui->rbGPIO2pos->setEnabled(false);
        ui->rbGPIO2neg->setEnabled(false);
    }

    // Stop loading settings
    bUpdateShowing = false;

    return true;
}
