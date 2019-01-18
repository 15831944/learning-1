#include<iostream.h>

int functiamea(int a);
int functiamea(int a,int b);

int main()
{
	int (*fp)(int a,int b);
	fp=functiamea;
	cout<<fp(5,5)<<"\n";
}

int functiamea(int a)
{
	return a;
}
int functiamea(int a,int b)
{
	return a*b;
}