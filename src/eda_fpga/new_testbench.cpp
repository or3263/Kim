#include "new_testbench.h"
#include "ui_new_testbench.h"

new_testbench::new_testbench(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_testbench)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setMinimumSize(447, 513);this->setMaximumSize(447, 513);//固定对话框大小
    this->setWindowTitle("新建测试文件");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);//去掉对话框的问号
}

new_testbench::~new_testbench()
{
    delete ui;
}
void new_testbench::on_pushButton_clicked()
{
    this->exec();
}
