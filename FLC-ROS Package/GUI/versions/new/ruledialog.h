//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef RULEDIALOG_H
#define RULEDIALOG_H

#include <QDialog>
#include "addrulesdialog.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include "commondef.h"

namespace Ui {
class ruleDialog;
}

class ruleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ruleDialog(MainWindow_t* pstData_i, QWidget *parent = 0);
    ~ruleDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_released();
private:
    void AddItems(Rule_t stRule);
private:
    Ui::ruleDialog *ui;
    enum column{
        Anticident, Conseqient, AndOr, Weight
    };
    MainWindow_t* m_pstData;
    QVector<Rule_t> m_vstRules;
};

#endif // RULEDIALOG_H
