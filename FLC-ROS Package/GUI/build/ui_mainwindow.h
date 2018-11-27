/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_acpic;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBox_numins;
    QSpinBox *spinBox_numouts;
    QSpinBox *spinBox_numrules;
    QComboBox *comboBox_5;
    QDialogButtonBox *buttonBox;
    QLabel *label_9;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(506, 368);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_acpic = new QLabel(centralWidget);
        label_acpic->setObjectName(QStringLiteral("label_acpic"));
        label_acpic->setGeometry(QRect(320, 0, 171, 131));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 141, 86));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(263, 133, 231, 130));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_6->addWidget(comboBox);

        comboBox_2 = new QComboBox(layoutWidget1);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_6->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(layoutWidget1);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        verticalLayout_6->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(layoutWidget1);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        verticalLayout_6->addWidget(comboBox_4);


        horizontalLayout_3->addLayout(verticalLayout_6);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(169, 42, 141, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(layoutWidget2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        radioButton_4 = new QRadioButton(layoutWidget2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(layoutWidget2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 272, 481, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(11, 132, 249, 130));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spinBox_numins = new QSpinBox(layoutWidget4);
        spinBox_numins->setObjectName(QStringLiteral("spinBox_numins"));
        spinBox_numins->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numins);

        spinBox_numouts = new QSpinBox(layoutWidget4);
        spinBox_numouts->setObjectName(QStringLiteral("spinBox_numouts"));
        spinBox_numouts->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numouts);

        spinBox_numrules = new QSpinBox(layoutWidget4);
        spinBox_numrules->setObjectName(QStringLiteral("spinBox_numrules"));
        spinBox_numrules->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numrules);

        comboBox_5 = new QComboBox(layoutWidget4);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        verticalLayout_4->addWidget(comboBox_5);


        horizontalLayout->addLayout(verticalLayout_4);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(320, 310, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 310, 301, 16));
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 10, 188, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit = new QLineEdit(layoutWidget5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_4);
        QWidget::setTabOrder(radioButton_4, radioButton_3);
        QWidget::setTabOrder(radioButton_3, comboBox_2);
        QWidget::setTabOrder(comboBox_2, spinBox_numins);
        QWidget::setTabOrder(spinBox_numins, spinBox_numouts);
        QWidget::setTabOrder(spinBox_numouts, spinBox_numrules);
        QWidget::setTabOrder(spinBox_numrules, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_acpic->setText(QString());
        radioButton->setText(QApplication::translate("MainWindow", "Type-1", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Interval Type-2", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "And Method", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Or Method", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Agg. Method", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Implication Method", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Min", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Prod", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Max", Q_NULLPTR)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Max", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Prod", Q_NULLPTR)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Min", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Prod", Q_NULLPTR)
        );
        radioButton_4->setText(QApplication::translate("MainWindow", "TSK", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Mamdani", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add Inputs", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add Outputs", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add Rules", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Number of Inputs", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Number of Outputs", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Number of Rules", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Output Processing Method", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Centroid", Q_NULLPTR)
         << QApplication::translate("MainWindow", "WtdAvg", Q_NULLPTR)
         << QApplication::translate("MainWindow", "NT", Q_NULLPTR)
         << QApplication::translate("MainWindow", "UB", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWindow", "North Carolina A & T State University", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "FLS Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
