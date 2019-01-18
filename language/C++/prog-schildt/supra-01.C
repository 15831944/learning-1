#include<iostream.h>

int functiamea(int i);			//la premier function
double functiamea(double i);//la seconde function

int main()
{
	cout<<functiamea(10)<<" "; //il apelle la premier function 
	cout<<functiamea(5.4)<<"\n";//il apelle la seconde function
}

double functiamea(double i)
{
	return i;
}
int functiamea(int i)
{
	return i;
}