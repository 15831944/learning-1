// day1_helloDlg.h : header file
//

#if !defined(AFX_DAY1_HELLODLG_H__B1CF599F_3C1B_4C6F_856A_ADA4EA17FB28__INCLUDED_)
#define AFX_DAY1_HELLODLG_H__B1CF599F_3C1B_4C6F_856A_ADA4EA17FB28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay1_helloDlg dialog

class CDay1_helloDlg : public CDialog
{
// Construction
public:
	CDay1_helloDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay1_helloDlg)
	enum { IDD = IDD_DAY1_HELLO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay1_helloDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay1_helloDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHello();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY1_HELLODLG_H__B1CF599F_3C1B_4C6F_856A_ADA4EA17FB28__INCLUDED_)
