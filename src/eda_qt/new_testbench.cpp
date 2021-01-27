#include "new_testbench.h"
#include "ui_new_testbench.h"

new_testbench::new_testbench(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_testbench)
{
    ui->setupUi(this);
    this->setModal(true);
}

new_testbench::~new_testbench()
{
    delete ui;
}
void new_testbench::on_pushButton_clicked()
{
    this->exec();
}
