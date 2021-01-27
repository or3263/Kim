#ifndef PORT_H
#define PORT_H
#include <iostream>
#include <QString>
enum PortType{INPUT,OUTPUT,INOUT};

class Port
{
private:
    QString name; //端口名
    PortType portType;      //输入或输出 0为in 1为out
    bool dataType;  //数据类型  0为wire 1为reg
    int dataSize;   //数据长度
    int portNum;    //端口标识
public:
    Port();
    Port(QString,PortType,bool,int,int);
    void setName(QString);
    QString getName();
    void setPortType(PortType);
    PortType getPortType();
    void setDataType(bool);
    bool getDataType();
    void setDataSize(int);
    int getDataSize();
    int getPortNum();
};

#endif // PORT_H
