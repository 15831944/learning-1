#include<stdio.h>
#include<setjmp.h>

#define CTRLL '\014'
#define ESCK '\033'
#define MAX 11
jmp_buf jmp_mediu;
void getlinie(char *buf)
{
	int nc=0,ch;
	do
	{
		ch=mygetch();
		printf("%c",ch);
		if(nc==MAX) longjmp(jmp_mediu,1);
		buf[nc++]=(ch=='\n') ?'\0':ch;
	}while(ch!='\n');
}
int mygetch(void)
{
	int c;
	c=getch();
	if(c==CTRLL) longjmp(jmp_mediu,2);
	if(c==ESCK) longjmp(jmp_mediu,3);
	return(c=='\r') ? '\n':c;
}
main()
{
	int retval;
	int linie=1;
	char buf[MAX],ch;
	retval=setjmp(jmp_mediu);
	if(retval!=0)
	{
		switch(retval)
		{
			case 1:
				printf("\t linie prea lunga - se ignora\n");
				break;
			case 2:
				printf("\t\tlinia se ignora\n");
				break;
			case 3:
				printf("\t\texit ?[d]:");
				ch=getch();
				printf("%dc\n",ch);
				if(ch=='d') exit(1);
		}
	}
	printf("Linia %2d:\t",linie);
	while(1)
	{
		getlinie(buf);
		printf("Linia %2d:\t",++linie);
	}
}