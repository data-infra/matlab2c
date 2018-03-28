#include "Matlab2c.h"
using namespace Matlab2c;

//产生以输入元素为对角元素的矩阵
//输入为行向量或列向量，输出为以该向量为对角线的矩阵。
Matrix Matlab2c::blkdiag(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*a.column,a.row*a.column);
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
		{
			if (i==j)
				p(i,j)=a(j);
			else
				p(i,j)=0;
		}
	return p;
}

//多项式系数矩阵的友矩阵
//输入为多项式的系数向量，输出为该多项式的友矩阵。
Matrix Matlab2c::compan(Matrix& a)
{
	Matlab2c::CheckLicense();
	if(a.row!=1)
		throw_logic_error("多项式系数矩阵行数不为1");
	Matrix p(a.column-1,a.column-1);
	if(Matlab2c::FloatNotEqual(a(0),0))
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				if(i==0)
					p(j)=(a(j+1)/a(0));
				else if (i-j==1)
					p(i,j) =1;
				else
					p(i,j) =0;
			}
	else
		throw_logic_error("向量第一个元素为0，错误");
	return p;
}

//生成单位矩阵
//输入单位矩阵的维数，输出相应大小的单位矩阵。
Matrix Matlab2c::eye(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(n,n);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if (i==j)
				a(i,j)=1;
			else
				a(i,j)=0;
	return a;
}
Matrix Matlab2c::eye(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(row,column);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if (i==j)
				a(i,j)=1;
			else
				a(i,j)=0;
	return a;
}

//生成Hankel方阵
//输入为两个行向量，输出为其Hankel矩阵。
Matrix Matlab2c::hankel(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a.column,b.column);
	int i,j;
	if (a(a.column-1)!=b(0))
	{
		throw_logic_error("第一个向量最后一个元素和第二个向量第一个元素不相等");
	}
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if ((i+j)<(a.column))
				p(i,j)=a(i+j);
			else
				p(i,j)=b(i+j+1-a.column);
	return p;
}
Matrix Matlab2c::hankel(Matrix& a)
{
	Matrix p(a.column,a.column);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if ((i+j)<(a.column))
				p(i,j)=a(i+j);
			else
				p(i,j)=0;
	return p;
}

//生成Hilbert(希尔伯特)矩阵
//输入为矩阵的维数，输出相应大小的Hilbert矩阵。
Matrix Matlab2c::hilb(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=1.0/(i+j+1);
	return p;
}


//生成全1矩阵
//输入:矩阵的行数和列数
//输出:相应大小的全1矩阵。
Matrix Matlab2c::ones(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(n,n);
	for (i=0;i<a.row*a.column;i++)
		a.data[i]=1;
	return a;
}
Matrix Matlab2c::ones(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(row,column);
	for (i=0;i<a.row*a.column;i++)
			a.data[i]=1;
	return a;
}

//生成Pascal矩阵
//输入为矩阵的维数，输出相应大小的Pascal矩阵。
Matrix Matlab2c::pascal(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(i==0)
				p(i,j) =1;
			else if (j==0)
				p(i,j) =1;
			else
				p(i,j) =p(i-1,j)+p(i,j-1);
	return p;
}


//生成托普利兹矩阵
//a作为矩阵的第一列，b作为矩阵的第一行，首元素要求相等，返回响应的托普利兹矩阵
Matrix Matlab2c::toeplitz(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.column*a.row,b.column*b.row);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(j==0)
				p(i,j)=a(i);
			else if (i==0)
				p(i,j) =b(j);
			else
				p(i,j) =p(i-1,j-1);
	return p;
}


//生成Wilkinson特征值测试阵
//输入为矩阵的维数，输出相应大小的Wilkinson矩阵。
Matrix Matlab2c::wilkinson(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	if (n==1)
		p.data[0]=0;
	else if (n>1)
	{
		if (n%2==0)
		{
			for (i=0;i<p.row;i++)
				for (j=0;j<p.column;j++)
					if (i-j==1 || j-i==1)
						p(i,j) = 1;
					else if(i==j)
						p(i,j) =std::fabs((n-1)/2-i+0.5);
					else
						p(i,j) =0;
		}
		else
		{
			for (i=0;i<p.row;i++)
				for (j=0;j<p.column;j++)
					if (i-j==1 || j-i==1)
						p(i,j) = 1;
					else if(i==j)
						p(i,j) =std::abs(n/2-i);
					else
						p(i,j) =0;
		}
	}
	return p;
}

//矩阵的张量积
//两个矩阵两两元素(一个来自a一个来自b)可能的乘机
Matrix Matlab2c::kron(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*b.row,a.column*b.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			for (int ii=0;ii<b.row;ii++)
				for (int jj=0;jj<b.column;jj++)
				{
					//行i*b.row+ii，列j*b.column+jj
					p(i*b.row+ii,j*b.column+jj)=a(i,j)*b(ii,jj);
				}
	return p;
}

