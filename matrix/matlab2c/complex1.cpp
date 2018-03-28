#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;


//复数矩阵取实部
//输入：复数矩阵a
//输出：复数矩阵a的实部
Matrix Matlab2c::real(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.real();
}

//复数矩阵取虚部
//输入：复数矩阵a
//输出：复数矩阵a的虚部
Matrix Matlab2c::imag(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.imag();
}


//复数矩阵取角度
//输入：复数矩阵a
//输出：矩阵a各复数元素的角度值（弧度单位）
Matrix Matlab2c::angle(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.angle();
}


//复数矩阵取模
//输入：复数矩阵a
//输出：矩阵a各复数元素的模长值
Matrix Matlab2c::abs(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.abs();
}



//复数矩阵取共轭
//输入：复数矩阵a
//输出：复数矩阵a的共轭
CMatrix Matlab2c::conj(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.conj();
}










