#pragma once
#include <afx.h>
template <class T> class CStack {
public:
	CStack();
	virtual ~CStack();
	BOOL IsEmpty() const;
	T Pop();
	void Push(const T& item);
private:
	CStack<T>(const CStack& T) {};
	T* m_p;
	int m_nStored;
	int m_nDepth;
	enum { GROW_BY = 5 };
};

template <class T> CStack<T>::CStack() {
	m_p = 0;
	m_nStored = 0;
	m_nDepth = 0;
}

template <class T>CStack<T>::~CStack() {
	delete[] m_p;
}

//operations
template <class T> BOOL CStack<T>::IsEmpty() const {
	return m_nStored == 0;
}

template <class T> void CStack<T>::Push(const T& item) {
	if (m_nStored == m_nDepth) {
		T* p = new T[m_nDepth + GROW_BY];
		for (int i = 0; i < m_nDepth; i++) {
			p[i] = m_p[i];
		}
		m_nDepth += GROW_BY;
		delete[] m_p;
		m_p = p;
	}
	m_p[m_nStored] = item;
	m_nStored++;
}

template <class T> T CStack<T>::Pop() {
	ASSERT(m_nStored);
	m_nStored--;
	return m_p[m_nStored];
}
