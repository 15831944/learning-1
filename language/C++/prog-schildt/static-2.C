#include<iostream.h>

class comun{
public:
	static int a;
};
int comun::a;
int main()
{
	comun::a=99; //initialize avant creee l'objet
	cout<<"C'est la valeur initiale de a: "<<comun::a<<"\n";
	
	comun x;
	cout<<"C'est x.a "<<x.a<<"\n";
}