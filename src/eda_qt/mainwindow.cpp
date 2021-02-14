//1.24-23_12 新增了new_constrain.ui
//修改了mainwindow的菜单栏
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "project_head.h"
#include "QMessageBox"
#include "code_editor_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("");

    ui->tabWidget->setTabsClosable(true);

    ui->textEdit->setTextColor(QColor(100, 200, 100));
    ui->textEdit->setText("Time:"+getSysDate()+"\t\tOUTPUT:\n");
    QString configPath = QCoreApplication::applicationDirPath();
    QFileInfo fileInfo(configPath+"/config.ini");//第一次运行程序时在当前目录下新建config.ini
    if(!fileInfo.isFile()){
        QFile file(configPath+"/config.ini");
        if(!file.open(QIODevice::WriteOnly)){
            ;;
        }
        //qDebug()<<configPath;
        QDomDocument doc;
        QDomProcessingInstruction instruction;  //添加处理指令（声明）
        QString data;
        data = "version=\"1.0\" encoding=\"UTF-8\"";
        instruction = doc.createProcessingInstruction("xml", data);
        doc.appendChild(instruction);
        QTextStream out(&file);
        doc.save(out, 4);
        file.close();
    }


//    //测试代码编辑器
//    QWidget *a = new QWidget(ui->tab_code);
//    QsciLexerVerilog *textLexer =new QsciLexerVerilog;
//    QsciScintilla *editext = new QsciScintilla;
//    editext->setLexer(textLexer);
//    editext->setParent(a);
//    a->show();
//    editext->resize(500,500);
//    editext->show();
//    Module b =  Module("asa",3,2,3);
//    editext->setText(b.generateCode("")) ;

