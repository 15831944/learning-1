#include<stdio.h>
void main()
{
	unsigned int num,d;
	int i=0;
	char buf[10];
	printf("Introduceti numarul:");
	scanf("%u",&num);
	for(;num;num/=16)
	{
		d=num%16;
		buf[i++]=(d<=9)?d+'0':d+'a'-10;
	}
	for(;i;) putchar(buf[--i]);
	putchar('\n');
}