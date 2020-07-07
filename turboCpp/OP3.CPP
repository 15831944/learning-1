/*
 * programul ilustreaza declararea si unctionarea constructurilor si
 * destructorilor si pun in evidenta momentele in care acestia se apeleaza
 * prin afisarea unor mesaje la consola
 * cosntructorul de copiere este implementat deoarece avem alocare dinamica
 * daca era alocare statica nu trebuia de definit
 */
#include <iostream.h>
//lista FIFO de nmax numere intregi
class fifo {
	int nmax; //dimensiunea listei
	int *tab; //adresa tabloului listei
	int ncrt; //numarul curent de elemente din lista
	int prim; // indexul primului element din lista
public:
	fifo(int); // constructor 1
	fifo(); // constructor 2
	fifo(fifo &); //constructor de copiere
	~fifo(); //destructor
	//adauga element la sfirsit
	int adaug(int);
	//extrage primul element
	int extrag(int&);
	//functii inline
	//not lista vida
	int nl_vida()
	{
		return ncrt >0; // ncrt == 0 -> lista vida
	}
	//not lista plina
	int nl_plina()
	{
		return ncrt < nmax; // ncrt == nmax -> lista plina
	}
	const fifo& operator=(const fifo&);
};
//definitiile functiilor membre ale clasei fifo
//constructor 1, lista de n elemente
fifo::fifo(int n)
{
	nmax = n;
	tab = new int[n];
	ncrt=prim = 0;
	cout<<"Constructor 1, lista de "<<nmax<<" elemente\n";
}
//constructor 2 implicit
fifo::fifo()
{
	//lista de 100 elemente
	nmax = 100;
	tab = new int[100];
	ncrt = prim = 0;
	cout<<"Constructor 2, lista de 100 elemente\n";
}
//constuctor de copiere
fifo::fifo(fifo &inl)
{
	nmax = inl.nmax;
	prim = inl.prim;
	tab=new int[nmax];
	int i = prim;
	for(ncrt = 0; ncrt <inl.ncrt;i = (i+1)%nmax,ncrt++)
		tab[i]=inl.tab[i];
	cout<<"Constructor de copiere , lista de "<<nmax<<" elemente\n";
}
//destructor
fifo::~fifo()
{
	cout<<"Destructor, lista de "<<nmax<<" elemente\n";
	delete tab;
}

int fifo::adaug(int k)
{
	if(nl_plina()) {
		tab[(prim+ncrt) %nmax] = k;
		ncrt++;
		cout<<"Lista are "<< ncrt<< " elemente\n";
		return 1;
	}
	else {
		cout<<"Lista plina !\n";
		return 0;
	}
}

int fifo::extrag(int &k)
{
	if(nl_vida()) {
		k = tab[prim];
		prim = (prim +1) %nmax;
		ncrt--;
		cout<<"Lista are "<<ncrt<<" elemente\n";
		return 1;
	}
	else {
		cout<<"Lista vida !\n";
		return 0;
	}
}

const fifo& fifo::operator=(const fifo& la)
{
	cout<<this<<"Operator=,\n";
//	cout<<la<<"\n";
	if(this != &la) {
		nmax = la.nmax;
		prim = la.prim;
		delete tab;
		tab = new int[nmax];
		cout<<"new: "<<tab<<'\n';
		int i=prim;
		for(ncrt = 0; ncrt < la.ncrt; ncrt++) {
			tab[i] = la.tab[i];
			i=(i+1)%nmax;
		}
	}
	return *this;
}
void main()
{
	fifo la1(10), la2(20), la3(20);
	la1 = la1; // atribuire fara efecturarea nici unei operatii
	la3 = la2 = la1;
}
