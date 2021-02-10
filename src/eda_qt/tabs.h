#ifndef TABS_H
#define TABS_H

#include <QWidget>
#include"module.h"
class tabs : public QWidget
{
public:
    explicit tabs(QWidget *parent = nullptr);
    void setModuleObject(const Module &);
    Module & getModuleObject();
    int flag;//1：打开的文件；0：新建的文件或另存为的标志
    QString filePath;
    int isPopular;//1：已被添加；0：未被添加
signals:

private:
    Module moduleObject;
};

#endif // TABS_H
