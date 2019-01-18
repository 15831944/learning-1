//problema 1 de la pagina 100
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
typedef struct element
{
	char cod[10];
	unsigned long nr_lei;
};
element *pret,minim,maxim;
int main(void)
{
int nr_produse,i;
	cout<<"\n Introduceti cite produse aveti.\n";
	cin>>nr_produse;
	pret=(element *)calloc(nr_produse,sizeof(element));
	if(pret==(element *)NULL)
	{
		cout<<"Eroare de alocare memorie pentru catalog.\n";
		exit(1);
	}
	cout<<"Intoduceti elementele\n";
	for(i=0;i<nr_produse;i++)
	{
		cout<<"Codul ";
		cin>>pret[i].cod;
		cout<<"Pretul ";
		cin>>pret[i].nr_lei;
	}
	strcpy(minim.cod,pret[0].cod);
	minim.nr_lei=pret[0].nr_lei;
	maxim.nr_lei=pret[0].nr_lei;
	strcpy(minim.cod,pret[0].cod);
	for(i=0;i<nr_produse;i++)
	{
		if(pret[i].nr_lei<minim.nr_lei)
		{
			strcpy(minim.cod,pret[i].cod);
			minim.nr_lei=pret[i].nr_lei;
		}
		if(pret[i].nr_lei>maxim.nr_lei)
		{
			strcpy(maxim.cod,pret[i].cod);
			maxim.nr_lei=pret[i].nr_lei;
		}
	}
	cout<<"Minimul este elementul cu codul "<<minim.cod<<" si valoarea "<<minim.nr_lei<<"\n";
	cout<<"Maximul este elementul cu codul "<<maxim.cod<<" si valoarea "<<maxim.nr_lei<<"\n";
	free(pret);
	exit(0);
}