//    this->init_tab_widget("", 0, 0, 0);
    // 初始化左边list表
    this->init_list();

    QTimer::singleShot(2, this, SLOT(on_load()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recv_new_module(QString name, int inp1, int out, int inp2, int flag ) //接收新建module窗口发送来的Module类
{
    this->init_tab_widget(name, inp1, out, inp2, flag);
}


void MainWindow::dialog_new_module() //弹出新建module窗口
{
    new_module *s = new new_module(this);
    connect(s, SIGNAL(m_send_data(QString, int, int, int,int)), this, SLOT(recv_new_module(QString, int, int, int,int)));
    s->show();
}

void MainWindow::init_list()
{
    QStandardItemModel *itemModel = new QStandardItemModel(this);

    QStringList list;
//    list.append("_74HC138");
//    list.append("_74HC151");
//    list.append("_74HC181");
//    list.append("_74HC182");
//    list.append("_74HC190");
//    list.append("_74HC194");
//    list.append("_74HC238");
//    list.append("AD0809");
//    list.append("add");

    for (int i = 0; i < list.size(); i++)
    {
        QString s = static_cast<QString>(list.at(i));
        QStandardItem *item = new QStandardItem(s);
        itemModel->appendRow(item);
    }
    ui->listView_popular->setModel(itemModel);
}

void MainWindow::init_tab_widget(QString name, int inp1, int out, int inp2, int flag) // inp1 = input， out = output, inp2 = input and output
{
    //flag==0:新建；flag==1:打开
    // 新建标签
    tabs *tab = new tabs();
    tab->setObjectName(name + "_tab"); // 设置module table object名字
    tab->flag = 0;
    tab->filePath = "";
    tab->setTabType(MODULE);
    qDebug() << "tab1 " << tab->width() << tab->height();
    ui->tabWidget->addTab(tab, name);
    if (flag == 0){
    ui->textEdit->append(getSysTime()+"新建了\""+name+"\"模块\n");//发送log消息
    }else if(flag == 1){
    ;;
    }
    tab->resize(ui->tabWidget->width(), ui->tabWidget->height());
    qDebug() << "tab2 " << tab->width() << tab->height();

    // 切换到新加入的标签
    change_tab_index(get_tab_index() - 1);
    QLayoutItem *item;
    while ((item = ui->gridLayout_2->takeAt(0)))
    {
        ui->gridLayout_2->removeItem(item);
        delete item->widget();
    }
    while ((item = ui->gridLayout_3->takeAt(0)))
    {
        ui->gridLayout_3->removeItem(item);
        delete item->widget();
    }

    // 新建Code Editor按钮
    QPushButton *codeEditor_button = new QPushButton(tab);
    codeEditor_button->setGeometry(QRect(0, tab->height() - 85, 50, 50));
    codeEditor_button->setObjectName(name + "_codeEditor");
    codeEditor_button->setText("Code\nEidtor");
    connect(codeEditor_button, SIGNAL(clicked()), this, SLOT(on_code_Editor_clicked()));
    codeEditor_button->show();
    codeEditor_button->parent();

    // 新建Code View按钮
    QPushButton *codeView_button = new QPushButton(tab);
    codeView_button->setGeometry(QRect(0, tab->height() - 85 - 100 , 50, 50));
    codeView_button->setObjectName(name + "_codeView");
    codeView_button->setText("Code\nView");
    connect(codeView_button, SIGNAL(clicked()), this, SLOT(on_code_View_clicked()));
    codeView_button->show();
    codeView_button->parent();

//    //新建Save Code
//    QPushButton *codeSave_button = new QPushButton(tab);
//    codeSave_button->setGeometry(QRect(tab->width()-55, tab->height() - 85 - 100 , 50, 50));
//    codeSave_button->setObjectName(name + "_codeSave");
//    codeSave_button->setText("Save\nCode");
//    connect(codeSave_button, SIGNAL(clicked()), this, SLOT(on_code_Save_clicked()));
//    codeSave_button->show();
//    codeSave_button->parent();

//    //新建Save Module
//    QPushButton *moduleSave_button = new QPushButton(tab);
//    moduleSave_button->setGeometry(QRect(tab->width()-55, tab->height() - 85 , 50, 50));
//    moduleSave_button->setObjectName(name + "_codeModule");
//    moduleSave_button->setText("Save\nModule");
//    connect(moduleSave_button, SIGNAL(clicked()), this, SLOT(on_module_Save_clicked()));
//    moduleSave_button->show();
//    moduleSave_button->parent();

    // 新建module
    QWidget *tab_module = new QWidget(tab);
    tab_module->setObjectName(name + "_module");  // 设置module object名字

    // 设置table module的背景颜色
//    QPalette pal(tab_module->palette());
//    pal.setColor(QPalette::Background, Qt::black);

    tab_module->setAutoFillBackground(true);
    tab_module->setStyleSheet("background-color: rgb(0, 0, 0);");
//    tab_module->setPalette(pal);

    int module_width = tab->width() / 3 * 2;
    int module_height = tab->height() - 80;

    qDebug() << "tabWidget " << ui->tabWidget->width() << ui->tabWidget->height();

    tab_module->setGeometry(QRect((tab->width() - module_width) / 2, (tab->height() - module_height) / 2, module_width, module_height));
    tab_module->show();


    int widget_2_width = module_width - 100;
    int widget_2_height = module_height - 100;

//    qDebug() << "tab module" << tab_module->pos();
//    qDebug() << "tab width " << tab->width();
//    qDebug() << "tab height " << tab->height();
    if (tab_module->palette() == tab->palette())
    {
        qDebug() << "yes";
    }

    // 二层widget

    QWidget *widget_2 = new QWidget();

    widget_2->setGeometry(QRect(50, 50, widget_2_width, widget_2_height));
    widget_2->setObjectName(name + "_2");

    widget_2->setAutoFillBackground(true); // 填充背景
    widget_2->setStyleSheet("background-color: rgb(170, 0, 0);"); // 设置背景颜色
    QLabel *nameLable = new QLabel;//module的name标签
    nameLable->setGeometry(200,200,100,100);
    nameLable->setObjectName(name + "_nameLable");
    nameLable->setText(name);
    nameLable->setParent(widget_2);
    nameLable->show();
    widget_2->setParent(tab_module);
    widget_2->show();
    QPushButton *on_widget_2 = new QPushButton;//创建透明按钮叠加在widget_2上
    on_widget_2->setGeometry(QRect(0,0,widget_2_width,widget_2_height));
    on_widget_2->setObjectName(name + "on_widget_2_button");
    on_widget_2->setFlat(true);
    on_widget_2->setAutoFillBackground(true);
    QPalette palette = on_widget_2->palette();
    palette.setColor(QPalette::Button,QColor(255,0,0,100));
    on_widget_2->setPalette(palette);
    on_widget_2->setParent(widget_2);
    on_widget_2->show();
    connect(on_widget_2, SIGNAL(clicked()), this, SLOT(on_module_clicked()));//连接按钮的点击信号
//    QPushButton *port1 = new QPushButton(tab_module);
//    port1->setGeometry(QRect(50, 50, 50, 50));
//    port1->show();

    // 插入端口
//    Module m = Module(name, inp1, out, inp2);
//    tab->setModuleObject(m);
    tab->setModuleObject(Module(name, inp1, out, inp2));

    double paragraph; // 分段变量
    int port_number = 0;
    QPoint widget_2_pos = widget_2->pos();

    // 增加左边端口
    paragraph = 1.0 / (inp1 + 1);

    for (int cycle = 1; cycle <= inp1; cycle++) {
        QPushButton *port = new QPushButton();

        // 设置名称
        port->setObjectName(name + "_p_" + QString::number(port_number));
        port->setText(tab->getModuleObject().getSelectedPort(port_number).getName());



        // 设置大小，位置
        port->resize(50, 50);
        port->move(this->calculate_pos(widget_2_pos.x() - port->width() / 2, widget_2_height, paragraph * cycle));

        // 设置背景颜色
        widget_2->setAutoFillBackground(true);
        port->setStyleSheet("background-color: rgb(100, 100, 10);");

        // 连接click事件
        connect(port, SIGNAL(clicked()), this, SLOT(on_port_clicked()));

        // 显示
        port->setParent(tab_module);
        port->show();

//        qDebug() << port->pos();

        port_number++;
    }


    // 增加右边端口
    int right_port_num = out + inp2;
    paragraph = 1.0 / (right_port_num + 1);

    for (int cycle = 1; cycle <= right_port_num; cycle++) {
        QPushButton *port = new QPushButton();

        // 设置名称
        port->setObjectName(name + "_p_" + QString::number(port_number));
        port->setText(tab->getModuleObject().getSelectedPort(port_number).getName());

        // 设置大小，位置
        port->resize(50, 50);
        port->move(this->calculate_pos(widget_2_pos.x() + widget_2_width - port->width() / 2, widget_2_height, paragraph * cycle));

        // 设置背景颜色
        widget_2->setAutoFillBackground(true);
        if (cycle > out) // in out
        {
            port->setStyleSheet("background-color: rgb(200, 200, 200);");
        }
        else
        {
            port->setStyleSheet("background-color: rgb(75, 75, 75);");
        }

        // 连接click事件
        connect(port, SIGNAL(clicked()), this, SLOT(on_port_clicked()));

        // 显示
        port->setParent(tab_module);
        port->show();

        port_number++;
    }

//    for (int cycle = 1; cycle <= out; cycle++) {
//        QPushButton *port = new QPushButton();

//        // 设置名称
//        port->setObjectName(name + "_p_" + QString::number(port_number));
//        port->setText("P" + QString::number(port_number));

//        // 设置大小，位置
//        port->resize(50, 50);
//        port->move(this->calculate_pos(widget_2_pos, widget_2_height, paragraph * cycle));

//        // 设置背景颜色
//        widget_2->setAutoFillBackground(true);
//        port->setStyleSheet("background-color: rgb(100, 100, 10);");

//        // 显示
//        port->setParent(tab_module);
//        port->show();

//        port_number++;
//    }

}
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_Module_triggered()//菜单栏new module弹出的对话框
{
    this->dialog_new_module();
}

//void MainWindow::on_actionNew_Constrain_triggered()
//{
//    this->dialog_new_constrain();

//}

//void MainWindow::dialog_new_constrain()
//{
//    new_constrain *s = new new_constrain(this);
//    connect(s, SIGNAL(c_send_data(QString, int, int, int,int)), this, SLOT(recv_new_constrain(QString, int, int, int,int)));
//    s->show();
//}

//void MainWindow::recv_new_constrain(QString name, int inp1, int out, int inp2, int flag ) //接收新建module窗口发送来的Module类
//{
//    this->init_tab_constrain(name, inp1, out, inp2, flag);
//}

//void MainWindow::init_tab_constrain(QString name, int inp1, int out, int inp2, int flag)
//{
//    //qDebug()<<"shoudao";
//    tabs *tab = new tabs();
//    tab->setObjectName(name + "_c_tab"); // 设置module table object名字
//    tab->flag = 0;
//    tab->filePath = "";
//    tab->setTabType(CONSTRAIN);
//    ui->tabWidget->addTab(tab, name);
//    if (flag == 0){
//    ui->textEdit->append(getSysTime()+"新建了\""+name+"\"约束文件\n");//发送log消息
//    }else if(flag == 1){
//    ;;
//    }
//    tab->resize(ui->tabWidget->width(), ui->tabWidget->height());
//    change_tab_index(get_tab_index() - 1);


//    QPushButton *codeView_button = new QPushButton(tab);
//    codeView_button->setGeometry(QRect(0, tab->height() - 85 - 100 , 50, 50));
//    codeView_button->setObjectName(name + "_c_codeView");
//    codeView_button->setText("Code\nView");
//    connect(codeView_button, SIGNAL(clicked()), this, SLOT(on_code_View_clicked()));
//    codeView_button->show();
//    codeView_button->parent();

//    QWidget *tab_constrain = new QWidget(tab);
//    tab_constrain->setObjectName(name +"_constrain");

//    tab_constrain->setAutoFillBackground(true);
//    tab_constrain->setStyleSheet("background-color: rgb(0, 0, 0);");
//    int module_width = tab->width() / 3 * 2;
//    int module_height = tab->height() - 80;
//    tab_constrain->setGeometry(QRect((tab->width() - module_width) / 2, (tab->height() - module_height) / 2, module_width, module_height));
//    tab_constrain->show();
//    int widget_2_width = module_width - 100;
//    int widget_2_height = module_height - 100;

//    QWidget *widget_2 = new QWidget();
//    widget_2->setGeometry(QRect(50, 50, widget_2_width, widget_2_height));
//    widget_2->setObjectName(name + "_c_2");
//    widget_2->setAutoFillBackground(true); // 填充背景
//    widget_2->setStyleSheet("background-color: rgb(170, 0, 0);"); // 设置背景颜色
//    QLabel *nameLable = new QLabel;//module的name标签
//    nameLable->setGeometry(200,200,100,100);
//    nameLable->setObjectName(name + "_c_nameLable");
//    nameLable->setText(name);
//    nameLable->setParent(widget_2);
//    nameLable->show();
//    widget_2->setParent(tab_constrain);
//    widget_2->show();
//    QPushButton *on_widget_2 = new QPushButton;//创建透明按钮叠加在widget_2上
//    on_widget_2->setGeometry(QRect(0,0,widget_2_width,widget_2_height));
//    on_widget_2->setObjectName(name + "c_on_widget_2_button");
//    on_widget_2->setFlat(true);
//    on_widget_2->setAutoFillBackground(true);
//    QPalette palette = on_widget_2->palette();
//    palette.setColor(QPalette::Button,QColor(255,0,0,100));
//    on_widget_2->setPalette(palette);
//    on_widget_2->setParent(widget_2);
//    on_widget_2->show();
//    connect(on_widget_2, SIGNAL(clicked()), this, SLOT(on_module_clicked()));//连接按钮的点击信号

//    tab->setConstrainObject(constrain(name, inp1, out, inp2));
//    double paragraph; // 分段变量
//    int port_number = 0;
//    QPoint widget_2_pos = widget_2->pos();
//    paragraph = 1.0 / (inp1 + 1);
//    for (int cycle = 1; cycle <= inp1; cycle++) {
//        QPushButton *port = new QPushButton();
//        port->setObjectName(name + "_c_p_" + QString::number(port_number));
//        port->setText(tab->getModuleObject().getSelectedPort(port_number).getName());
//        port->resize(50, 50);
//        port->move(this->calculate_pos(widget_2_pos.x() - port->width() / 2, widget_2_height, paragraph * cycle));
//        widget_2->setAutoFillBackground(true);
//        port->setStyleSheet("background-color: rgb(100, 100, 10);");
//        connect(port, SIGNAL(clicked()), this, SLOT(on_port_clicked()));
//        port->setParent(tab_constrain);
//        port->show();
//        port_number++;
//    }
//    int right_port_num = out + inp2;
//    paragraph = 1.0 / (right_port_num + 1);
//    for (int cycle = 1; cycle <= right_port_num; cycle++) {
//        QPushButton *port = new QPushButton();
//        port->setObjectName(name + "_c_p_" + QString::number(port_number));
//        port->setText(tab->getModuleObject().getSelectedPort(port_number).getName());
//        port->resize(50, 50);
//        port->move(this->calculate_pos(widget_2_pos.x() + widget_2_width - port->width() / 2, widget_2_height, paragraph * cycle));
//        widget_2->setAutoFillBackground(true);
//        if (cycle > out) // in out
//        {
//            port->setStyleSheet("background-color: rgb(200, 200, 200);");
//        }
//        else
//        {
//            port->setStyleSheet("background-color: rgb(75, 75, 75);");
//        }

//        // 连接click事件
//        connect(port, SIGNAL(clicked()), this, SLOT(on_port_clicked()));

//        // 显示
//        port->setParent(tab_constrain);
//        port->show();

//        port_number++;
//    }
//}
void MainWindow::on_actionNew_Testbench_triggered()
{
    new_testbench *s = new new_testbench(this);
    s->show();
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    //TODO销毁Module类和tab组件
}


void MainWindow::on_actionCode_Generate_triggered()//代码生成的选项
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    ui->textEdit->append(getSysTime()+"模块\'"+m.getName()+"\'的"+m.saveCodeFile(m.generateCode(m.getCode())));
}

void MainWindow::on_actionCode_View_triggered()
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    code_editor_dialog *d = new code_editor_dialog();
    d->get_tab(tab);
    d->init_text_edit();
    d->set_type(code_editor_dialog::view);
    d->show();

}

