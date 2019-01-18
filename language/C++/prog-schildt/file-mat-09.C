#include<iostream.h>
#include<strstream.h>

const int marime=5;
class punct
{
	int x,y;
public:
	punct(int i,int j)
	{
		if(i>marime) i=marime; if(i<0) i=0;
		if(j>marime) j=marime; if(j<0) j=0;
		x=i;y=j;
	}
	friend ostream &operator<<(ostream &stream,punct o);
};
ostream &operator<<(ostream &stream,punct o)
{
	register int i,j;
	for(j=marime;j>=0;j--)
	{
		stream<<j;
		if(j==o.y)
		{
			for(i=0;i<o.x;i++) stream <<" ";
			stream<<'*';
		}
		stream<<"\n";
	}
	for(i=0;i<=marime;i++) stream<<" "<<i;
	stream<<"\n";
	return stream;
}
int main()
{
	punct a(2,3),b(1,1);
	char sir[200];
	cout<<"Il affiche avec cout:\n";
	cout<<a<<"\n"<<b<<"\n\n";
	//dans ce moment il utilize d'operation I/O avec RAM
	ostrstream outs(sir,sizeof(sir));
	outs<<a<<b<<ends;
	cout<<"Il affiche avec la formatations de RAM:\n";
	cout<<sir;
}