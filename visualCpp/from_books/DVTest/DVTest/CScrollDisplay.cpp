#include "pch.h"
#include "CScrollDisplay.h"
#include "DVTestDoc.h"

IMPLEMENT_DYNCREATE(CScrollDisplay, CScrollView)

void CScrollDisplay::OnDraw(CDC* pDC)
{
	CDVTestDoc* pDoc = (CDVTestDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	//calculeaza spatiul necesar pentru o singurara linie de text, inclusiv zona dintre linii
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nLineHeight = tm.tmHeight + tm.tmExternalLeading;
	CPoint ptText(0, 0);
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szName = pDoc->GetName(nIndex);
		pDC->TextOutW(ptText.x, ptText.y, szName);
		ptText.y += nLineHeight;
	}
}

void CScrollDisplay::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	InvalidateRect(NULL);
}


void CScrollDisplay::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	InvalidateRect(NULL);
}
