
// DVTest.h : main header file for the DVTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDVTestApp:
// See DVTest.cpp for the implementation of this class
//

class CDVTestApp : public CWinApp
{
public:
	CDVTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	CDocTemplate* GetDisplayTemplate() const;
	CDocTemplate* GetFormTemplate() const;
	CDocTemplate* GetScrollDisplayTemplate() const;
	CDocTemplate* GetSplitTemplate() const;
	~CDVTestApp();
private:
	CDocTemplate* m_pDisplayTemplate;
	CDocTemplate* m_pFormTemplate;
	CDocTemplate* m_pScrollDisplayTemplate;
	CDocTemplate* m_pSplitTemplate;
};

extern CDVTestApp theApp;
