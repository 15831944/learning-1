#include<iostream.h>
#include<strstream.h>

ostream &sd(ostream &stream)
{
	stream<<"------> ";
	return stream;
}
ostream &ss(ostream&stream)
{
	stream<<" <------";
	return stream;
}
int main()
{
	char sir[80];
	ostrstream outs(sir,sizeof(sir));
	outs<<sd<<"Voire cette numero: ";
	outs<<100000<<ss<<ends;
	cout<<" "<<sir<<endl;
}