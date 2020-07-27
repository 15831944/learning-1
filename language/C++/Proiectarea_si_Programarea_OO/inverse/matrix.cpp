// matrix.cpp: implementation of the Cmatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "matrix.h"
#include <stdlib.h>
#include<memory.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cmatrix::Cmatrix()
{
	m_dim=0;
}

Cmatrix::Cmatrix(long dim)
{
	m_dim=dim;
}

Cmatrix::~Cmatrix()
{
}
long Cmatrix::getdim()
{
	return m_dim;
}

void Cmatrix::setdim(long dim)
{
	m_dim=dim;
}

double Cmatrix::get(long i, long j)
{
	if(i<m_dim && j<m_dim)
		return m_mat[i][j];
	else return -1;
}

long Cmatrix::set(double val, long i, long j)
{
	if(i<m_dim && j<m_dim)
	{
		m_mat[i][j]=val;
		return 0;
	}
	else return -1;
}

Cmatrix Cmatrix::operator +(Cmatrix mat)
{
	if(mat.m_dim!=m_dim) return NULL;
	Cmatrix ob(m_dim);
	for(long i=0;i<m_dim;i++)
		for(long j=0;j<m_dim;j++)
			ob.m_mat[i][j]=m_mat[i][j]+mat.m_mat[i][j];
	return ob;
}

Cmatrix Cmatrix::operator -(Cmatrix mat)
{
	if(mat.m_dim!=m_dim) return NULL;
	Cmatrix ob(m_dim);
	for(long i=0;i<m_dim;i++)
		for(long j=0;j<m_dim;j++)
			ob.m_mat[i][j]=m_mat[i][j]-mat.m_mat[i][j];
	return ob;
}

Cmatrix Cmatrix::operator *(Cmatrix mat)
{
	if(mat.m_dim!=m_dim) return NULL;
	Cmatrix ob(m_dim);
	for(long i=0;i<m_dim;i++)
		for(long j=0;j<m_dim;j++)
		{
			ob.m_mat[i][j]=0.0;
			for(long k=0;k<m_dim;k++)
				ob.m_mat[i][j]+=m_mat[i][k]*mat.m_mat[k][j];
		}
	return ob;
}

Cmatrix Cmatrix::inv()
{
	long k,i,j;
	double temp;
	Cmatrix ob1(m_dim);
	for(i=0;i<m_dim;i++)
		for(j=0;j<m_dim;j++)
			ob1.m_mat[i][j]=m_mat[i][j];
	Cmatrix ob(m_dim);
	for(i=0;i<m_dim;i++)
		for(j=0;j<m_dim;j++)
			if(i==j) ob.m_mat[i][i]=1.0;
			else ob.m_mat[i][j]=0.0;
	for(k=0;k<m_dim;k++)
	{
		for(i=0;i<m_dim;i++)
		{
			if(i!=k)
			{
				temp=ob1.m_mat[i][k]/ob1.m_mat[k][k];
				for(j=k+1;j<m_dim;j++)
					ob1.m_mat[i][j]-=temp*ob1.m_mat[k][j];
				for(j=0;j<m_dim;j++)
						ob.m_mat[i][j]-=temp*ob.m_mat[k][j];
			}
			else
			{
				for(j=0;j<m_dim;j++)
				{
					ob.m_mat[i][j]=ob.m_mat[i][j]/ob1.m_mat[i][i];
					if(j!=i)
						ob1.m_mat[i][j]=ob1.m_mat[i][j]/ob1.m_mat[i][i];
				}
				ob1.m_mat[i][i]=1.0;
			}
		}
	}
	return ob;
}
