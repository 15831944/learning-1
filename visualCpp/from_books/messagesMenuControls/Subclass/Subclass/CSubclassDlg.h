#pragma once

#include "CNumericEdit.h"

// CSubclassDlg dialog

class CSubclassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubclassDlg)

public:
	CSubclassDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSubclassDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUBCLASS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CNumericEdit m_editNumeric;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
