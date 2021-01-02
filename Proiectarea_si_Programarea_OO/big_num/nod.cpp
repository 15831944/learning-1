// nod.cpp: implementation of the Cnod class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "nod.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cnod::Cnod()
{
	m_val=0;
	prev=NULL;
	next=NULL;
}

Cnod::Cnod(char val)
{
	m_val=val;
	prev=NULL;
	next=NULL;
}

Cnod::~Cnod()
{

}
char Cnod::operator+(char val)
{
	m_val+=val;
	if(m_val>=10)
	{
		m_val=m_val%10;
		return 1;
	}
	else return 0;
}
char Cnod::operator+(Cnod &val)
{
	m_val+=val.m_val;
	if(m_val>=10)
	{
		m_val=m_val%10;
		return 1;
	}
	else return 0;
}
char Cnod::operator-(char val)
{
	if(m_val<val)
	{
		m_val=m_val+10-val;
		return 1;
	}
	else
	{
		m_val=m_val-val;
		return 0;
	}
}
char Cnod::operator-(Cnod &val)
{
	if(m_val<val.m_val)
	{
		m_val=m_val+10-val.m_val;
		return 1;
	}
	else
	{
		m_val=m_val-val.m_val;
		return 0;
	}
}
char Cnod::operator*(char val)
{
	m_val*=val;
	char temp;
	if(m_val>=10)
	{
		temp=m_val/10;
		m_val=m_val%10;
		return temp;
	}
	else return 0;
}
char Cnod::operator*(Cnod &val)
{
	m_val*=val.m_val;
	char temp;
	if(m_val>=10)
	{
		temp=m_val/10;
		m_val=m_val%10;
		return temp;
	}
	else return 0;
}
