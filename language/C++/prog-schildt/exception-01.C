#include<iostream.h>
int main()
{
	cout<<"Start\n";
	try
	{
		cout<<"A l'interieur de block try\n";
		throw 100;
		cout<<"Cette ne s'execute pas\n";
	}
	catch (int i)
	{
		cout<<"J'avais apris une exception -- la valeur est: "<<i<<endl;
	}
	cout<<"Fin\n";
}