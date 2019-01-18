#include<stdio.h>
#define NSTACK 20
char stack[NSTACK],*pstk=stack;
push(char d)
{
	if(pstk>=stack+NSTACK) exit(1);
	*pstk++=d;
}
pop()
{
	if(pstk<=stack) return EOF;
	return *--pstk;
}

main()
{
	char *p="emit are";
	int i;
	while((i=*p++)!='\0') push(i);
	while((i=pop())!=EOF) putchar(i);
	putchar('\n');
}