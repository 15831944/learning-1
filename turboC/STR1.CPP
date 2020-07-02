/*
 * mod de utilizare scriere pe stringuri
 */
#include <stdio.h>

char buf[80];
int i = 100;
double r = 12.4567;

void main()
{
	sprintf(buf, "Valorile initiale i =%4d r = %8.4lf\n", i, r);
	/* test */
	puts(buf);
	sscanf( buf, "Valorile initiale = %4d r = %8lf\n", &i, &r);
	/* tests */
	printf("Valorile citite de sscanf i = %4d, r = %8.4lf\n", i, r);
}