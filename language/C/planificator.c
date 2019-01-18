#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char *p[MAX], *qretrieve(void);
int spos=0; //pozitia libera din coada
int rpos=0; //pozitia primului element din coada
void enter(void), qstore(char *q), review(void), delete(void);

//definirea functiilor care relizeaza operatii asupra cozii

//recupereaza o intilnire
char *qretrieve(void)
{
	//testez daca coada este goala
	if(spos==rpos)
	{
		printf("Nu mai sunt intilniri.\n");
		return NULL;
	}
	//incrementez prima pozitie
	rpos++;
	//returnez prima pozitie
	return p[rpos-1];
	
}

//stocheaza o intilnire
void qstore(char *q)
{
	//testez daca coada este plina
	if(spos==MAX)
		printf("Lista este plina. \n");
	else
	{
		//stochez data
		p[spos]=q;
		//incrementez pozitia libera in coada
		spos++;
	}
}

//sterge o intilnire din coada
void delete(void)
{
	char *p;
	//daca coada este goala ies
	if((p=qretrieve())==NULL) return;
	//daca coada nu este qoala afisez data
	printf("%s\n",p);
}

//consulta coada
void review(void)
{
	register int t;
	//afisez coada acest lucru este posibil deoare ea este vazuta ca o 
	//lista cu acces aleatoriu
	for(t=rpos;t<spos;++t)
		printf("%d %s\n",t+1,p[t]);
}

//introducerea intilnirii in coada
void enter(void)
{
	char s[256], *p;
	
	do{
		printf("Introduceti intilnirea %d: ",spos+1);
		gets(s);
		if(*s==0) break;//nu mai sunt locuri libere
		//aloc memorie pentru stringul introdus plus un spatiu pentru terminator
		p=malloc(strlen(s)+1);
		//testez daca am suficienta memorie
		if(!p)
		{
			printf("Memorie epuizata. \n");
			return;
		}
		//copiez stringul s in p
		strcpy(p,s);
		if(*s) qstore(p);
	}while (*s);
}

int main(void)
{
	char s[80];
	register int t;
	
	//intializez tabloul cu 0
	for(t=0;t<MAX;t++) p[t]=NULL;
	for(;;)
	{
		printf("Enter,List,Remove,Quit: ");
		gets(s);
		*s=toupper(*s);
		switch(*s)
		{
			case 'E':
				enter();
				break;
			case 'L':
				review();
				break;
			case 'R':
				delete();
				break;
			case 'Q':
				exit(0);
		}
	}
}