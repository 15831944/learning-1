// MDI_ReditDoc.h : interface of the CMDI_ReditDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDI_REDITDOC_H__417932ED_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
#define AFX_MDI_REDITDOC_H__417932ED_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDI_ReditDoc : public CRichEditDoc
{
protected: // create from serialization only
	CMDI_ReditDoc();
	DECLARE_DYNCREATE(CMDI_ReditDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDI_ReditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CMDI_ReditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDI_ReditDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDI_REDITDOC_H__417932ED_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
