/********************************************************************************
** Form generated from reading UI file 'new_file.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_FILE_H
#define UI_NEW_FILE_H

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

class Ui_new_file
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_module_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_input_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *lineEdit_out;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_input_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_ok;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QLabel *label_2;

    void setupUi(QDialog *new_file)
    {
        if (new_file->objectName().isEmpty())
            new_file->setObjectName(QString::fromUtf8("new_file"));
        new_file->resize(430, 503);
        verticalLayoutWidget = new QWidget(new_file);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 80, 341, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_module_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_module_name->setObjectName(QString::fromUtf8("lineEdit_module_name"));

        horizontalLayout_5->addWidget(lineEdit_module_name);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_input_1 = new QLineEdit(verticalLayoutWidget);
        lineEdit_input_1->setObjectName(QString::fromUtf8("lineEdit_input_1"));

        horizontalLayout_4->addWidget(lineEdit_input_1);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        lineEdit_out = new QLineEdit(verticalLayoutWidget);
        lineEdit_out->setObjectName(QString::fromUtf8("lineEdit_out"));

        horizontalLayout_2->addWidget(lineEdit_out);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_input_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_input_2->setObjectName(QString::fromUtf8("lineEdit_input_2"));

        horizontalLayout->addWidget(lineEdit_input_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_3 = new QWidget(new_file);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 440, 341, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(horizontalLayoutWidget_3);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout_6->addWidget(pushButton_ok);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(horizontalLayoutWidget_3);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_6->addWidget(pushButton_cancel);

        label_2 = new QLabel(new_file);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 10, 171, 61));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);

        retranslateUi(new_file);

        QMetaObject::connectSlotsByName(new_file);
    } // setupUi

    void retranslateUi(QDialog *new_file)
    {
        new_file->setWindowTitle(QApplication::translate("new_file", "Dialog", nullptr));
        label_3->setText(QApplication::translate("new_file", "Module Name:", nullptr));
        label_4->setText(QApplication::translate("new_file", "Input Ports:", nullptr));
        label_8->setText(QApplication::translate("new_file", "Output Ports:", nullptr));
        label->setText(QApplication::translate("new_file", "Input Ports:", nullptr));
        pushButton_ok->setText(QApplication::translate("new_file", "Ok", nullptr));
        pushButton_cancel->setText(QApplication::translate("new_file", "Cancel", nullptr));
        label_2->setText(QApplication::translate("new_file", "New Module", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_file: public Ui_new_file {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_FILE_H
