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
    XMLReader Mgr(&m_stData);
    Mgr.ReadXMLFile();
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
    acceptDrops();
    CollectData();
    XMLWriter Mgr(&m_stData);
    if(Mgr.SaveXMLFile())
        close();
}

void MainWindow::on_buttonBox_rejected()
{
    close();
}
