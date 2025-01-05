#include "dialog.h"
#include "ui_dialog.h"
#include "graphplot.h"
#include "devices.h"
#include "Settings.h"
#include "DIMHW.h"

#include <iostream>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    // Setup GUI
    ui->setupUi(this);

    // Connect events
    connect(ui->cmdDetector, SIGNAL(clicked()), this, SLOT(cmdDetector_clicked()));
    connect(ui->cmdSettings, SIGNAL(clicked()), this, SLOT(cmdSettings_clicked()));
    connect(ui->cmdStart, SIGNAL(clicked()), this, SLOT(cmdStart_clicked()));
    connect(ui->cmdStop, SIGNAL(clicked()), this, SLOT(cmdStop_clicked()));
    connect(ui->cmdClear, SIGNAL(clicked()), this, SLOT(cmdClear_clicked()));


    // Initial loading
    ui->cmdDetector->setEnabled(true);
    ui->cmdSettings->setEnabled(false);
    ui->cmdStart->setEnabled(false);
    ui->cmdStop->setEnabled(false);
    ui->cmdClear->setEnabled(false);
    ui->SpectrumPlot->setNrOfChannels(1024);
    ui->SpectrumPlot->ClearSpectrum();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::cmdDetector_clicked()
{
    if (m_hMCA)
    {
        // Active handle close it
        CloseDevice(m_hMCA);
        m_hMCA = NULL;

        // Change button text back to open
        ui->cmdDetector->setText("Open");

        ui->cmdSettings->setEnabled(false);
        ui->cmdStart->setEnabled(false);
        ui->cmdStop->setEnabled(false);
        ui->cmdClear->setEnabled(false);
    }
    else
    {
        // Null handle, open dialog to open new
        Devices *poDevices = new Devices();
        poDevices->exec();
        m_hMCA = poDevices->MCAHandle();
        delete poDevices;

        if (!m_hMCA)
            return;

        // Set HV
        int iVal=1;
        int iRet=SetParam(m_hMCA, DEF_MCA_PARAM_HV_STATUS, &iVal, 4);
        if(iRet!=MCA_SUCCESS)
            return;

        // Update GUI
        UpdateGUI();

        // Change button text to close
        ui->cmdDetector->setText("Close");        

        ui->cmdSettings->setEnabled(true);
        ui->cmdStart->setEnabled(true);
        ui->cmdStop->setEnabled(true);
        ui->cmdClear->setEnabled(true);
    }
}
void Dialog::cmdSettings_clicked()
{
    Settings *poSettings = new Settings(this);
    poSettings->setMCAHandle(m_hMCA);
    poSettings->exec();
}
void Dialog::cmdStart_clicked()
{
    if (!m_hMCA)
        return;

    // Start acquisition
    StartAcquisition(m_hMCA);

    // Start update timer
    if(!poTimer)
    {
        poTimer=new QTimer(this);
        connect(poTimer, SIGNAL(timeout()), this, SLOT(UpdateGUI()) );
    }

    poTimer->setInterval(500);
    poTimer->start();
    std::cout << "Started" << std::endl;
}
void Dialog::cmdStop_clicked()
{
    if (!m_hMCA)
        return;

    // Stop acquisition
    StopAcquisition(m_hMCA);

    // Update spectrum
    UpdateGUI();

    // Stop update timer
    if(poTimer)
        poTimer->stop();
}
void Dialog::cmdClear_clicked()
{
    if (!m_hMCA)
        return;

    // Clear all
    ClearAll(m_hMCA);

    // Update spectrum
    UpdateGUI();
}

bool Dialog::UpdateGUI()
{
    int iRet=0;
    uint32_t *palSpectrum;
    uint32_t iNrOfChannels;
    float sElapsedLiveTime=0.0;
    float sElapsedRealTime=0.0;

    // Check if the handle is valid
    if (m_hMCA == NULL)
        return false;

    // Get a nr of channels from the detector
    iRet = GetParam(m_hMCA, DEF_MCA_PARAM_NUM_CHANNELS, &iNrOfChannels, 4);
    if (iRet != MCA_SUCCESS)        
        return false;

    // redimension spectrum array
    palSpectrum = (uint32_t*)malloc(sizeof(uint32_t) * iNrOfChannels);
    // Get a spectrum from the detector
    iRet = ReadSpectrum(m_hMCA, palSpectrum, &iNrOfChannels, &sElapsedRealTime, &sElapsedLiveTime);
    if (iRet != MCA_SUCCESS)
        return false;

    // Update the spectrum
    ui->SpectrumPlot->setNrOfChannels(iNrOfChannels);
    ui->SpectrumPlot->setSpectrum(palSpectrum, iNrOfChannels);

    // Update livetime and realtime
    ui->txtLivetime->setText(QString("%1").arg(sElapsedLiveTime));
    ui->txtRealtime->setText(QString("%1").arg(sElapsedRealTime));

    // return
    return true;
}
