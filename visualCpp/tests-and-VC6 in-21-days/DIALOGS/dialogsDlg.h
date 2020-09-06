// dialogsDlg.h : header file
//

#if !defined(AFX_DIALOGSDLG_H__769CCD84_5303_40E1_96D8_237E98F730E1__INCLUDED_)
#define AFX_DIALOGSDLG_H__769CCD84_5303_40E1_96D8_237E98F730E1__INCLUDED_

#include "MsgDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogsDlg dialog

class CDialogsDlg : public CDialog
{
// Construction
public:
	CDialogsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogsDlg)
	enum { IDD = IDD_DIALOGS_DIALOG };
	CButton	m_cWhichOption;
	CString	m_sResults;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnYesnocancel();
	afx_msg void OnFileopen();
	afx_msg void OnExit();
	afx_msg void OnAbortretryignore();
	afx_msg void OnBcustomdialog();
	afx_msg void OnBwhichoption();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMsgDlg m_dMsgDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSDLG_H__769CCD84_5303_40E1_96D8_237E98F730E1__INCLUDED_)
