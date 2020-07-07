/*
 * supradefinirea operatorului cast si altii
 */
#include <iostream.h>

class complex {
	//re = partea reala, im = partea imaginara
	float re, im;
public:
	complex(float r=0, float i=0) // construtor
	{
		re = r;
		im = i;
		cout<<"Constructor,";
		afisare();
	}
	complex(complex & c) //constructor copiere
	{
		re = c.re;
		im = c.im;
		cout<<"Constructor, copiere ";
		afisare();
	}
/* ambuitate
	operator float() // conversie complex --> float
	{
		cout<<"Apel float,re="<<re;
		cout<<",im="<<im<<' ';
		return re;
	}
	*/
	void afisare()
	{
		cout<<" re="<<re;
		cout<<", im="<<im<<'\n';
	}
	const complex& operator=(const double &d)
	{
		re = d;
		im = 0;
		cout<<" Op=cmplex<-double: ";
		afisare();
		cout<<'='<<d<<'\n';
		return *this;
	}
	friend complex operator+(complex, complex);
};

complex operator+(complex a, complex b)
{
	cout<<" Op+complex.";
	a.afisare();
	cout<<" + ";
	b.afisare();
	cout<<'\n';
	return complex(a.re+b.re,a.im+b.im);
}
void main()
{
	complex c(1.1,1.1),r;
	cout <<'\n';
	r=1.5;
	cout<<"r=";r.afisare();cout<<"\n\n";
	r = c + 2.2;
	cout<<"r=";r.afisare(); cout<<"\n\n";
	r = 2.2 + c;
	cout<<"r=";r.afisare(); cout<<"\n";
}