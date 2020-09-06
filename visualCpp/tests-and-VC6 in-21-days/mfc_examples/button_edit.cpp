//header for windows
#include<afxwin.h>

#define IDB_BUTTON 100
#define IDC_EDIT   200

//class for main application
class CButtonEditApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for main windows
class CButtonEditWindows : public CFrameWnd
{
	CEdit *m_pEdit;
	CButton *m_pButton;
	CString m_display;
public:
	CButtonEditWindows();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CButtonEditWindows,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

BOOL CButtonEditApp::InitInstance()
{
	m_pMainWnd=new CButtonEditWindows;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CButtonEditWindows::CButtonEditWindows()
{
	//create the windows
	Create(NULL,"Button and edit box",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton=new CButton;
	m_pButton->Create("Hit Me !!!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDB_BUTTON);
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_pEdit=new CEdit;
	m_pEdit->Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_EDIT);
}

void CButtonEditWindows::OnSize(UINT mtype,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton->MoveWindow(rect);
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_pEdit->MoveWindow(rect);
}

void CButtonEditWindows::ButtonHandler(void)
{

}

CButtonEditApp myApp;