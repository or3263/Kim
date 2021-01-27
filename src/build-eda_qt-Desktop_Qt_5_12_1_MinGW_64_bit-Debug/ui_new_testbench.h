/********************************************************************************
** Form generated from reading UI file 'new_testbench.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_TESTBENCH_H
#define UI_NEW_TESTBENCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_testbench
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_module_name_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_input_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit_out_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *lineEdit_input_4;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_ok_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_cancel_2;

    void setupUi(QDialog *new_testbench)
    {
        if (new_testbench->objectName().isEmpty())
            new_testbench->setObjectName(QString::fromUtf8("new_testbench"));
        new_testbench->resize(405, 486);
        verticalLayoutWidget = new QWidget(new_testbench);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 70, 341, 371));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_module_name_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_module_name_2->setObjectName(QString::fromUtf8("lineEdit_module_name_2"));

        horizontalLayout_7->addWidget(lineEdit_module_name_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_input_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_input_3->setObjectName(QString::fromUtf8("lineEdit_input_3"));

        horizontalLayout_8->addWidget(lineEdit_input_3);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        lineEdit_out_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_out_2->setObjectName(QString::fromUtf8("lineEdit_out_2"));

        horizontalLayout_3->addWidget(lineEdit_out_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        lineEdit_input_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_input_4->setObjectName(QString::fromUtf8("lineEdit_input_4"));

        horizontalLayout_9->addWidget(lineEdit_input_4);


        verticalLayout_2->addLayout(horizontalLayout_9);

        label_7 = new QLabel(new_testbench);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 0, 171, 61));
        QFont font;
        font.setPointSize(18);
        label_7->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(new_testbench);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 430, 341, 41));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        pushButton_ok_2 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_ok_2->setObjectName(QString::fromUtf8("pushButton_ok_2"));

        horizontalLayout_10->addWidget(pushButton_ok_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        pushButton_cancel_2 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_cancel_2->setObjectName(QString::fromUtf8("pushButton_cancel_2"));

        horizontalLayout_10->addWidget(pushButton_cancel_2);


        retranslateUi(new_testbench);

        QMetaObject::connectSlotsByName(new_testbench);
    } // setupUi

    void retranslateUi(QDialog *new_testbench)
    {
        new_testbench->setWindowTitle(QApplication::translate("new_testbench", "Dialog", nullptr));
        label_5->setText(QApplication::translate("new_testbench", "Module Name:", nullptr));
        label_6->setText(QApplication::translate("new_testbench", "Input Ports:", nullptr));
        label_9->setText(QApplication::translate("new_testbench", "Output Ports:", nullptr));
        label_2->setText(QApplication::translate("new_testbench", "Input Ports:", nullptr));
        label_7->setText(QApplication::translate("new_testbench", "New Testbench", nullptr));
        pushButton_ok_2->setText(QApplication::translate("new_testbench", "Ok", nullptr));
        pushButton_cancel_2->setText(QApplication::translate("new_testbench", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_testbench: public Ui_new_testbench {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_TESTBENCH_H
