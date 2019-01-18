#include<iostream.h>
template<class tip1,class tip2>
void funcmea(tip1 x,tip2 y)
{
	cout<<x<<" "<<y<<endl;
}
int main()
{
	funcmea(10,"hi");
	funcmea(0.23,12L);
}