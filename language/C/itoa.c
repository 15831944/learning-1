#include<stdlib.h>
#include<stdio.h>
#include<itoa.h>
void main(void)
{
char str[10];
int test;
int i;
	test=-0xFFFFFFF;
	itoa(test,str,10);
	for(i=0;i<10;i++)
	{
		printf("%c ",str[i]);fflush(stdout);
	}
	for(i=0;i<10;i++) str[i]=' ';
	printf("\n");fflush(stdout);
}