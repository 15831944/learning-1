#include<iostream.h>

class baza
{
protected:
	int i,j;
public:
	void pune(int a,int b) {i=a; j=b;}
	void arata() {cout<<i<<" "<<j<<"\n";}
};
class derivat1 : public baza 
{
	int k;
public:
	void punek() {k=i*j;} //il este legal
	void aratak() {cout<<k<<"\n";}
};
class derivat2 : public derivat1
{
	int m;
public:
	void punem() {m=i-j;} //c'est posibil
	void aratam() {cout<<m<<"\n";}
};
int main()
{
	derivat1 ob1;
	derivat2 ob2;
	
	ob1.pune(2,3);
	ob1.arata();
	ob1.punek();
	ob1.aratak();
	
	ob2.pune(3,4);
	ob2.arata();
	ob2.punek();
	ob2.punem();
	ob2.aratak();
	ob2.aratam();
}