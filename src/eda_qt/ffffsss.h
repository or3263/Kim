#ifndef FFFFSSS_H
#define FFFFSSS_H

#include <QWidget>
#include"module.h"
class ffffsss : public QWidget
{
public:
    explicit ffffsss(QWidget *parent = nullptr);
    void setModuleObject(Module);
    Module getModuleObject();
signals:

private:
    Module moduleObject;
};

#endif // FFFFSSS_H
