#pragma once
#include <afxwin.h>
class CDisplayView :
    public CView
{
public:
    DECLARE_DYNCREATE(CDisplayView)
    virtual void OnInitialUpdate();
    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
    virtual void OnDraw(CDC* /*pDC*/);
};

