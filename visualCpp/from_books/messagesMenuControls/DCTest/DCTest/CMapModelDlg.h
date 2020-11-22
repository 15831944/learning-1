#pragma once


// CMapModelDlg dialog

class CMapModelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMapModelDlg)

public:
	CMapModelDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMapModelDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAP_MODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_szCombo;
	int m_cxEllipse;
	int m_cyEllipse;
	int m_nPenWidth;
	COLORREF m_clrOptiune;
	CBrush m_brControl;
	afx_msg void OnClickedColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
