#ifndef MODULE_H
#define MODULE_H
#include <iostream>
#include <vector>
#include <QString>
#include "port.h"
#include <QApplication>
#include <QFileDialog>

class Module
{
private:
    QString name;   //模块名字
    int inputPorts; //输入端口数量
    int outputPorts; //输出端口数量
    int inOutPorts; //双向端口数量
    int latestNum;  //vector标识
    QString code;   //code
    std::vector<Port> ports;    //端口类数组
    QString annotation;     //模块注释
public:
    Module();
    Module(QString,int,int,int);    //构造函数 （名字，输入端口数量，输出端口数量，双向端口数量）
    Port getSelectedPort(int);  //返回选中的Port 参数为port对象标识默认从0开始
    void addPort();     //添加Port
    void deletePort(int);   //删除Port
    void setCode(QString);
    QString getCode();
    void setAnnotation(QString);
    QString getAnnotation();
    QString generateCode(QString);
    void saveCodeFile(QString geneCodes);
    void saveModuleFile();

    int getLatestNum();
};

#endif // MODULE_H
