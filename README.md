## 禁止商用
## 可执行文件请在右侧“发行版”中下载
## 支持Windows、Macos、Linux(X86)平台


## 简介	Introduction

![DX-20220118@2x](pics/DX-20220118@2x.png)

此软件是用QT进行编写的一款可视化的用于FPGA设计的EDA软件。具备了传统FPGA EDA软件不具备的可视化设计功能，使开发工作变得更简单、直观。特点是可视化和代码相结合，灵活性高，自动生成代码等。

This software is a visualized EDA software for FPGA design written by QT. It has the visual design function that traditional FPGA EDA software does not have, which makes the development work more simple and intuitive. It is characterized by the combination of visualization and code, high flexibility and automatic code generation.

![image-20210214213005184](pics/image-20210214213005184.png)

## 如何使用	How to use

![image-20210214213219086](pics/image-20210214213219086.png)

如上图，整个软件分为：

1.菜单栏：包括文件的新建、打开、保存等操作。软件首选项设置。代码的生成、查看与导出等功能。

2.工作区：对模块、端口的操作以及核心算法的代码编写和整体代码的查看。

3.属性栏：当在工作区中选中端口或是模块后，右侧将会显示它们的属性，可以进行修改。

4.常用模块区：用户可将自己常用的模块保存至此，方便重复利用。

5.信息输出区：用来记录一些工作中的信息以及显示错误和警告。



As shown in the figure above, the whole software is divided into:

1. Menu bar: including the new file, open, save and other operations. Software preferences settings. Code generation, view and export functions.

2. Work area: operation of module and port, code writing of core algorithm and view of overall code.

3. Property bar: when ports or modules are selected in the workspace, their properties will be displayed on the right side, which can be modified.

4. Popular module area: users can save their common modules here for reuse.

5. Information output area: used to record some working information and display errors and warnings.

## 示例 	Example

创建一个功能为两输入的与门，输入输出信号的数据长度均为2 bits

Create an *andgate* with two input ports and one output port. The data size of input and output signals is 2 bits.

先在菜单栏的File->New->New Module中打开新建模块的对话框

First, open the new module dialog box in File > New > new module in the menu bar

![image-20210214214031903](pics/image-20210214214031903.png)

在对话框中输入想创建的模块名、各端口数量。本例的模块名为andgate，输入端口数为2，输出端口数为1

In the dialog box, enter the name of the module you want to create and the number of ports. The module in this example is called *andgate*, with two input ports and one output port

![image-20210214214206653](pics/image-20210214214206653.png)

点击OK后，工作区将会新建一个名为andgate的模块

After clicking OK, a new module named *andgate* will be created in the workspace

![image-20210214214312177](pics/image-20210214214312177.png)

其中左侧黄色的端口为输入端口，右侧灰色的端口为输出端口。首先先将默认的端口名p1、p2、p3分别改名为a、b、out。a和b端口为输入端口，out为输出端口。并将三个端口的数据长度都改成2位。

The yellow port on the left is the input port, and the gray port on the right is the output port. First, change the default port names p1, p2 and p3 to a, b and out respectively. Ports a and b are input ports, and out is output port. The data size of the three ports is changed to 2 bits.

![image-20210214214627832](pics/image-20210214214627832.png)

修改完如图：

As shown in the figure:

![image-20210214214705402](pics/image-20210214214705402.png)

其中，Name为端口名称，Inout为端口的输入输出类型，DataType为wire或reg型，DataSize为端口的数据长度，Function为用户给端口的功能备注。

***Name*** is the port's name, ***Inout*** is the *input / output* type of the port, ***Datatype*** is *wire* or *reg* type, ***Datasize*** is the data size of the port, and ***Function*** is the function remarks given by the user to the port.

将端口属性设置完毕后，在工作区的左下角的Code Editor中开始编写功能算法代码：

After setting the port properties, start to write the function algorithm code in the **Code Editor** in the lower left corner of the workspace

```verilog
assign out = a & b;
```

![image-20210214215105141](pics/image-20210214215105141.png)

关闭代码编辑器后代码将会自动保存，此时可点击Code View查看生成的完整代码

After closing the code editor, the code will be saved automatically. At this time, you can click **Code View** to view the generated complete code

![image-20210215021916023](pics/image-20210215021916023.png)

最后在菜单栏中Code->CodeGenerate可以将verilog代码保存至.v文件

Finally, in the menu bar, Code -> Codegenerate can save the Verilog code to the *. v file*

![image-20210214215401838](pics/image-20210214215401838.png)

