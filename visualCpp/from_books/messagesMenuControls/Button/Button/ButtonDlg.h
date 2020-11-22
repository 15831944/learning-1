
// ButtonDlg.h : header file
//

#pragma once


// CButtonDlg dialog
class CButtonDlg : public CDialogEx
{
// Construction
public:
	CButtonDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUTTON_DIALOG };
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
	CButton m_btnTest;
	CButton m_btnAmp;
	CButton m_btnVolume;
	CButton m_btnHigh;
	CButton m_btnLow;
	afx_msg void OnBtnTest();
	CButton m_btnEnableRecording;
};
