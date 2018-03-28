#include "Matlab2c.h"
using namespace Matlab2c;




//判断矩阵对称正定	
int Matlab2c::isSymmetryRegular(Matrix& a, int sym)
{		
	Matlab2c::CheckLicense();
	long double ldDet;
	size_t i, j, k;

	size_t sC = a.column;	//矩阵列数
	size_t sR = a.row;	//矩阵行数

	size_t stRank = sR;				// 矩阵阶数
	if(stRank != a.row)
		return int(-1);				// 不是方阵

	if(sym > 0)
		if(isSymmetry(a)==false)
			return int(-2);			//rhs不是对称阵

	cout << " K = 1 \t Determinant = " << a.data[0] <<endl;

	for(k = 0; k < stRank; k ++)	//若要判别半正定，负定，这句要修改
	{
		if(FloatEqual(a(k,k), 0)||a(k,k) < 0)
			return int(-3);	//对角元不大于0，矩阵不是正定阵
	}

	for(k = 2; k <= sR; k++)
	{
		Matrix m(k,k);	//生成一matrix对象

		for(i=0; i<k; i++)
			for(j=0; j<k; j++)
				m(i, j) = (long double)a(i,j);	//初始化

		ldDet = det(m);				// 顺序主子式的值

		cout << " K = " << k << "\t Determinant = " << ldDet << endl; 

		if(FloatEqual(ldDet,0) || ldDet < 0.0)
			return (0);					//不是正定阵
	}
	if(sym == 1) return int(2);			//矩阵为正定对称阵
	else		 return int(1);			//矩阵为正定阵
}

//判断矩阵对称
bool Matlab2c::isSymmetry(Matrix& a)
{
	Matlab2c::CheckLicense();
	bool bSy = true;
	size_t stRow = a.row;	//取矩阵行数

	if(a.column == stRow)	// 必须是方阵
	{
		for(size_t i = 1; i < stRow; i ++)			//判断是否对称
			for(size_t j = 0; j < i; j ++)
				if(FloatNotEqual((long double)a(i,j), (long double)a(i,j)))
				{
					bSy =  false;
					goto RET;
				}
	}
	else
		bSy = false;
RET: return bSy;	//矩阵对称
}


//可逆方阵的LU分解
//输入可逆方阵，输出为L下三角矩阵和U上三角矩阵的矩阵指针
Matrix* Matlab2c::lu(Matrix& a)
{
	Matlab2c::CheckLicense();
	if (a.row!=a.column)
	{
		throw_logic_error("LU分解矩阵必须为方阵");
		return nullptr;
	}
	Matrix *p = new Matrix[2];
	int n=a.row;
	int i,j,k,w,v,tt;
	for (k=0; k<=n-2; k++)
	{ 
		tt=k*n+k;
		if (std::fabs(a.data[tt])+1.0==1.0)
		{ 
			printf("fail\n"); 
			return(nullptr);
		}
		for (i=k+1; i<=n-1; i++)
		{ 
			w=i*n+k; a.data[w]=a.data[w]/a.data[tt];
		}
		for(i=k+1; i<=n-1; i++)
		{ 
			w=i*n+k;
			for (j=k+1; j<=n-1; j++)
			{ 
				v=i*n+j;
				a(v)=a(v)-a(w)*a(k*n+j);
			}
		}
	}
	for (i=0; i<=n-1; i++)
	{ 
		for (j=0; j<i; j++)
		{ 
			w=i*n+j; p[0].data[w]=a.data[w]; p[1].data[w]=0.0;
		}
		w=i*n+i;
		p[0].data[w]=1.0; p[1].data[w]=a.data[w];
		for (j=i+1; j<=n-1; j++)
		{ 
			w=i*n+j; p[0].data[w]=0.0; p[1].data[w]=a.data[w];
		}
	}
	return(p);
}

