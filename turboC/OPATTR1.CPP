/* atribuire si trunchieri */
#include <stdio.h>

void main()
{
	int i = 0x7fff;
	long k = 0x1234aaaa, m;
	float v;

	/* nedegradanta long <-- int */
	printf("%X ", m = i);
	printf("%X\n", m);
	/* degradanta int <-- long */
	printf("%X ", i = k);
	printf("%X\n", k);

	/* nedegradanta float <-- int */
	printf("%8.1lf ", v = 12345);
	printf("%8.1lf\n", v);

	/* degradanta long <-- double */
	printf("%ld ", k = 9876.54);
	printf("%ld\n",k);
}