#include<iostream.h>

class putere
{
	double b;
	int e;
	double val;
public:
	putere(double baza,int exp);
	double da_put() {return this->val;}
};
putere::putere(double baza,int exp)
{
	b=baza;
	e=exp;
	this->val=1;
	if(exp==0) return;
	for(;exp>0;exp--) val=val*b;
}
int main()
{
	putere x(4.0,2),y(2.5,1),z(5.7,0);
	cout<<x.da_put()<<" ";
	cout<<y.da_put()<<" ";
	cout<<z.da_put()<<"\n";
}