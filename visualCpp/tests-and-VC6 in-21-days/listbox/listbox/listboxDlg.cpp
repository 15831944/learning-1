
// listboxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "listbox.h"
#include "listboxDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClistboxDlg dialog



ClistboxDlg::ClistboxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClistboxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClistboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_listBox);
	//  DDX_Control(pDX, IDC_COMBO, m_comboBox);
	DDX_Control(pDX, IDC_COMBO, m_comboList);
}

BEGIN_MESSAGE_MAP(ClistboxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST, &ClistboxDlg::OnDblclkList)
	ON_BN_CLICKED(IDOK, &ClistboxDlg::OnBnClickedOk)
	ON_CBN_CLOSEUP(IDC_COMBO, &ClistboxDlg::OnCloseupCombo)
	ON_CBN_EDITUPDATE(IDC_COMBO, &ClistboxDlg::OnEditupdateCombo)
END_MESSAGE_MAP()


// ClistboxDlg message handlers

BOOL ClistboxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	m_listBox.AddString(_T("foo"));
	m_listBox.AddString(_T("Bar"));
	m_listBox.AddString(_T("Buzz"));
	m_comboList.AddString(_T("Foo"));
	m_comboList.AddString(_T("Bar"));
	m_comboList.AddString(_T("Buzz"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void ClistboxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void ClistboxDlg::OnPaint()
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
HCURSOR ClistboxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClistboxDlg::OnDblclkList()
{
	int nSelectie=m_listBox.GetCurSel();
	if(nSelectie!=LB_ERR)
	{
		CString szSelectie;
		m_listBox.GetText(nSelectie,szSelectie);
		AfxMessageBox(szSelectie);
	}
}


void ClistboxDlg::OnBnClickedOk()
{
	CString szCombo;
	m_comboList.GetWindowTextW(szCombo);
	AfxMessageBox(szCombo);
	int nOptiune=m_comboList.GetCurSel();
	szCombo.Format(_T("Selectia currenta este %d"),nOptiune);
	AfxMessageBox(szCombo);
	CDialogEx::OnOK();
}


void ClistboxDlg::OnCloseupCombo()
{
	CString szOptiune;
	CString szRezultat;
	int nOptiune;
	m_comboList.GetWindowTextW(szOptiune);
	nOptiune=m_comboList.GetCurSel();
	if(nOptiune!=CB_ERR)
	{
		m_comboList.GetLBText(nOptiune,szOptiune);
		szRezultat=_T("inchide dupa selectie ") + szOptiune;
	}
	else if(szOptiune.IsEmpty()==TRUE)
	{
		szRezultat=_T("nu s-a selectat nici o optiune");
	}
	else if(m_comboList.FindStringExact(-1,szOptiune)!=CB_ERR)
	{
		szRezultat=_T("Adaugare ") +szOptiune + _T("la lista");
		m_comboList.AddString(szOptiune);
		szRezultat=_T("Adaug ") + szOptiune + _T(" in lista");
	}
	CWnd* pWnd=GetDlgItem(IDC_RESULT);
	ASSERT(pWnd);
	if(pWnd)
		pWnd->SetWindowTextW(szRezultat);
}


void ClistboxDlg::OnEditupdateCombo()
{
	CString szOptiune;
	CString szRezultat;
	m_comboList.GetWindowTextW(szOptiune);
	szRezultat=_T("Optiunea modificata in ") + szOptiune;
	CWnd* pWnd=GetDlgItem(IDC_RESULT);
	ASSERT(pWnd);
	if(pWnd)
		pWnd->SetWindowTextW(szRezultat);
}
