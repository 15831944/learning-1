#include "pch.h"
#include "CDisplayView.h"
#include "DVTestDoc.h"

IMPLEMENT_DYNCREATE(CDisplayView, CView)


void CDisplayView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	InvalidateRect(NULL);
}


void CDisplayView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	InvalidateRect(NULL);
}


void CDisplayView::OnDraw(CDC* pDC)
{
	CDVTestDoc* pDoc = (CDVTestDoc*) GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//calculeaza spatiul necesar pentru o singura linie de text, inclusiv zona dintre linii
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
