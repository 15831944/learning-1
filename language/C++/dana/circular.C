/*
	Sa se afiseze permutarile circulare dintr-o lista ciculara
*/
#include<iostream.h>
#include<stdio.h>
typedef struct elem
{
	int value;
	elem *urmator;
};
int numere;
elem *inserare_crescatoare(elem *lista,int value)
{
elem *temporar,*baza,*precedent;
int value1;
int flag=0;
	baza=lista;
	temporar=new elem;
	temporar->value=value;
	if(lista==(elem *)NULL)
	{
		temporar->urmator=temporar;
		return(temporar);
	}
	else if(lista->urmator==baza)
	{
		if(lista->value<value)
		{
			temporar->urmator=lista;
			lista->urmator=temporar;
			return(lista);
		}
		else
		{
			temporar->urmator=lista;
			lista->urmator=temporar;
			return(temporar);
		}
	}
	else
	{
		precedent=(elem *)NULL;
		//caut locul de insertie pt lista ordonata crescator
		while(lista->value<value)
		{
			precedent=lista;
			lista=lista->urmator;
			if(lista==baza) break;
		}
		if(precedent==(elem *)NULL)
		{
			temporar->urmator=baza;
			while(lista->urmator!=baza) lista=lista->urmator;
			lista->urmator=temporar;
			return(temporar);
		}
		temporar->urmator=lista;
		precedent->urmator=temporar;
		return(baza);
	}
}

elem *introducere(void)
{
int value;
elem *lista;
int i;

	cout<<"\n Introduceti cite numere aveti=";cin>>numere;cout<<"\n";
	for(i=0;i<numere;i++)
	{
		cout<<"Introduceti valoarea ";fflush(stdout);
		cin>>value;fflush(stdin);
		if(i==0)
		lista=inserare_crescatoare((elem *)NULL,value);
		else
		lista=inserare_crescatoare(lista,value);
	}
	return(lista);
}
void printare(elem *lista)
{
elem *baza;
	baza=lista;
	while(lista->urmator!=baza)
	{
		cout<<"Value="<<lista->value<<"\n";
		fflush(stdout);
		lista=lista->urmator;
	}
	cout<<"Value="<<lista->value<<"\n";fflush(stdout);
}

void distrugere(elem *lista)
{
elem *temporar,*baza;
	baza=lista;
	while(lista->urmator!=baza)
	{
		temporar=lista;
		lista=lista->urmator;
		delete temporar;
	}
}

void permutare(elem *lista)
{
elem *baza;
int i;
	baza=lista;
	cout<<"Permutari circulare\n";fflush(stdout);
	for(i=0;i<numere;i++)
	{
		cout<<"Permutare:";fflush(stdout);
		while(lista->urmator!=baza)
		{
			cout<<lista->value;
			fflush(stdout);
			lista=lista->urmator;
		}
		cout<<lista->value<<"\n";fflush(stdout);
		baza=baza->urmator;
		lista=baza;
	}
}
void main(void)
{
elem *lista;
	lista=introducere();
	cout<<"\n Au fost introduse datele\n";fflush(stdout);
	printare(lista);
	permutare(lista);
	distrugere(lista);
}