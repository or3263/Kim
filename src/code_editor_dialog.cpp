#include "code_editor_dialog.h"
#include "ui_code_editor_dialog.h"
#include "mainwindow.h"
code_editor_dialog::code_editor_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::code_editor_dialog)
{
    ui->setupUi(this);

    this->setModal(true);

    editext->setLexer(textLexer);

    editext->setMarginType(0, QsciScintilla::NumberMargin);
    editext->setMarginLineNumbers(0, true);
    editext->setMarginWidth(0, 30);

    ui->verticalLayout->addWidget((QWidget *) editext);
}

void code_editor_dialog::set_type(int window_type)
{
    this->window_type = window_type;
    if (window_type == code_editor_dialog::editor)
    {
        this->setWindowTitle("Code Editor");
    }
    else if (window_type == code_editor_dialog::view)
    {
        this->setWindowTitle("Code View");
        editext->setReadOnly(true);

        this->temp_code = editext->text();
        editext->setText(this->temp_tab->getModuleObject().generateCode(this->temp_code)); // 显示完整代码
    }
}

code_editor_dialog::~code_editor_dialog()//关闭时保存代码
{
    this->save_tab();
//    qDebug() << "save";
    if (this->window_type == code_editor_dialog::view)
    {
        editext->setText(this->temp_code);
        this->temp_tab->getModuleObject().setCode(this->temp_code);
    }
    delete ui;
}

void code_editor_dialog::get_tab(tabs *tab)
{
    this->temp_tab = tab;
}

void code_editor_dialog::save_tab()
{
    QString code = editext->text();
//    qDebug() << "save:" << code;
    this->temp_tab->getModuleObject().setCode(code);
}

void code_editor_dialog::init_text_edit()//打开时获取代码
{
    Module m = this->temp_tab->getModuleObject();
    QString code = m.getCode();
//    qDebug() << "get:" << code;
    this->editext->setText(code);
}

void code_editor_dialog::closeEvent(QCloseEvent *event)
{
    this->~code_editor_dialog();
}
