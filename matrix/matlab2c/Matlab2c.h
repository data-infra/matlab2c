#pragma once                  //��ֹ�ļ������ذ���
#include <stdio.h>
#include <stdlib.h>
#include <string>             //�ַ���
#include <fstream>            //�ļ���
#include <iostream>           //������
#include <regex>              //������ʽ
#include <exception>          //�쳣
#include <vector>             //���ݽṹ  �����ֲ��Ķ�̬����
#include <math.h>             //��ֵ�����㷨
#include <complex>				//���븴��
#include <functional>         //����ָ�룬������ָ����Ϊ�Զ��庯������   ʵ�����ûص�����
#include <iomanip>			//Ϊ���̶ܹ����С��λ�ĸ���
#include <random>			//�������

#ifndef _DLL_API
#define _DLL_API _declspec(dllexport)
#endif
using namespace std;


//�Զ��������ռ�
namespace Matlab2c
{

	class CMatrix;
	class Matrix;
	typedef std::complex<double> Complex;
	typedef unsigned long DWORD;

	const float  FLOATERROR = 1.0e-6F;   //��С������������Ƚ����
	const double DOUBLEERROR = 1.0e-15;  //��Сdouble���Ƚ����
	const long double LONGDOUBLEERROR = 1.0e-30;   //long double�Ƚ����
	const double GoldNo = 0.618033399;		//�ƽ�ָ��(1.0-0.381966)
	const double inf = DBL_MAX;   //�����
	const double pi = 3.1415926535898;   //Բ����
	const double PI = 3.1415926535898;   //Բ����
	const double eps = DOUBLEERROR;  //�����������
	
	//���������������ڳ����߼�����ʱ��������Ϣ
	_DLL_API void throw_logic_error(string str);
	//��ȡ���к�
	_DLL_API string GetSerialNumber();
	//ע��dll
	_DLL_API bool activate(string SerialNumber);
	//У��dll�Ƿ����
	_DLL_API void CheckLicense();



	//���������ַ���
	_DLL_API void trim_string(string &s);
	_DLL_API void split_char(const std::string& yuan, std::vector<std::string>& arr, const std::string& split);
	_DLL_API void split_string(const std::string& yuan, std::vector<std::string>& arr, const std::string& split);
	_DLL_API void replace_string(string&   str,const   string&   old_value,const   string&   new_value);
	_DLL_API int length(string& str);	//�ַ�������
	_DLL_API string strcat(string& a,string& s);   //���������ַ���,ÿ���ַ������ұߵĿո񱻲��� 
	_DLL_API void deblank(string& a);  //ɾ����β�Ŀո�
	_DLL_API void strtrim(string& str);   //�����ַ����Ŀ�ͷ��β���Ŀո��Ʊ��س���
	_DLL_API bool strcmp(string& a,string& b);    //�Ƚ������ַ����Ƿ���ȫ��ȣ��ǣ������棬���򣬷��ؼ� 
	_DLL_API bool strncmp(string& a,string& b,int n);    //�Ƚ������ַ���ǰn���ַ��Ƿ���ȣ��ǣ������棬���򣬷��ؼ� 
	_DLL_API bool strcmpi(string& a,string& b);    //�Ƚ������ַ����Ƿ���ȫ��ȣ�������ĸ��Сд 
	_DLL_API bool strncmpi(string& a,string& b,int n);   //�Ƚ������ַ���ǰn���ַ��Ƿ���ȣ�������ĸ��Сд
	_DLL_API bool isletter(string& a);  //����ַ�����ÿ���ַ�ʱ������Ӣ����ĸ 
	_DLL_API bool isspace(string& a);    //����ַ�����ÿ���ַ��Ƿ����ڸ�ʽ�ַ����ո񣬻س����Ʊ����з��ȣ� 
	_DLL_API string strrep(string s,string& sub,string& replace);   //�����ַ����滻�����ִ�Сд 
	_DLL_API vector<int> findstr(string& s,string& sub);   //����str1��str2�У��϶��ַ����ڽϳ��ַ����г��ֵ�λ�ã�û�г��ַ��ؿ����� 
	_DLL_API string* strtok(string s,char split);     //����str����charָ�����ַ���ǰ�Ĳ��ֺ�֮��Ĳ��֣� 
	_DLL_API string blanks(int n);            //������n���ո���ɵ��ַ��� 
	_DLL_API string lower(string str);           //���ַ����е���ĸת����Сд 
	_DLL_API string upper(string str);            //���ַ����е���ĸת���ɴ�д  
	_DLL_API string num2str(double value);		//������ת��Ϊ�����ַ��� 
	_DLL_API double str2num(string str);		//�������ַ���ת��Ϊ���� 
	_DLL_API string int2str(int value);		//����ֵ����ת��Ϊ����������ɵ��ַ����� 



	//��ѧ����
	_DLL_API bool FloatEqual(float lhs, float rhs);		//�Ƚ���float���������
	_DLL_API bool FloatNotEqual(float lhs, float rhs);		//�Ƚ���float�����������
	_DLL_API bool FloatEqual(double lhs, double rhs);		//�Ƚ���double���������
	_DLL_API bool FloatNotEqual(double lhs, double rhs);	//�Ƚ���double�����������
	_DLL_API bool FloatEqual(long double lhs, long double rhs);	//�Ƚ���long double���������
	_DLL_API bool FloatNotEqual(long double lhs, long double rhs);	//�Ƚ���long double�����������
	
	//����ת��
	//_DLL_API double hex2num(string str);  // ���ַ�����ʾ��16������ת����һ��˫���ȸ�������
	//dec2hex��hex2dec

	//��λ����
	_DLL_API int bitand(int x,int y);  //��λ��
	_DLL_API int bitcmp(int x);  //��λ��
	_DLL_API int bitor(int x,int y);  //��λ���
	_DLL_API int bitxor(int x,int y);  //��λ���
	_DLL_API int bitshift(int x,int k);  //��λ�ƶ�
	//_DLL_API int bitget(int x,int pos);  //��λ��ȡ
	//_DLL_API int& bitset(int& x,int pos);  //��λ����


	//��������
	_DLL_API double realmax(string type="double");
	_DLL_API double realmin(string type="double");