void MainWindow::on_pushButton_new_module_clicked()
{
    this->dialog_new_module();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) //当鼠标拖动时
{
    if (event->buttons() == Qt::LeftButton)
    {
//        QPoint p = event->globalPos() - source_mouse_point;
//        qDebug() << "拖动：" << p;
//        QPoint d = this->source_widget_point + p;
//        qDebug() << d;

//        int tab_width = ui->tab->width();
//        int tab_height = ui->tab->height();
//        int w_width = ui->tab_widget->width();
//        int w_height = ui->tab_widget->height();

//        if (d.x() <= 0 || d.y() <=0)
//        {
//            return;
//        }
//        else if ((d.x() + w_width) >= tab_width || (d.y() + w_height) >= tab_height)
//        {
//            return;
//        }

//        ui->tab_widget->move(d);
/*
        qDebug() << ui->tabWidget->currentIndex(); */// 获取当前标签
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) //当鼠标按下时
{
    if (event->button() == Qt::LeftButton)
    {
//        this->source_mouse_point = event->globalPos();
//        this->source_widget_point = ui->tab_widget->pos();
//        qDebug() << this->source_widget_point;
    }
}

QPoint MainWindow::calculate_pos(int source_x, int source_height, double paragraph)
{
    double y = source_height * paragraph;
    qDebug() << y;
    QPoint point = QPoint(source_x,  y);
    return point;
}

void MainWindow::on_code_Editor_clicked()
{
    // 打开code editor窗口
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
//    qDebug() << clickedButton->parent()->objectName();
    code_editor_dialog *d = new code_editor_dialog();
    d->get_tab((tabs *)clickedButton->parent());
    d->init_text_edit();
    d->set_type(code_editor_dialog::editor);
    d->show();
}

void MainWindow::on_code_View_clicked()
{
    // 打开code view窗口
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
//    qDebug() << clickedButton->parent()->objectName();
    code_editor_dialog *d = new code_editor_dialog();
    d->get_tab((tabs *)clickedButton->parent());
    d->init_text_edit();
    d->set_type(code_editor_dialog::view);
    d->show();
}

//void MainWindow::on_code_Save_clicked()
//{
//    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
//    Module m = ((tabs *)clickedButton->parent())->getModuleObject();
//    ui->textEdit->append(getSysTime()+"模块\'"+m.getName()+"\'的"+m.saveCodeFile(m.generateCode(m.getCode())));

//}

//void MainWindow::on_module_Save_clicked()
//{
//    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
//    Module m = ((tabs *)clickedButton->parent())->getModuleObject();
//    ui->textEdit->append(getSysTime()+"模块\'"+m.getName()+"\'的"+m.saveModuleFile());
//}

QString MainWindow::getSysDate()
{
    QDateTime d = QDateTime::currentDateTime();//获取系统现在的时间
    QString SysDate = d.toString("yyyy-MM-dd"); //设置显示格式
    return SysDate;
}

QString MainWindow::getSysTime()
{
    QTime t=QTime::currentTime();
    QString SysTime=t.toString("HH:mm:ss");
    SysTime = SysTime + "\t\t";
    return  SysTime;
}

void MainWindow::on_actionLog_triggered()
{
    QString log = ui->textEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("导出日志文件"),QStringLiteral("C:/"),QStringLiteral("log(*.log)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        ui->textEdit->append(getSysTime()+"文件保存失败，请检查权限。");
    }
    QByteArray logArr = log.toUtf8();//将qstring转换为qbytearray
    file.write(logArr);
    file.close();
    ui->textEdit->append(getSysTime()+"日志文件已保存至路径： "+fileName+"\n");
}

void MainWindow::on_actionClear_Log_triggered()
{
    ui->textEdit->setText("Time:"+getSysDate()+"\t\tOUTPUT:\n");
}

void MainWindow::on_actionAbout_triggered()
{
    about_Dialog *s = new about_Dialog(this);
    s->show();
}

void MainWindow::on_actionOpen_triggered()
{

    QString tempPath = QFileDialog::getOpenFileName(this, QStringLiteral("打开"),QCoreApplication::applicationDirPath(),"yangnai files(*.mod;*.const;*vcd;*test)");
       if(!tempPath.isEmpty())
       {
            QFile file(tempPath);
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                QMessageBox::information(NULL, QString("title"), QString("open error!"));
                return;
            }
            QDomDocument document;
            QString error;
            int row = 0, column = 0;
            if(!document.setContent(&file, false, &error, &row, &column))
            {
                QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));
                return;
            }
            if(document.isNull())
            {
                QMessageBox::information(NULL, QString("title"), QString("document is null!"));
                return;
            }
            QDomElement root = document.documentElement();
            if(root.tagName()=="module"){
                QString moduleName =  root.firstChildElement().text();
                QDomNodeList moduleNodeList = root.childNodes();
                QString moduleAnnotation = moduleNodeList.at(1).toElement().text();
                QString moduleCode = moduleNodeList.at(2).toElement().text();
                QDomElement modulePortsDom = moduleNodeList.at(3).toElement();
                QDomNodeList modulePortsNodeList = modulePortsDom.childNodes();
                int input=0,output=0,inout =0;
                for(int i = 0;i<modulePortsNodeList.count();++i){
                    if(modulePortsNodeList.at(i).toElement().firstChildElement().text()=="INPUT"){
                        input++;
                    }else if(modulePortsNodeList.at(i).toElement().firstChildElement().text()=="OUTPUT"){
                        output++;
                    }else{
                        inout++;
                    }
                }
                MainWindow::init_tab_widget(moduleName,input,output,inout,1 );
                tabs* tempTab = (tabs*) ui->tabWidget->currentWidget();
                tempTab->getModuleObject().setAnnotation(moduleAnnotation);
                tempTab->getModuleObject().setCode(moduleCode);
                tempTab->flag = 1;
                tempTab->filePath = tempPath;
                for(int i = 0;i<modulePortsNodeList.count();++i){
                    QDomElement tempDomElement = modulePortsNodeList.at(i).toElement();
                    tempTab->getModuleObject().getSelectedPort(i).setName(tempDomElement.tagName());
                    QDomNodeList tempDomNodeList =  tempDomElement.childNodes();
                    tempTab->getModuleObject().getSelectedPort(i).setDataType(tempDomNodeList.at(1).toElement().text()=="wire"?0:1);
                    tempTab->getModuleObject().getSelectedPort(i).setDataSize(tempDomNodeList.at(2).toElement().text().toInt());
                    tempTab->getModuleObject().getSelectedPort(i).setAnnotation(tempDomNodeList.at(3).toElement().text());
                }
                ui->textEdit->append(getSysTime()+"打开了路径为"+tempPath +"的\""+ moduleName+"\"模块\n");//发送log消息
            }
       }
}

