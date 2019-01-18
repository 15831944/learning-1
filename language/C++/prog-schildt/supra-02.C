#include<iostream.h>

int functiamea(int i);	//cette il differe de numero de parametre
int functiamea(int i,int j);

int main()
{
	cout<<functiamea(10)<<" ";
	cout<<functiamea(4,5)<<"\n";
}

int functiamea(int i)
{
	return i;
}

int functiamea(int i,int j)
{
	return i*j;
}