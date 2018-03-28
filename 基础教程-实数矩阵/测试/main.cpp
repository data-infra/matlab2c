#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;
//声明三个调用函数
double map_fun(double item,int row,int column,Matrix& src);
double map_row_fun(double prev,double cur,int row,int column,Matrix& src);
double map_column_fun(double prev,double cur,int row,int column,Matrix& src);
int main()
{
	try{
	//生成矩阵
	Matrix matrix1();   //定义一个空矩阵
	Matrix matrix2(2,3);  //定义矩阵行列，但是不定义矩阵元素的值
	Matrix matrix3(2,3,1.1);  //定义矩阵行列，同时设置所有元素的值等于第三个参数
	Matrix matrix3_1(3.14);  //定义一个1x1的矩阵
	cout<<"matrix3_1:\n"<<matrix3_1.toString()<<endl;   //输出矩阵

	//使用double[]定义矩阵
	double a[]={1,2,3,4,5,6};
	Matrix matrix4(2,3,a);    //使用一维数组定义一个矩阵，矩阵元素个数小于等于数组元素个数
	Matrix matrix5(1,6,a);	  //定义一个行向量
	Matrix matrix6(5,1,a);    //定义一个列向量,不使用全部数据
	cout<<"matrix6:\n"<<matrix6.toString()<<endl;   //输出矩阵


	//使用vector<>和vector<vector<>>定义矩阵
	vector<double> ivec(a, a+6);  //定义一个vector
	Matrix matrix6_1(ivec);   //使用vector定义一列矩阵（列向量）
	Matrix matrix6_2(ivec,2,3);   //使用vector定义矩阵
	vector<double> ivec1(a, a+6);
	vector<vector<double>> arr;    //定义一个vector<vector<>>
	arr.push_back(ivec);
	arr.push_back(ivec1);
	Matrix matrix6_3(arr);   //使用vector<vector<double>>定义矩阵
	cout<<"matrix6_3:\n"<<matrix6_3.toString()<<endl;   //输出矩阵
	
	//使用double[][]定义矩阵
	double aa[2][3]={{1,2,3},{4,5,6}} ;
	Matrix matrix7(2,3,(double*)aa);		//使用二维数组定义一个矩阵，矩阵元素个数小于等于数组元素个数
	Matrix matrix8("[1,2,3;4,5,6]");		//使用matlab语法字符串生成矩阵,分号表示换行
	Matrix matrix9("[1 2 3;4,5,6]");		//逗号或空格表示分列,
	Matrix matrix10("1 2 3;4,5,6;7 8 9");	//[]包含一个矩阵，可以省略
	Matrix matrix11("[1:2:8;4,5,6,7]");		//可以使用x1:x2:x3的数列形式表示一行数据，x1为首元素，x2为步长，x3为终点
	Matrix matrix12("[1:4;4,5,6,7]");		//可以使用x1:x3的数列形式表示一行数据，x1为首元素，x3为终点，步长为1
	Matrix matrix12_1=Matrix("1:3:12");				//生成向量
	matrix12_1 = Matrix("1:12");				//生成向量
	matrix12_1 = Matlab2c::linspace(1,12,13);	//使用函数生成向量，参数为起点，终点，数量
	cout<<"matrix12_1:\n"<<matrix12_1.toString()<<endl;   //输出矩阵


	//复制和赋值
	Matrix matrix13 = matrix12;				//复制生成一个矩阵，复制所有元素。[1,2,3,4;4,5,6,7]
	Matrix matrix14;
	matrix14=matrix12;		//赋值一个矩阵，复制所有元素
	cout<<"matrix14:\n"<<matrix14.toString()<<endl;   //输出矩阵

	//元素读取和赋值
	double dtemp=82.5;
	matrix14(0,1) = dtemp;   //矩阵元素赋值，下标从0开始
	dtemp = matrix14(1,0);   //读取矩阵元素，下标从0开始
	matrix5(0)=dtemp;   //向量元素赋值，下标从0开始
	dtemp = matrix5(1);  //读取向量元素，下标从0开始

	//子矩阵读取
	Matrix matrix15=matrix10(1,2,0,2);  //参数起始行（包含）、终止行（包含）、起始列（包含）、终止列（包含）
	Matrix matrix16=matrix10("1:2,0:1:2");  //读取子矩阵，下标从0开始
	Matrix matrix17=matrix6("0:2:5");  //读取子向量，下标从0开始
	cout<<"matrix17:\n"<<matrix17.toString()<<endl;   //输出矩阵
	//矩阵转置
	matrix17 = matrix4.T();   //T函数为转置
	cout<<"matrix17:\n"<<matrix17.toString()<<endl;   //输出矩阵

	//矩阵的运算
	double arr1[]={1,2,3,4,5,6};
	double arr2[]={6,5,4,3,2,1};
	Matrix matrix18(2,3,arr1);
	Matrix matrix19(2,3,arr2);

	//矩阵加法
	Matrix matrix20=matrix18+matrix19;   //矩阵相加
	matrix20 +=matrix18;	//矩阵+=运算符
	matrix20 = matrix18+1;	//矩阵加上常数，每个元素均加上常数
	matrix20 +=1;   //矩阵+=运算符
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //输出矩阵

	//矩减法
	matrix20 =matrix18-matrix19;  //矩阵相减
	matrix20 -=matrix18;  //矩阵-=运算符
	matrix20 = matrix18-1;	//矩阵减去常数，每个元素均减去常数
	matrix20 -=1;   //矩阵-=运算符
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //输出矩阵

	//矩阵乘法
	matrix19 = Matrix(3,2,arr2);
	matrix20 =matrix18*matrix19;  //矩阵相乘，
	matrix20 =matrix18*3;  //矩阵乘以常数，每个元素均乘以常数
	matrix20 *=3;  //矩阵常数的*=运算
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //输出矩阵

	//矩阵除法
	matrix20 = matrix18/3;	//矩阵除以常数，每个元素均除以常数
	matrix20 /=3;   //矩阵常数的/=运算
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //输出矩阵

	//矩阵点运算
	Matrix matrix20_1=matrix18.dot(matrix4,"+");   //点运算要求两个矩阵行列数相同
	matrix20_1=matrix18.dot(matrix4,"-");
	matrix20_1=matrix18.dot(matrix4,"*");
	matrix20_1=matrix18.dot(matrix4,"/");
	matrix20_1=matrix18.dot(matrix4,"\\");		//右除函数\在字符串中会被理解为转义符号，所以需要\\代表右除
	cout<<"matrix20_1:\n"<<matrix20_1.toString()<<endl;   //输出矩阵

	//矩阵正负号运算
	Matrix matrix21=-matrix18;    //负号表示每个元素都取反
	matrix21=+matrix18;  //正号表示元素不变
	cout<<"matrix21:\n"<<matrix21.toString()<<endl;   //输出矩阵

	//矩阵相等和不等判断
	if (matrix18==matrix4)   //矩阵相等性判断，每个元素均相等，要求行列数和每个元素都相等
		if (matrix4!=matrix5)  //矩阵的不相等性判断，行数、列数或其中任意一个元素不相等都会判断为不相等
			cout<<"矩阵18和矩阵4相等，矩阵4和矩阵5不相等"<<endl;

	//判断矩阵是否为行向量或列向量
	if (matrix5.isVector())
		cout<<"矩阵5是向量"<<endl;

	//矩阵横向和纵向扩展，改变源矩阵
	Matrix matrix22=matrix18;	//[1,2,3;4,5,6]
	matrix22.append_left(matrix3);   //在矩阵左侧扩展，改变了源矩阵，返回void，要求两个矩阵行数相等，等价于[matrix3,matrix22]
	matrix22=matrix18;
	matrix22.append_right(matrix3);   //在矩阵右侧扩展，改变了源矩阵，返回void，要求两个矩阵行数相等，等价于[matrix22,matrix3]
	matrix22=matrix18;
	matrix22.append_top(matrix3);   //在矩阵顶部扩展，改变了源矩阵，返回void，要求两个矩阵列数相等，等价于[matrix3;matrix22]
	matrix22=matrix18;
	matrix22.append_bottom(matrix3);   //在矩阵下部扩展，改变了源矩阵，返回void，要求两个矩阵列数相等，等价于[matrix22;matrix3]
	cout<<"matrix22:\n"<<matrix22.toString()<<endl;   //输出矩阵

	//矩阵删除行列，改变源矩阵
	Matrix matrix23=matrix10;	//[1 2 3;4,5,6;7 8 9]
	matrix23.remove_row(1);   //删除矩阵指定行，下标从0开始
	matrix23=matrix10;
	matrix23.remove_row(0,1);  //删除矩阵多行，起始行下标（包含），终止行下标（包含），下标从0开始
	matrix23=matrix10;
	matrix23.remove_column(1);  //删除矩阵指定列，下标从0开始
	matrix23=matrix10;
	matrix23.remove_column(1,2);  //删除矩阵多列，起始列下标（包含），终止列下标（包含），下标从0开始
	matrix23=matrix10;
	matrix23.remove_row_column(1,1);  //删除矩阵指定行和指定列，下标从0开始
	matrix23=matrix10;
	matrix23.remove_row_column(0,1,1,1);  //删除矩阵多行和多列，起始行下标（包含），终止行下标（包含），起始列下标，终止列下标，下标从0开始
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;   //输出矩阵

	//替换子矩阵
	matrix10.replace(matrix8,0,1);    //matrix8为[1,2,3;4,5,6]，matrix10为[1,2,3;4,5,6;7,8,9]
	cout<<"matrix10:\n"<<matrix10.toString()<<endl;   //输出矩阵

	//矩阵遍历
	Matrix matrix24;	//[1,2,3;4,5,6]
	matrix24 = matrix18.map(map_fun);   //map函数遍历每一个元素，不改变源矩阵
	matrix24 = matrix18.map_row(map_row_fun);   //map函数按行遍历每一行，不改变源矩阵。每一行返回一个值，最后获得一个列向量
	matrix24 = matrix18.map_column(map_column_fun);   //map函数按列遍历每一列，不改变源矩阵。每一列返回一个值，最后获得一个行向量
	cout<<"matrix24:\n"<<matrix24.toString()<<endl;   //输出矩阵

	//矩阵类型的转化
	Matrix matrix25=matrix4;	//[1 2 3;4,5,6]
	string str=matrix25.toString();   //转化为字符串，每个元素保留4位小数
	double *arr3 = matrix25.toSeries();  //转化为一维数组
	double **arr4 = matrix25.toArray();  //转化为二维数组
	vector<double> vec1 = matrix25.toVector();  //转化为一维向量vector
	vector<vector<double>> vec2 = matrix25.toVector2();  //转化为二维向量vector
	cout<<vec2[1][1]<<endl;
	}
	catch(exception err)
	{
		cout<<err.what()<<endl;
	}
	system("pause");
	return 0;
}

//定义一个遍历函数(格式固定)。输入参数：当前元素的值，所属行，所属列，源矩阵。返回当前元素的替代值。
//此处的遍历函数为每一个元素加上1
 double map_fun(double item,int row,int column,Matrix& src)
 {
	 return item+1;
 }

 //定义一个按行遍历函数(固定格式),每一行得到一个值
 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵。
 //迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
 //此处的按行遍历函数求每行中的最大值
 double map_row_fun(double prev,double cur,int row,int column,Matrix& src)
 {
	 if(prev>cur)
		 return prev;
	 return cur;
 }


 //定义一个按列遍历函数(固定格式),每一列得到一个值
  //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
 //迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
 //此处的按列遍历函数求每列中的平均值
 double map_column_fun(double prev,double cur,int row,int column,Matrix& src)
 {
	 if(row==src.row-1)  //如果遍历到最后一行数据
		return (prev+cur)/src.row;   //加上当前项，再取平均
	return prev+cur;		//前一项加上当前项，获得的和向后传递
 }
