/********************************************************************************
** Form generated from reading UI file 'addrulesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRULESDIALOG_H
#define UI_ADDRULESDIALOG_H

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

class Ui_addrulesDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *anticident;
    QLineEdit *consequent;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *andor;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *weight;

    void setupUi(QDialog *addrulesDialog)
    {
        if (addrulesDialog->objectName().isEmpty())
            addrulesDialog->setObjectName(QStringLiteral("addrulesDialog"));
        addrulesDialog->resize(726, 116);
        buttonBox = new QDialogButtonBox(addrulesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(540, 80, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(addrulesDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 531, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        anticident = new QLineEdit(layoutWidget);
        anticident->setObjectName(QStringLiteral("anticident"));

        horizontalLayout_2->addWidget(anticident);

        consequent = new QLineEdit(layoutWidget);
        consequent->setObjectName(QStringLiteral("consequent"));

        horizontalLayout_2->addWidget(consequent);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(addrulesDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(550, 10, 95, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        andor = new QLineEdit(layoutWidget1);
        andor->setObjectName(QStringLiteral("andor"));

        verticalLayout_2->addWidget(andor);

        widget = new QWidget(addrulesDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(655, 10, 61, 61));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        weight = new QDoubleSpinBox(widget);
        weight->setObjectName(QStringLiteral("weight"));
        weight->setMaximum(1);
        weight->setSingleStep(0.1);
        weight->setValue(1);

        verticalLayout_3->addWidget(weight);


        retranslateUi(addrulesDialog);

        QMetaObject::connectSlotsByName(addrulesDialog);
    } // setupUi

    void retranslateUi(QDialog *addrulesDialog)
    {
        addrulesDialog->setWindowTitle(QApplication::translate("addrulesDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("addrulesDialog", "Anticident", Q_NULLPTR));
        label_2->setText(QApplication::translate("addrulesDialog", "Consequent", Q_NULLPTR));
        label_3->setText(QApplication::translate("addrulesDialog", "Inference (And/Or)", Q_NULLPTR));
        label_4->setText(QApplication::translate("addrulesDialog", "Weight", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addrulesDialog: public Ui_addrulesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRULESDIALOG_H
