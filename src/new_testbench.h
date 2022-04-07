#ifndef NEW_TESTBENCH_H
#define NEW_TESTBENCH_H

#include <QDialog>

namespace Ui {
class new_testbench;
}

class new_testbench : public QDialog
{
    Q_OBJECT

public:
    explicit new_testbench(QWidget *parent = nullptr);
    ~new_testbench();
private slots:
    void on_pushButton_clicked();
private:
    Ui::new_testbench *ui;
};

#endif // NEW_TESTBENCH_H
