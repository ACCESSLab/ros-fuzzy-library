//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef OUTTABLEDIALOG_H
#define OUTTABLEDIALOG_H

#include <QDialog>
#include "outputdialog.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include "commondef.h"

namespace Ui {
class outtableDialog;
}

class outtableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outtableDialog(MainWindow_t* pstData_i, QWidget *parent = 0);
    ~outtableDialog();

private slots:
    void on_outtableadd_released();

    void on_outtablebbox_accepted();

private:

    void AddItemsToList(OutputData_t stOutData);
private:
    Ui::outtableDialog *ui;
    enum column{
        Name, Range, NumMFs
    };
    MainWindow_t* m_pstData;
    QVector<OutputData_t> m_vstOutputData;
};

#endif // OUTTABLEDIALOG_H
