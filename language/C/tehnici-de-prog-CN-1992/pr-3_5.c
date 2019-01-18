#include<stdio.h>
main()
{
	char cbuf[80],*p=cbuf;
	float fbuf[80],*q=fbuf;
	printf("cbuf=%u &cbuf[5]=p+5=%u\n",cbuf,p+5);
	printf("fbuf=%u &fbuf[5]=q+5=%u\n",fbuf,q+5);
	printf("&cbuf[5]=%u\n",(char *)p+5*sizeof(char));
	printf("&fbuf[5]=%u\n",(float *)q+5*sizeof(float));
}