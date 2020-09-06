// menus.h : main header file for the MENUS application
//

#if !defined(AFX_MENUS_H__3EC97B10_A8C2_4337_8C86_7C92AA0B82BE__INCLUDED_)
#define AFX_MENUS_H__3EC97B10_A8C2_4337_8C86_7C92AA0B82BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenusApp:
// See menus.cpp for the implementation of this class
//

class CMenusApp : public CWinApp
{
public:
	CMenusApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenusApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMenusApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUS_H__3EC97B10_A8C2_4337_8C86_7C92AA0B82BE__INCLUDED_)
