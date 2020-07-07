/*
 * supradefinirea operatorului cast
 */
#include <iostream.h>
class complex; // declaratie incompleta
class pozitie; //declaratie incompleta
class pozitie {
	int x,y;
public:
	pozitie(int cord, int ord)
	{
		x = cord;
		y = ord;
	}
	pozitie(pozitie &p)
	{
		x = p.x;
		y = p.y;
	}
	operator complex(); //prototip operator
	friend complex::complex(pozitie);
};

class complex {
	//re = partea reala, im = partea imaginara
	float re, im;
public:
	complex(float r=0, float i=0) // construtor
	{
		re = r;
		im = i;
		cout<<"Cosntructor,";
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
	complex(pozitie);
};

//definitia functiei operator
pozitie::operator complex()
{
	complex c;
	c.re = x;
	c.im = y;
	return c;
}

complex::complex(pozitie p)
{
	re = p.x;
	im = p.y;
}
void main()
{
	pozitie p(2,3);
	complex c;
	cout<<"Conversie\n";
	c = p;
	c.afisare();
}