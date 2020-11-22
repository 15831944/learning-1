#pragma once
class CScrollSplit :
    public CMDIChildWnd
{
public:
    DECLARE_DYNCREATE(CScrollSplit)
private:
    CSplitterWnd m_wndSplit;
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};

