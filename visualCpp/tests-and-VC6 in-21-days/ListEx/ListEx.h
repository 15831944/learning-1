// ListEx.h : main header file for the LISTEX application
//

#if !defined(AFX_LISTEX_H__34D0DDC3_AE03_11DB_B910_C96B64896645__INCLUDED_)
#define AFX_LISTEX_H__34D0DDC3_AE03_11DB_B910_C96B64896645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListExApp:
// See ListEx.cpp for the implementation of this class
//

class CListExApp : public CWinApp
{
public:
	CListExApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListExApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListExApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEX_H__34D0DDC3_AE03_11DB_B910_C96B64896645__INCLUDED_)
