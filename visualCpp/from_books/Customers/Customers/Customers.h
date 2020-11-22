
// Customers.h : main header file for the Customers application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCustomersApp:
// See Customers.cpp for the implementation of this class
//

class CCustomersApp : public CWinApp
{
public:
	CCustomersApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCustomersApp theApp;
