#include<iostream.h>

class clasamea
{
	int i;	
public:
	int nr;
	void pune_i(int n) {i=n;}
	int da_i() {return i;}
	clasamea();
	clasamea(int n,int n1);
	~clasamea();
};
clasamea::clasamea()
{
	cout<<"Il contruit "<<i<<"\n";
}
clasamea::clasamea(int n,int n1)
{
	i=n;
	nr=n1;
	cout<<"Il contruit "<<i<<":"<<nr<<"\n";
}
clasamea::~clasamea()
{
	cout<<"Il detruit "<<i<<":"<<nr<<"\n";
}

clasamea f();	//il returne un obiect de type clasamea
int main()
{
//	clasamea o;
//	o=f();
	clasamea o=f();
	cout<<o.da_i()<<"\n";
	o.nr=2;
}
clasamea f()
{
	clasamea x(1,1);
	x.pune_i(1);
	return x;
}