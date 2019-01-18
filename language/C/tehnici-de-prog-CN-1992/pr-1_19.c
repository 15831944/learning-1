#define N 10
#include<stdio.h>
void hanoi(int *,int *,int *,int);
void mutare(int *,int *);
int pop(int *);
void push(int *,int);
void print(void);
void prints(char,int *);

int sa[N]={9,9,8,7,6,5,4,3,2,1};
int sb[N];
int sc[N];
main(void)
{
	int m;
	sa[0]=m=3;
	print();
	hanoi(sa,sb,sc,m);
}
void hanoi(int *a,int *b,int *c,int n)
{
	if(n==1) mutare(a,b);
	else
	{
		hanoi(a,c,b,n-1);
		mutare(a,b);
		hanoi(c,b,a,n-1);
	}
}
void mutare(int a[],int b[])
{
	push(b,pop(a));
	print();
}
int pop(int s[])
{
	if(s[0]==0) printf("pop:stiva vida\n");
	else return(s[(s[0]--)]);
}
void push(int s[],int e)
{
	s[++s[0]]=e;
}
void print(void)
{
	prints('A',sa);
	prints('B',sb);
	prints('C',sc);
	putchar('\n');
}
void prints(char c,int *s)
{
	int i;
	printf("%c:",c);
	for(i=0;i<s[0];i++) printf("%2d",s[i+1]);
	putchar('\n');
}