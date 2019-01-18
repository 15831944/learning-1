#include<iostream.h>

class baza
{
	int i,j;
public:
	void pune(int a,int b) {i=a; j=b;}
	void arata() {cout<<i<<" "<<j<<"\n";}
};
class derivat: public baza
{
	int k;
public:
	derivat(int x) {k=x;}
	void aratak() {cout<<k<<"\n";}
};
int main()
{
	derivat ob(3);
	ob.pune(1,2); //acces a membre de base
	ob.arata();		//acces a membre de base
	ob.aratak();	//acces a membre de derive
}