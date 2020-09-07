// ComboListDlg.h : header file
//

#if !defined(AFX_COMBOLISTDLG_H__C7C52A25_ABD6_11DB_B910_E53D54DB6E4F__INCLUDED_)
#define AFX_COMBOLISTDLG_H__C7C52A25_ABD6_11DB_B910_E53D54DB6E4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboListDlg dialog

class CComboListDlg : public CDialog
{
// Construction
public:
	CComboListDlg(CWnd* pParent = NULL);	// standard constructor
	int m_data[3];
// Dialog Data
	//{{AFX_DATA(CComboListDlg)
	enum { IDD = IDD_COMBOLIST_DIALOG };
	CComboBox	m_combo;
	int		m_rez;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CComboListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelendokcombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOLISTDLG_H__C7C52A25_ABD6_11DB_B910_E53D54DB6E4F__INCLUDED_)
