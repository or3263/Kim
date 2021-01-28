#include "ffffsss.h"

ffffsss::ffffsss(QWidget *parent) : QWidget(parent)
{

}

void ffffsss::setModuleObject(Module moduleObject)
{
    this->moduleObject=moduleObject;
}
Module ffffsss::getModuleObject()
{
    return this->moduleObject;
}
