/* obiecte constante */
#include <iostream.h>

class pozitie {
	int x,y; //coordonate
public:
	pozitie(int abs=0,int ord=0) {
		x = abs;
		y = ord;
	}
	pozitie(pozitie &in) {
		x = in.x;
		y = in.y;
	}
	~pozitie() {
	}
	void afisare() const;//functie constanta
	void deplasare(int,int);
};
void pozitie::afisare() const
{
	cout<<" x="<<x<<",y="<<y<<'\n';
}
void pozitie::deplasare(int dx, int dy)
{
	x +=dx;
	y +=dy;
}
void main()
{
	const pozitie p1; // obiect constant
	//pointer la obiect constant
	const pozitie *pp = &p1;
	pozitie p2;
	p1.afisare(); //corect;
	p1.deplasare(10,10); // avertisment functie neconstanta
	p1.afisare();
	pp->deplasare(10,10); //avertisment functie neconstanta
	pp->afisare();
}