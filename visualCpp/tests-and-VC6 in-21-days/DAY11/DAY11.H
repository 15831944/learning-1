// day11.h : main header file for the DAY11 application
//

#if !defined(AFX_DAY11_H__EAA08CD5_4109_48EC_8A07_99C895377829__INCLUDED_)
#define AFX_DAY11_H__EAA08CD5_4109_48EC_8A07_99C895377829__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay11App:
// See day11.cpp for the implementation of this class
//

class CDay11App : public CWinApp
{
public:
	CDay11App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay11App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDay11App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY11_H__EAA08CD5_4109_48EC_8A07_99C895377829__INCLUDED_)
