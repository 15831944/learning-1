
// DVTestDoc.cpp : implementation of the CDVTestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DVTest.h"
#endif

#include "DVTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDVTestDoc

IMPLEMENT_DYNCREATE(CDVTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDVTestDoc, CDocument)
END_MESSAGE_MAP()


// CDVTestDoc construction/destruction

CDVTestDoc::CDVTestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDVTestDoc::~CDVTestDoc()
{
}

BOOL CDVTestDoc::OnNewDocument()
{
	TRACE(_T("CDVTest::OnNewDocument"));
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_arNames.RemoveAll();
	m_arNames.Add(_T("Curly"));
	m_arNames.Add(_T("Moe"));
	m_arNames.Add(_T("Shemp"));
	return TRUE;
}




// CDVTestDoc serialization

void CDVTestDoc::Serialize(CArchive& ar)
{
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
void CDVTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CDVTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDVTestDoc::SetSearchContent(const CString& value)
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

// CDVTestDoc diagnostics

#ifdef _DEBUG
void CDVTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDVTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDVTestDoc commands

CString CDVTestDoc::GetName(int nIndex) const {
	ASSERT(nIndex < m_arNames.GetSize());
	return m_arNames[nIndex];
}
int CDVTestDoc::AddName(const CString& szName) {
	TRACE("CDVTestDoc::AddName, string = %s\n", szName);
	int nPozitie = m_arNames.Add(szName);
	UpdateAllViews(NULL);
	return nPozitie;
}
int CDVTestDoc::GetCount() const {
	return m_arNames.GetSize();
}