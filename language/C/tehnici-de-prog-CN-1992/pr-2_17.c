#include<stdio.h>
#include<string.h>
#define MAX 256
char *citin(char *prompt)
{
	char *p,*q;
	int nc;
	unsigned size =MAX;
	char *malloc(),*realooc();
	if((p=q=malloc(size))==NULL)
	{
		printf("eroare malloc()\n");
		exit(1);
	}
	printf("%s",prompt);
	for(nc=1;(*p=getchar())!='\n'&&*p!=EOF;nc++)
	{
		if(nc%MAX==0)
		{
			size+=MAX;
			if((p=q=(char *)realloc(q,size))==NULL)
			{
				printf("eroare realoc()\n");
				exit(1);
			}
			p+=nc;
			continue;
		}
		p++;
	}
	*p='\0';
	return (char *)realloc(q,nc);
}
main()
{
	char *p,*citin();
	p=citin(">>");
	printf("sirul de intrare: %s\t lungime=%d\n",p,strlen(p));
}