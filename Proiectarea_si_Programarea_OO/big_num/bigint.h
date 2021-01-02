// bigint.h: interface for the Cbigint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIGINT_H__F85FFA07_56C0_11DA_B910_9D465AA39378__INCLUDED_)
#define AFX_BIGINT_H__F85FFA07_56C0_11DA_B910_9D465AA39378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<stdlib.h>
#include<iostream>
#include "nod.h"
using namespace std;

class Cbigint  
{
public:
	int m_nr;
	void reset();
	void putr(char val);
	char get(bool &flg);
	void put(char val);
	void operator+(Cbigint &val);
	void operator-(Cbigint &val);
	Cbigint();
	Cbigint(Cbigint &val);
	virtual ~Cbigint();
	friend ostream &operator<<(ostream &out,Cbigint &val);
protected:
	void erase();
	void reorganize();
	Cnod *m_beg,*m_end;
	Cnod *m_parc;
	bool m_first;
};


#endif // !defined(AFX_BIGINT_H__F85FFA07_56C0_11DA_B910_9D465AA39378__INCLUDED_)
