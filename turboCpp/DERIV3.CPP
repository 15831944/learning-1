/*
 * derivare multipla
 */
#include <iostream.h>
#include <string.h>

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
	x += dx;
	y += dy;
}
class string {
protected:
	int ncar; // lingimea sirului
	char *str; //adresa sirului
public:
	//constructori
	string(int n = 0)
	{
		ncar = n;
		str = new char[n+1];
		str[0] = 0;
		cout<<"Constructor 1 ";
		afisare();
	}
	string(char *s)
	{
		ncar = strlen(s);
		str = new char[ncar +1];
		strcpy(str,s);
		cout<<"Constructor 2 ";
		afisare();
	}
	string(string &s)
	{
		ncar = s.ncar;
		str = new char[ncar+1];
		strcpy(str,s.str);
		cout<<"Constructor copiere ";
		afisare();
	}
	//destructor
	~string()
	{
		cout<<"Destructor ";
		afisare();
		delete str;
	}
	void afisare()
	{
		cout<<"string: "<<str<<'\n';
	}
};
//clasa strpoz derivata din string si pozitie
class strpoz : public pozitie,public string
{
	char culoare;
public:
//constructori
	strpoz(int abs, int ord, int n=0, char c='A'): pozitie(abs,ord),string(n)
	{
		culoare = c;
		cout<<"Constructor 2 ";
		afisare();
	}
	strpoz(int abs, int ord, char *s, char c='A') : pozitie(abs, ord),string(s)
	{
		culoare =c ;
		cout<<"Constructor 2 ";
		afisare();
	}
	strpoz(strpoz &sp) : pozitie(sp),string(sp)
	{
		culoare = sp.culoare;
		cout<<"Constructor copiere ";
		afisare();
	}
	//destructor
	~strpoz()
	{
		cout<<"Destructor ";
		afisare();
	}
	//functii membre
	void coloreaza(char c)
	{
		culoare = c;
	}
	void afisare()
	{
		cout<<"strpoz: "<<str;
		cout<<",x="<<x<<",y="<<y;
		cout<<",culoare="<<culoare<<'\n';
	}

};

void main()
{
	strpoz sp1(5,5,"TEXT");
	sp1.afisare();
	strpoz sp2(sp1);
	sp2.afisare();
}