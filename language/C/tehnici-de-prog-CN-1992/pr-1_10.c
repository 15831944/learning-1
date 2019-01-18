#include<stdlib.h>
#include<stdio.h>
int factorial(int n)
{
	if(n<0)
	{
		printf("Nu se poate calcula factorialul\n");
		exit(-1);
	}
	if(n==1) return 1;
	return n*factorial(n-1);
}
int main(int argc,char **argv)
{
	int fact;
	if(argc<2)
	{
		printf("Utilizare: %s numar\n",argv[0]);
		exit(-1);
	}
	if((fact=atoi(argv[1]))>15)
	{
		printf("Depasirea capacitatii de calcul !\n");
		exit(-1);
	}
	fact=factorial(fact);
	printf("Rezultat: %d\n",fact);
}