#if !defined(AFX_MSGDLG_H__D1F70DCE_815E_43D6_826B_C153342336C5__INCLUDED_)
#define AFX_MSGDLG_H__D1F70DCE_815E_43D6_826B_C153342336C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog

class CMsgDlg : public CDialog
{
// Construction
public:
	CMsgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMsgDlg)
	enum { IDD = IDD_MESSAGEDLG };
	CString	m_sMessage;
	int		m_iOption;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGDLG_H__D1F70DCE_815E_43D6_826B_C153342336C5__INCLUDED_)
