#include<iostream.h>

class clasamea
{
public:
	int i;
	clasamea *operator->() {return this;}
};
int main()
{
	clasamea ob;
	ob->i=10;
	cout<<ob.i<<" "<<ob->i<<"\n";
}