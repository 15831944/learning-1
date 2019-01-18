#include<iostream.h>
class loc
{
	int longitud,latitud;
public:
	loc(){}
	loc(int lg,int lt)
	{
		longitud=lg;
		latitud=lt;
	}
	void arata()
	{
		cout<<longitud<<" ";
		cout<<latitud<<"\n";
	}
	loc operator+(loc op2);
};
loc loc::operator+(loc op2)
{
	loc temp;
	temp.longitud=op2.longitud+longitud;
	temp.latitud=op2.latitud+latitud;
	return temp;
}
int main()
{
	loc ob1(10,20),ob2(5,30);
	ob1.arata(); //affiche 10 20
	ob2.arata();	//affiche 5 30
	ob1=ob1+ob2;
	ob1.arata(); //affiche 15 50
}