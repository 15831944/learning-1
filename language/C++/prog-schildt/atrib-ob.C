#include<iostream.h>

class clasamea
{
	int i;
public:
	void pune_i(int n) {i=n;}
	int da_i() {return i;}
};

int main()
{
	clasamea ob1,ob2;
	
	ob1.pune_i(99);
	ob2=ob1;	//il atribue les done de ob1 a ob2
	cout<<"C'est le i de ob2: "<<ob2.da_i()<<"\n";
}