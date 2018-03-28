#include "Matlab2c.h"
using namespace Matlab2c;


//返回按列求积后的行向量，输入为行向量，返回行积（1x1矩阵）
//输入为一个矩阵，输出为每列的乘积向量。返回一个行向量
Matrix Matlab2c::prod(Matrix& a)
{
	Matlab2c::CheckLicense();
	double prod=1;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p = Matrix(1,1);
		for (int j=0;j<a.column;j++)
			prod=prod*a.data[j];
		p.data[0] = prod;
		return p;
	}
	Matrix p = Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*(a(i,j));
		}
		p.data[j]=prod;
	}
	return p;
}
CMatrix Matlab2c::prod(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex prod=1;
	if(a.row==1)  //若数据矩阵为行向量
	{
		CMatrix p = CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			prod=prod*a.data[j];
		p.data[0] = prod;
		return p;
	}
	CMatrix p = CMatrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*(a(i,j));
		}
		p.data[j]=prod;
	}
	return p;
}

//矩阵各维度累积连乘
//返回各维度累乘积，输入为矩阵，返回按列累积连乘，输入为向量，返回按序列累积连乘结果
Matrix Matlab2c::cumprod(Matrix& a)  
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double prod=1;
	if(a.row==1)  //若数据矩阵为行向量，则按行累积
	{
		for (int j=0;j<a.column;j++)
		{
			prod=prod*a.data[j];
			p.data[j]=prod;
		}
		return p;
	}
	for(int j=0;j<a.column;j++)
	{	
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*a(i,j);
			p(i,j)=prod;
		}
	}
	return p;
}

CMatrix Matlab2c::cumprod(CMatrix& a)  
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex prod=1;
	if(a.row==1)  //若数据矩阵为行向量，则按行累积
	{
		for (int j=0;j<a.column;j++)
		{
			prod=prod*a.data[j];
			p.data[j]=prod;
		}
		return p;
	}
	for(int j=0;j<a.column;j++)
	{	
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*a(i,j);
			p(i,j)=prod;
		}
	}
	return p;
}

//计算矩阵各列的几何平均数，输入为行向量时返回行向量的几何平均数
//输入：矩阵a
//输出：矩阵a各列的几何平均数
//提示：由于计算平均是要做根号运算，所以各列相乘后的值有时要求为正数
Matrix Matlab2c::geomean(Matrix& a)
{
	Matlab2c::CheckLicense();
	double m=1;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			m = m*a.data[j];
		p.data[0]=std::pow(m,1.0/a.column);
		return p;
	}
	Matrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m = m*(a(i,j));
		p.data[j]=std::pow(m,1.0/a.row);
	}
	return p;
}

CMatrix Matlab2c::geomean(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex m=1;
	if(a.row==1)  //若数据矩阵为行向量
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			m = m*a.data[j];
		p.data[0]=std::pow(m,1.0/a.column);
		return p;
	}
	CMatrix p=CMatrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m = m*(a(i,j));
		p.data[j]=std::pow(m,1.0/a.row);
	}
	return p;
}

//计算矩阵各列的调和平均数，输入为行向量时返回行向量的调和平均数
//输入：矩阵a
//输出：矩阵a各列的调和平均数
//提示：做调和运算要求矩阵元素不能为0
Matrix Matlab2c::harmmean(Matrix& a)
{
	Matlab2c::CheckLicense();
	double m=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			m +=1.0/(a.data[j]);
		p.data[0]=(double)a.column/m;
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m +=1.0/(a(i,j));
		p.data[j]=(double)a.row/m;
	}
	return p;
}
CMatrix Matlab2c::harmmean(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex m=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			m +=1.0/(a.data[j]);
		p.data[0]=(Complex)a.column/m;
		return p;
	} 
	CMatrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m +=1.0/(a(i,j));
		p.data[j]=(Complex)a.row/m;
	}
	return p;
}

//返回按列求和后的行向量，输入为行向量时返回行和
//输入为矩阵a，输出为矩阵a按列求和后返回行向量p
Matrix Matlab2c::sum(Matrix& a)
{
	Matlab2c::CheckLicense();
	double sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			sum+=a.data[j];
		p.data[0] = sum;
		return p;
	}

	Matrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
			sum +=a(i,j);
		p.data[j]=sum;
	}
	return p;
}
CMatrix Matlab2c::sum(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			sum+=a.data[j];
		p.data[0] = sum;
		return p;
	}

	CMatrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
			sum +=a(i,j);
		p.data[j]=sum;
	}
	return p;
}


//到返回各维度顺序累加和，输入为行向量，返回累加求和
//输入：矩阵a
//输出：矩阵a各列各维度的累加值。
//提示：返回值大小与输入矩阵大小相等。
Matrix Matlab2c::cumsum(Matrix& a) 
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		for (int j=0;j<a.column;j++)
		{
			sum+=a.data[j];
			p.data[j]=sum;
		}
		return p;
	}
	for (int j=0;j<p.column;j++)
	{
		sum=0;
		for (int i=0;i<p.row;i++)
		{
			sum+=(a(i,j));
			p(i,j)=sum;
		}
	}
	return p;
}
CMatrix Matlab2c::cumsum(CMatrix& a) 
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		for (int j=0;j<a.column;j++)
		{
			sum+=a.data[j];
			p.data[j]=sum;
		}
		return p;
	}
	for (int j=0;j<p.column;j++)
	{
		sum=0;
		for (int i=0;i<p.row;i++)
		{
			sum+=(a(i,j));
			p(i,j)=sum;
		}
	}
	return p;
}