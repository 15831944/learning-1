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
	int &operator[](int i);
};
int &untip::operator[](int i)
{
	if(i<0||i>2)
	{
		cout<<"Erreur de limitations\n";
		exit(1);
	}
	return a[i];
}
int main()
{
	untip ob(1,2,3);
	cout<<ob[1];
	cout<<" ";
	ob[1]=25;
	cout<<ob[1];
	ob[3]=44;
}