// day1_hello.h : main header file for the DAY1_HELLO application
//

#if !defined(AFX_DAY1_HELLO_H__AACDD335_07C0_4772_ABBD_4DF81F7B756B__INCLUDED_)
#define AFX_DAY1_HELLO_H__AACDD335_07C0_4772_ABBD_4DF81F7B756B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay1_helloApp:
// See day1_hello.cpp for the implementation of this class
//

class CDay1_helloApp : public CWinApp
{
public:
	CDay1_helloApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay1_helloApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay1_helloApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY1_HELLO_H__AACDD335_07C0_4772_ABBD_4DF81F7B756B__INCLUDED_)
