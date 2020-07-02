/*
 * program care exemplifica parametrii din linia de comanda
 */

#include <stdio.h>
void main(int argc, char *argv[])
{
	int i;
	if (argc < 2)
		puts("Nu mi-ai spus cum te numesti !");
	else {
		printf("\nSalut ");
		for (i = 1; i < argc; i++)
			printf("%s ", argv[i]);
		puts("!!!");
	}
}