/*
 * suprascrierea operatiilor << si >>
 */
#include <iostream.h>
class complex
{
	//re =partea imaginara, im = partea imaginara
	float re, im;
public:
	complex(float r =0, float i =0)
	{
		re = r;
		im = i;
	}
	operator float()
	{
		return re;
	}
	friend istream& operator>>(istream&, complex&);
	friend ostream& operator<<(ostream&, complex);
};
//operatorul de intrare
istream& operator>>(istream& in, complex& cx)
{
	char c,ok = 1;
	float x,y;
	if(!(in>>x)) ok = 0;
	else {
		in.get(c);
		if(c == '\n') { // parte imaginara nula
			cx.re = x;
			cx.im = 0;
			return in;
		}
		if(c != '+' && c !='-') ok =0;
		else {
			in.putback(c); // returneaza semnul
			if(!(in >> y))
				ok = 0;
			else {
				in >> c;
				if(c != 'j')
					ok = 0;
			}
		}
	}
	if (ok) {
		cx.re = x;
		cx.im = y;
	}
	else
		in.clear(ios::badbit | in.rdstate());
	return in;
}
//operator de iesire
ostream& operator<<(ostream& ies,complex cx)
{
	ies<<cx.re;
	if(cx.im <0)
		ies<<cx.im<<'j';
	else
		ies<<'+'<<cx.im<<'j';
	return ies;
}
void main()
{
	complex cx;
	char lin[80];
	for(;;) {
		cout<<"Introduceti un numar complex: ";
		if(cin>>cx)
			cout<<"Ati introdus: "<<cx<<'\n';
		else {
			cout <<"Incorect\n";
			cin.clear();
			cin.getline(lin,80);
		}
		//iesire din ciclu daca real = 0 conversie complex -> float
		if(!cx)
			break;
	}
	cout<<"Final main()\n";
}
