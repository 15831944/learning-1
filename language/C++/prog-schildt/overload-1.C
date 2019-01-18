#include<iostream.h>

//abs c'est define in trois variete
int abs(int i);
double abs(double d);
long abs(long l);

int main()
{
	cout<<abs(-10)<<"\n";
	cout<<abs(-11.0)<<"\n";
	cout<<abs(-9L)<<"\n";
}

int abs(int i)
{
	cout<<"l'utilization de abs() pour int\n";
	return i<0?-i:i;
}
double abs(double d)
{
	cout<<"l'utilization de abs() pour double\n";
	return d<0?-d:d;
}
long abs(long l)
{
	cout<<"l'utilization de abs() pour long\n";
	return l<0?-l:l;
}