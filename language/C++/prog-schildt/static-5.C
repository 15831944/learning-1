#include<iostream.h>
class tip_static
{
	static int i;
public:
	static void init(int x) {i=x;}
	void arata() {cout<<i<<"\n";}
};
int tip_static::i;	//il defini i
int main()
{
	//il initialise les dates de type static avand de creation de l'objets
	tip_static::init(100);
	
	tip_static x;
	x.arata();	//afficher 100
}	