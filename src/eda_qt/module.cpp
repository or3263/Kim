#include "module.h"
#include <iostream>

Module::Module()
{

}

Module::Module(std::string name,int inputPorts,int outputPorts)
{
    this->name = name;
    int portsNum = 0;
    for(int i = 0;i<inputPorts;i++,portsNum++)
    {
        this->ports.push_back(Port("p"+std::to_string(portsNum),0,0,1));
    }
    for(int i = 0;i<outputPorts;i++,portsNum++)
    {
        this->ports.push_back(Port("p"+std::to_string(portsNum),1,0,1));
    }
}
