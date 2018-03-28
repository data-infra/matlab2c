#include "Matlab2c.h"
using namespace Matlab2c;


//矩阵对角线元素的抽取和根据对角元素生成矩阵
//X = diag(v,k)当v是一个含有n个元素的向量时，返回一个n+abs(k)阶方阵X，向量v在矩阵X中的第k个对角线上，k=0表示主对角线，k>0表示在主对角线上方，k<0表示在主对角线下方。
//v = diag(X,k)返回列向量v，v由矩阵X的第k个对角线上的元素形成
Matrix Matlab2c::diag(Matrix& a,int n)
{ 
	Matlab2c::CheckLicense();
	Matrix p;
	int p_row;
	int index=0;
	//根据向量生成矩阵
	if (a.isVector())
	{
		p_row =a.row*a.column+std::abs(n);
		p=Matrix(p_row,p_row);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
				if (j-i==n)
					p(i,j)=a(index++);
				else
					p(i,j)=0;
		return p;
	}
	//根据矩阵提取对角元素
	else
	{
		p.column =1;
		if (n>0)
			p.row=std::min(a.column-n,a.row);
		else
			p.row=std::min(a.column,a.row+n);
		p.data=new double[p.row*p.column];
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if (j-i==n)
					p(index++) = a(i,j);	
		return p;
	}
}
Matrix Matlab2c::diag(Matrix& a)
{ 
	Matlab2c::CheckLicense();
	return diag(a,0);
}
CMatrix Matlab2c::diag(CMatrix& a,int n)
{ 
	Matlab2c::CheckLicense();
	CMatrix p;
	int p_row;
	int index=0;
	//根据向量生成矩阵
	if (a.isVector())
	{
		p_row =a.row*a.column+std::abs(n);
		p=CMatrix(p_row,p_row);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
				if (j-i==n)
					p(i,j)=a(index++);
				else
					p(i,j)=0;
		return p;
	}
	//根据矩阵提取对角元素
	else
	{
		p.column =1;
		if (n>0)
			p.row=std::min(a.column-n,a.row);
		else
			p.row=std::min(a.column,a.row+n);
		p.data=new Complex[p.row*p.column];
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if (j-i==n)
					p(index++) = a(i,j);	
		return p;
	}
}
CMatrix Matlab2c::diag(CMatrix& a)
{ 
	Matlab2c::CheckLicense();
	return diag(a,0);
}
//矩阵左右翻转
//矩阵左右翻转：输入为一个矩阵，输出为该矩阵左右翻转后的矩阵。
//如果A是一个行向量，fliplr(A)将A中元素的顺序进行翻转。 如果A是一个列向量，fliplr(A)还等于A。
Matrix Matlab2c::fliplr(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double temp;
	for (int i=0;i<p.row;i++)
		for (int j=0;j<(p.column-1)/2+1;j++)
		{
			temp = a(i,j);
			p(i,j) = a(i,a.column-j-1);
			p(i,p.column-j-1) = temp;
		}
	return p;
}
CMatrix Matlab2c::fliplr(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex temp;
	for (int i=0;i<p.row;i++)
		for (int j=0;j<(p.column-1)/2+1;j++)
		{
			temp = a(i,j);
			p(i,j) = a(i,a.column-j-1);
			p(i,p.column-j-1) = temp;
		}
		return p;
}

//矩阵上下翻转
//矩阵上下翻转：输入为一个矩阵，输出为该矩阵上下翻转后的矩阵，若A为列向量，则B为倒叙A，若A为行向量，则B等于A
Matrix Matlab2c::flipud(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double temp;
	for (int i=0;i<(p.row-1)/2+1;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			temp = a(i,j);
			p(i,j) = a(a.row-1-i,j);
			p(p.row-1-i,j) = temp;
		}
	}
	return p;
}
CMatrix Matlab2c::flipud(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex temp;
	for (int i=0;i<(p.row-1)/2+1;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			temp = a(i,j);
			p(i,j) = a(a.row-1-i,j);
			p(p.row-1-i,j) = temp;
		}
	}
	return p;
}






//复制和平铺矩阵
//复制和平铺矩阵：输入为一个矩阵a，以及两个整数m、n，输出以a为元素的m*n的组合矩阵。
Matrix Matlab2c::repmat(Matrix& a,int m,int n)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*m,a.column*n);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=a(i%a.row,j%a.column);
	return p;
}
CMatrix Matlab2c::repmat(CMatrix& a,int m,int n)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row*m,a.column*n);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=a(i%a.row,j%a.column);
	return p;
}


//矩阵逆时针旋转
//矩阵逆时针旋转：输入为一个矩阵及旋转角度（0不旋转，1逆时针旋转90度，2逆时针旋转180度，3逆时针旋转270度）。
Matrix Matlab2c::rot90(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p;
	if (n%4==0)
	{
		p=a;
		return p;
	}
	else if (n%4==1)
	{
		p=Matrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-j,i) = a(i,j);
	}
	else if (n%4==2)
	{
		p=Matrix(a.row,a.column);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-i,p.column-1-j) = a(i,j);
	}
	else if (n%4==3)
	{
		p=Matrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(j,p.column-1-i) = a(i,j);
	}
	return p;
}
Matrix Matlab2c::rot90(Matrix& a)
{
	Matlab2c::CheckLicense();
	return rot90(a,1);
}
CMatrix Matlab2c::rot90(CMatrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	CMatrix p;
	if (n%4==0)
	{
		p=a;
		return p;
	}
	else if (n%4==1)
	{
		p=CMatrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-j,i) = a(i,j);
	}
	else if (n%4==2)
	{
		p=CMatrix(a.row,a.column);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-i,p.column-1-j) = a(i,j);
	}
	else if (n%4==3)
	{
		p=CMatrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(j,p.column-1-i) = a(i,j);
	}
	return p;
}
CMatrix Matlab2c::rot90(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return rot90(a,1);
}

//提取矩阵下三角
//输入为一个矩阵，输出为该矩阵的下三角矩阵，包含对角元素，可以不是方阵
Matrix Matlab2c::tril(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i>=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}
CMatrix Matlab2c::tril(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i>=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}


//提取矩阵上三角
//输入为一个矩阵，输出为该矩阵的上三角矩阵，包含对角元素，可以不是方阵
Matrix Matlab2c::triu(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i<=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}
CMatrix Matlab2c::triu(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i<=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}

//矩阵合并
//目前支持两维合并，dim=1，矩阵横向合并等价于[a,b]，dim=2矩阵纵向合并等价于[a;b]
Matrix Matlab2c::cat(int dim,Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a);
	switch (dim)
	{
	case 1:
		p.append_bottom(b);
		return p;
	case 2:
		p.append_right(b);
		return p;
	default:
		p.append_bottom(b);
		return p;
	}
}
CMatrix Matlab2c::cat(int dim,CMatrix& a,CMatrix& b)
{
	Matlab2c::CheckLicense();
	CMatrix p(a);
	switch (dim)
	{
	case 1:
		p.append_bottom(b);
		return p;
	case 2:
		p.append_right(b);
		return p;
	default:
		p.append_bottom(b);
		return p;
	}
}