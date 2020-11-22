#pragma once
#include <afx.h>
class CUser :
    public CObject
{
    DECLARE_SERIAL(CUser);
public:
    //constructori
    CUser();
    CUser(const CString& szName, const CString& szAddr);
    //atribute
    void Set(const CString& szName, const CString& szAddr);
    CString GetName() const;
    CString GetAddr() const;
    //operatii
    virtual void Serialize(CArchive& ar);
    //implmentation
    CString m_szName;
    CString m_szAddr;
};

