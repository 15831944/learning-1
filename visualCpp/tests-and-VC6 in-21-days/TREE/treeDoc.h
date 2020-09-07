// treeDoc.h : interface of the CTreeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEDOC_H__EC627F6B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
#define AFX_TREEDOC_H__EC627F6B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTreeDoc : public CDocument
{
protected: // create from serialization only
	CTreeDoc();
	DECLARE_DYNCREATE(CTreeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEDOC_H__EC627F6B_AA08_11DB_B910_EA91DC6E6D44__INCLUDED_)
