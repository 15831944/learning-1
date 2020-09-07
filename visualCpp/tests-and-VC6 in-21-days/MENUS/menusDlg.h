// menusDlg.h : header file
//

#if !defined(AFX_MENUSDLG_H__FC8C7341_BB41_4517_B536_CF5FFE3442FF__INCLUDED_)
#define AFX_MENUSDLG_H__FC8C7341_BB41_4517_B536_CF5FFE3442FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMenusDlg dialog

class CMenusDlg : public CDialog
{
// Construction
public:
	CMenusDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMenusDlg)
	enum { IDD = IDD_MENUS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMenusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnFileHello();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileExit();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUSDLG_H__FC8C7341_BB41_4517_B536_CF5FFE3442FF__INCLUDED_)
