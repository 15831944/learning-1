//header for windows include
#include<afxwin.h>

#define IDB_BUTTON 100

//main class for application
class CButtonTest : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CButtonWindow :  public CFrameWnd
{
	CButton *m_cb;
public:
	CButtonWindow();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler();
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CButtonWindow,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

BOOL CButtonTest::InitInstance()
{
	m_pMainWnd=new CButtonWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CButtonWindow::CButtonWindow()
{
	Create(NULL,"CButton test",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the user rectangle
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	m_cb=new CButton;
	m_cb->Create("Push Me",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect,this,IDB_BUTTON);
}

void CButtonWindow::OnSize(UINT mType,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	m_cb->MoveWindow(rect);
}

void CButtonWindow::ButtonHandler()
{
	MessageBeep(-1);
}
CButtonTest myApp;