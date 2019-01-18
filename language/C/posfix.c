#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *p;		//pointer catre o zona libera
int *vfs;	//pointer catre virful stivei
int *bzs;	//pointer catre baza stivei

//functia de introducere a unui element in stiva
void push(int i)
{
	if(p>bzs)
	{
		printf("Stiva este plina.\n");
		return;
	}
	*p=i;
	p++;
}

//functia de extragere a unui element din stiva
int pop(void)
{
	p--;
	if(p<vfs)
	{
		printf("Stiva este goala.\n");
		return 0;
	}
	return *p;
}

int main(void)
{
	int a,b;
	char s[80];
	
	p=(int *)malloc(MAX*sizeof(int));
	if(!p)
	{
		printf("Eroare de alocare.\n");
		exit (1);
	}
	vfs=p;		//virful stivei
	bzs=p+MAX-1;	//baza stivei
	printf("Calculator cu patru functii.\n");
	printf("Tastati q pentru a renunta.\n");
	do
	{
		printf(": ");
		gets(s);
		switch(*s)
		{
			case '+':
				a=pop();
				b=pop();
				printf("%d\n",b+a);
				push(b+a);
				break;
			case '-':
				a=pop();
				b=pop();
				printf("%d\n",b-a);
				push(b-a);
				break;
			case '*':
				a=pop();
				b=pop();
				printf("%d\n",b*a);
				push(b*a);
				break;
			case '/':
				a=pop();
				b=pop();
				if(a==0)
				{
					printf("Impartire cu zero.\n");
					break;
				}
				printf("%d\n",b/a);
				push(b/a);
				break;
			case '.':	//arata virful stivei
				a=pop();
				push(a);
				printf("Virful stivei este %d\n",a);
				break;
			default:
				push(atoi(s));
			}
		}while(*s!='q');
	}