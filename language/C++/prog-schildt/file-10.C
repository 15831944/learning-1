#include<iostream.h>
#include<fstream.h>

int main()
{
	ifstream in("test");
	if(!in)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	in.ignore(10,' ');
	char c;
	while(in)
	{
		in.get(c);
		cout<<c;
	}
	in.close();
}