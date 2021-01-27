#include "new_file.h"
#include "ui_new_file.h"

new_file::new_file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_file)
{
    ui->setupUi(this);
    this->setModal(true);

    // 限制为 int 格式，范围两位数
    QIntValidator *int_v = new QIntValidator;
    int_v->setRange(0, 50);
    ui->lineEdit_out->setValidator(int_v);
    ui->lineEdit_input_1->setValidator(int_v);
    ui->lineEdit_input_2->setValidator(int_v);
}

new_file::~new_file()
{
    delete ui;
}

void new_file::on_pushButton_cancel_clicked()
{
    this->~new_file();
}

void new_file::on_pushButton_ok_clicked()
{
    QString name = ui->lineEdit_module_name->text();
    emit send_data(name);

    this->~new_file();
}
