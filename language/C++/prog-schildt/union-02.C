#include<iostream.h>
#include<string.h>
int main()
{
	//la definition de union anonyme
	union
	{
		long l;
		double d;
		char s[4];
	};
	//dans ce moment , l'acces a membre d'union c'est direct
	l=100000;
	cout<<l<<" ";
	d=123.2342;
	cout<<d<<" ";
	strcpy(s,"hi");
	cout<<s<<"\n";
}
	