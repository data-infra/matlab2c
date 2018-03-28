#include "Matlab2c.h"
using namespace Matlab2c;

//实矩阵求绝对值
//输入为一个矩阵，输出为该矩阵元素的绝对值矩阵。
Matrix Matlab2c::abs(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(a.row,a.column);
	for (i=0;i<(p.row*p.column);i++)
		p.data[i]=(double)std::fabs(a.data[i]);
	return p;
}
//矩阵元素朝正无穷大方向取整
//输入：原矩阵a
//输出：矩阵a元素向上取整
Matrix Matlab2c::ceil(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	p.data = new double[p.row*p.column];
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = std::ceil(a(i,j)); //ceil(x)返回的是大于等于x的最小整数
	return p;
}


//求以e为底的指数函数
//输入：矩阵a
//输出：矩阵a的以e为底的指数值
Matrix Matlab2c::exp(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::exp(a(i,j));
	return p;
}

//求元素平方根函数
//输入：矩阵a
//输出：矩阵a的元素平方根
Matrix Matlab2c::sqrt(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sqrt(a(i,j));
	return p;
}

//矩阵元素朝0方向取整
//输入：实矩阵a
//输出：矩阵元素向0取整
Matrix Matlab2c::fix(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = (int)(a(i,j)); //fix(x)返回的是靠近0的整数
	return p;
}


//矩阵元素朝负无穷方向取整
//输入：实矩阵a
//输出：矩阵元素向负无穷取整
Matrix Matlab2c::floor(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = std::floor(a(i,j));
	return p;
}


//求矩阵元素自然对数　
//输入：矩阵a，矩阵元素大于0
//输出：矩阵a的以e为底的对数值
Matrix Matlab2c::log(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::log(a(i,j));
	return p;
}

//求矩阵常数对数　
//输入：矩阵a，矩阵元素大于0
//输出：矩阵a的以10为底的对数值
Matrix Matlab2c::log10(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::log10(a(i,j));
	return p;
}


//求组合数
//输入：组合总个数n，可以组合的数目m
//输出：组合数目
int Matlab2c::nchoosek(int n,int m)
{
	Matlab2c::CheckLicense();
	int fenzi=1;
	int fenmu=1;
	int temp = n-m;
	for (;n>m;n--)
		fenzi = fenzi*n;
	for (;temp>0;temp--)
		fenmu = fenmu*temp;
	return fenzi/fenmu;
}



//矩阵正切函数
//输入：数据矩阵
//输出：正切值
Matrix Matlab2c::tan(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::tan(a(i,j));
	return p;
}
//矩阵反正切函数，
//输入：矩阵a
//输出：矩阵a的反正切值
Matrix Matlab2c::atan(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::atan(a(i,j));
	return p;
}

//矩阵双曲正切函数，
//输入：矩阵a
//输出：矩阵a的双曲正切值
Matrix Matlab2c::tanh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::tanh(a(i,j));
	return p;
}
//矩阵正弦函数
//输入：矩阵a
//输出：矩阵a的正弦值
Matrix Matlab2c::sin(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sin(a(i,j));
	return p;
}

//矩阵反正弦函数，
//输入：矩阵a
//输出：矩阵a的反正弦值
Matrix Matlab2c::asin(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::asin(a(i,j));
	return p;
}
//矩阵双曲正弦函数，
//输入：矩阵a
//输出：矩阵a的双曲正弦值
Matrix Matlab2c::sinh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sinh(a(i,j));
	return p;
}


//矩阵余弦函数
//输入：矩阵a
//输出：矩阵a的余弦值
Matrix Matlab2c::cos(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::cos(a(i,j));
	return p;
}

//矩阵反余弦函数，
//输入：矩阵a
//输出：矩阵a的反余弦值
Matrix Matlab2c::acos(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::acos(a(i,j));
	return p;
}


//矩阵双曲余弦函数
//输入：数据矩阵
//输出：双曲余弦值
Matrix Matlab2c::cosh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::cosh(a(i,j));
	return p;
}








//求整数阶乘
//当输入为整数时，返回输入的阶乘
int Matlab2c::factorial(int a)
{
	Matlab2c::CheckLicense();
	int d=1;
	for (;a>0;a--)
		d = d*a;
	return d;
}

//求矩阵阶乘
//当输入为矩阵时，返回一个同等大小的矩阵，每个矩阵上的数为之前的数的乘机
Matrix Matlab2c::factorial(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double d=1;
	for (int i=0;i<a.row*a.column;i++)
	{
		 d= d*a(i);
		 p(i)=d;
	}
	return p;
}