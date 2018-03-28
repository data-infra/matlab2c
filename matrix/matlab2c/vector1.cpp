#include "Matlab2c.h"
using namespace Matlab2c;

//快速排序法
//输入：要排序的数据指针，数据的个数num
//	输出：从小大小排序后的数据指针。
//	提示：函数改变原数据
void Matlab2c::Q_sort(Matrix& a)  //改变原有数据
{
	Matlab2c::CheckLicense();
	Q_sort(a.data,a.row*a.column);
}
void Matlab2c::Q_sort(double *a,int num)  //改变原有数据
{
	Matlab2c::CheckLicense();
	int i=0;
	int j=num-1;
	double key=*a;
	if (num>1)
	{
		while(i!=j)
		{
			for (;i<j;j--)
				if (*(a+j)<key)
				{
					*(a+i)=*(a+j);
					break;
				}
				for (;i<j;i++)
					if (*(a+i)>key)
					{
						*(a+j)=*(a+i);
						break;
					}
					*(a+i)=key;
		}
		Q_sort(a,i);
		Q_sort(a+i+1,num-i-1);
	}
}


//选择排序法
//输入：向量
//	输出：排序后的向量，升序
//	提示：函数改变原函数
void Matlab2c::C_sort(Matrix& a)   //改变原有数据
{
	Matlab2c::CheckLicense();
	int i,j,k;
	double temp; 
	int n=a.row*a.column;
	for(i=0;i<n-1;i++) 
	{ 
		k=i;                                       //给记号赋值
		for(j=i+1;j<n;j++) 
			if(a.data[k]>a.data[j]) 
				k=j;                               //是k总是指向最小元素
		if(i!=k) 
		{                                          //当k!=i是才交换，否则a[i]即为最小
			temp=a.data[i]; 
			a.data[i]=a.data[k]; 
			a.data[k]=temp; 
		} 
	} 
}
//排序函数
//对每一列按升序排序
Matrix Matlab2c::sort(Matrix& a)   
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int j=0;j<a.column;j++)
	{
		vector<double> lie(a.row);
		for (int i=0;i<a.row;i++)
			lie[i]=a(i,j);
		std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
		for (int i=0;i<p.row;i++)
			p(i,j)=lie[i];	
	}
	return p;
}
//对每一列或每一行按升序排序，不改变源矩阵
Matrix Matlab2c::sort(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	if (dim==1)
	{
		for (int j=0;j<a.column;j++)
		{
				vector<double> lie(a.row);
				for (int i=0;i<a.row;i++)
					lie[i]=a(i,j);

				std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[i];	
		}
	}
	else if(dim==2){
		for (int i=0;i<a.row;i++)
		{
			vector<double> lie(a.column);
			for (int j=0;j<a.column;j++)
				lie[j]=a(i,j);

			std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
			for (int j=0;j<p.column;j++)
				p(i,j)=lie[j];	
		}
	}
	return p;
}
//对每一列按升序排序或按降序排序
Matrix Matlab2c::sort(Matrix& a,string mode)
{
	Matlab2c::CheckLicense();
	string mode1;
	transform(mode.begin(),mode.end(),back_inserter(mode1),::tolower);
	Matrix p(a.row,a.column);
	for (int j=0;j<a.column;j++)
	{
		vector<double> lie(a.row);
		for (int i=0;i<a.row;i++)
			lie[i]=a(i,j);

		std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
		if(mode1=="ascend")
			for (int i=0;i<p.row;i++)
				p(i,j)=lie[i];	
		else if(mode1=="descend")
			for (int i=0;i<p.row;i++)
				p(i,j)=lie[p.row-i-1];	
	}
	return p;
}
//对每一列或每一行按升序排序或按降序排序
Matrix Matlab2c::sort(Matrix& a,int dim,string mode)
{
	Matlab2c::CheckLicense();
	string mode1;
	transform(mode.begin(),mode.end(),back_inserter(mode1),::tolower);
	Matrix p(a.row,a.column);
	if (dim==1)
	{
		for (int j=0;j<a.column;j++)
		{
			vector<double> lie(a.row);
			for (int i=0;i<a.row;i++)
				lie[i]=a(i,j);

			std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
			if(mode1=="ascend")
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[i];	
			else if(mode1=="descend")
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[p.row-i-1];	
		}
	}
	else if(dim==2){
		for (int i=0;i<a.row;i++)
		{
			vector<double> lie(a.column);
			for (int j=0;j<a.column;j++)
				lie[j]=a(i,j);

			std::sort(begin(lie),end(lie));	  //对vector调用系统排序进行排序
			if(mode1=="ascend")
				for (int j=0;j<p.column;j++)
					p(i,j)=lie[j];	
			else if(mode1=="descend")
				for (int j=0;j<p.column;j++)
					p(i,j)=lie[p.column-j-1];	
		}
	}
	return p;
}

