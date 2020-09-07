// clientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__62A29D4A_2EE1_497A_8181_C51C15CFD17F__INCLUDED_)
#define AFX_CLIENTDLG_H__62A29D4A_2EE1_497A_8181_C51C15CFD17F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CIPAddressCtrl	m_addrctl;
	int		m_port;
	CString	m_recv;
	CString	m_send;
	CString	m_error;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CSocket m_socket;
	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onconnect();
	afx_msg void Onend();
	afx_msg void Onrequest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__62A29D4A_2EE1_497A_8181_C51C15CFD17F__INCLUDED_)
