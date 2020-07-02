/*
 * ilustreaza structura unui sir de caractere si utilizarea functiilor
 * printf si scanf
 */
#include <stdio.h>

void main(void)
{
	int i;
	/* sir de maximum 20 de caractere initializat cu 10 caractere
	 *str[10] are valoarea '\0'
	 */
	char str[21] = "abcd!?1234";
	/* afiseaza caracterele sirului */
	printf("Sirul contine intial caracterele: %s\n", str);
	printf("Si este memorat sub forma: ");
	/* afiseaza codurile ASCII ale sirului */
	for (i = 0; str[i]; i++)
		printf("%X ", str[i]);
	/* afiseaza terminatorul */
	printf("%X ", str[i]);
	/* se introduce de la tastatura un alt sir */
	printf("\nIntorduceti numele dvs: ");
	scanf("%s", str);
	printf("Sirul contine acum caracterele: %s\n", str);
	printf("Si este memorat sub forma: ");
	for (i = 0; str[i]; i++)
		printf("%X ", str[i]);
	printf("%X", str[i]);
}