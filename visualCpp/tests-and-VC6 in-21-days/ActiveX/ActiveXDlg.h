// ActiveXDlg.h : header file
//
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_ACTIVEXDLG_H__8F3510A7_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_)
#define AFX_ACTIVEXDLG_H__8F3510A7_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CActiveXDlg dialog

class CActiveXDlg : public CDialog
{
// Construction
public:
	void DoSort();
	CString RandomStringValue(int m_iColumn);
	int GenID(int m_iRow,int m_iCol);
	void LoadData();
	CActiveXDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CActiveXDlg)
	enum { IDD = IDD_ACTIVEX_DIALOG };
	CMSFlexGrid	m_ctlFGrid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveXDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CActiveXDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnMouseDownMsfgrid(short Button, short Shift, long x, long y);
	afx_msg void OnMouseUpMsfgrid(short Button, short Shift, long x, long y);
	afx_msg void OnDblClickMsfgrid();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iMouseCol;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVEXDLG_H__8F3510A7_36BD_11DB_B910_FABBBA0E7F0D__INCLUDED_)
