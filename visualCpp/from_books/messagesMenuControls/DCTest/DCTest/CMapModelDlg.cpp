// CMapModelDlg.cpp : implementation file
//

#include "pch.h"
#include "DCTest.h"
#include "CMapModelDlg.h"
#include "afxdialogex.h"


// CMapModelDlg dialog

IMPLEMENT_DYNAMIC(CMapModelDlg, CDialogEx)

CMapModelDlg::CMapModelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAP_MODE, pParent)
	, m_szCombo(_T(""))
	, m_cxEllipse(0)
	, m_cyEllipse(0)
	, m_nPenWidth(0)
{

}

CMapModelDlg::~CMapModelDlg()
{
}

void CMapModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO, m_szCombo);
	DDX_Text(pDX, IDC_CXELLIPSE, m_cxEllipse);
	DDX_Text(pDX, IDC_CYELLIPSE, m_cyEllipse);
	DDX_Text(pDX, IDC_WIDTH, m_nPenWidth);
}


BEGIN_MESSAGE_MAP(CMapModelDlg, CDialogEx)
	ON_BN_CLICKED(IDC_COLOR, &CMapModelDlg::OnClickedColor)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMapModelDlg message handlers


void CMapModelDlg::OnClickedColor()
{
	CColorDialog dlgColor;
	if (dlgColor.DoModal() == IDOK) {
		m_clrOptiune = dlgColor.GetColor();
		//daca pensula exista deja, stergeti obiectul GDI curent inaine de a apela CreateSolidBrush
		if (m_brControl.Detach())
			m_brControl.DeleteObject();
		m_brControl.CreateSolidBrush(m_clrOptiune);
		InvalidateRect(NULL);
	}
}


HBRUSH CMapModelDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//change the color of the backgound of the dialog
	if (nCtlColor == CTLCOLOR_DLG || nCtlColor == CTLCOLOR_STATIC) {
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)m_brControl.GetSafeHandle();
	}
	else {
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
//	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}
