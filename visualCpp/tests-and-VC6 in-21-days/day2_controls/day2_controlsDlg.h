// day2_controlsDlg.h : header file
//

#if !defined(AFX_DAY2_CONTROLSDLG_H__19A2148D_361C_4C54_94FB_F75737AAD204__INCLUDED_)
#define AFX_DAY2_CONTROLSDLG_H__19A2148D_361C_4C54_94FB_F75737AAD204__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay2_controlsDlg dialog

class CDay2_controlsDlg : public CDialog
{
// Construction
public:
	CDay2_controlsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay2_controlsDlg)
	enum { IDD = IDD_DAY2_CONTROLS_DIALOG };
	CString	m_strMessage;
	CString	m_strProgToRun;
	BOOL	m_bEnableMsg;
	BOOL	m_bEnablePrg;
	BOOL	m_bShowMsg;
	BOOL	m_bShowPrg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay2_controlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay2_controlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnClrmsg();
	afx_msg void OnDfltmsg();
	afx_msg void OnCkenblmsg();
	afx_msg void OnShowmsg();
	afx_msg void OnCkshwmsg();
	afx_msg void OnRunpgm();
	afx_msg void OnCkenblprg();
	afx_msg void OnCkshwprg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY2_CONTROLSDLG_H__19A2148D_361C_4C54_94FB_F75737AAD204__INCLUDED_)
