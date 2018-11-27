/********************************************************************************
** Form generated from reading UI file 'ruledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEDIALOG_H
#define UI_RULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ruleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ruleDialog)
    {
        if (ruleDialog->objectName().isEmpty())
            ruleDialog->setObjectName(QStringLiteral("ruleDialog"));
        ruleDialog->resize(623, 523);
        buttonBox = new QDialogButtonBox(ruleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(440, 490, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(ruleDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 601, 441));
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        pushButton = new QPushButton(ruleDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 460, 99, 27));

        retranslateUi(ruleDialog);

        QMetaObject::connectSlotsByName(ruleDialog);
    } // setupUi

    void retranslateUi(QDialog *ruleDialog)
    {
        ruleDialog->setWindowTitle(QApplication::translate("ruleDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ruleDialog", "Add Rule", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ruleDialog: public Ui_ruleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEDIALOG_H
