/*
 * fisierul fifo.cpp
 * definitiile functiilor membre ale clasei fifo,
 * declarata in fisierul fifo.h
*/
#include <iostream.h>
#include "fifo.h" // pentru fifo.h in directorul curent

fifo::fifo(int n) // lista de n elemente
{
	nmax=n;
	tab = new int[n];
	ncrt = prim = 0;
	cout<<"Constructor, lista de "<<nmax<<" elemente\n";
}

fifo::fifo(fifo &inl) // constructor de copiere
{
	nmax = inl.nmax;
	prim = inl.prim;
	tab = new int[nmax];
	int i = prim;
	for (ncrt = 0; ncrt < inl.ncrt; i = (i+1) %nmax, ncrt++)
		tab[i] = inl.tab[i];
	cout<<"Constructor copiere, lista de "<<nmax<<" elemente\n";
}
fifo::~fifo() // destructor
{
	cout<<"Destructor, lista de "<<nmax<<" elemente\n";
	delete tab;
}
int fifo::adaug(int k) // adauga k la lista
{
	if(nl_plina()) {
		tab[(prim+ncrt)%nmax] = k;
		ncrt++;
		cout<<"Lista are "<<ncrt<<" elemente\n";
		return 1;
	}
	else {
		cout<<"Lista plina !\n";
		return 0;
	}
}
int fifo::extrag(int &k) // extrage din lista
{
	if(nl_vida()) {
		k = tab[prim];
		prim = (prim +1)%nmax;
		ncrt--;
		cout<<"Lista are "<<ncrt<<" elemente\n";
		return 1;
	}
	else {
		cout<<"Lista vida !\n";
		return 0;
	}
}
