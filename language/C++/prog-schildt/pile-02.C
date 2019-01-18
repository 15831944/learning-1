#include<iostream.h>
#define SIZE 100

//cette creee la clase stiva
class stiva
{
	int stiv[SIZE];
	int vis;
public:
	stiva();		//constructeur
	~stiva();	//destructeur
	void pune(int i);
	int scoate();
};

//la function constructeur pour stiva
stiva::stiva()
{
	vis=0;
	cout<<"La pile c'est initialize\n";
}
//la function destructeur pour stiva
stiva::~stiva()
{
	cout<<"La pile c'est detruite\n";
}
void stiva::pune(int i)
{
	if(vis==SIZE)
	{
		cout<<"La pile c'est plein\n";
		return;
	}
	stiv[vis]=i;
	vis++;
}
int stiva::scoate()
{
	if(vis==0)
	{
		cout<<"Depasse inferieure\n";
		return 0;
	}
	vis--;
	return stiv[vis];
}

int main()
{
	stiva a,b;//il cree deux objects stiva
	
	a.pune(1);
	b.pune(2);
	a.pune(3);
	b.pune(4);
	
	cout<<a.scoate()<<" ";
	cout<<a.scoate()<<" ";
	cout<<b.scoate()<<" ";
	cout<<b.scoate()<<"\n";
}