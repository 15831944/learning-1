
// Print.h : main header file for the Print application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPrintApp:
// See Print.cpp for the implementation of this class
//

class CPrintApp : public CWinApp
{
public:
	CPrintApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPrintApp theApp;
