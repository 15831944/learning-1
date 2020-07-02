/*
 * programul afiseaza pe ecran textul din sirul de caractere msg
 * reprezentind declaratiile a trei tablouri char s[8], long v[4]
 * si float m[4][4]
 * se afiseaza pentru fiecare in parte dimensiunea si adresele
 * zonei rezervate in memorie impreuna cu adresele si valorile
 * fiecarui element.
 */
#include <stdio.h>
#include <conio.h>

char msg[] = "Analiza structurii de date:\n"
		" char s[8]=\"Exemplu\";\n"
		" long v[4]={0,1,2,3};\n"
		" float m[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};\n";
char s[8] = "Exemplu";
long v[4] = {0,1,2,3};
float m[4][4]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void main()
{
	float *fp;
	int i = 0;
	int j;
	char c;
	clrscr();
	puts(msg);
	printf("s[8] contine %d octeti", sizeof(s));
	printf(" intre adresele: %p - %p\n", s,&s[7]);
	for(i = 0; i < 8; i++)
		printf("s[%d] - %p: %c = %#x\n", i, s + i, *(s+i),*(s+i));
	getch();
	/* asteapta apasarea unei taste */
	printf("v[4] contien %d octeti", sizeof(v));
	printf(" intre adresele: %p - %p\n",v, (char *)&v[4]-1);
	for(i = 0; i < 4; i++)
		printf("v[%d] - %p: %ld\n", i, v+i, *(v+i));
	getch();
	fp = (float *)m;
	printf("m[4][4] contine %d octeti", sizeof(m));
	printf(" intre adresele: %p - %p\n", m, (char *)&m[3][4] -1);
	for(i = 0; i < 4; i++) {
		printf(" (m+%d)=%p\n", i, m+i);
		for(j = 0; j < 4; j++, fp++)
			printf("m[%d][%d] - %p: %4.2f\n", i, j, fp, *fp);
	}
	getch();
	printf("\nMesajul msg[] contine %d caractere, intre adresele %p -%p\n",
		sizeof(msg), msg, msg+ sizeof(msg) -1);
	getch();
}