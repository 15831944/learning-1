
// TreeEx.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TreeEx.h"
#include "MainFrm.h"

#include "TreeExDoc.h"
#include "TreeExView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeExApp

BEGIN_MESSAGE_MAP(CTreeExApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CTreeExApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CTreeExApp construction

CTreeExApp::CTreeExApp() noexcept
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("TreeEx.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CTreeExApp object

CTreeExApp theApp;


// CTreeExApp initialization

BOOL CTreeExApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTreeExDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CTreeExView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CTreeExApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CTreeExApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree;
protected:
	CImageList m_imageList;
	BOOL m_bIsDragging;
	HTREEITEM m_dragItem;
	HTREEITEM m_dragTarget;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBegindragTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(TVN_BEGINDRAG, IDC_TREE, &CAboutDlg::OnBegindragTree)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// App command to run the dialog
void CTreeExApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTreeExApp message handlers





BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_imageList.Create(IDB_TREE, 14, 1, RGB(255, 0, 0));
	m_tree.SetImageList(&m_imageList, TVSIL_NORMAL);
	HTREEITEM hCapitol;
	hCapitol = m_tree.InsertItem(_T("Capitolul 1"), 0, 0);
	m_tree.InsertItem(_T("Ce"), 1, 1, hCapitol);
	m_tree.InsertItem(_T("De ce"), 1, 1, hCapitol);
	m_tree.InsertItem(_T("Cum"), 1, 1, hCapitol);
	hCapitol = m_tree.InsertItem(_T("Capitolul 2"), 0, 0);
	m_tree.InsertItem(_T("Ce"), 1, 1, hCapitol);
	m_tree.InsertItem(_T("De ce"), 1, 1, hCapitol);
	m_tree.InsertItem(_T("Cum"), 1, 1, hCapitol);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CAboutDlg::OnBegindragTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	m_dragItem = pNMTreeView->itemNew.hItem;
	if(m_tree.GetParentItem(m_dragItem) != NULL) {
		CImageList* pDragImage;
		pDragImage = m_tree.CreateDragImage(m_dragItem);
		m_tree.SelectItem(m_dragItem);
		pDragImage->BeginDrag(0, CPoint(0, 0));
		pDragImage->DragEnter(&m_tree, pNMTreeView->ptDrag);
		SetCapture();
		m_bIsDragging = TRUE;
	}
	*pResult = 0;
}


void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bIsDragging == TRUE) {
		CPoint ptTree(point);
		MapWindowPoints(&m_tree, &ptTree, 1);
		CImageList::DragMove(ptTree);
		UINT uHitTest = TVHT_ONITEM;
		m_dragTarget = m_tree.HitTest(ptTree, &uHitTest);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CAboutDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bIsDragging == TRUE) {
		CImageList::DragLeave(&m_tree);
		CImageList::EndDrag();
		ReleaseCapture();
		m_bIsDragging = FALSE;
		if (m_dragTarget != NULL) {
			HTREEITEM hParent;
			hParent = m_tree.GetParentItem(m_dragTarget);
			CString szLabel = m_tree.GetItemText(m_dragItem);
			if (hParent != NULL)
				m_tree.InsertItem(szLabel, 1, 1, hParent, m_dragTarget);
			else
				m_tree.InsertItem(szLabel, 1, 1, m_dragTarget, TVI_FIRST);
			m_tree.DeleteItem(m_dragItem);
		}
	}
	else {
		CDialogEx::OnLButtonUp(nFlags, point);
	}
}
