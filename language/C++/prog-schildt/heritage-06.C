#include<iostream.h>

class baza1
{
protected:
	int x;
public:
	void aratax() {cout<<x<<"\n";}
};
class baza2
{
protected:
	int y;
public:
	void aratay() {cout<<y<<"\n";}
};
class derivat:public baza1,public baza2
{
public:
	void pune(int i,int j) {x=i; y=j;}
};
int main()
{
	derivat ob;
	ob.pune(10,20); //il este assigure par derivate
	ob.aratax();	//de baza1
	ob.aratay();	//de baza2
}