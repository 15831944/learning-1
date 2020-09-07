// Tasking.h : main header file for the TASKING application
//

#if !defined(AFX_TASKING_H__850FBD55_62DC_43A8_9E36_23C8E4410E43__INCLUDED_)
#define AFX_TASKING_H__850FBD55_62DC_43A8_9E36_23C8E4410E43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskingApp:
// See Tasking.cpp for the implementation of this class
//

class CTaskingApp : public CWinApp
{
public:
	CTaskingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskingApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTaskingApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKING_H__850FBD55_62DC_43A8_9E36_23C8E4410E43__INCLUDED_)
