#pragma once


// CHelloDlg dialog

class CHelloDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHelloDlg)

public:
	CHelloDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHelloDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELLO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
