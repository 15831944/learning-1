#include<iostream.h>
#include<fstream.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout<<"Utilization: prog <nomfichier>\n";
		return 1;
	}
	ifstream in(argv[1]);
	if(!in) 
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	char sir[255];
	while(in)
	{
		in.getline(sir,255);
		cout<<sir<<endl;
	}
	in.close();
}