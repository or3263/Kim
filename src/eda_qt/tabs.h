#ifndef TABS_H
#define TABS_H

#include <QWidget>
#include"module.h"
#include"constrain.h"
enum TabType{MODULE,CONSTRAIN,TESTBENCH};
class tabs : public QWidget
{
private:
    TabType tabType;
public:
    explicit tabs(QWidget *parent = nullptr);
    void setModuleObject(const Module &);
    Module & getModuleObject();
    void setConstrainObject(const constrain &);
    constrain & getConstrainObject();

    int flag;//1：打开的文件；0：新建的文件或另存为的标志
    QString filePath;
    int isPopular;//1：已被添加；0：未被添加
    void setTabType(TabType);
    TabType getTabType();
signals:

private:
    Module moduleObject;
    constrain constrainObject;
};

#endif // TABS_H
