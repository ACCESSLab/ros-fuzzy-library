//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "outputdialog.h"
#include "ui_outputdialog.h"

outputDialog::outputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Name" << "Type" << "P1" << "P2" << "P3" << "P4" << "Maximum" << "TSK Coefficients";
    ui->outMFtable->setColumnCount(8);
    ui->outMFtable->setHorizontalHeaderLabels(titles);
}

outputDialog::~outputDialog()
{
    delete ui;
}

void outputDialog::on_buttonBox_accepted()
{
    m_stOutputData.sName = outName();
    m_stOutputData.sRange = outRange();
    accept();
}

void outputDialog::on_buttonBox_rejected()
{
    reject();
}

void outputDialog::on_addMF_released()
{
    outMFsDialog omfdialog;
    omfdialog.setWindowTitle("Add Output MF");
    omfdialog.setModal(true);
    int res = omfdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    OutputMF_t stMFInfo;
    stMFInfo.dP1 = omfdialog.omfp1();
    stMFInfo.dP2 = omfdialog.omfp2();
    stMFInfo.dP3 = omfdialog.omfp3();
    stMFInfo.dP4 = omfdialog.omfp4();
    stMFInfo.sName = omfdialog.omfName();
    stMFInfo.sType = omfdialog.omfType();
    stMFInfo.dMaximum = omfdialog.omfMax();
    stMFInfo.sTSKCoefficients = omfdialog.otskc();
    m_stOutputData.vstMF.push_back(stMFInfo);
    AddItemsToList(stMFInfo);
}

void outputDialog::AddItemsToList(OutputMF_t stMFInfo)
{
    ui->outMFtable->insertRow((ui->outMFtable->rowCount()));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Name, new QTableWidgetItem(stMFInfo.sName));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Type, new QTableWidgetItem(stMFInfo.sType));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P1, new QTableWidgetItem(QString::number(stMFInfo.dP1)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P2, new QTableWidgetItem(QString::number(stMFInfo.dP2)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P3, new QTableWidgetItem(QString::number(stMFInfo.dP3)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P4, new QTableWidgetItem(QString::number(stMFInfo.dP4)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Maximum, new QTableWidgetItem(QString::number(stMFInfo.dMaximum)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, TSKC, new QTableWidgetItem(stMFInfo.sTSKCoefficients));
}

QString outputDialog::outName() const{
    return ui->outname->text();
}
QString outputDialog::outRange() const{
    return ui->outrange->text();
}
int outputDialog::outNumMFs() const{
    return ui->numMFs->value();
}
