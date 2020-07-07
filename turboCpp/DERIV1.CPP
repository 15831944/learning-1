/*
 * crearea unei clase derivate
 */
#include <iostream.h>

//clasa pozitie, clasa de baza
class pozitie {
protected:
	int x, y; //coordonate
public:
	pozitie(int=0,int=0); // constructor
	pozitie(pozitie &); // constructor copiere
	~pozitie(); //destructor
	void afisare();
	void deplasare(int,int);
};

//definitii functii membre, clasa pozitie
pozitie::pozitie(int abs, int ord) // constructor
{
	x = abs;
	y = ord;
	cout<<"Constructor "<<this;
	afisare();
}
//constructor copiere
pozitie::pozitie(pozitie &p)
{
	x = p.x;
	y = p.y;
	cout<<"Constructor copiere "<<this;
	afisare();
}
//destructor
pozitie::~pozitie()
{
	cout<<"Destructor "<<this;
	afisare();
}
void pozitie::afisare()
{
	cout<<" pozitie: x="<<x<<",y="<<y<<'\n';
}
void pozitie::deplasare(int dx, int dy)
{
	x += dx;
	y += dy;
}

//clasa punct, derivata din clasa pozitie
class punct : public pozitie
{
	int vizibil; // 0 invizibil
	char culoare; // culoare codificata printr-o litera
public:
	//constuctor
	punct(int=0,int=0,char='A');
	//constructor de copiere
	punct(punct &);
	//destructor
	~punct();
	void arata()
	{
		vizibil = 1;
	}
	void ascunde()
	{
		vizibil = 0;
	}
	void coloreaza(char c)
	{
		culoare = c;
	}
	void afispct();
	void afisare();
	void deplasare(int dx, int dy);
};
void punct::afispct()
{
	cout<<" punct: x="<<x<<",y="<<y;
	cout<<" culoare = "<<culoare<<'\n';
}
//constructor pentru punct
punct::punct(int abs, int ord, char c) : pozitie(abs, ord)
{
	vizibil = 0; //initial invizibil
	culoare = c;
	cout<<"Constructor "<<this;
	afispct();
}

//destructor punct
punct::~punct()
{
	cout<<"Destructor "<<this;
	afispct();
}
/* a se vedea si a doua versiune
punct::punct(punct &pct): pozitie(pct.x,pct.y)
{
	vizibil = pct.vizibil;
	culoare = pct.culoare;
	cout<<"Constructor copiere," << this;
	afispct();
}
*/

punct::punct(punct &pct): pozitie(pct)
{
	vizibil = pct.vizibil;
	culoare = pct.culoare;
	cout<<"Constructor copiere," << this;
	afispct();
}

void punct::afisare()
{
	cout<<" punct: x="<<x<<". y="<<y;
	cout<<" culoare="<<culoare;
	if(vizibil) cout<<" vizibil\n";
	else cout<<" invizibil\n";
}

void punct::deplasare(int dx, int dy)
{
	if(vizibil) {
		cout<<"Deplasare: ";
		afisare(); // apel afisare punct
	}
	x += dx;
	y += dy;
	if(vizibil) {
		cout<<" la coordonatele: ";
		//apel afisare pozitie
		pozitie::afisare();
	}
}
void main()
{
	punct p0,p1(10,10),p2(20,20,'b');
	punct p2_1(30,30,'V');
	punct p3(p2_1);
	punct p;
	p.arata();
	p.deplasare(10,10);
}
