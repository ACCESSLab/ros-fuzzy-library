/********************************************************************************
** Form generated from reading UI file 'inmfsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INMFSDIALOG_H
#define UI_INMFSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inMFsDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *inMFname;
    QLineEdit *inMFtype;
    QDoubleSpinBox *inMFP1;
    QDoubleSpinBox *inMFP2;
    QDoubleSpinBox *inMFP3;
    QDoubleSpinBox *inMFP4;
    QDoubleSpinBox *inMFmax;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *inMFsDialog)
    {
        if (inMFsDialog->objectName().isEmpty())
            inMFsDialog->setObjectName(QStringLiteral("inMFsDialog"));
        inMFsDialog->resize(284, 279);
        layoutWidget = new QWidget(inMFsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(14, 7, 257, 264));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        inMFname = new QLineEdit(layoutWidget);
        inMFname->setObjectName(QStringLiteral("inMFname"));

        verticalLayout_2->addWidget(inMFname);

        inMFtype = new QLineEdit(layoutWidget);
        inMFtype->setObjectName(QStringLiteral("inMFtype"));

        verticalLayout_2->addWidget(inMFtype);

        inMFP1 = new QDoubleSpinBox(layoutWidget);
        inMFP1->setObjectName(QStringLiteral("inMFP1"));
        inMFP1->setMaximum(1e+7);

        verticalLayout_2->addWidget(inMFP1);

        inMFP2 = new QDoubleSpinBox(layoutWidget);
        inMFP2->setObjectName(QStringLiteral("inMFP2"));
        inMFP2->setMaximum(1e+7);

        verticalLayout_2->addWidget(inMFP2);

        inMFP3 = new QDoubleSpinBox(layoutWidget);
        inMFP3->setObjectName(QStringLiteral("inMFP3"));
        inMFP3->setMaximum(1e+7);

        verticalLayout_2->addWidget(inMFP3);

        inMFP4 = new QDoubleSpinBox(layoutWidget);
        inMFP4->setObjectName(QStringLiteral("inMFP4"));
        inMFP4->setMaximum(1e+7);

        verticalLayout_2->addWidget(inMFP4);

        inMFmax = new QDoubleSpinBox(layoutWidget);
        inMFmax->setObjectName(QStringLiteral("inMFmax"));
        inMFmax->setMaximum(1);
        inMFmax->setSingleStep(0.1);
        inMFmax->setValue(1);

        verticalLayout_2->addWidget(inMFmax);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(inMFsDialog);

        QMetaObject::connectSlotsByName(inMFsDialog);
    } // setupUi

    void retranslateUi(QDialog *inMFsDialog)
    {
        inMFsDialog->setWindowTitle(QApplication::translate("inMFsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("inMFsDialog", "Name", Q_NULLPTR));
        label_7->setText(QApplication::translate("inMFsDialog", "Type", Q_NULLPTR));
        label_2->setText(QApplication::translate("inMFsDialog", "P1", Q_NULLPTR));
        label_3->setText(QApplication::translate("inMFsDialog", "P2", Q_NULLPTR));
        label_4->setText(QApplication::translate("inMFsDialog", "P3", Q_NULLPTR));
        label_5->setText(QApplication::translate("inMFsDialog", "P4", Q_NULLPTR));
        label_6->setText(QApplication::translate("inMFsDialog", "Maximum", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inMFsDialog: public Ui_inMFsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INMFSDIALOG_H
