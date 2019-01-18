/* Rezolvarea triunghiurilor oarecare */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
int i,j,k;
float temp;
char nec,junk;
struct element
{
	char type;
	float valoare;
} elemente[2][3];
float arie;
	printf("\n Introduceti ce elemente cunoasteti.");
	printf("\n Cu litera mica laturile si cu litera mare unghiurile.\n");
	printf("\n Introduceti cunoscuta si valoarea.\n");
	for(i=0;i<3;i++) 
	{
		fflush(stdin);
		scanf("%c%c %f",&junk,&nec,&temp);
		fflush(stdin);
		switch(nec)
		{
			case 'a':
					elemente[0][0].type='a';
					elemente[0][0].valoare=temp;
					break;
			case 'b':
					elemente[0][1].type='b';
					elemente[0][1].valoare=temp;	
					break;
			case 'c':
					elemente[0][2].type='c';
					elemente[0][2].valoare=temp;
					break;
			case 'A':
					elemente[1][0].type='A';
					elemente[1][0].valoare=temp*M_PI/180;
					break;
			case 'B':
					elemente[1][1].type='B';
					elemente[1][1].valoare=temp*M_PI/180;
					break;
			case 'C':
					elemente[1][2].type='C';
					elemente[1][2].valoare=temp*M_PI/180;
					break;
		}
	}
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	printf("%c %f\n",elemente[i][j].type,elemente[i][j].valoare);
	
}