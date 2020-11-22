
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "CtrlBar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateTimer)
	ON_BN_CLICKED(IDC_BAR_HELP, OnBarHelp)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_TIME
};

static UINT BASED_CODE arToolButtons[] = {
	ID_APP_ABOUT,
	ID_SEPARATOR,
	ID_VIEW_TOOLBAR,
	ID_VIEW_STATUS_BAR
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//initialiarea ceasului pentru bara de stare
	m_wndStatusBar.SetPaneInfo(4, ID_INDICATOR_TIME, SBPS_POPOUT, 80);
	SetTimer(1, 1000, NULL);
	
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//crearea unei bare de dialog
	m_dlgBar.Create(this, IDD_BAR, CBRS_TOP, IDD_BAR);
	m_dlgBar.SetWindowTextW(_T("Bara de dialog"));
	m_dlgBar.EnableDocking(CBRS_ALIGN_ANY);
	//ancoreaza bara in fereastra principala
	DockControlBar(&m_dlgBar);
	//createa unei bare de instrumente flotante
	m_toolBar.Create(this);
	m_toolBar.SetWindowTextW(_T("Instrumente"));
	m_toolBar.LoadBitmapW(IDB_TOOLS);
	m_toolBar.SetButtons(arToolButtons, sizeof(arToolButtons) / sizeof(UINT));
	//permite ancorarea, chiar daca initial bare de instrumente va fi flotanta
	m_toolBar.EnableDocking(CBRS_ALIGN_ANY);
	//calculreaza pozitia barei de instrumente
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	FloatControlBar(&m_toolBar, rc.TopLeft());
	UINT nOldStyle = m_toolBar.GetBarStyle();
	m_toolBar.SetBarStyle(nOldStyle | CBRS_TOOLTIPS | CBRS_FLYBY);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	m_wndStatusBar.InvalidateRect(NULL);

	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnUpdateTimer(CCmdUI* pCmdUI) {
	pCmdUI->Enable();
	CTime theTime = CTime::GetCurrentTime();
	CString szTime = theTime.Format("%I:%M:%S %p");
	pCmdUI->SetText(szTime);
}

void CMainFrame::OnBarHelp() {
	AfxMessageBox(_T("Selectat helpul din bara de dialog"));
}