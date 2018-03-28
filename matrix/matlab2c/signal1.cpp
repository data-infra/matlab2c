#include "Matlab2c.h"
using namespace Matlab2c;

//为信号添加高斯白噪声
//输入：实信号，信噪比
//输出：输出添加列信噪比的信号
//提示：信噪比单位为dB
Matrix Matlab2c::awgn(Matrix& sign,double SNR)
{
	Matlab2c::CheckLicense();
	int i;
	double sigPower=0; 
	double noisePower=0;
	Matrix p(sign.row,sign.column);
	Matrix noise;
	srand((unsigned)time(NULL));
	for (i=0;i<sign.row*sign.column;i++)
	{
		sigPower+=pow(sign.data[i],2);
	}
	sigPower = sigPower/(sign.row*sign.column);
	noisePower = sigPower/(pow(10,SNR/10));
	noise = Matlab2c::normrnd(0,noisePower,sign.row,sign.column);
	for (i=0;i<p.row*p.column;i++)
	{
		p.data[i]=noise.data[i]+sign.data[i];
	}
	return p;
}

//实数序列FFT，先将实数序列转化为复数序列，在进行fft
CMatrix Matlab2c::fft(Matrix& a)
{
	Matlab2c::CheckLicense();
	return fft(CMatrix(a));
}

//复数序列fft
//输入：复数序列a
//输出：序列a的fft
CMatrix Matlab2c::fft(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	int len =a.row*a.column;
	double x1,y1;

	for(int k=0;k<len;k++)
	{
		x1=0;y1=0;
		for(int i=0;i<len;i++)
		{
			x1+=a.data[i].real()*std::cos(2*Matlab2c::PI*k*i/len)+a.data[i].imag()*std::sin(2*Matlab2c::PI*k*i/len);
			y1+=a.data[i].imag()*std::cos(2*Matlab2c::PI*k*i/len)-std::sin(2*Matlab2c::PI*k*i/len)*a.data[i].real();
		}
		p.data[k]=Complex(x1,y1);
	}
	return p;
}





//产生锯齿波或者三角波，幅度为正负1
//输入：锯齿波信号时域取值点a，上升段比例width
//输出：锯齿波信号在取值点上的值
//提示：幅度为正负1，周期为2pi，width为上升段比例,默认为1
Matrix Matlab2c::sawtooth(Matrix& a,double width)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	int n;
	double data;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
		{
			n=std::floor(a(i,j)/(2*Matlab2c::PI));  //向下取整
			data = a(i,j)-n*2*Matlab2c::PI;
			if (data<=(2*Matlab2c::PI*width) && data>0)
				p(i,j) = 1.0/(Matlab2c::PI*width)*data-1;
			else if (data>(2*Matlab2c::PI*width) && data<=(2*Matlab2c::PI))
				p(i,j) = -1.0/(Matlab2c::PI*(1-width))*data+(1+width)/(1-width);
		}
		return p;
}


//生成sinc信号
//输入：sinc信号时域取值点a
//输出：sinc信号在取值点上的值
Matrix Matlab2c::sinc(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if(a(i,j)==0)
				p(i,j)=0;
			else
				p(i,j) = std::sin(PI*(a(i,j)))/(PI*(a(i,j)));
	return p;
}



//获取信号数据data在区间x点上的累计概率密度
//输入：信号数据，计算累计概率的区间点
//	输出：信号在区间点上的累计概率值
//	提示：调用较多内部自定义函数
Matrix Matlab2c::signcdf(Matrix& data ,Matrix& x)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p,temp1(x),temp2;
	temp1.append_top(-INT_MAX);  //添加一个负无穷大
	temp2 = Matlab2c::histc(data,temp1);
	temp2.row--;  //去掉最后一个数据，因为最后一个一定为1
	for (i=0;i<temp2.row;i++)
		temp2.data[i] = temp2.data[i]/(data.row*data.column);  //数据归一化
	p = Matlab2c::cumsum(temp2);
	return p;
}


//根据信号信息获取数据的概率密度函数
//输入：信号数据data 计算概率的区间点
//	输出：信号数据在区间点上的概率密度
//	提示：概率密度计算可能和公式计算不一样.这里为区间点上的积分值
Matrix Matlab2c::signpdf(Matrix& data ,Matrix& x) // data 和x是向量
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p;
	p = Matlab2c::histc(data,x);
	p.row--;  //去掉最后一个数据，因为区间数比数据点数少一个
	for (i=0;i<p.row;i++)
		p.data[i] = p.data[i]/(data.row*data.column);  //数据归一化
	return p;
}




