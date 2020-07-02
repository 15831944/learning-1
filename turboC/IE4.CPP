/*
 * programul afiseaza un memou care permite selectarea unuia din tipurile
 *  float, double sau long double dupa care solicita introducerea de la
 * tastatura a unui numar si a unui sir de caractere corespunzator
 * formatului de afisare dorit si afiseaza pe ecran valoarea
 */
#include <stdio.h>
#include <conio.h>

char menu()
{

	puts("Tipul valorii: f = float, d = double, l = long double");
	printf("Optiunea ?");
	return getche() & 0x5f;
}
void ex_opt(char opt)
{
	char frm[10]; /* sir de caractere pentru identificarea formatului */

	float rvt;
	double rvd;
	long double rvld;
		putchar('\n');
		switch(opt) {
			case 'f':
			case 'F':
				printf(" Valoare (float, format de citere % %10f)?");
				scanf("%10f", &rvt);
				fflush(stdin);
				printf("Format de afisare: ");
				gets(frm);
				printf(frm, rvt);
				break;
			case 'D':
			case 'd':
				printf(" Valoare (double, format de citire % %15lf) ?");
				scanf("%20lf",&rvd);
				fflush(stdin);
				printf("Format de afisare: ");
				gets(frm);
				printf(frm, rvd);
				break;
			case 'l':
			case 'L':
				printf(" Valoare (long double, format citire % %20Ld) ?");
				scanf("%20Lf", &rvld);
				fflush(stdin);
				printf("Format de afisare: ");
				gets(frm);
				printf(frm, rvld);
				break;
			default:
				puts("Optiune incorecta");
		}
		putchar('\n');
}
void main()
{
	char opt; /* litera optiunii selectate */
	clrscr(); /* sterge ecranul */
	for (opt = menu(); opt != 'S'; opt = menu())
		ex_opt(opt);
}
