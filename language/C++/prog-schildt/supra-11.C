#include<iostream.h>

class untip
{
	int a[3];
public:
	untip(int i,int j,int k)
	{
		a[0]=i;
		a[1]=j;
		a[2]=k;
	}
//	int operator[](int i) {return a[i];}
	int &operator[](int i) {return a[i];}
};
int main()
{
	untip ob(4,5,6);
	for(int i=0;i<3;i++)	cout<<ob[i]<<"\n";
	for(int i=0;i<3;i++) ob[i]=i;
	for(int i=0;i<3;i++)	cout<<ob[i]<<"\n";	
}