void MainWindow::on_port_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    // 获取button控件object名，切割字符串
    QString button_object_name = clickedButton->objectName();
    QStringList name_list = button_object_name.split("_");

    int port_number = name_list.last().toInt();

    this->click_send_type = MainWindow::port;

    this->property_type_number = MainWindow::port; // 设置全局点击控件类型

    this->set_property_interface(MainWindow::port, port_number);
}

void MainWindow::on_module_clicked()
{
    //tabs *tab = (tabs *)ui->tabWidget->currentWidget();

    this->click_send_type = MainWindow::module;

    this->set_property_interface(MainWindow::module, 0);
}

void MainWindow::set_property_interface(int type, int port_number)
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();

    if (type == MainWindow::port)
    {
        ui->toolBox_right->setCurrentIndex(1);
        Port port = tab->getModuleObject().getSelectedPort(port_number);
        this->temp_port_number = port_number;

        // 加载Label

        QStringList property_text;
        property_text << "Name" << "Inout" << "DataType" << "DataSize" << "Function" << "Color";

        for (int row = 1; row < property_text.length() + 1; row++)
        {
            QLabel *label_name = new QLabel(ui->toolbox_property);
            label_name->setText(property_text.at(row - 1));
            ui->gridLayout_2->addWidget(label_name, row, 0);
        }


        // 加载line edit
        //
        QLineEdit *line_edit = new QLineEdit(ui->toolbox_property);
        line_edit->setText(port.getName());
        line_edit->setObjectName("p_name");
        connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
        ui->gridLayout_2->addWidget(line_edit, 1, 1);

        line_edit = new QLineEdit(ui->toolbox_property);
        line_edit->setText(QString::number(port.getDataSize()));
        line_edit->setObjectName("datasize");
        connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
        ui->gridLayout_2->addWidget(line_edit, 4, 1);

        line_edit = new QLineEdit(ui->toolbox_property);
        line_edit->setText(port.getAnnotation());
        line_edit->setObjectName("function");
        connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
        ui->gridLayout_2->addWidget(line_edit, 5, 1);


        // 加载ComboBox
        //
        QComboBox *combobox = new QComboBox(ui->toolbox_property);
        QStringList port_type_list;
        port_type_list << "input" << "output" << "inout";
        combobox->addItems(port_type_list);
        combobox->setCurrentIndex(port.getPortType());
        combobox->setObjectName("porttype");
        connect(combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combobox_current_index_changed(int)));
        ui->gridLayout_2->addWidget(combobox, 2, 1);

        combobox = new QComboBox(ui->toolbox_property);
        QStringList data_type_list;
        data_type_list << "wire" << "reg";
        combobox->addItems(data_type_list);
        combobox->setCurrentIndex(port.getDataType());
        combobox->setObjectName("datatype");
        connect(combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combobox_current_index_changed(int)));
        ui->gridLayout_2->addWidget(combobox, 3, 1);

        combobox = new QComboBox(ui->toolbox_property);
        ui->gridLayout_2->addWidget(combobox, 6, 1);
    }

    if (type == MainWindow::module)
    {
        ui->toolBox_right->setCurrentIndex(2);
        Module module = tab->getModuleObject();

        QStringList property_text;

        property_text << "Name" << "Annotation";

        for (int row = 1; row < property_text.length() + 1; row++)
        {
            QLabel *label_name = new QLabel(ui->toolbox_m_property);
            label_name->setText(property_text.at(row - 1));
            ui->gridLayout_3->addWidget(label_name, row, 0);
        }

        QLineEdit *line_edit = new QLineEdit(ui->toolbox_m_property);
        line_edit->setText(module.getName());
        line_edit->setObjectName("m_name");
        connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
        ui->gridLayout_3->addWidget(line_edit, 1, 1);

        line_edit = new QLineEdit(ui->toolbox_m_property);
        line_edit->setText(module.getAnnotation());
        line_edit->setObjectName("annotation");
        connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
        ui->gridLayout_3->addWidget(line_edit, 2, 1);

    }
}

