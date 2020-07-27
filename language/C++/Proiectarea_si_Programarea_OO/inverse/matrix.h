// matrix.h: interface for the Cmatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__74B85FC7_43B6_11DA_B910_E4EDB3C94E15__INCLUDED_)
#define AFX_MATRIX_H__74B85FC7_43B6_11DA_B910_E4EDB3C94E15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX 10
class Cmatrix  
{
public:
	Cmatrix inv();
	void setdim(long dim);
	long getdim();
	long set(double val,long i,long j);
	double get(long i,long j);
	Cmatrix operator+(Cmatrix mat);
	Cmatrix operator-(Cmatrix mat);
	Cmatrix operator*(Cmatrix mat);
	Cmatrix();
	Cmatrix(long dim);
	virtual ~Cmatrix();
protected:
	double m_mat[MAX][MAX];
	long m_dim;
};

#endif // !defined(AFX_MATRIX_H__74B85FC7_43B6_11DA_B910_E4EDB3C94E15__INCLUDED_)
