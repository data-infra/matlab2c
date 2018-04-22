开发注意事项：

1、目前matlab2c对矩阵的实现仅包含实数型、复数型数据。实数型矩阵使用Matrix定义，复数型矩阵使用CMatrix定义。
2、实数矩阵元素int、float元素类型会自动转为double。 复数元素类型为c++标准复数std::complex<double>使用typedef别名定义为Complex
3、本应用开发环境为vs2012，建议使用c++11编译器
4、借助广大网友的力量，动态链接库会实时更新实现更多的函数功能，欢迎下载最新版2017-12-06。
5、开发中请尽量规范代码编写，调用函数使用Matlab2c::xx函数，避免与其他库同名函数、同名变量的冲突
6、使用动态链接库dll，文件较小，需要匹配的调试环境。静态链接库，文件较大，不需要匹配的调试环境。

matlab2c开发调用方法（2选1）：

使用动态链接库：
1、将Matlab2c.dll拷贝到exe同目录下
2、将Matlab2c.h、Matlab2c.lib放到项目头文件目录下 
3、在cpp文件中引入下面的代码
#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;


使用静态链接库：
1、将Matlab2c.h、Matlab2c.lib放到项目头文件目录下 
2、在cpp文件中引入下面的代码
#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;
