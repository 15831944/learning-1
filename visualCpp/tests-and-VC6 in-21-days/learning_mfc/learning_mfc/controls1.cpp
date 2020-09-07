//header for windows include
#include<afxwin.h>

#define IDC_BUTTON 100
#define IDC_HITEDITRO 101
#define IDC_EDITRW 102

//main class for application
class CControls1App : CWinApp
{
public:
	virtual BOOL InitInstance();
};

//main class for window
class CControls1Window : public CFrameWnd
{
protected:
	CButton m_cButton;
	CEdit   m_cHitEditRo;
	CEdit   m_cEditRW;
	CString m_sMessageRO;
	CString m_sMessageRW;
	int m_iCounter;
public:
	CControls1Window();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	afx_msg void OnPaint(void);
	afx_msg void OnChanged(void);
	virtual void DoDataExchange(CDataExchange *pDX);
	DECLARE_MESSAGE_MAP();
};

BOOL CControls1App::InitInstance()
{
	m_pMainWnd=new CControls1Window;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

//dodataexchange implementation
void CControls1Window::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX,IDC_HITEDITRO,m_sMessageRO);
	DDX_Text(pDX,IDC_EDITRW,m_sMessageRW);
}

//message mapping
BEGIN_MESSAGE_MAP(CControls1Window,CFrameWnd)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDITRW,OnChanged)
	ON_BN_CLICKED(IDC_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

CControls1Window::CControls1Window()
{
	//create the window
	Create(NULL,"Controls one",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
	//rectangle for operations
	CRect rect;
	//create the parameters for button
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,0);
	//create the button
	m_cButton.Create("Hit me !!!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDC_BUTTON);
	//create the parameters for edit ro
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,0,0,-20);
	//create the edit RO rectangle
	m_cHitEditRo.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_HITEDITRO);
	m_cHitEditRo.SetReadOnly();
	m_iCounter=0;
	//create the message
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,-20,-20,0);
	CDC* pDC=GetDC();
	pDC->DrawText(m_sMessageRW,rect,DT_SINGLELINE);
	//create the edit RW
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,0,-20,-20);
	m_cEditRW.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|SS_CENTER,rect,this,IDC_EDITRW);
}

void CControls1Window::OnSize(UINT mType,int cx,int cy)
{
	CRect rect;
	//create the parameters for button
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,0);
	m_cButton.MoveWindow(rect);
	//create the parameters for edit ro
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,0,0,-20);
	m_cHitEditRo.MoveWindow(rect);
}

void CControls1Window::OnPaint()
{
	CRect rect;
	PAINTSTRUCT ps;
	CDC* pDC = BeginPaint(&ps);
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,-20,0,-20);
	pDC->DrawText(m_sMessageRW,rect,DT_SINGLELINE);
	EndPaint(&ps);
}

void CControls1Window::OnChanged(void)
{
	UpdateData(TRUE);
	CDC *pDC=GetDC();
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,-20,-20,0);
	pDC->DrawText(m_sMessageRW,rect,DT_SINGLELINE);
}

void CControls1Window::ButtonHandler(void)
{
	m_iCounter++;
	m_sMessageRO.Format("You have hit me %d times",m_iCounter);
    UpdateData(FALSE);
}

CControls1App myApp;