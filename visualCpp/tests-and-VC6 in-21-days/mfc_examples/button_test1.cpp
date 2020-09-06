//header include for windows
#include<afxwin.h>
#define IDB_BUTTON 100
#define IDS_STATIC 200

//class for main application
class CButtonTest1App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for main windows
class CButtonTest1Windows : public CFrameWnd
{
	CStatic *m_pStatic;
	CButton *m_pButton;
public:
	CButtonTest1Windows();
	afx_msg void OnSize(UINT,int,int);
	afx_msg void ButtonHandler(void);
	DECLARE_MESSAGE_MAP();
};
//mesage map
BEGIN_MESSAGE_MAP(CButtonTest1Windows,CFrameWnd)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

BOOL CButtonTest1App::InitInstance()
{
	m_pMainWnd=new CButtonTest1Windows;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CButtonTest1Windows::CButtonTest1Windows()
{
	//create the main
	Create(NULL,"button test 1",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//get the client rectangle to create the button
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton=new CButton;
	m_pButton->Create("Hit Me !!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDB_BUTTON);
	//get the client rectangle to create the static text
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_pStatic=new CStatic;
	m_pStatic->Create("",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDS_STATIC);
}

void CButtonTest1Windows::ButtonHandler(void)
{
	//compute the client rectangle to create the static text
	CRect rect;
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	delete m_pStatic;
	m_pStatic=new CStatic;
	m_pStatic->Create("you have hit me!!!",WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_STATIC);
}

void CButtonTest1Windows::OnSize(UINT mType,int cx,int cy)
{
	//get the client rectangle to create the button
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_pButton->MoveWindow(rect);
	//compute the client rectangle to create the static text
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	m_pStatic->MoveWindow(rect);
}

CButtonTest1App myApp;