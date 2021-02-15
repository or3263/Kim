#include "new_constrain.h"
#include "ui_new_constrain.h"

new_constrain::new_constrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_constrain)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setMinimumSize(447, 513);this->setMaximumSize(447, 513);//固定对话框大小
    this->setWindowTitle("新建约束文件");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);//去掉对话框的问号
    QIntValidator *int_v = new QIntValidator;
    int_v->setRange(0, 50);
    ui->lineEdit_out->setValidator(int_v);
    ui->lineEdit_input_1->setValidator(int_v);
    ui->lineEdit_input_2->setValidator(int_v);
}

new_constrain::~new_constrain()
{
    delete ui;
}

void new_constrain::on_pushButton_cancel_clicked()
{
    this->~new_constrain();
}

//void new_constrain::on_pushButton_clicked()
//{

//    this->exec();
//}


void new_constrain::on_pushButton_ok_clicked()
{
    QString name = ui->lineEdit_constrain_name->text();
    QString p1_t = ui->lineEdit_input_1->text();
    QString out_t = ui->lineEdit_out->text();
    QString p2_t = ui->lineEdit_input_2->text();
    int p1, p2, out,flag;
    flag = 0;
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

    emit c_send_data(name, p1, out, p2,flag); // 发送数据至Main Window
    this->~new_constrain();
}
