
// ListBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ListBox.h"
#include "ListBoxDlg.h"
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
public:
//	virtual BOOL OnInitDialog();
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


// CListBoxDlg dialog



CListBoxDlg::CListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_listBox);
	DDX_Control(pDX, IDC_COMBO, m_comboList);
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK, &CListBoxDlg::OnClickedCheck)
	ON_LBN_DBLCLK(IDC_LIST, &CListBoxDlg::OnDblclkList)
	ON_CBN_CLOSEUP(IDC_COMBO, &CListBoxDlg::OnCloseupCombo)
	ON_CBN_EDITUPDATE(IDC_COMBO, &CListBoxDlg::OnEditupdateCombo)
	ON_BN_CLICKED(IDOK, &CListBoxDlg::OnOK)
END_MESSAGE_MAP()


// CListBoxDlg message handlers

BOOL CListBoxDlg::OnInitDialog()
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

	m_listBox.AddString(_T("Foo"));
	m_listBox.AddString(_T("Bar"));
	m_listBox.AddString(_T("Baz"));

	m_comboList.AddString(_T("FooCombo"));
	m_comboList.AddString(_T("BarCombo"));
	m_comboList.AddString(_T("BazCombo"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBoxDlg::OnPaint()
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
HCURSOR CListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBoxDlg::OnClickedCheck()
{
	CString data;
	data.Format(_T("Caseta are %d elemente"), m_listBox.GetCount());
	AfxMessageBox(data);
}


void CListBoxDlg::OnDblclkList()
{
	int nSelectie = m_listBox.GetCurSel();
	if (nSelectie != LB_ERR) {
		CString szSelectie;
		m_listBox.GetText(nSelectie, szSelectie);
		AfxMessageBox(szSelectie);
	}
}


void CListBoxDlg::OnCloseupCombo()
{
	CString szOptiune;
	CString szRezultat;
	int nOptiune;
	//citeste selectiile curente din controalele de editare si cele tip caseta lista
	m_comboList.GetWindowTextW(szOptiune);
	nOptiune = m_comboList.GetCurSel();
	if (nOptiune != CB_ERR) {
		//daca in caseta lista a fost facuta o optiune valida, preia sirul de cractere al articolului
		m_comboList.GetLBText(nOptiune, szOptiune);
		szRezultat = _T("Inchide prima selectie ") + szOptiune;
	}
	else if (szOptiune.IsEmpty() == TRUE) {
		//nu s-a facut nici o optiune din caseta lista, iar controlul de editare era gol
		szRezultat = " Nici o optiune selectata";
	}
	else if (m_comboList.FindStringExact(-1, szOptiune) != CB_ERR) {
		//sirul din controlul de editare a fost gasit in caseta lista
		szRezultat = _T("Adaugare ") + szOptiune + _T(" la lista");
	}
	else {
		//sirul din controlul de editare a fost gasit in caseta lista. Adauga sirul
		m_comboList.AddString(szOptiune);
		szRezultat = _T("Adaug ") + szOptiune + _T("in lista");
	}
	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	ASSERT(pWnd);
	if (pWnd)
		pWnd->SetWindowTextW(szRezultat);

}


void CListBoxDlg::OnEditupdateCombo()
{
	CString szOptiune;
	CString szRezultat;
	m_comboList.GetWindowText(szOptiune);
	szRezultat = _T(" Optiunea modificata in ") + szOptiune;
	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	ASSERT(pWnd);
	if (pWnd)
		pWnd->SetWindowTextW(szRezultat);
}


void CListBoxDlg::OnOK()
{
	CString szCombo;
	m_comboList.GetWindowText(szCombo);
	AfxMessageBox(szCombo);
	int nOptione = m_comboList.GetCurSel();
	szCombo.Format(_T("Selectia curenta este %d"), nOptione);
	AfxMessageBox(szCombo);
//	CDialogEx::OnOK();
}
