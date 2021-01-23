#ifndef PORT_H
#define PORT_H
#include <iostream>

class Port
{
private:
    std::string name; //端口名
    bool inOut;      //输入或输出
    bool dataType;  //数据类型
    int dataSize;   //数据长度
public:
    Port();
    Port(std::string,bool,bool,int);
};

#endif // PORT_H
