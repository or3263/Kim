#include "port.h"

Port::Port()
{

}

Port::Port(std::string name,bool inOut,bool dataType,int dataSize)
{
    this->name = name;
    this->inOut = inOut;
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

void Port::setInOut(bool inOut)
{
    this->inOut = inOut;
}
bool Port::getInOut()
{
    return this->inOut;
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
