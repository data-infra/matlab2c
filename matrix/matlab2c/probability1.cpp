#include "Matlab2c.h"
using namespace Matlab2c;




//二项分布的密度函数值
//输入：事件发生K次(行向量形式)；n—试验总次数；p每次试验事件发生的概率；
//输出：事件发生K次的概率密度
//提示：函数不改变矩阵原有数据
Matrix Matlab2c::binopdf (Matrix& k, int n,double p)
{
	Matlab2c::CheckLicense();
	Matrix c(k.row,k.column);
	for (int i=0;i<c.row;i++)
		for (int j=0;j<c.column;j++)
			c(i,j) = (double)Matlab2c::nchoosek(n,k(i,j))*(double)(pow(p,k(i,j))*pow((1-p),(n-k(i,j))));
	return c;
}


//生成二项分布随机矩阵
//输入为二项分布的参数n和p，以及矩阵的行数和列数
//输出为二项分布随机矩阵
Matrix Matlab2c::binornd(int n,double p,int row,int column)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix c(row,column);
	int x=-1;
	double dScope;
	double *g = new double[n+1];
	double max=0;
	srand((unsigned)time(0));
	for (i=0;i<n+1;i++)
	{
		g[i]=(double)Matlab2c::nchoosek(n,i)*(double)(pow(p,i)*pow((1-p),(n-i)));//获取所可能概率密度
		if (max<g[i])
			max=g[i];
	}
	for (i=0;i<c.row;i++)
		for (j=0;j<c.column;j++)
		{
			x=-1;
			while (x<0 || x>n)
				x = (int)((double)std::rand()/RAND_MAX*n);
			do
			{
				dScope = ((double)std::rand()/RAND_MAX)*max;
			}while( dScope > g[x]);   //满足的次数就反应了概率密度
			c(i,j)=x;
		}	
		return c;
}

//二项分布的期望方差
//输入：n—试验总次数；p每次试验事件发生的概率
//输出：二项分布的期望与方差
Matrix* Matlab2c::binostat (Matrix& n,Matrix& p) 
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(n.row,n.column),varMatrix(p.row,p.column);
	Matrix *back=new Matrix[2];
	for (int i=0;i<n.row;i++)
		for (int j=0;j<n.column;j++)
		{
			averMatrix(i,j) =n(i,j)*(p(i,j));
			varMatrix(i,j) = n(i,j)*(p(i,j))*(1-p(i,j));
		}
	back[0]=averMatrix;
	back[1]=varMatrix;
	return back;
}

//生成指数分布的随机矩阵
//输入为行数列数，指数分布的参数mu
//输出随机矩阵
Matrix Matlab2c::exprnd(double mu,int row ,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//如果用这个默认的引擎，每次生成的随机序列是相同的。
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			exponential_distribution<double> exponential(mu);
			p(i,j)=exponential(gen);
		}
	}

	return p;
}


//指数分布函概率值
//输入：欲求pdf的点向量，指数分布的参数lambda
//输出：相应的pdf值
Matrix Matlab2c::exppdf(Matrix& a,double mu)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(a(i,j)>=0)
				p(i,j) = (double)(mu*std::exp(-mu*a(i,j)));
			else
				p(i,j) =0;
	return p;
}

//求指数分布的均值和方差
//输入指数分布的参数mu，以1/Lambda为输入参数
//输出指数分布的期望和方差
Matrix* Matlab2c::expstat(Matrix& mu)
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(mu),varMatrix(mu.row,mu.column);
	Matrix *p = new Matrix[2];
	for (int i=0;i<mu.row*mu.column;i++)
		varMatrix(i)=mu(i)*mu(i);
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}