//按行方式排序
//A为矩阵，返回矩阵Y，Y按A的第1列由小到大，以行方式排序后生成的矩阵。
//按指定列col由小到大进行排序,col默认为0
Matrix Matlab2c::sortrows(Matrix& a,int col)
{
	Matlab2c::CheckLicense();
	Matrix sorttemp=a(0,a.row-1,col,col);
	sorttemp = Matlab2c::sort(sorttemp);
	Matrix flag(a.row,1,0.0);  //记录当前行是否已被占用
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)   //排序列排序前的遍历
		for(int ii=0;ii<sorttemp.row;ii++)   //排序列排序后的遍历
			if (a(i,col)==sorttemp(ii) && flag(ii)==0)
			{
				flag(ii)=1;
				for (int t = 0; t < a.column; t++)
					p(ii,t)=a(i,t);   //将第i行布置到第ii行
				break;
			}
	return p;
}


//向量的离散卷积，相关运算，多项式乘法
//输入：两个向量，或者多项式，输出结果方向根据后面向量的方向
//输出：向量离散卷积，或者相关运算，或者多项式乘法的结果
Matrix Matlab2c::conv(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if(!(a.isVector() && b.isVector()))
		throw_logic_error("输入参数必须为向量");
	int i,k;
	double m;
	Matrix p;
	if (b.row==1)
	{
		p.row=1;
		p.column = a.row*a.column+b.row*b.column-1;
	}else{
		p.column=1;
		p.row = a.row*a.column+b.row*b.column-1;
	}

	p.data = new double[p.row*p.column];
	for (k=0;k<p.row*p.column;k++)
	{
		m=0;
		for (i=0;i<a.row*a.column;i++)
			if ((k-i)>-1 && (k-i)<b.row*b.column)
				m+=(a.data[i])*(b.data[k-i]);
		p.data[k]=m;
	}
	return p;
}
CMatrix Matlab2c::conv(CMatrix& a,CMatrix& b)
{
	Matlab2c::CheckLicense();
	if(!(a.isVector() && b.isVector()))
		throw_logic_error("输入参数必须为向量");
	int i,k;
	Complex m;
	CMatrix p;
	if (b.row==1)
	{
		p.row=1;
		p.column = a.row*a.column+b.row*b.column-1;
	}else{
		p.column=1;
		p.row = a.row*a.column+b.row*b.column-1;
	}

	p.data = new Complex[p.row*p.column];
	for (k=0;k<p.row*p.column;k++)
	{
		m=0;
		for (i=0;i<a.row*a.column;i++)
			if ((k-i)>-1 && (k-i)<b.row*b.column)
				m+=(a.data[i])*(b.data[k-i]);
		p.data[k]=m;
	}
	return p;
}


int nowcan;
Matrix nowzhen;
//向量全排列子函数
void perm(double* data, int n, int curr)
{
	Matlab2c::CheckLicense();
	int i;
	double t;
	if (curr==n-1)
	{
		for (i= 0; i < n; ++i)
			*(nowzhen.data+nowzhen.column*nowcan+i) = data[i];	
		nowcan++;
	}
	else
	{
		for (i = curr; i < n; ++i)
		{
			t = data[curr], data[curr] = data[i], data[i] = t;
			perm(data, n, curr+1);
			t = data[curr], data[curr] = data[i], data[i] = t;
		}
	}
}
//矩阵所有元素的全排列主函数，不区分相同元素，只记录位置
//输入：需要排序的列向量或者行向量
//	输出：向量元素的全排列
//	提示：函数不区分相同元素。函数不改变原函数数据。 N!行、 N列
Matrix Matlab2c::perms(Matrix& a)
{
	Matlab2c::CheckLicense();
	nowcan =0;
	nowzhen.row =Matlab2c::factorial(a.row*a.column);
	nowzhen.column = a.column*a.row;
	nowzhen.data = new double[nowzhen.row*nowzhen.column];
	perm(a.data, a.column*a.row, 0);
	return nowzhen;
}







