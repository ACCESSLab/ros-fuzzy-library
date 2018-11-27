/********************************************************************************
** Form generated from reading UI file 'outputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTDIALOG_H
#define UI_OUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_outputDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *outname;
    QLineEdit *outrange;
    QSpinBox *numMFs;
    QTableWidget *outMFtable;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addMF;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *outputDialog)
    {
        if (outputDialog->objectName().isEmpty())
            outputDialog->setObjectName(QStringLiteral("outputDialog"));
        outputDialog->resize(769, 371);
        layoutWidget = new QWidget(outputDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 263, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        outname = new QLineEdit(layoutWidget);
        outname->setObjectName(QStringLiteral("outname"));

        verticalLayout->addWidget(outname);

        outrange = new QLineEdit(layoutWidget);
        outrange->setObjectName(QStringLiteral("outrange"));

        verticalLayout->addWidget(outrange);

        numMFs = new QSpinBox(layoutWidget);
        numMFs->setObjectName(QStringLiteral("numMFs"));
        numMFs->setMaximum(9999999);

        verticalLayout->addWidget(numMFs);


        horizontalLayout->addLayout(verticalLayout);

        outMFtable = new QTableWidget(outputDialog);
        outMFtable->setObjectName(QStringLiteral("outMFtable"));
        outMFtable->setGeometry(QRect(10, 113, 751, 192));
        outMFtable->horizontalHeader()->setDefaultSectionSize(150);
        layoutWidget_2 = new QWidget(outputDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 310, 701, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        addMF = new QPushButton(layoutWidget_2);
        addMF->setObjectName(QStringLiteral("addMF"));

        horizontalLayout_2->addWidget(addMF);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(outputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(590, 340, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(outputDialog);

        QMetaObject::connectSlotsByName(outputDialog);
    } // setupUi

    void retranslateUi(QDialog *outputDialog)
    {
        outputDialog->setWindowTitle(QApplication::translate("outputDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("outputDialog", "Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("outputDialog", "Range", Q_NULLPTR));
        label_3->setText(QApplication::translate("outputDialog", "Number of MFs", Q_NULLPTR));
        addMF->setText(QApplication::translate("outputDialog", "Add MF", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class outputDialog: public Ui_outputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTDIALOG_H
