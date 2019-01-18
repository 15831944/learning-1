#include<iostream.h>
#include<string.h>

#define IN 1
#define CHECKED_OUT 0
class carte
{
	char autor[40];
	char titlu[40];
	int stare;
public:
	carte(char *n,char *t,int s);
	int ia_stare(){ return stare;}
	void da_stare(int s){stare=s;}
	void arata();
};
carte::carte(char *n,char *t,int s)
{
	strcpy(autor,n);
	strcpy(titlu,t);
	stare=s;
}
void carte::arata()
{
	cout<<titlu<<" de "<<autor;
	cout<<" este ";
	if(stare==IN) cout<<"aici.\n";
	else cout<<"data.\n";
}
int main()
{
	carte b1("Twain","Tom Sowyer",IN);
	carte b2("Melville","Moby Dick",CHECKED_OUT);
	
	b1.arata();
	b2.arata();
}