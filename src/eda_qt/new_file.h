<<<<<<< HEAD
#ifndef NEW_FILE_H
#define NEW_FILE_H

#include <QDialog>

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
    void on_pushButton_clicked();

private:
    Ui::new_file *ui;
};

#endif // NEW_FILE_H
=======
#ifndef NEW_FILE_H
#define NEW_FILE_H

#include <QDialog>

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
    void on_pushButton_clicked();

private:
    Ui::new_file *ui;
};

#endif // NEW_FILE_H
>>>>>>> bd1e03bf8f08e9d7e5b165ba9b21a76e52608e50
