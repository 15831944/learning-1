// nod.h: interface for the Cnod class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOD_H__F85FFA09_56C0_11DA_B910_9D465AA39378__INCLUDED_)
#define AFX_NOD_H__F85FFA09_56C0_11DA_B910_9D465AA39378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<stdlib.h>

class Cnod  
{
public:
	Cnod();
	Cnod(char val);
	virtual ~Cnod();
	char operator+(char val);
	char operator+(Cnod &val);
	char operator-(char val);
	char operator-(Cnod &val);
	char operator*(char val);
	char operator*(Cnod &val);
	char m_val;
	Cnod *prev;
	Cnod *next;
};

#endif // !defined(AFX_NOD_H__F85FFA09_56C0_11DA_B910_9D465AA39378__INCLUDED_)
