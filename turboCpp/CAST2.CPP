/*
 * supradefinirea operatorului cast
 */
#include <iostream.h>
class complex; // declaratie incompleta
class pozitie {
	int x,y;
public:
	pozitie(int cord, int ord)
	{
		x = cord;
		y = ord;
		cout<<"Constructor,";
		afisare();
		cout<<'\n';
	}
	pozitie(pozitie &p)
	{
		x = p.x;
		y = p.y;
		cout<<"Constructor copiere,";
		afisare();
		cout<<'\n';
	}
	operator complex(); //prototip operator
	void afisare()
	{
		cout<<" x="<<x;
		cout<<",y="<<y<<'\n';
	}
};

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
	operator float() // conversie complex --> float
	{
		cout<<"Apel float,re="<<re;
		cout<<",im="<<im<<' ';
		return re;
	}
	void afisare()
	{
		cout<<" re="<<re;
		cout<<", im="<<im<<'\n';
	}
	friend pozitie::operator complex();
	const complex& operator=(const double &d)
	{
		re = d;
		im = 0;
		cout<<" Operator complex<=double: ";
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

//definitia functiei operator
pozitie::operator complex()
{
	complex c;
	c.re = x;
	c.im = y;
	return c;
}
void main()
{
	complex c1(1.1,1.1),r;
	pozitie p1(10,10), p2(20,20);
	cout<<'\n';
	r = p1 + p2;
	//complex = pozitie + pozitie
	cout<<"r=";r.afisare();cout<<"\n\n";
	r = p1 + 2.2;
	//complex = pozitie + double;
	cout<<"r=";r.afisare();cout<<'\n';
}