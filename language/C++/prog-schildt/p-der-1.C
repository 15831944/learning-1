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
	derivat d;
	bp=&d;	//le pointer de base indiche vers l'objet derivate
	//acces a l'objet derivee utilize le pointer de base
	bp->pune_i(10);
	cout<<bp->da_i()<<" ";
	((derivat *)bp)->pune_j(88);
	cout<<((derivat *)bp)->da_j()<<"\n";
}