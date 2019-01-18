#include<sys/types.h>
#include<unistd.h>
#include<sys/times.h>
#include<stdio.h>
#include"temps1.c"

int main()
{
struct timeval t1,t2;
int i;
//	for(i=0;i<2;i++)
//	{
//		gettimeofday(&t1,NULL);
//		sleep(6);
//		gettimeofday(&t2,NULL);
//		speedup(t1,t2,1);
//	}
	for(i=0;i<2;i++)
	{
		gettimeofday(&t1,NULL);
		usleep(185000);
		gettimeofday(&t2,NULL);
		speedup(t1,t2,1);
	}
}