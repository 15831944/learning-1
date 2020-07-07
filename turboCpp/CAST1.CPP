/*
 * supradefinirea operatorului cast
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
};
void fct(float r) // functie de test
{
	cout<<" Apel fct("<<r<<")\n";
}
void main()
{
	complex c1(1,1), c2(2,2);
	float r1 = 0;
	float r2 = 0;
	//1. conversia explicita
	r1 = (float)c1;
	cout<<"r1="<<r1<<'\n';
	//2. convesia implicita de atribuire
	r2 = c2;
	cout<<"r2="<<r2<<'\n';
	//conversie cu transferul parametrilor
	fct(r1);
	//3. apel fara conversie
	fct(c1);
	//4. conversie implicita
	//conversii la evelauarea expresiilor
	//5. converie implicita c1 --> float
	r1 = c1 + r1;
	cout<<"r1="<<r1<<'\n';
	//6. conversie implicite c1 ,c2 --> float
	r2 = c1  + c2;
	cout<<"r2="<<r2<<'\n';
	//7. conversii implicitec2 --> float --> double
	r2 = c2 + 4.55;
	cout<<"r2="<<r2<<'\n';
}