//求一个数组不同维度的最大值
//输入为一个向量时，输出为一个1x1的矩阵
//输入为一个矩阵，输出为每列最大值向量。
//dim=1（默认）按列求最大值，dim=2按行求最大值
Matrix Matlab2c::max(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double maxitem=DBL_MIN;
		for (int i=0;i<a.row*a.column;i++)
			if(maxitem<a(i))
				maxitem=a(i);
		p.data[0]=maxitem;
		return p;
	}
	else
	{
		if (dim==1)
		{
			Matrix p(1,a.column);
			double maxitem=DBL_MIN;
			for (int j=0;j<a.column;j++)
			{
				maxitem=DBL_MIN;
				for (int i=0;i<a.row;i++)
					if(maxitem<a(i,j))
						maxitem=a(i,j);
				p.data[j]=maxitem;
			}
			return p;
		}else{
			Matrix p(a.row,1);
			double maxitem=DBL_MIN;
			for (int i=0;i<a.row;i++)
			{
				maxitem=DBL_MIN;
				for (int j=0;j<a.column;j++)
					if(maxitem<a(i,j))
						maxitem=a(i,j);
				p.data[i]=maxitem;
			}
			return p;
		}
		
	}
}
//求一个数组不同维度的最小值
//输入为一个向量时，输出为一个1x1的矩阵
//输入为一个矩阵，输出为每列最小值向量。
//dim=1（默认）按列求最小值，dim=2按行求最小值
Matrix Matlab2c::min(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double minitem=DBL_MAX;
		for (int i=0;i<a.row*a.column;i++)
			if(minitem>a(i))
				minitem=a(i);
		p.data[0]=minitem;
		return p;
	}
	else
	{
		if(dim==1)
		{
			Matrix p(1,a.column);
			int i,j;
			double minitem=DBL_MAX;
			for (j=0;j<a.column;j++)
			{
				minitem=DBL_MAX;
				for (i=0;i<a.row;i++)
					if(minitem>a(i,j))
						minitem=a(i,j);
				p.data[j]=minitem;
			}
			return p;
		}
		else
		{
			Matrix p(a.row,1);
			double minitem=DBL_MAX;
			for (int i=0;i<a.row;i++)
			{
				minitem=DBL_MAX;
				for (int j=0;j<a.column;j++)
					if(minitem>a(i,j))
						minitem=a(i,j);
				p.data[i]=minitem;
			}
			return p;
		}
		
	}
}
//均值向量，返回列求均值后的行向量
//输入为一个矩阵，输出为每列的均值向量。
//输入为一个向量，输出为1x1的均值
//dim=1（默认）按列求均值，dim=2按行求均值
Matrix Matlab2c::mean(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double sum=0;
		for (int i=0;i<a.row*a.column;i++)
				sum +=a(i);
		p.data[0]=sum/(a.row*a.column);
		return p;
	}
	else
	{
		if (dim==1)
		{
			Matrix p(1,a.column);
			int i,j;
			double sum=0;
			for (j=0;j<a.column;j++)
			{
				sum=0;
				for (i=0;i<a.row;i++)
					sum +=a(i,j);
				p.data[j]=sum/a.row;
			}
			return p;
		}else
		{
			Matrix p(a.row,1);
			double sum=0;
			for (int i=0;i<a.row;i++)
			{
				sum=0;
				for (int j=0;j<a.column;j++)
					sum +=a(i,j);
				p.data[i]=sum/a.column;
			}
			return p;
		}
		
	}
}


