#include<iostream.h>
#include<fstream.h>

int main()
{
	int i;
	ofstream out("CHARS",ios::out | ios::binary);
	if(!out)
	{
		cout<<"Je ne peux pas ouvre le fichier.\n";
		return 1;
	}
	for(i=0;i<257;i++) out.put((char)i);
	out.close();
}