#include<iostream.h>

class baza
{
	protected:
		int i,j;	// protected pour la base mais accesible pour le derivate
	public:
		void pune(int a,int b) {i=a;j=b;}
		void arata() { cout<<i<<" "<<j<<"\n";}
	};
	class derivat: public baza
	{
		int k;
	public:
		void punek() {k=i*j;}
		void aratak() {cout<<k<<"\n";}
	};
	int main()
	{
		derivat ob;
		ob.pune(2,3);	//OK il est connue a derivate
		ob.arata();	//OK, il este connue a derivate
		ob.punek();
		ob.aratak();
	}
		