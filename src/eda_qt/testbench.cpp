#include "testbench.h"

testbench::testbench()
{

}
testbench::testbench(QString name,int inputPorts,int outputPorts,int inOutPorts)
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

Port testbench::getSelectedPort(int portNum)
{
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(this->ports.at(i).getPortNum()==portNum)
            return this->ports.at(i);
    }
    return Port();
}

void testbench::addPort()
{
    this->ports.push_back(Port("p"+QString::number(this->latestNum),INPUT,0,1,this->latestNum));
}
void testbench::deletePort(int portNum)
{

    if(this->ports[portNum].getPortType()==INPUT){
       this->inputPorts--;
    }else if(this->ports[portNum].getPortType()==OUTPUT) {
       this->outputPorts--;
    }else{
        this->inOutPorts--;
    }
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(this->ports.at(i).getPortNum()==portNum)
            this->ports.erase(this->ports.begin()+i);
    }
}

void testbench::setCode(QString code)
{
    this->code = code;
}

QString testbench::getCode()
{
    return this->code;
}

QString testbench::generateCode(QString code)
{
    QString generateCodes;
    generateCodes = "Module "+this->name+"();\n";

    for(unsigned long i = 0;i<this->ports.size();i++){
            if(this->ports.at(i).getDataType()==0){
                generateCodes =generateCodes + "wire ";

            }else{
                generateCodes =generateCodes + "reg ";
            }
            generateCodes =generateCodes + this->ports.at(i).getName()+";\n";
    }

    generateCodes = generateCodes + code;
    generateCodes = generateCodes + "initial begin\n" + "$dumpfile (\"保存路径.vcd\");\n$dumpvars;\nend\n";
    generateCodes = generateCodes + "testbench中例化的module以及相关的连线操作";
    generateCodes = generateCodes + "endmodule";
    return generateCodes;
}
