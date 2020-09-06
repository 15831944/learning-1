// serialize.h : main header file for the SERIALIZE application
//

#if !defined(AFX_SERIALIZE_H__E2B2D199_20F2_4775_B6A6_0B3FFD104C97__INCLUDED_)
#define AFX_SERIALIZE_H__E2B2D199_20F2_4775_B6A6_0B3FFD104C97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerializeApp:
// See serialize.cpp for the implementation of this class
//

class CSerializeApp : public CWinApp
{
public:
	CSerializeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSerializeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALIZE_H__E2B2D199_20F2_4775_B6A6_0B3FFD104C97__INCLUDED_)
