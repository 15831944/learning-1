#include<afxwin.h>
#include<afxtempl.h>
#include<list>
#include<array>
#include <string>
using namespace std;

#define IDC_BUTTON 100
#define IDC_STL 101
#define IDC_MFC 102

//class for stl
class CSTL
{
	list<string> m_internal;
public:
	CSTL();
	CString Update(void);
};

CSTL::CSTL()
{
	m_internal.push_back("first");
	m_internal.push_back("second");
	m_internal.push_back("third");
}

CString CSTL::Update(void)
{
	CString ret;
	for(list<string>::iterator it=m_internal.begin();it!=m_internal.end();++it)
	{
		ret+=(*it).c_str();
		ret+="\r\n";
	}
	return ret;
}

//class for mfc
class CMFC : public CObject
{
	CList<CString,CString&> m_internal;
public:
	CMFC();
	CString Update(void);
#ifdef _DEBUG
	void Dump(CDumpContext& dc)
	{
		CObject::Dump(dc);
		dc<<m_internal;
	}
#endif
};

CMFC::CMFC()
{
	m_internal.AddTail(CString("first"));
	m_internal.AddTail(CString("second"));
	m_internal.AddTail(CString("third"));
}

CString CMFC::Update(void)
{
	CString ret;
	POSITION pos=m_internal.GetHeadPosition();
	for(int i=0;i<m_internal.GetCount();++i)
	{
		ret+=m_internal.GetNext(pos);
		ret+="\r\n";
	}
	return ret;
}

//main class for application
class stlmfcApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for main window
class stlmfcWindow : public CFrameWnd
{
	CEdit m_cSTL;
	CEdit m_cMFC;
	CButton m_cButton;
	CString m_szSTL;
	CString m_szMFC;
	CSTL m_stl;
	CMFC m_mfc;
public:
	stlmfcWindow();
protected:
	afx_msg void ButtonHandler(void);
	void DoDataExchange(CDataExchange *pDX);
	DECLARE_MESSAGE_MAP();
};

BOOL stlmfcApp::InitInstance()
{
	m_pMainWnd=new stlmfcWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

//start the main
stlmfcApp myApp;

stlmfcWindow::stlmfcWindow()
{
	//create the window
	Create(NULL,"stl vs mfc",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
	//create the edit boxes
	CRect rect;
	//create the stl view
	GetClientRect(&rect);
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,-20);
	rect.bottom=rect.bottom-60;
	m_cSTL.Create(ES_MULTILINE|WS_CHILD|WS_BORDER|WS_VISIBLE,rect,this,IDC_STL);
	m_cSTL.SetReadOnly();
	//create the mfc view
	GetClientRect(&rect);
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,-20,-20,-20);
	rect.bottom=rect.bottom-60;
	m_cMFC.Create(ES_MULTILINE|WS_CHILD|WS_BORDER|WS_VISIBLE,rect,this,IDC_MFC);
	m_cMFC.SetReadOnly();
	//create the push button
	GetClientRect(&rect);
	rect.InflateRect(-20,-20,-20,-20);
	rect.top=rect.bottom-50;
	rect.right=rect.left+60;
	m_cButton.Create("Change",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDC_BUTTON);
}

BEGIN_MESSAGE_MAP(stlmfcWindow,CFrameWnd)
	ON_BN_CLICKED(IDC_BUTTON,ButtonHandler)
END_MESSAGE_MAP();

void stlmfcWindow::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX,IDC_STL,m_szSTL);
	DDX_Text(pDX,IDC_MFC,m_szMFC);
}

void stlmfcWindow::ButtonHandler(void)
{
	m_szMFC=m_mfc.Update();
	m_szSTL=m_stl.Update();
	UpdateData(FALSE);
}