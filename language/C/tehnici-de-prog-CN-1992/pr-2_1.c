#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main(int argc,char **argv)
{
	double baza,exponent;
	double (*mtab[10])();
	if(argc!=3)
	{
		printf("Utilizare: %s baza exponent\n",argv[0]);
		exit(1);
	}
	baza=atof(argv[1]);
	exponent=atof(argv[2]);
	mtab[0]=pow;
	printf("%g^%g=%g\n",baza,exponent,(*mtab[0])(baza,exponent));
}