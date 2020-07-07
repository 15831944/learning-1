/*
 * functii prietene
 */
#include <iostream.h>
class pozitie; //declare incompleta necesara pt clasa print
class print {
public:
	// nu merg functii inline deoarece nu se cunosc variabilele clasei
	void afiseaza(pozitie &p);
};
class pozitie {
	int x,y;
public:
	pozitie(int abs,int ord) {
		x = abs;
		y = ord;
		cout<<"Constructor "<<this<<'\n';
	}
	~pozitie() {
		cout<<"Destructor "<<this<<'\n';
	}
	void deplasare(int dx, int dy) {
		x +=dx;
		y +=dy;
	}
	//functie prietena
	friend int coincid(pozitie &, pozitie &);
	friend void print::afiseaza(pozitie &);
};

void print::afiseaza(pozitie &p)
{
	cout<<"Pozitie x="<<p.x<<",y="<<p.y<<'\n';
}

int coincid(pozitie &p1, pozitie &p2)
{
	if(p1.x == p2.x && p1.y == p2.y) return 1;
	else return 0;
}

void main()
{
	pozitie p1(1,2);
	pozitie p2(1,2);
	if (coincid(p1,p2) == 1)
		cout<<"Coincid p1 si p2\n";
	else
		cout<<"Nu coincid p1 si p2\n";
	p2.deplasare(2,3);
	if (coincid(p1,p2) == 1)
		cout<<"Coincid p1 si p2\n";
	else
		cout<<"Nu coincid p1 si p2\n";
	print pr;
	pr.afiseaza(p2);
}
