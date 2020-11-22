
// CustomersDoc.cpp : implementation of the CCustomersDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Customers.h"
#endif

#include "CustomersDoc.h"
#include "CUsersDlg.h"
#include "Users.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCustomersDoc

IMPLEMENT_DYNCREATE(CCustomersDoc, CDocument)

BEGIN_MESSAGE_MAP(CCustomersDoc, CDocument)
	ON_COMMAND(ID_EDIT_USER, &CCustomersDoc::OnEditUser)
END_MESSAGE_MAP()


// CCustomersDoc construction/destruction

CCustomersDoc::CCustomersDoc() noexcept
{
	// TODO: add one-time construction code here

}

CCustomersDoc::~CCustomersDoc()
{
}

BOOL CCustomersDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CCustomersDoc serialization

void CCustomersDoc::Serialize(CArchive& ar)
{
	m_setOfUsers.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CCustomersDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CCustomersDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CCustomersDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCustomersDoc diagnostics

#ifdef _DEBUG
void CCustomersDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCustomersDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCustomersDoc commands


void CCustomersDoc::OnEditUser()
{
	CUsersDlg dlg;
	if (dlg.DoModal() == IDOK) {
		CUser* pUser = new CUser(dlg.m_szName, dlg.m_szAddr);
		m_setOfUsers.Add(pUser);
		UpdateAllViews(NULL);
		SetModifiedFlag();
	}
}

int CCustomersDoc::GetCount() const {
	return m_setOfUsers.GetSize();
}

CUser* CCustomersDoc::GetUser(int nUser) const {
	CUser* pUser = 0;
	if (nUser < m_setOfUsers.GetSize())
		pUser = m_setOfUsers.GetAt(nUser);
	return pUser;
}