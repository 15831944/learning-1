//header for windows
#include<afxwin.h>

//class for main application
class CStaticTests : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for the frame
class CStaticWindow: public CFrameWnd
{
private:
	CStatic *cs;
public:
	CStaticWindow();
};

BOOL CStaticTests::InitInstance()
{
	m_pMainWnd=new CStaticWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CStaticWindow::CStaticWindow()
{
	//create the window itself
	Create(NULL,"Cstatic tests",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the client rectangle
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	//create the static part
	cs=new CStatic;
	cs->Create("Hello world",WS_CHILD|WS_BORDER|WS_VISIBLE|SS_CENTER,rect,this);
}

CStaticTests myApp;