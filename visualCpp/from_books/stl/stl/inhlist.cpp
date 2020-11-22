#include <iostream>

using namespace std;
class BaseObject {

};
class ListNode {
public :
	ListNode(int NewKey, BaseObject& NewObject);
	void SetNext(ListNode *pNewNext);
	BaseObject * GetContents() const;
	int GetKey() const;
	ListNode* GetNext() const;
private:
	ListNode* next;
	BaseObject* value;
	int key;
};

//constructor
ListNode::ListNode(int NewKey, BaseObject& NewObject) : next(NULL), value(&NewObject), key(NewKey) {	
}

void ListNode::SetNext(ListNode* pNewNext) {
	next = pNewNext;
}

BaseObject* ListNode::GetContents() const {
	return value;
}

int ListNode::GetKey() const {
	return key;
}

ListNode* ListNode::GetNext() const {
	return next;
}

//tipul Boolean
typedef unsigned char Boolean;
const Boolean TRUE = 1;
const Boolean FALSE = 0;

class List {
public:
	List();
	~List();
	Boolean Add(int NewKey, BaseObject& NewObject);
	Boolean Remove(int SearchKey);
	BaseObject* Find(int SearchKey) const;
	BaseObject* operator[](int OrderKey);
	int GetListSize() const;
private:
	ListNode* head;
	unsigned int NumItems;
};

//constructor
List::List() : head(NULL), NumItems(0) {

}

//destructor
List::~List() {
	//sterge toate elemente
	while (head) {
		ListNode* pTemp = head->GetNext();
		delete head;
		head = pTemp;
	}
}

Boolean List::Add(int NewKey, BaseObject& NewObject) {
	//aloca memorie pentru noul nod
	ListNode* pNewNode = new ListNode(NewKey, NewObject);
	if (!pNewNode)
		return FALSE;
	//inserarea nodului in lista
	pNewNode->SetNext(head);
	head = pNewNode;
	NumItems++;
	return TRUE;
}

Boolean List::Remove(int SearchKey) {
	ListNode* pCursor = head;
	//exista o lista
	if (!pCursor)
		return FALSE;
	//verifica inceputul listei
	if (pCursor->GetKey() == SearchKey) {
		head = pCursor->GetNext();
		delete pCursor;
		NumItems--;
		return TRUE;
	}
	//parcurge lista
	while (pCursor->GetNext()) {
		if (pCursor->GetNext()->GetKey() == SearchKey) {
			ListNode* pTemp = pCursor->GetNext();
			pCursor->SetNext(pTemp->GetNext());
			delete pTemp;
			NumItems--;
			return TRUE;
		}
	}
	return FALSE;
}

BaseObject* List::Find(int SearchKey) const {
	ListNode* pCursor = head;
	while (pCursor) {
		if (pCursor->GetKey() == SearchKey)
			return pCursor->GetContents();
		else
			pCursor = pCursor->GetNext();
	}
	return NULL;
}

int List::GetListSize() const {
	return NumItems;
}

//operatori
BaseObject* List::operator[](int OrderKey) {
	ListNode* pCursor = head;
	int Count = 1;
	while (pCursor) {
		if (Count++ == OrderKey)
			return pCursor->GetContents();
		pCursor = pCursor->GetNext();
	}
	return NULL;
}

struct IntClass : public BaseObject {
	IntClass(int NewInt) {
		theInt = NewInt;
	}
	int theInt;
};

void ShowList(List& theList) {
	int Loop;
	cout << "The list: ( ";
	for (Loop = 0; Loop < theList.GetListSize(); Loop++) {
		if (Loop)
			cout << ", ";
		IntClass* pIntClass = (IntClass *)theList[Loop + 1];
		cout << pIntClass->theInt;
	}
	cout << " )\n";
}

int main() {
	List theList;
	IntClass Int1(34), Int2(22), Int3(675);

	theList.Add(1, Int1);
	theList.Add(2, Int2);
	theList.Add(3, Int3);
	ShowList(theList);
	theList.Remove(2);
	ShowList(theList);
	theList.Remove(1);
	ShowList(theList);
	theList.Remove(3);
	ShowList(theList);
}