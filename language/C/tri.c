/* Rezolvarea triunghiurilor oarecare */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
int i,j,k,test;
float temp;
char nec;
struct element
{
	char type;
	float valoare;
} elemente[2][3];
float arie,perimetru;
	for(i=0;i<3;i++)
	{
		elemente[0][i].valoare=0;
		elemente[1][i].valoare=0;
	}
	elemente[0][0].type='a';
	elemente[0][1].type='b';
	elemente[0][2].type='c';
	elemente[1][0].type='A';
	elemente[1][1].type='B';
	elemente[1][2].type='C';
	printf("\n Introduceti ce elemente cunoasteti.");
	printf("\n Cu litera mica laturile si cu litera mare unghiurile.\n");
	printf("\n Introduceti cunoscuta si valoarea.\n");
	for(i=0;i<3;i++)
	{
		fflush(stdin);
		scanf("%c %f",&nec,&temp);
		fflush(stdin);
		switch(nec)
		{
			case 'a':
					elemente[0][0].valoare=temp;
					break;
			case 'b':
					elemente[0][1].valoare=temp;
					break;
			case 'c':
					elemente[0][2].valoare=temp;
					break;
			case 'A':
					elemente[1][0].valoare=temp*M_PI/180;
					break;
			case 'B':
					elemente[1][1].valoare=temp*M_PI/180;
					break;
			case 'C':
					elemente[1][2].valoare=temp*M_PI/180;
					break;
		}
	}
	test=0;
	for(i=0;i<3;i++) if(elemente[0][i].valoare==0) test+=1;
	if(test==2)
	{
		for(i=0;i<3;i++) if(elemente[1][i].valoare==0)
								{
								j=i+1; if(j>2) j=0;
								k=i-1; if(k<0) k=2;
								elemente[1][i].valoare=M_PI-(elemente[1][j].valoare+elemente[1][k].valoare);
								break;
								}
	}
//afisare
	for(i=0;i<3;i++)
	printf("%c %f\n",elemente[0][i].type,elemente[0][i].valoare);
	for(i=0;i<3;i++)
	printf("%c %f\n",elemente[1][i].type,elemente[1][i].valoare*180/M_PI);
	printf("Aria este %f\n",arie);
	exit(0);
}