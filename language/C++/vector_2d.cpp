// vector_2d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;


int main(int argc, char* argv[])
{
	double **probmat;
	double **yps;
	double *xp;
	double *x;
	double *y;
	double *temp;
	double ttemp;
	long xn,yn,i,j,k;
	cout<<"Input dimnesiunile \n";
	cout<<"dimY=un=)";
	cin>>yn;
	cout<<"dimX=xn=";
	cin>>xn;
	probmat=(double **)calloc(xn,sizeof(double *));
	temp=(double *)calloc(xn*yn,sizeof(double));
	for(i=0;i<xn;i++)
	{
		probmat[i]=temp;
		temp+=yn;
	}
	x=(double *)calloc(xn,sizeof(double));
	y=(double *)calloc(yn,sizeof(double));
	xp=(double *)calloc(xn,sizeof(double));
	yps=(double **)calloc(xn,sizeof(double *));
	temp=(double *)calloc(xn*yn,sizeof(double));
	for(i=0;i<xn;i++)
	{
		yps[i]=temp;
		temp+=yn;
	}
	cout<<"Input data X\n";
	for(i=0;i<xn;i++) cin>>x[i];
	cout<<"Input data Y\n";
	for(j=0;j<yn;j++) cin>>y[i];
	cout<<"Input probability matrix\n";
	for(i=0;i<xn;i++)
	{
		for(j=0;j<yn;j++)
		{
			cin>>probmat[i][j];
		}
	}
	for(i=0;i<xn;i++)
	{
		xp[i]=0.0;
		for(j=0;j<yn;j++)
			xp[i]=xp[i]+probmat[i][j];
	}
	cout<<"by x\n";cout.flush();
	for(i=1;i<xn;i++) xp[i]=xp[i-1]+xp[i]; //for prob
	for(i=0;i<xn;i++) cout<<xp[i]<<endl;cout.flush();
	for(i=0;i<xn;i++)
	{
		for(j=0;j<yn;j++)
			yps[i][j]=probmat[i][j]/xp[i];
		for(j=1;j<yn;j++)
			yps[i][j]=yps[i][j]+yps[i][j-1];
	}
	cout<<"Generate x\n";cout.flush();
	long nr;
	cout<<"How many run do you have\n";
	cin>>nr;
	double genx;
	for(k=0;k<nr;k++)
	{
		genx=(double)rand()/(double)RAND_MAX;
		for(i=0;i<xn;i++)
			if(genx<xp[i]) break;
		cout<<"X="<<x[i]<<endl;cout.flush();
		genx=(double)rand()/(double)RAND_MAX;
		for(j=0;j<yn;j++)
			if(genx<yps[i][j]) break;
		cout<<"Y="<<y[i]<<endl;cout.flush();
	}
	return 0;
}
