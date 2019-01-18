#include<iostream.h>
#include<strstream.h>
int main()
{
	char s[]="10.23 cette est un texte !#?@\n";
	istrstream ins(s);
	char ch;
	ins.unsetf(ios::skipws);
	while(ins)
	{
		ins>>ch;
		cout<<ch;
	}
	cout<<endl;
}