//生成零矩阵
//输入为矩阵的行数和列数，输出相应大小的零矩阵。
Matrix Matlab2c::zeros(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(n,n);
	for (i=0;i<p.row*p.column;i++)
		p(i)=0;
	return p;
}
 Matrix Matlab2c::zeros(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(row,column);
	for (i=0;i<p.row*p.column;i++)
			p(i)=0;
	return p;
}



//截取矩阵多列
//输入：原矩阵a，截取的起始列n1，终止列n2
//	输出：输出矩阵a的第n1列到n2列(包括第n2列)，原矩阵不改变
//	提示：n1，n2从1开始，即下标同matlab使用相同
Matrix Matlab2c::get_2column(Matrix& a,int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,n2-n1+1);
	for (i=0;i<p.row;i++)
		for(j=n1-1;j<n2+1;j++)
			p(i,j-n1+1)=a(i,j);
	return p;
}


//截取矩阵多行，下标同matlab使用，从1开始
//输入：原矩阵a，截取的起始行m1，终止行m2
//	输出：输出矩阵a的第m1行到m2行(包括第m2行)，原矩阵不改变
//	提示：m1，m2从1开始，即下标同matlab使用相同
Matrix Matlab2c::get_2row(Matrix& a,int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(m2-m1+1,a.column);
	for(i=m1-1;i<m2+1;i++)
		for(j=0;j<p.column;j++)
			p(i-m1+1,j)=a(i,j);
	return p;
}


//截取矩阵指定列
//输入：源矩阵a，要截取的列数n
//	输出：源矩阵a的第n列
//	提示：直接按matlab里面的下标方式调用。n从1开始
Matrix Matlab2c::get_column(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(a.row,1);
	for (i=0;i<a.row;i++)
		p.data[i]=a(i,n-1); 
	return p;
}

//截取矩阵指定行，下标同matlab，从1开始
//输入：源矩阵a，要截取的行数m
//	输出：源矩阵a的第m行
//	提示：直接按matlab里面的下标方式调用。m从1开始
Matrix Matlab2c::get_row(Matrix& a,int m)
{
	Matlab2c::CheckLicense();
	int j;
	Matrix p(1,a.column);
	for (j=0;j<a.column;j++)
		p.data[j]=a(m-1,j);
	return p;
}


//矩阵多列赋值
//输入：源矩阵yuan，要赋值的矩阵fu，要赋值的列数n1，n2
//提示：直接按matlab里面的下标方式调用。n从1开始
void Matlab2c::set_2column(Matrix& yuan,Matrix& fu, int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j;
	for (i=0;i<yuan.row;i++)
		for(j=n1;j<n2+1;j++)
			yuan(i,j)=fu(i,j-n1);
}

//指定多行赋值
//输入：源矩阵yuan，要赋值的矩阵fu，要赋值的行m1 到行m2
//提示：直接按matlab里面的下标方式调用。m从1开始
void Matlab2c::set_2row(Matrix& yuan,Matrix& fu, int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j;
	for(i=m1;i<m2+1;i++)
		for (j=0;j<yuan.column;j++)
			yuan(i,j)=fu(i-m1,j);
}


//指定列赋值
//输入：源矩阵yuan，要赋值的矩阵fu，要赋值的列数n
//	提示：直接按matlab里面的下标方式调用。n从1开始
void Matlab2c::set_column(Matrix& yuan,Matrix& fu, int n)
{
	Matlab2c::CheckLicense();
	int i;
	for (i=0;i<yuan.row;i++)
		yuan(i,n)=fu.data[i];
}


//指定行赋值
//输入：源矩阵yuan，要赋值的矩阵fu，要赋值的行数m
//	提示：直接按matlab里面的下标方式调用。m从1开始
void Matlab2c::set_row(Matrix& yuan,Matrix& fu, int m)
{
	Matlab2c::CheckLicense();
	int j;
	for (j=0;j<yuan.column;j++)
		yuan(m-1,j)=fu.data[j];
}

//删除矩阵多列
//输入：原矩阵a，要删除的列数起点n1，要删除列数终点n2，下标从1开始
//	输出：原矩阵a删除列n1到n2后的矩阵。包含删除n2列
//	提示：函数不改变原矩阵，下标同matlab，删除列包含n1，n2
Matrix Matlab2c::del_2column(Matrix& a,int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row,a.column-n2+n1-1);
	for (j=0;j<a.column;j++)
		if (j<n1-1 || j>=n2)
		{
			for (i=0;i<a.row;i++)
				p(i,d)=a(i,j);
			d++;
		}
		return p;
}


