// treeView.cpp : implementation of the CMyTreeView class
//

#include "stdafx.h"
#include "tree.h"

#include "treeDoc.h"
#include "treeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	//{{AFX_MSG_MAP(CMyTreeView)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView construction/destruction

CMyTreeView::CMyTreeView()
{
	// TODO: add construction code here

}

CMyTreeView::~CMyTreeView()
{
}

BOOL CMyTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style|=(TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS);
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView drawing

void CMyTreeView::OnDraw(CDC* pDC)
{
	CTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CMyTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& tree=GetTreeCtrl();	
	m_tree=&tree;
	m_imagelist.Create(IDB_TREE,46,1,RGB(255,0,0));
	tree.SetImageList(&m_imagelist,TVSIL_NORMAL);
	HTREEITEM hCapitol=tree.InsertItem("Capitolul 1");
	tree.InsertItem("Ce",hCapitol);
	tree.InsertItem("De ce",hCapitol);
	tree.InsertItem("Cum",hCapitol);
	hCapitol=tree.InsertItem("Capitolul 2");
	tree.InsertItem("Ce",hCapitol);
	tree.InsertItem("De ce",hCapitol);
	tree.InsertItem("Cum",hCapitol);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView printing

BOOL CMyTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView diagnostics

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeDoc* CMyTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeDoc)));
	return (CTreeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView message handlers

void CMyTreeView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_dragItem=pNMTreeView->itemNew.hItem;
//	CTreeCtrl& tree=GetTreeCtrl();	
//	m_tree=&tree;
	if(m_tree->GetParentItem(m_dragItem)!=NULL)
	{
		CImageList* pDragImage;
		pDragImage=m_tree->CreateDragImage(m_dragItem);
		m_tree->SelectItem(m_dragItem);
		pDragImage->BeginDrag(0,CPoint(0,0));
		pDragImage->DragEnter(m_tree,pNMTreeView->ptDrag);
		SetCapture();
		m_bIsDragging=TRUE;
	}
	*pResult = 0;
}

void CMyTreeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(m_bIsDragging==TRUE)
	{
		CPoint ptTree(point);
		MapWindowPoints(m_tree,&ptTree,1);
		CImageList::DragMove(ptTree);
		UINT uHitTest=TVHT_ONITEM;
		m_dragTarget=m_tree->HitTest(ptTree,&uHitTest);
	}
	CTreeView::OnMouseMove(nFlags, point);
}

void CMyTreeView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(m_bIsDragging==TRUE)
	{
		CImageList::DragLeave(m_tree);
		CImageList::EndDrag();
		ReleaseCapture();
		m_bIsDragging=FALSE;
		if(m_dragTarget!=NULL)
		{
			HTREEITEM hParent;
			hParent=m_tree->GetParentItem(m_dragTarget);
			CString szLabel=m_tree->GetItemText(m_dragItem);
			if(hParent!=NULL)
				m_tree->InsertItem(szLabel,hParent,m_dragTarget);
			else
				m_tree->InsertItem(szLabel,m_dragTarget,TVI_FIRST);
			m_tree->DeleteItem(m_dragItem);
		}
	}
	else
		CTreeView::OnLButtonUp(nFlags, point);
}
