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
};
//new et detele global
void *operator new(size_t marime)
{
	cout<<"Dans new\n";
	return malloc(marime);
}
void operator  delete(void *p)
{
	cout<<"Dans delete\n";
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
	p2=new loc(-10,20);
	if(!p2)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	float *f=new float;
	if(!f)
	{
		cout<<"Erreur d'affecte\n";
		exit(1);
	}
	*f=10.10;
	cout<<*f<<"\n";
	p1->arata();
	p2->arata();
	delete p1;
	delete p2;
	delete f;
}