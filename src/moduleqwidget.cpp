#include "moduleqwidget.h"

#include "project_head.h"

#include "module.h"

moduleQWidget::moduleQWidget(QWidget *parent) : QWidget(parent)
{


}
void moduleQWidget::setModuleName(Module moduleName)
{
    this->module = moduleName;
}
Module moduleQWidget::getModuleName()
{
    return  this->module;
}
