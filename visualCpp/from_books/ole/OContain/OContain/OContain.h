
// OContain.h : main header file for the OContain application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COContainApp:
// See OContain.cpp for the implementation of this class
//

class COContainApp : public CWinApp
{
public:
	COContainApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COContainApp theApp;
