#include<string.h>
#include<stdio.h>
char *top(char *p)
{
	return p;
}
char *rest(char *p)
{
	return (p+1);
}
put_in(char *d,char *s)
{
	while(*d++);
	*(d-1)=*s;
	*d='\0';
}
rev(char *p,char *q)
{
	if(strlen(p)==1)
	{
		strcpy(q,p);
	}
	else
	{
		rev(rest(p),q);
		put_in(q,top(p));
	}
}
void main(int argc,char **argv)
{
	char buf[25];
	if(argc<2)
	{
		printf("Utilizare: %s sirul_de_inversar\n",argv[0]);
		exit(-1);
	}
	rev(argv[1],buf);
	printf("Rezultat: %s\n",buf);
}
	