#include<strstream.h>
#include<iostream.h>
int main()
{
	char sir[80];
	ostrstream iesiri(sir,sizeof(sir));
	iesiri<<"Hello ";
	iesiri<<34<<" "<<1234.23<<ends;
	cout<<iesiri.pcount()<<" "<<sir<<"\n";
}