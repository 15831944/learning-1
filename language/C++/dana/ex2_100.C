//Problema 2 de la pagina 100 fara punctul a
#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<fstream.h>
ofstream ordonat;
ofstream restant,neprezentat;
ifstream intrare;
typedef struct student
{
	char grupa[5];
	char nume[20];
	float media;
};
student *facultate,maxim,temp;

int main(void)
{
int numar,i,j,pozitie;
	intrare.open("intrare.txt");
	ordonat.open("ordonat.txt");
	restant.open("restant.txt");
	neprezentat.open("nepr.txt");
	//fac alocare dinamica pentru vectorul de structuri
	facultate=(student *)calloc(1,sizeof(student));
	if(facultate==(student *)NULL)
	{
		cout<<"\n Eroare de alocare memorie.\n";
		exit(1);
	}
	numar=0;
	while(!intrare.eof())
	{
		//refac realocarea pentru a avea o dinamica buna
		if(numar!=0) facultate=(student *)realloc(facultate,sizeof(student));
		intrare>>facultate[numar].grupa;
		intrare>>facultate[numar].nume;
		intrare>>facultate[numar].media;
		numar++;
	}
	numar--;
	for(i=0;i<numar;i++)
	{
		//scoate in fisierul nepr.txt  studentii neprezentati media=1
		if(facultate[i].media==1)
		{
			neprezentat<<"\n Student\n";
			neprezentat<<facultate[i].grupa<<"\n";
			neprezentat<<facultate[i].nume<<"\n";
			neprezentat<<facultate[i].media;
		}
		//scoate in fiserul restant.txt studentii restanti
		if((facultate[i].media<5)&&(facultate[i].media!=1))
			{
				restant<<"\n Student\n";
				restant<<facultate[i].grupa<<"\n";
				restant<<facultate[i].nume<<"\n";
				restant<<facultate[i].media;
			}
	}
	//scoate in fisierul ordonat.txt fisierul de intrare ordonat descrescator dupa media
	for(i=0;i<numar;i++)
	{
		strcpy(maxim.grupa,facultate[i].grupa);
		strcpy(maxim.nume,facultate[i].nume);
		maxim.media=facultate[i].media;
		pozitie=i;
		//caut maximul dintre elementele ramase de la i spre numar
		for(j=i;j<numar;j++)
		{
			if(maxim.media<facultate[j].media)
			{
				maxim.media=facultate[j].media;
				strcpy(maxim.nume,facultate[j].nume);
				strcpy(maxim.grupa,facultate[j].grupa);
				pozitie=j;
			}
		 }
		//schimb pozitia elementului maxim cu elementul i
		strcpy(temp.grupa,facultate[i].grupa);
		strcpy(temp.nume,facultate[i].nume);
		temp.media=facultate[i].media;
		strcpy(facultate[i].grupa,facultate[pozitie].grupa);
		strcpy(facultate[i].nume,facultate[pozitie].nume);
		facultate[i].media=facultate[pozitie].media;
		strcpy(facultate[pozitie].grupa,temp.grupa);
		strcpy(facultate[pozitie].nume,temp.nume);
		facultate[pozitie].media=temp.media;
	}
	for(i=0;i<numar;i++)
	{
		ordonat<<facultate[i].grupa<<"\n";
		ordonat<<facultate[i].nume<<"\n";
		ordonat<<facultate[i].media<<"\n";
	}
	//printam pe ecran studentul cu media cea mai mare el este primul element
	// din sir dupa ordonare
	cout<<"\n Studentul cu media cea mai mare\n";
	cout<<facultate[0].grupa<<"\n";
	cout<<facultate[0].nume<<"\n";
	cout<<facultate[0].media<<"\n";
	//inclidem fisiere si eliberam memoria
	intrare.close();
	neprezentat.close();
	restant.close();
	ordonat.close();
	free(facultate);
	exit(1);
}