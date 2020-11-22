
// CtrlBar.h : main header file for the CtrlBar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCtrlBarApp:
// See CtrlBar.cpp for the implementation of this class
//

class CCtrlBarApp : public CWinApp
{
public:
	CCtrlBarApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCtrlBarApp theApp;
