//header fo windows
#include<afxwin.h>

//class for main application
class CSecondTest : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CSecondTestWindow : public CFrameWnd
{
	CStatic *m_cs;
public:
	CSecondTestWindow();
	afx_msg void OnSize(UINT,int,int);
	DECLARE_MESSAGE_MAP();	
};

void CSecondTestWindow::OnSize(UINT mtype,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	m_cs->MoveWindow(rect);
}

BEGIN_MESSAGE_MAP(CSecondTestWindow,CFrameWnd)
	ON_WM_SIZE()
END_MESSAGE_MAP();

BOOL CSecondTest::InitInstance()
{
	m_pMainWnd=new CSecondTestWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CSecondTestWindow::CSecondTestWindow()
{
	Create(NULL,"Second test",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//rectangle
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	//create the static
	m_cs=new CStatic;
	m_cs->Create("Hello worlds",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this);
}

CSecondTest myApp;