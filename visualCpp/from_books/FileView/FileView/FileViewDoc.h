
// FileViewDoc.h : interface of the CFileViewDoc class
//


#pragma once


class CFileViewDoc : public CDocument
{
protected: // create from serialization only
	CFileViewDoc() noexcept;
	DECLARE_DYNCREATE(CFileViewDoc)
	CPtrArray *lines;
	int maxLineLength;

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
	virtual ~CFileViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CPtrArray *GetLines() { return lines; }
	int getMaxLineLength() { return maxLineLength; }

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
