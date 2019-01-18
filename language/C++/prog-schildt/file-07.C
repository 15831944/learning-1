#include<iostream.h>
#include<fstream.h>

int main()
{
	float fnum[4]={99.75, -34.4,1776.0, 200.1};
	int i;
	ofstream out("numere",ios::out | ios::binary);
	if(!out)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	out.write((unsigned char *)&fnum,sizeof(fnum));
	out.close();
	for(i=0;i<4;i++) fnum[i]=0.0;
	ifstream in("numere",ios::in | ios::binary);
	in.read((unsigned char *)&fnum,sizeof(fnum));
	cout<<"Je lise "<<in.gcount()<<" octets \n";
	for(i=0;i<4;i++) cout<<fnum[i]<<" ";
	cout<<"\n";
	in.close();
}