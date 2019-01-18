#include<iostream.h>
#include<fstream.h>

int main()
{
	ofstream out("INVENTAR");
	if(!out)
	{
		cout<<"Je ne peux pas ouvre le fischier INVENTAR.\n";
		return 1;
	}
	out<<"Radio "<<39.25<<endl;
	out<<"Prajitor "<<19.95<<endl;
	out<<"Mixer "<<24.80<<endl;
	out.close();
}