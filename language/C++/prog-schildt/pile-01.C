#include<iostream.h>
#define SIZE 100
//Cette cree la classe pile
class stiva
{
	int stiv[SIZE];
	int vis;
public:
	void init();
	void pune(int i);
	int scoate();
};

void stiva::init()
{
	vis=0;
}

void stiva::pune(int i)
{
	if(vis==SIZE)
	{
		cout<<"La pile c'est plein.";
		return;
	}
	stiv[vis]=i;
	vis++;
}

int stiva::scoate()
{
	if(vis==0)
	{
		cout<<"Depasse inferieure.";
		return 0;
	}
	vis--;
	return stiv[vis];
}

int main()
{
	stiva stiva1,stiva2; //cree deux object "stiva"
	stiva1.init();
	stiva2.init();
	
	stiva1.pune(1);
	stiva2.pune(2);
	stiva1.pune(3);
	stiva2.pune(4);
	
	cout<<stiva1.scoate()<<" ";
	cout<<stiva1.scoate()<<" ";
	cout<<stiva2.scoate()<<" ";
	cout<<stiva2.scoate()<<"\n";
	return 0;
}