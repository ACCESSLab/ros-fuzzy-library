/********************************************************************************
** Form generated from reading UI file 'intabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTABLEDIALOG_H
#define UI_INTABLEDIALOG_H

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

class Ui_intableDialog
{
public:
    QDialogButtonBox *intablebbox;
    QTableWidget *intableWidget;
    QPushButton *intableadd;

    void setupUi(QDialog *intableDialog)
    {
        if (intableDialog->objectName().isEmpty())
            intableDialog->setObjectName(QStringLiteral("intableDialog"));
        intableDialog->resize(322, 460);
        intablebbox = new QDialogButtonBox(intableDialog);
        intablebbox->setObjectName(QStringLiteral("intablebbox"));
        intablebbox->setGeometry(QRect(-30, 420, 341, 32));
        intablebbox->setOrientation(Qt::Horizontal);
        intablebbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        intableWidget = new QTableWidget(intableDialog);
        intableWidget->setObjectName(QStringLiteral("intableWidget"));
        intableWidget->setGeometry(QRect(10, 10, 301, 371));
        intableadd = new QPushButton(intableDialog);
        intableadd->setObjectName(QStringLiteral("intableadd"));
        intableadd->setGeometry(QRect(10, 390, 99, 27));

        retranslateUi(intableDialog);
        QObject::connect(intablebbox, SIGNAL(accepted()), intableDialog, SLOT(accept()));
        QObject::connect(intablebbox, SIGNAL(rejected()), intableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(intableDialog);
    } // setupUi

    void retranslateUi(QDialog *intableDialog)
    {
        intableDialog->setWindowTitle(QApplication::translate("intableDialog", "Dialog", Q_NULLPTR));
        intableadd->setText(QApplication::translate("intableDialog", "Add Input", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class intableDialog: public Ui_intableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTABLEDIALOG_H
