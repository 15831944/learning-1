
// FileView.h : main header file for the FileView application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFileViewApp:
// See FileView.cpp for the implementation of this class
//

class CFileViewApp : public CWinApp
{
public:
	CFileViewApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFileViewApp theApp;
