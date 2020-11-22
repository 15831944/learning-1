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
public:
};


