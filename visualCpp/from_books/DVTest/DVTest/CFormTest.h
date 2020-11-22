#pragma once



// CFormTest form view
//change to CDialogEx to add variabile din class wizard
class CFormTest : public CFormView
{
	DECLARE_DYNCREATE(CFormTest)

protected:
	CFormTest();           // protected constructor used by dynamic creation
	virtual ~CFormTest();

public:
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_VIEW};
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEdit m_edNames;
	CListBox m_lbNames;
	afx_msg void OnApply();
	afx_msg void OnClose();
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


