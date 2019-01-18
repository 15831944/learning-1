#include<stdio.h>
#include<math.h>
#define EPSILON 1E-7
#define PI 3.1415926
float f(float);
float bisectie(float,float);
float bisectie(float a,float b)
{
	float c,fc;
	int sfa;
	sfa=(f(a)<0);
	do
	{
		c=(a+b)/2;
		fc=f(c);
		if((fc<0)==sfa) a=c;else b=c;
	}while(fabs(b-a)<=EPSILON && fabs(f(c))>=EPSILON);
	return c;
}
float f(float x)
{
	return (x-1)*(x+2)*(x-PI)*(x-2*PI);
}
int main()
{
	float a,b;
	printf("\n");
	do
	{
		printf("a=");scanf("%f",&a);
		printf("b=");scanf("%f",&b);
	}while(f(a)*f(b)>=0);
	printf("radacina este:%15.8f\n",bisectie(a,b));
}