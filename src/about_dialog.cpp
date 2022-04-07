#include "about_dialog.h"
#include "ui_about_dialog.h"

about_Dialog::about_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("关于");
    this->setModal(true);
    this->setMinimumSize(435, 324);this->setMaximumSize(435, 324);//固定对话框大小
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);//去掉对话框的问号
    ui->label->setOpenExternalLinks(true);//超链接
}

about_Dialog::~about_Dialog()
{
    delete ui;
}
