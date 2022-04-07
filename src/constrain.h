/* New Constrain功能的类*/
#ifndef CONSTRAIN_H
#define CONSTRAIN_H

#include<port.h>
#include <QApplication>

//#include "project_head.h"

class constrain
{
private:
    QString name;
    int inputPorts;//输入端口数
    int outputPorts;//输出端口数
    int inOutPorts;//双向端口数
    int latestNum;  //vector标识
    QString code;   //code
    std::vector<Port> ports;    //端口类数组
public:
    constrain();
    constrain(QString,int,int,int);    //构造函数 （名字，输入端口数量，输出端口数量，双向端口数量）
    Port getSelectedPort(int);  //返回选中的Port 参数为port对象标识默认从0开始
    void addPort();     //添加Port
    void deletePort(int);   //删除Port
    void setCode(QString);
    QString getCode();
    QString generateCodeAltera();
    QString generateCodeXilinx();
    void saveCodeFile(QString geneCodes);
};

#endif // CONSTRAIN_H