//删除矩阵多行
//输入：原矩阵a，要删除的行数起点m1，要删除行数终点m2，下标从1开始
//	输出：原矩阵a删除从m1到m2后的矩阵。删除m2行
//	提示：函数不改变原矩阵，下标同matlab，删除行包含m1，m2
Matrix Matlab2c::del_2row(Matrix& a,int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row-m2+m1-1,a.column);
	for (i=0;i<a.row;i++)
		if (i<m1-1 || i>=m2)
		{
			for (j=0;j<a.column;j++)
				p(d,j)=a(i,j);
			d++;
		}
		return p;
}


//删除矩阵指定列
//输入：原矩阵a，要删除的列数n，n取值同matlab，从1开始
//	输出：矩阵a删除第n列后新的矩阵
//	提示：函数不改变矩阵原有数据
Matrix Matlab2c::del_column(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row,a.column-1);
	for (j=0;j<a.column;j++)
		if (j!=n-1)
		{
			for (i=0;i<a.row;i++)
				p(i,d)=a(i,j);
			d++;
		}
		return p;
}



//删除矩阵指定行
//输入：原矩阵a，要删除的行数m，m取值同matlab，从1开始
//	输出：矩阵a删除第m行后新的矩阵
//	提示：函数不改变矩阵原有数据
Matrix Matlab2c::del_row(Matrix& a,int m)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row-1,a.column);
	for (i=0;i<a.row;i++)
		if (i!=m-1)
		{
			for (j=0;j<a.column;j++)
				p(d,j)=a(i,j);
			d++;
		}
		return p;
}


//同时删除矩阵指定行和指定列
//输入：原矩阵a，要同时删除的行数m，列数n
//	输出：原矩阵a删除第m行，第n列后的矩阵
//	提示：m和n下标从1开始，函数不改变原矩阵数据
Matrix Matlab2c::del_row_column(Matrix& a,int rowsnum,int columnsnum)
{
	Matlab2c::CheckLicense();
	int i=0,j;
	int rownow = rowsnum-1,columnnow = columnsnum-1;
	Matrix p(a.row-1,a.column-1);
	while(i<rownow)
	{ 
		j=0;
		while(j<columnnow)
		{
			p(i,j)=a(i,j);
			j++;
		}
		j++;
		while(j>columnnow&&j<a.column)
		{
			p(i,j)=a(i,j); 
			j++;
		}
		i++;
	}
	i++;
	while(i>rownow&&i<a.row)
	{
		j=0;
		while(j<columnnow)
		{
			p(i-1,j)=a(i,j);
			j++;
		}
		j++;
		while(j>columnnow&&j<a.column)
		{
			p(i-1,j-1)=a(i,j); 
			j++;
		}
		i++;
	}
	return p;

}


//左右合并矩阵
//输入：矩阵a,b
//	输出：矩阵a，b左右合并之后的矩阵
//	提示：函数不改变原矩阵数据
Matrix Matlab2c::left_right(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix c(a.row,a.row+a.column);
	int i,j;
	for (i=0;i<a.row;i++)
	{
		for (j=0;j<a.column;j++)
			c(i,j)=a(i,j);
		for (j=0;j<b.column;j++)
			c(i,j+a.column)=b(i,j);
	}
	return c;
}



//上下合并矩阵
//输入：矩阵a,b
//	输出：矩阵a，b上下合并之后的矩阵
//	提示：函数不改变原矩阵数据
Matrix Matlab2c::up_down(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix c(a.row+a.column,a.column);
	int i,j;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			c(i,j)=a(i,j);
	for (i=0;i<b.row;i++)
		for (j=0;j<b.column;j++)
			c(i,j+a.row*a.column)=b(i,j);
	return c;
}

//矩阵按列变维
//矩阵按列变维：输入为矩阵a，以及想要变换的维数m、n，输出为按列重排的m*n矩阵。矩阵变维，先列后行
Matrix  Matlab2c::reshape(Matrix& a,int row,int column)
{
	Matlab2c::CheckLicense();
	if (row*column<=a.row*a.column)
	{
		Matrix p(row,column);
		for (int j=0;j<p.column;j++)
			for (int i=0;i<p.row;i++)
				p(i,j)=a((j*p.row+i)%a.row,(j*p.row+i)/a.row);
		return p;
	}
	else
	{
		throw_logic_error("矩阵变维时数据不够");
		return NULL;
	}
}
CMatrix  Matlab2c::reshape(CMatrix& a,int row,int column)
{
	Matlab2c::CheckLicense();
	if (row*column<=a.row*a.column)
	{
		CMatrix p(row,column);
		for (int j=0;j<p.column;j++)
			for (int i=0;i<p.row;i++)
				p(i,j)=a((j*p.row+i)%a.row,(j*p.row+i)/a.row);
		return p;
	}
	else
	{
		throw_logic_error("矩阵变维时数据不够");
		return NULL;
	}
}
