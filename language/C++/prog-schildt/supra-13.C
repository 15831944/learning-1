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
		cout<<longitud<<" "<<latitud<<"\n";
	}
	loc operator+(loc op2);
	loc operator()(int i,int j);
};
loc loc::operator()(int i,int j)
{
	longitud=i;
	latitud=j;
	return *this;
}
loc loc::operator+(loc op2)
{
	loc temp;
	temp.longitud=op2.longitud+longitud;
	temp.latitud=op2.latitud+latitud;
	return temp;
}
int main()
{
	loc ob1(10,20),ob2(1,1);
	ob1.arata();
	ob1(7,8);
	ob1.arata();
	ob1=ob2+ob1(10,10);
	ob1.arata();
}