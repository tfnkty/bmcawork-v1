#include "devices.h"
#include "ui_devices.h"

#include <qmessagebox.h>

struct DeviceInfo
{
    QString szPath;
    QString szName;
    QString szSerial;
    int iDeviceType;

    QString ToString()
    {
        return QString("Name: %1 Path: %2 Serial: %3 Type: %4").arg(szName).arg(szPath).arg(szSerial).arg(iDeviceType);
    }
};

Q_DECLARE_METATYPE(DeviceInfo)

Devices::Devices(QWidget *parent) : QDialog(parent), ui(new Ui::Devices)
{
    // Setup GUI
    ui->setupUi(this);

    // Connect events
    connect(ui->cmdSearch, SIGNAL(clicked()), this, SLOT(cmdSearch_clicked()));
    connect(ui->cmdOpen, SIGNAL(clicked()), this, SLOT(cmdOpen_clicked()));
    connect(ui->cmdCancel, SIGNAL(clicked()), this, SLOT(cmdCancel_clicked()));

    // Load GUI

}

Devices::~Devices()
{
    delete ui;
}

void Devices::setMCAHandle(HANDLE hMCA)
{
    m_hMCA = hMCA;
}
HANDLE Devices::MCAHandle()
{
    return m_hMCA;
}

void Devices::cmdSearch_clicked()
{
    int iRet=NULL;
    int iNrOfDevices;

    // Device info
    char szPath[DEF_MCA_STRING_LENGTH];
    char szName[DEF_MCA_STRING_LENGTH];
    char szSerial[DEF_MCA_STRING_LENGTH];
    char szItemText[DEF_MCA_STRING_LENGTH];
    int iDeviceType;

    // Search for detectors
    iNrOfDevices = FindDevicesEx(DEF_MCA_INTFC_ALL, 100, true);

    // Clear the listbox
    ui->lbDevices->clear();

    // Try to open one
    for (int iLoop=0; iLoop < iNrOfDevices; iLoop++)
    {
        // Get device info
        GetDeviceInfo(iLoop, szPath, DEF_MCA_STRING_LENGTH, szName, DEF_MCA_STRING_LENGTH, szSerial, DEF_MCA_STRING_LENGTH, &iDeviceType);

        // Make the listbox string
        sprintf(szItemText, "Name: %s Path: %s Serial: %s Type: %d", szName, szPath, szSerial, iDeviceType);

        DeviceInfo oDevInfo;
        oDevInfo.szName.clear();
        oDevInfo.szName.append(szName);
        oDevInfo.szPath.clear();
        oDevInfo.szPath.append(szPath);
        oDevInfo.szSerial.clear();
        oDevInfo.szSerial.append(szSerial);
        oDevInfo.iDeviceType = iDeviceType;

        QVariant oDevInfoData;
        oDevInfoData.setValue(oDevInfo);

        // Add the device to the listbox
        QListWidgetItem *poWidgetItem = new QListWidgetItem();
        poWidgetItem->setText(oDevInfo.ToString());
        poWidgetItem->setData(Qt::UserRole, oDevInfoData);

        ui->lbDevices->addItem(poWidgetItem);
    }
}
void Devices::cmdOpen_clicked()
{
    int iRet=NULL;

    // Get selected item
    if(ui->lbDevices->selectedItems().count() > 0)
    {
        QListWidgetItem *poItem = ui->lbDevices->selectedItems().at(0);
        QVariant oDevInfoData = poItem->data(Qt::UserRole);
        DeviceInfo oDevInfo = oDevInfoData.value<DeviceInfo>();

        // Try to open the detector
        iRet = OpenDeviceEx(oDevInfo.szPath.toLatin1().data(), oDevInfo.iDeviceType, &m_hMCA , 2000);
        if (iRet == MCA_SUCCESS)
        {
            // Close form
            this->close();
        }
        else
        {
            // Error
            QMessageBox msgBox;
            msgBox.setText("Error");
            msgBox.setInformativeText("Error opening detector?");
            msgBox.exec();

            // reset handle
            m_hMCA = NULL;
            // Return
            return;
        }
    }
}
void Devices::cmdCancel_clicked()
{
    // Close form
    this->close();
}
