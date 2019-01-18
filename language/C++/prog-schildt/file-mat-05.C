#include<iostream.h>
#include<strstream.h>

int main()
{
	char s[]="abcdefghijklmnop";
	istrstream ins(s);
	char ch;
	while(!ins.eof())
	{
		ins.get(ch);
		cout<<ch;
	}
	cout<<endl;
}