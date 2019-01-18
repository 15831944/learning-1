#include<iostream.h>

class baza1
{
protected:
	int i;
public:
	baza1(int x) {i=x; cout<<"Il construi la base1\n";}
	~baza1() {cout<<"Il destrui base1\n";}
	void test() {cout<<"testare\n";}
};
class baza2
{
protected:
	int k;
public:
	baza2(int x) {k=x; cout<<"Il contrui la base2\n";}
	~baza2() {cout<<"Il detruit baza2\n";}
};
class derivat: public baza2,private baza1
{
	int j;
public:
	baza1::test;
	derivat(int x,int y,int z): baza1(y),baza2(z) {j=x;cout<<"Il constui le derivat\n";}
	~derivat(){cout<<"Il detrui derive\n";}
	void arata(){cout<<i<<" "<<j<<" "<<k<<"\n";}
};
int main()
{
	derivat ob(3,4,5);
	ob.arata();
	ob.test();
}