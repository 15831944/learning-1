#include<iostream.h>

class cl
{
public:
	cl(int i) {val=i;}
	int val;
	int val_dubla() {return val+val;}
};
int main()
{
	int cl::*date;	//pointer a unde donne membre
	int (cl::*func)();	//pointer a une function membre
	cl ob1(1),ob2(2);	//cree objets
	cl *p1,*p2;
	
	p1=&ob1;
	p2=&ob2;
	
	date=&cl::val;	//il donne l'offset pour val
	func=&cl::val_dubla; //il donne l'offset pur val_duble()
	cout<<"Voici les values: ";
	cout<<p1->*date<<" "<<p2->*date<<"\n";
	cout<<"Ici les values sont double: ";
	cout<<(p1->*func)()<<" "<<(p2->*func)()<<"\n";
}