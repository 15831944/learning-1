#include<iostream.h>
template<class tip1,class tip2> class clasamea
{
	tip1 i;
	tip2 j;
public:
	clasamea(tip1 a,tip2 b) {i=a;j=b;}
	void arata() {cout<<i<<" "<<j<<endl;}
};
int main()
{
	clasamea<int,double> ob1(10,0.23);
	clasamea<char, char *> ob2('x',"Cette est un test.");
	ob1.arata();
	ob2.arata();
}