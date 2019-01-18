/* Program care realizeaza binomul lui newton */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
int n,i;
float combinari,a;
	printf("\n Introduceti (x+a) la puterea n, intii a si apoi n.\n");
	fflush(stdin);
	scanf("%f %d",&a,&n);
	fflush(stdin);
	printf("x(%d)+",n);
	for(i=1;i<n;i++)
	{
		combinari=factorial(n)/factorial(i)/factorial(n-i);
		printf("%.2fx(%d)+",combinari*pow(a,i),n-i);
	}
	printf("%.2f",pow(a,n));
	exit(0);
}