#include<iostream.h>
const int SIZE =100;
template <class stip> class stiva
{
	stip stv[SIZE];
	int vis;
public:
	stiva();
	~stiva();
	void pune(stip i);
	stip scoate();
};
template <class stip> stiva<stip>::stiva()
{
	vis=0;
	cout<<"La pille est initialise\n";
}
template <class stip> stiva<stip>::~stiva()
{
	cout<<"La pille est detruite\n";
}
template <class stip> void stiva<stip>::pune(stip i)
{
	if(vis==SIZE)
	{
		cout<<"La pille c'est pleine.\n";
		return;
	}
	stv[vis]=i;
	vis++;
}
template<class stip> stip stiva<stip>::scoate()
{
	if(vis==0)
	{
		cout<<"La pille c'est vide.\n";
		return 0;
	}
	vis--;
	return stv[vis];
}
int main()
{
	stiva<int> a;
	stiva<double> b;
	stiva<char> c;
	int i;
	a.pune(1);
	b.pune(99.2);
	a.pune(2);
	b.pune(-12.23);
	
	cout<<a.scoate()<<" ";
	cout<<a.scoate()<<endl;
	cout<<b.scoate()<<" ";
	cout<<b.scoate()<<endl;
	for(i=0;i<10;i++) c.pune((char) 'A'+i);
	for(i=0;i<10;i++) cout<<c.scoate()<<" ";
	cout<<endl;
}