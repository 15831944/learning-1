#include<iostream.h>
#include<strstream.h>

int main()
{
	char iostr[80];
	strstream ios(iostr,sizeof(iostr),ios::in | ios::out);
	int a,b;
	char sir[80];
	ios<<"10 20 testare";
	ios>>a>>b>>sir;
	cout<<a<<" "<<b<<" "<<sir<<endl;
}