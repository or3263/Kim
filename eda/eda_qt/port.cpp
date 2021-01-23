#include "port.h"

Port::Port()
{

}

Port::Port(std::string name,bool inOut,bool dataType,int dataSize){
    this->name = name;
    this->inOut = inOut;
    this->dataSize =dataSize;
    this->dataType = dataType;
}
