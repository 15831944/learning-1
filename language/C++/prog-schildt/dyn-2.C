#include<iostream.h>

int main()
{
	int *p;
	p=new int(87);	//initialise avec 87
	if(!p)
	{
		cout<<"Error de affecte de memoire\n";
		exit(1);
	}
	cout<<"A "<<p<<" "<<"est la valeur "<<*p<<"\n";
	delete p;
}