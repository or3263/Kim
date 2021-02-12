#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "project_head.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getSysTime();
    QString getSysDate();

    void change_tab_index(int index);
    int get_tab_index();


    enum property_type {port, module};
private slots:

    void recv_new_module(QString, int, int, int, int);

    void recv_new_constrain(QString, int, int, int, int);

    void on_actionExit_triggered();

    void on_actionNew_Module_triggered();

    void on_actionNew_Constrain_triggered();

    void on_actionNew_Testbench_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionCode_View_triggered();

    void on_actionCode_Generate_triggered();

    void on_pushButton_new_module_clicked();

    void on_code_Editor_clicked();

    void on_code_View_clicked();

//    void on_code_Save_clicked();

//    void on_module_Save_clicked();

    void on_port_clicked(); // port点击事件，显示右边属性栏

    void on_module_clicked();

    void on_combobox_current_index_changed(int index); // combobox 更改选项时触发

    void on_actionLog_triggered();

    void on_actionClear_Log_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();
    
    void on_actionProject_triggered();

    void on_tabWidget_tabBarClicked(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_load();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionAdd_to_popular_triggered();

private:
    Ui::MainWindow *ui;

    void dialog_new_module();

    void dialog_new_constrain();

    void init_list();

    void init_tab_widget(QString, int, int, int, int);

    void init_tab_constrain(QString, int, int, int, int);

    QPoint calculate_pos(int source_x, int source_height, double paragraph); // 计算相对位置

    void set_property_interface(int type, int port_number); // 设置属性栏界面

    QPoint source_mouse_point;
    QPoint source_widget_point;

    int property_type_number;

    int temp_port_number;

    int click_send_type;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
