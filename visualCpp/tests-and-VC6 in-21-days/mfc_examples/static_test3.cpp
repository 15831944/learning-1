//header for windows
#include<afxwin.h>

//class for application
class CStaticTest : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CStaticWindow : public CFrameWnd
{
	CStatic *cs;
public:
	CStaticWindow();
	afx_msg void OnSize(UINT,int,int);
	DECLARE_MESSAGE_MAP();
};

void CStaticWindow::OnSize(UINT mtype,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	cs->MoveWindow(rect);
}

BEGIN_MESSAGE_MAP(CStaticWindow,CFrameWnd)
	ON_WM_SIZE()
END_MESSAGE_MAP();

BOOL CStaticTest::InitInstance()
{
	m_pMainWnd=new CStaticWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CStaticWindow::CStaticWindow()
{
	//create the main window
	Create(NULL,"Cstatic window moving",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the rectangle
	CRect rect;
	GetClientRect(&rect);
	//reduce the rectangle with 20
	rect.InflateRect(-20,-20);
	//create the static text
	cs=new CStatic;
	cs->Create("Hellow World",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this);
}

CStaticTest myApp;