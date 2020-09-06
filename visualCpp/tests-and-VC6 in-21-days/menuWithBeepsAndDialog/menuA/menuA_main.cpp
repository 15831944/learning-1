//include for windows header
#include <afxwin.h>
#include "resource.h"

//main class for application
class CMyMenuApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};
//frame class
class CMyFrame : public CFrameWnd
{
public:
	CMyFrame();
	DECLARE_MESSAGE_MAP()
private:
	int m_nBeeps;
	void OnOneBeep();
	void OnFourBeeps();
	void OnGreetings();
	void OnTimer(UINT);
};
BOOL CMyMenuApp::InitInstance(void)
{
	m_pMainWnd=new CMyFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CMyMenuApp my_app;

BEGIN_MESSAGE_MAP(CMyFrame,CFrameWnd)
	ON_COMMAND(ID_ONE_BEEP,OnOneBeep)
	ON_COMMAND(ID_FOUR_BEEPS,OnFourBeeps)
	ON_COMMAND(ID_GREETING,OnGreetings)
	ON_WM_TIMER()
END_MESSAGE_MAP();

CMyFrame::CMyFrame()
{
	Create(NULL,_T("Menus Examples A"),WS_OVERLAPPEDWINDOW,CRect(0,0,400,400),NULL,MAKEINTRESOURCE(IDR_MENU1),LoadAccelTable(MAKEINTRESOURCE(IDR_ACCELERATOR1))); //without accelerator
	m_nBeeps=0;
}
void CMyFrame::OnOneBeep(void)
{
	::MessageBeep(0);
}
void CMyFrame::OnFourBeeps(void)
{
	SetTimer(1,200,NULL);
}
void CMyFrame::OnGreetings(void)
{
	int MyChoice=MessageBoxW(_T("Hello there!\nDo you want four beeps?"),_T("Greeting"),MB_ICONEXCLAMATION|MB_YESNOCANCEL);
	if(MyChoice==IDYES)
		OnFourBeeps();
}
void CMyFrame::OnTimer(UINT nId)
{
	if(4==m_nBeeps)
	{
		KillTimer(1);
		m_nBeeps=0;
		return;
	}
	else
	{
		::MessageBeep(0);
		m_nBeeps++;
	}
}