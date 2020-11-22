
// TabExample.h : main header file for the TabExample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTabExampleApp:
// See TabExample.cpp for the implementation of this class
//

class CTabExampleApp : public CWinApp
{
public:
	CTabExampleApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTabExampleApp theApp;
