#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct elem{
			elem *prec;
			char *nume;};
int i,j,test,total;
elem *virf,*virf1,*temporar,*baza,*baza1,*output;
char *temporarchar;
void introducere(void)
{
	total=0;
	for(i=0;i<2;i++)
	{
		if(i==0)
		{
			cout<<"Dati autorii de la A la F in ordine pentru oprire introduceti 0";
			cout<<"Citi autori aveti";
			cin>>test;
			total+=test;
		}
		if(i==1)
		{
			cout<<"Dati autorii de la G la P in ordine pentru oprire introduceti 0";
			cout<<"Citi autori aveti";
			cin>>test;
			total+=test;
		}
		if(i==0)
		{
		      virf=new elem;

		      cin>>virf->nume;
		      virf->prec=(elem *)NULL;
		      baza=virf;
		}
		else
		{
			virf1=new elem;
			cin>>virf1->nume;
			virf1->prec=(elem *)NULL;
			baza1=virf1;
		}
		for(j=1;j<test;j++)
		{
			temporar=new elem;
			if(i==0)
			{
			      temporar->prec=virf;
			      virf=temporar;
				temporarchar=(char *)calloc(128,sizeof(char));
				virf1->nume=temporarchar;
			      cin>>virf->nume;
			}
			else
			{
				temporar->prec=virf1;
				virf1=temporar;
				temporarchar=(char *)calloc(128,sizeof(char));
				virf1->nume=temporarchar;
				cin>>virf1->nume;
			}
		}
	}
}
void printare(elem *inceput)
{
int flag;
	flag=0;
       while(flag==0)
       {
		cout<<inceput->nume;cout<<"\n";
		if(inceput->prec==(elem *)NULL) flag=1;
		temporar=inceput;
		inceput=inceput->prec;
		free(temporar->nume);
		delete temporar;
       }
}
void inversare(elem *inceput)
{
int flag;
elem *temporar1;
	flag=0;
	j=0;
       while(flag==0)
       {
		temporar1=new elem;
		if(j==0) temporar1->prec=(elem *)NULL;
		else temporar1->prec=output;
		output=temporar1;
		output->nume=inceput->nume;
		if(inceput->prec==(elem *)NULL) flag=1;
		temporar=inceput;
		inceput=inceput->prec;
		delete temporar;
		j++;
       }

}
void main(void)
{
	introducere();
	baza1->prec=virf;
	inversare(virf1);
	cout<<"Stiva \n";
	printare(output);
}