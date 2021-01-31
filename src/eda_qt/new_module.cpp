#include "new_module.h"
#include "ui_new_module.h"

new_module::new_module(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_module)
{
    ui->setupUi(this);
    this->setModal(true); // 设置模态

    // 限制为 int 格式，范围两位数
    QIntValidator *int_v = new QIntValidator;
    int_v->setRange(0, 50);
    ui->lineEdit_out->setValidator(int_v);
    ui->lineEdit_input_1->setValidator(int_v);
    ui->lineEdit_input_2->setValidator(int_v);
}

new_module::~new_module()
{
    delete ui;
}

void new_module::on_pushButton_cancel_clicked()
{
    this->~new_module();
}

void new_module::on_pushButton_ok_clicked()
{
    QString name = ui->lineEdit_module_name->text();
    QString p1_t = ui->lineEdit_input_1->text();
    QString out_t = ui->lineEdit_out->text();
    QString p2_t = ui->lineEdit_input_2->text();

    int p1, p2, out;

    if (p1_t == "")
    {
        p1 = 0;
    } else {
        p1 = p1_t.toInt();
    }
    if (p2_t == "")
    {
        p2 = 0;
    } else {
        p2 = p2_t.toInt();
    }
    if (out_t == "")
    {
        out = 0;
    } else {
        out = out_t.toInt();
    }

    emit send_data(name, p1, out, p2); // 发送数据至Main Window
    this->~new_module();
}
