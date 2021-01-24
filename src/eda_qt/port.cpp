#include "port.h"

Port::Port()
{

}

Port::Port(std::string name,PortType portType,bool dataType,int dataSize)
{
    this->name = name;
    this->portType = portType;
    this->dataSize =dataSize;
    this->dataType = dataType;
}

void Port::setName(std::string name)
{
   this->name = name;
}

std::string Port::getName()
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
