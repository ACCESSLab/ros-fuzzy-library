//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QMap>
#include <QDebug>
#include "XMLWriter.h"
#include "XMLReader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Fuzzabel FLS Library");

    //QPixmap picat("C:/Users/Abel/Documents/FLS Library Cui v2/FLS_Library_Gui/build-FLS_Library_Gui-Desktop-Debug/NCA&T_Interlock_Lettermark.png");
    //ui->label_atpic->setPixmap(picat);
    QPixmap picacs("C:/Users/Abel/Documents/FLS Library Cui v2/FLS_Library_Gui/build-FLS_Library_Gui-Desktop-Debug/accesslab.jpg");
    ui->label_acpic->setPixmap(picacs);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CollectData()
{
    m_stData.sFLSName           = ui->lineEdit->text();
    m_stData.bType1             = ui->radioButton->isChecked();
    m_stData.bInterval2         = ui->radioButton_2->isChecked();
    m_stData.bTSK               = ui->radioButton_4->isChecked();
    m_stData.bMamdani           = ui->radioButton_3->isChecked();
    m_stData.nNumberOfInputs    = ui->spinBox_numins->text().toInt();
    m_stData.nNumberOFOutputs   = ui->spinBox_numouts->text().toInt();
    m_stData.nNumberOfRules     = ui->spinBox_numrules->text().toInt();
    m_stData.sProcessingMethod  = ui->comboBox_5->currentText();
    m_stData.sAndMethod         = ui->comboBox->currentText();
    m_stData.sOrMethod          = ui->comboBox_2->currentText();
    m_stData.sAggMethod         = ui->comboBox_3->currentText();
    m_stData.sImplicationMethod = ui->comboBox_4->currentText();
}

void MainWindow::on_pushButton_2_released()
{
    intableDialog intdialog(&m_stData, this);
    intdialog.setWindowTitle("Input");
    intdialog.setModal(true);
    intdialog.exec();
}

void MainWindow::on_pushButton_3_released()
{
    outtableDialog outtdialog(&m_stData, this);
    outtdialog.setWindowTitle("Output");
    outtdialog.setModal(true);
    outtdialog.exec();
}

void MainWindow::on_pushButton_4_released()
{
    ruleDialog rdialog(&m_stData, this);
    rdialog.setWindowTitle("Rule");
    rdialog.setModal(true);
    rdialog.exec();
}

void MainWindow::on_buttonBox_accepted()
{
    QString dir = "";
    dir = QFileDialog::getSaveFileName(this, tr("Open Directory"), "");
    if (dir == "")
        return;
    acceptDrops();
    CollectData();
    XMLWriter Mgr(&m_stData);
    if(Mgr.SaveXMLFile(dir))
        close();
}

void MainWindow::on_buttonBox_rejected()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    QString dir = "";
    dir = QFileDialog::getOpenFileName(this, tr("Open Directory"), "");
    if (dir == "")
        return;
    XMLReader Mgr(&m_stData);
    Mgr.ReadXMLFile(dir);

    ui->lineEdit->setText(m_stData.sFLSName);
    ui->radioButton->setChecked(m_stData.bType1);
    ui->radioButton_2->setChecked(m_stData.bInterval2);
    ui->radioButton_4->setChecked(m_stData.bTSK);
    ui->radioButton_3->setChecked(m_stData.bMamdani);
    ui->spinBox_numins->setValue(m_stData.nNumberOfInputs);
    ui->spinBox_numouts->setValue(m_stData.nNumberOFOutputs);
    ui->spinBox_numrules->setValue(m_stData.nNumberOfRules);
    ui->comboBox_5->setCurrentText(m_stData.sProcessingMethod);
    ui->comboBox->setCurrentText(m_stData.sAndMethod);
    ui->comboBox_2->setCurrentText(m_stData.sOrMethod);
    ui->comboBox_3->setCurrentText(m_stData.sAggMethod);
    ui->comboBox_4->setCurrentText(m_stData.sImplicationMethod);
}
