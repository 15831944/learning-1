/*
 * transferul prin valoare, obiecte temporare, metode statice
 */
#include <iostream.h>
class pozitie {
static int cnt; //date statice private, contor de obiecte
	int x,y; //coordonate
public:
	pozitie(int=0,int=0);//constructor
	pozitie(pozitie &);//constructor de copiere
	~pozitie(); //destructor
	void deplasare(int,int); //deplasare relativa
	void afisare();
	//fucntie membra statica
	static void nr_obj();
};
//definitii functii membre
//constructor
pozitie::pozitie(int abs, int ord)
{
	x = abs;
	y = ord;
	cout<<"Constructor, "<<this;
	afisare();
	cnt++;
	nr_obj();
}
//constructor copiere
pozitie::pozitie(pozitie &c)
{
	x = c.x;
	y = c.y;
	cout<<"Constructor copiere,"<<this;
	afisare();
	cnt++;
	nr_obj();
}
//destructor
pozitie::~pozitie()
{
	cout<<"Destructor,"<<this;
	afisare();
	cnt--;
	nr_obj();
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
//afisare numar de obiecte
void pozitie::nr_obj()
{
	cout<<" Numarul curent de obiecte: "<<cnt<<'\n';
}

//definitie functie de test
void fct(int i, int j)
{
	cout<<"Incepe fct("<<i<<","<<j<<")\n";
	pozitie p(i,j);
	cout<<"Final fct("<<i<<","<<j<<")\n";
}
//definire si initializare cu 0, contor static
int pozitie::cnt;
void main()
{
	cout<<"Incepe main()\n";
	//apelare functie membra satatica
	pozitie::nr_obj();
	//p= obiect local, automatic
	pozitie p(1,0);
	fct(10,0);
	cout<<"Final main()\n";
}