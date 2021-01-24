# eda_qt

### -介绍
eda软件开发

## -           开发需求
### ------------001------------
点击“新建模块”按钮后，弹出一对话框，如：
![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/232300_bb1cd7c7_8607408.png "QQ截图20210123232228.png")  

用户可输入：模块名称、input端口数量、output端口数量、inout端口数量  
点击ok后，将出现一“矩形图”，代表着该模块  
![这是我们软件里用的矩形](https://images.gitee.com/uploads/images/2021/0123/232810_4125e7a6_8607408.png "矩形.png")  
上图是我们要开发的软件里用的矩形图  
这是我们仿照的软件里的截图，模块名为123，input、output、inout都为1  
![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/232955_c341839e_8607408.png "QQ截图20210123232905.png")  
点击某一端口时，应做到可以修改端口的属性，包括：![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/233219_b40e4d51_8607408.png "QQ截图20210123233154.png")  
|端口名：要在矩形图上体现  
|输入输出类型：可以在input、output、inout中选![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/233346_328b5e77_8607408.png "QQ截图20210123233330.png")  
|数据类型：可以在wire、reg中选![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/233408_06262ce9_8607408.png "QQ截图20210123233336.png")  
|数据长度：可设置正整数值  
|颜色：此功能目前可先不做。。  
### ------------002------------  
双击模块矩形，可进入用户代码编辑界面  
此时用户只需要输入算法代码 如：assign c = a & b;  
其他代码由软件自动生成。 
![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/234049_deade8af_8607408.png "QQ截图20210123234037.png")  
其中第一段的格式为module xxx[*](端口名); 如用户在最开始的对话框中填写模块名为123，且整个模块中所有的端口为a、b、c三个时  
软件将会生成module 123[*](a,b,c);  
 **第二段** 代码为：input/output/inout 端口名；例如用户设置a为input,b为output,c为inout。则代码为  
input a; output b; inout c;  
 **第三段** 代码为：端口数据类型 端口名；例如用户定义a端口为wire型，b、c端口为reg型，则：  
wire a; reg b; reg c;  
第四段代码为之前用户输入的算法代码  
最后是固定句式：endmodule 相当于这个模块结束了  
另外要注意：当端口的数据长度定义为i（正整数）时，相应的在上述 **第二段、第三段** 代码中要有所改变，在端口名前加[i-1:0]  
例如：![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/234717_374091e7_8607408.png "QQ截图20210123234621.png")用户定义了p0为3位    
![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/234922_d18c6d0d_8607408.png "QQ截图20210123234626.png")  ![输入图片说明](https://images.gitee.com/uploads/images/2021/0123/234930_6490091b_8607408.png "QQ截图20210123234630.png")  
则p0前面加[2:0]  
### ------------003------------  
应有“保存模块”和“生成代码”两个按钮。其中：  
保存模块：做到将此次用户新建的模块里的所有内容打包保存 下次用户双击时可以直接在软件里打开  
生成代码：将软件生成的代码 让用户选择位置保存。保存为 **verilog目录**  目录下应有 **此模块及其内部子模块** 所有的verilog代码文件  **扩展名为.v**   









