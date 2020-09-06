// serverDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__189A0114_EE25_45E3_BE17_4A4F753E4652__INCLUDED_)
#define AFX_SERVERDLG_H__189A0114_EE25_45E3_BE17_4A4F753E4652__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	int		m_port;
	CString	m_send;
	CString	m_recv;
	CString	m_error;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CSocket m_socket;
	CSocket m_csocket;
	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onconnect();
	afx_msg void Onend();
	afx_msg void Onprel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__189A0114_EE25_45E3_BE17_4A4F753E4652__INCLUDED_)
