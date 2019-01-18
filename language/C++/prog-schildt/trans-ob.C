#include<iostream.h>

class clasamea
{
	int i;
	int nr;
public:
	clasamea(int n,int nr);
	~clasamea();
	void pune_i(int n,int n1) {i=n;nr=n1;}
	void pune_i1(int n) {i=n;}
	int da_i() {return i;}
};

clasamea::clasamea(int n,int n1)
{
	i=n;
	nr=n1;
	cout<<"Construit "<<i<<"\n";
}

clasamea::~clasamea()
{
	cout<<"Il detruit "<<i<<":"<<nr<<"\n";
}

void f(clasamea ob);
	clasamea o(1,1);

int main()
{
	f(o);
	cout<<"C'est le i de main():"<<o.da_i()<<"\n";
}

void f(clasamea ob)
{
	ob.pune_i(2,2);
	cout<<"C'est le i local:"<<ob.da_i()<<"\n";
	o.pune_i1(3);
}
