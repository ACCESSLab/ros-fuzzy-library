//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "inputdialog.h"
#include "ui_inputdialog.h"


inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Name" << "Type" << "P1" << "P2" << "P3" << "P4" << "Maximum";
    ui->inMFtable->setColumnCount(7);
    ui->inMFtable->setHorizontalHeaderLabels(titles);
}

inputDialog::~inputDialog()
{
    delete ui;
}

void inputDialog::CollectData()
{
    m_stInputData.sName = ui->inname->text();
    m_stInputData.sRange = ui->inrange->text();
}

void inputDialog::on_addMF_released()
{
    inMFsDialog imfdialog;
    imfdialog.setWindowTitle("Add Input MF");
    imfdialog.setModal(true);
    int res = imfdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    InputMF_t stMFInfo;
    stMFInfo.dP1 = imfdialog.imfp1();;
    stMFInfo.dP2 = imfdialog.imfp2();;
    stMFInfo.dP3 = imfdialog.imfp3();;
    stMFInfo.dP4 = imfdialog.imfp4();;
    stMFInfo.sName = imfdialog.imfName();
    stMFInfo.sType = imfdialog.imfType();
    stMFInfo.dMaximum = imfdialog.imfMax();
    AddItemsToList(stMFInfo);
    m_stInputData.vstMF.push_back(stMFInfo);

//    QString flsConfig3 = "flsConfig.txt";
//    QFile mFile(flsConfig3);
//
//    if(!mFile.open(QFile::WriteOnly | QFile::Append)){
//        qDebug() <<"Could not open file for writing.";
//        return;
//    }
//
//    //intableDialog intd;
//    /*QString main_inpname = inputDialog.indialog.inName();
//    QString main_inprange = indialog.inRange();
//    int main_inpMFs = indialog.inNumMFs();*/
//
//    QTextStream out(&mFile);
//    out << endl;
//    out << "main_inmfpname =" << iMFname << endl;
//    out << "main_inmfprange =" << iMFType <<endl;
//    out << "main_inmfpMFs =" << iMFP1 <<endl;
//    mFile.flush();
//    mFile.close();
}

void inputDialog::AddItemsToList(InputMF_t stMFInfo)
{
    ui->inMFtable->insertRow((ui->inMFtable->rowCount()));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Name, new QTableWidgetItem(stMFInfo.sName));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Type, new QTableWidgetItem(stMFInfo.sType));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P1, new QTableWidgetItem(QString::number(stMFInfo.dP1)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P2, new QTableWidgetItem(QString::number(stMFInfo.dP2)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P3, new QTableWidgetItem(QString::number(stMFInfo.dP3)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P4, new QTableWidgetItem(QString::number(stMFInfo.dP4)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Maximum, new QTableWidgetItem(QString::number(stMFInfo.dMaximum)));

}

QString inputDialog::inName() const{
    return ui->inname->text();
}
QString inputDialog::inRange() const{
    return ui->inrange->text();
}
int inputDialog::inNumMFs() const{
    return ui->numMFs->value();
}

void inputDialog::on_buttonBox_accepted()
{
    CollectData();
    accept();
}

void inputDialog::on_buttonBox_rejected()
{
    reject();
}
