#include<iostream.h>
#include<fstream.h>
#include<stdio.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout<<"Utilization: iesire <nomfichier>\n";
		return 1;
	}
	ofstream out(argv[1]);
	if(!out)
	{
		cout<<"Je ne peux pas ouvre le fichier de sortir\n";
		return 1;
	}
	char sir[80];
	cout<<"Il ecrite sur le disc, RETURN pour fini le program.\n";
	do
	{
		cout<<": ";
		gets(sir);
		out<<sir<<endl;
	} while(*sir);
	out.close();
}
		