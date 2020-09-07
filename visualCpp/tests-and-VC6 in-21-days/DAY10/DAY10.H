// day10.h : main header file for the DAY10 application
//

#if !defined(AFX_DAY10_H__532339F3_F7F3_46E0_A000_8698F4B275D3__INCLUDED_)
#define AFX_DAY10_H__532339F3_F7F3_46E0_A000_8698F4B275D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay10App:
// See day10.cpp for the implementation of this class
//

class CDay10App : public CWinApp
{
public:
	CDay10App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay10App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDay10App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY10_H__532339F3_F7F3_46E0_A000_8698F4B275D3__INCLUDED_)
