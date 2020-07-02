/*
 * program care solicita introducerea a trei valori reale si verifica
 * daca acesea pot fi laturile unui triunghi.
 */
#include <stdio.h>

void main()
{
	float a, b,c;
	int t;
	printf("Introduceti 3 valori reale: ");
	scanf("%f%f%f", &a, &b, &c);
	t = !((a <= 0) || (b <= 0) || (c <= 0));
	t = t && (a < b + c) && (b < a + c) && (c < a + b);
	printf("%d\n", t);
	if (!t)
		printf("nu ");
	printf("pot fi lungimile laturilor unui triunghi !\n");
}