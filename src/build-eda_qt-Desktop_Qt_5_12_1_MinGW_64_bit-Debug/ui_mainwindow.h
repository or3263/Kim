/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionNew_Module;
    QAction *actionNew_Constrain;
    QAction *actionNew_Testbench;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_top;
    QPushButton *pushButton_new_file;
    QPushButton *pushButton_17;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_body;
    QToolBox *toolBox_left;
    QWidget *page;
    QWidget *toolbox_system;
    QListView *listView_left;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_widget;
    QToolBox *toolBox_right;
    QWidget *toolbox_search;
    QWidget *toolbox_property;
    QHBoxLayout *horizontalLayout_bottom;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuEdit;
    QMenu *menuFile;
    QMenu *menuNew;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1056, 672);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Module = new QAction(MainWindow);
        actionNew_Module->setObjectName(QString::fromUtf8("actionNew_Module"));
        actionNew_Constrain = new QAction(MainWindow);
        actionNew_Constrain->setObjectName(QString::fromUtf8("actionNew_Constrain"));
        actionNew_Testbench = new QAction(MainWindow);
        actionNew_Testbench->setObjectName(QString::fromUtf8("actionNew_Testbench"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_top = new QHBoxLayout();
        horizontalLayout_top->setObjectName(QString::fromUtf8("horizontalLayout_top"));
        horizontalLayout_top->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_new_file = new QPushButton(centralwidget);
        pushButton_new_file->setObjectName(QString::fromUtf8("pushButton_new_file"));

        horizontalLayout_top->addWidget(pushButton_new_file);

        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        horizontalLayout_top->addWidget(pushButton_17);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_top->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_top->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_top->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_top->addWidget(pushButton);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_top->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_top->addWidget(pushButton_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_top->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_top);

        horizontalLayout_body = new QHBoxLayout();
        horizontalLayout_body->setObjectName(QString::fromUtf8("horizontalLayout_body"));
        toolBox_left = new QToolBox(centralwidget);
        toolBox_left->setObjectName(QString::fromUtf8("toolBox_left"));
        toolBox_left->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBox_left->sizePolicy().hasHeightForWidth());
        toolBox_left->setSizePolicy(sizePolicy1);
        toolBox_left->setMinimumSize(QSize(200, 0));
        toolBox_left->setSizeIncrement(QSize(0, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 200, 330));
        toolBox_left->addItem(page, QString::fromUtf8("Page 1"));
        toolbox_system = new QWidget();
        toolbox_system->setObjectName(QString::fromUtf8("toolbox_system"));
        toolbox_system->setGeometry(QRect(0, 0, 200, 330));
        listView_left = new QListView(toolbox_system);
        listView_left->setObjectName(QString::fromUtf8("listView_left"));
        listView_left->setGeometry(QRect(0, 0, 200, 16777215));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listView_left->sizePolicy().hasHeightForWidth());
        listView_left->setSizePolicy(sizePolicy2);
        listView_left->setMinimumSize(QSize(200, 0));
        listView_left->setEditTriggers(QAbstractItemView::NoEditTriggers);
        toolBox_left->addItem(toolbox_system, QString::fromUtf8("System"));

        horizontalLayout_body->addWidget(toolBox_left);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab_widget = new QWidget(tab);
        tab_widget->setObjectName(QString::fromUtf8("tab_widget"));
        tab_widget->setGeometry(QRect(50, 50, 561, 251));
        tab_widget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->addTab(tab, QString());

        horizontalLayout_body->addWidget(tabWidget);

        toolBox_right = new QToolBox(centralwidget);
        toolBox_right->setObjectName(QString::fromUtf8("toolBox_right"));
        sizePolicy1.setHeightForWidth(toolBox_right->sizePolicy().hasHeightForWidth());
        toolBox_right->setSizePolicy(sizePolicy1);
        toolBox_right->setMinimumSize(QSize(200, 0));
        toolbox_search = new QWidget();
        toolbox_search->setObjectName(QString::fromUtf8("toolbox_search"));
        toolbox_search->setGeometry(QRect(0, 0, 200, 330));
        toolBox_right->addItem(toolbox_search, QString::fromUtf8("Search"));
        toolbox_property = new QWidget();
        toolbox_property->setObjectName(QString::fromUtf8("toolbox_property"));
        toolbox_property->setGeometry(QRect(0, 0, 200, 330));
        toolBox_right->addItem(toolbox_property, QString::fromUtf8("Property"));

        horizontalLayout_body->addWidget(toolBox_right);


        verticalLayout->addLayout(horizontalLayout_body);

        horizontalLayout_bottom = new QHBoxLayout();
        horizontalLayout_bottom->setObjectName(QString::fromUtf8("horizontalLayout_bottom"));
        horizontalLayout_bottom->setSizeConstraint(QLayout::SetDefaultConstraint);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_bottom->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_bottom);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1056, 23));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew->addAction(actionNew_Module);
        menuNew->addAction(actionNew_Constrain);
        menuNew->addAction(actionNew_Testbench);

        retranslateUi(MainWindow);

        toolBox_left->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        toolBox_right->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionNew_Module->setText(QApplication::translate("MainWindow", "New Module", nullptr));
        actionNew_Constrain->setText(QApplication::translate("MainWindow", "New Constrain", nullptr));
        actionNew_Testbench->setText(QApplication::translate("MainWindow", "New Testbench", nullptr));
        pushButton_new_file->setText(QApplication::translate("MainWindow", "New File", nullptr));
        pushButton_17->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        toolBox_left->setItemText(toolBox_left->indexOf(page), QApplication::translate("MainWindow", "Page 1", nullptr));
        toolBox_left->setItemText(toolBox_left->indexOf(toolbox_system), QApplication::translate("MainWindow", "System", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        toolBox_right->setItemText(toolBox_right->indexOf(toolbox_search), QApplication::translate("MainWindow", "Search", nullptr));
        toolBox_right->setItemText(toolBox_right->indexOf(toolbox_property), QApplication::translate("MainWindow", "Property", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
