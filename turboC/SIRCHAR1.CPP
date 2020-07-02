/* se solicita introducerea de la tastatura a unui nume,
 * il memoreaza intr-o variabila si apoi afiseaza octec cu octet
 * in hexa informatia memorata
 */
#include <stdio.h>
#define N 11
void main(void)
{
	char nume[N];
	int i;
	puts("Introduceti numele dumneavoastra: ");
	gets(nume);
	printf("%s este memorat in variabila nume prin secventa de coduri ASCII:\n", nume);
	i = 0;
	while (nume[i] > 0) {
		printf("%X ", nume[i]);
		i = i + 1;
	}
	/* afiseaza terminatorul '\0' */
	printf("%X\n", nume[i]);
}