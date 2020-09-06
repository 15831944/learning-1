//header for windows
#include<afxwin.h>

#define IDB_BUTTON 100
#define IDC_EDIT 200

//main class for application
class CButtonEditApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//main class for winodow
class CButtonEditWindow : public CFrameWnd
{
	CButton *m_pButton;
	CString m_str;
public:
	CButtonEditWindow();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	//{{AFX_DATA(CButtonEditWindows)
		enum { IDD=IDC_EDIT};
		CEdit m_Edit;
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonEditWindows)
	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	DECLARE_MESSAGE_MAP();
};

void CButtonEditWindow::DoDataExchange(CDataExchange* pDX)
{
    CWnd::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CButtonEditWindows)
//    DDX_Control(pDX, IDC_EDIT, m_Edit);
	DDX_Text(pDX, IDC_EDIT, m_str);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CButtonEditWindow,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

BOOL CButtonEditApp::InitInstance()
{
	m_pMainWnd=new CButtonEditWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CButtonEditWindow::CButtonEditWindow()
{
	//create the windows
	Create(NULL,"Button and edit",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the rectangle for button
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton=new CButton;
	m_pButton->Create("Hit Me !!!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDB_BUTTON);
	//get the rectangle for edit
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_Edit.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_EDIT);
}

void CButtonEditWindow::OnSize(UINT mType,int cx,int cy)
{
	CRect rect;
	//get the rectagle for button
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton->MoveWindow(rect);
	//get the rectangle for edit box
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_Edit.MoveWindow(rect);
}

void CButtonEditWindow::ButtonHandler(void)
{
	m_str="you have hit me !!!";
	UpdateData(FALSE);
}


CButtonEditApp myApp;