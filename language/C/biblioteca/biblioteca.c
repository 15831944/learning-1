#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef LINUX
#include<conio.h>
#include<dir.h>
#endif
struct carte
{
	char titlu[80];
	char autor[80];
	char editura[80];
	int pret;
	int nr_pagini;
	struct carte *avant;
	struct carte *apres;
};
struct carte *baza,*final,*temp;
FILE *fp;
char name[FILENAME_MAX];
int eliberare(void)
{
	while(baza!=NULL)
	{
		temp=baza;
		baza=baza->apres;
		free(temp);
	}
	return 0;
}
int save(void)
{
	scanf("%s",name);fflush(stdin);
	if(baza==NULL)
	{
		printf("lista vida\n");fflush(stdout);
		return -1;
	}
	fp=(FILE *)fopen(name,"w");
	if(fp==NULL)
	{
		perror("eroare open file");
		exit(-1);
	}
	temp=baza;
	while(temp!=NULL)
	{
		fwrite(temp,sizeof(struct carte),1,fp);
		temp=temp->apres;
	}
	fclose(fp);
	return 0;
}
int load(void)
{
	struct carte *temp;
	int nr_citit;
	scanf("%s",name);fflush(stdin);
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		perror("Eroare deschidere fisier");
		fflush(stderr);
		return -1;
	}
	while(!feof(fp))
	{
		temp=(struct carte *)calloc(1,sizeof(struct carte));
		nr_citit=fread(temp,sizeof(struct carte),1,fp);
		if(nr_citit==0)
		{
			fclose(fp);
			free(temp);
			return 0;
		}
		if(baza==NULL) //este primul element din lista
		{
			baza=final=temp;
			temp->avant=NULL;
			temp->apres=NULL;
		}
		else
		{
			final->apres=temp;
			temp->avant=final;
			temp->apres=NULL;
			final=temp;
		}
	}
	fclose(fp);
	return 0;
}
int adaugare(void)
{
#ifdef LINUX
	char nr; //pt gcc , vechea problema cu scanf("%d"),scanf("%c");
	scanf("%c",&nr);fflush(stdin);//pt gcc , vechea problema cu scanf("%d"),scanf("%c");
#endif
	temp=(struct carte *)calloc(1,sizeof(struct carte));
	printf("Introduceti autorul:");fflush(stdout);
	fflush(stdin);
	gets(temp->autor);
	fflush(stdin);
	printf("Introduceti titlul:");fflush(stdout);
	gets(temp->titlu);
	fflush(stdin);
	printf("Introduceti pretul:");fflush(stdout);
	scanf("%d",&temp->pret);fflush(stdin);
	printf("Introduceti numarul de pagini:");fflush(stdout);
	scanf("%d",&temp->nr_pagini);fflush(stdin);
	if((strcmp("exit",temp->titlu)==0 )|| (strlen(temp->titlu)==0))
	{
		free(temp);
		return 1;
	}
	if(baza==NULL) //este primul element din lista
	{
		baza=final=temp;
		temp->avant=NULL;
		temp->apres=NULL;
	}
	else
	{
		final->apres=temp;
		temp->avant=final;
		temp->apres=NULL;
		final=temp;
	}
	return 0;
}
int afisare(struct carte *book)
{
	printf("\nTitlu=%s\n",book->titlu);fflush(stdout);
	printf("Autor=%s\n",book->autor);fflush(stdout);
	printf("Nr pagini=%d\n",book->nr_pagini);fflush(stdout);
	printf("Pret=%d\n",book->pret);fflush(stdout);
	return 0;
}
int stergere(void)
{
	char autor[80],titlu[80];
	char flag;
#ifdef LINUX
	scanf("%c",&flag);fflush(stdin);//pentru gcc
#endif
	printf("Introduceti autorul\n");fflush(stdout);
	gets(autor);
	printf("Introduceti titlul\n");fflush(stdout);
	gets(titlu);
	temp=baza;
	while(temp!=NULL)
	{
		if(strcmp(autor,temp->autor)==0 && strcmp(titlu,temp->titlu)==0)
		{
			afisare(temp);
			printf("doriti stergere d/n:");fflush(stdout);
			scanf("%c",&flag);fflush(stdin);
			if(flag=='d' || flag=='D')
			{
				if(temp->avant==NULL)
				{
					baza=temp->apres;
					baza->avant=NULL;
					free(temp);
					temp=baza;
				}
				else if(temp->apres==NULL)
				{
					final=temp->avant;
					final->apres=NULL;
					free(temp);
					return 0;
				}
				else
				{
					temp->avant->apres=temp->apres;
					temp->apres->avant=temp->avant;
					free(temp);
					temp=baza;
				}
			}
		}
		else
		{
			printf("passe\n");fflush(stdout);
			temp=temp->apres;
		}
	}
	printf("cartea nu a fost gasita\n");fflush(stdout);
	return 1;
}
int cautare(void)
{
	char caut[80];
	int flag=0;
	int operatie;
	printf("Doriti cautare dupa autor[0] sau titlu[1]:");fflush(stdout);
	scanf("%d",&operatie);fflush(stdin);
	switch(operatie)
	{
		case 0://autor
			#ifdef LINUX
			scanf("%c",&caut[0]);fflush(stdin);//pentru gcc
			#endif
			printf("Introduceti autorul\n");fflush(stdout);
			gets(caut);
			temp=baza;
			while(temp!=NULL)
			{
				if(strcmp(caut,temp->autor)==0)
				{
					afisare(temp);
					flag++;
				}
				temp=temp->apres;
			}
			if(flag==0)
			{
				printf("Nu a fost gasita nici o carte de autorul %s\n",caut);
				fflush(stdout);
			}
			return flag;
		case 1://titlu
			#ifdef LINUX
			scanf("%c",&caut[0]);fflush(stdin);//pentru gcc
			#endif
			printf("Introduceti titlul cartii\n");fflush(stdout);
			gets(caut);
			temp=baza;
			while(temp!=NULL)
			{
				if(strcmp(caut,temp->titlu)==0)
				{
					afisare(temp);
					flag++;
				}
				temp=temp->apres;
			}
			if(flag==0)
			{
				printf("Nu a fost gasita nici o carte de titlul %s\n",caut);
				fflush(stdout);
			}
			return flag;
		default:
			printf("Nu a-ti introdus optiunea corecta\n");
			fflush(stdout);
			return -1;
	}
}
int cautare_disk()
{
	char caut[80];
	int flag=0;
	int operatie;
	int nr_citit;
	eliberare();
	scanf("%s",name);fflush(stdin);
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		perror("Eroare deschidere fisier");
		fflush(stderr);
		return -1;
	}
	printf("Doriti cautare dupa autor[0] sau titlu[1]:");fflush(stdout);
	scanf("%d",&operatie);fflush(stdin);
	switch(operatie)
	{
		case 0://autor
			#ifdef LINUX
			scanf("%c",&caut[0]);fflush(stdin);//pentru gcc
			#endif
			printf("Introduceti autorul\n");fflush(stdout);
			gets(caut);
			break;
		case 1://titlu
			#ifdef LINUX
			scanf("%c",&caut[0]);fflush(stdin);//pentru gcc
			#endif
			printf("Introduceti titlul cartii\n");fflush(stdout);
			gets(caut);
			break;
		default:
			printf("Nu a-ti introdus optiunea corecta\n");
			fflush(stdout);
			return -1;
	}
	temp=(struct carte *)calloc(1,sizeof(struct carte));
	while(!feof(fp))
	{
		nr_citit=fread(temp,sizeof(struct carte),1,fp);
		if(nr_citit==0)
		{
			fclose(fp);
			free(temp);
			return 0;
		}
		if(operatie==0 && strcmp(caut,temp->autor)==0) flag=1;
		else
		{
			if(operatie==1 && strcmp(caut,temp->titlu)==0) flag=1;
			else flag=0;
		}
		if(flag==1)
		{
			afisare(temp);
			if(baza==NULL) //este primul element din lista
			{
				baza=final=temp;
				temp->avant=NULL;
				temp->apres=NULL;
				temp=(struct carte *)calloc(1,sizeof(struct carte));
			}
			else
			{
				final->apres=temp;
				temp->avant=final;
				temp->apres=NULL;
				final=temp;
				temp=(struct carte *)calloc(1,sizeof(struct carte));
			}
			flag=0;
		}
	}
	fclose(fp);
}
int append_disk()
{
	#ifdef LINUX
	char test;
	#endif
	scanf("%s",name);fflush(stdin);
	fp=fopen(name,"a");
	if(fp==NULL)
	{
		perror("eroare deschidere fisier");
		return -1;
	}
	temp=(struct carte *)calloc(1,sizeof(struct carte));
	#ifdef LINUX
	scanf("%c",&test);fflush(stdin);//pentru gcc
	#endif
	printf("Introduceti autorul:");fflush(stdout);
	fflush(stdin);
	gets(temp->autor);
	fflush(stdin);
	printf("Introduceti titlul:");fflush(stdout);
	gets(temp->titlu);
	fflush(stdin);
	printf("Introduceti pretul:");fflush(stdout);
	scanf("%d",&temp->pret);fflush(stdin);
	printf("Introduceti numarul de pagini:");fflush(stdout);
	scanf("%d",&temp->nr_pagini);fflush(stdin);
	fwrite(temp,sizeof(struct carte),1,fp);fflush(fp);
	fclose(fp);
	return 0;
}
int afisare_disk()
{
	struct carte *temp;
	int nr_citit;
	scanf("%s",name);fflush(stdin);
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		perror("Eroare deschidere fisier");
		fflush(stderr);
		return -1;
	}
	temp=(struct carte *)calloc(1,sizeof(struct carte));
	while(!feof(fp))
	{
		nr_citit=fread(temp,sizeof(struct carte),1,fp);
		if(nr_citit==0)
		{
			fclose(fp);
			free(temp);
			return 0;
		}
		afisare(temp);
	}
	fclose(fp);
	free(temp);
	return 0;
}

