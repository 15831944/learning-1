#include<iostream.h>

class convert
{
protected:
	double val1;
	double val2;
public:
	convert(double i)
	{
		val1=i;
	}
	double daconv() {return val2;}
	double dainit()	{return val1;}
	virtual void calcul()=0;
};
class l_in_g:public convert
{
public:
	l_in_g(double i): convert(i){}
	void calcul()
	{
		val2=val1/3.7854;
	}
};
class f_in_c:public convert
{
public:
	f_in_c(double i):convert(i) {}
	void calcul()
	{
		val2=(val1-32)/1.8;
	}
};
int main()
{
	convert *p;
	l_in_g lgob(4);
	f_in_c fcob(70);
	p=&lgob;
	cout<<p->dainit()<<" litri represent ";
	p->calcul();
	cout<<p->daconv()<<" galons\n";
	p=&fcob;
	cout<<p->dainit()<<" dans Fahrenheit represent ";
	p->calcul();
	cout<<p->daconv()<<" Celsius\n";
}