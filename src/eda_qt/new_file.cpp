<<<<<<< HEAD
#include "new_file.h"
#include "ui_new_file.h"

new_file::new_file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_file)
{
    ui->setupUi(this);
    this->setModal(true);
}

new_file::~new_file()
{
    delete ui;
}

void new_file::on_pushButton_clicked()
{
    this->exec();
}
=======
#include "new_file.h"
#include "ui_new_file.h"

new_file::new_file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_file)
{
    ui->setupUi(this);
    this->setModal(true);
}

new_file::~new_file()
{
    delete ui;
}

void new_file::on_pushButton_clicked()
{
    this->exec();
}
>>>>>>> bd1e03bf8f08e9d7e5b165ba9b21a76e52608e50
