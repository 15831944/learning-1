
// ImageListView.cpp : implementation of the CImageListView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ImageList.h"
#endif

#include "ImageListDoc.h"
#include "ImageListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageListView

IMPLEMENT_DYNCREATE(CImageListView, CView)

BEGIN_MESSAGE_MAP(CImageListView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CImageListView construction/destruction

CImageListView::CImageListView() noexcept
{
	m_imageList.Create(32, 32, TRUE, 4, 1);
	AddBitmapToImageList(IDB_CROSS);
	AddBitmapToImageList(IDB_CHECK);
	AddBitmapToImageList(IDB_BANG);
	AddBitmapToImageList(IDB_BALL);
}

CImageListView::~CImageListView()
{
}

BOOL CImageListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CImageListView drawing

void CImageListView::OnDraw(CDC* pDC)
{
	CImageListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap bmpHello;
	bmpHello.LoadBitmapW(IDB_HELLO);
	//calculeaza dimensiunea imaginii bitmap folosind o structura BITMAP
	BITMAP bm;
	bmpHello.GetObject(sizeof(BITMAP), &bm);
	//creaza un DC de memorie , selecteaza imaginea bitmap in Dc-ul de memorie si apeleaza BitBlt
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpHello);
	pDC->BitBlt(10, 10, bm.bmWidth, bm.bmHeight, &dcMem, 0, 0, SRCCOPY);

	CPoint ptImage(50, 0);
	for (int nImage = 0; nImage < 4; nImage++) {
		m_imageList.Draw(pDC, nImage, ptImage, ILD_NORMAL);
		ptImage.x += 50;
	}
	//suprapunerea unei imagini
	m_imageList.SetBkColor(CLR_NONE);
	CPoint ptOverlay(50, 0);
	m_imageList.SetOverlayImage(0, 1);
	m_imageList.Draw(pDC, 3, ptOverlay, ILD_OVERLAYMASK | INDEXTOOVERLAYMASK(1));
	//reselecteaza imaginea bitmap originala in DC-ul de memorie
	dcMem.SelectObject(pbmpOld);
}


// CImageListView printing

BOOL CImageListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

BOOL CImageListView::AddBitmapToImageList(UINT nResourceID) {
	BOOL bReturn;
	CBitmap bmp;
	bReturn = bmp.LoadBitmapW(nResourceID);
	if (bReturn != FALSE) {
		bReturn = m_imageList.Add(&bmp, RGB(255, 255, 255));
		bmp.DeleteObject();
	}
	return bReturn;
}

// CImageListView diagnostics

#ifdef _DEBUG
void CImageListView::AssertValid() const
{
	CView::AssertValid();
}

void CImageListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageListDoc* CImageListView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageListDoc)));
	return (CImageListDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageListView message handlers
