// timers.h : main header file for the TIMERS application
//

#if !defined(AFX_TIMERS_H__5A05FD85_ED43_4D31_B5C8_732FD64576A5__INCLUDED_)
#define AFX_TIMERS_H__5A05FD85_ED43_4D31_B5C8_732FD64576A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimersApp:
// See timers.cpp for the implementation of this class
//

class CTimersApp : public CWinApp
{
public:
	CTimersApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimersApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimersApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERS_H__5A05FD85_ED43_4D31_B5C8_732FD64576A5__INCLUDED_)
