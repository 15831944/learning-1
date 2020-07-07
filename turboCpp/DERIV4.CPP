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
	virtual void afisare();
	virtual void deplasare(int,int);
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
	cout<<"Constructor copiere ";
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
	cout<<" pozitie: "<<this<<" x="<<x<<",y="<<y<<'\n';
}
void pozitie::deplasare(int dx, int dy)
{
	cout<< "pozitie: "<<this<<'\n';
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
	void afisare();
	void deplasare(int dx, int dy);
};
//constructor pentru punct
punct::punct(int abs, int ord, char c) : pozitie(abs, ord)
{
	vizibil = 0; //initial invizibil
	culoare = c;
	cout<<"Constructor "<<this;
	afisare();
}

//destructor punct
punct::~punct()
{
	cout<<"Destructor "<<this;
	afisare();
}
/* a se vedea si a doua versiune
punct::punct(punct &pct): pozitie(pct.x,pct.y)
{
	vizibil = pct.vizibil;
	culoare = pct.culoare;
	cout<<"Constructor copiere," << this;
	afisare();
}
*/

punct::punct(punct &pct): pozitie(pct)
{
	vizibil = pct.vizibil;
	culoare = pct.culoare;
	cout<<"Constructor copiere,";
	afisare();
}

void punct::afisare()
{
	cout<<" punct: "<<this<<" x="<<x<<". y="<<y;
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
	pozitie poz(1,1), *ppoz = &poz;
	punct pct1(5,5,'R'), *ppct=&pct1;
	ppoz -> afisare();
	ppct -> afisare();
	ppoz = ppct;
	ppoz -> afisare();
	ppoz -> deplasare(4,4);
}
