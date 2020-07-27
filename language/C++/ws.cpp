// ws.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	double atp,stp,at,st;
	double wt,tid,ttid,twt;
	long icount,ns;
	cout<<"Input atp=";
	cin>>atp;
	cout<<"Input stp=";
	cin>>stp;
	cout<<"Input ns=";
	cin>>ns;
	tid=0;
	ttid=0;
	twt=0;
	wt=0;
	cout<<icount<<endl;
	icount=0;
	while(icount<ns)
	{
		at=-log(rand()/(double)RAND_MAX)/atp;
		at=at-wt;
		st=-log(rand()/(double)RAND_MAX)/stp;
		icount++;
		if(st>at)
		{
			tid=0;
			wt=st-at;
			twt=twt+wt;
		}
		else
		{
			wt=0;
			tid=at-st;
			ttid+=tid;
		}
	}
	cout<<"AWT="<<twt/ns<<endl;
	cout<<"ATID="<<ttid/ns<<endl;

	return 0;
}
