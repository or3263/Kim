#include "tabs.h"

tabs::tabs(QWidget *parent) : QWidget(parent)
{

}

void tabs::setModuleObject(const Module & moduleObject)
{
    this->moduleObject=moduleObject;
}
const Module & tabs::getModuleObject()
{
    return this->moduleObject;
}
