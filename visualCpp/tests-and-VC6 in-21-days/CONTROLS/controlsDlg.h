// controlsDlg.h : header file
//

#if !defined(AFX_CONTROLSDLG_H__EC627F7B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
#define AFX_CONTROLSDLG_H__EC627F7B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CControlsDlg dialog

class CControlsDlg : public CDialog
{
// Construction
public:
	CControlsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControlsDlg)
	enum { IDD = IDD_CONTROLS_DIALOG };
	CSliderCtrl	m_slider;
	CProgressCtrl	m_progress;
	CSpinButtonCtrl	m_spin;
	int		m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CControlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLSDLG_H__EC627F7B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
