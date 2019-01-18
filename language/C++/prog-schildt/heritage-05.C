#include<iostream.h>

class baza
{
protected:
	int i,j; //protected pour baza,mai accesibil pour derivate
public:
	void puneij(int a,int b) {i=a; j=b;}
	void arataij() {cout<<i<<" "<<j<<"\n";}
};
class derivat1:protected baza
{
	int k;
public:
	void punek() {puneij(10,12); k=i*j;}
	void aratatot() {cout<<k<<" "; arataij();}
};
int main()
{
	derivat1 ob;
	ob.punek();
	ob.aratatot();
}