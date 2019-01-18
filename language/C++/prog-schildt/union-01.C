#include<iostream.h>

union sch_octet
{
	void sch();
	void da_octet(unsigned i);
	void arata_cuvint();
	
	unsigned u;
	unsigned char c[2];
};

void sch_octet::sch()
{
	unsigned char t;
	t=c[0];
	c[0]=c[1];
	c[1]=t;
}

void sch_octet::arata_cuvint()
{
	cout<<u<<"\n";
}

void sch_octet::da_octet(unsigned i)
{
	u=i;
}
int main()
{
	sch_octet b;
	b.da_octet(49034);
	b.sch();
	b.arata_cuvint();
}