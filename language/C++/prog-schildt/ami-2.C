#include<iostream.h>
#define IDLE 0
#define INUSE 1

class C2;// il este explique plus tard
class C1
{
	int stare;	//INUSE s'il est sur l'ecran, IDLE s'il n'est pas
public:
	void da_stare(int cond);
	friend int idle(C1 a,C2 b);
};
class C2
{
	int stare; //INUSE s'il est sur l'ecran, IDLE s'il n'est pas
public:
	void da_stare(int cond);
	friend int idle(C1 a,C2 b);
};

void C1::da_stare(int cond)
{
	stare=cond;
}
void C2::da_stare(int cond)
{
	stare=cond;
}
int idle(C1 a,C2 b)
{
	if(a.stare||b.stare) return 0;
	else return 1;
}
int main()
{
	C1 x;
	C2 y;
	
	x.da_stare(IDLE);
	y.da_stare(IDLE);
	
	if(idle(x,y)) cout<<"L'ecran peux utilise.\n";
	else cout<<"C'este utilise.\n";
	x.da_stare(INUSE);
	if(idle(x,y)) cout<<"L'ecran peux utilise.\n";
	else cout<<"C'est utilise.\n";
}