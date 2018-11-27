
//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "intabledialog.h"
#include "ui_intabledialog.h"

/*void write_intable(QString flsConfig){
    QFile mFile(flsConfig);

    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() <<"Could not open file for writing.";
        return;
    }

    QTextStream out(&mFile);
    out << "[FLS]" << endl;
    out << "Type = IT-2" << endl;
    mFile.flush();
    mFile.close();
}*/

intableDialog::intableDialog(MainWindow_t* pDate_i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intableDialog), m_pstData(pDate_i)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Input Name"<< "Range"<<"MFs";
    ui->intableWidget->setColumnCount(3);
    ui->intableWidget->setHorizontalHeaderLabels(titles);
    inpCount = 0;
    foreach(InputData_t stIp, m_pstData->vstInputs)
    {
        AddItemToList(stIp);
    }
}

intableDialog::~intableDialog()
{
    delete ui;
}


void intableDialog::on_intableadd_released()
{
    inputDialog indialog;
    indialog.setWindowTitle("Add FLS Input");
    indialog.setModal(true);
    int res = indialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    InputData_t stData = indialog.GetInputData();
    m_vstInputData.push_back(stData);
    AddItemToList(stData);
}

void intableDialog::AddItemToList(InputData_t stData)
{
    ui->intableWidget->insertRow((ui->intableWidget->rowCount()));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, Name, new QTableWidgetItem(stData.sName));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, Range, new QTableWidgetItem(stData.sRange));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, NumMFs, new QTableWidgetItem(QString::number(stData.vstMF.size())));
}

void intableDialog::on_intablebbox_accepted()
{
    m_pstData->vstInputs = m_vstInputData;
    return accept();
}
