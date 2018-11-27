//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "addrulesdialog.h"
#include "ui_addrulesdialog.h"

addrulesDialog::addrulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrulesDialog)
{
    ui->setupUi(this);
}

addrulesDialog::~addrulesDialog()
{
    delete ui;
}

QString addrulesDialog::anticident() const{
    return ui->anticident->text();
}

QString addrulesDialog::consequent() const{
    return ui->consequent->text();
}

QString addrulesDialog::andor() const{
    return ui->andor->text();
}

double addrulesDialog::weight() const{
    return ui->weight->value();
}

void addrulesDialog::on_buttonBox_accepted()
{
    accept();
}

void addrulesDialog::on_buttonBox_rejected()
{
    reject();
}
