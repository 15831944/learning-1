// complex1.cpp: implementation of the Ccomplex class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "complex1.h"
#include<iostream.h>
#include<math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ccomplex::Ccomplex()
{
	m_imag=0.0;
	m_real=0.0;
	m_type=false;
	m_r=0.0;
	m_phi=0.0;
}

Ccomplex::Ccomplex(double real,double imag)
{
	m_real=real;
	m_imag=imag;
	m_type=true;
	m_r=0.0;
	m_phi=0.0;
}

Ccomplex::~Ccomplex()
{

}

double Ccomplex::getreal()
{
	if(m_type==true) return m_real;
	else return m_r*cos(m_phi);
}

double Ccomplex::getimag()
{
	if(m_type==true) return m_imag;
	else return m_r*sin(m_phi);
}

void Ccomplex::afiseaza()
{
	if(m_type==true) cout<<m_real<<"+i"<<m_imag<<endl;
	else cout<<m_r*cos(m_phi)<<"+i"<<m_r*sin(m_phi)<<endl;
}

void Ccomplex::citeste(double *real, double *imag)
{
	if(m_type==true)
	{
		*real=m_real;
		*imag=m_imag;
	}
	else
	{
		*real=m_r*cos(m_phi);
		*imag=m_r*sin(m_phi);
	}
}

void Ccomplex::set(double real, double imag)
{
	m_type=true;
	m_real=real;
	m_imag=imag;
}

void Ccomplex::setreal(double real)
{
	m_type=true;
	m_real=real;
}

void Ccomplex::setimag(double imag)
{
	m_type=true;
	m_imag=imag;
}

void Ccomplex::setr(double r)
{
	m_type=false;
	m_r=r;
}

void Ccomplex::setphi(double phi)
{
	m_type=false;
	m_phi=phi;
}

void Ccomplex::polar()
{
	m_type=false;
	m_r=sqrt(pow(m_real,2)+pow(m_imag,2));
	if(m_real>0) m_phi=atan(m_imag/m_real);
	else if(m_real==0 && m_imag>0) m_phi=asin(1);
	else if(m_real==0 && m_imag<0) m_phi=-asin(1);
	else if(m_real<0) m_phi=acos(-1)+atan(m_imag/m_real);
}

void Ccomplex::algebric()
{
	m_type=true;
	m_real=m_r*cos(m_phi);
	m_imag=m_r*sin(m_phi);
}

Ccomplex Ccomplex::operator +(Ccomplex op2)
{
	Ccomplex op3;
	if(m_type==true)
	{
		op3.setreal(m_real+op2.getreal());
		op3.setimag(m_imag+op2.getimag());
	}
	else
	{
		algebric();
		op3.setreal(m_real+op2.getreal());
		op3.setimag(m_imag+op2.getimag());
	}
	return op3;
}

Ccomplex Ccomplex::operator -(Ccomplex op2)
{
	Ccomplex op3;
	if(m_type==true)
	{
		op3.setreal(m_real-op2.getreal());
		op3.setimag(m_imag-op2.getimag());
	}
	else
	{
		algebric();
		op3.setreal(m_real-op2.getreal());
		op3.setimag(m_imag-op2.getimag());
	}
	return op3;
}

Ccomplex Ccomplex::operator *(Ccomplex op2)
{
	Ccomplex op3;
	if(m_type==true)
	{
		op3.setreal(m_real*op2.getreal()-m_imag*op2.getimag());
		op3.setimag(m_real*op2.getimag()+m_imag*op2.getreal());
	}
	else
	{
		op3.setr(m_r*op2.getreal());
		op3.setphi(m_phi+op2.getphi());
	}
	return op3;
}


double Ccomplex::getr()
{
	if(m_type==true)
		polar();
	return m_r;
}

double Ccomplex::getphi()
{
	if(m_type==true)
		polar();
	return m_phi;
}

Ccomplex Ccomplex::operator^(long putere)
{
	Ccomplex op;
	if(m_type==true) polar();
	op.setr(pow(m_r,putere));
	op.setphi(putere*m_phi);
	return op;
}
