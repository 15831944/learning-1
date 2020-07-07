/*
 * utilizarea fstream pentru citire scriere clasa complex
 */
#include <fstream.h>
class complex
{
	float re,im;
public:
	complex()
	{
		re = im = 0;
	}
	complex(float r, float i)
	{
		re =r;
		im = i;
	}
	void val(float r, float i)
	{
		re = r;
		im = i;
	}
	//conversie complex -> float
	operator float()
	{
		return re;
	}
	friend istream& operator>>(istream& in, complex& cx);
	friend ostream& operator<<(ostream& ies, complex& cx);
};
//citire numar complex
istream& operator>>(istream& in, complex& cx)
{
	char c,ok =1;
	float x,y;
	if(!(in>>x)) ok =0;
	else {
		in.get(c);
		if(c=='\n') { // parte imaginara nula
			cx.re =x;
			cx.im=0;
			return in;
		}
		if (c != '+' && c !='-') ok =0;
		else {
			in.putback(c); //returneaza semnul
			if(!(in>>y)) ok = 0;
			else {
				in >> c;
				if(c!='j') ok =0;
			}
		}
	}
	if(ok) {
		cx.re = x;
		cx.im = y;
	}
	else in.clear(ios::badbit | in.rdstate());
	return in;
}
//scrie numar complex
ostream& operator<<(ostream& ies, complex& cx)
{
	ies << cx.re;
	if(cx.im < 0)
		ies<<cx.im<<'j';
	else ies<<'+'<<cx.im<<'j';
	return ies;
}
int main()
{
	complex tcxi[4], tcxe[4];
	tcxe[0].val(0,0);
	tcxe[1].val(1,-1);
	tcxe[2].val(2,2);
	tcxe[3].val(3,-3);
	//creaza fisierul fiscpx.dat
	ofstream ies("fiscpx.dat");
	if(!ies) {
		cout<<"Eroare de deschidere fis \n";
		return 1;
	}
	//si copiaza in el tcxe[]
	for(int i =0; i<4;i++)
		ies<<tcxe[i]<<endl;
	ies.close();
	//deschide fiscpx.dat pentru citire
	ifstream in("fiscpx.dat");
	if(!in) {
		cout<<"Eroare la deschiderea fisierului \n";
		return 1;
	}
	//citeste fisierul fiscpx in tcxi[] si afiseaza tcxi[] pe ecran
	cout<<"Continutul fisierului:\n";
	i = 0;
	while(in>>tcxi[i])
		cout<<tcxi[i++]<<endl;
	in.close();
}