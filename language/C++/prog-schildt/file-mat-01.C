#include<strstream.h>
#include<iostream.h>
int main()
{
	char sir[80];
	ostrstream iesiri(sir,sizeof(sir));
	iesiri<<"Hello ";
	iesiri<<99-14<<hex<<" ";
	iesiri.setf(ios::showbase);
	iesiri<<100<<ends;
	cout<<sir<<"\n";
}