//返回各列中位数组成的行向量，
//输入为行向量，返回输入的中位数
//输入为一个矩阵，输出为每列的中位数向量。
//dim=1（默认）按列求中位数，dim=2按行求中位数
Matrix Matlab2c::median(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	int lp=0;
	Matrix c = Matlab2c::sort(a,dim);   //对没一列或每一行按升序排序
	Matrix p;
	
	if(a.isVector())  //若数据矩阵为向量
	{
		p=Matrix(1,1);
		if ((a.row*a.column)%2==1)
			p.data[0]=c.data[(a.row*a.column/2)];
		else
			p.data[0]=0.5*(c.data[(a.row*a.column/2)])+0.5*(c.data[(a.row*a.column/2-1)]);
		return p;
	}
	if (dim==1)
	{
		p=Matrix(1,a.column);
		if (a.row%2==1)
			for (int j=0;j<p.column;j++)
				p.data[j]=c(a.row/2,j);
		else
			for (int j=0;j<p.column;j++)
				p.data[j]=0.5*c(a.row/2,j)+0.5*c(a.row/2-1,j);
		return p;
	}else
	{
		p=Matrix(a.row,1);
		if (a.column%2==1)
			for (int i=0;i<p.row;i++)
				p.data[i]=c(i,a.column/2);
		else
			for (int i=0;i<p.row;i++)
				p.data[i]=0.5*c(i,a.column/2)+0.5*c(i,a.column/2-1);
		return p;
	}
}



//正态分布的概率值　
//输入：要求概率密度的点矩阵；aver—均值；sigma—标准差
//输出矩阵点上的概率密度值
Matrix Matlab2c::normpdf(Matrix& a,double aver,double sigma)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
			p(i,j) = (double)(1.0/(std::sqrt(2*3.141592)*sigma)*std::exp(-(a(i,j)-aver)*(a(i,j)-aver)/(2*sigma*sigma)));
	return p;
}
//求正态分布的均值和方差
//输入正态分布的均值和标准差
//输出正态分布的均值和方差
Matrix* Matlab2c::normstat(Matrix& aver,Matrix& sigma)
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(aver),varMatrix(aver.row,aver.column);
	Matrix *p = new Matrix[2];
	for (int i=0;i<sigma.row*sigma.column;i++)
		varMatrix(i)=sigma(i)*sigma(i);
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}





//生成正态分布的随机矩阵
//输入为行数列数，正态分布的均值和标准差
//输出正态分布矩阵
Matrix Matlab2c::normrnd(double aver,double sigma,int row,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//如果用这个默认的引擎，每次生成的随机序列是相同的。
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			normal_distribution<double> normal(aver,sigma);
			p(i,j)=normal(gen);
		}
	}

	return p;
}


//求泊松分布的概率值　
//输入:欲求pdf的点向量，及poisson参数lambda
//输出:pdf值
Matrix Matlab2c::poisspdf(Matrix& a,double Lambda)
{
	Matlab2c::CheckLicense();
	double e =2.718282;
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = (double)(pow(e,-Lambda)*pow(Lambda,a(i,j))/Matlab2c::factorial((int)(a(i,j))));
	return p;
}


//计算矩阵各列的数值范围，输入为行向量时，返回行的取值范围
//输入：矩阵a
//输出：矩阵a各列的最大值与最小值的差
Matrix Matlab2c::range(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	double maxdata=0;
	double mindata=0;
	Matrix p;
	if(a.row==1)  //若数据矩阵为行向量
	{
		p=Matrix(1,1);
		maxdata = a.data[0];
		mindata = a.data[0];
		for (j=0;j<a.column;j++)
		{
			if (maxdata<a.data[j])
				maxdata = a.data[j];
			if (mindata>a.data[j])
				mindata = a.data[j];
		}
		p.data[0]=maxdata-mindata;
		return p;
	}
	p=Matrix(1,a.column);
	for (j=0;j<a.column;j++)
	{
		maxdata = a(0,j);
		mindata = a(0,j);
		for (i=0;i<a.row;i++)
		{
			if (maxdata<a(i,j))
				maxdata = a(i,j);
			if (mindata>a(i,j))
				mindata = a(i,j);
		}
		p.data[j]=maxdata-mindata;
	}
	return p;
}


//求瑞利分布概率值
//输入：欲求pdf的点向量，瑞丽分布的参数sigma
Matrix Matlab2c::raylpdf(Matrix& a,double sigma)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(a(i,j)>=0)
				p(i,j) = (double)(a(i,j)/(sigma*sigma)*std::exp(-(a(i,j))*(a(i,j))/(2*sigma*sigma)));
			else
				p(i,j) =0;
	return p;
}


