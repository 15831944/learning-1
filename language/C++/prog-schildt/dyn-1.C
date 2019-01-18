#include<iostream.h>

int main()
{
	int *p;
	p=new int;	//il affecte de space pour un int
	if(!p)
	{
		cout<<"Error de affecte la memoire\n";
		exit(1);
	}
	*p=100;
	cout<<"A "<<p<<" "<<"est la valeur "<<*p<<"\n";
	delete p;
}