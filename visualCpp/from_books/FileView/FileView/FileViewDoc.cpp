
// FileViewDoc.cpp : implementation of the CFileViewDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileView.h"
#endif

#include "FileViewDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFileViewDoc

IMPLEMENT_DYNCREATE(CFileViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileViewDoc, CDocument)
END_MESSAGE_MAP()


// CFileViewDoc construction/destruction

CFileViewDoc::CFileViewDoc() noexcept
{
	lines = NULL;
	try {
		lines = new CPtrArray();
	}
	catch (CMemoryException *e) {
		AfxMessageBox(_T("Can't allocate memory for readind file contents"));
		TRACE0("Unable to allocate memory for file contents\n");
		e->Delete();
	}
	TRACE0("Allocated lines array\n");
	maxLineLength = 0;
}

CFileViewDoc::~CFileViewDoc()
{
	int i = 0;
	if (lines != NULL) {
		while (i < lines->GetSize())
			delete (CString *)lines->GetAt(i++);
		lines->RemoveAll();
		delete lines;
		lines = NULL;
	}
	TRACE0("Deleted lines array\n");
}

BOOL CFileViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CFileViewDoc serialization

void CFileViewDoc::Serialize(CArchive& ar)
{
	BYTE buf;
	CString s;
	if (ar.IsStoring())
	{
		//TODO: add storing code here
	}
	else
	{
		while (1) {
			try {
				ar >> buf;
			}
			catch (CArchiveException *e) {
				if (e->m_cause != CArchiveException::endOfFile) {
					TRACE0("Unknown exception loading file!\n");
					throw;
				}
				else {
					TRACE0("End of file reached ... \n");
					e->Delete();
				}
				break;
			}
			s += buf;
			if (buf == '\n') {
				try {
					lines->Add(new CString(s));
				}
				catch (CMemoryException *e) {
					AfxMessageBox(_T("Not enough memory to load entire file"));
					TRACE1("Not enough memory to load file;_only %d lines loaded\n", lines->GetSize());
					e->Delete();
					break;
				}
				if (maxLineLength < s.GetLength())
					maxLineLength = s.GetLength();
				s.Empty();
			}
		}
#ifdef _DEBUG
		afxDump.SetDepth(1);
		afxDump << lines;
#endif
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFileViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CFileViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFileViewDoc::SetSearchContent(const CString& value)
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

// CFileViewDoc diagnostics

#ifdef _DEBUG
void CFileViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFileViewDoc commands
