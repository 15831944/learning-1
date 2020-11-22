// CUsersDlg.cpp : implementation file
//

#include "pch.h"
#include "Customers.h"
#include "CUsersDlg.h"
#include "afxdialogex.h"


// CUsersDlg dialog

IMPLEMENT_DYNAMIC(CUsersDlg, CDialogEx)

CUsersDlg::CUsersDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_DLG, pParent)
	, m_szAddr(_T(""))
	, m_szName(_T(""))
{

}

CUsersDlg::~CUsersDlg()
{
}

void CUsersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADDR, m_szAddr);
	DDX_Text(pDX, IDC_EDIT_NAME, m_szName);
}


BEGIN_MESSAGE_MAP(CUsersDlg, CDialogEx)
END_MESSAGE_MAP()


// CUsersDlg message handlers
