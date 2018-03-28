#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;


//从文件中加载数据
//文件内容为矩阵数组形式，元素间通过空格间隔
Matrix Matlab2c::load(string path){
	Matlab2c::CheckLicense();
	std::ifstream fin(path, std::ios::in); 
	char line[1024]={0}; 
	string x="0";
	vector<vector<double>> alldata;
	while(fin.getline(line, sizeof(line),'\n')) 
	{ 

		vector<double> onerow;
		std::stringstream word(line); 
		while(word>>x)
		{
			onerow.push_back(std::stod(x));
		}
		if (onerow.size()!=0)
		{
			alldata.push_back(onerow);
		}

	} 
	fin.close(); 
	Matrix p(alldata);
	return p;
}

//将矩阵数据写入文件
//输入：文件地址，要写入的矩阵
void Matlab2c::save(string path,Matrix& a){
	Matlab2c::CheckLicense();
	std::ofstream fout(path, std::ios::out); 

	for (int i=0;i<a.row;i++)
	{
		int j=0;
		for (j=0;j<a.column-1;j++)
		{
			fout<<a(i,j)<<" ";
		}
		fout<<a(i,j);
		fout<<"\n";
	}
	fout.close();
}


//获取文件的行数
//输入：文件地址
//输出：文件行数
//提示：每行最多1024字节，如果操作可以自己修改每行最大字节数
int Matlab2c::linenum(string path)
{
	Matlab2c::CheckLicense();
	std::ifstream fin(path, std::ios::in); 
	char line[1024]={0}; 
	int num=0;
	while(fin.getline(line, sizeof(line),'\n')) 
	{ 
		num++;
	} 
	fin.close(); 
	return num;
}
