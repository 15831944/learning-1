#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
	//ultimul=(primul+nrcrt) modulo N
	int tab[N];	//tabloul de date
	int nrcrt;	//numarul curent din lista
	int prim;	//primul element din lista
} fifo;


//functia de initializare
void init(fifo *ls)
{
	ls->nrcrt=ls->prim=0;
}

//functia de testare (daca este vida)
int nl_vida(fifo *ls)
{
	return (ls->nrcrt>0);
}

//functia de testare (daca este plina)
int nl_plina(fifo *ls)
{
	return (ls->nrcrt<N);
}

//functia de adaugare
int adaug(fifo *ls,int k)
{
	if(nl_plina(ls))
	{
		//adaug in coada
		(ls->tab)[(ls->prim+ls->nrcrt)%N]=k;
		//incrementez numarul de elemente
		(ls->nrcrt)++;
		//afisez de test numarul de elemente
		printf("Nr de elemente din coada este %d.\n",ls->nrcrt);
		return 1;
	}
	else
	{
		printf("Coada este plina.\n");
		return 0;
	}
}

//functia de extragere
//int extrag(fifo *ls,int *k)	//cind returneaza functioneaza
int extrag(fifo *ls)
{

	if(nl_vida(ls))
	{
		//extrag din coada
//		k=(int *)(ls->tab)[ls->prim];
		//updatez primul element
		ls->prim=(ls->prim+1)%N;
		//decrementez nr de elemente din coada
		ls->nrcrt--;
		//afisez de test
		printf("Nr de elemente din coada este %d.\n",ls->nrcrt);
		//extrag din coada
	        return	(ls->tab)[(ls->prim-1)%N];
//		return 1;
	}
	else
	{
		printf("Coada este vida.\n");
		return 0;
	}
}

int main(void)
{
	int i;
	int k=1;  
	fifo l;
	fifo *lp;
	//initializez coada
	init(&l);
	//initializez o coada dinamica
	lp=malloc(sizeof(fifo));
	//intializez coada dinamica
	init(lp);
	//verific daca coada este goala !!! de ce trebuie
	printf("Extrag din coada l.\n");
//	extrag(&l,&k); //varianta aceasta nu fuctioneaza
	k=extrag(&l);
	//introduc in coada 3 elemente
	printf("Introduc in coada 3 elemente.\n");
	for(i=0;i<3 && nl_plina(lp);i++)
	{
		printf("%d\n",10+i);
		adaug(lp,10+i);
	}
	printf("Coada are:\n");
	for(i=0;i<3;i++) printf("%d\n",lp->tab[i]);
	printf("Extrag toate elementele din lp.\n");
	while(nl_vida(lp))
	{
//		extrag(lp,&k);	//varianta aceasta nu functioneaza
		k=extrag(lp);
		printf("%d\n",k);
	}
	//elimin coada dinamica
	free(lp);
}