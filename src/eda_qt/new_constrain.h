#ifndef NEW_CONSTRAIN_H
#define NEW_CONSTRAIN_H

#include <QDialog>

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
    void on_pushButton_clicked();
private:
    Ui::new_constrain *ui;
};

#endif // NEW_CONSTRAIN_H
