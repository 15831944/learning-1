/* Program care realizeaza combinari de n luate cite m */
#include<stdio.h>
#include<stdlib.h>

float factorial(int numar)
{
int i;
float factorial=1;
	if(numar==0) return 1;
	for(i=1;i<numar+1;i++) factorial*=i;
	return factorial;
}

int main(void)
{
int m,n;
float combinari,aranjamente;
int i,test;
char key;
	test=0;
	while(test!=1)
	{
		printf("\n Introduceti exponentii m si n ");
		scanf("%d %d",&m,&n);
		fflush(stdin);
		combinari=factorial(n)/factorial(m)/factorial(n-m);
		aranjamente=1;
		for(i=0;i<m;i++) aranjamente*=n-i;
		printf("\n Combinari de %d luate cite %d fac: %.2g \n",n,m,combinari);
		printf("\n Aranjamente de %d luate cite %d fac %.2g \n",n,m,aranjamente); 
		i=0;
		//testez daca s-a introdus corect simbolul de iesire sau continuare si actionez ca atare
		while(i!=1)
		{
			printf("\n Doriti sa continuati D/N ");
			key=getchar();
			if((key=='D')||(key=='d'))
			{ 
				test=0;
				i=1;
			}
			else 	if((key=='N')||(key=='n'))
					{ 
						test=1;
						i=1;
					}
					else i=0;
		}
		fflush(stdout);

	}
	exit(0);
}