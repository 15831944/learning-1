#include<iostream.h>
void f();
int main()
{
	f();
	//clasamea il n'est pas conue ici
}
void f()
{
	class clasamea
	{
		int i;
		public:
			void pune_i(int n) {i=n;}
			int da_i() {return i;}
	} ob;
	
	ob.pune_i(10);
	cout<<ob.da_i();
}
		