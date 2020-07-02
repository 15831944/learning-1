/* transferul prin referinta */
#include <stdio.h>

void schimba(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	int a, b;
	a = 10;
	b = 20;
	printf("inainte a=%d b=%d\n", a,b);
	schimba(&a,&b);
	printf("dupa a=%d b=%d\n",a,b);
}