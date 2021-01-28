//1.24-23_12 新增了new_constrain.ui
//修改了mainwindow的菜单栏
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "new_testbench.h"
#include "new_constrain.h"
#include "new_file.h"
#include "moduleqwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->tabWidget->setTabsClosable(true);
    // 设置背景颜色
    this->init_tab_widget();
    // 初始化左边list表
    this->init_list();
    qDebug() << ui->tab->geometry().width();
    ui->tabWidget->insertTab(3, new QWidget, "s");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    this->dailog_new_file();
}

void MainWindow::recv_new_file(QString name)
{
    ui->textEdit->setText(name);
}

void MainWindow::on_pushButton_new_file_clicked()
{
    this->dailog_new_file();
}

void MainWindow::dailog_new_file()
{
    new_file *s = new new_file(this);
    connect(s, SIGNAL(send_data(QString)), this, SLOT(recv_new_file(QString)));
    s->show();
}

void MainWindow::init_list()
{
    QStandardItemModel *itemModel = new QStandardItemModel(this);

    QStringList list;
    list.append("_74HC138");
    list.append("_74HC151");
    list.append("_74HC181");
    list.append("_74HC182");
    list.append("_74HC190");
    list.append("_74HC194");
    list.append("_74HC238");
    list.append("AD0809");
    list.append("add");

    for (int i = 0; i < list.size(); i++)
    {
        QString s = static_cast<QString>(list.at(i));
        QStandardItem *item = new QStandardItem(s);
        itemModel->appendRow(item);
    }
    ui->listView_left->setModel(itemModel);
}

void MainWindow::init_tab_widget()
{
    QPalette pal(ui->tab_widget->palette());
    pal.setColor(QPalette::Background, Qt::black);
    ui->tab_widget->setAutoFillBackground(true);
    ui->tab_widget->setPalette(pal);
    ui->tab_widget->resize(ui->tab->width() + 200, ui->tab->height() + 200);
    ui->tab_widget->move(ui->tab->width() / 2, ui->tab->height() / 2 - 100);
}
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_Module_triggered()//菜单栏new module弹出的对话框
{
    this->dailog_new_file();
}

void MainWindow::on_actionNew_Constrain_triggered()
{
    new_constrain *s = new new_constrain(this);
    s->show();
}
void MainWindow::on_actionNew_Testbench_triggered()
{
    new_testbench *s = new new_testbench(this);
    s->show();
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    //TODO销毁Module类和tab组件
}
