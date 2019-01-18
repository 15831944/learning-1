#include<iostream.h>

class c1
{
	int i;
public:
	c1(int j) {i=j;}
	int da_i() {return i;}
};

int main()
{
	c1 ob(88), *p;
	p=&ob;//il donne l'addresse de ob
	cout<<p->da_i()<<"\n";	//il utilize -> pour apelle da_i()
}