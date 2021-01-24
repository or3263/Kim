#ifndef MODULE_H
#define MODULE_H
#include <iostream>
#include <vector>
#include "port.h"
class Module
{
private:
    std::string name;
    int inputPorts;
    int ouputPorts;
    std::vector<Port> ports;
public:
    Module();
    Module(std::string,int,int);
};

#endif // MODULE_H
