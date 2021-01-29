#include "module.h"
#include <QDebug>
#include <QFile>
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
       this->outputPorts--;
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
void Module::setAnnotation(QString annotation)
{
    this->annotation = annotation;
}

QString Module::getAnnotation()
{
    return this->annotation;
}

QString Module::generateCode(QString code)
{
    QString generateCodes;
    generateCodes = "Module "+this->name+"(\n";
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(i ==this->ports.size()-1){
            generateCodes =generateCodes + "\t" + this->ports.at(i).getName();
        }else{
            generateCodes =generateCodes + "\t" + this->ports.at(i).getName()+",\n";
        }
    }
    generateCodes = generateCodes+");\n\n";
    for(unsigned long i = 0;i<this->ports.size();i++){
            if(this->ports.at(i).getPortType()==INPUT){
                generateCodes =generateCodes + "\tinput ";

            }else if (this->ports.at(i).getPortType()==OUTPUT) {
                generateCodes =generateCodes + "\toutput ";
            }else{
                generateCodes =generateCodes + "\tinout ";
            }
            if(this->ports.at(i).getDataSize()==1){//判断port的DataSize是不是为1.
                generateCodes =generateCodes + this->ports.at(i).getName()+";\n";
            }else{
                generateCodes =generateCodes + " [" + QString::number(this->ports.at(i).getDataSize()-1) + ":0] " + this->ports.at(i).getName()+";\n";
            }
    }
    generateCodes = generateCodes+"\n";
    for(unsigned long i = 0;i<this->ports.size();i++){
            if(this->ports.at(i).getDataType()==0){
                generateCodes =generateCodes + "\twire ";

            }else{
                generateCodes =generateCodes + "\treg ";
            }
            if(this->ports.at(i).getDataSize()==1){//判断port的DataSize是不是为1.
                generateCodes =generateCodes + this->ports.at(i).getName()+";\n";
            }else{
                generateCodes =generateCodes + " [" + QString::number(this->ports.at(i).getDataSize()-1) + ":0] " + this->ports.at(i).getName()+";\n";
            }
    }
    generateCodes = generateCodes + "\n" + code+"\n\nendmodule";
    return generateCodes;
}
void Module::saveCodeFile(QString geneCodes)
{
    QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("生成Verilog代码文件"),QStringLiteral("C:/"),QStringLiteral("verilog(*.v)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){}
    QByteArray geneCodesArr = geneCodes.toUtf8();//将qstring转换为qbytearray
    file.write(geneCodesArr);
    file.close();
}
