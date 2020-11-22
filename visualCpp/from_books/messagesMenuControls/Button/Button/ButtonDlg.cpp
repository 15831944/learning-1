
// ButtonDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Button.h"
#include "ButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CButtonDlg dialog



CButtonDlg::CButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_BTN_TEST, m_btnTest);
	DDX_Control(pDX, IDC_CHECK_AMP, m_btnAmp);
	DDX_Control(pDX, IDC_GROUP_VOLUME, m_btnVolume);
	DDX_Control(pDX, IDC_RADIO_HIGH, m_btnHigh);
	DDX_Control(pDX, IDC_RADIO_LOW, m_btnLow);
	DDX_Control(pDX, IDC_ENABLE_RECORDING, m_btnEnableRecording);
}

BEGIN_MESSAGE_MAP(CButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDD_BTN_TEST, &CButtonDlg::OnBtnTest)
END_MESSAGE_MAP()


// CButtonDlg message handlers

BOOL CButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CButtonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CButtonDlg::OnBtnTest()
{
//	AfxMessageBox(_T("S-a apasat butonul de test"));
	static BOOL bSetNivelApa = TRUE;
	if (bSetNivelApa == TRUE) {
		m_btnVolume.SetWindowTextW(_T("&Nivelul apei"));
		m_btnAmp.SetWindowTextW(_T("&Record"));
		m_btnEnableRecording.EnableWindow(TRUE);
		m_btnEnableRecording.ShowWindow(SW_SHOW);
		bSetNivelApa = FALSE;
	}
	else {
		m_btnVolume.SetWindowTextW(_T("&Volume"));
		m_btnAmp.SetWindowTextW(_T("&Amplify"));
		m_btnEnableRecording.EnableWindow(FALSE);
		m_btnEnableRecording.ShowWindow(SW_HIDE);
		bSetNivelApa = TRUE;
	}
}
