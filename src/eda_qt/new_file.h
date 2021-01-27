#ifndef NEW_FILE_H
#define NEW_FILE_H

#include <QDialog>

#include <qvalidator.h>

namespace Ui {
class new_file;
}

class new_file : public QDialog
{
    Q_OBJECT

public:
    explicit new_file(QWidget *parent = nullptr);
    ~new_file();

private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

signals:
    void send_data(QString name);

private:
    Ui::new_file *ui;
};

#endif // NEW_FILE_H
