//header for windows include
#include<afxwin.h>
#define IDB_BUTTON 100
#define IDS_EDIT 200
//class for main application
class CButtonTest2App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CButtonTest2Window : public CFrameWnd
{
	CButton *m_cb;
	CStatic *m_cs;
public:
	CButtonTest2Window();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	DECLARE_MESSAGE_MAP();
};

BOOL CButtonTest2App::InitInstance()
{
	m_pMainWnd=new CButtonTest2Window;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CButtonTest2Window,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

CButtonTest2Window::CButtonTest2Window()
{
	//create the window
	Create(NULL,"Button test2",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the client rectangle for button
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+(rect.bottom-rect.top)/2-10;
	rect.InflateRect(-20,-20,-20,0);	
	//create the button
	m_cb=new CButton;
	m_cb->Create("Hit Me",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDB_BUTTON);
	//get the client rectangle for static
	GetClientRect(&rect);
	rect.top=rect.top+(rect.bottom-rect.top)/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_cs=new CStatic;
	m_cs->Create("",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDS_EDIT);
}

void CButtonTest2Window::OnSize(UINT nType,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+(rect.bottom-rect.top)/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_cb->MoveWindow(rect);
	GetClientRect(&rect);
	rect.top=rect.top+(rect.bottom-rect.top)/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_cs->MoveWindow(rect);
}

void CButtonTest2Window::ButtonHandler(void)
{
	CRect rect;
	//get the client rectangle for static
	GetClientRect(&rect);
	rect.top=rect.top+(rect.bottom-rect.top)/2+10;
	rect.InflateRect(-20,0,-20,-20);
	delete m_cs;
	m_cs=new CStatic;
	m_cs->Create("You have just hit me",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDS_EDIT);
}

CButtonTest2App myApp;