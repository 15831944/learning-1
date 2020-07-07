/*
 * transferul prin valoare, obiecte temporare
 */
#include <iostream.h>
class pozitie {
	int x,y; //coordonate
public:
	pozitie(int=0,int=0);//constructor
	pozitie(pozitie &);//constructor de copiere
	~pozitie(); //destructor
	void deplasare(int,int); //deplasare relativa
	void afisare();
};
//definitii functii membre
//constructor
pozitie::pozitie(int abs, int ord)
{
	x = abs;
	y = ord;
	cout<<"Constructor, "<<this;
	afisare();
}
//constructor copiere
pozitie::pozitie(pozitie &c)
{
	x = c.x;
	y = c.y;
	cout<<"Constructor copiere,"<<this;
	afisare();
}
//destructor
pozitie::~pozitie()
{
	cout<<"Destructor,"<<this;
	afisare();
}
void pozitie::afisare()
{
	cout<<" x="<<x<<",y="<<y<<'\n';
}
void pozitie::deplasare(int abs, int ord)
{
	x+=abs;
	y+=ord;
}
//definitie functie de test
pozitie tst(pozitie p)
{
	cout<<"Apel tst()\n";
	p.deplasare(10,10);
	return p;
}

void main()
{
	cout<<"Incepe main()\n";
	pozitie p0,p1(1,1);
	{
		p0=tst(p1);
		p0.afisare();
	}
	p0.deplasare(10,10);
	cout<<"Final main()\n";
}