#include "pch.h"
#include "CSplitFrame.h"
#include "CFormTest.h"

IMPLEMENT_DYNCREATE(CSplitFrame, CMDIChildWnd)

BOOL CSplitFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	if (m_wndSplit.CreateStatic(this, 2, 1) == FALSE) {
		TRACE0("Crearea CreateStaticSplitter esuata\n");
		return FALSE;
	}
	BOOL bCreated = m_wndSplit.CreateView(0, 0, pContext->m_pNewViewClass, CSize(100, 115), pContext);
	if (bCreated == FALSE) {
		TRACE0("Erroare de creare a primului panou\n");
		return FALSE;
	}
	//adauga al doilea panou
	bCreated = m_wndSplit.CreateView(1, 0, RUNTIME_CLASS(CFormTest), CSize(0, 0), pContext);
	if (bCreated == FALSE) {
		TRACE0("Eroare de creare a panoului secund\n");
		return FALSE;
	}
	//activarea vizualizarea de intrare
	SetActiveView((CView*)m_wndSplit.GetPane(0, 0));
	return TRUE;
}
