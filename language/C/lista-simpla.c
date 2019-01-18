//program pentru testarea listei simplu inlantuite
#include <stdio.h>
#include <stdlib.h>

typedef struct adresa
{
	char nume[40];
	char strada[40];
	char oras[20];
	char stat[3];
	char cod_postal[11];
	struct adresa *urm;
} lista;

void sls_store(struct adresa *i,struct adresa **prim,struct adresa **ultim)
{
	struct adresa *vechi,*p;
	p=*prim;
	
	//verificam daca lista este goala
	if(!*ultim)
	{
		i->urm=NULL;
		*ultim=i;
		*prim=i;
		return;
	}
	
	vechi=NULL;
	
	while(p)
	{
		if(strcmp(p->nume,i->nume)<0)
		{
			vechi=p;
			p=p->urm;
		}
		else 
		{
			//intra la mijloc
			if(vechi)
			{
				vechi->urm=i;
				i->urm=p;
				return;
			}
			//noul prim element
			i->urm=p;
			*prim=i;
			return;
		}
	}
	//introduce la sfirsit
	(*ultim)->urm=i;
	i->urm=NULL;
	*ultim=i;
}

//functia de afisare
void display(struct adresa *prim)
{
	while(prim)
	{
		printf("%s\n",prim->nume);
		prim=prim->urm;
	}
}

//functia de cautare
struct adresa *search(struct adresa *prim,char *n)
{
	while(prim)
	{
		if(strcmp(prim->nume,n)) return prim;
		prim=prim->urm;
	}
	return NULL;
}

//functia de stergere
void sldelete(struct adresa **prim,struct adresa **ultim,struct adresa *p,struct adresa *a)
{
	if(p) p->urm=a->urm;
	else *prim=a->urm;
	
	if(a==*ultim && p) *ultim=p;
}

int main(void)
{
	int i;
	struct adresa *info,*prim,*ultim;
	printf("Se vor introduce 10 valori in lista.\n");
	prim=NULL;
	ultim=NULL;
	for(i=0;i<10;i++)
	{
		info=malloc(sizeof(struct adresa));
		scanf("%s\n",info->nume);
		sls_store(info,&prim,&ultim);
	}
	printf("Lista este:\n");
	display(prim);
}