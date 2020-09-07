//Include for windows header
#include<afx.h>
#include<iostream>
using std::cout;
using std::endl;
class CObjectMenu : public CObject
{
	DECLARE_DYNCREATE(CObjectMenu);
public:
	CObjectMenu();
public:
	void Set(const CString& szNume);
	CString Get() const;
private:
	CString m_szNume;
};

IMPLEMENT_DYNCREATE(CObjectMenu,CObject);
CObjectMenu::CObjectMenu()
{
}

void CObjectMenu::Set(const CString& szNume)
{
	m_szNume=szNume;
}

CString CObjectMenu::Get(void) const
{
	return m_szNume;
}

int main()
{
	CRuntimeClass* pRuntime=RUNTIME_CLASS(CObjectMenu);
	CObject* pObj=pRuntime->CreateObject();
	ASSERT(pObj->IsKindOf(RUNTIME_CLASS(CObjectMenu)));
	CObjectMenu* pFoo=(CObjectMenu*)pObj;
	pFoo->Set("FooBar");
	cout<<pFoo->Get()<<endl;
	delete pFoo;
	return 0;
}