#ifndef NEW_CONSTRAIN_H
#define NEW_CONSTRAIN_H

#include <QDialog>
#include <qvalidator.h>
#include "project_head.h"

namespace Ui {
class new_constrain;
}

class new_constrain : public QDialog
{
    Q_OBJECT

public:
    explicit new_constrain(QWidget *parent = nullptr);
    ~new_constrain();
private slots:
    //void on_pushButton_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

signals:
    void c_send_data(QString, int, int, int, int);
private:
    Ui::new_constrain *ui;
};

#endif // NEW_CONSTRAIN_H
