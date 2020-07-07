/* tablouri de obiecte */
#include <iostream.h>
class pozitie {
public:
	int x,y;
	pozitie(int abs, int ord) {
		x = abs;
		y = ord;
		cout<<"Constructor,";
		afisare();
	}
	pozitie() {
		x = 0;
		y = 0;
		cout<<"Constructor,";
		afisare();
	}
	void deplasare(int dx, int dy) {
		x +=dx;
		y +=dy;
	}
	void afisare() {
		cout<<"x="<<x<<",y="<<y<<'\n';
	}
	~pozitie() {
		cout<<"Destructor pozitie\n";
	}
};
class text_poz {
	char *txt;
	pozitie orig;
public:
	text_poz(int abs, int ord, char *c = NULL):orig(abs,ord)
	{
		txt = c;
		cout<<"Constructor text_poz,"<<txt<<'\n';
		orig.afisare();
	}
	~text_poz() {
		cout<<"Destructor text_poz\n";
	}
	void depl_orig(int dx, int dy) {
		orig.deplasare(dx,dy);
		orig.afisare();
	}
};
void main()
{
	cout<<"Incepe main()\n";
	text_poz txt(10,10,"Turbo C++");
	txt.depl_orig(5,5);
	cout<<"New tests\n";
	pozitie p(1,1), *pptr;
	int pozitie::* xptr;
	int pozitie::* yptr;
	void (pozitie:: *fptr)(int,int);
	pptr = &p;
	xptr = &pozitie::x;
	yptr = &pozitie::y;
	fptr = &pozitie::deplasare;
	(p.*fptr)(10,10);
	cout<<"Noua pozitie este: ";
	cout<<'('<<p.*xptr;
	cout<<", "<<p.*yptr<<")\n";
	(pptr->*fptr)(10,10);
	cout<<"Noua pozitie este: ";
	cout<<'('<<pptr->*xptr;
	cout<<", "<<pptr->*yptr<<")\n";
	cout<<"Final main()\n";
}
