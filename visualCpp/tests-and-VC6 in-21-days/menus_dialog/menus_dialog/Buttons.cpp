// Buttons.cpp : implementation file
//

#include "stdafx.h"
#include "Buttons.h"
#include "afxdialogex.h"


// CButtons dialog

IMPLEMENT_DYNAMIC(CButtons, CDialog)

CButtons::CButtons(CWnd* pParent /*=NULL*/)
	: CDialog(CButtons::IDD, pParent)
{
	m_iMirroring=1;
}

CButtons::~CButtons()
{
}

void CButtons::DoDataExchange(CDataExchange* pDX)
{	
	DDX_Text(pDX,IDC_EDITRW,m_sEditRW);
	DDX_Text(pDX,IDC_EDITRO,m_sEditRO);
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_PUTDATA, m_bPutData);
	DDX_Control(pDX, IDC_LISTBOX, m_cListBox);
}


BEGIN_MESSAGE_MAP(CButtons, CDialog)
	ON_BN_CLICKED(IDC_PUSH, &CButtons::OnPush)
	ON_BN_CLICKED(IDC_RADIO_YES,&CButtons::OnRadioYes)
	ON_BN_CLICKED(IDC_RADIO_NO,&CButtons::OnRadioNo)
	ON_EN_CHANGE(IDC_EDITRW,&CButtons::OnEditChange)
END_MESSAGE_MAP()


// CButtons message handlers


void CButtons::OnPush()
{
	// TODO: Add your control notification handler code here	
	UpdateData(TRUE);
	m_sEditRO=m_sEditRW;
	if(m_bPutData)
	{
		m_cListBox.InsertString(0,m_sEditRW);
	}
	UpdateData(FALSE);
}

void CButtons::OnRadioYes(void)
{
	CheckRadioButton(IDC_RADIO_YES,IDC_RADIO_NO,IDC_RADIO_YES);
	m_iMirroring=0;
}

void CButtons::OnRadioNo(void)
{
	CheckRadioButton(IDC_RADIO_YES,IDC_RADIO_NO,IDC_RADIO_NO);
	m_iMirroring=1;
}

void CButtons::OnEditChange(void)
{
	if(m_iMirroring==0)
	{
		UpdateData(TRUE);
		m_sEditRO=m_sEditRW;
		UpdateData(FALSE);
	}
}