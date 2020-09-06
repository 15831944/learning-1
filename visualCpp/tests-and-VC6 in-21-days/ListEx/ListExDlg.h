// ListExDlg.h : header file
//

#if !defined(AFX_LISTEXDLG_H__34D0DDC5_AE03_11DB_B910_C96B64896645__INCLUDED_)
#define AFX_LISTEXDLG_H__34D0DDC5_AE03_11DB_B910_C96B64896645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListExDlg dialog

class CListExDlg : public CDialog
{
// Construction
public:
	CListExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListExDlg)
	enum { IDD = IDD_LISTEX_DIALOG };
	CListCtrl	m_listctrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListExDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void SetListView(DWORD dbView);
	CImageList m_imageLarge;
	CImageList m_imageSmall;
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CListExDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioIcon();
	afx_msg void OnRadioReport();
	afx_msg void OnRadioList();
	afx_msg void OnRadioSmall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEXDLG_H__34D0DDC5_AE03_11DB_B910_C96B64896645__INCLUDED_)
