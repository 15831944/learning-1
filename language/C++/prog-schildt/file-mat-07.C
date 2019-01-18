#include<iostream.h>
#include<strstream.h>

int main()
{
	char *p;
	ostrstream outs;
	outs<<"Il me plait C++ ";
	outs<<-10<<hex<<" ";
	outs.setf(ios::showbase);
	outs<<100<<endl<<ends;
	p=outs.str();
	cout<<p;
	delete p;
}