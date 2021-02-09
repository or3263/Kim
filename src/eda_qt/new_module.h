#ifndef NEW_MODULE_H
#define NEW_MODULE_H

#include <QDialog>

#include <qvalidator.h>

#include "project_head.h"

namespace Ui {
class new_module;
}

class new_module : public QDialog
{
    Q_OBJECT

public:
    explicit new_module(QWidget *parent = nullptr);
    ~new_module();

private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

signals:
    void send_data(QString, int ,int ,int,int);

private:
    Ui::new_module *ui;
};

#endif // NEW_MODULE_H
