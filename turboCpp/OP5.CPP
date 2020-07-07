/*
 * programul ilustreaza declararea si unctionarea constructurilor si
 * destructorilor si pun in evidenta momentele in care acestia se apeleaza
 * prin afisarea unor mesaje la consola
 * cosntructorul de copiere este implementat deoarece avem alocare dinamica
 * daca era alocare statica nu trebuia de definit
 * suprascierea operatorilor new si delete
 */
#include <iostream.h>
#include <conio.h>
//lista FIFO de nmax numere intregi
class fifo {
	int nmax; //dimensiunea listei
	int *tab; //adresa tabloului listei
	int ncrt; //numarul curent de elemente din lista
	int prim; // indexul primului element din lista
	static int cnt; /// contor de obiecte dinamice
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
	int& operator[](int);
	void *operator new(size_t);
	void operator delete(void*);
};
//definitiile functiilor membre ale clasei fifo
//constructor 1, lista de n elemente
fifo::fifo(int n)
{
	nmax = n;
	tab = new int[n];
	ncrt=prim = 0;
	cout<<"Constructor 1, lista de "<<nmax<<" elemente\n";
	cnt++;
}
//constructor 2 implicit
fifo::fifo()
{
	//lista de 100 elemente
	nmax = 100;
	tab = new int[100];
	ncrt = prim = 0;
	cout<<"Constructor 2, lista de 100 elemente\n";
	cnt++;
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
	cnt++;
}
//destructor
fifo::~fifo()
{
	cout<<"Destructor, lista de "<<nmax<<" elemente\n";
	delete tab;
	cnt--;
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

//suprascriere operator =
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

//suprascrierea operator []
int& fifo::operator[](int n)
{
	return tab[(prim+n)%nmax];
}

void* fifo::operator new(size_t dim)
{
	cnt++;
	//incrementarea contorul
	cout<<"new: cnt="<<cnt<<'\n';
	return new char[dim];
}
void fifo::operator delete(void* p)
{
	//decrementeaza contorul de obiecte dinamice
	cnt--;
	cout<<"new:cnt ="<<cnt<<'\n';
	delete p;
}

int fifo::cnt; // definitie/initializare cnt =0

void main()
{
	clrscr();
	fifo *lp1, *lp2, *lp3;
	lp1 = new fifo(10);
	//initializare prin copiere
	lp2 = new fifo(*lp1);
	// operator new predefinit
	lp3=::new fifo(20);
	delete lp1;
	delete lp2;
	// operator delete predefinit
	::delete lp3;
}
