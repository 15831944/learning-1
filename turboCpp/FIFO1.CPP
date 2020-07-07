/*
 * class fifo implementarea unei liste fifo de 100 intregi
 */
#include <iostream.h>

//lista FIFO de 100 numere intregi
class fifo { //in loc de class se poate utiliza struct dar nu este recomandat
	// declaratii cu access implicit privat
	int tab[100]; //tabloul de 100 elemente
	int ncrt; //numarul curent de elemente din lista
	int prim; // indexul primului element din lista
public:
	//declarratii cu access public
	int adaug(int); //adauga un element la sfirsit
	int extrag(int&); //extrage primul element
	//functii inline
	void init() // initializare
	{
		ncrt = prim = 0;
	}
	int nl_vida() // not lista vida
	{
		return ncrt > 0; // ncrt == 0 -> lista vida
	}
	int nl_plina() // not lista plina
	{
		return ncrt < 100; // ncrt == 100 -> lista plina
	}
};

int fifo::adaug(int k)
{
	if(nl_plina()) {
		tab[(prim+ncrt)%100] = k;
		ncrt++;
		cout << "Lista are "<< ncrt << " elemente\n";
		return 1;
	}
	else {
		cout << "Lista plina !\n";
		return 0;
	}
}

int fifo::extrag(int &k)
{
	if(nl_vida()) {
		k = tab[prim];
		prim = (prim +1) %100;
		ncrt--;
		cout << "Lista are "<<ncrt<<"elemente \n";
		return 1;
	}
	else {
		cout << "Lista vida !\n";
		return 0;
	}
}

void main()
{
	int i;
	fifo ls; // ls ese un obiect din clasa fifo
	fifo *lp; // lp este pointer de obiecte fifo
	lp = new fifo; //creare obiect dinamic fifo
	ls.init(); // initializare ls
	lp -> init() ; // initializare lp
	cout << "Adauga un element la ls\n";
	if(ls.nl_plina()) {
		cout << i << '\n';
		ls.adaug(i);
	}
	cout << "Elimina un element din ls\n";
	if(ls.nl_vida()) {
		ls.extrag(i);
		cout << i << '\n';
	}
	cout<< "Adaug la lista ls 3 elemente\n";
	for(i=0;i <3 && ls.nl_plina();i++) {
		cout<<10+i;
		ls.adaug(10+i);
	}
	cout<<"Extrage din lista lp";
	lp->extrag(i); //arata c alp este vida
	cout << "Atribuire *lp=ls\n";
	*lp=ls;
	cout<<"Extrage toate elementele din lp\n";
	while(lp -> nl_vida()) {
		lp -> extrag(i);
		cout<<i<<"\n";
	}
	delete lp; //elimina obiectul dinamic  ??? acum pointerul este la ls
}