//矩阵循环移位
//输入：矩阵a，要以移动的维度
//输出：移位后的矩阵
//downshift>0，下移，downshift<0上移，rightshift>0右移 rightshift<0左移
Matrix Matlab2c::circshift(Matrix& a,int downshift)  //n为正顺时针，n为负时针
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //两次%一定能化成正数余数
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
			p(newrow,j) = a(i,j);
	}
	return p;
}
Matrix Matlab2c::circshift(Matrix& a,int downshift,int rightshift) 
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //两次%一定能化成正数余数
	rightshift = ((rightshift%a.column)+a.column)%a.column;   //两次%一定能化成正数余数
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)//先行变
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
		{
			int newcolumn=(j+rightshift)%a.column;
			p(newrow,newcolumn) = a(i,j);
		}
	}
	return p;
}
CMatrix Matlab2c::circshift(CMatrix& a,int downshift)  //n为正顺时针，n为负时针
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //两次%一定能化成正数余数
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
			p(newrow,j) = a(i,j);
	}
	return p;
}
CMatrix Matlab2c::circshift(CMatrix& a,int downshift,int rightshift) 
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //两次%一定能化成正数余数
	rightshift = ((rightshift%a.column)+a.column)%a.column;   //两次%一定能化成正数余数
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)//先行变
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
		{
			int newcolumn=(j+rightshift)%a.column;
			p(newrow,newcolumn) = a(i,j);
		}
	}
	return p;
}
//查找元素位置
//输入：输入为向量或矩阵，查找数字m
//输出：m在向量或矩阵中的位置
//提示：当输入为向量时，输出为列向量，位置下标从0开始，
//当输入为矩阵时，输出为矩阵，第1列为元素所在行，第二列为元素所在列，第三列为元素值。
Matrix Matlab2c::find(Matrix& a,double m)  
{
	Matlab2c::CheckLicense();
	//如果是向量
	if (a.isVector())
	{
		vector<int> location;
		for (int i=0;i<a.row*a.column;i++)
			if(a(i)!=m)
				location.push_back(i);
		Matrix p(location.size(),1);
		for (int i=0;i<p.row;i++)
			p(i)=location[i];
		return p;
	}
	//如果是矩阵
	else
	{
		vector<int> x,y;
		vector<double> value;
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if(a(i)!=m)
				{
					x.push_back(i);
					y.push_back(j);
					value.push_back(a(i,j));
				}
		Matrix p(x.size(),3);
		for (int i=0;i<p.row;i++)
		{ 
			p(i,0)=x[i];
			p(i,1)=y[i];
			p(i,2)=value[i];
		}
		return p;
	}
}
Matrix Matlab2c::find(Matrix& a) 
{
	Matlab2c::CheckLicense();
	return find(a,0);
}


//根据位置，返回元素列向量
//输入：数据序列a，位置序列weizhi
//	输出：数据序列相应位置上的元素值
//	提示：位置下标从1开始。
//Matrix Matlab2c::getdata(Matrix& a,Matrix& weizhi)
//{
//	int i;
//	Matrix p(weizhi.row*weizhi.column,1);
//	for (i=0;i<p.row;i++)
//		p.data[i]=a.data[(int)(*(weizhi.data+i))-1];
//	return p;
//}


