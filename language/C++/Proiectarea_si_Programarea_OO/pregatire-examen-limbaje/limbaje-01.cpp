/* 
	Sa se realizeze o stiva si o coada pentru numere intregi pozitive care vor fi citite de la
	tastatura si vor fi poi afisate. Se va realiza in C++ cu clase implementata dinamic.
*/
#include<iostream.h>
struct dLIFO
{
	int val;
	struct dLIFO *prec;
};
struct dFIFO
{
	int val;
	struct dFIFO *next;
};

class LIFO
{
public:
	void push(int val1);
	int pop(void);
	LIFO();
private:
	struct dLIFO *virf,*temp;
};
LIFO::LIFO()
{
	virf=NULL;
}
void LIFO::push(int val1)
{
	temp=new struct dLIFO;
	temp->val=val1;
	if(virf==NULL) temp->prec=NULL;
	else temp->prec=virf;
	virf=temp;
}
int LIFO::pop()
{
	if(virf==NULL) return -1;
	temp=virf;
	virf=virf->prec;
	int val=temp->val;
	delete temp;
	return val;
}

class FIFO
{
public:
	void push(int val1);
	int pop(void);
	FIFO();
private:
	struct dFIFO *baza,*virf,*temp;
	int val;
};
FIFO::FIFO()
{
	baza=virf=NULL;
}
void FIFO::push(int val1)
{
	temp=new struct dFIFO;
	temp->val=val1;
	temp->next=NULL;
	if(baza==NULL)	virf=baza=temp;
	else
	{
		virf->next=temp;
		virf=temp;
	}
}
int FIFO::pop()
{
	if(baza==NULL) return -1;
	temp=baza;
	baza=baza->next;
	if(baza==NULL) virf=NULL;
	val=temp->val;
	delete temp;
	return val;
}

void main()
{
	int val;
	FIFO fifo;
	LIFO lifo;
	cin>>val;
	while(val>=0)
	{
		fifo.push(val);
		lifo.push(val);
		cin>>val;
	}
	cout<<"FIFO"<<endl;
	while((val=fifo.pop())!=-1) cout<<val<<endl;
	cout<<"LIFO"<<endl;
	while((val=lifo.pop())!=-1) cout<<val<<endl;
	cout.flush();
}