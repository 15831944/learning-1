#include<iostream.h>
#include<stdlib.h>

const int SIZE=10;
template<class stip> class atip
{
	stip a[SIZE];
public:
	atip()
	{
		register int i;
		for(i=0;i<SIZE;i++) a[i]=i;
	}
	stip &operator[](int i);
};
template <class stip> stip &atip<stip>::operator[](int i)
{
	if(i<0 || i>SIZE-1)
	{
		cout<<"\nLa valeur "<<i<<" de indice est dehors les limites.\n";
		exit(1);
	}
	return a[i];
}
int main()
{
	atip<int> intob;
	atip<double> doubleob;
	int i;
	cout<<"Matrice de int: ";
	for(i=0;i<SIZE;i++) intob[i]=i;
	for(i=0;i<SIZE;i++) cout<<intob[i]<<" ";
	cout<<"\n";
	cout<<"Matrice de double: ";
	cout.precision(2);
	for(i=0;i<SIZE;i++) doubleob[i]=(double)i/3;
	for(i=0;i<SIZE;i++) cout<<doubleob[i]<<" ";
	cout<<endl;
	intob[12]=100;
}