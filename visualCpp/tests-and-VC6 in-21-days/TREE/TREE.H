// tree.h : main header file for the TREE application
//

#if !defined(AFX_TREE_H__EC627F63_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
#define AFX_TREE_H__EC627F63_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeApp:
// See tree.cpp for the implementation of this class
//

class CTreeApp : public CWinApp
{
public:
	CTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTreeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE_H__EC627F63_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
