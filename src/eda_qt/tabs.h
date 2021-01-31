#ifndef TABS_H
#define TABS_H

#include <QWidget>
#include"module.h"
class tabs : public QWidget
{
public:
    explicit tabs(QWidget *parent = nullptr);
    void setModuleObject(const Module &);
    const Module & getModuleObject();
signals:

private:
    Module moduleObject;
};

#endif // TABS_H
