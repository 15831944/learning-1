// complex1.h: interface for the Ccomplex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPLEX1_H__611AD867_40F7_11DA_B910_F4D2DF191E08__INCLUDED_)
#define AFX_COMPLEX1_H__611AD867_40F7_11DA_B910_F4D2DF191E08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Ccomplex  
{
public:
	Ccomplex operator^(long putere);
	double getphi();
	double getr();
	void setphi(double phi);
	void setr(double r);
	Ccomplex operator*(Ccomplex op2);
	void algebric();
	void polar();
	Ccomplex operator-(Ccomplex op2);
	void setimag(double imag);
	void setreal(double real);
	Ccomplex operator+(Ccomplex op2);
	void set(double real,double imag);
	void citeste(double *real,double *imag);
	void afiseaza();
	double getimag();
	double getreal();
	Ccomplex();
	Ccomplex(double real,double imag);
	virtual ~Ccomplex();

protected:
	bool m_type;
	double m_phi;
	double m_r;
	double m_imag;
	double m_real;
};

#endif // !defined(AFX_COMPLEX1_H__611AD867_40F7_11DA_B910_F4D2DF191E08__INCLUDED_)
