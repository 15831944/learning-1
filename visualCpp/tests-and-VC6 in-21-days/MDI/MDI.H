// MDI.h : main header file for the MDI application
//

#if !defined(AFX_MDI_H__056A207D_A231_11DB_B910_D50B31D6A328__INCLUDED_)
#define AFX_MDI_H__056A207D_A231_11DB_B910_D50B31D6A328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDIApp:
// See MDI.cpp for the implementation of this class
//

class CMDIApp : public CWinApp
{
public:
	CMDIApp();
	CDocTemplate* GetDisplayTemplate() const;
	CDocTemplate* GetFormTemplate() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDocTemplate* m_pDisplayTemplate;
	CDocTemplate* m_pFormTemplate;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDI_H__056A207D_A231_11DB_B910_D50B31D6A328__INCLUDED_)
