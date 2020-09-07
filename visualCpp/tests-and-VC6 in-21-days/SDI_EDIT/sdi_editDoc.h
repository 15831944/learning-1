// sdi_editDoc.h : interface of the CSdi_editDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDI_EDITDOC_H__A2BEF549_A7E3_11DB_B910_C96105C64945__INCLUDED_)
#define AFX_SDI_EDITDOC_H__A2BEF549_A7E3_11DB_B910_C96105C64945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSdi_editDoc : public CDocument
{
protected: // create from serialization only
	CSdi_editDoc();
	DECLARE_DYNCREATE(CSdi_editDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdi_editDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSdi_editDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSdi_editDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDI_EDITDOC_H__A2BEF549_A7E3_11DB_B910_C96105C64945__INCLUDED_)
