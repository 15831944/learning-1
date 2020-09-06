// dialogsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialogs.h"
#include "MsgDlg.h"
#include "dialogsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogsDlg dialog

CDialogsDlg::CDialogsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogsDlg)
	m_sResults = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogsDlg)
	DDX_Control(pDX, IDC_BWHICHOPTION, m_cWhichOption);
	DDX_Text(pDX, IDC_RESULTS, m_sResults);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogsDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_YESNOCANCEL, OnYesnocancel)
	ON_BN_CLICKED(IDC_FILEOPEN, OnFileopen)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_ABORTRETRYIGNORE, OnAbortretryignore)
	ON_BN_CLICKED(IDC_BCUSTOMDIALOG, OnBcustomdialog)
	ON_BN_CLICKED(IDC_BWHICHOPTION, OnBwhichoption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogsDlg message handlers

BOOL CDialogsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_cWhichOption.EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDialogsDlg::OnYesnocancel() 
{

	int iResults;
	iResults=MessageBox("Press the Yes,No,Cancel Button!",
		"Yes, No, Cancel Dialog",
		MB_YESNOCANCEL|MB_ICONINFORMATION);
	switch(iResults)
	{
	case IDYES:
		m_sResults="YES ! YES ! YES !";
		break;
	case IDNO:
		m_sResults="NO ! NO ! NO !";
		break;
	case IDCANCEL:
		m_sResults="Sorry Calceled!";
		break;
	}
	UpdateData(FALSE);
}

void CDialogsDlg::OnFileopen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog m_OpenFile(TRUE);
	if(m_OpenFile.DoModal()==IDOK)
	{
		m_sResults=m_OpenFile.GetFileName();
		UpdateData(FALSE);
	}
}

void CDialogsDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDialogsDlg::OnAbortretryignore() 
{
	// TODO: Add your control notification handler code here
	int iResults;
	iResults=MessageBox("Pres the Abort, Retry, Ignore button",
		"Abort,Retry,Ignore",
		MB_ABORTRETRYIGNORE|MB_ICONINFORMATION);
	switch(iResults)
	{
	case IDABORT:
		m_sResults="Abort ! Abort ! Abort !";
		break;
	case IDRETRY:
		m_sResults="Retry ! Retry ! Retry ! Again!";
		break;
	case IDIGNORE:
		m_sResults="Ignore the Message!";
		break;
	}
	UpdateData(FALSE);
}

void CDialogsDlg::OnBcustomdialog() 
{
	// TODO: Add your control notification handler code here
	if(m_dMsgDlg.DoModal()==IDOK)
	{
		m_sResults=m_dMsgDlg.m_sMessage;
		UpdateData(FALSE);
		m_cWhichOption.EnableWindow(TRUE);
	}
	else m_cWhichOption.EnableWindow(FALSE);
}

void CDialogsDlg::OnBwhichoption() 
{
	// TODO: Add your control notification handler code here
	switch(m_dMsgDlg.m_iOption)
	{
		case 0:
			m_sResults="First Option!";
			break;
		case 1:
			m_sResults="Second Option!";
			break;
		case 2:
			m_sResults="Third Option!";
			break;
		case 3:
			m_sResults="Forth Option!";
			break;
	}
	UpdateData(FALSE);
}
