
// EditTest.h : main header file for the EditTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEditTestApp:
// See EditTest.cpp for the implementation of this class
//

class CEditTestApp : public CWinApp
{
public:
	CEditTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEditTestApp theApp;
