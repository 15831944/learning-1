#include<iostream.h>
#include<stdio.h>

class data
{
	int zi,luna,an;
public:
	data(char *d);
	data(int z,int l,int a);
	void arata_data();
};
data::data(char *d)
{
	sscanf(d,"%d%*c%d%*c%d",&zi,&luna,&an);
}
data::data(int z,int l,int a)
{
	zi=z;
	luna=l;
	an=a;
}
void data::arata_data()
{
	cout<<zi<<"/"<<luna<<"/"<<an<<"\n";
}
int main()
{
	data ob1(4,12,96),ob2("22/10/97");
	ob1.arata_data();
	ob2.arata_data();
}