#include<stdio.h>
#define CUVDIM sizeof(unsigned int)*8
unsigned int rol(unsigned int word,int n)
{
	return word<<n|(word>>CUVDIM-n);
}
unsigned int ror(unsigned int word,int n)
{
	return word>>n|(word<<CUVDIM-n);
}
void main()
{
	unsigned int num;
	printf("Introduceti un nr hexa:");
	scanf("%x",&num);
	printf("Rotire la stinga 8 biti=%x\n",rol(num,8));
	printf("Rotire la dreapta 4 biti=%x\n",ror(num,4));
}