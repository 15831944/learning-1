
// RichText.h : main header file for the RichText application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRichTextApp:
// See RichText.cpp for the implementation of this class
//

class CRichTextApp : public CWinApp
{
public:
	CRichTextApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRichTextApp theApp;
