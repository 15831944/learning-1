#include<string.h>
#include<stdio.h>
put_in(char *d,char *s)
{
	while(*d++);
	*(d-1)=*s;
	*d='\0';
}
rev(char *p,char *q,int h)
{
	int i;
	for(i=0;i<h;i++) printf(" ");
	printf("Apel recursiv %d cu p: %s\n",h++,p);
	if(strlen(p)==1)
	{
		strcpy(q,p);
	}
	else
	{
		rev(p+1,q,h);
		put_in(q,p);
		for(i=0;i<h;i++) printf(" ");
		printf("Sfirsit apel recursiv %d cu q:%s\n",h,q);
	}
}
void main(int argc,char **argv)
{
	char buf[25];
	int h=0;
	if(argc<2)
	{
		printf("Utilizare: %s sirul_de_inversar\n",argv[0]);
		exit(-1);
	}
	rev(argv[1],buf,h);
	printf("Rezultat: %s\n",buf);
}
	