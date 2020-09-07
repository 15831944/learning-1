// timersDlg.h : header file
//

#if !defined(AFX_TIMERSDLG_H__3FACB327_47F6_43EF_9607_FDF36F73F510__INCLUDED_)
#define AFX_TIMERSDLG_H__3FACB327_47F6_43EF_9607_FDF36F73F510__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimersDlg dialog

class CTimersDlg : public CDialog
{
// Construction
public:
	CTimersDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimersDlg)
	enum { IDD = IDD_TIMERS_DIALOG };
	CButton	m_cStartTime;
	CButton	m_cStopTime;
	CString	m_sTime;
	CString	m_sCount;
	int		m_iInterval;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimersDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeInterval();
	afx_msg void OnStarttime();
	afx_msg void OnStoptime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSDLG_H__3FACB327_47F6_43EF_9607_FDF36F73F510__INCLUDED_)
