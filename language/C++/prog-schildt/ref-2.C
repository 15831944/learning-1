#include<iostream.h>

void neg(int &i); //i c'est dans ce moment un refference
int main()
{
	int x;
	x=10;
	cout<<x<<" il est nie ";
	neg(x);	//dans ce point ce n'est pas necessaire l'operatoire &
	cout<<x<<"\n";
}

void neg(int &i)
{
	i=-i; //dans ce moment i este une reference, il n'a pas besion de *
}