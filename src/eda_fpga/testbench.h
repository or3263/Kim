#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <vector>
#include <QString>
#include "port.h"
#include <QApplication>
#include <QFileDialog>

class testbench
{
private:
    QString name;   //模块名字
    int inputPorts; //输入端口数量
    int outputPorts; //输出端口数量
    int inOutPorts; //双向端口数量
    int latestNum;  //vector标识
    QString code;   //code
    std::vector<Port> ports;    //端口类数组
public:
    testbench();
    testbench(QString,int,int,int);    //构造函数 （名字，输入端口数量，输出端口数量，双向端口数量）
    Port getSelectedPort(int);  //返回选中的Port 参数为port对象标识默认从0开始
    void addPort();     //添加Port
    void deletePort(int);   //删除Port
    void setCode(QString);
    QString getCode();
    QString generateCode(QString);
    void saveCodeFile(QString geneCodes);
};

#endif // TESTBENCH_H
