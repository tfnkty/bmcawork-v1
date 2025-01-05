#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "DIMHW.h"
#include "mcasettings.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();    
private:
    Ui::Settings *ui;

    HANDLE m_hMCA=NULL;
    MCASettings m_oMCASettings;
    bool bUpdateShowing=false;
public:
    void setMCAHandle(HANDLE hMCA);
    HANDLE MCAHandle();
private slots:
    void showEvent(QShowEvent *event);
    // LineEdit
    void txtPresetTime_editingFinished();
    void txtPresetCounts_editingFinished();
    void txtDwellTime_editingFinished();
    // Radionbutton
    void rbPHA_rbMCS_toggled(const bool);
    void rbPositive_rbNegative_toggled(const bool);
    // Checkbox
    void chkPresetTime_toggled(const bool);
    void chkPresetCounts_toggled(const bool);
    void chkBLR_toggled(const bool);
    void chkPUR_toggled(const bool);
    void chkHVON_toggled(const bool);
    // Spinbox
    void nmrMCSLLD_valueChanged(const int);
    void nmrMCSULD_valueChanged(const int);
    void nmrLLD_valueChanged(const int);
    void nmrULD_valueChanged(const int);
    void nmrPresetCountsLLD_valueChanged(const int);
    void nmrPresetCountsULD_valueChanged(const int);
    void nmrThreshold_valueChanged(const int);
    // DoubleSpinbox
    void nmrVolt_valueChanged(const double);
    // Comboboxes
    void cmbPresetTime_currentIndexChanged(const int);
    void cmbPHAChannels_currentIndexChanged(const int);
    void cmbMCSChannels_currentIndexChanged(const int);
    void cmbCoarseGain_currentIndexChanged(const int);
    void cmbDigitalGain_currentIndexChanged(const int);
    void cmbRT_currentIndexChanged(const int);
    void cmbFT_currentIndexChanged(const int);
    void cmbPZ_currentIndexChanged(const int);
    // Slider
    void sldrFineGain_valueChanged(const int);
    // Buttons
    void cmdAdvanced_clicked();
    void cmdApply_clicked();
    void cmdStore_clicked();
    void cmdClose_clicked();

    bool UpdateGUI(MCASettings oSettings);


};

#endif // SETTINGS_H
