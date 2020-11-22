#pragma once
#include <afxwin.h>
class CScrollDisplay :
    public CScrollView
{
public:
    DECLARE_DYNCREATE(CScrollDisplay)
    virtual void OnDraw(CDC* /*pDC*/);
    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
    virtual void OnInitialUpdate();
};

