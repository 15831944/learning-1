
// DVTestDoc.h : interface of the CDVTestDoc class
//


#pragma once


class CDVTestDoc : public CDocument
{
protected: // create from serialization only
	CDVTestDoc() noexcept;
	DECLARE_DYNCREATE(CDVTestDoc)

// Attributes
public:
	CString GetName(int nIndex) const;
	int AddName(const CString& szName);
	int GetCount() const;
private:
	CArray<CString, CString> m_arNames;
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
	virtual ~CDVTestDoc();
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
};
