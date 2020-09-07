//implementation of class for application
#include "fontsapp.h"
#include "fontsframe.h"

BOOL CFontsApp::InitInstance(void)
{
	m_pMainWnd=new CFontsFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CFontsApp my_application;