//满秩矩阵的QR分解
Matrix* Matlab2c::qr(Matrix& a)   //返回矩阵第一个为Q，第二个为R
{
	Matlab2c::CheckLicense();
	Matrix *back = new Matrix[2];
	Matrix& rhs=a;
	int stRow = a.row;	// 矩阵行数
	int stCol = a.column;	// 矩阵列数
	Matrix rhq(stRow,stCol);
	if(stRow < stCol)
	{
		throw_logic_error("QR分解矩阵行不能小于列");
		return nullptr;
	}
	for(int i=0; i<stRow; i++)
		for(int j=0; j<stRow; j++)
		{ 
			rhq(i,j)=0.0;
			if(i==j) rhq(i,j)=1.0;
		}

		int nn=stCol;

		if(stRow == stCol) nn=stRow-1;

		for(int k=0; k<nn; k++)
		{
			double u=0.0;

			for(int i = k; i < stRow; i++)
			{ 
				double w = std::fabs(rhs(i,k));
				if(w > u) u = w;
			}
			double alpha=0.0;
			for(int i = k; i < stRow; i++)
			{
				double t=rhs(i,k)/u;
				alpha=alpha+t*t;
			}

			if(rhs(k,k)>0.0) u=-u;

			alpha=u*std::sqrt(alpha);

			if(FloatEqual(alpha,0.0)) return(0);

			u=std::sqrt(2.0*alpha*(alpha-rhs(k,k)));

			if(FloatNotEqual(u,0.0))
			{ 
				rhs(k,k)=(rhs(k,k)-alpha)/u;

				for(int i=k+1; i<stRow; i++)
					rhs(i,k) /= u;

				for(int j=0; j<stRow; j++)
				{
					double t=0.0;

					for(size_t jj=k; jj<stRow; jj++)
						t=t+rhs(jj,k)*rhq(jj,j);

					for(int i=k; i<stRow; i++)
						rhq(i,j)=rhq(i,j)-2.0*t*rhs(i,k);
				}

				for(int j=k+1; j<stCol; j++)
				{ 
					double t=0.0;

					for(int jj=k; jj<stRow; jj++)
						t=t+rhs(jj,k)*rhs(jj,j);

					for(int i=k; i<stRow; i++)
						rhs(i,j)=rhs(i,j)-2.0*t*rhs(i,k);
				}

				rhs(k,k)=alpha;

				for(int i=k+1; i<stRow; i++)
					rhs(i,k)=0.0;
			}
		}

		for(int i=0; i<stRow-1; i++)
			for(int j=i+1; j<stRow;j++)
				swap(rhq(i,j), rhq(j,i));
		back[0]=rhq;  //赋值为深赋值
		return back;
}



//矩阵分解-对称正定矩阵的Cholesky分解
Matrix Matlab2c::chol(Matrix& a)
{
	Matlab2c::CheckLicense();
	int iReValue= isSymmetryRegular(a, 1);	//判别对称正定
	if(iReValue < 2)
	{
		throw_logic_error("Cholesky矩阵分解要求矩阵正定");
		return NULL;
	}

	int stRank = a.column;	// 矩阵阶数

	Matrix p(a);				//生成一matrix对象，用rhs初始化

	p.data[0] = std::sqrt(p.data[0]); 
	for(int i=1; i<stRank; i++)
		p.data[i*p.column] /= p.data[0];
	for(int j=1; j<stRank; j++)
	{
		for(size_t k=0; k<j; k++)
			p(j,j) -= p(j,k) * p(j,k);
		p(j,j)= std::sqrt(p(j,j));
		for(int i=j+1; i<stRank; i++)
		{
			for(int k=0; k<j; k++)
				p(i,j) -= p(i,k) * p(j,k);
			p(i,j) /= p(j,j);
		}
	}
	for(int i=0; i<stRank-1; i++)
		for(int j=i+1; j<stRank; j++)
			p(i,j)=0;

	return p;		//返回行列式值
}
