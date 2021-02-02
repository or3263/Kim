#include "mainwindow.h"
#include"module.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Module module;
//    module = Module("TestModule",2,3,4);
//    module.saveCodeFile(module.generateCode("UserCode"));

    w.show();
    return a.exec();
}
