#include<stdio.h>
main()
{
	long buf[50];
	double *p;
	struct orice {char buff[80];} s;
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(double));
	printf("%d\n",sizeof(double *));
	printf("%d\n",sizeof(struct orice));
	
	printf("%d\n",sizeof(buf));
	printf("%d\n",sizeof(buf[2]));
	printf("%d\n",sizeof(buf+1));
	printf("%d\n",sizeof(s.buff));
}