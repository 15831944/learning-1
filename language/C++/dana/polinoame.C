#include<iostream.h>
#include<stdio.h>
typedef struct elem
{
	int value;
	int arg;
	elem *urmator;
};
elem *adaug(elem *lista,int value,int arg)
{
elem *temporar;
	temporar=new elem;
	temporar->value=value;
	temporar->arg=arg;
	temporar->urmator=(elem *)NULL;
	if(lista==(elem *)NULL)
		return(temporar);
	else
	{
		lista->urmator=temporar;
		return(temporar);
	}
}
elem *introducere(void)
{
FILE *fp;
char nume[FILENAME_MAX];
int value;
int arg;
char delimitator;
char ctmp;
elem *baza,*lista;
int i;
	printf("Introduceti numele fisierului in care se alfa polinomul\n");fflush(stdout);
	scanf("%s",nume);fflush(stdin);
	if((fp=(FILE *)fopen(nume,"r"))==(FILE *)NULL)
	{
		perror("file not open");
		exit(-1);
	}
	i=0;
	while(feof(fp)==0)
	{
		fscanf(fp,"%d",&value);fflush(fp);
		if(feof(fp)==0)
		{
			fscanf(fp,"%c",&delimitator);fflush(fp);
			if((delimitator=='X')||(delimitator=='x'))
			{
				fscanf(fp,"%c",&ctmp);fflush(fp);
				if((ctmp=='+')||(ctmp=='-')) 
				{
					arg=1;
					fseek(fp,-1,SEEK_CUR);fflush(fp);
				}
				else 
				{
					fseek(fp,-1,SEEK_CUR);fflush(fp);
					fscanf(fp,"%d",&arg);fflush(fp);
				}
			}
			else delimitator=0;
		}
		else 
			arg=0;
		if(i==0) baza=lista=adaug((elem *)NULL,value,arg);
		else lista=adaug(lista,value,arg);
		i++;
	}
	fclose(fp);
	return(baza);
}
void distrugere(elem *lista)
{
elem *temporar;
	while(lista!=(elem *)NULL)
	{
		temporar=lista;
		lista=lista->urmator;
		delete temporar;
	}
}

void printare(elem *lista)
{
char sign;
char delimitator='X';
	while(lista!=(elem *)NULL)
	{
		if(lista->value>0) sign='+';
		else sign=0;
		if(lista->arg==1)
		{
			printf("%c%d%c",sign,lista->value,delimitator);fflush(stdout);
		}
		else if(lista->arg==0)
		{
			printf("%c%d",sign,lista->value);fflush(stdout);
		}
		else
		{
			printf("%c%d%c%d",sign,lista->value,delimitator,lista->arg);fflush(stdout);
		}
		lista=lista->urmator;
	}
	printf("\n");fflush(stdout);
}
elem *suma(elem *poli1,elem *poli2)
{
elem *rezultat,*baza;
	rezultat=(elem *)NULL;
	while((poli1!=(elem *)NULL)||(poli2!=(elem *)NULL))
	{
		if((poli1==(elem *)NULL)&&(poli2!=(elem *)NULL))
		{
			if(rezultat==(elem *)NULL)
				baza=rezultat=adaug(rezultat,poli2->value,poli2->arg);
			else rezultat=adaug(rezultat,poli2->value,poli2->arg);
			poli2=poli2->urmator;
		}
		else if((poli1!=(elem *)NULL)&&(poli2==(elem *)NULL))
		{
			if(rezultat==(elem *)NULL)
				baza=rezultat=adaug(rezultat,poli1->value,poli1->arg);
			else rezultat=adaug(rezultat,poli1->value,poli1->arg);
			poli1=poli1->urmator;
		}
		else if(poli1->arg==poli2->arg)
		{
			if(rezultat==(elem *)NULL)
				baza=rezultat=adaug(rezultat,(poli1->value+poli2->value),poli1->arg);
			else rezultat=adaug(rezultat,(poli1->value+poli2->value),poli1->arg);
			poli1=poli1->urmator;
			poli2=poli2->urmator;
		}
		else if(poli1->arg>poli2->arg)
		{
			if(rezultat==(elem *)NULL)
				baza=rezultat=adaug(rezultat,poli1->value,poli1->arg);
			else rezultat=adaug(rezultat,poli1->value,poli1->arg);
			poli1=poli1->urmator;
		}
		else if(poli1->arg<poli2->arg)
		{
			if(rezultat==(elem *)NULL)
				baza=rezultat=adaug(rezultat,poli2->value,poli2->arg);
			else rezultat=adaug(rezultat,poli2->value,poli2->arg);
			poli2=poli2->urmator;
		}
	}
	return(baza);
}
int main(void)
{
elem *poli1;
elem *poli2;
elem *rezultat;
	poli1=introducere();
	poli2=introducere();
	cout<<"primul polinom=";fflush(stdout);
	printare(poli1);
	cout<<"\nal doilea polinom=";fflush(stdout);
	printare(poli2);
	cout<<"\nsuma=";fflush(stdout);
	rezultat=suma(poli1,poli2);
	printare(rezultat);
	cout<<"\n";fflush(stdout);
	distrugere(poli1);
	distrugere(poli2);
	distrugere(rezultat);
}