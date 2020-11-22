#pragma once


// CFormatDlg dialog

class CFormatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFormatDlg)

public:
	CFormatDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFormatDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBold;
	BOOL m_bItalic;
	BOOL m_bUnderline;
	afx_msg void OnColor();
	COLORREF m_clrText;
};
