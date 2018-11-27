//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "addrulesdialog.h"
#include "inmfsdialog.h"
#include "inputdialog.h"
#include "intabledialog.h"
#include "mainwindow.h"
#include "outmfsdialog.h"
#include "outputdialog.h"
#include "outtabledialog.h"
#include "ruledialog.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
