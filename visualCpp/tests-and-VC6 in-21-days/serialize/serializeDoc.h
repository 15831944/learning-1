// serializeDoc.h : interface of the CSerializeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALIZEDOC_H__5B06CE8D_2879_48F3_8534_1C8060DE7FA3__INCLUDED_)
#define AFX_SERIALIZEDOC_H__5B06CE8D_2879_48F3_8534_1C8060DE7FA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerializeDoc : public CDocument
{
protected: // create from serialization only
	CSerializeDoc();
	DECLARE_DYNCREATE(CSerializeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPerson* GetLastRecord();
	CPerson* GetPrevRecord();
	CPerson* GetNextRecord();
	CPerson* GetFirstRecord();
	CPerson* GetCurRecord();
	int GetCurRecordNbr();
	int GetTotalRecords();
	virtual ~CSerializeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerializeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPerson* AddNewRecord();
	int m_iCurPosition;
	CObArray m_oaPeople;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALIZEDOC_H__5B06CE8D_2879_48F3_8534_1C8060DE7FA3__INCLUDED_)
