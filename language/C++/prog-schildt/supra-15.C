#include<iostream.h>

class loc
{
	int longitud,latitud;
public:
	loc() {}
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
	loc operator,(loc op2);
};

loc loc::operator,(loc op2)
{
	loc temp;
	temp.longitud=op2.longitud;
	temp.latitud=op2.latitud;
	cout<<op2.longitud<<" "<<op2.latitud<<"\n";
	return temp;
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
	loc ob1(10,20),ob2(5,30),ob3(1,1);
	ob1.arata();
	ob2.arata();
	ob3.arata();
	cout<<"\n";
	ob1=(ob1,ob2+ob2,ob3);
	ob1.arata();
}