#include<iostream.h>

char &inloc(int i);	//il returne une reference
char s[80]="Je vous salute";

int main()
{
	inloc(2)='X'; //il atribue X le space apres Je
	cout<<s<<"\n";
}
char &inloc(int i)
{
	return s[i];
}