void MainWindow::on_combobox_current_index_changed(int index)
{
    qDebug() << index << "change";

    QComboBox *combobox = qobject_cast<QComboBox *>(sender());
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();

    QString object_name = combobox->objectName();

    if (object_name == "porttype")
    {
        switch (index) {
        case INPUT:
            tab->getModuleObject().getSelectedPort(this->temp_port_number).setPortType(INPUT);
            break;
        case OUTPUT:
            tab->getModuleObject().getSelectedPort(this->temp_port_number).setPortType(OUTPUT);
            break;
        case INOUT:
            tab->getModuleObject().getSelectedPort(this->temp_port_number).setPortType(INOUT);
            break;
        }

    }
    else if (object_name == "datatype")
    {
        tab->getModuleObject().getSelectedPort(this->temp_port_number).setDataType(index);
    }
}

void MainWindow::on_actionProject_triggered()
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    //m.exportProject();
//    QUrl test = QFileDialog::getSaveFileUrl(NULL,QStringLiteral("导出工程目录"),QStringLiteral("C:/"),QStringLiteral("目录(*)"));
//    qDebug()<<test;
    QString filePath = QFileDialog::getSaveFileName(NULL, QStringLiteral("导出工程目录"),QStringLiteral("C:/"),QStringLiteral("目录(*)"));

    QDir *folder = new QDir;
    bool exist = folder->exists(filePath);
    if (exist)
    {
        ui->textEdit->append("目录已存在\n");
    }else{
        folder->mkdir(filePath);
    }
    filePath = filePath + "/";
    QString codeFile = filePath + (m.getName()) + ".v";
    QFile file1(codeFile);
    if(!file1.open(QIODevice::WriteOnly)){
        ui->textEdit->append("保存code文件出错\n");
    }
    QByteArray geneCodesArr = (m.generateCode(m.getCode())).toUtf8();
    file1.write(geneCodesArr);
    file1.close();

    QString moduleFile = filePath + (m.getName() + ".mod");
    QFile file2(moduleFile);
    if(!file2.open(QIODevice::WriteOnly)){
        ui->textEdit->append ("保存module文件出错\n");
    }
    file2.close();
    QDomDocument doc = m.module_relay();
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            ui->textEdit->append ("保存module文件出错\n");
        }
    QTextStream out(&file2);
    doc.save(out, 4);
    file2.close();

    QString logFile = filePath + (m.getName() + ".log");
    QFile file3(logFile);
    if(!file3.open(QIODevice::WriteOnly)){
        ui->textEdit->append ("保存log文件出错\n");
    }
    QString log = ui->textEdit->toPlainText();
    QByteArray logArr = log.toUtf8();//将qstring转换为qbytearray
    file3.write(logArr);
    file3.close();
    ui->textEdit->append(getSysTime()+m.getName()+"的工程文件集已导出至："+filePath+"目录\n");//发送log消息
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    qDebug() << "clicked";
    QLayoutItem *item;
    while ((item = ui->gridLayout_2->takeAt(0)))
    {
        ui->gridLayout_2->removeItem(item);
        delete item->widget();
    }
    while ((item = ui->gridLayout_3->takeAt(0)))
    {
        ui->gridLayout_3->removeItem(item);
        delete item->widget();
    }
    qDebug()<<"666"<<ui->tabWidget->count();

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QLineEdit *line_edit = qobject_cast<QLineEdit *>(sender());
//    qDebug() << line_edit->objectName() << "Finish";
    QString object_name = line_edit->objectName();

    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    QString tab_name = tab->objectName().split("_")[0];

    if (object_name == "p_name")
    {
        tab->getModuleObject().getSelectedPort(this->temp_port_number).setName(arg1);



        if (click_send_type == MainWindow::port) // 当点击是按钮时
        {
            QPushButton *button = tab->findChild<QPushButton *>(tab_name + "_p_" + QString::number(this->temp_port_number));
            button->setText(arg1);
        }

       // setText(tab->getModuleObject().getSelectedPort(this->temp_port_number).getName());
    }
    else if (object_name == "datasize")
    {
        tab->getModuleObject().getSelectedPort(this->temp_port_number).setDataSize(arg1.toInt());
    }
    else if (object_name == "function")
    {
        tab->getModuleObject().getSelectedPort(this->temp_port_number).setAnnotation(arg1);
    }
    else if (object_name == "m_name")
    {
        tab->getModuleObject().setName(arg1);
        if (click_send_type == MainWindow::module)
        {
            QLabel *label = tab->findChild<QLabel *>(tab_name + "_nameLable");
            label->setText(arg1);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), arg1);
        }

    }
    else if (object_name == "annotation")
    {
        tab->getModuleObject().setAnnotation(arg1);
    }
}

