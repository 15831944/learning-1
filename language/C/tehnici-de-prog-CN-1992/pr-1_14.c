#include<stdio.h>
int incerc(int i,int x,int);
void print(void);
#define N 5
#define NP 25
#define LIBER 0
#define SUCCES 1
#define ESEC 0
static int a[8]={2,1,-1,-2,-2,-1,1,2};
static int b[8]={1,2,2,1,-1,-2,-2,-1};
int h[N][N];

void main(void)
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			h[i][j]=LIBER;
	h[0][0]=1;
	if(incerc(2,0,0)==SUCCES) print();
	else printf("Problema nu are solutie\n");
}
int incerc(int i,int x,int y)
{
	int k,xu,yu,q;
	for(k=0,q=ESEC;q==ESEC && k<8;k++)
	{
		xu=x+a[k];
		yu=y+b[k];
		if(xu>=0 && xu<N && yu>=0 && yu<N)
			if(h[xu][yu]==LIBER)
			{
				h[xu][yu]=i;
				if(i<NP){ if((q=incerc(i+1,xu,yu))==ESEC) h[xu][yu]=LIBER;}
				else q=SUCCES;
			}	
	}
//	printf("%d \n",q);
	return q;
}
void print()
{
	int i,j,k;
	for(k=0;k<N;k++) printf("-----");
	putchar('\n');
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++) printf("| %2d",h[i][j]);
		printf("|\n");
		for(j=0;k<N;k++) printf("-----");
		putchar('\n');
	}
}