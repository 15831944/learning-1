#include<iostream.h>
class clasamea
{
public:
	int cine;
	clasamea(int ex);
	~clasamea();
} glob_ob1(1),glob_ob2(2);

clasamea::clasamea(int ex)
{
	cout<<"Initialization "<<ex<<"\n";
	cine=ex;
}
clasamea::~clasamea()
{
	cout<<"Destruction"<<cine<<"\n";
}
int main()
{
	clasamea local_ob1(3);
	cout<<"Ce il n'est pas la premier ligne affiche.\n";
	clasamea local_ob2(4);
}