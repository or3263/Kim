#ifndef CODE_EDITOR_DIALOG_H
#define CODE_EDITOR_DIALOG_H

#include <QDialog>

#include "project_head.h"

namespace Ui {
class code_editor_dialog;
}

class code_editor_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit code_editor_dialog(QWidget *parent = nullptr);
    ~code_editor_dialog();

    void get_tab(tabs *tab);
    void init_text_edit();

    void set_type(int window_type); // 设置窗口类型，is 编辑器 or 查看器

    enum Window_Type{editor, view};

private:
    Ui::code_editor_dialog *ui;

    tabs *temp_tab;
    QString temp_code;
    int window_type;
    QsciLexerVerilog *textLexer =new QsciLexerVerilog;
    QsciScintilla *editext = new QsciScintilla;

    void save_tab();


protected:
    void closeEvent(QCloseEvent *);


};

#endif // CODE_EDITOR_DIALOG_H
