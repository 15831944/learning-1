#include<iostream.h>

class c1
{
	int h;
	int i;
public:
	c1(int j,int k);
	~c1();
	int ia_i() {return i;}
	int ia_h() {return h;}
};

c1::c1(int j,int k)
{
	h=k;
	i=k;
	cout<<"Il construit:i="<<i<<" h="<<h<<"\n";
}
c1::~c1()
{
	cout<<"Il detruit:i="<<i<<" h="<<h<<"\n";
}
int main()
{
	c1 ob[3]={ c1(1,2),c1(3,4),c1(5,6)}; //initialization
	int i;
	for(i=0;i<3;i++)
		cout<<ob[i].ia_h()<<","<<ob[i].ia_i()<<"\n";
}