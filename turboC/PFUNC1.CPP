/*
 * compara doua siruri de caractere si afiseaza relatia dintre ele.
 * in acest scop se foloseste functia test() care primeste ca parametrii
 * adresele sirurilor si un pointer catre o functie care reprezinta
 * criteriul de comparare
 */
#include <stdio.h>
void test(char *a, char *b, int(*cmp)(char *, char *));
/* criteriu de comparatie */
int comp(char *s1,char *s2);
void main()
{
	char s1[80], s2[80];
	int (*p)(char *, char *);
	/* atribui lui p adresa functiei comp() */
	p = comp;
	puts("Introduceti primul sir ");
	gets(s1);
	puts("Introduceti al doile sir ");
	gets(s2);
	/* compara sirurile s1, s2 folosind functia comp()*/
	test(s1,s2,p);
}
void test(char *a, char *b, int(*cmp)(char *, char *))
{
	if (!(*cmp)(a,b))
		printf("s1 egal cu s2");
	else
		printf("s1 diferit de s2");
}

int comp(char *s1, char *s2)
{
	/* compara doar primul caracter */
	return s1[0]-s2[0];
}