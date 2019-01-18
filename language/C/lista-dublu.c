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
	struct adresa *preced;
} info;

//creaza o lista dublu inlantuita ordonata in ordine crescatoare
void dls_store( struct adresa *i, struct adresa **primul,struct adresa **ultimul)
{
	struct adresa *vechi,*p;
	//primul element din lista
	if(*ultimul==NULL)
	{
		i->urm=NULL;
		i->preced=NULL;
		*primul=i;
		*ultimul=i;
		return;
	}
	
	p=*primul;
	
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
		//inserare la mijloc
			if(p->preced)
			{
				p->preced->urm=i;
				i->urm=p;
				i->preced=p->preced;
				p->preced=i;
				return;
			}
		//inserare la inceput
			i->preced=NULL;
			p->preced=i;
			i->urm=p;
			*primul=i;
			return;
		}
	}
	//inserare la final
	i->urm=NULL;
	i->preced=vechi;
	vechi->urm=i;
	*ultimul=i;
}

//functia de stergere a unui element
void dldelete(struct adresa *a,struct adresa **primul,struct adresa **ultimul)
{
	if(a->preced)
	{
	//stergere de la mijloc
		if(a->urm)
		{
		 	a->preced->urm=a->urm;
			a->urm->preced=a->preced;
			return;
		}
		else
		{
			*ultimul=a->preced;
			a->preced->urm=NULL;
			return;
		}
	}
	else
	{
	//stergerea primului element
		*primul=a->urm;
		if(*primul) a->urm->preced=NULL;	//!!!
		return;
	}
}

//functia de afisare a listei
void display_sd(struct adresa *primul)
{
	if(primul==NULL) printf("Lista este goala.\n");
	while(primul)
	{
		printf("%s\n",primul->nume);
		primul=primul->urm;
	}

}
void display_ds(struct adresa *ultimul)
{
	while(ultimul)
	{
		printf("%s\n",ultimul->nume);
		ultimul=ultimul->preced;
	}
}

//functia de cautare
struct adresa *find(struct adresa *primul,char *str)
{
	while(primul)
	{
		if(strcmp(primul->nume,str)==0) return primul;
		primul=primul->urm;
	}
	return NULL;
}
int main(void)
{
	struct adresa *info,*prim,*ultim;
	char temp[40];
	int k;
	printf("Introduceti 10 nume in lista.\n");
	prim=NULL;
	ultim=NULL;
	for(k=0;k<10;k++)
	{
		info=malloc(sizeof(struct adresa));
		scanf("%s",info->nume);
		dls_store(info,&prim,&ultim);
	}
	printf("Afisare de la stinga la dreapta:\n");
	display_sd(prim);
	printf("Afisare de la dreapta la stinga:\n");
	display_ds(ultim);
	printf("Introduceti numele de sters:\n");
	scanf("%s",temp);
	printf("\n");
	dldelete(find(prim,temp),&prim,&ultim);
	printf("Dupa stergere lista este:\n");
	display_sd(prim);
	while(prim)
	{
		printf("sterg %s\n",prim->nume);
		dldelete(prim,&prim,&ultim);
		prim=prim->urm;
	}
	display_sd(prim);
}