
// ListExDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ListEx.h"
#include "ListExDlg.h"
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


// CListExDlg dialog



CListExDlg::CListExDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_ICON, &CListExDlg::OnClickedRadioIcon)
	ON_BN_CLICKED(IDC_RADIO_LIST, &CListExDlg::OnClickedRadioList)
//	ON_COMMAND(IDC_RADIO_REPORT, &CListExDlg::OnRadioReport)
	ON_BN_CLICKED(IDC_RADIO_SMALL, &CListExDlg::OnClickedRadioSmall)
	ON_BN_CLICKED(IDC_RADIO_REPORT, &CListExDlg::OnClickedRadioReport)
END_MESSAGE_MAP()


// CListExDlg message handlers

BOOL CListExDlg::OnInitDialog()
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

	m_imageLarge.Create(IDB_BALLS, 32, 1, RGB(255, 255, 255));
	m_imageSmall.Create(IDB_SM_BALLS, 16, 1, RGB(255, 255, 255));
	m_listCtrl.SetImageList(&m_imageLarge, LVSIL_NORMAL);
	m_listCtrl.SetImageList(&m_imageSmall, LVSIL_SMALL);

	//crearea coloanelor in lista
	LV_COLUMN listColumn;
	LV_ITEM listItem;
	LPWSTR arColumns[3] = { _T("Oras"), _T("Fotbal"), _T("Baseball") };
	listColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	listColumn.fmt = LVCFMT_LEFT;
	listColumn.cx = 60;
	for (int nColumn = 0; nColumn < 3; nColumn++) {
		listColumn.iSubItem = nColumn;
		listColumn.pszText = arColumns[nColumn];
		m_listCtrl.InsertColumn(nColumn, &listColumn);
	}
	//adagarea articolelor in list
	listItem.mask = LVIF_TEXT | LVIF_IMAGE;
	listItem.iSubItem = 0;
	LPWSTR arOras[3] = { _T("Oakland"),_T("San Diego"),_T("Seattle") };
	LPWSTR arFotbal[3] = { _T("Raiders"),_T("Chargers"),_T("Seahawks") };
	LPWSTR arBaseball[3] = { _T("Atheletics"),_T("Padres"),_T("Mariners") };
	for (int nItem = 0; nItem < 3; nItem++) {
		listItem.iItem = nItem;
		listItem.pszText = arOras[nItem];
		listItem.iImage = nItem % 2;
		m_listCtrl.InsertItem(&listItem);
		m_listCtrl.SetItemText(nItem, 1, arFotbal[nItem]);
		m_listCtrl.SetItemText(nItem, 2, arBaseball[nItem]);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListExDlg::OnPaint()
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
HCURSOR CListExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CListExDlg::SetListView(DWORD dwNewStyle) {
	DWORD dwOldStyle;
	HWND hWndList;
	hWndList = m_listCtrl.GetSafeHwnd();
	dwOldStyle = GetWindowLong(hWndList, GWL_STYLE);
	if ((dwOldStyle & LVS_TYPEMASK) != dwNewStyle) {
		//dont' forget ~
		dwOldStyle &= ~LVS_TYPEMASK;
		dwNewStyle |= dwOldStyle;
		SetWindowLong(hWndList, GWL_STYLE, dwNewStyle);
	}
}

void CListExDlg::OnClickedRadioIcon()
{
	SetListView(LVS_ICON);
}


void CListExDlg::OnClickedRadioList()
{
	SetListView(LVS_LIST);
}


void CListExDlg::OnClickedRadioSmall()
{
	SetListView(LVS_SMALLICON);
}


void CListExDlg::OnClickedRadioReport()
{
	SetListView(LVS_REPORT);
}
