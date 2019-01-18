#include<iostream.h>

class clasamea
{
	int a,b;
public:
	friend int sum(clasamea x);
	void da_ab(int i,int j);
	void printe();
};
void clasamea::da_ab(int i,int j)
{
	a=i;
	b=j;
}
void clasamea::printe()
{
	cout<<a<<" "<<b<<"\n";
}
//Note: sum() c'est n'est pas une function membre a ni une classe
int sum(clasamea x)
{
/*	parce que sum() c'est une funtion ami pour clasamea, elle peux a l'acces directement a a et b */
	return x.a+x.b;
}

int main()
{
	clasamea n;
	n.da_ab(3,4);
	n.printe();
	cout<<"La somme c'est "<<sum(n)<<"\n";
}