//返回各区间的数目多少,返回列向量
//输入：数据序列a，边界序列edg
//输出：数据序列a中的元素在edg序列各区间上的个数的多少
//提示：区间为左闭右开,返回列向量
Matrix Matlab2c::histc(Matrix& a,Matrix& edg)    //两个向量
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(edg.row*edg.column,1);
	for (i=0;i<p.row;i++)
		p.data[i]=0;
	for (i=0;i<a.row*a.column;i++)
		for (j=edg.row*edg.column-1;j>-1;j--)
			if((a.data[i])>=(edg.data[j]))
			{
				(p.data[j])++;  //大于等于小区间下边界，小于小区间上边界的数据的个数.最后一个存储等于最后一个值的个数
				break;
			}
			return p;
}


//将符号序列化为1,0，-1,
//输入为矩阵a，输出矩阵a的各个元素的符号值。
//即若元素大于0，则返回1；等于0，返回0；小于0，返回-1
Matrix Matlab2c::sign(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if (a(i,j)>0)
				p(i,j)=1;
			else if(a(i,j)<0)
				p(i,j)=-1;
			else
				p(i,j)=0;
	return p;
}


//在向量的首位添加数据x
//输入：向量a,要添加的数据x
//	输出：在向量a的最前面添加数据x后的向量
//	提示：输入向量为行向量或者列向量，输出保持行列特性
//Matrix Matlab2c::x_vector(double x,Matrix& a)
//{
//	int i;
//	Matrix p;
//	if(a.row!=1)
//	{
//		p.row=a.row+1;
//		p.column = a.column;
//	}
//	else
//	{
//		p.column=a.column+1;
//		p.row = a.row;
//	}
//	p.data = new double[p.row*p.column];
//	*p.data =x;//在数据首部添加数据
//	for (i=0;i<a.row*a.column;i++)
//		p(i+1)=a.data[i];
//	return p;
//}


//在向量的尾部添加数据x
//输入：向量a,要添加的数据x
//	输出：在向量a的最后面添加数据x后的向量
//	提示：输入向量为行向量或者列向量，输出保持行列特性
//Matrix Matlab2c::vector_x(Matrix& a,double x)
//{
//	int i;
//	Matrix p;
//	if(a.row!=1)
//	{
//		p.row=a.row+1;
//		p.column = a.column;
//	}
//	else
//	{
//		p.column=a.column+1;
//		p.row = a.row;
//	}
//	p.data = new double[p.row*p.column];
//	for (i=0;i<a.row*a.column;i++)
//		p.data[i]=a.data[i];
//	p.data[p.row*p.column-1]=x;//在数据尾部添加数据
//	return p;
//}



//线性等分向量的生成
//输入为数据起点终点a、b以及数据点数n，输出为介于a和b之间等分的n个数,默认为100
Matrix Matlab2c::linspace(double begin,double finish,int number)
{
	Matlab2c::CheckLicense();
	int j;
	double interval = (finish-begin)/(number-1);
	Matrix p(1,number);
	for (j=0;j<p.column;j++)
		p.data[j]=begin+j*interval;
	return p;
}

//对数等分，先等分，在求10的x次方,个数number有默认值100
Matrix Matlab2c::logspace(double begin,double finish,int number)
{
	Matlab2c::CheckLicense();
	int j;
	double interval = (finish-begin)/(number-1);
	Matrix p(1,number);
	for (j=0;j<p.column;j++)
		p.data[j]=std::pow(10,begin+j*interval);
	return p;
}

//向量点积运算
//输入：向量a，向量b
//	输出：向量a和b的点积
double Matlab2c::dot(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	int i,j;
	double sum=0;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			sum +=a(i,j)*b(i,j);
	return sum;
}


