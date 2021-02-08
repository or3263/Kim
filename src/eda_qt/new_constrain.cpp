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
}

new_constrain::~new_constrain()
{
    delete ui;
}
void new_constrain::on_pushButton_clicked()
{
    this->exec();
}
