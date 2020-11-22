
// CustomersDoc.h : interface of the CCustomersDoc class
//


#pragma once
#include "CUser.h"
class CCustomersDoc : public CDocument
{
protected: // create from serialization only
	CCustomersDoc() noexcept;
	DECLARE_DYNCREATE(CCustomersDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCustomersDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	int GetCount() const;
	CUser* GetUser(int nUser) const;
protected:
	CArray<CUser*, CUser*&> m_setOfUsers;
public:
	afx_msg void OnEditUser();
};
