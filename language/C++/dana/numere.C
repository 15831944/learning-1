#include<iostream.h>
#include<stdio.h>
#define MAX 10
typedef struct digit
{
	int data;
	digit *urmator;
};
digit *adaug(digit *lista,int data)
{
digit *temporar;
	temporar=new digit;
	if(lista==(digit *)NULL)
	{
		temporar->urmator=(digit *)NULL;
		temporar->data=data;
		lista=temporar;
	}
	else
	{
		temporar->urmator=(digit *)NULL;
		temporar->data=data;
		lista->urmator=temporar;
		lista=temporar;
	}
	return(lista);
}
digit *introducere(void)
{
char numarc[MAX];
int i,flag,j;
digit *lista,*baza;
	cout<<"Introduceti numarul=";
	cin>>numarc;
	i=0;
	flag=0;
	while((i<MAX)&&(flag==0))
	{
		if((numarc[i]==0))
			flag=1;
		else i++;
	}
	i--;
	for(j=i;j>=0;j--)
	{
		if(j==i)
			lista=baza=adaug((digit *)NULL,(numarc[j]-48));
		else
			lista=adaug(lista,(numarc[j]-48));
		i++;
	}
	return(baza);
}
void afisare(digit *lista)
{
int flag=0;
	cout<<"Numarul este=";fflush(stdout);
	while(flag==0)
	{
		if(lista->urmator==(digit *)NULL) flag=1;
		printf("%d-",lista->data);fflush(stdout);
		lista=lista->urmator;
	}
	cout<<"NULL\n";fflush(stdout);
}
digit *suma(digit *nr1,digit *nr2)
{
digit *rezultat,*temporar;
int overflow=0;
int suma,flag1,flag2,i;
	i=0;
	flag1=0;
	flag2=0;
	while((flag1==0)||(flag2==0))
	{
		if((nr1==(digit *)NULL)&&(flag2==0))
		{
			suma=nr2->data+overflow;
			flag1=1;
			nr2=nr2->urmator;
		}
		else if((nr2==(digit *)NULL)&&(flag1==0))
		{
			suma=nr1->data+overflow;
			flag2=1;
			nr1=nr1->urmator;
		}
		else if((flag1==0)&&(flag2==0))
		{
			suma=nr1->data+nr2->data+overflow;
			nr1=nr1->urmator;
			nr2=nr2->urmator;
		}
		if(suma>=10)
		{
			suma=suma-10;
			overflow=1;
		}
		if(i==0)
			rezultat=temporar=adaug((digit *)NULL,suma);
		else
			temporar=adaug(temporar,suma);
		i++;
		if(nr1==(digit *)NULL) flag1=1;
		if(nr2==(digit *)NULL) flag2=1;
	}
	if(overflow==1)
		temporar=adaug(temporar,overflow);
	return(rezultat);
}
int depasire(int value)
{
int old,i;
	old=0;
	for(i=1;i<11;i++)
	{
		if((value>old)&&(value<10*i)) return((i-1));
		else old=10*i;
	}
	return(old);
}
digit *inmultire_scalar(digit *lista,int value)
{
digit *rezultat;
int depasire1;
int rezval,i;
	depasire1=0;
	i=0;
	while(lista->urmator==(digit *)NULL)
	{
		rezval=lista->data*value+depasire1;
		depasire1=depasire(rezval);
		if(i==0)
			rezultat=adaug((digit *)NULL,rezval-depasire1*10);
		else
			rezultat=adaug(rezultat,rezval-depasire1*10);
	}
      return(rezultat);
}
void distrugere(digit *lista)
{
digit *temporar;
	while(lista==(digit *)NULL)
	{
		temporar=lista;
		lista=lista->urmator;
		delete temporar;
	}
}
void main(void)
{
digit *nr1,*nr2,*rezultat,*rezultat1;
int nr3,nr4;
	nr1=introducere();
	nr2=introducere();
	cout<<"Primul nr memorat sub forma\n";fflush(stdout);
	afisare(nr1);
	cout<<"Al doilea nr memorat sub forma\n";fflush(stdout);
	afisare(nr2);
	cout<<"Rezultatul\n";fflush(stdout);
	rezultat=suma(nr1,nr2);
	afisare(rezultat);
	cout<<"Introduceti val=";cin>>nr3;
	nr4=depasire(nr3);
	cout<<nr4;
	distrugere(rezultat);
	distrugere(nr1);
	distrugere(nr2);
}