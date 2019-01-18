#include<iostream.h>

class numar
{
protected:
	int val;
public:
	void puneval(int i) {val=i;}
	virtual void arata()=0;
};
class tiphex:public numar
{
public:
	void arata()
	{
		cout<<hex<<val<<"\n";
	}
};
class tipdec:public numar
{
public:
	void arata()
	{
		cout<<val<<"\n";
	}
};
class tipoct:public numar
{
public:
	void arata()
	{
		cout<<oct<<val<<"\n";
	}
};
int main()
{
	tipdec d;
	tiphex h;
	tipoct o;
	d.puneval(20);
	d.arata();	//il affiche 20 zecimal
	h.puneval(20);
	h.arata();	//il affiche 14 hexa
	o.puneval(20);
	o.arata(); 	//il affiche 24 oct
}