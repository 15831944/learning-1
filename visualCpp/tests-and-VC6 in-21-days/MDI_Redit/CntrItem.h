// CntrItem.h : interface of the CMDI_ReditCntrItem class
//

#if !defined(AFX_CNTRITEM_H__417932F1_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
#define AFX_CNTRITEM_H__417932F1_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMDI_ReditDoc;
class CMDI_ReditView;

class CMDI_ReditCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CMDI_ReditCntrItem)

// Constructors
public:
	CMDI_ReditCntrItem(REOBJECT* preo = NULL, CMDI_ReditDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CMDI_ReditDoc* GetDocument()
		{ return (CMDI_ReditDoc*)CRichEditCntrItem::GetDocument(); }
	CMDI_ReditView* GetActiveView()
		{ return (CMDI_ReditView*)CRichEditCntrItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDI_ReditCntrItem)
	public:
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	~CMDI_ReditCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__417932F1_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
