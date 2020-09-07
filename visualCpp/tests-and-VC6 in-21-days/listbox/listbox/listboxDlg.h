
// listboxDlg.h : header file
//

#pragma once
#include "afxwin.h"


// ClistboxDlg dialog
class ClistboxDlg : public CDialogEx
{
// Construction
public:
	ClistboxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnDblclkList();
	CComboBox m_comboList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnCloseupCombo();
	afx_msg void OnEditupdateCombo();
};
