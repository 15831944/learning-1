#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	if(argc!=4)
	{
		cout<<"Utilization: prog <nomfichier> <octet> <character>\n";
		return 1;
	}
	fstream out(argv[1],ios::in | ios::out | ios::binary);
	if(!out)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	out.seekp(atoi(argv[2]),ios::beg);
	out.put(*argv[3]);
	out.close();
}