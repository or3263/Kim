#include "module.h"

Module::Module()
{

}

Module::Module(QString name,int inputPorts,int outputPorts,int inOutPorts)
{
    this->name = name;
    this->latestNum = 0;
    for(int i = 0;i<inputPorts;i++,this->latestNum++)
    {
        this->ports.push_back(Port("p"+QString::number(this->latestNum),INPUT,0,1,this->latestNum));
    }
    for(int i = 0;i<outputPorts;i++,this->latestNum++)
    {
        this->ports.push_back(Port("p"+QString::number(this->latestNum),OUTPUT,0,1,this->latestNum));
    }
    for(int i = 0;i<inOutPorts;i++,this->latestNum++)
    {
        this->ports.push_back(Port("p"+QString::number(this->latestNum),INOUT,0,1,this->latestNum));
    }
}

Port Module::getSelectedPort(int portNum)
{
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(this->ports.at(i).getPortNum()==portNum)
            return this->ports.at(i);
    }
    return Port();
}

void Module::addPort()
{
    this->ports.push_back(Port("p"+QString::number(this->latestNum),INPUT,0,1,this->latestNum));
}
void Module::deletePort(int portNum)
{

    if(this->ports[portNum].getPortType()==INPUT){
       this->inputPorts--;
    }else if(this->ports[portNum].getPortType()==OUTPUT) {
       this->ouputPorts--;
    }else{
        this->inOutPorts--;
    }
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(this->ports.at(i).getPortNum()==portNum)
            this->ports.erase(this->ports.begin()+i);
    }
}

void Module::setCode(QString code)
{
    this->code = code;
}

QString Module::getCode()
{
    return this->code;
}

QString Module::generateCode()
{

}