void MainWindow::change_tab_index(int index)
{
    ui->tabWidget->setCurrentIndex(index);
}

int MainWindow::get_tab_index()
{
    return ui->tabWidget->count();
}

void MainWindow::on_load()
{
    this->init_tab_widget("module", 0, 0, 0,2);
}

void MainWindow::on_actionSave_triggered()
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    if(tab->flag == 0){
        QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("生成Module文件"),m.getName(),QStringLiteral("Module(*.mod)"));
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            ui->textEdit->append(getSysTime()+"保存文件失败\n");//发送log消息
            return;
        }
        file.close();

        QDomDocument doc;

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                qDebug() << "open for add error!!";
            }
        doc = m.module_relay();
        QTextStream out(&file);
        doc.save(out, 4);
        file.close();
        ui->textEdit->append(getSysTime()+m.getName()+"的模块文件已保存至路径： "+fileName+"\n");//发送log消息
        tab->filePath = fileName;
    }else if (tab->flag == 1){
        QString fileName = tab->filePath;
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            ui->textEdit->append(getSysTime()+"保存文件失败\n");//发送log消息
            return;
        }
        file.close();

        QDomDocument doc;

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                qDebug() << "open for add error!!";
            }
        doc = m.module_relay();
        QTextStream out(&file);
        doc.save(out, 4);
        file.close();
        ui->textEdit->append(getSysTime()+m.getName()+"的模块文件已保存至路径： "+fileName+"\n");//发送log消息
    }
    tab->flag = 1;
}

