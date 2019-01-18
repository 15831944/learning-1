#include<stdio.h>
#include<math.h>
double (*tab[])(double)={sin,cos,tan,exp,log,log10};
int main()
{
	int i;
	double x;
	for(x=0.01;x<1.01;x+=0.1)
	{
		for(i=0;i<sizeof(tab)/sizeof(tab[0]);i++)
		 printf("%lf ",(*tab[i])(x));
		 printf("\n");
	}
}