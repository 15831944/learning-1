/* dialogul cu consola  */
#include <stdio.h>

int sqr(int); /* prototipul functiei sqr() */
void main(void)
{
	int num, rez;
	printf("Introduceti un numar intreg: ");
	scanf("%d", &num);
	rez = sqr(num); /* apel al functiei sqr() */
	printf("%d la patrat = %d\n",num, rez);
}

sqr(int q) /* definitia functiei sqr() */
{
	return q*q;
}