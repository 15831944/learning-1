#include<iostream.h>
#include<stdlib.h>

class loc
{
	int longitud,latitud;
public:
	loc() {}
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
};
//new is supracharge relative a loc
void *loc::operator new(size_t marime)
{
	cout<<"Dans mon new\n";
	return malloc(marime);
}
void loc::operator delete(void *p)
{
	cout<<"Dans ma delete\n";
	free(p);
}
int main()
{
	loc *p1,*p2;
	p1=new loc(10,20);
	if(!p1)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	p2=new loc(-10,-20);
	if(!p2)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	p1->arata();
	p2->arata();
	delete p1;
	delete p2;
}