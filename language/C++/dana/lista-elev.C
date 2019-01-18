#include<iostream.h>
#include<stdio.h>
#define NOTE 3
FILE *fp;
int numar;
typedef struct date_elev
{
	char nume[20];
	char prenume[20];
	float note[NOTE];
};
typedef struct elem
{
	date_elev date;
	elem *urmator;
};
float medief(elem *lista)
{
float medie=0;
int i;
	for(i=0;i<NOTE;i++)
		medie+=lista->date.note[i];
	return (medie/NOTE);
}
elem *adaug(elem *lista)
{
elem *temporar;
elem *baza;
int i;
	temporar=new elem;
	baza=lista;
	if(baza!=(elem *)NULL)
	{
		while(lista->urmator!=(elem *)NULL)
			lista=lista->urmator;
		//am gasit capatul listei
		lista->urmator=temporar;
	}
	cout<<"Introduceti numele ";cin>>temporar->date.nume;
	cout<<"Introduceti prenumele ";cin>>temporar->date.prenume;
	cout<<"Introduceti cele trei note ";
	for(i=0;i<NOTE;i++)
		cin>>temporar->date.note[i];
	temporar->urmator=(elem *)NULL;
	if(baza!=(elem *)NULL)	return baza;
	else return(temporar);
}
void distrugere(elem *lista)
{
elem *temporar;
	while(lista->urmator!=(elem *)NULL)
	{
		temporar=lista;
		lista=temporar->urmator;
		delete temporar;
	}
	delete lista;
}
void schimbare(int first,int second,elem *lista)
{
elem *elem1,*elem2,*temporar;
int i,flag;
	elem1=elem2=lista;
	for(i=0;i<(first-1);i++)
		elem1=elem1->urmator;
	for(i=0;i<(second-1);i++)
		elem2=elem2->urmator;
	temporar=elem1->urmator;
	//refac legatura 1
	elem1->urmator=elem2->urmator;
	//refac legatura 3
	elem2->urmator=temporar;
	//refac legatura 2
	temporar=elem1->urmator->urmator;
	elem1->urmator->urmator=elem2->urmator->urmator;
	//refac legatura 3
	elem2->urmator->urmator=temporar;
}

elem *introducere(void)
{
int i;
int flag=0;
elem *temporar;
	while(flag==0)
	{
		cout<<"Introduceti citi elevi aveti ";cin>>numar;
		if((numar==0)||(numar<0))
		{
			flag=0;
			cout<<"Ati introdus un numar invalid\n";
		}
		else flag=1;
	}
	temporar=adaug((elem *)NULL);
	for(i=1;i<numar;i++)
		temporar=adaug(temporar);
	return(temporar);
}
void afisare(elem *lista)
{
int flag=0;
	while(flag==0)
	{
		cout<<"nume="<<lista->date.nume<<"\n";
		cout<<"prenume="<<lista->date.prenume<<"\n";
		cout<<"note="<<lista->date.note[0]<<" "<<lista->date.note[1]<<" "<<lista->date.note[2]<<"\n";
		lista=lista->urmator;
		if(lista==(elem *)NULL) flag=1;
	}
}
void afisare_medie9(elem *lista)
{
float prag;
int flag;
float medie;
	cout<<"Introduceti pragul de selectie ";cin>>prag;
	flag=0;
	while(flag==0)
	{
		medie=medief(lista);
		if(medie>=prag)
		{
			cout<<"Numele:"<<lista->date.nume<<"\n";
			cout<<"Prenumele:"<<lista->date.prenume<<"\n";
		}
		if(lista->urmator==(elem *)NULL) flag=1;
		lista=lista->urmator;
	}
}

void afisare_medie(elem *lista)
{
float medie1;
float medie;
int flag;
int i;
	flag=0;
	medie=0;
	i=0;
	while(flag==0)
	{
		medie1=medief(lista);
		medie+=medie1;
		i++;
		cout<<"Numele:"<<lista->date.nume<<"\n";
		cout<<"Prenumele:"<<lista->date.prenume<<"\n";
		cout<<"Medie:"<<medie1<<"\n";
		if(lista->urmator==(elem *)NULL) flag=1;
		lista=lista->urmator;
	}
	cout<<"Media generala:"<<medie/i<<"\n";
}



elem  *consecutiv(elem *lista,int pozitie)
{
elem *temporar,*baza;
int flag,i;
	baza=lista;
	if(pozitie==0)
	{
		//elementul din pozitie
		temporar=lista;
		//elementul din pozitie+1
		lista=lista->urmator;
		//elementul din pozitie
		temporar->urmator=lista->urmator;
		lista->urmator=temporar;
		return(lista);
	}
	else
	{	for(i=0;i<(pozitie-1);i++)
			lista=lista->urmator;
		//elementul din pozitie
		temporar=lista->urmator;
		lista->urmator=temporar->urmator;
		//elementul din pozitie+1
		lista=lista->urmator;
		//elementul din pozitie
		temporar->urmator=lista->urmator;
		lista->urmator=temporar;
		return(baza);
	}
}
elem *consecutiv1(elem *lista)
{
elem *temporar;
	temporar=lista;
	//primul element schimbat
	lista=lista->urmator;
	//al doilea element
	temporar->urmator=lista->urmator;
	lista->urmator=temporar;
	return(lista);
}
elem *sortare_descrescatoare(elem *lista)
{
int i,j;
elem *baza,*temporar;
	baza=temporar=lista;
	for(i=0;i<numar;i++)
	{
		j=0;
		lista=baza;
		while(j<(numar-1-i))
		{
			if(medief(lista)<medief(lista->urmator))
			{
				if(j==0)
					baza=lista=consecutiv1(lista);
				else
				{
					lista=consecutiv1(lista);
					temporar->urmator=lista;
				}
			}
			temporar=lista;
			lista=lista->urmator;
			j++;
		}
	}
	return (baza);
}
int afisare_concurs(elem *lista)
{
int locuri;
int i;
int flag;
elem *temporar;
	cout<<"Introduceti nr de locuri";fflush(stdout);
	cin>>locuri;
	i=0;
	flag=0;
	while(flag!=1)
	{
		if((lista->urmator==(elem *)NULL))
		{
			i++;
			cout<<lista->date.nume<<"\n"<<lista->date.prenume<<"\n media="<<medief(lista)<<"\n";
			return(i);
		}
		if(i<(locuri+1))
		{
			i++;
			cout<<lista->date.nume<<"\n"<<lista->date.prenume<<"\n media="<<medief(lista)<<"\n";
		}
		if(i==locuri)
		{
			temporar=lista;
			lista=lista->urmator;
			while(medief(temporar)==medief(lista))
			{
				i++;
				cout<<lista->date.nume<<"\n"<<lista->date.prenume<<"\n media="<<medief(lista)<<"\n";
				lista=lista->urmator;
			}
			flag=1;
		}
		lista=lista->urmator;
	}
	return(i);
}
int main(void)
{
elem *lista,*temporar;
int flag;
int i;
int locuri;
		lista=introducere();
		flag=0;
		i=0;
 		lista=sortare_descrescatoare(lista);
		afisare(lista);
		afisare_medie(lista);
		afisare_medie9(lista);
		locuri=afisare_concurs(lista);
		cout<<"Nr locuri="<<locuri<<"\n";
		distrugere(lista);
		return(1);
}