//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef ADDRULESDIALOG_H
#define ADDRULESDIALOG_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

namespace Ui {
class addrulesDialog;
}

class addrulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addrulesDialog(QWidget *parent = 0);
    ~addrulesDialog();

    QString anticident() const;
    QString consequent() const;
    QString andor() const;
    double weight() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addrulesDialog *ui;
};

#endif // ADDRULESDIALOG_H
