#include<iostream.h>
template <class X> void inloc(X &a,X &b)
{
	X temp;
	temp=a;
	a=b;
	b=temp;
}
void inloc(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"Dans la function inloc(int &,int &) supraecrit.\n";
}
int main()
{
	int i=10,j=20;
	float x=10.1,y=23.3;
	char a='x',b='z';
	cout<<"i,j originals: "<<i<<" "<<j<<endl;
	cout<<"x,y originals: "<<x<<" "<<y<<endl;
	cout<<"a,b originals: "<<a<<" "<<b<<endl;
	inloc(i,j);
	inloc(x,y);
	inloc(a,b);
	cout<<"i,j inverses: "<<i<<" "<<j<<endl;
	cout<<"x,y inverses: "<<x<<" "<<y<<endl;
	cout<<"a,b inverses: "<<a<<" "<<b<<endl;
}