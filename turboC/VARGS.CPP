/*
 * utilizare numar de parametri variabili
 * in va_Arg nu se folosesc tipurile: char, unsigned char, float
 * se folosesc in schimb valorile extinse int, double
 * functia max_n intoarce valoarea maxima dintr-un numar arbitrar de valori
 */
#include <stdarg.h>
#include <stdio.h>

double max_n(int np, ...)
{
	va_list ap;
	double mx, pr;
	int i;
	/* initializeaza  variabila ap */
	va_start(ap, np);
	/* citeste prima valoare */
	mx = va_arg(ap, double);
	for (i = 1; i  < np; i++) {
		/* citeste urmatoarele valori */
		pr = va_arg(ap, double);
		if (mx < pr) mx = pr;
	}
	/* termina citirea parametrilor */
	va_end(ap);
	return mx;
}

void main()
{
	float t[10] = { 1.2, 9.4, -3.5, 2.7, 1e9, 100.5, 22.39, 33.12, 27, -2.6};
	double r;
	r = max_n(4,t[0], t[9], 5.5,17.2);
	/* n = 4 valori */
	printf("%8.2lf\n",r);
}