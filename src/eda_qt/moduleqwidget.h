#ifndef MODULEQWIDGET_H
#define MODULEQWIDGET_H

#include <QWidget>
#include"module.h"
class moduleQWidget : public QWidget
{
    Q_OBJECT
public:
    explicit moduleQWidget(QWidget *parent = nullptr);
    void setModuleName(Module);
    Module getModuleName();
private:
    Module module;
signals:

};

#endif // MODULEQWIDGET_H
