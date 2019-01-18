#include<iostream.h>

class c1
{
	public:
		c1(int i) {val=i;}
		int val;
		int val_dubla() {return val+val;}
};

int main()
{
	int c1::*date;	//pointer a une donne membre
	int (c1::*func)(); //pointer a une function membre
	c1 ob1(1),ob2(2);
	date=&c1::val;	//il donne le offset pour val
	func=&c1::val_dubla;	//il donne le offset pour val_double()
	
	cout<<"Voila les valeurs: ";
	cout<<ob1.*date<<" "<<ob2.*date<<"\n";
	cout<<"Ici ils sont double: ";
	cout<<(ob1.*func)()<<" "<<(ob2.*func)()<<"\n";
}