	//ʱ�亯��
	//double start_time=0;
	//_DLL_API int now();	//��������ʽ������ǰ���ں�ʱ��
	//_DLL_API string date();	//���ַ�ת��ʽ������ǰ����
	//_DLL_API Matrix clock();	//��������ʽ������ǰ���ں�ʱ��
	//_DLL_API int datenum();	//���ڵ�������ʽת��
	//_DLL_API string datestr(int now,int mode=0);	//���ڵ��ַ�����ʽת��
	//_DLL_API Matrix datevec();	//���ڵ�������ʽת��
	//_DLL_API Matrix calendar();	//��������
	//_DLL_API Matrix weekday();	//���ں���
	//_DLL_API Matrix eomday();	//��ĩ���жϺ���
	//_DLL_API Matrix cputime();	//����CPU��ʱ��
	//_DLL_API void tic();	//��������ʱ��
	//_DLL_API double toc();	//��ȡ����ʱ��
	//_DLL_API Matrix etime();	//ʹ��ʱ�亯��
	//_DLL_API Matrix pause();	//��ͣ����




//����ʵ��������
_DLL_API class Matrix{
//��������
public:		
	double* data;
	int row;
	int column;
	//���캯���������վ���
	Matrix(){
		row=0;column=0;data=nullptr;
	}
	//��doubeת��Ϊ1x1����
	Matrix(double item){
		row=1;column=1;this->data=new double[row*column];
		data[0]=item;
	}
	//�������󣬲���ֵ
	Matrix(int row,int column){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
	}
	//����ֵ���󣬾�����ÿ��Ԫ�ض����ڸ���ֵ
	Matrix(int row,int column,double data){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data;
	}
	//�������鹹������,����Ԫ��
	Matrix(int row,int column,double *data){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//�������鹹������,����Ԫ��
	Matrix(double *data,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//����������������
	template<class T>
	Matrix(vector<T> a){
		this->row=a.size();
		this->column=1;
		this->data=new double[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = (double)a[i];
	}
	//����������������
	template<class T>
	Matrix(vector<T> a,int row,int column){
		if (a.size()<row*column)
		{
			throw_logic_error("�޷���������vector���ɾ���");
			return;
			//*this=NULL;
		}
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = (double)a[i];
	}
	//����������������
	Matrix(vector<vector<double>> a){
		if (a.size()>0 && a[0].size()>0)
		{
			this->row=a.size();
			this->column=a[0].size();
			this->data=new double[row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					this->data[i*column+j] = a[i][j];
		}
	}
	//ͨ��matlab�ַ����������
	Matrix(string str){    //ȥ�����߿ո�  ȥ������[]   ��;�ָ�  ��,��ո�ָ�   ��:�ָ�
		Matrix a= str2matrix(str);
		this->row=a.row;
		this->column=a.column;
		this->data=new double[row*column];
		for (int i=0;i<a.row*a.column;i++)
			this->data[i]=a.data[i];
	}
	Matrix str2matrix(string str){   //����һ���ַ����ж��Ƿ�      \[([0-9\-\.:]*[ ,]*;*)+\]    ����Ԫ��Ϊ0-9.:-���   ��������ʹ�ÿո��,�м�����ʹ��;�����Ϊ[]
		trim_string(str);   //ȥ����β�ո�

		if (str[0]=='[' && str[str.length()-1]==']')   //��β�Ƿ�Ϊ[]
		{
			str = str.substr(1,str.length()-2);
			Matrix p = str2matrix(str);
			return p;
		}
		else if(str.find(';')!= string::npos){    //�Ƿ����;  �Ƿ�����
			vector<string> strarr1;
			split_char(str,strarr1,";");   //�ָ�ÿ��
			Matrix p;
			for (int i=0;i<strarr1.size();i++)
			{
				Matrix temp=str2matrix(strarr1[i]);   //����ÿһ�������ַ�������ȡÿһ�е�����
				p.append_bottom(temp);   //����һ������
			}
			return p;
		}else if (str.find_first_of(", ")!= string::npos)   //�Ƿ���� ���Ƿ��ж���
		{
			vector<string> strarr2;
			split_char(str,strarr2,", ");   //�ָ�ÿ��

			Matrix p;
			for (int i=0;i<strarr2.size();i++)
			{
				Matrix temp=str2matrix(strarr2[i]);   //����ÿһ�������ַ�������ȡÿһ�е�����
				p.append_right(temp);   //����һ������
			}
			return p;
		}else if (str.find(':')!= string::npos)    //�ж�ÿ��Ԫ���Ƿ�������Ԫ��
		{
			vector<string> strarr3;
			split_char(str,strarr3,":");   
			if (strarr3.size()==3)//���������Ԫ�ء�������βԪ��
			{
				double begindata=atof(strarr3[0].c_str());
				double jiangedata = atof(strarr3[1].c_str());
				int num = (int)((atof(strarr3[2].c_str())-begindata)/jiangedata)+1;
				double* date_temp = new double[num];
				for (int i=0;i<num;i++)
				{
					date_temp[i]= begindata+jiangedata*i;
				}
				
				Matrix r(1,num,date_temp);
				delete [] date_temp;
				date_temp = 0;
				
				return r;    //�����������󣬷��س���������������Ҳ���Է��س��о���
			}
			if (strarr3.size()==2)//���������Ԫ�أ�βԪ�أ�Ĭ�ϲ���Ϊ1
			{
				double begindata=atof(strarr3[0].c_str());
				int num = (int)((atof(strarr3[1].c_str())-begindata))+1;
				double* date_temp = new double[num];
				for (int i=0;i<num;i++)
				{
					date_temp[i]= begindata+i;
				}
				
				Matrix r(1,num,date_temp);
				delete [] date_temp;
				date_temp = 0;
				
				return r;    //�����������󣬷��س���������������Ҳ���Է��س��о���
			}
		}else
		{
			return Matrix(1,1,atof(str.c_str()));   //����Ǵ����־�ת��Ϊdouble
		}
	}
	//���ƹ��캯��
	Matrix(const Matrix& another){
		this->row=another.row;
		this->column=another.column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
	}	
	//����ת��ΪCMatrix����Ϊǰ��ֻ���������ͣ���û�ж��壬����ֻ��ʹ�����͵����û�ָ�룬����ʹ�����ͱ���
	//����������Ժ�����������ǰ�棬����������������д
	/*operator CMatrix() const
	{
	return CMatrix(*this);
	}*/
	//���ظ�ֵ�������������matlab�и�ֵ������Ƶ�Ч��
	Matrix& operator=(const Matrix& another){
		if(this==&another)
			return *this;
		this->row=another.row;
		this->column=another.column;
		if(data !=nullptr)
			delete[] data;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
		return *this;
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ���ȡʱ����
	double operator()(int i,int j) const
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		if (j>this->column-1 || j<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i*column+j];
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ�д��ʱ����
	double& operator()(int i,int j)
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		if (j>this->column-1 || j<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i*column+j];
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ���ȡʱ����
	double operator()(int i) const
	{
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i];
	}
	//����()�����,�±��0��ʼ��ϰ��
	double& operator()(int i){
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i];
	}
	//����()�����,�±��0��ʼ��ϰ��,��ȡ�Ӿ��󣬶�ȡʱ����
	Matrix operator()(int row1,int row2,int column1,int column2) const   //���������±��л���
	{
		Matrix p(row2-row1+1,column2-column1+1);
		for (int i=row1;i<row2+1;i++)
			for (int j=column1;j<column2+1;j++)
				p(i-row1,j-column1) = this->data[i*column+j];
		return p;
	}
	//�����ַ�����ȡ�Ӿ��󣬲��ܶ��Ӿ���ֵ
	Matrix operator()(string str){
		Matrix rowcontrol,columncontrol;   //�п������У����п�������
		trim_string(str);   //ȥ����β�ո�
		if(str==":")
			return Matrix(*this);
		int index=str.find_first_of(",");
		if (index>-1)   //�������,����ͬʱ�����к���
		{
			string strtemp1=str.substr(0,str.find_first_of(","));   //��ѯ�п����ַ���
			trim_string(strtemp1);   //ȥ����β�ո�
			if (strtemp1==":")   //��ʾ���л����С���������
			{
				rowcontrol = Matrix(1,row);
				for (int i=0;i<row;i++)
					rowcontrol(i)=i;
			}
			else
				rowcontrol = Matrix(strtemp1);

			string strtemp2=str.substr(str.find_first_of(",")+1);   //��ѯ�п����ַ���
			trim_string(strtemp2);   //ȥ����β�ո�
			if (strtemp2==":")   //��ʾ���л����С���������
			{
				columncontrol = Matrix(1,column);
				for (int i=0;i<column;i++)
					columncontrol(i)=i;
			}	
			else
				columncontrol = Matrix(strtemp2);
			Matrix p(rowcontrol.row*rowcontrol.column,columncontrol.row*columncontrol.column);
			for (int i=0;i<rowcontrol.row*rowcontrol.column;i++)
			{
				for (int j=0;j<columncontrol.row*columncontrol.column;j++){
					p(i,j) = this->data[(int)(rowcontrol.data[i]*column+columncontrol.data[j])];
				}
			}
			return p;
		}
		else			//�����������밴����ʹ�ã�ȡ�����ֲ�����
		{
			columncontrol = Matrix(str);
			Matrix p(1,columncontrol.row*columncontrol.column);
			for (int j=0;j<columncontrol.row*columncontrol.column;j++){
				p(j) = this->data[(int)(columncontrol.data[j])];
			}
			return p;
		}

	}

	//���ؼӷ������
	Matrix operator+(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]+xi;
		return p;
	}
	//���ؼӷ������
	Matrix& operator+=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] += xi;
		return *this;
	}
	//���ؼӷ������
	Matrix operator+(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p(i)=data[i]+another(i);
		return p;
	}
	//���ؼӷ������
	Matrix& operator+=(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		for (int i=0;i<row*column;i++)
			this->data[i]+=another.data[i];
		return *this;
	}
	//���ؼ��������
	Matrix operator-(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]-xi;
		return p;
	}
	//���ؼ��������
	Matrix& operator-=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] -= xi;
		return *this;
	}
	//���ؼ��������
	Matrix operator-(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=data[i]-another.data[i];
		return p;
	}
	//���ؼ��������
	Matrix& operator-=(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		for (int i=0;i<row*column;i++)
			this->data[i]-=another.data[i];
		return *this;
	}
	//���س˷������
	Matrix operator*(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = this->data[i]*xi;
		return p;
	}
	//���س˷������
	Matrix& operator*=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] *= xi;
		return *this;
	}
	//���س˷������
	Matrix operator*(Matrix& another){
		if(!another.data || !this->data)
			throw_logic_error("����˷�����Ϊ��");
		if (column!=another.row)
			throw_logic_error ("����ƥ��");
		Matrix p(row,another.column);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				double sum=0;
				for (int t=0;t<column;t++)  //��һ������ĵ�i�г��Եڶ�������ĵ�j��
					sum+=data[i*column+t]*another(t,j);
				p(i,j) = sum;
			}
		return p;
	}
	//���س��������
	Matrix operator/(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]/xi;
		return p;
	}
	//���س��������
	Matrix& operator/=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] /= xi;
		return *this;
	}
	//���ؾ���Ⱥ�==�����
	bool operator==(Matrix& another){
		if (this->row!= another.row)
			return false;
		if (this->column != another.column)
			return false;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i],another.data[i]))
				return false;
		return true;
	}
	//���ؾ���Ⱥ�!=�����
	bool operator!=(Matrix& another){
		if (this->row!= another.row)
			return true;
		if (this->column != another.column)
			return true;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i],another.data[i]))
				return true;
		return false;
	}
	//����һԪ������������
	Matrix operator +() const
	{
		return *this;			//�������κδ���ά��ԭ״
	}
	//����һԪ������������
	Matrix operator -() const
	{
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=-this->data[i];
		return p;
	}
	//����ת�ã����ı�Դ����
	Matrix T()
	{
		Matrix p(column,row);
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				p(j,i)=(*this)(i,j);
		return p;
	}

	//��������չ���ı���Դ����
	void append_left(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			double* datanew=new double[row*new_column];
			for (int i=0;i<a.row;i++)
			{
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j]=a(i,j);
				for (int j=0;j<column;j++)
					datanew[i*new_column+j+a.column]=this->data[i*column+j];
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//�����ײ����Ԫ��
	void append_left(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//��������չ���ı���Դ����
	void append_right(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			double* datanew=new double[row*new_column];
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<column;j++)
					datanew[i*new_column+j]=this->data[i*column+j];
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j+column]=a(i,j);
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//����β�����Ԫ��
	void append_right(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//��������չ���ı���Դ����
	void append_top(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			double* datanew=new double[new_row*column];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[i*column+j]=a(i,j);
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[(i+a.row)*column+j]=this->data[i*column+j];
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//�����ײ����Ԫ��
	void append_top(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//��������չ���ı���Դ����
	void append_bottom(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			double* datanew=new double[new_row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[i*column+j]=this->data[i*column+j];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[(i+row)*column+j]=a(i,j);
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//����β�����Ԫ��
	void append_bottom(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_row(int rowindex)  //ɾ��ָ����
	{
		if (rowindex>=row || rowindex<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newrow=row-1;
		data = new double[newrow*column];
		for (int i=0;i<rowindex;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=rowindex;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_row(int row1,int row2)  //ɾ������,���������±�
	{
		if (row1>=row || row2>=row || row1<0||row2<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newrow=row-row2+row1-1;
		data = new double[newrow*column];
		for (int i=0;i<row1;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=row1;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+row2-row1+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_column(int columnindex)  //ɾ��ָ����
	{
		if (columnindex>=column || columnindex<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-1;
		data = new double[row*newcolumn];
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_column(int column1,int column2)  //ɾ������,���������±�
	{
		if (column1>=column || column2>=column || column1<0||column2<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-column2+column1-1;
		data = new double[row*newcolumn];
		
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//ɾ��ָ�����к���
	void remove_row_column(int rowindex,int columnindex)
	{
		if (columnindex>=column || columnindex<0 || rowindex<0 || rowindex>=row)
		{
			throw_logic_error("ɾ�����з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-1;
		int newrow=row-1;
		data = new double[newrow*newcolumn];
		for (int i=0;i<rowindex;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		for (int i=rowindex;i<newrow;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//ɾ�����кͶ���
	void remove_row_column(int row1,int row2,int column1,int column2)
	{
		if (column1>=column || column1<0 || row1<0 || row1>=row || column2>=column || column2<0 || row2<0 || row2>=row)
		{
			throw_logic_error("ɾ�����з�ΧԽ��");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-column2+column1-1;
		int newrow=row-row2+row1-1;
		data = new double[newrow*newcolumn];
		for (int i=0;i<row1;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		for (int i=row1;i<newrow;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j+column2-column1+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//�滻�ֲ����󣬸ı���Դ����
	void replace(Matrix &a,int row1,int column1) 
	{
		int endrow=std::min(this->row,a.row+row1);
		int endcolumn=std::min(this->column,a.column+column1);
		for (int i=row1;i<endrow;i++)
			for (int j=column1;j<endcolumn;j++)
				this->data[i*column+j] = a((i-row1),j-column1);
	}



	//����Ԫ�ر�����������Ҫ���������������������Ԫ��ֵ�������У������У�Դ���󣬷����滻ֵ�����ı�Դ����
	Matrix map(function<double(double item,int row,int column,Matrix& src)> fun){
		Matrix p(this->row,this->column);
		for (int i=0;i<this->row;i++)
			for (int j=0;j<this->column;j++)
				p(i,j)=fun(this->data[i*column+j],i,j,*this);
		return p;	
	}

	//����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ���������Ϊһ����������
	 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
	//�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
	Matrix map_row(function<double(double prev,double cur,int row,int column,Matrix& src)> fun){
		Matrix p(this->row,1);
		for (int i=0;i<this->row;i++)
		{
			double result = this->data[i*column];
			for (int j=1;j<this->column;j++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(i) = result;
		}
		return p;
	}

	//����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
	 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
	//�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
	Matrix map_column(function<double(double prev,double cur,int row,int column,Matrix& src)> fun){
		Matrix p(1,this->column);
		for (int j=0;j<this->column;j++)
		{
			double result = this->data[j];
			for (int i=1;i<this->row;i++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(j) = result;
		}
		return p;
	}
	//������
	Matrix dot(Matrix& a,string operation)
	{
		if (row!=a.row || column!=a.column)
		{
			throw_logic_error("���������ƥ��");
			return NULL;
		}
		Matrix p(row,column);
		if (operation=="+")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)+a(i,j);
		else if (operation=="-")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)-a(i,j);
		else if (operation=="*")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)*a(i,j);
		else if (operation=="/")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)/a(i,j);
		else if (operation=="\\")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=a(i,j)/(*this)(i,j);
		return p;
	}

	//��ѯ�Ƿ�������
	bool isVector()
	{
		if (row==1||column==1)
			return true;
		return false;
	}
	//ת���ɸ�������
	/*CMatrix toCMatrix(){
		CMatrix p(*this);
		return p;
	}*/
	//�ַ�����ʽ��ʾ
	string toString(){
		stringstream back;
		for (int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				back<< fixed << setprecision(4)<<data[i*column+j];
				back<<"   ";
			}
			if(i!=row-1)
				back<<"\n";
		}
		return back.str();
	}
	//��������ת��Ϊseries
	double* toSeries(){
		double* back = new double[row*column];
		for (int i=0;i<column*row;i++)
			back[i] = data[i];
		return back;
	}
	//ת��Ϊ��λ����
	double** toArray(){
		double** back = new double*[column];
		int n=0;
		for (int i=0;i<row;i++){
			back[i]=new double[column];
			for(int j=0;j<column;j++)
				back[i][j] = data[i*column+j];
		}
		return back;
	}
	//��������ת��Ϊһάvector
	vector<double> toVector(){
		int t=0;
		vector<double> back(row*column);
		for (int i=0;i<row;i++)
			for (int j=0;j<column;j++)
				back[t++]=data[i*column+j];
		return back;
	}
	//��������ת��Ϊ��άvector
	vector<vector<double>> toVector2(){
		int rowindex=0;
		int columnindex=0;
		vector<vector<double>> back(row);
		for (int i=0;i<row;i++)
		{
			columnindex=0;
			vector<double> newrow(column);
			for (int j=0;j<column;j++)
				newrow[columnindex++]=data[i*column+j];
			back[rowindex++]=newrow;
		}
		return back;
	}
	//��������������ʹ������������ԭ�����ںܶຯ���ֲ����ͷ�����Ҫ����data���ݣ�����ʹ�ֲ�����������ɽ��ն��󲻿��á����������д�˸�ֵ����������Լ��ϣ���Ϊ�ں����ڣ��ȸ�ֵ���������ֲ�����
	~Matrix(){
		row=0;column=0;
		if(data !=nullptr){
			delete[] data;
			data=nullptr;
		}
	}

};




//���帴��������
_DLL_API class CMatrix{
//��������
public:		
	Complex* data;
	int row;
	int column;
	//���캯���������վ���
	CMatrix(){
		row=0;column=0;data=nullptr;
	}
	//��Complexת��Ϊ1x1����
	CMatrix(Complex item){
		row=1;column=1;this->data=new Complex[row*column];
		data[0]=item;
	}
	//��ʵ����ת��Ϊ��������
	CMatrix(Matrix& a){
		row=a.row;
		column=a.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				data[i*column+j]=Complex(a(i,j),0);
	}
	//��ʵ�����鲿��ɸ�������
	CMatrix(Matrix& real,Matrix& imag){
		row=real.row;
		column=real.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				data[i*column+j]=Complex(real(i,j),imag(i,j));
	}

	//�������󣬲���ֵ
	CMatrix(int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
	}
	//����ֵ���󣬾�����ÿ��Ԫ�ض����ڸ���ֵ
	CMatrix(int row,int column,Complex data){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data;
	}
	//�������鹹������,����Ԫ��
	CMatrix(int row,int column,double *x,double *y){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=Complex(x[i],y[i]);
	}
	//�������鹹������,����Ԫ��
	CMatrix(double *x,double *y,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=Complex(x[i],y[i]);
	}
	//�������鹹������,����Ԫ��
	CMatrix(int row,int column,Complex *data){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//�������鹹������,����Ԫ��
	CMatrix(Complex *data,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//����������������
	CMatrix(vector<Complex> a){
		this->row=a.size();
		this->column=1;
		this->data=new Complex[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = a[i];
	}
	//����������������
	CMatrix(vector<Complex> a,int row,int column){
		if (a.size()<row*column)
		{
			throw_logic_error("�޷���������vector���ɾ���");
			return;
			//*this=NULL;
		}
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = a[i];
	}
	//����������������
	CMatrix(vector<vector<Complex>> a){
		if (a.size()>0 && a[0].size()>0)
		{
			this->row=a.size();
			this->column=a[0].size();
			this->data=new Complex[row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					this->data[i*column+j] = a[i][j];
		}
	}
	//���ƹ��캯��
	CMatrix(const CMatrix& another){
		this->row=another.row;
		this->column=another.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
	}	
	//���ظ�ֵ�������������matlab�и�ֵ������Ƶ�Ч��
	CMatrix& operator=(const CMatrix& another){
		if(this==&another)
			return *this;
		this->row=another.row;
		this->column=another.column;
		if(data !=nullptr)   //�������ͷ�֮ǰ���ڴ棬��Ȼ�ڴ�й©��
			delete[] data;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
		return *this;
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ���ȡʱ����
	Complex operator()(int i,int j) const
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		if (j>this->column-1 || j<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i*column+j];
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ�д��ʱ����
	Complex& operator()(int i,int j)
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		if (j>this->column-1 || j<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i*column+j];
	}
	//����()�����,�±��0��ʼ��ϰ�ߣ���ȡʱ����
	Complex operator()(int i) const
	{
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i];
	}
	//����()�����,�±��0��ʼ��ϰ��
	Complex& operator()(int i){
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("��ȡ����Ԫ�أ���������Χ");
		return data[i];
	}
	//����()�����,�±��0��ʼ��ϰ��,��ȡ�Ӿ��󣬶�ȡʱ����
	CMatrix operator()(int row1,int row2,int column1,int column2) const   //���������±��л���
	{
		CMatrix p(row2-row1+1,column2-column1+1);
		for (int i=row1;i<row2+1;i++)
			for (int j=column1;j<column2+1;j++)
				p(i-row1,j-column1) = this->data[i*column+j];
		return p;
	}
	
	//���ؼӷ������
	CMatrix operator+(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]+xi;
		return p;
	}
	//���ؼӷ������
	CMatrix& operator+=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] += xi;
		return *this;
	}
	//���ؼӷ������
	CMatrix operator+(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p(i)=data[i]+another(i);
		return p;
	}
	//���ؼӷ������
	CMatrix& operator+=(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		for (int i=0;i<row*column;i++)
			this->data[i]+=another.data[i];
		return *this;
	}
	//���ؼ��������
	CMatrix operator-(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]-xi;
		return p;
	}
	//���ؼ��������
	CMatrix& operator-=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] -= xi;
		return *this;
	}
	//���ؼ��������
	CMatrix operator-(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=data[i]-another.data[i];
		return p;
	}
	//���ؼ��������
	CMatrix& operator-=(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("����ƥ��");
		for (int i=0;i<row*column;i++)
			this->data[i]-=another.data[i];
		return *this;
	}
	//���س˷������
	CMatrix operator*(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = this->data[i]*xi;
		return p;
	}
	//���س˷������
	CMatrix& operator*=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] *= xi;
		return *this;
	}
	//���س˷������
	CMatrix operator*(CMatrix& another){
		if(!another.data || !this->data)
			throw_logic_error("����˷�����Ϊ��");
		if (column!=another.row)
			throw_logic_error ("����ƥ��");
		CMatrix p(row,another.column);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				Complex sum=0;
				for (int t=0;t<column;t++)  //��һ������ĵ�i�г��Եڶ�������ĵ�j��
					sum+=data[i*column+t]*another(t,j);
				p(i,j) = sum;
			}
		return p;
	}
	//���س��������
	CMatrix operator/(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]/xi;
		return p;
	}
	//���س��������
	CMatrix& operator/=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] /= xi;
		return *this;
	}
	//���ؾ���Ⱥ�==�����
	bool operator==(CMatrix& another){
		if (this->row!= another.row)
			return false;
		if (this->column != another.column)
			return false;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i].real(),another.data[i].real()) || FloatNotEqual(this->data[i].imag(),another.data[i].imag()))
				return false;
		return true;
	}
	//���ؾ���Ⱥ�!=�����
	bool operator!=(CMatrix& another){
		if (this->row!= another.row)
			return true;
		if (this->column != another.column)
			return true;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i].real(),another.data[i].real()) || FloatNotEqual(this->data[i].imag(),another.data[i].imag()))
				return true;
		return false;
	}
	//����һԪ������������
	CMatrix operator +() const
	{
		return *this;			//�������κδ���ά��ԭ״
	}
	//����һԪ������������
	CMatrix operator -() const
	{
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=-this->data[i];
		return p;
	}
	//����ת�ã����ı�Դ����
	CMatrix T()
	{
		CMatrix p(column,row);
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				p(j,i)=(*this)(i,j);
		return p;
	}

	//��������չ���ı���Դ����
	void append_left(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			Complex* datanew=new Complex[row*new_column];
			for (int i=0;i<a.row;i++)
			{
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j]=a(i,j);
				for (int j=0;j<column;j++)
					datanew[i*new_column+j+a.column]=this->data[i*column+j];
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//�����ײ����Ԫ��
	void append_left(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//��������չ���ı���Դ����
	void append_right(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			Complex* datanew=new Complex[row*new_column];
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<column;j++)
					datanew[i*new_column+j]=this->data[i*column+j];
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j+column]=a(i,j);
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//����β�����Ԫ��
	void append_right(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//��������չ���ı���Դ����
	void append_top(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			Complex* datanew=new Complex[new_row*column];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[i*column+j]=a(i,j);
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[(i+a.row)*column+j]=this->data[i*column+j];
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//�����ײ����Ԫ��
	void append_top(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//��������չ���ı���Դ����
	void append_bottom(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			Complex* datanew=new Complex[new_row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[i*column+j]=this->data[i*column+j];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[(i+row)*column+j]=a(i,j);
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("�ϲ�������������");
		}
	}
	//����β�����Ԫ��
	void append_bottom(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_row(int rowindex)  //ɾ��ָ����
	{
		if (rowindex>=row || rowindex<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newrow=row-1;
		data = new Complex[newrow*column];
		for (int i=0;i<rowindex;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=rowindex;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_row(int row1,int row2)  //ɾ������,���������±�
	{
		if (row1>=row || row2>=row || row1<0||row2<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newrow=row-row2+row1-1;
		data = new Complex[newrow*column];
		for (int i=0;i<row1;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=row1;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+row2-row1+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_column(int columnindex)  //ɾ��ָ����
	{
		if (columnindex>=column || columnindex<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-1;
		data = new Complex[row*newcolumn];
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//ɾ��ָ���У��ı���Դ����
	void remove_column(int column1,int column2)  //ɾ������,���������±�
	{
		if (column1>=column || column2>=column || column1<0||column2<0)
		{
			throw_logic_error("ɾ���з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-column2+column1-1;
		data = new Complex[row*newcolumn];
		
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//ɾ��ָ�����к���
	void remove_row_column(int rowindex,int columnindex)
	{
		if (columnindex>=column || columnindex<0 || rowindex<0 || rowindex>=row)
		{
			throw_logic_error("ɾ�����з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-1;
		int newrow=row-1;
		data = new Complex[newrow*newcolumn];
		for (int i=0;i<rowindex;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		for (int i=rowindex;i<newrow;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//ɾ�����кͶ���
	void remove_row_column(int row1,int row2,int column1,int column2)
	{
		if (column1>=column || column1<0 || row1<0 || row1>=row || column2>=column || column2<0 || row2<0 || row2>=row)
		{
			throw_logic_error("ɾ�����з�ΧԽ��");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-column2+column1-1;
		int newrow=row-row2+row1-1;
		data = new Complex[newrow*newcolumn];
		for (int i=0;i<row1;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		for (int i=row1;i<newrow;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j+column2-column1+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//�滻�ֲ����󣬸ı���Դ����
	void replace(CMatrix &a,int row1,int column1) 
	{
		int endrow=std::min(this->row,a.row+row1);
		int endcolumn=std::min(this->column,a.column+column1);
		for (int i=row1;i<endrow;i++)
			for (int j=column1;j<endcolumn;j++)
				this->data[i*column+j] = a((i-row1),j-column1);
	}



	//����Ԫ�ر�����������Ҫ���������������������Ԫ��ֵ�������У������У�Դ���󣬷����滻ֵ�����ı�Դ����
	CMatrix map(function<Complex(Complex item,int row,int column,CMatrix& src)> fun){
		CMatrix p(this->row,this->column);
		for (int i=0;i<this->row;i++)
			for (int j=0;j<this->column;j++)
				p(i,j)=fun(this->data[i*column+j],i,j,*this);
		return p;	
	}

	//����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ���������Ϊһ����������
	 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
	//�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
	CMatrix map_row(function<Complex(Complex prev,Complex cur,int row,int column,CMatrix& src)> fun){
		CMatrix p(this->row,1);
		for (int i=0;i<this->row;i++)
		{
			Complex result = this->data[i*column];
			for (int j=1;j<this->column;j++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(i) = result;
		}
		return p;
	}

	//����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
	 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
	//�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
	CMatrix map_column(function<Complex(Complex prev,Complex cur,int row,int column,CMatrix& src)> fun){
		CMatrix p(1,this->column);
		for (int j=0;j<this->column;j++)
		{
			Complex result = this->data[j];
			for (int i=1;i<this->row;i++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(j) = result;
		}
		return p;
	}
	//������
	CMatrix dot(CMatrix& a,string operation)
	{
		if (row!=a.row || column!=a.column)
		{
			throw_logic_error("���������ƥ��");
			return NULL;
		}
		CMatrix p(row,column);
		if (operation=="+")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)+a(i,j);
		else if (operation=="-")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)-a(i,j);
		else if (operation=="*")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)*a(i,j);
		else if (operation=="/")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)/a(i,j);
		else if (operation=="\\")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=a(i,j)/(*this)(i,j);
		return p;
	}

	//��ѯ�Ƿ�������
	bool isVector()
	{
		if (row==1||column==1)
			return true;
		return false;
	}
	//ʵ������
	Matrix real(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++){
			p(i) = data[i].real();
		}
		return p;
	}
	//�鲿����
	Matrix imag(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++){
			p(i) = data[i].imag();
		}
		return p;
	}
	//ģֵ����
	Matrix abs(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=(double)std::sqrt((this->data[i].imag())*(this->data[i].imag())+(this->data[i].real())*(this->data[i].real()));
		return p;
	}
	//�ǶȾ���
	Matrix angle(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=(double)std::atan((this->data[i].imag())/(this->data[i].real()));
		return p;
	}
	//�������
	CMatrix conj(){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=Complex(this->data[i].real(),-(this->data[i].imag()));
		return p;
	}
	//�ַ�����ʽ��ʾ
	string toString(){
		stringstream back;
		for (int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				if(data[i*column+j].imag()<0)
					back<< fixed << setprecision(4)<<data[i*column+j].real()<<data[i*column+j].imag()<<"i";
				else
				{
					back<< fixed << setprecision(4)<<data[i*column+j].real()<<"+"<<data[i*column+j].imag()<<"i";
				}
				back<<"   ";
			}
			if(i!=row-1)
				back<<"\n";
		}
		return back.str();
	}
	//��������ת��Ϊseries
	Complex* toSeries(){
		Complex* back = new Complex[row*column];
		for (int i=0;i<column*row;i++)
			back[i] = data[i];
		return back;
	}
	//ת��Ϊ��λ����
	Complex** toArray(){
		Complex** back = new Complex*[column];
		int n=0;
		for (int i=0;i<row;i++){
			back[i]=new Complex[column];
			for(int j=0;j<column;j++)
				back[i][j] = data[i*column+j];
		}
		return back;
	}
	//��������ת��Ϊһάvector
	vector<Complex> toVector(){
		int t=0;
		vector<Complex> back(row*column);
		for (int i=0;i<row;i++)
			for (int j=0;j<column;j++)
				back[t++]=data[i*column+j];
		return back;
	}
	//��������ת��Ϊ��άvector
	vector<vector<Complex>> toVector2(){
		int rowindex=0;
		int columnindex=0;
		vector<vector<Complex>> back(row);
		for (int i=0;i<row;i++)
		{
			columnindex=0;
			vector<Complex> newrow(column);
			for (int j=0;j<column;j++)
				newrow[columnindex++]=data[i*column+j];
			back[rowindex++]=newrow;
		}
		return back;
	}
	//��������������ʹ������������ԭ�����ںܶຯ���ֲ����ͷ�����Ҫ����data���ݣ�����ʹ�ֲ�����������ɽ��ն��󲻿��á����������д�˸�ֵ����������Լ��ϣ���Ϊ�ں����ڣ��ȸ�ֵ���������ֲ�����
	~CMatrix(){
		row=0;column=0;
		if(data !=nullptr){
			delete[] data;
			data=nullptr;
		}
	}

};







//=================================��������===============================
//����������Ԫ��Ϊ�Խ�Ԫ�صľ���
_DLL_API Matrix blkdiag(Matrix& a);   //blkdiag(1,5,3,5);
//����ʽϵ��������Ѿ���
_DLL_API Matrix compan(Matrix& a);
//���ɵ�λ����    ���뵥λ�����ά���������Ӧ��С�ĵ�λ����
_DLL_API  Matrix eye(int n);
_DLL_API  Matrix eye(int row,int column);  
//����Hankel����   ����Ϊ���������������Ϊ��Hankel����
_DLL_API Matrix hankel(Matrix& a,Matrix& b); 
_DLL_API Matrix hankel(Matrix& a); 
//����Hilbert(ϣ������)����       ����Ϊ�����ά���������Ӧ��С��Hilbert����
_DLL_API Matrix hilb(int n);
//����ȫ1����
_DLL_API Matrix ones(int n);   
_DLL_API Matrix ones(int row,int column);   
//����ȫ0����
_DLL_API Matrix zeros(int n);
_DLL_API Matrix zeros(int row,int column);
//����Pascal����     ����Ϊ�����ά���������Ӧ��С��Pascal����
_DLL_API Matrix pascal(int n);
//�����������Ⱦ���      ��Ӧmatlab�е�toeplitz ����
_DLL_API Matrix toeplitz(Matrix& a,Matrix& b);
//����Wilkinson����ֵ������      ����Ϊ�����ά���������Ӧ��С��Wilkinson����
_DLL_API Matrix wilkinson(int n);
//�����������
_DLL_API  Matrix kron(Matrix& a,Matrix& b);




//==================================�������===============================

//��������
_DLL_API int rank(Matrix& a);
//�����Ӧ����ʽ��ֵ
_DLL_API double det(Matrix& a);
//��������
_DLL_API Matrix inv(Matrix& a);
//�����ļ�
_DLL_API double trace(Matrix& a);
//������������
_DLL_API int length(Matrix& a);
//�������������
_DLL_API int* size(Matrix& a);



//==================================�������===============================
//����Խ���Ԫ�صĳ�ȡ�͸��ݶԽ�Ԫ�����ɾ���
_DLL_API Matrix diag(Matrix& a,int n);
_DLL_API Matrix diag(Matrix& a);
_DLL_API CMatrix diag(CMatrix& a,int n);
_DLL_API CMatrix diag(CMatrix& a);
//��ȡ���������ǣ������Խ�Ԫ�أ����Բ��Ƿ���
_DLL_API Matrix tril(Matrix& a);
_DLL_API CMatrix tril(CMatrix& a);
//��ȡ���������ǣ������Խ�Ԫ�أ����Բ��Ƿ���
_DLL_API Matrix triu(Matrix& a);
_DLL_API CMatrix triu(CMatrix& a);
//�������ҷ�ת
_DLL_API Matrix fliplr(Matrix& a);
_DLL_API CMatrix fliplr(CMatrix& a);
//�������·�ת
_DLL_API Matrix flipud(Matrix& a);
_DLL_API CMatrix flipud(CMatrix& a);
//�����б�ά   ����Ϊ����a���Լ���Ҫ�任��ά��m��n�����Ϊ�������ŵ�m*n����
_DLL_API Matrix  reshape(Matrix& a,int row,int column);
_DLL_API CMatrix  reshape(CMatrix& a,int row,int column);
//������ʱ����ת90��   ����Ϊһ��������ת�Ƕȣ�0����ת��1��ʱ����ת90�ȣ�2��ʱ����ת180�ȣ�3��ʱ����ת270�ȣ���
_DLL_API Matrix rot90(Matrix& a,int n);
_DLL_API Matrix rot90(Matrix& a);
_DLL_API CMatrix rot90(CMatrix& a,int n);
_DLL_API CMatrix rot90(CMatrix& a);
//���ƺ�ƽ�̾���   ����Ϊһ������a���Լ���������m��n�������aΪԪ�ص�m*n����Ͼ���
_DLL_API Matrix repmat(Matrix& a,int m,int n);
_DLL_API CMatrix repmat(CMatrix& a,int m,int n);
//����ϲ���Ŀǰ֧����ά�ϲ���dim=1���������ϲ���dim=2��������ϲ�
_DLL_API Matrix cat(int dim,Matrix& a,Matrix& b);
_DLL_API CMatrix cat(int dim,CMatrix& a,CMatrix& b);



//===========================����ֽ�=======================
//�жϾ���Գ�����	
_DLL_API int isSymmetryRegular(Matrix& a, int sym);
_DLL_API bool isSymmetry(Matrix& a);

//����ֽ�-���淽���LU�ֽ�
_DLL_API Matrix* lu(Matrix& a);
//����ֽ�-���Ⱦ����QR�ֽ�
_DLL_API Matrix* qr(Matrix& a);
//����ֽ�-�Գ����������Cholesky�ֽ�
_DLL_API Matrix chol(Matrix& a);
//����ֽ�-���ⷽ���Schur�ֽ�
_DLL_API Matrix schur(Matrix& a);
//����ֽ�-���ⷽ���Hessenberg�ֽ�
_DLL_API Matrix hess(Matrix& a);
//����ֽ�-���ⷽ�������ֵ�ֽ�EVD
_DLL_API Matrix eig(Matrix& a);
//����ֽ�-������������ֵ�ֽ�SVD
_DLL_API Matrix svd(Matrix& a);




//��ȡ�������   ���룺ԭ����a����ȡ����ʼ��n1����ֹ��n2   ������������a�ĵ�n1�е�n2��(������n2��)��ԭ���󲻸ı�
_DLL_API Matrix get_2column(Matrix& a,int n1,int n2);
_DLL_API Matrix get_2row(Matrix& a,int m1,int m2);
_DLL_API Matrix get_column(Matrix& a,int n);
_DLL_API Matrix get_row(Matrix& a,int m);

_DLL_API void set_2column(Matrix& src,Matrix& sub, int n1,int n2);
_DLL_API void set_2row(Matrix& src,Matrix& sub, int m1,int m2);
_DLL_API void set_column(Matrix& src,Matrix& sub, int n);
_DLL_API void set_row(Matrix& src,Matrix& sub, int m);

_DLL_API Matrix del_2column(Matrix& a,int n1,int n2);
_DLL_API Matrix del_2row(Matrix& a,int m1,int m2);
_DLL_API Matrix del_column(Matrix& a,int n);
_DLL_API Matrix del_row(Matrix& a,int m);
_DLL_API Matrix del_row_column(Matrix& a,int rowsnum,int columnsnum);

_DLL_API Matrix left_right(Matrix& a,Matrix& b);
_DLL_API Matrix up_down(Matrix& a,Matrix& b);

//�������
_DLL_API string disp(Matrix& a);
_DLL_API string disp(CMatrix& a);


//=======================================���������С�����ʽ======================================
//��������   ���룺Ҫ���������ָ�룬���ݵĸ���num
_DLL_API  void Q_sort(Matrix& a);
_DLL_API  void Q_sort(double *a,int num);
//ѡ������
_DLL_API  void C_sort(Matrix& a);
//������
_DLL_API  Matrix sort(Matrix& a);
_DLL_API  Matrix sort(Matrix& a,int dim);
_DLL_API  Matrix sort(Matrix& a,string mode);
_DLL_API  Matrix sort(Matrix& a,int dim,string mode);
//���з�ʽ����
_DLL_API  Matrix sortrows(Matrix& a,int col=0);
//��������ɢ�����������㣬����ʽ�˷�
_DLL_API  Matrix conv(Matrix& a,Matrix& b);
_DLL_API  CMatrix conv(CMatrix& a,CMatrix& b);
//����ȫ����   ��ʾ��������������ͬԪ�ء��������ı�ԭ��������
_DLL_API  Matrix perms(Matrix& a);

//����ѭ����λ   ��ʾ���������ı�Դ���С�rightshift>0������ѭ�����ƣ�rightshift<0����ѭ������
_DLL_API  Matrix circshift(Matrix& a,int downshift);
_DLL_API  Matrix circshift(Matrix& a,int downshift,int rightshift);
_DLL_API  CMatrix circshift(CMatrix& a,int downshift);
_DLL_API  CMatrix circshift(CMatrix& a,int downshift,int rightshift);
//����Ԫ�أ�����λ��     ���룺����a����������m    �����m�������е�λ��
_DLL_API  Matrix find(Matrix& a);  //���ҷ�0Ԫ��λ��
_DLL_API  Matrix find(Matrix& a,double m);
//����λ�ã�����Ԫ��������
//_DLL_API  Matrix getdata(Matrix& a,Matrix& weizhi);
//���ظ��������Ŀ����,����������
_DLL_API  Matrix histc(Matrix& a,Matrix& edg);
//���������л�Ϊ1,0��-1,������Ԫ�ش���0���򷵻�1������0����0��С��0������-1��
_DLL_API  Matrix sign(Matrix& a);
//����������λ�������x
//_DLL_API  Matrix x_vector(double x,Matrix& a);
//��������β���������x
//_DLL_API  Matrix vector_x(Matrix& a,double x);
//���Եȷ�����������    ����Ϊ��������յ�a��b�Լ����ݵ���n�����Ϊ����a��b֮��ȷֵ�n����
_DLL_API  Matrix linspace(double begin,double finish,int number=100);
//��������ָ���ȷ�
_DLL_API  Matrix logspace(double begin,double finish,int number=100);
//�����������
_DLL_API  double dot(Matrix& a,Matrix& b);
//����ʽ����,a����b
_DLL_API  Matrix deconv(Matrix& a1,Matrix& b1);
//����ʽ�� 
_DLL_API  Matrix polyder(Matrix& a);
//����ʽ���� 
_DLL_API  Matrix polyint(Matrix& a);
//����ʽ�ӷ�
//_DLL_API  Matrix polynome_add(Matrix& a,Matrix& b);
//�����ʽa����m�㴦��ֵ
_DLL_API  double polyval(Matrix& a,double m);
//���ݸ������ʽϵ��
_DLL_API  Matrix poly(Matrix& a);

//����ȥ�ظ�
_DLL_API  Matrix *unique(Matrix& a);
//�������ϵĲ���
_DLL_API  Matrix unionf(Matrix& a,Matrix& b);
//��⼯���е�Ԫ���Ƿ�����һ��������
_DLL_API  Matrix *ismember(Matrix& a,Matrix& b);
//���������ϵĽ���
_DLL_API  Matrix *intersect(Matrix& a,Matrix& b);




//=================================�����м���======================================
//�����ά���ۻ�����
_DLL_API  Matrix cumprod(Matrix& a);
_DLL_API  CMatrix cumprod(CMatrix& a);
//���ذ���������������������Ϊ�������������л�������Ϊһ���������Ϊÿ�еĳ˻�������
_DLL_API  Matrix prod(Matrix& a);
_DLL_API  CMatrix prod(CMatrix& a);
//���������еļ���ƽ����������Ϊ������ʱ�����������ļ���ƽ����
_DLL_API  Matrix geomean(Matrix& a);
_DLL_API  CMatrix geomean(CMatrix& a);
//���������еĵ���ƽ����������Ϊ������ʱ�����������ĵ���ƽ����
_DLL_API  Matrix harmmean(Matrix& a);
_DLL_API  CMatrix harmmean(CMatrix& a);
//����Ϊ����a�����Ϊ����a������ͺ󷵻�������p  �������ı�ԭ�����ֵ
_DLL_API  Matrix sum(Matrix& a);
_DLL_API  CMatrix sum(CMatrix& a);
//�����ظ�ά��˳���ۼӺͣ�����Ϊ���󣬷��ذ����ۼӺ�
_DLL_API  Matrix cumsum(Matrix& a);
_DLL_API  CMatrix cumsum(CMatrix& a);



//==================================��ֵ����=======================================
//����Ԫ�ؾ���ֵ
_DLL_API  Matrix abs(Matrix& a);
//����Ԫ������ȡ��
_DLL_API  Matrix ceil(Matrix& a);
//����Ԫ����e��ָ������
_DLL_API  Matrix exp(Matrix& a);
//����Ԫ����ƽ��������
_DLL_API  Matrix sqrt(Matrix& a);
//����Ԫ����0ȡ��
_DLL_API  Matrix fix(Matrix& a);
//����Ԫ������ȡ��
_DLL_API  Matrix floor(Matrix& a);
//����Ԫ����log(e)
_DLL_API  Matrix log(Matrix& a);
//����Ԫ����log(10)
_DLL_API  Matrix log10(Matrix& a);

//����Ԫ����sinֵ
_DLL_API  Matrix sin(Matrix& a);
//����Ԫ����asinֵ
_DLL_API  Matrix asin(Matrix& a);
//����Ԫ����sinhֵ
_DLL_API  Matrix sinh(Matrix& a);
//����Ԫ����cosֵ
_DLL_API  Matrix cos(Matrix& a);
//����Ԫ����acosֵ
_DLL_API  Matrix acos(Matrix& a);
//����Ԫ����coshֵ
_DLL_API  Matrix cosh(Matrix& a);
//�������׳�
//����Ԫ����tanֵ
_DLL_API  Matrix tan(Matrix& a);
//����Ԫ����atanֵ
_DLL_API  Matrix atan(Matrix& a);
//����Ԫ����tanhֵ
_DLL_API  Matrix tanh(Matrix& a);

_DLL_API  int factorial(int a);
//�����׳�
_DLL_API  Matrix factorial(Matrix& a);
//�������
_DLL_API  int nchoosek(int n,int m);



//===================================�źŲ���=======================================
//Ϊ�ź���Ӹ�˹������   ����ȵ�λΪdB
_DLL_API  Matrix awgn(Matrix& sign,double SNR);
//��������fft 
_DLL_API  CMatrix fft(Matrix& a);
_DLL_API  CMatrix fft(CMatrix& a);
//������ݲ��������ǲ�������Ϊ����1   //a��������,��������Ϊ2pi��widthΪ�����α���
_DLL_API  Matrix sawtooth(Matrix& a,double width=1);
//����sinc�ź�   ���룺sinc�ź�ʱ��ȡֵ��a   �����sinc�ź���ȡֵ���ϵ�ֵ
_DLL_API  Matrix sinc(Matrix& a);

//��ȡ�ź�����data������x���ϵ��ۼƸ����ܶ� 
_DLL_API  Matrix signcdf(Matrix& data ,Matrix& x);
//�����ź���Ϣ��ȡ���ݵĸ����ܶȺ���   data ��x������
//��ʾ�������ܶȼ�����ܺ͹�ʽ���㲻һ��.����Ϊ������ϵĻ���ֵ
_DLL_API  Matrix signpdf(Matrix& data ,Matrix& x);




//==============================�ļ�����==========================================
//���ļ��ж�ȡ����
_DLL_API  Matrix load(string path);
//������洢���ļ�
_DLL_API  void save(string path,Matrix& a);
//��ȡ�ļ�������
_DLL_API  int linenum(string path);


//===================================������=======================================
//ȡ������ʵ��
_DLL_API  Matrix real(CMatrix& a);
//ȡ�������鲿
_DLL_API  Matrix imag(CMatrix& a);
//ȡ������Ԫ�ؽǶ�ֵ
_DLL_API  Matrix angle(CMatrix& a);
//ȡ������Ԫ��ģֵ
_DLL_API  Matrix abs(CMatrix& a);
//ȡ�������
_DLL_API  CMatrix conj(CMatrix& a);


//======================================������=================================
//�����ÿ�����ֵ
_DLL_API  Matrix max(Matrix& a,int dim=1);
//�����ÿ����Сֵ
_DLL_API  Matrix min (Matrix& a,int dim=1);
//��ֵ���������ذ������ֵ���������
_DLL_API  Matrix mean(Matrix& a,int dim=1);
//���ظ�����λ����ɵ���������������Ϊ������������1x1����λ��
_DLL_API  Matrix median(Matrix& a,int dim=1);
//���������е���ֵ��Χ�����
_DLL_API  Matrix range(Matrix& a);
//���ذ��б�׼������������Ϊ������ʱ�������������ı�׼��
_DLL_API  Matrix std(Matrix& a);
//���ذ��з�������
_DLL_API  Matrix var(Matrix& a);


//���ɶ���ֲ��������
_DLL_API  Matrix binornd(int n,double p,int row,int column);
//����ֲ����ܶȺ���ֵ
_DLL_API  Matrix binopdf(Matrix& k, int n,double p);
//����ֲ�����������
_DLL_API  Matrix *binostat(Matrix& n,Matrix& p);


//���ɾ��ȷֲ��������
_DLL_API  Matrix rand(int row,int column,double min=0,double max=1);
//���ɾ��ȷֲ������������
_DLL_API  Matrix randind(int row,int column,int min=0,int max=1);
//���ȷֲ����������������ͷ���
_DLL_API  Matrix *unifstat(Matrix& a,Matrix& b);

//���ɱ�׼��̬�ֲ�����
_DLL_API  Matrix randn(int row ,int column);
//������̬�ֲ����������
_DLL_API  Matrix normrnd(double aver,double sigma,int row ,int column);
//��̬�ֲ��ĸ���ֵ��
_DLL_API  Matrix normpdf(Matrix& x,double aver=0,double sigma=1);
//����̬�ֲ��ľ�ֵ�ͷ���
_DLL_API  Matrix *normstat(Matrix& aver,Matrix& sigma);


//����ָ���ֲ����������
_DLL_API  Matrix exprnd(double mu,int row ,int column);
//ָ���ֲ�������ֵ
_DLL_API  Matrix exppdf(Matrix& x,double mu);
//ָ���ֲ��ľ�ֵ�ͷ���
_DLL_API  Matrix *expstat(Matrix& mu);


//���ɷֲ��ĸ���ֵ��
_DLL_API  Matrix poisspdf(Matrix& k,double Lambda);
//�����ֲ�����ֵ
_DLL_API  Matrix raylpdf(Matrix& x,double sigma);
//Τ���ֲ�����ֵ
_DLL_API  Matrix weibpdf(Matrix& x,double k,double lambda);





}
