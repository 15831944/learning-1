/* parametri cu valori implicite  nu se compileaza */
#include <iostream.h>

void main()
{
	int i,j;
	void fct(int,int&=i);
	fct(1,j); //efect j=1;
	fct(5); //efect i=5;
	cout<<"i="<<i<<",j="<<j<<'\n';
}

void fct(int a, int& b)
{
	b=a;
}