//多项式求商,a除以b
//输入：两个多项式的矩阵a与b
//输出：a除以b的商矩阵
Matrix Matlab2c::deconv(Matrix& a1,Matrix& b1)
{
	Matlab2c::CheckLicense();
	Matrix p;
	int i,j;
	int lengtha,lengthb;
	double *ma;
	double *mb;
	double *a;  //清楚a1前面的0
	double *b;  //清除b1前面的零
	for (i=0;i<a1.column;i++)
		if ((a1.data[i])!=0)
			break;
	lengtha =a1.column-i;
	a =new double[lengtha];
	for (i=(a1.column-lengtha);i<a1.column;i++)
		a[i-a1.column+lengtha] = a1.data[i];

	for (i=0;i<b1.column;i++)
		if ((b1.data[i])!=0)
			break;
	//b成为b1消除前面0后的多项式
	lengthb=b1.column-i;
	b=new double[lengthb];
	for (i=(b1.column-lengthb);i<b1.column;i++)
		b[i-b1.column+lengthb] = b1.data[i];

	p=Matrix(1,lengtha+1-lengthb);
	ma = new double[lengtha];  //储存循环被除数
	mb = new double[lengtha];  //存储循环减去的值
	for (i=0;i<lengtha;i++)
		ma[i] =a[i];

	for (i=0;i<p.column;i++)
	{
		p.data[i]=ma[i]/(b[0]);
		for (j=0;j<lengthb;j++)
			mb[j] =(p.data[i])*(b[j]);

		for (j=i;j<(i+lengthb);j++)
			ma[j]=ma[j]-mb[j-i];
	}
	delete[] a;
	delete[] b;
	delete[] ma;
	delete[] mb;
	return p;
}



//多项式求导
//输入:多项式的系数矩阵a(按列合并成一维向量)
//输出:多项导数的系数向量
Matrix Matlab2c::polyder(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(1,a.row*a.column-1);
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);
	for (int i=0;i<p.column;i++)
		p.data[i] =temp.data[i]*(p.column-i);
	return p;
}


//多项式求积分
//输入:多项式的系数矩阵a(按列合并成一维向量)
//输出:多项积分的系数向量，常数项为0
Matrix Matlab2c::polyint(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(1,a.row*a.column+1);
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);
	for (int i=0;i<p.column-1;i++)
		p.data[i] = temp.data[i]/(p.column-i-1);
	p.data[a.row*a.column]=0;
	return p;
}


//多项式加法
//输入:两个多项式的系数矩阵a和b
//输出:两个多项式和的系数矩阵
//Matrix Matlab2c::polynome_add(Matrix& a,Matrix& b)
//{
//	int i;
//	Matrix p;
//	if (a.column>b.column || a.column==b.column)
//	{
//		p=Matrix(1,a.column);
//		for (i=0;i<a.column;i++)
//		{
//			if (i<(a.column-b.column))
//			{
//				p.data[i] = a.data[i];
//			}
//			else
//				p.data[i] = a.data[i]+b.data[i-a.column+b.column];
//		}
//	}
//	if (a.column<b.column)
//	{
//		p=Matrix(1,b.column);
//		for (i=0;i<b.column;i++)
//		{
//			if (i<(b.column-a.column))
//			{
//				p.data[i] = b.data[i];
//			}
//			else
//				p.data[i] = b.data[i]+a.data[i-b.column+a.column];
//		}
//	}
//	return p;
//}



//求多项式a，在m点处的值
//输入：多项式的系数矩阵a及求值点m,(按列合并成一维向量)
//输出：多项式在m点的取值
double Matlab2c::polyval(Matrix& a,double m)
{
	Matlab2c::CheckLicense();
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);

	double s =0;
	for(int i=0;i<a.row*a.column;i++)
		s+=a.data[a.row*a.column-i-1]*pow(m,i);
	return s;
}



//取集合的单值元素
//输入：集合a
//输出：集合指针，第一个集合表示集合a去除重复元素后的集合排序，第二个集合是新集合元素在原集合a中的位置，第三个集合为原集合a元素在新集合中的位置。
//提示：位置下标从0开始
Matrix* Matlab2c::unique(Matrix& a)
{
	Matlab2c::CheckLicense();
	bool exist=false;
	vector<double> c;

	Matrix *p; 
	p = new Matrix[3];
	for (int j=0;j<a.row*a.column;j++)
	{
		exist=false;
		for (int n=0;n<c.size();n++)
			if (a.data[j]==c[n])
			{
				exist=true;
				break;
			}
			if (!exist)
				c.push_back( a.data[j]);  
	}

	Matrix ia(1,c.size());
	Matrix ib(1,a.row*a.column); 
	Matrix tmp(c,1,c.size());
	Matlab2c::Q_sort(tmp);  //快速排序
	for (int i=0;i<a.row*a.column;i++)
	{
		for (int j=0;j<tmp.row*tmp.column;j++)
		{
			if(a(i)==tmp(j))
			{
				ia(j)=i;
				ib(i)=j;
			}
		}
	}

	*p = tmp;
	*(p+1)=ia;
	*(p+2)=ib;
	return p;
}


