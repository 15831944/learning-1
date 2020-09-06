// sdi_edit.h : main header file for the SDI_EDIT application
//

#if !defined(AFX_SDI_EDIT_H__A2BEF543_A7E3_11DB_B910_C96105C64945__INCLUDED_)
#define AFX_SDI_EDIT_H__A2BEF543_A7E3_11DB_B910_C96105C64945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSdi_editApp:
// See sdi_edit.cpp for the implementation of this class
//

class CSdi_editApp : public CWinApp
{
public:
	CSdi_editApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdi_editApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSdi_editApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDI_EDIT_H__A2BEF543_A7E3_11DB_B910_C96105C64945__INCLUDED_)
