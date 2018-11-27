//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef OUTMFSDIALOG_H
#define OUTMFSDIALOG_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

namespace Ui {
class outMFsDialog;
}

class outMFsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outMFsDialog(QWidget *parent = 0);
    ~outMFsDialog();

    QString omfName() const;
    QString omfType() const;
    double omfp1() const;
    double omfp2() const;
    double omfp3() const;
    double omfp4() const;
    double omfMax() const;
    QString otskc() const;

private slots:

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();
private:
    Ui::outMFsDialog *ui;
};

#endif // OUTMFSDIALOG_H
