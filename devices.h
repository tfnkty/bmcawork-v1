#ifndef DEVICES_H
#define DEVICES_H

#include <QDialog>
#include "DIMHW.h"

namespace Ui {
class Devices;
}

class Devices : public QDialog
{
    Q_OBJECT

public:
    explicit Devices(QWidget *parent = 0);
    ~Devices();
    void setMCAHandle(HANDLE hMCA);
    HANDLE MCAHandle();
private:
    Ui::Devices *ui;

    HANDLE m_hMCA=NULL;
private slots:
    void cmdSearch_clicked();
    void cmdOpen_clicked();
    void cmdCancel_clicked();
};

#endif // DEVICES_H
