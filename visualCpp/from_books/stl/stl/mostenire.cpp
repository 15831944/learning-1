#include <iostream>

//template de baza
template <class T2>
class BaseTemplate {
public :
	BaseTemplate(int val) {
		m_val = val;
	}
	void  DoIt() {
		std::cout << "In BaseTemplate val=" << m_val << " and "<<*m_data<<std::endl;
	}
	void SetData(T2& data) {
		m_data = &data;
	}
private:
	int m_val;
	T2* m_data;
};

//clasa derivate template
template<class T1, class T2>
class DerivedTemplate : public BaseTemplate<T2> {
public:
	DerivedTemplate(int val1, int val2) : BaseTemplate<T2>(val2){
		m_val = val1;
	}
	void DoIt() {
		std::cout << "In DerivedTemplate val=" << m_val << " and " << *m_data << std::endl;
		BaseTemplate<T2>::DoIt();
	}
	void SetData(T1& data1, T2& data2) {
		m_data = &data1;
		BaseTemplate<T2>::SetData(data2);
	}
private:
	int m_val;
	T1* m_data;
};

int main() {
	DerivedTemplate<int, const char *> MyData(12, 34);
	int data1 = 24;
	const char * data2 = "bla bla";
	MyData.SetData(data1, data2);
	MyData.DoIt();

}