// ActiveX.h : main header file for the ACTIVEX application
//

#if !defined(AFX_ACTIVEX_H__8F3510A5_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_)
#define AFX_ACTIVEX_H__8F3510A5_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CActiveXApp:
// See ActiveX.cpp for the implementation of this class
//

class CActiveXApp : public CWinApp
{
public:
	CActiveXApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveXApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CActiveXApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVEX_H__8F3510A5_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_)
