
// MouseTst.h : main header file for the MouseTst application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMouseTstApp:
// See MouseTst.cpp for the implementation of this class
//

class CMouseTstApp : public CWinApp
{
public:
	CMouseTstApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMouseTstApp theApp;
