#include<iostream.h>

void schimb(int &i,int &j);
int main()
{
	int a,b,c,d;
	a=1;
	b=2;
	c=3;
	d=4;
	cout<<"a et b: "<<a<<" "<<b<<"\n";
	schimb(a,b);
	cout<<"a et b: "<<a<<" "<<b<<"\n";
	cout<<"c et d: "<<c<<" "<<d<<"\n";
	schimb(c,d);
	cout<<"c et d: "<<c<<" "<<d<<"\n";
}
void schimb(int &i,int &j)
{
	int t;
	t=i;
	i=j;
	j=t;
}