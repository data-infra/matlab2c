#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;

//去除字符串的首尾
void Matlab2c::trim_string(string &s)     //字符串去除首尾
{  
	if (!s.empty())   
	{  
		s.erase(0,s.find_first_not_of(" "));  
		s.erase(s.find_last_not_of(" ") + 1);  
	}
}
//按字符分割字符串
void Matlab2c::split_char(const std::string& yuan, std::vector<std::string>& arr, const std::string& split)   //多字符分割
{
	std::string::size_type pos1, pos2;
	pos2 = yuan.find_first_of(split);
	pos1 = 0;
	while(std::string::npos != pos2)
	{
		if (pos1!=pos2)
			arr.push_back(yuan.substr(pos1, pos2-pos1));
		pos1 = pos2 + 1;
		pos2 = yuan.find_first_of(split, pos1);   //find_first_of方法查询任意一个字符首次出现的位置，允许了使用多个分割字符
	}
	if(pos1 != yuan.length())  //分割剩余的最后一个字符串
		arr.push_back(yuan.substr(pos1));
}
//按字符串分割字符串
void Matlab2c::split_string(const std::string& yuan, std::vector<std::string>& arr, const std::string& split)   //字符串分割
{
	std::string::size_type pos1, pos2;
	pos2 = yuan.find(split);
	pos1 = 0;
	while(std::string::npos != pos2)
	{
		if (pos1!=pos2)
			arr.push_back(yuan.substr(pos1, pos2-pos1));
		pos1 = pos2 + split.size();
		pos2 = yuan.find(split, pos1);   //find_first_of方法查询任意一个字符首次出现的位置，允许了使用多个分割字符
	}
	if(pos1 != yuan.length())
		arr.push_back(yuan.substr(pos1));
}
//替换全部子字符串
void  Matlab2c::replace_string(string&   str,const   string&   old_value,const   string&   new_value)   
{   
	for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())   {   
		if(   (pos=str.find(old_value,pos))!=string::npos   )   
			str.replace(pos,old_value.length(),new_value);   
		else   break;   
	}   
}

//字符串长度
int Matlab2c::length(string& str)
{
     return str.length();
}
//连接两个字符串,每个字符串最右边的空格被裁切 
string Matlab2c::strcat(string& a,string& s) 
{
	string aa = a;
	string ss=s;
	aa.erase(aa.find_last_not_of(" ") + 1);  
	ss.erase(ss.find_last_not_of(" ") + 1);  
	return aa+ss;
}

//比较字符串是否相等
bool Matlab2c::strcmp(string& a,string& b)
{
	if (a==b)
		return true;
	return false;
}
//比较字符串前n个字符相等
bool Matlab2c::strncmp(string& a,string& b,int n)
{
	string aa=a.substr(0,n);
	string bb=b.substr(0,n);
	if (aa==bb)
		return true;
	return false;
}
//比较字符串是否相等，不区分大小写
bool Matlab2c::strcmpi(string& a,string& b)
{
	string aa=Matlab2c::lower(a);
	string bb=Matlab2c::lower(b);
	if (aa==bb)
		return true;
	return false;
}
//比较字符串前n个字符相等，不区分大小写
bool Matlab2c::strncmpi(string& a,string& b,int n)
{
	string aa=a.substr(0,n);
	string bb=b.substr(0,n);
	aa=Matlab2c::lower(aa);
	bb=Matlab2c::lower(bb);
	if (aa==bb)
		return true;
	return false;
}
//字符串转化大小写
string Matlab2c::lower(string str)
{
	transform(str.begin(),str.end(),str.begin(),tolower);
	return str;
}
//字符串转化大小写
string Matlab2c::upper(string str)
{
	transform(str.begin(),str.end(),str.begin(),toupper);
	return str;
}

//检测字符串中每个字符时否属于英文字母 
bool Matlab2c::isletter(string& a)
{
	for (int i=0;i<a.length();i++)
	{
		if(a[i]<'a' || a[i]>'Z')
			return false;
	}
	return true;
}

//检测字符串中每个字符是否属于格式字符（空格，回车，制表，换行符等） 
bool Matlab2c::isspace(string& a)
{
	for (int i=0;i<a.length();i++)
	{
		if(a[i]!=' ' && a[i]!='\n' && a[i]!='\t' && a[i]!='\r')
			return false;
	}
	return true;
}


//删除结尾空格
void Matlab2c::deblank(string& a)
{
	a.erase(a.find_last_not_of(" ") + 1);  
}
//裁切字符串的开头和尾部的空格，制表，回车符
void strtrim(string& str)
{
	trim_string(str);
}
//替换子串
string Matlab2c::strrep(string s,string& sub,string& replace)
{
	replace_string(s,sub,replace);
	return s;
}

//分割字符串成两段
string* Matlab2c::strtok(string s,char split)
{
	string* p=new string[2];
	std::string::size_type pos1=s.find(split);
	if (pos1==std::string::npos)
	{
		p[0]=s;
		p[1]="";
	}else
	{
		p[0]=s.substr(0,pos1);
		p[1]=s.substr(pos1+1);
	}
	return p;

}

//创建有n个空格组成的字符串 
string blanks(int n)
{
	string p="";
	for(int i=0;i<n;i++)
		p=p+" ";
	return  p;
}

//查找str1和str2中，较短字符串在较长字符串中出现的位置，没有出现返回空数组 
vector<int> findstr(string& s,string& sub)
{
	vector<int> all;
	std::string::size_type pos1=s.find(sub);
	if (pos1!=std::string::npos)
	{
		all.push_back(pos1);
		pos1=s.find(sub);
	}
	return all;
}
//将数字转换为数字字符串 
string num2str(double value)
{
	return to_string(value);
}

//把数值数组转换为整数数字组成的字符数组 
string int2str(int value)
{
	return to_string(value);
}

//将数字字符串转换为数字 
double str2num(string str)
{
	return stod(str);
}