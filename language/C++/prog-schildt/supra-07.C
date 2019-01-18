#include<iostream.h>

class loc
{
	int longitud,latitud;
public:
	loc() {} //il este necessaire pour la construction temporare
	loc(int lg,int lt)
	{
		longitud=lg;
		latitud=lt;
	}
	void arata()
	{
		cout<<longitud<<" "<<latitud<<"\n";
	}
	loc operator=(loc op2);
	//avec des functions amis
	friend loc operator++(loc &op);
	friend loc operator--(loc &op);
	friend loc operator++(loc &op,int x);
	friend loc operator+(loc op1,loc op2);
	friend loc operator+(loc op1,int op2);
	friend loc operator+(int op1,loc op2);
};
loc operator+(loc op1,int op2)
{
	loc temp;
	temp.longitud=op1.longitud+op2;
	temp.latitud=op1.latitud+op2;
	return temp;
}
loc operator+(int op1,loc op2)
{
	loc temp;
	temp.longitud=op2.longitud+op1;
	temp.latitud=op2.latitud+op1;
	return temp;
}
loc operator+(loc op1,loc op2)
{
	loc temp;
	temp.longitud=op1.longitud+op2.longitud;
	temp.latitud=op1.latitud+op2.latitud;
	return temp;
}
loc operator++(loc &op)
{
	op.longitud++;
	op.latitud++;
	return op;
}
loc operator--(loc &op)
{
	op.longitud--;
	op.latitud--;
	return op;
}
loc operator++(loc &op,int x)
{
	loc temp(op.longitud,op.latitud);
	op.longitud++;
	op.latitud++;
	return temp;
}
loc loc::operator=(loc op2)
{
	longitud=op2.longitud;
	latitud=op2.latitud;
	return *this;
}
int main()
{
	loc ob1(10,20),ob2(5,30),ob3(4,4);
	ob1=ob1+ob2;
	ob1.arata(); //affiche 15 50
	++ob1;
	ob1.arata();	//affiche 16 51
	--ob2;
	ob2.arata();	//affiche 4 29
	ob1=ob1+ob2++;
	ob1.arata();	//affiche 20 80
	ob2.arata(); //affiche 5 30
	ob2++;
	ob2.arata();	//affiche 6 31
	ob1=ob3+10;
	ob2=10+ob3;
	ob1.arata();	//affiche 14 14
	ob2.arata();	//affiche 14 14
}