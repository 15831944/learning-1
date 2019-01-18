#include<stdio.h>
int f(int a,int *p) {a=--(*p);return a;}
int main()
{
	int x=1,y=2;
	y=f(y,&x); printf("x=%d y=%d\n",x,y);
	y=f(y,&x); printf("x=%d y=%d\n",x,y);
}
	