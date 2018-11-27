//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "outtabledialog.h"
#include "ui_outtabledialog.h"

outtableDialog::outtableDialog(MainWindow_t* pstData_i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outtableDialog), m_pstData(pstData_i)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Output Name"<< "Range" << "MFs";
    ui->outtableWidget->setColumnCount(3);
    ui->outtableWidget->setHorizontalHeaderLabels(titles);
    foreach(OutputData_t stOut, m_pstData->vstOutputs)
    {
        AddItemsToList(stOut);
    }
}

outtableDialog::~outtableDialog()
{
    delete ui;
}

void outtableDialog::on_outtableadd_released()
{

    int res;
    outputDialog outdialog;
    outdialog.setWindowTitle("Add FLS Output");
    outdialog.setModal(true);
    res = outdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }
    OutputData_t stData = outdialog.GetOutputData();
    m_vstOutputData.push_back(stData);
    AddItemsToList(stData);
}

void outtableDialog::AddItemsToList(OutputData_t stOutData)
{

    ui->outtableWidget->insertRow((ui->outtableWidget->rowCount()));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, Name, new QTableWidgetItem(stOutData.sName));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, Range, new QTableWidgetItem(stOutData.sRange));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, NumMFs, new QTableWidgetItem(QString::number(stOutData.vstMF.size())));
}

void outtableDialog::on_outtablebbox_accepted()
{
    m_pstData->vstOutputs = m_vstOutputData;
    return accept();
}
