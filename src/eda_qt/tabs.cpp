#include "tabs.h"

tabs::tabs(QWidget *parent) : QWidget(parent)
{

}

void tabs::setModuleObject(const Module & moduleObject)
{
    this->moduleObject=moduleObject;
}
Module & tabs::getModuleObject()
{
    return this->moduleObject;
}

void tabs::setConstrainObject(const constrain & constrainObject)
{
    this->constrainObject=constrainObject;
}
constrain & tabs::getConstrainObject()
{
    return this->constrainObject;
}

void tabs::setTabType(TabType tabType)
{
    this->tabType = tabType;
}

TabType tabs::getTabType()
{
    return this->tabType;
}
