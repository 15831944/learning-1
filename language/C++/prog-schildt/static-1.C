/* Exemples pour le dates static */
#include <iostream.h>
class comun{
	static int a;
	int b;
public:
	void da(int i,int j) {a=i;b=j;}
	void arata();
};
int comun::a; //il preciser le a
void comun::arata()
{
	cout<<"Acesta este a static: "<<a;
	cout<<"\nAcesta este b ne-static: "<<b;
	cout<<"\n";
}
int main()
{
	comun x,y;
	x.da(1,1);	//inialize a avec 1
	x.arata();
	
	y.da(2,2);	//il change le a dans 2
	y.arata();
	
	x.arata();	//dans ce moment a etre change pour y et aussi pour x
	
}