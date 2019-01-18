#include<iostream.h>

class baza
{
	int i,j;
public:
	void pune(int a,int b) {i=a; j=b;}
	void arata() {cout<<i<<" "<<j<<"\n";}
};
class derivat: private baza
{
	int k;
public:
	derivat(int x) {k=x;}
	void puned(int a,int b) {pune(a,b);}
	void aratak() {cout<<k<<"\n";arata();}
};
int main()
{
	derivat ob(3);
	ob.puned(1,2); //acces a membre de base
	ob.aratak();	//acces a membre de derive
}