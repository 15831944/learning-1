#include<stdio.h>
int f(int *p) {return (*p)++;}
int main()
{
	int x=1,y=2;
	y=f(&x); printf("x=%d y=%d \n",x,y);
	y=f(&x); printf("x=%d y=%d \n",x,y);
}