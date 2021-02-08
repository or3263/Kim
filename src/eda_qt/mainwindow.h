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
private slots:

    void recv_new_module(QString, int, int, int);

    void on_actionExit_triggered();

    void on_actionNew_Module_triggered();

    void on_actionNew_Constrain_triggered();

    void on_actionNew_Testbench_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionCode_Viver_triggered();

    void on_actionCode_Generate_triggered();

    void on_pushButton_new_module_clicked();

    void on_code_Editor_clicked();

    void on_code_View_clicked();

    void on_code_Save_clicked();

    void on_module_Save_clicked();


    void on_actionLog_triggered();

    void on_actionClear_Log_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    void dailog_new_module();

    void init_list();

    void init_tab_widget(QString, int, int, int);

    QPoint calculate_pos(int source_x, int source_height, double paragraph); // 计算相对位置

    QPoint source_mouse_point;
    QPoint source_widget_point;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
