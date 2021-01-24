#ifndef PORT_H
#define PORT_H
#include <iostream>

enum PortType{INPUT,OUTPUT,INOUT};

class Port
{
private:
    std::string name; //端口名
    PortType portType;      //输入或输出 0为in 1为out
    bool dataType;  //数据类型  0为wire 1为reg
    int dataSize;   //数据长度
public:
    Port();
    Port(std::string,PortType,bool,int);
    void setName(std::string);
    std::string getName();
    void setPortType(PortType);
    PortType getPortType();
    void setDataType(bool);
    bool getDataType();
    void setDataSize(int);
    int getDataSize();

};

#endif // PORT_H
