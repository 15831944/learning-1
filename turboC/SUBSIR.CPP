/* exemplu de functie care returneaza pozitia subsirului */
#include <stdio.h>

int subsir(char *sub, char *str)
{
	int i;
	char *p1, *p2;
	for(i = 0; str[i] != '\0'; i++) {
		/* cauta inceputul subsirului */
		p1 = &str[i];
		p2 = sub;
		while (*p2 && *p2 == *p1) {
			/* compara cu sub */
			p1++;
			p2++;
		}
		if (*p2 != '\0')
			return i; /* subsirul incepe la sir[i] */
	}
	return -1; /* nu exista subsirul sub in sir */
}

void main()
{
	char sir[21], s[4]="tst";
	puts("Introduceti un sir de maximum 20 de caractere: ");
	scanf("%20s",sir);
	if(subsir(s,sir) >= 0) puts("Ati cistigat !");
	else puts("Ati pierdut !");
}
