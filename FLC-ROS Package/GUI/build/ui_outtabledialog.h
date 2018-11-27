/********************************************************************************
** Form generated from reading UI file 'outtabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTTABLEDIALOG_H
#define UI_OUTTABLEDIALOG_H

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

class Ui_outtableDialog
{
public:
    QDialogButtonBox *outtablebbox;
    QTableWidget *outtableWidget;
    QPushButton *outtableadd;

    void setupUi(QDialog *outtableDialog)
    {
        if (outtableDialog->objectName().isEmpty())
            outtableDialog->setObjectName(QStringLiteral("outtableDialog"));
        outtableDialog->resize(321, 450);
        outtablebbox = new QDialogButtonBox(outtableDialog);
        outtablebbox->setObjectName(QStringLiteral("outtablebbox"));
        outtablebbox->setGeometry(QRect(-30, 410, 341, 32));
        outtablebbox->setOrientation(Qt::Horizontal);
        outtablebbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        outtableWidget = new QTableWidget(outtableDialog);
        outtableWidget->setObjectName(QStringLiteral("outtableWidget"));
        outtableWidget->setGeometry(QRect(10, 10, 301, 371));
        outtableadd = new QPushButton(outtableDialog);
        outtableadd->setObjectName(QStringLiteral("outtableadd"));
        outtableadd->setGeometry(QRect(10, 390, 99, 27));

        retranslateUi(outtableDialog);
        QObject::connect(outtablebbox, SIGNAL(accepted()), outtableDialog, SLOT(accept()));
        QObject::connect(outtablebbox, SIGNAL(rejected()), outtableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(outtableDialog);
    } // setupUi

    void retranslateUi(QDialog *outtableDialog)
    {
        outtableDialog->setWindowTitle(QApplication::translate("outtableDialog", "Dialog", Q_NULLPTR));
        outtableadd->setText(QApplication::translate("outtableDialog", "Add Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class outtableDialog: public Ui_outtableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTTABLEDIALOG_H