下方信息输出区也会有相应的提示

The information output area will also have corresponding prompts

![image-20210214215421023](pics/image-20210214215421023.png)

这是保存的.v文件，与Code View中的完整代码一致

This is the saved *.v file*, consistent with the complete code in **Code View**

![image-20210215021949830](pics/image-20210215021949830.png)

模块文件的保存则是在菜单栏中File->Save中进行

The module file is saved in the menu bar File-> Save



![image-20210214215520178](pics/image-20210214215520178.png)

保存的模块文件的文件名默认和模块的Name一致，后缀为.mod

The file name of the saved module file is the same as the module name by default, and the suffix is *'.Mod'*

![image-20210214215604370](pics/image-20210214215604370.png)

也可选择Save As...来进行另存为

You can also select 'Save As...' to save as

mod文件的打开在菜单栏的File->Open

The *'.mod' file* can be opened in the menu bar File -> Open

![image-20210214215715142](pics/image-20210214215715142.png)

选中.mod文件后即可在工作区内打开

It can be opened in the workspace

![image-20210214215739450](pics/image-20210214215739450.png)

下方的信息输出区也可导出为日志，在File->Export...->Log

The information output area can also be exported as a log file. In File -> Export... ->Log

![image-20210214220042606](pics/image-20210214220042606.png)

![image-20210214220127145](pics/image-20210214220127145.png)

Export->Project是将此模块相关的.v、.mod、.log文件导出至一个目录中。

Export > Project can exports *. v, . mod, .log files* related to this module to a directory.

## 其他功能说明以及待开发的内容	Other function description and something to be developed

Edit->Clear Log可以将信息输出区清空

Edit -> Clear log can clear the information output area

![image-20210214220251371](pics/image-20210214220251371.png)

Tools->Preference->Language可以进行中英文切换

Tools -> Preference -> Language can switch between Chinese and English

![image-20210214220412076](pics/image-20210214220412076.png)

File->Add to Popular的作用是将当前模块添加到左侧常用区（正在开发）

The function of File > Add to Popular is to add the current module to the left popular area (under development)

![image-20210214220540866](pics/image-20210214220540866.png)

File->New->New Constrain/Testbench是新建约束文件和新建测试文件（正在开发）

The function of File->New->New Constrain/Testbench is a new constraint file and a new test file (under development)

![image-20210214220606964](pics/image-20210214220606964.png)

左侧常用区下面的Example是示例模块（还没做）

The example below the popular area on the left is the example module (to be developed)

![image-20210214220727743](pics/image-20210214220727743.png)

仿真功能（还没做）

Simulation function (to be developed)

多级模块以及例化（还没做）

Multi level module and instantiation (to be developed)

……（还没做。。。）

……  (to be developed...)

## 文件目录	File directory

lang目录:语言包

./lang: language pack

![image-20210214222745369](pics/image-20210214222745369.png)

pics目录:图片

./pics: pictures

release目录:发布后的可执行文件。eda_qt_Vxx.exe为未打包的程序，不可单独使用。eda_qt_Vxx_boxed.exe为打包后的程序，可不放在目录中单独使用。注：如需要切换中英文，则lang目录必须存在。

./release: Executable file after release. *eda_ qt_ Vxx.exe* It is an unpackaged program and cannot be used alone. *eda_ qt_ Vxx_ boxed.exe* is the packaged program, it can be used alone without being placed in the directory. Note: if you need to switch between Chinese and English, *lang* directory must exist.

src目录:代码文件，如下

./src: Code files

ui文件：界面的设计

ui files: User interface

![image-20210214221353054](pics/image-20210214221353054.png)

每个ui文件对应一个同名的.cpp和.h文件

Each UI file corresponds to a .CPP and a .H file with the same name

about_dialog.ui:“关于”的界面

code_editor_dialog.ui:代码编辑、查看器的界面

mainwindow.ui:主界面

new_constrain:新建约束文件的界面

new_module:新建模块文件的界面

new_testbench:新建测试文件的界面

以下都为.cpp和.h文件

tabs:工作区的类

moduleqwidget:未使用

module:模块的类，模块相关的属性和方法

constrain:约束文件的类（待开发）

testbench:测试文件的类（待开发）

port:端口类，端口相关的属性和方法

Qsci目录：QScintilla是一个免费、跨平台、支持语法高亮的编辑控件。

![image-20210214222136046](pics/image-20210214222136046.png)

Chinese/English.ts:QT语言家文件

![image-20210214222457488](pics/image-20210214222457488.png)



















