
// ListExDlg.h : header file
//

#pragma once


// CListExDlg dialog
class CListExDlg : public CDialogEx
{
// Construction
public:
	CListExDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnClickedRadioIcon();
	afx_msg void OnClickedRadioList();
	afx_msg void OnClickedRadioSmall();
	afx_msg void OnClickedRadioReport();
	void SetListView(DWORD dwView);
	CImageList m_imageLarge;
	CImageList m_imageSmall;
};
