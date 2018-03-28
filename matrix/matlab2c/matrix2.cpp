#include "Matlab2c.h"
using namespace Matlab2c;

//求矩阵的秩
//输入源矩阵，返回矩阵的秩int型
int Matlab2c::rank(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j,k,nn,is,js,l,ll,u,v;
	double q,d;
	nn=a.row;
	if (a.row>=a.column) nn=a.column;
	k=0;
	for (l=0; l<=nn-1; l++)
	{ 
		q=0.0;
		for (i=l; i<=a.row-1; i++)
			for (j=l; j<=a.column-1; j++)
			{ 
				ll=i*a.column+j; d=std::fabs(a.data[ll]);
				if (d>q) 
				{ 
					q=d; is=i; js=j;
				}
			}
			if (q+1.0==1.0) return(k);
			k=k+1;
			if (is!=l)
			{ 
				for (j=l; j<=a.column-1; j++)
				{ 
					u=l*a.column+j; v=is*a.column+j;
					d=a.data[u]; a.data[u]=a.data[v]; a.data[v]=d;
				}
			}
			if (js!=l)
			{ 
				for (i=l; i<=a.row-1; i++)
				{ 
					u=i*a.column+js; v=i*a.column+l;
					d=a.data[u]; a.data[u]=a.data[v]; a.data[v]=d;
				}
			}
			ll=l*a.column+l;
			for (i=l+1; i<=a.column-1; i++)
			{ 
				d=a(i,l)/a.data[ll];
				for (j=l+1; j<=a.column-1; j++)
				{ 
					u=i*a.column+j;
					a.data[u]=a.data[u]-d*a(l,j);
				}
			}
	}
	return(k);
}
//求方阵对应行列式的值
//输入源矩阵，返回矩阵的行列式double型。可逆矩阵的行列式不为0
double Matlab2c::det(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i=0,j;
	double mo=0;
	for(j=0;j<a.column;j++)
	{
		if(a.column==1)
		{
			mo=(double)(a(i,j))*pow(-1.0,i+j+2);
			break;
		}
		Matrix c(a);
		c.remove_row_column(0,j);
		mo+=(double)a(i,j)*pow(-1.0,i+j+2)*Matlab2c::det(c);//函数递归调用
	}
	return mo;
}



//求矩阵的逆
//输入：为可逆方矩阵  输出：矩阵的逆
void swap(double *a,double *b);  //声明子程序
Matrix Matlab2c::inv(Matrix& a)
{
	Matlab2c::CheckLicense();
	if (a.row!=a.column)
	{
		throw_logic_error("求逆矩阵不为方阵");
		return NULL;
	}
	int *is,*js,i,j,k;
	int n=a.row;
	double temp,fmax;
	Matrix p(a.row,a.column);
	for(i=0;i<n;i++)
	{ 
		for(j=0;j<n;j++)
			p(i,j)=a(i,j);
	}
	is=new int[n];
	js=new int[n];
	for(k=0;k<n;k++)
	{
		fmax=0.0;
		for(i=k;i<n;i++)
			for(j=k;j<n;j++)
			{ 
				temp=std::fabs(p(i,j));//找最大值
				if(temp>fmax)
				{ 
					fmax=temp;
					is[k]=i;js[k]=j;
				}
			}
			if((fmax+1.0)==1.0)
			{  
				delete[] is;
				delete[] js;
				throw_logic_error("不存在逆矩阵");
				return NULL;
			}
			if((i=is[k])!=k)
				for(j=0;j<n;j++)
					swap(p.data+k*n+j,p.data+i*n+j);//交换指针
			if((j=js[k])!=k)
				for(i=0;i<n;i++)
					swap(p.data+i*n+k,p.data+i*n+j);  //交换指针
			p(k,k)=1.0/p(k,k);
			for(j=0;j<n;j++)
				if(j!=k)
					p(k,j)*=p(k,k);
			for(i=0;i<n;i++)
				if(i!=k)
					for(j=0;j<n;j++)
						if(j!=k)
							p(i,j)=p(i,j)-p(i,k)*p(k,j);
			for(i=0;i<n;i++)
				if(i!=k)
					p(i,k)*=-p(k,k);
	}
	for(k=n-1;k>=0;k--)
	{
		if((j=js[k])!=k)
			for(i=0;i<n;i++)
				swap((p.data+j*n+i),(p.data+k*n+i));
		if((i=is[k])!=k)
			for(j=0;j<n;j++)
				swap((p.data+j*n+i),(p.data+j*n+k));
	}
	delete[] is;
	delete[] js;
	return p;
}
void swap(double *a,double *b)
{  
	double c;
	c=*a;
	*a=*b;
	*b=c;
}


//求矩阵的迹
//输入为一个方阵，输出为该方阵的迹(主对角元素的和)。
double Matlab2c::trace(Matrix& a)
{
	Matlab2c::CheckLicense();
	if (a.row!=a.column)
	{
		throw_logic_error ("求迹矩阵不是方阵");
		return 0;
	}
	double sum=0;
	for (int i=0;i<a.row;i++)
		sum+=a(i,i);
	return sum;
}

//计算向量长度
int Matlab2c::length(Matrix& a)
{
	Matlab2c::CheckLicense();
	return a.row*a.column;
}

//计算矩阵行列数目
int* Matlab2c::size(Matrix& a)
{
	Matlab2c::CheckLicense();
	int* size=new int[2];
	size[0]=a.row;
	size[1]=a.column;
	return size;
}