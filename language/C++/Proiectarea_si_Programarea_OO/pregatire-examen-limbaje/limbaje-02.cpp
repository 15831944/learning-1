/*
	Sa se realizeze o coada de numere intregi. Apoi sa se realizeze alta lista 
	de numere intregi derivind clasa coada astfel incit sa mai avem operatii
	de aranjare crescatoare sau descrescatoare a listei impreuna cu listarea 
	continutului listei. Se va implementa dinamic in C++ cu clase.
*/
#include<iostream.h>
struct dFIFO
{
	int val;
	struct dFIFO *next;
};
class FIFO
{
public:
	void push(int val1);
	int pop();
	FIFO();
protected:
	struct dFIFO *baza,*virf;
	int val;
private:
	struct dFIFO *temp;
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
	if(baza==NULL) baza=virf=temp;
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

class coada : public FIFO
{
public:
	void listare();
	void crescatoare();
	void descrescatoare();
private:
	struct dFIFO *temp,*temp1,*work,*temp2,*tempm,*tempma;
};
void coada::listare()
{
	temp=baza;
	while(temp!=NULL)
	{
		cout<<temp->val<<endl;cout.flush();
		temp=temp->next;
	}
}
void coada::crescatoare()
{
	int max;
	bool t=true;
	work=baza;
	max=baza->val;
	temp1=work;
	temp=NULL;
	while(work->next!=NULL)
	{
		tempm=NULL;
		tempma=NULL;
		max=temp1->val;
		while(temp1!=NULL)
		{
			if(temp1->val>=max)
			{
				tempm=temp1;
				tempma=temp;
				max=temp1->val;
			}
			temp=temp1;
			temp1=temp1->next;
		}
		if(tempm==NULL)
		{
			tempm=work->next;
			tempma=work;
		}
		if(tempma!=NULL)
		{
			tempma->next=tempm->next;
			tempm->next=baza;
		}
		baza=tempm;
		if(t==true)
		{
			work=tempm;
			t=false;
		}
		temp=work;
		temp1=temp->next;
	}
	virf=work;
}
void coada::descrescatoare()
{
	int min;
	bool t=true;
	work=baza;
	min=baza->val;
	temp1=work;
	temp=NULL;
	while(work->next!=NULL)
	{
		tempm=NULL;
		tempma=NULL;
		min=temp1->val;
		while(temp1!=NULL)
		{
			if(temp1->val<=min)
			{
				tempm=temp1;
				tempma=temp;
				min=temp1->val;
			}
			temp=temp1;
			temp1=temp1->next;
		}
		if(tempm==NULL)
		{
			tempm=work->next;
			tempma=work;
		}
		if(tempma!=NULL)
		{
			tempma->next=tempm->next;
			tempm->next=baza;
		}
		baza=tempm;
		if(t==true)
		{
			work=tempm;
			t=false;
		}
		temp=work;
		temp1=temp->next;
	}
	virf=work;
}

void main()
{
	coada q;
	int val;
	cin>>val;
	while(val>=0)
	{
		q.push(val);
		cin>>val;
	}
	cout<<"Listare"<<endl;
	q.listare();
	cout<<"Listare crescatoare"<<endl;
	q.crescatoare();
	q.listare();
	cout<<"Listare descrescatoare"<<endl;
	q.descrescatoare();
	while((val=q.pop())!=-1) cout<<val<<endl;
}