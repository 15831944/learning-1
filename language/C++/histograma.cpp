// histograma.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<fstream>

using namespace std;

int main(int argc, char* argv[])
{
	double *generate;
	double *intervals;
	int *relfreq;
	int nr;
	double max,min;
	int innr,i,j;
	double genu,geny;
	cout<<"Give the number of values nr=";
	cin>>nr;

	cout<<"Give the number of desired intervals ";
	cin>>innr;
	intervals=new double[innr];
	relfreq=new int[innr];
	for(i=0;i<innr;i++) relfreq[i]=0;
	max=generate[0];
	min=generate[0];
	for(i=0;i<nr;i++)
	{
		if(max<generate[i]) max=generate[i];
		if(min>generate[i]) min=generate[i];
	}
	intervals[0]=min;
	intervals[innr-1]=max;
	double step;
	step=(max-min)/(innr-1);
	for(i=1;i<innr-1;i++)
		intervals[i]=intervals[i-1]+step;
	for(j=0;j<nr;j++)
	{
		for(i=1;i<innr;i++)
			if(intervals[i-1]<generate[j] && intervals[i]>=generate[j] )
			{
				relfreq[i]++;
				break;
			}
			
	}
	cout<<"The histogram is\n";
	for(i=1;i<innr;i++)
		cout<<"In ["<<intervals[i-1]<<","<<intervals[i]<<"] we have "<<relfreq[i]<<endl;
	ofstream fp;
	fp.open("weibul.txt");
	for(i=1;i<innr;i++)
	fp<<(intervals[i]-intervals[i-1])/2<<" "<<relfreq[i]<<endl;
	fp.close();
	for(i=0;i<nr;i++)
	{
		do
		{
			geny=log(rand()/(double)RAND_MAX);
			genu=rand()/(double)RAND_MAX;
		}
		while(0<=genu && genu<=exp(-geny*geny/2+geny-1/2));
		if(rand()/(double)RAND_MAX<0.5) generate[i]=geny;
		else generate[i]=-geny;
	}
	for(i=0;i<innr;i++) relfreq[i]=0;
	max=generate[0];
	min=generate[0];
	for(i=0;i<nr;i++)
	{
		if(max<generate[i]) max=generate[i];
		if(min>generate[i]) min=generate[i];
	}
	intervals[0]=min;
	intervals[innr-1]=max;
	step=(max-min)/(innr-1);
	for(i=1;i<innr-1;i++)
		intervals[i]=intervals[i-1]+step;
	for(j=0;j<nr;j++)
	{
		for(i=1;i<innr;i++)
			if(intervals[i-1]<generate[j] && intervals[i]>=generate[j] )
			{
				relfreq[i]++;
				break;
			}
			
	}
	cout<<"The histogram is\n";
	for(i=1;i<innr;i++)
		cout<<"In ["<<intervals[i-1]<<","<<intervals[i]<<"] we have "<<relfreq[i]<<endl;
	fp.open("gauss.txt");
	for(i=1;i<innr;i++)
	fp<<(intervals[i]-intervals[i-1])/2<<" "<<relfreq[i]<<endl;
	fp.close();

	delete []generate;
	delete []relfreq;
	delete []intervals;
	return 0;
}
