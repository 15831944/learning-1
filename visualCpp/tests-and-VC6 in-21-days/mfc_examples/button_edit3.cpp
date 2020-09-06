//header for windows
#include<afxwin.h>

#define IDC_HITEDIT		100
#define IDC_HITBUTTON	101
#define IDC_HITCOUNT	102

//class for main application
class CButtonEdit3App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for main winodow
class CButtonEdit3Window : public CFrameWnd
{
protected:
	int m_iCounter;
	CButton m_HitButton;
	CEdit m_HitEdit;
	CEdit m_HitCount;
	CString m_sMessage;
public:
	CButtonEdit3Window();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	virtual void DoDataExchange(CDataExchange *pDX);
	DECLARE_MESSAGE_MAP();
};

void CButtonEdit3Window::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX,IDC_HITEDIT,m_sMessage);
	DDX_Text(pDX,IDC_HITCOUNT,m_iCounter);
}

BOOL CButtonEdit3App::InitInstance(void)
{
	m_pMainWnd=new CButtonEdit3Window;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CButtonEdit3Window,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_HITBUTTON,ButtonHandler)
END_MESSAGE_MAP();

CButtonEdit3Window::CButtonEdit3Window()
{
	//rectangle for operations
	CRect rect;
	//create the main window
	Create(NULL,"Layout for hit me !",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//compute the size for button and create it
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,0);
	m_HitButton.Create("Hit me !!!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDC_HITBUTTON);
	//compute the size for the down edit control
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,0,0,-20);
	m_HitEdit.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_HITEDIT);
	m_HitEdit.SetReadOnly();
	//compute the size for the down right edit control
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,0,-20,-20);
	m_HitCount.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_HITCOUNT);
	m_HitCount.SetReadOnly();
	//reset the counters
	m_iCounter=0;
	m_sMessage="";
}

void CButtonEdit3Window::OnSize(UINT mType,int cx,int cy)
{
	//rectangle for operations
	CRect rect;
	//compute the size for button and create it
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,0);
	m_HitButton.MoveWindow(rect);
	//compute the size for the down edit control
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,0,0,-20);
	m_HitEdit.MoveWindow(rect);
	//compute the size for the down right edit control
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,0,-20,-20);
	m_HitCount.MoveWindow(rect);
}

void CButtonEdit3Window::ButtonHandler(void)
{
	m_iCounter++;
	m_sMessage.FormatMessage("You have hit me %1!d! times",m_iCounter);
	UpdateData(FALSE);
}

CButtonEdit3App myApp;