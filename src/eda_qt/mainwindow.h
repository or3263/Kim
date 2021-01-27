#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QPalette>
#include <QStandardItem>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void recv_new_file(QString name);

    void on_pushButton_new_file_clicked();

    void on_actionExit_triggered();

    void on_actionNew_Module_triggered();

    void on_actionNew_Constrain_triggered();

    void on_actionNew_Testbench_triggered();

private:
    Ui::MainWindow *ui;

    void dailog_new_file();

    void init_list();
};
#endif // MAINWINDOW_H
