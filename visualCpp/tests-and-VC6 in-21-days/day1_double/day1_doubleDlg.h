// day1_doubleDlg.h : header file
//

#if !defined(AFX_DAY1_DOUBLEDLG_H__D00ED0F0_416E_407E_885B_4535C5A23385__INCLUDED_)
#define AFX_DAY1_DOUBLEDLG_H__D00ED0F0_416E_407E_885B_4535C5A23385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay1_doubleDlg dialog

class CDay1_doubleDlg : public CDialog
{
// Construction
public:
	CDay1_doubleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay1_doubleDlg)
	enum { IDD = IDD_DAY1_DOUBLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay1_doubleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay1_doubleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFirst();
	afx_msg void OnSecond();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY1_DOUBLEDLG_H__D00ED0F0_416E_407E_885B_4535C5A23385__INCLUDED_)
