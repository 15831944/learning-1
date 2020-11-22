#include "pch.h"
#include "CScrollSplit.h"

IMPLEMENT_DYNCREATE(CScrollSplit, CMDIChildWnd)

BOOL CScrollSplit::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CSize size(10, 10);

	return m_wndSplit.Create(this, 2, 2, size, pContext);
}
