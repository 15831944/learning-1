#include<stdio.h>
int nivrec;
void push(unsigned int *p)
{
	fprintf(stderr,"push stiva %d:\tdigit=%d=%x\t&digit=%x\n",++nivrec,*p,*p,p);
}
void pop(unsigned int *p)
{
	fprintf(stderr,"pop stiva %d:\tdigit=%d=%x\t&digit=%x\n",nivrec--,*p,*p,p);
}
void itoh(unsigned int n)
{
	int digit;
	char *hex="0123456789abcdef";
	push(&n);
	if(digit=n/16) itoh(digit);
	putchar(hex[n%16]);
	pop(&n);
}
int main(int argc,char **argv)
{
	unsigned int num;
	if(argc==1)
	{
		fprintf(stderr,"Apel: %s numar\n",argv[0]);
		exit(1);
	}
	num=atoi(argv[1]);
	itoh(num);
	putchar('\n');
}