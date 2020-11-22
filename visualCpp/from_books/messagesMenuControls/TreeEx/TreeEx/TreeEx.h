
// TreeEx.h : main header file for the TreeEx application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTreeExApp:
// See TreeEx.cpp for the implementation of this class
//

class CTreeExApp : public CWinApp
{
public:
	CTreeExApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTreeExApp theApp;
