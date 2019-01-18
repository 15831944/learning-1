#include<iostream.h>
#include<strstream.h>
int main()
{
	char s[]="10 Hello 0x88 12.23 gata";
	istrstream ins(s);
	int i;
	char sir[80];
	float f;
	ins>>i;
	ins>>sir;
	char c;
	cout<<i<<" "<<sir<<endl;
	ins>>i>>c>>hex>>i;
	ins>>f;
	ins>>sir;
	cout<<hex<<i<<" "<<f<<" "<<sir<<"\n";
}