int main(void)
{
	int flag,flag1;
	int operatie;
	baza=NULL;
	flag1=0;
	while(flag1==0)
	{
		#ifndef LINUX
		clrscr();
		#endif
		printf("Memorie[0] Disk[1] Exit[2]\n");fflush(stdout);
		printf("Introduceti operatia:");fflush(stdout);
		scanf("%d",&operatie);fflush(stdin);
		switch(operatie)
		{
			case 0://memorie
				printf("Load[0] Afisare[1] Cautare[2] Operatii[3]\n");fflush(stdout);
				printf("Introduceti operatia:");fflush(stdout);
				scanf("%d",&operatie);fflush(stdin);
				switch(operatie)
				{			
					case 0://load
						eliberare();
						baza=NULL;
						load();
						break;
					case 1://afisare
						temp=baza;
						while(temp!=NULL)
						{
							afisare(temp);
							temp=temp->apres;
						}
						#ifndef LINUX
						while(!kbhit());
						#endif
						break;
					case 2: //cautare in memorie
						cautare();
						#ifndef LINUX
						while(!kbhit());
						#endif
						break;
					case 3://operatie
						printf("Save[0]  Append[1] Stergere element[2] Stergere lista[3] Lista noua[4]\n");fflush(stdout);
						printf("Introduceti operatia:");fflush(stdout);
						scanf("%d",&operatie);fflush(stdout);
					switch(operatie)
					{
						case 0://save
							save();
							break;
						case 1: //apend
							adaugare();
							break;
						case 2://stergere element
							stergere();
							break;
						case 3://stergere completa
							eliberare();
							break;
						case 4://introducere lista noua
							eliberare();
							baza=NULL;
							printf("Introduceti cartile\n");fflush(stdout);
							flag=0;
							while(flag==0) { flag=adaugare();}
							break;
					}
					break;
				}
				break;
			case 1: //disk
				eliberare();
				baza=NULL;
				printf("Append[0] Afisare[1] Cautare[2]\n");fflush(stdout);
				printf("Introduceti operatia:");fflush(stdout);
				scanf("%d",&operatie);fflush(stdin);
				switch(operatie)
				{			
					case 0://append
						append_disk();
						break;
					case 1: //afisare
						afisare_disk();
						#ifndef LINUX
						while(!kbhit());
						#endif
						break;
					case 2://Cautare
						cautare_disk();
						#ifndef LINUX
						while(!kbhit());
						#endif
						break;
				}
				break;
			case 2: //exit
				flag1=1;
				break;
		}
	}
	eliberare();
	return 0;
}
