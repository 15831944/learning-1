// day1_double.h : main header file for the DAY1_DOUBLE application
//

#if !defined(AFX_DAY1_DOUBLE_H__E932847F_F884_4604_B2EA_F5DA8163E551__INCLUDED_)
#define AFX_DAY1_DOUBLE_H__E932847F_F884_4604_B2EA_F5DA8163E551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay1_doubleApp:
// See day1_double.cpp for the implementation of this class
//

class CDay1_doubleApp : public CWinApp
{
public:
	CDay1_doubleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay1_doubleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay1_doubleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY1_DOUBLE_H__E932847F_F884_4604_B2EA_F5DA8163E551__INCLUDED_)
