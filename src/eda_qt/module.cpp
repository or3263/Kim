#include "module.h"
#include <QDebug>
#include <QFile>
#include <QtXml>
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

Port & Module::getSelectedPort(int portNum)
{
    for(unsigned long i = 0;i<this->ports.size();i++){
        if(this->ports.at(i).getPortNum()==portNum)
            return this->ports.at(i);
    }
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

QString Module::getName()
{
    return this->name;
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
    generateCodes = generateCodes + "\n" +code+"\n\nendmodule";
    return generateCodes;
}
QString Module::saveCodeFile(QString geneCodes)
{
    QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("生成Verilog代码文件"),QStringLiteral("C:/"),QStringLiteral("verilog(*.v)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        return("文件保存出错，请检查权限。\n");
    }
    QByteArray geneCodesArr = geneCodes.toUtf8();//将qstring转换为qbytearray
    file.write(geneCodesArr);
    file.close();
    return ("代码文件已保存至路径： "+fileName+"\n");
}
QString Module::saveModuleFile()
{
    QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("生成Module文件"),QStringLiteral("C:/"),QStringLiteral("Module(*.mod)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        return("文件保存出错，请检查权限。\n");
    }
    QDomDocument doc;

    file.close();

    QDomProcessingInstruction instruction;  //添加处理指令（声明）
    QString data;
    data = "version=\" encoding=\"" "\" standalone=\"" "\"";
    instruction = doc.createProcessingInstruction("xml", data);
    doc.appendChild(instruction);
    QDomElement elementRoot = doc.createElement("module");
    QDomElement element_M_Name = doc.createElement("m_name");
    QDomElement element_Code = doc.createElement("code");
    QDomElement element_Ports = doc.createElement("Ports");
    for(unsigned long i = 0;i<this->ports.size();i++){  //循环生成每个端口的节点
        QDomElement element_Port = doc.createElement(this->ports.at(i).getName());//端口标签设置为端口名
        element_Ports.appendChild(element_Port);//每个端口标签是ports的子
        QDomElement element_Port_PType = doc.createElement("PType");//生成端口输入输出类型节点
            if(this->ports.at(i).getPortType()==INPUT){
                element_Port_PType.appendChild(doc.createTextNode("INPUT"));
            }else if(this->ports.at(i).getPortType()==OUTPUT){
                element_Port_PType.appendChild(doc.createTextNode("OUTPUT"));
            }else{
                element_Port_PType.appendChild(doc.createTextNode("INOUT"));
            }
        element_Port.appendChild(element_Port_PType);//设置端口属性为端口的子节点
        QDomElement element_Port_DType = doc.createElement("DType");//生成端口数据类型节点
        element_Port_DType.appendChild(doc.createTextNode(this->ports.at(i).getDataType()?"reg":"wire"));
        element_Port.appendChild(element_Port_DType);
        QDomElement element_Port_DSize = doc.createElement("DSize");
        element_Port_DSize.appendChild(doc.createTextNode(QString::number(this->ports.at(i).getDataSize())));
        element_Port.appendChild(element_Port_DSize);
        QDomElement element_Port_Annotation = doc.createElement("Annotation");
        element_Port_Annotation.appendChild(doc.createTextNode(this->ports.at(i).getAnnotation()));
        element_Port.appendChild(element_Port_Annotation);
    }

    element_M_Name.appendChild(doc.createTextNode(this->name));
    element_Code.appendChild(doc.createTextNode(this->getCode()));
    elementRoot.appendChild(element_M_Name);
    elementRoot.appendChild(element_Code);
    elementRoot.appendChild(element_Ports);
    doc.appendChild(elementRoot);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "open for add error!!";
        }

    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
    return ("模块文件已保存至路径： "+fileName+"\n");
}
