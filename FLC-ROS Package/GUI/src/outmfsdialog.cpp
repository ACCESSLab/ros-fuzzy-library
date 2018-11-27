//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "outmfsdialog.h"
#include "ui_outmfsdialog.h"

outMFsDialog::outMFsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outMFsDialog)
{
    ui->setupUi(this);
}

outMFsDialog::~outMFsDialog()
{
    delete ui;
}

void outMFsDialog::on_buttonBox_rejected()
{
    reject();
}

void outMFsDialog::on_buttonBox_accepted()
{
    accept();
}

QString outMFsDialog::omfName() const{
    return ui->outMFname->text();
}

QString outMFsDialog::omfType() const{
    return ui->outMFtype->text();
}

double outMFsDialog::omfp1() const{
    return ui->outMFP1->value();
}

double outMFsDialog::omfp2() const{
    return ui->outMFP2->value();
}

double outMFsDialog::omfp3() const{
    return ui->outMFP3->value();
}

double outMFsDialog::omfp4() const{
    return ui->outMFP4->value();
}

double outMFsDialog::omfMax() const{
    return ui->outMFmax->value();
}

QString outMFsDialog::otskc() const{
    return ui->outTSKC->text();
}
