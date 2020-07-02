/*
 * functie care realizeaza o cifrare oarecare a unui sir de caracter 
 */
#include <stdio.h>

void cifru(const char *stri, char *strc);
void main()
{
	char str_cifrat[80];
	char str_init[80] = "mesaj de test";
	cifru(str_init, str_cifrat);
	printf("cifrat = %s\n",str_cifrat);
}

void cifru (const char *stri, char *strc)
{
	/* cifrare prin incrementare a codului ASCII */
	while (*stri) {
		*strc = *stri + 1;
		strc++;
		stri++;
	}
	*strc='\0';
}