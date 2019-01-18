#include<iostream.h>

#define IDLE 0
#define INUSE 1

class C2;//il est explique plus tard
class C1
{
	int stare;	//INUSE s'il este sur l'ecran,IDLE s'il n'est pas.
public:
	void da_stare(int cond);
	int idle(C2 b);//dans ce moment il est un membre de C1
};
class C2
{
	int stare;	//INUSE s'il este sur l'ecran,IDLE s'il n'est pas.
public:
	void da_stare(int cond);
	friend int C1::idle(C2 b);
};

void C1::da_stare(int cond)
{
	stare=cond;
}
void C2::da_stare(int cond)
{
	stare=cond;
}

//idle() il este un membre de C1, mais ami de C2
int C1::idle(C2 b)
{
	if(stare||b.stare) return 0;
	else  return 1;
}

int main()
{
	C1 x;
	C2 y;
	
	x.da_stare(IDLE);
	y.da_stare(IDLE);
	
	if(x.idle(y)) cout<<"L'ecran peux utilise.\n";
	else cout<<"C'est utilise.\n";
	
	x.da_stare(INUSE);
	
	if(x.idle(y)) cout<<"L'ecran peux utilise.\n";
	else cout<<"C'est utilise.\n";
}