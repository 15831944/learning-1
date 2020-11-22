
// FloatingMenu.h : main header file for the FloatingMenu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFloatingMenuApp:
// See FloatingMenu.cpp for the implementation of this class
//

class CFloatingMenuApp : public CWinApp
{
public:
	CFloatingMenuApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFloatingMenuApp theApp;
