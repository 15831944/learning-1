
// ListBoxDlg.h : header file
//

#pragma once


// CListBoxDlg dialog
class CListBoxDlg : public CDialogEx
{
// Construction
public:
	CListBoxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTBOX_DIALOG };
#endif

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
	afx_msg void OnClickedCheck();
	afx_msg void OnDblclkList();
	CComboBox m_comboList;
	afx_msg void OnCloseupCombo();
	afx_msg void OnEditupdateCombo();
	afx_msg void OnOK();
};
