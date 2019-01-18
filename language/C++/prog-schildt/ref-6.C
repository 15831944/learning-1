#include<iostream.h>

int main()
{
	int a;
	int &ref=a;	//reference independente
	a=10;
	cout<<a<<" "<<ref<<"\n";
	ref=100;
	cout<<a<<" "<<ref<<"\n";
	int b=19;
	ref=b;	//ce il pousse la valeur b dans a
	cout<<a<<" "<<ref<<"\n";
	ref--; //ce decremente a mais il ne touche pas la reference ref
	cout<<a<<" "<<ref<<"\n";
}
	