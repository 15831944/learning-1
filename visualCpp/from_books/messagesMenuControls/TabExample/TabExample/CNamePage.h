#pragma once


// CNamePage

class CNamePage : public CPropertyPage
{
	DECLARE_DYNAMIC(CNamePage)

public:
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAME_PAGE };
#endif
	CNamePage();
	virtual ~CNamePage();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);
public:
	CString m_szAddress;
	CString m_szCity;
	CString m_szName;
	afx_msg void OnChangeEditName();
};


