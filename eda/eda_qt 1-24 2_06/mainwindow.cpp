#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "new_file.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    new_file *s = new new_file(this);
    s->show();
}
