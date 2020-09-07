#pragma once
#include "resource.h"

// CButtons dialog

class CButtons : public CDialog
{
	DECLARE_DYNAMIC(CButtons)
private:
	CString m_sEditRW;
	CString m_sEditRO;
	int m_iMirroring;
public:
	CButtons(CWnd* pParent = NULL);   // standard constructor
	virtual ~CButtons();

// Dialog Data
	enum { IDD = IDD_BUTTONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnPush();
	afx_msg void OnRadioYes();
	afx_msg void OnRadioNo();
	afx_msg void OnEditChange();
public:
	BOOL m_bPutData;
	CListBox m_cListBox;
};
