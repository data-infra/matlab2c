#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;

//在Matlab2c空间中，使用typedef std::complex<double> Complex将c++标准复数重命名为Complex，所以Complex的使用遵循标准复数的使用

//声明三个调用函数
Complex map_fun(Complex item,int row,int column,CMatrix& src);
Complex map_row_fun(Complex prev,Complex cur,int row,int column,CMatrix& src);
Complex map_column_fun(Complex prev,Complex cur,int row,int column,CMatrix& src);
int main()
{
	Complex com0= Complex(0,0);
	Complex com1 = Complex(1,1);
	Complex com2 = Complex(2,2);
	Complex com3 = Complex(3,3);
	Complex com4 = Complex(4,4);
	Complex com5 = Complex(5,5);
	Complex com6 = Complex(6,6);
	Complex com7 = Complex(7,7);
	Complex com8 = Complex(8,8);
	Complex com9 = Complex(9,9);
	cout<<com1+2.0<<endl;								//Complex在运算中只能将double型数据自动转化为Complex

	try{

	//生成矩阵
	double a0[]={1,2,3,4,5,6};
	double a1[]={1,2,3,4,5,6};
	CMatrix matrix1();									//定义一个空矩阵
	CMatrix matrix2(2,3);								//定义矩阵行列，但是不定义矩阵元素的值
	CMatrix matrix3(2,3,Complex(1,-1));					//定义矩阵行列，同时设置所有元素的值等于第三个参数
	CMatrix matrix4(3.14);								//定义一个1x1的矩阵,可以使用一个实数，会自动转为复数
	CMatrix matrix4_1(Matrix(a0,2,3));					//使用实数矩阵生成复数矩阵，虚部为0
	CMatrix matrix4_2(Matrix(a0,2,3),Matrix(a0,2,3));   //使用两个实数矩阵生成复数矩阵，分别为实部和虚部
	CMatrix matrix4_3(2,3,a0,a1);						//使用两个实数数组生成复数矩阵，分别为实部和虚部
	CMatrix matrix4_4(a0,a1,2,3);						//使用两个实数数组生成复数矩阵，分别为实部和虚部
	cout<<"matrix4_4:\n"<<matrix4_4.toString()<<endl;   //输出矩阵

	//使用double[]定义矩阵
	Complex a[6] = {com1,com2,com3,com4,com5,com6};
	CMatrix matrix5(2,3,a);								//使用一维数组定义一个矩阵，矩阵元素个数小于等于数组元素个数
	CMatrix matrix6(1,6,a);								//定义一个行向量
	CMatrix matrix7(5,1,a);								//定义一个列向量,不使用全部数据
	cout<<"matrix7:\n"<<matrix7.toString()<<endl;		//输出矩阵


	//使用vector<>和vector<vector<>>定义矩阵
	vector<Complex> ivec(a, a+6);						//定义一个vector
	CMatrix matrix8(ivec);								//使用vector定义一列矩阵（列向量）
	CMatrix matrix9(ivec,2,3);							//使用vector定义矩阵
	vector<Complex> ivec1(a, a+6);
	vector<vector<Complex>> arr;						//定义一个vector<vector<>>
	arr.push_back(ivec);
	arr.push_back(ivec1);
	CMatrix matrix10(arr);								//使用vector<vector<double>>定义矩阵
	cout<<"matrix10:\n"<<matrix10.toString()<<endl;		//输出矩阵
	
	////使用double[][]定义矩阵
	Complex aa[2][3]={{com1,com2,com3},{com4,com5,com6}} ;
	CMatrix matrix11(2,3,(Complex*)aa);					//使用二维数组定义一个矩阵，矩阵元素个数小于等于数组元素个数
	cout<<"matrix11:\n"<<matrix11.toString()<<endl;		//输出矩阵


	//复制和赋值
	CMatrix matrix12 = matrix5;							//复制生成一个矩阵，复制所有元素。
	CMatrix matrix13;
	matrix13=matrix5;									//赋值一个矩阵，复制所有元素
	cout<<"matrix13:\n"<<matrix13.toString()<<endl;		//输出矩阵

	//元素读取和赋值
	matrix13(0,1) = com0;								//矩阵元素赋值，下标从0开始
	com0 = matrix13(1,0);								//读取矩阵元素，下标从0开始
	matrix7(0)=com0;									//向量元素赋值，下标从0开始
	com0 = matrix7(1);									//读取向量元素，下标从0开始

	//子矩阵读取
	CMatrix matrix14=matrix5(0,1,0,2);					//参数起始行（包含）、终止行（包含）、起始列（包含）、终止列（包含）
	cout<<"matrix14:\n"<<matrix14.toString()<<endl;		//输出矩阵
	
	//矩阵转置
	CMatrix matrix15 = matrix5.T();						//T函数为转置
	cout<<"matrix15:\n"<<matrix15.toString()<<endl;		//输出矩阵

	//矩阵的运算
	Complex arr1[]={com1,com2,com3,com4,com5,com6};
	Complex arr2[]={com6,com5,com4,com3,com2,com1};
	CMatrix matrix16(2,3,arr1);
	CMatrix matrix17(2,3,arr2);

	//矩阵加法
	CMatrix matrix18=matrix16+matrix17;					//矩阵相加
	matrix18 +=matrix16;								//矩阵+=运算符
	matrix18 = matrix16+1;								//矩阵加上常数，每个元素均加上常数
	matrix18 +=com1;									//矩阵+=运算符
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//输出矩阵

	//矩减法
	matrix18 =matrix16-matrix17;						//矩阵相减
	matrix18 -=matrix16;								//矩阵-=运算符
	matrix18 = matrix16-1;								//矩阵减去常数，每个元素均减去常数
	matrix18 -=com1;									//矩阵-=运算符
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//输出矩阵

	//矩阵乘法
	matrix17 = CMatrix(3,2,arr2);
	matrix18 =matrix16*matrix17;						//矩阵相乘，
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//输出矩阵
	matrix18 =matrix18*3.0;								//矩阵乘以常数，每个元素均乘以常数
	matrix18 *=com1;									//矩阵常数的*=运算
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//输出矩阵

	//矩阵除法
	matrix18 = matrix16/3.0;							//矩阵除以常数，每个元素均除以常数
	matrix18 /=com1;									//矩阵常数的/=运算
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//输出矩阵

	//矩阵点运算
	CMatrix matrix19=matrix16.dot(matrix5,"+");			//点运算要求两个矩阵行列数相同
	matrix19=matrix16.dot(matrix5,"-");
	matrix19=matrix16.dot(matrix5,"*");
	matrix19=matrix16.dot(matrix5,"/");
	matrix19=matrix16.dot(matrix5,"\\");				//右除函数\在字符串中会被理解为转义符号，所以需要\\代表右除
	cout<<"matrix19:\n"<<matrix19.toString()<<endl;		//输出矩阵

	//矩阵正负号运算
	CMatrix matrix20=-matrix16;							//负号表示每个元素都取反
	matrix20=+matrix16;									//正号表示元素不变
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;		//输出矩阵

	//矩阵相等和不等判断
	if (matrix16==matrix5)								//矩阵相等性判断，每个元素均相等，要求行列数和每个元素都相等
		if (matrix5!=matrix6)							//矩阵的不相等性判断，行数、列数或其中任意一个元素不相等都会判断为不相等
			cout<<"矩阵16和矩阵5相等，矩阵5和矩阵6不相等"<<endl;

	//判断矩阵是否为行向量或列向量
	if (matrix6.isVector())
		cout<<"矩阵6是向量"<<endl;

	//矩阵横向和纵向扩展，改变源矩阵
	CMatrix matrix21=matrix16;	
	matrix21.append_left(matrix3);						//在矩阵左侧扩展，改变了源矩阵，返回void，要求两个矩阵行数相等，等价于[matrix3,matrix21]
	matrix21=matrix16;
	matrix21.append_right(matrix3);						//在矩阵右侧扩展，改变了源矩阵，返回void，要求两个矩阵行数相等，等价于[matrix21,matrix3]
	matrix21=matrix16;
	matrix21.append_top(matrix3);						//在矩阵顶部扩展，改变了源矩阵，返回void，要求两个矩阵列数相等，等价于[matrix3;matrix21]
	matrix21=matrix16;
	matrix21.append_bottom(matrix3);					//在矩阵下部扩展，改变了源矩阵，返回void，要求两个矩阵列数相等，等价于[matrix21;matrix3]
	cout<<"matrix21:\n"<<matrix21.toString()<<endl;		//输出矩阵

	//矩阵删除行列，改变源矩阵
	Complex b1[9] = {com1,com2,com3,com4,com5,com6,com7,com8,com9};
	CMatrix matrix22(3,3,b1);
	CMatrix matrix23=matrix22;
	matrix23.remove_row(1);								//删除矩阵指定行，下标从0开始
	matrix23=matrix22;
	matrix23.remove_row(0,1);							//删除矩阵多行，起始行下标（包含），终止行下标（包含），下标从0开始
	matrix23=matrix22;
	matrix23.remove_column(1);							//删除矩阵指定列，下标从0开始
	matrix23=matrix22;
	matrix23.remove_column(1,2);						//删除矩阵多列，起始列下标（包含），终止列下标（包含），下标从0开始
	matrix23=matrix22;
	matrix23.remove_row_column(1,1);					//删除矩阵指定行和指定列，下标从0开始
	matrix23=matrix22;
	matrix23.remove_row_column(0,1,1,1);				//删除矩阵多行和多列，起始行下标（包含），终止行下标（包含），起始列下标，终止列下标，下标从0开始
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;		//输出矩阵

	//替换子矩阵
	matrix22.replace(matrix5,0,1);						//matrix5为[1,2,3;4,5,6]，matrix22为[1,2,3;4,5,6;7,8,9]
	cout<<"matrix22:\n"<<matrix22.toString()<<endl;		//输出矩阵

	//矩阵遍历
	matrix23 = matrix5.map(map_fun);					//map函数遍历每一个元素，不改变源矩阵
	matrix23 = matrix5.map_row(map_row_fun);			//map函数按行遍历每一行，不改变源矩阵。每一行返回一个值，最后获得一个列向量
	matrix23 = matrix5.map_column(map_column_fun);		//map函数按列遍历每一列，不改变源矩阵。每一列返回一个值，最后获得一个行向量
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;		//输出矩阵

	//复矩阵属性函数
	Matrix matrix24;
	matrix24 = matrix5.real();							//求实部矩阵
	matrix24 = matrix5.imag();							//求虚部矩阵
	matrix24 = matrix5.angle();							//求角度矩阵
	matrix24 = matrix5.abs();							//求模值矩阵
	CMatrix matrix24_1 = matrix5.conj();				//求共轭矩阵
	cout<<"matrix24_1:\n"<<matrix24_1.toString()<<endl;	//输出矩阵

	//矩阵类型的转化
	CMatrix matrix25=matrix5;
	string str=matrix25.toString();						//转化为字符串，每个元素保留4位小数
	Complex *arr3 = matrix25.toSeries();				//转化为一维数组
	Complex **arr4 = matrix25.toArray();				//转化为二维数组
	vector<Complex> vec1 = matrix25.toVector();			//转化为一维向量vector
	vector<vector<Complex>> vec2 = matrix25.toVector2();//转化为二维向量vector
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
//此处的遍历函数为每一个元素加上1+1j
 Complex map_fun(Complex item,int row,int column,CMatrix& src)
 {
	 Complex com1(1,1);
	 return (item+com1);
 }

 //定义一个按行遍历函数(固定格式),每一行得到一个值
 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵。
 //迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
 //此处的按行遍历函数求每行中的实部最大值
 Complex map_row_fun(Complex prev,Complex cur,int row,int column,CMatrix& src)
 {
	 if(prev.real()>cur.real())
		 return prev;
	 return cur;
 }


 //定义一个按列遍历函数(固定格式),每一列得到一个值
  //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
 //迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
 //此处的按列遍历函数求每列中的平均值
 Complex map_column_fun(Complex prev,Complex cur,int row,int column,CMatrix& src)
 {
	 if(row==src.row-1)						//如果遍历到最后一行数据
		return (prev+cur)/(src.row*1.0);	//加上当前项，再取平均
	return prev+cur;						//前一项加上当前项，获得的和向后传递
 }
