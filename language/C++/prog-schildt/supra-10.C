#include<iostream.h>
#include<stdlib.h>

class loc
{
	int longitud,latitud;
public:
	loc(){ longitud=latitud=0;}
	loc(int lg,int lt)
	{
		longitud=lg;
		latitud=lt;
	}
	void arata()
	{
		cout<<longitud<<" "<<latitud<<"\n";
	}
	void *operator new(size_t marime);
	void operator delete(void *p);
	void *operator new[](size_t marime);
	void operator delete[](void *p);
};
void *loc::operator new(size_t marime)
{
	cout<<"Dans new simple\n";
	return malloc(marime);
}
void loc::operator delete(void *p)
{
	cout<<"Dans delete simple\n";
	free(p);
}
void *loc::operator new[](size_t marime)
{
	cout<<"Il affecte memoire pour la matrice utise new[] propre\n";
	return malloc(marime);
}
void loc::operator delete[](void *p)
{
	cout<<"Elibre memorire de matrice utilise delete[] propre\n";
	free(p);
}
int main()
{
	loc *p1,*p2;
	int i;
	p1=new loc(10,20);
	if(!p1)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	p2=new loc[10];
	if(!p2)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	p1->arata();
	for(i=0;i<10;i++) p2[i].arata();
	delete p1;
	delete []p2;
}