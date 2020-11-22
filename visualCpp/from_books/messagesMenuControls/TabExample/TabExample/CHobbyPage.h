#pragma once


// CHobbyPage

class CHobbyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CHobbyPage)

public:
	CHobbyPage();
	virtual ~CHobbyPage();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);
public:
	afx_msg void OnCheckPolo();
	afx_msg void OnCheckSquash();
	afx_msg void OnCheckCurling();
	virtual BOOL OnApply();
};


