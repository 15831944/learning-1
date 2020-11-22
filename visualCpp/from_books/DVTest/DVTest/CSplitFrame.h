#pragma once
#include <afxwin.h>
class CSplitFrame :
    public CMDIChildWnd
{
public:
    DECLARE_DYNCREATE(CSplitFrame)
private:
    CSplitterWnd m_wndSplit;
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};

