//header for the windows applications
#include <afxwin.h>
#include "resource.h"

//class for main application
class CResApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};
//class for frame windows
class CResFrame : public CFrameWnd
{
public:
	CResFrame()
	{
		Create(NULL,_T("Resource window"),WS_OVERLAPPEDWINDOW|WS_VISIBLE,CRect(0,0,300,300),NULL,MAKEINTRESOURCE(IDR_FAMILYMENU));
	}
};
BOOL CResApp::InitInstance(void)
{
	m_pMainWnd=new CResFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CResApp my_appl;