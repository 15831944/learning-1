
// DCTest.h : main header file for the DCTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDCTestApp:
// See DCTest.cpp for the implementation of this class
//

class CDCTestApp : public CWinApp
{
public:
	CDCTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDCTestApp theApp;
