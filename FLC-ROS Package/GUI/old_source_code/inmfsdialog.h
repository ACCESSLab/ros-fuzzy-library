//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef INMFSDIALOG_H
#define INMFSDIALOG_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

namespace Ui {
class inMFsDialog;
}

class inMFsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inMFsDialog(QWidget *parent = 0);
    ~inMFsDialog();

    QString imfName() const;
    QString imfType() const;
    double imfp1() const;
    double imfp2() const;
    double imfp3() const;
    double imfp4() const;
    double imfMax() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::inMFsDialog *ui;
};

#endif // INMFSDIALOG_H
