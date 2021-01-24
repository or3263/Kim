#include "module.h"
#include <iostream>

Module::Module()
{

}

Module::Module(std::string name,int inputPorts,int outputPorts,int inOutPorts)
{
    this->name = name;
    int portsNum = 0;
    for(int i = 0;i<inputPorts;i++,portsNum++)
    {
        this->ports.push_back(Port("p"+std::to_string(portsNum),INPUT,0,1));
    }
    for(int i = 0;i<outputPorts;i++,portsNum++)
    {
        this->ports.push_back(Port("p"+std::to_string(portsNum),OUTPUT,0,1));
    }
    for(int i = 0;i<inOutPorts;i++,portsNum++)
    {
        this->ports.push_back(Port("p"+std::to_string(portsNum),INOUT,0,1));
    }
}

void Module::setCode(std::string code)
{
    this->code = code;
}

std::string Module::getCode()
{
    return this->code;
}

std::string Module::generateCode()
{

}
