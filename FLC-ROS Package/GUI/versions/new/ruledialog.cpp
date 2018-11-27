//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "ruledialog.h"
#include "ui_ruledialog.h"

ruleDialog::ruleDialog(MainWindow_t* pstData_i,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ruleDialog), m_pstData(pstData_i)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Antecedents" << "Consequents" << "Inference (And/Or)" << "Weight";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    foreach(Rule_t stRule, m_pstData->vstRules)
    {
        AddItems(stRule);
    }
}

ruleDialog::~ruleDialog()
{
    delete ui;
}

void ruleDialog::on_buttonBox_accepted()
{
    m_pstData->vstRules = m_vstRules;
    accept();
}

void ruleDialog::on_buttonBox_rejected()
{
    reject();
}

void ruleDialog::on_pushButton_released()
{
    addrulesDialog rdialog;
    rdialog.setWindowTitle("Add Rule");
    rdialog.setModal(true);
    int res = rdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }
    Rule_t stRule;
    stRule.sAntecedent = rdialog.anticident();
    stRule.sConsequent = rdialog.consequent();
    stRule.sInference = rdialog.andor();
    stRule.dWeight = rdialog.weight();
    AddItems(stRule);
    m_vstRules.push_back(stRule);
}

void ruleDialog::AddItems(Rule_t stRule)
{
    ui->tableWidget->insertRow((ui->tableWidget->rowCount()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Anticident, new QTableWidgetItem(stRule.sAntecedent));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Conseqient, new QTableWidgetItem(stRule.sConsequent));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, AndOr, new QTableWidgetItem(stRule.sInference));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Weight, new QTableWidgetItem(QString::number(stRule.dWeight)));
}
