<<<<<<< HEAD
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
=======
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
>>>>>>> bd1e03bf8f08e9d7e5b165ba9b21a76e52608e50
