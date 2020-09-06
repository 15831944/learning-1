//include windows
#include<afxwin.h>

#define IDC_EDIT 100

//my basic class
class CMyBasic : public CObject
{
	DECLARE_DYNCREATE(CMyBasic);
public:
	CMyBasic();
	void Set(const CString& szMenu);
	CString Get(void) const;
#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
#endif
private:
	CString m_szMenu;
};

IMPLEMENT_DYNCREATE(CMyBasic,CObject);

//constructor for class
CMyBasic::CMyBasic()
{

}

//setter and gether
void CMyBasic::Set(const CString& szMenu)
{
	m_szMenu=szMenu;
}

CString CMyBasic::Get(void) const
{
	return m_szMenu;
}

#ifdef _DEBUG
void CMyBasic::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
	dc<<m_szMenu;
}
#endif


//class for main application
class CBasicApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for main window
class CBasicWindows: public CFrameWnd
{
	CString m_szText;
	CMyBasic* m_pBasic;
	CEdit m_cEdit;
public:
	CBasicWindows();
	virtual ~CBasicWindows()
	{
		delete m_pBasic;
	}
	afx_msg void OnPaint(void);
	afx_msg void EditChanged(void);
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP();
};

void CBasicWindows::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX,IDC_EDIT,m_szText);
}

void CBasicWindows::EditChanged(void)
{
	UpdateData(TRUE);
	CRect rect;
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	CDC *pDC=GetDC();
	m_pBasic->Set(m_szText);
	pDC->DrawText(m_pBasic->Get(),rect,SS_CENTER);
}

void CBasicWindows::OnPaint()
{
	PAINTSTRUCT ps;
	CRect rect;
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.InflateRect(-20,0,-20,-20);
	CDC *pDC=BeginPaint(&ps);
	m_pBasic->Set(m_szText);
	pDC->DrawText(m_pBasic->Get(),rect,SS_CENTER);
	EndPaint(&ps);
}

BEGIN_MESSAGE_MAP(CBasicWindows,CFrameWnd)
	ON_WM_PAINT()
	ON_EN_UPDATE(IDC_EDIT,EditChanged)
END_MESSAGE_MAP();

BOOL CBasicApp::InitInstance()
{
	m_pMainWnd=new CBasicWindows;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CBasicWindows::CBasicWindows()
{
	Create(NULL," basic exchanged",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
	CRect rect;
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.InflateRect(-20,-20,-20,0);
	m_cEdit.Create(WS_CHILD|WS_VISIBLE|SS_CENTER,rect,this,IDC_EDIT);
	CRuntimeClass* pRuntime=RUNTIME_CLASS(CMyBasic);
	CObject* pObject=pRuntime->CreateObject();
	ASSERT(pObject->IsKindOf(RUNTIME_CLASS(CMyBasic)));
	m_pBasic=(CMyBasic*)pObject;
}

CBasicApp myApp;