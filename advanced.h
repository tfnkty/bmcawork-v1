#ifndef ADVANCED_H
#define ADVANCED_H

#include <QDialog>
#include "DIMHW.h"
#include "mcasettings.h"

namespace Ui {
class Advanced;
}

class Advanced : public QDialog
{
    Q_OBJECT

public:
    explicit Advanced(QWidget *parent = 0);
    ~Advanced();    
private:
    Ui::Advanced *ui;

    HANDLE m_hMCA=NULL;
    MCASettings m_oMCASettings;
    bool bUpdateShowing=false;
public:
    void setSettings(MCASettings oSettings);
    MCASettings Settings();
    void setMCAHandle(HANDLE hMCA);
    HANDLE MCAHandle();
private slots:
    void showEvent(QShowEvent *event);

    // Radiobuttons
    void rbGPIO1pos_rbGPIO1neg_toggled(const bool);
    void rbGPIO2pos_rbGPIO2neg_toggled(const bool);

    // Checkbox
    void chkExtAcqCtlEnable_toggled(const bool);

    // Spinbox
    void nmrLTtrim_valueChanged(const int);
    void nmrAnalogPZ_valueChanged(const int);

    // Combobox
    void cmbBLRrate_currentIndexChanged(const int);
    void cmbPURguard_currentIndexChanged(const int);
    void cmbTRPguard_currentIndexChanged(const int);

    // Buttons
    void cmbGPIO1_currentIndexChanged(const int);
    void cmbGPIO2_currentIndexChanged(const int);
    void cmdApply_clicked();
    void cmdClose_clicked();

    bool UpdateGUI(MCASettings oSettings);
};

#endif // ADVANCED_H
