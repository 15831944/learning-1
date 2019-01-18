#include<stdio.h>
int main()
{
	printf("int=%d long=%d long long=%d float=%d double=%d long double=%d \n",sizeof(int),sizeof(long),sizeof(long long),sizeof(float),sizeof(double),sizeof(long double));
	fflush(stdout);
}