/********************************************************************************
** Form generated from reading UI file 'outmfsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTMFSDIALOG_H
#define UI_OUTMFSDIALOG_H

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

class Ui_outMFsDialog
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
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *outMFname;
    QLineEdit *outMFtype;
    QDoubleSpinBox *outMFP1;
    QDoubleSpinBox *outMFP2;
    QDoubleSpinBox *outMFP3;
    QDoubleSpinBox *outMFP4;
    QDoubleSpinBox *outMFmax;
    QLineEdit *outTSKC;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *outMFsDialog)
    {
        if (outMFsDialog->objectName().isEmpty())
            outMFsDialog->setObjectName(QStringLiteral("outMFsDialog"));
        outMFsDialog->resize(455, 306);
        layoutWidget = new QWidget(outMFsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(7, 5, 441, 297));
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

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        outMFname = new QLineEdit(layoutWidget);
        outMFname->setObjectName(QStringLiteral("outMFname"));

        verticalLayout_2->addWidget(outMFname);

        outMFtype = new QLineEdit(layoutWidget);
        outMFtype->setObjectName(QStringLiteral("outMFtype"));

        verticalLayout_2->addWidget(outMFtype);

        outMFP1 = new QDoubleSpinBox(layoutWidget);
        outMFP1->setObjectName(QStringLiteral("outMFP1"));
        outMFP1->setMaximum(1e+7);

        verticalLayout_2->addWidget(outMFP1);

        outMFP2 = new QDoubleSpinBox(layoutWidget);
        outMFP2->setObjectName(QStringLiteral("outMFP2"));
        outMFP2->setMaximum(1e+7);

        verticalLayout_2->addWidget(outMFP2);

        outMFP3 = new QDoubleSpinBox(layoutWidget);
        outMFP3->setObjectName(QStringLiteral("outMFP3"));
        outMFP3->setMaximum(1e+7);

        verticalLayout_2->addWidget(outMFP3);

        outMFP4 = new QDoubleSpinBox(layoutWidget);
        outMFP4->setObjectName(QStringLiteral("outMFP4"));
        outMFP4->setMaximum(1e+7);

        verticalLayout_2->addWidget(outMFP4);

        outMFmax = new QDoubleSpinBox(layoutWidget);
        outMFmax->setObjectName(QStringLiteral("outMFmax"));
        outMFmax->setMaximum(1);
        outMFmax->setSingleStep(0.1);
        outMFmax->setValue(1);

        verticalLayout_2->addWidget(outMFmax);

        outTSKC = new QLineEdit(layoutWidget);
        outTSKC->setObjectName(QStringLiteral("outTSKC"));

        verticalLayout_2->addWidget(outTSKC);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(outMFsDialog);

        QMetaObject::connectSlotsByName(outMFsDialog);
    } // setupUi

    void retranslateUi(QDialog *outMFsDialog)
    {
        outMFsDialog->setWindowTitle(QApplication::translate("outMFsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("outMFsDialog", "Name", Q_NULLPTR));
        label_7->setText(QApplication::translate("outMFsDialog", "Type", Q_NULLPTR));
        label_2->setText(QApplication::translate("outMFsDialog", "P1", Q_NULLPTR));
        label_3->setText(QApplication::translate("outMFsDialog", "P2", Q_NULLPTR));
        label_4->setText(QApplication::translate("outMFsDialog", "P3", Q_NULLPTR));
        label_5->setText(QApplication::translate("outMFsDialog", "P4", Q_NULLPTR));
        label_6->setText(QApplication::translate("outMFsDialog", "Maximum", Q_NULLPTR));
        label_8->setText(QApplication::translate("outMFsDialog", "TSK Coefficients", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class outMFsDialog: public Ui_outMFsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTMFSDIALOG_H
