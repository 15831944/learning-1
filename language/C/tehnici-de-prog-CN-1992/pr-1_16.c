#include<stdio.h>
main()
{
	union
	{
		unsigned short num;
		unsigned char s[2];
	} val;
	char *p="0123456789abcdef";
	printf("Introduceti un numar:");
	scanf("%d",&val.num);
	putchar(p[val.s[1]>>4]);
	putchar(p[val.s[1]&15]);
	putchar(p[val.s[0]>>4]);
	putchar(p[val.s[0]&15]);
	putchar('\n');
}