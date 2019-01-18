#include<iostream.h>

void Xmanip(int test)
{
static	char error[]="La value est zero";
	try
	{
		if(test) throw test;
//		else throw "La value est zero";
		else throw error;
	}
	catch(int i)
	{
		cout<<"Il a prelue l'exception #: "<<i<<endl;
	}
	catch(char *sir)
	{
//		cout<<"Il a prelue l'exception #: "<<sir<<endl;
		throw;
	}
	catch(...)
	{
		cout<<"Il n'emporte quelle exception\n";
	}
}
int main()
{
	cout<<"Start\n";
	try
	{
		Xmanip(1);
		Xmanip(2);
		Xmanip(0);
		Xmanip(3);
	}
	catch(char *sir)
	{
		cout<<"Il a prelue l'exception dans main#: "<<sir<<endl;
	}
	cout<<"FIN\n";
}
	