void MainWindow::on_actionSave_As_triggered()
{
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    QString fileName = QFileDialog::getSaveFileName(NULL, QStringLiteral("生成Module文件"),m.getName(),QStringLiteral("Module(*.mod)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        ui->textEdit->append(getSysTime()+"另存为文件失败\n");//发送log消息
        return;
    }
    file.close();

    QDomDocument doc;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "open for add error!!";
        }
    doc = m.module_relay();
    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
    ui->textEdit->append(getSysTime()+m.getName()+"的模块文件已另存为至路径： "+fileName+"\n");//发送log消息
    tab->filePath = fileName;
    tab->flag = 1;
}

void MainWindow::on_actionAdd_to_popular_triggered()
{
    QString configPath = QCoreApplication::applicationDirPath();
    tabs *tab = (tabs *)ui->tabWidget->currentWidget();
    Module m = tab->getModuleObject();
    if (tab->flag == 0){
        MainWindow::on_actionSave_triggered();
        QString tempPath = tab->filePath;
        QDomDocument doc;
        QDomElement elementRoot = doc.createElement("module");
        QDomElement elementName = doc.createElement("name");
        QDomElement elementPath = doc.createElement("path");
        elementPath.appendChild(doc.createTextNode(tab->filePath));
        elementName.appendChild(doc.createTextNode(m.getName()));
        elementRoot.appendChild(elementName);
        elementRoot.appendChild(elementPath);
        doc.appendChild(elementRoot);
        QFile file(configPath+"/config.ini");
        while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
        QTextStream out(&file);
        doc.save(out, 4);
        file.close();
        ui->textEdit->append(getSysTime()+m.getName()+"模块已加入常用区\n");
        tab->isPopular = 1;
    }else if(tab->flag == 1){
        if(tab->isPopular == 1){
            ui->textEdit->append(getSysTime()+"该模块已在常用区\n");
        }else{
            QString tempPath = tab->filePath;
            QDomDocument doc;
            QDomElement elementRoot = doc.createElement("module");
            QDomElement elementName = doc.createElement("name");
            QDomElement elementPath = doc.createElement("path");
            elementPath.appendChild(doc.createTextNode(tab->filePath));
            elementName.appendChild(doc.createTextNode(m.getName()));
            elementRoot.appendChild(elementName);
            elementRoot.appendChild(elementPath);
            doc.appendChild(elementRoot);
            QFile file(configPath+"/config.ini");
            while(!file.open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
            QTextStream out(&file);
            doc.save(out, 4);
            file.close();
            ui->textEdit->append(getSysTime()+m.getName()+"模块已加入常用区\n");
            tab->isPopular = 1;
        }
    }
}



void MainWindow::on_actionChinese_triggered()
{
    QTranslator m;
    QString currentPath = QCoreApplication::applicationDirPath();
    m.load(currentPath+"/lang/Chinese.qm");
    qApp->installTranslator(&m);
    this->ui->retranslateUi(this);
}

void MainWindow::on_actionEnglish_triggered()
{
    QString currentPath = QCoreApplication::applicationDirPath();
    QTranslator m;
    m.load(currentPath+"/lang/English.qm");
    qApp->installTranslator(&m);
    this->ui->retranslateUi(this);
}
