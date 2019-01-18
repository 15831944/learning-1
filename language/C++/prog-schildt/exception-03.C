#include<iostream.h>
void Xmanip(int test)
{
	try
	{
		if(test) throw test;
	}
	catch(int i)
	{
		cout<<"Je trouve l'exception #:"<<i<<endl;
	}
}
int main()
{
	cout<<"Start\n";
	Xmanip(1);
	Xmanip(2);
	Xmanip(0);
	Xmanip(3);
	cout<<"FIN\n";
}