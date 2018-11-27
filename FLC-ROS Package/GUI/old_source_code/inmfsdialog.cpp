//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "inmfsdialog.h"
#include "ui_inmfsdialog.h"

inMFsDialog::inMFsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inMFsDialog)
{
    ui->setupUi(this);
}

inMFsDialog::~inMFsDialog()
{
    delete ui;
}

void inMFsDialog::on_buttonBox_accepted()
{
    accept();
}

void inMFsDialog::on_buttonBox_rejected()
{
    reject();
}

QString inMFsDialog::imfName() const{
    return ui->inMFname->text();
}

QString inMFsDialog::imfType() const{
    return ui->inMFtype->text();
}

double inMFsDialog::imfp1() const{
    return ui->inMFP1->value();
}

double inMFsDialog::imfp2() const{
    return ui->inMFP2->value();
}

double inMFsDialog::imfp3() const{
    return ui->inMFP3->value();
}

double inMFsDialog::imfp4() const{
    return ui->inMFP4->value();
}

double inMFsDialog::imfMax() const{
    return ui->inMFmax->value();
}
