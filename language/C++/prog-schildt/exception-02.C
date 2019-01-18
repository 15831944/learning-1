#include<iostream.h>
void Xtest(int test)
{
	cout<<"Dans le Xtest, le test est: "<<test<<endl;
	if(test) throw test;
}
int main()
{
	cout<<"Start\n";
	try
	{
		cout<<"Dans le block try\n";
		Xtest(0);
		Xtest(1);
		Xtest(2);
	}
	catch (int i)
	{
		cout<<"Je trouve une exception --- la valeur est: "<<i<<endl;
	}
	cout<<"FIN\n";
}