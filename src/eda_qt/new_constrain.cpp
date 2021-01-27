#include "new_constrain.h"
#include "ui_new_constrain.h"

new_constrain::new_constrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_constrain)
{
    ui->setupUi(this);
    this->setModal(true);
}

new_constrain::~new_constrain()
{
    delete ui;
}
void new_constrain::on_pushButton_clicked()
{
    this->exec();
}
