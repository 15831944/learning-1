// mc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

int main(int argc, char* argv[])
{
	double val_pi,val_pi1,u;
	long N;
	long i;
	srand((unsigned)time(0));
	cout<<"Cite rulari\n";
	cin>>N;
	val_pi=0.0;
	val_pi1=0.0;
	for(i=0;i<N;i++)
	{
		u=rand()/(double)RAND_MAX;
		val_pi+=sqrt(1-pow(u,2));
		val_pi1+=sqrt(1-pow(u,2))+sqrt(1-pow(1-u,2));
	}
	val_pi=4*val_pi/N;
	val_pi1=2*val_pi1/N;
	cout<<"Val="<<val_pi<<":"<<val_pi1<<endl;
	double y,x;
	cout<<"Input x";
	cin>>x;
	double val;
	for(i=0;i<N;i++)
	{
		u=rand()/(double)RAND_MAX;
		y=ln((1+exp(-asin(1)*x/sqrt(3))/u-1)*sqrt(3)/(-asin(1)));

	return 0;
}
