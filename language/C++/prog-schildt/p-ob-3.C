#include<iostream.h>

class c1
{
public:
	int i;
	c1(int j) {i=j;}
};
int main()
{
	c1 ob(1);
	int *p;
	p=&ob.i;	//il prelue l'addresse de ob.i
	cout<<*p<<"\n";	//il a l'acces a ob.i par p
}