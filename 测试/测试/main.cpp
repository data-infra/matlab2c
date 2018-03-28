#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;

string GetSerialNumber1()
{
	int dwBuf[4] = {0};  
	__cpuidex(dwBuf, 1, 1);  
	char szTmp[]={NULL};  
	sprintf(szTmp, "%08X%08X", dwBuf[3], dwBuf[0]);  
	string back(szTmp);  

	return back;
}
int main()
{

	try{
		bool jihuo = Matlab2c::activate("1234");

		//string bb = Matlab2c::GetSerialNumber();
		cout<<jihuo<<endl;
	}catch(exception e)
	{
		cout<<e.what()<<endl;
	}

	system("pause");
	return 0;
}