#include<iostream.h>
#include<fstream.h>

int main(int argc,char **argv)
{
	char ch;
	if(argc!=2)
	{
		cout<<"Utilization: prog <nomfichier>\n";
		return 1;
	}
	ifstream in(argv[1],ios::in | ios::binary);
	if(!in)
	{
		cout<<"Je ne peux pas ouvre le fichier.\n";
		return 1;
	}
	while(in.get(ch)) cout<<ch;
	cout<<"\n";
}