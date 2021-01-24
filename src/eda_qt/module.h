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
    int inOutPorts;
    std::string code;
    std::vector<Port> ports;
public:
    Module();
    Module(std::string,int,int,int);
    void setCode(std::string);
    std::string getCode();
    std::string generateCode();
};

#endif // MODULE_H
