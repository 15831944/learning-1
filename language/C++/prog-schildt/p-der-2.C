#include<iostream.h>

class baza
{
	int i;
public:
	void pune_i(int num) {i=num;}
	int da_i() {return i;}
};
class derivat: public baza
{
	int j;
public:
	void pune_j(int num) {j=num;}
	int da_j() {return j;}
};
int main()
{
	baza *bp;
	derivat d[2];
	bp=d;
	d[0].pune_i(1);
	d[1].pune_i(2);
	cout<<bp->da_i()<<" ";
	bp++; //	relative a base, n'est pas a la clase derive
	cout<<bp->da_i()<<"\n";	//il affiche un vleur eronne
}