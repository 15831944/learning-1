// histograma.cpp : Defines the entry point for the console application.
//

#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>


int main(int argc, char* argv[])
{
	long *generate;
	double *intervals;
	double *probabilitati;
	double *cprob;
	long *relfreq;
	long nr,nre;
	double max,min;
	double genx;
	long *element;
	long innr,i,j,rnr;
	cout<<"Give the number of elements\n";
	cin>>nre;
	element=new long[nre];
	innr=0;
	cout<<"Give the elements\n";
	for(i=0;i<nre;i++)
	{
		cin>>element[i];
		innr+=element[i];
	}
	probabilitati=new double[nre];
	for(i=0;i<nre;i++)
		probabilitati[i]=element[i]/(double)innr;
	cprob=new double[nre];
	generate=new long[nre];
	cprob[0]=probabilitati[0];
	for(i=1;i<nre;i++)
	{
		cprob[i]=cprob[i-1]+probabilitati[i];
	}
//	for(i=0;i<nre;i++) cout<<cprob[i]<<endl;
	cout<<"Give the number of runtime\n";
	cin>>nr;
//	for(i=0;i<nre;i++) cout<<generate[i]<<endl;
	long *medie;
	long *dispersie;
	cout<<"Give the number of vectors\n";
	cin>>rnr;
	medie=new long[nre];
	dispersie=new long[nre];
	for(i=0;i<nre;i++) medie[i]=dispersie[i]=0;
	for(long k=0;k<rnr;k++)
	{
		for(i=0;i<nre;i++) generate[i]=0;
		for(j=0;j<nr;j++)
		{
			genx=(double)rand()/(double)RAND_MAX;
			for(i=0;i<nre;i++)
				if(genx<cprob[i]) break;
			generate[i]++;
		}
		for(i=0;i<nre;i++)
		{
			medie[i]+=generate[i];
			dispersie[i]+=generate[i]*generate[i];
		}
	}
	double *nprob;
	double *ndisp;
	nprob=new double[nre];
	ndisp=new double[nre];
	for(i=0;i<nre;i++)
	{
		nprob[i]=(double)medie[i]/(double)rnr;
		ndisp[i]=(double)dispersie[i]/(double)rnr-nprob[i]*nprob[i];
	}
	for(i=0;i<nre;i++)
		cout<<"prob orig "<<nr*probabilitati[i]<<" media calculata "<<nprob[i]<<endl;
	return 0;
}
