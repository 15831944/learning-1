// CTestDlg.cpp : implementation file
//

#include "pch.h"
#include "EditTest.h"
#include "CTestDlg.h"
#include "afxdialogex.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST, pParent)
	, m_editDDX(_T(""))
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_DDX, m_editDDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_TEST, &CTestDlg::OnClickedTest)
END_MESSAGE_MAP()


// CTestDlg message handlers


void CTestDlg::OnClickedTest()
{
	CString szEdit;
	CString szRezult;
	int nLung = m_editTest.LineLength();
	m_editTest.GetWindowTextW(szEdit);
	szRezult.Format(_T("%s are %d caractere"), szEdit, nLung);
	AfxMessageBox(szRezult);
}


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_editTest.SetWindowTextW(_T("Prestabilit"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
