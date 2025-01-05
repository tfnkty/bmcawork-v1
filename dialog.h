#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "DIMHW.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();    
private:
    Ui::Dialog *ui;
    QTimer *poTimer=NULL;
    HANDLE m_hMCA=NULL;
private slots:
    void cmdDetector_clicked();
    void cmdSettings_clicked();
    void cmdStart_clicked();
    void cmdStop_clicked();
    void cmdClear_clicked();

    bool UpdateGUI();
};

#endif // DIALOG_H
