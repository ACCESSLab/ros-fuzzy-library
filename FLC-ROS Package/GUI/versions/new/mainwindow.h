//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include "intabledialog.h"
#include "outtabledialog.h"
#include "ruledialog.h"
#include <QtCore>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFileDialog>
//#include <QtXML>
#include "commondef.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void CollectData();
private slots:
    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow_t m_stData;
};

#endif // MAINWINDOW_H
