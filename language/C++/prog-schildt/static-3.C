#include<iostream.h>

class c1
{
	static int resursa;
public:
	int ia_resursa();
	void resursa_libera() {resursa=0;}
};
int c1::resursa;	//il defini la resource
int c1::ia_resursa()
{
	if(resursa) return 0;	//la resource c'est ocupe
	else
	{
		resursa=1;
		return 1;	//la resource c'est attribue a ce objett
	}
}
int main()
{
c1 ob1,ob2;
	if(ob1.ia_resursa()) cout<<"ob1 a le droit d'accesse la resource\n";
	if(!ob2.ia_resursa()) cout<<"ob2 n'a pas le droit d'accesse la resource\n";
	ob1.resursa_libera();	//il lesse la resource pour autre
	if(ob2.ia_resursa()) cout<<"ob2 il peux utilise la resource\n";
}