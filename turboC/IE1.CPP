/*
 * programul afiseaza un memou care permite selectarea unuia din tipurile
 *  float, double sau long double dupa care solicita introducerea de la
 * tastatura a unui numar si a unui sir de caractere corespunzator
 * formatului de afisare dorit si afiseaza pe ecran valoarea
 */
#include <stdio.h>
#include <conio.h>

void main()
{
	char opt; /* litera optiunii selectate */
	char frm[10]; /* sir de caractere pentru identificarea formatului */

	float rvt;
	double rvd;
	long double rvld;
	clrscr(); /* sterge ecranul */
	puts("Tipul valorii: f = float, d = double, l = long double");
	printf("Optiunea ?");
	opt = getche() & 0x5f;
	printf("\n");
	if (opt == 'F') {
		printf(" Valoare (float, format de citere % %10f)?");
		scanf("%10f", &rvt);
		fflush(stdin);
		printf("Format de afisare: ");
		gets(frm);
		printf(frm, rvt);
	} else {
		if ( opt == 'D') {
			printf(" Valoare (double, format de citire % %15lf) ?");
			scanf("%20lf",&rvd);
			fflush(stdin);
			printf("Format de afisare: ");
			gets(frm);
			printf(frm, rvd);
		} else if (opt == 'L') {
			printf(" Valoare (long double, format citire % %20Ld) ?");
			scanf("%20Lf", &rvld);
			fflush(stdin);
			printf("Format de afisare: ");
			gets(frm);
			printf(frm, rvld);
		} else {
			puts("Optiune incorecta");
		}
	}
}
