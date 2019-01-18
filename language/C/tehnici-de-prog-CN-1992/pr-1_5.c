#include<stdio.h>
void swap(int *pa,int *pb)
{
	*pa^=*pb;
	*pb^=*pa;
	*pa^=*pb;
}
	
void main()
{
	int a=77,b=11;
	swap(&a,&b);
	printf("a=%d b=%d\n",a,b);
}