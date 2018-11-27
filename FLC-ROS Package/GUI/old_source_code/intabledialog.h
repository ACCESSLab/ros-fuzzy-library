//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef INTABLEDIALOG_H
#define INTABLEDIALOG_H

#include <QDialog>
#include "inputdialog.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QtCore>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
//#include <QtXml>
//#include <QDomElement>>
#include <QVector>

#include "commondef.h"

namespace Ui {
class intableDialog;
}

class intableDialog : public QDialog
{
    Q_OBJECT
protected:
    int inpCount;
public:
    explicit intableDialog(MainWindow_t* pDate_i, QWidget *parent = 0);
    ~intableDialog();

    QString inpname;
    QString inprange;    
    QString Input;
    QString MF;
    int inpMFs;
    //int inpCount;

private slots:
    void on_intableadd_released();

    void on_intablebbox_accepted();

private:

    void AddItemToList(InputData_t stData);

private:
    Ui::intableDialog *ui;
    enum column{
        Name, Range, NumMFs
    };
    MainWindow_t* m_pstData;
    QVector<InputData_t> m_vstInputData;
};

#endif // INTABLEDIALOG_H
