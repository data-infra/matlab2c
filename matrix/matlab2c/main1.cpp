#include "Matlab2c.h"
using namespace Matlab2c;

bool activated=true;

//获取cpuid
#if _MSC_VER < 1600    // VS2010. 据说VC2008 SP1之后才支持__cpuidex  
void __cpuidex(int CPUInfo[4], int InfoType, int ECXValue)  
{  
	if (NULL==CPUInfo)    return;  
	_asm{  
		// load. 读取参数到寄存器  
		mov edi, CPUInfo;    // 准备用edi寻址CPUInfo  
		mov eax, InfoType;  
		mov ecx, ECXValue;  
		// CPUID  
		cpuid;  
		// save. 将寄存器保存到CPUInfo  
		mov    [edi], eax;  
		mov    [edi+4], ebx;  
		mov    [edi+8], ecx;  
		mov    [edi+12], edx;  
	}  
}  
#endif    // #if _MSC_VER < 1600    // VS2010. 据说VC2008 SP1之后才支持__cpuidex  


static int activitenum=0;
//获取序列号 
string Matlab2c::GetSerialNumber()
{
	int dwBuf[4] = {0};  
	__cpuidex(dwBuf, 1, 1);  
	char szTmp[]={NULL};  
	sprintf(szTmp, "%08X%08X", dwBuf[3], dwBuf[0]);  
	string back(szTmp);  

	return back;
}
//注册函数
bool Matlab2c::activate(string ActivateNumber)
{
	//return true;   //默认是不需要激活的
	activated=false;
	activitenum++;
	if (activitenum>5)   //当单次激活次数大于5，以后就不能再激活了
		return false;

	//string SerialNumber = Matlab2c::GetSerialNumber();
	//SerialNumber=to_string(SerialNumber[4]>>5)+to_string(SerialNumber[5]>>5)+to_string(SerialNumber[6]>>5);   //防破解，每个DOWRD左移5位。
	//
	//if (ActivateNumber==SerialNumber)
	//{
	//	Matlab2c::activated=true;
	//}

	string arr[10]={"1111111111",
				  "8364592615",
				  "6472559361",
				  "5935871265",
				  "9126582364",
				  "1693258456",
				  "8652901567",
				  "6821932167",
				  "4862159713",
				  "7591357416"};

	//序列号列表
	for(int i=0;i<10;i++)
	{
		if (ActivateNumber==arr[i])
		{
			activated=true;
			return activated;
		}
	}
	throw logic_error("序列号注册失败");
	return activated;
}


//检测是否过期
inline void Matlab2c::CheckLicense()
{
	if(!activated)
	{
		throw logic_error("Matlab2c动态链接库已过期，请先获取序列号");
		return;
	}
}

//弹出错误，内联函数
inline void Matlab2c::throw_logic_error(string str)
{
	throw logic_error(str);
}

//判断float浮点数相等
inline bool Matlab2c::FloatEqual(float lhs, float rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::FLOATERROR)
		return true;
	else
		return false;
}
//判断float浮点数不相等
inline bool	Matlab2c::FloatNotEqual(float lhs, float rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::FLOATERROR)
		return true;
	else
		return false;
}
//判断double浮点数相等
inline bool	Matlab2c::FloatEqual(double lhs, double rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::DOUBLEERROR)
		return true;
	else
		return false;
}
//判断double浮点数不相等
inline bool	Matlab2c::FloatNotEqual(double lhs, double rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::DOUBLEERROR)
		return true;
	else
		return false;
}
//比较两long double浮点数相等
inline bool	Matlab2c::FloatEqual(long double lhs, long double rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::LONGDOUBLEERROR)
		return true;
	else
		return false;
}
//比较两long double浮点数不相等
inline bool	Matlab2c::FloatNotEqual(long double lhs, long double rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::LONGDOUBLEERROR)
		return true;
	else
		return false;
}

//输出对象字符串样式
string Matlab2c::disp(Matrix& a)
{
	return a.toString();
}
string Matlab2c::disp(CMatrix& a)
{
	return a.toString();
}
//返回指定类型最大值
double Matlab2c::realmax(string type){
	if (type=="singe")
		return FLT_MAX;
	else
	{
		return DBL_MAX;
	}
}

//返回指定类型最小值
double Matlab2c::realmin(string type){
	if (type=="singe")
		return FLT_MIN;
	else
	{
		return DBL_MIN;
	}
}

 //按位与
int bitand(int x,int y)
{
	return x&y;
}
//按位求补
int bitcmp(int x)
{
	return ~x;
}
//按位求或
int bitor(int x,int y)
{
	return x|y;
}
//按位异或
int bitxor(int x,int y)
{
	return x^y;
}

//按位移动
int bitshift(int x,int k)
{
	if(k>0)
		return x<<k;
	else
	{
		return x>>k;
	}
}
