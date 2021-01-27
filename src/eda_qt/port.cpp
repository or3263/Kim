#include "port.h"

Port::Port()
{

}

Port::Port(QString name,PortType portType,bool dataType,int dataSize,int portNum)
{
    this->name = name;
    this->portType = portType;
    this->dataSize =dataSize;
    this->dataType = dataType;
    this->portNum = portNum;
}

void Port::setName(QString name)
{
   this->name = name;
}

QString Port::getName()
{
    return this->name;
}

void Port::setPortType(PortType portType)
{
    this->portType = portType;
}
PortType Port::getPortType()
{
    return this->portType;
}

void Port::setDataType(bool dataType)
{
    this->dataType = dataType;
}
bool Port::getDataType()
{
    return this->dataType;
}

void Port::setDataSize(int dataSize)
{
    this->dataSize = dataSize;
}
int Port::getDataSize()
{
    return this->dataSize;
}
int Port::getPortNum(){
    return this->portNum;
}
void Port::setAnnotation(QString annotation)
{
    this->annotation = annotation;
}

QString Port::getAnnotation()
{
    return this->annotation;
}
