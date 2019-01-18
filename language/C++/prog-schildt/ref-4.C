#include<iostream.h>

class cl
{
	int ex;
public:
	int i;
	cl(int i);
	~cl();
	void neg(cl &o) {o.i=-o.i;}
};
cl::cl(int num)
{
	cout<<"Il contruit "<<num<<"\n";
	ex=num;
}
cl::~cl()
{
	cout<<"Il detruit "<<ex<<"\n";
}
int main()
{
	cl o(1);
	o.i=10;
	o.neg(o);
	cout<<o.i<<"\n";
}