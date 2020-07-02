/*
 * cimpuri de biti:
 * tipul poate fi int, signed sau unsigned
 * lungimea este o constanta intreaga cu valoarea in domeniul 0-15
 * nu se poate evalua adresa unui cimp deci & nu poate avea ca operatie
 * nu se poate organiza tablouri  de cimpuri de biti
 * domeniul se calculeaza signed int: -2^(n-1) <= V <= 2^(n-1) -1
 * pentru unsigned int: 0 <= V <= 2^(n-1)
 */
#include <stdio.h>
typedef struct {
	unsigned char adr;
	unsigned c_i:1;
	unsigned ns:3;
	unsigned pf:1;
	unsigned nr:3;
	unsigned lng;
	char * data;
} cadru_i;
void main()
{
	cadru_i cadru = {0xff, 0, 7, 0, 7, 0xffff, 0};
	char *p;
	int i, j;
	/* afiseaza membrii varibilei cadru */
	printf("adr = %x,c_i=%d,ns=%d,pf=%d,nr=%d, lng=%x, data=%p\n",
		cadru.adr, cadru.c_i, cadru.ns, cadru.pf, cadru.nr, cadru.lng, cadru.data);
	/* afiseaza in binar, octet cu octet, variabila cadru */
	for(i =0, p = (char *)&cadru; i < sizeof(cadru_i); i++, p++) {
		for(j=7; j >= 0; j--)
			printf("%d", (*p>>j) & 1);
		/* afiseaza bitul j */
		putchar('\n');
		/* linie noua */
	}
}