//header for windows
#include<afxwin.h>

#define IDC_BUTTON 100
#define IDC_EDIT   101

//main class for application
class CButtonEdit2App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//main class for window
class CButtonEdit2Window : public CFrameWnd
{
	CButton m_Button;
	CString m_message;
public:
	CButtonEdit2Window();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	enum {IDD=IDC_EDIT};
	CEdit m_Edit;
	virtual void DoDataExchange(CDataExchange *pDX);
	DECLARE_MESSAGE_MAP();
};

BOOL CButtonEdit2App::InitInstance()
{
	m_pMainWnd=new CButtonEdit2Window;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CButtonEdit2Window,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

void CButtonEdit2Window::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX,IDC_EDIT,m_message);
}

CButtonEdit2Window::CButtonEdit2Window()
{
	CRect rect;
	Create(NULL,"Button and Edit",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the client rect
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_Button.Create("Hit me !!",WS_VISIBLE|WS_CHILD|SS_CENTER|BS_PUSHBUTTON,rect,this,IDC_BUTTON);
	//get the client rect
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_Edit.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_EDIT);
}

void CButtonEdit2Window::ButtonHandler(void)
{
	m_message="you have hit me !!";
	UpdateData(FALSE);
}

void CButtonEdit2Window::OnSize(UINT mType,int cx,int cy)
{
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_Button.MoveWindow(rect);
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_Edit.MoveWindow(rect);
}

CButtonEdit2App myApp;