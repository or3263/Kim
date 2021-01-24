#ifndef PORT_H
#define PORT_H
#include <iostream>


class Port
{
private:
    std::string name; //端口名
    bool inOut;      //输入或输出 0为in 1为out
    bool dataType;  //数据类型  0为wire 1为reg
    int dataSize;   //数据长度
public:
    Port();
    Port(std::string,bool,bool,int);
    void setName(std::string);
    std::string getName();
    void setInOut(bool);
    bool getInOut();
    void setDataType(bool);
    bool getDataType();
    void setDataSize(int);
    int getDataSize();

};

#endif // PORT_H