//返回按列标准差向量，输入为行向量时，返回行向量的标准差
//输入为一个矩阵，输出为每列的标准差向量。
//实现的是matlab中 std(X,1) 函数
Matrix Matlab2c::std(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix m=mean(a);
	double sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			sum +=(a(j)-m(0))*(a(j)-m(0));
		p(0)=std::sqrt(sum/a.column);
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
		{
			sum +=(a(i,j)-m(j))*(a(i,j)-m(j));
		}
		p.data[j]=std::sqrt(sum/a.row);
	}
	return p;
}



//均匀分布（连续）的期望和方差
//输入：均匀分布的上界和下届
//输出：均匀分布的均值和方差
Matrix* Matlab2c::unifstat(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if(a.row!=b.row || a.column!=b.column)
	{
		throw_logic_error("均匀分布上下限矩阵不匹配");
		return NULL;
	}
	Matrix averMatrix(a.row,a.column),varMatrix(a.row,a.column);
	Matrix *p = new Matrix[2];

	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
		{
			averMatrix(i,j)=0.5*(a(i,j))+0.5*(b(i,j));
			varMatrix(i,j)=pow((a(i,j))-(b(i,j)),2)/12;
		}
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}




//返回按列方差向量，输入为行向量时，返回行向量的方差
//输入为一个矩阵，输出为每列的方差向量。
//实现的为matlab中D=var(X, 1) 函数
Matrix Matlab2c::var(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix m = Matlab2c::mean(a);
	double sum=0;
	if(a.row==1)  //若数据矩阵为行向量
	{
		Matrix p(1,1);
		for (int j=0;j<a.column;j++)
			sum +=(a(j)-m(0))*(a(j)-m(0));
		p(0) = sum/a.column;
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
		{
			sum +=(a(i,j)-m(j))*(a(i,j)-m(j));
		}
		p(j)=sum/a.row;
	}
	return p;
}


//韦伯分布概率值
//输入:韦伯分布的参数k、lambda
//输出:概率值
Matrix Matlab2c::weibpdf(Matrix& a,double k,double lambda)
{
	Matlab2c::CheckLicense();
	double e =2.718282;
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if (a(i,j)>=0)
				p(i,j) = (double)(k/lambda*std::pow(a(i,j)/lambda,k-1)*std::exp(std::pow(-(a(i,j)/lambda),k)));
			else
				p(i,j)=0;
	return p;
}



//生成均匀分布的随机矩阵
//输入为行数列数，以及均匀分布的下边界（默认为0）和上边界（默认为1）
//输出均匀分布矩阵
Matrix Matlab2c::rand(int row,int column,double min,double max)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(row,column);
	double temp;
	srand((unsigned)time(NULL));
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
		{
			temp = (double)std::rand()/RAND_MAX*(max-min)+min;
			p(i,j)=temp ;
		}	
		return p;
}




//生成标准正态分布矩阵
//输入为行数列数
//输出为标准正态分布矩阵
Matrix Matlab2c::randn(int row ,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//如果用这个默认的引擎，每次生成的随机序列是相同的。
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			//normal(0,1)中0为均值，1为方差
			normal_distribution<double> normal(0,1);
			p(i,j)=normal(gen);
		}
	}
	return p;
}


//生成均匀分布整型随机矩阵
//输入：矩阵要求行数列数，分布区间，下边界默认为0，上边界默认为1
//输出：随机整形矩阵
Matrix Matlab2c::randind(int row,int column,int min,int max)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	double temp;
	srand((unsigned)time(NULL));
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
		{
			temp = (double)std::rand()/RAND_MAX*(max-min+1)+min-0.5;
			p(i,j)=(int)(temp+0.5);  //4舍5入
		}	
		return p;
}


