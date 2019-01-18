#include<iostream.h>

class baza
{
public:
	virtual void vfunc()
	{
		cout<<"C'est vfunc() de base.\n";
	}
};
class derivat1: public baza
{
public:
	void vfunc()
	{
		cout<<"C'est vfunc() de derive1.\n";
	}
};
class derivat2: public derivat1
{
public:
	void vfunc()
	{
		cout<<"C'est vfunc() de derive2.\n";
	}
};

int main()
{
	baza *p,b;
	derivat1 d1;
	derivat2 d2;
//indique a base
	p=&b;
	p->vfunc(); //de base
	p=&d1;
	p->vfunc(); //de derive1
	p=&d2;
	p->vfunc();//de derive2
	b.vfunc();	//de base
	d1.vfunc();	//de derive1
	d2.vfunc();	//de derive2
}