//求两集合的并集
//输入：集合a，集合b
//	输出：a，b的并集
//	提示：集合以一维矩阵的形式表示
Matrix Matlab2c::unionf(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if (!((a.row==1 || a.column==1)&&(b.row==1 || b.column==1)))
		throw_logic_error("unionf函数要求输入为向量");
	int j,n,m=0;
	int geshu=0;
	Matrix c(1,a.column*a.row+b.column*b.row);
	for (j=0;j<a.row*a.column;j++)
	{
		m=0;
		for (n=0;n<geshu;n++)
			if ((a.data[j])==(c.data[n]))
			{
				m=1;
				break;
			}
			if (m==0)
			{
				c.data[geshu] = a.data[j];
				geshu++;
			}
	}
	for (j=0;j<b.row*b.column;j++)
	{
		m=0;
		for (n=0;n<geshu;n++)
			if (b.data[j]==c.data[n])
			{
				m=1;
				break;
			}
			if (m==0)
			{
				c.data[geshu] = b.data[j];
				geshu++;
			}
	}
	Matrix p(1,geshu);
	for (j=0;j<p.column;j++)
		p.data[j]=c.data[j];
	return p;
}

//检测集合中的元素是否处在另一个集合中
//输入：集合a，集合b
//输出：返回行向量指针，第一个向量记录a中的元素是否存在b中，第二个向量记录a中的元素在b中的位置，不存在则为-1
//提示：集合是一个行向量，即一维矩阵，下标从0开始，不存在为-1
Matrix* Matlab2c::ismember(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	bool exist=false;
	Matrix *p;
	Matrix p1(1,a.column);  //记录a中的元素是否存在b中,存在为1，不存在为0
	Matrix p2(1,a.column);  //记录a中的元素在b中的位置，不存在则为-1
	p = new Matrix[2];
	for (int j=0;j<a.column;j++)
	{
		int n=0;
		exist=false;
		for (n=0;n<b.column;n++)
			if (a.data[j]==b.data[n])
			{
				exist=true;
				break;
			}
		if (exist)
		{
			p1.data[j] = 1;
			p2.data[j] = n;
		}
		else
		{
			p1.data[j] = 0;
			p2.data[j] = -1;
		}
	}
	*p = p1;
	*(p+1)=p2;
	return p;
}



//求两个集合的交集
//输入：集合a，集合b
//输出：返回矩阵指针，第一个集合为a，b的交集，第二个集合为交集在集合a中的位置，第三个集合为交集在b中的位置。
//提示：集合以一维矩阵的形式表示。返回位置时，下标从0开始
Matrix* Matlab2c::intersect(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	vector<double> c;
	vector<int> ia;
	vector<int> ib;
	Matrix *p = new Matrix[3];
	for (int j=0;j<a.column;j++)
		for (int n=0;n<b.column;n++)
			if (a.data[j]==b.data[n])
			{
				ia.push_back(j);
				ib.push_back(n);
				c.push_back(a.data[j]);
				break;
			}
	
	*p = Matrix(c,1,c.size());
	*(p+1)=Matrix(ia,1,ia.size());
	*(p+2)=Matrix(ib,1,ib.size());
	return p;
}






//根据根求多项式系数  或求矩阵特征多项式
//输入：多项式的根向量a
//输出：多项式的系数矩阵
Matrix Matlab2c::poly(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(1,1),b(1,2);
	p.data[0]=1;
	b.data[0] =1;
	if (a.isVector())
	{
		for (i=0;i<a.row*a.column;i++)
		{
			b.data[1] = -(a.data[i]);
			p=conv(p,b);
		}
	}else if (a.row==a.column)   //求方阵的特征多项式
	{
		//p=det(lambda*eye(a.row))-a;
	}else
	{
		throw_logic_error("poly函数参数需为方阵或向量");
	}
	
	return p;
}

