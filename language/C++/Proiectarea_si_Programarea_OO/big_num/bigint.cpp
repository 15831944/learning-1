// bigint.cpp: implementation of the Cbigint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bigint.h"

ostream &operator<<(ostream &out,Cbigint &val)
{
	int tmp;
	bool flg;
	val.reset();
	tmp=val.get(flg);
	while(flg==true)
	{
		out<<tmp;
		tmp=val.get(flg);
	}
	return out;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cbigint::Cbigint()
{
	m_beg=NULL;
	m_end=NULL;
	m_parc=NULL;
	m_first=true;
	m_nr=0;
}
Cbigint::Cbigint(Cbigint &val)
{
	char tmp;
	bool flg;
	m_beg=NULL;
	m_end=NULL;
	m_first=true;
	m_nr=0;
	val.reset();
	tmp=val.get(flg);
	while(flg==true)
	{
		put(tmp);
		tmp=val.get(flg);
	}
}

Cbigint::~Cbigint()
{
	m_parc=m_beg;
	Cnod *tmp;
	while(m_parc!=NULL)
	{
		tmp=m_parc;
		m_parc=m_parc->next;
		delete tmp;
	}
}

void Cbigint::erase()
{
	m_parc=m_beg;
	Cnod *tmp;
	while(m_parc!=NULL)
	{
		tmp=m_parc;
		m_parc=m_parc->next;
		delete tmp;
	}
	m_beg=NULL;
	m_end=NULL;
	m_parc=NULL;
	m_first=true;
	m_nr=0;

}

void Cbigint::put(char val)
{
	if(m_beg==NULL)
	{
		m_beg=new Cnod(val);
		m_end=m_beg;
		m_parc=m_beg;
	}
	else
	{
		Cnod *tmp=new Cnod(val);
		m_end->next=tmp;
		tmp->prev=m_end;
		m_end=tmp;
	}
	m_nr++;
}

void Cbigint::putr(char val)
{
	if(m_beg==NULL)
	{
		m_beg=new Cnod(val);
		m_end=m_beg;
		m_parc=m_beg;
	}
	else
	{
		Cnod *tmp=new Cnod(val);
		m_beg->prev=tmp;
		tmp->next=m_beg;
		m_beg=tmp;
	}
	m_nr++;
}

char Cbigint::get(bool &flg)
{
	if(m_first==true)
	{
		m_parc=m_beg;
		m_first=false;
	}
	if(m_parc==NULL)
	{
		flg=false;
		return 0;
	}
	char tmp;
	tmp=m_parc->m_val;
	m_parc=m_parc->next;
	flg=true;
	return tmp;
}

void Cbigint::operator+(Cbigint &val)
{
	Cnod *tmp;
	tmp=val.m_end;
	m_parc=m_end;
	bool flg=true;
	char carry=0,carry1;
	while(flg==true)
	{
		if(m_parc!=NULL && tmp!=NULL)
		{
			carry1=*(m_parc)+*tmp;
			carry=carry1+(*(m_parc)+carry);
			m_parc=m_parc->prev;
			tmp=tmp->prev;
		} else if(m_parc==NULL && tmp!=NULL)
		{
			putr(tmp->m_val+carry);
			tmp=tmp->prev;
		}
		else
			if(m_parc!=NULL && tmp==NULL)
			{
				carry=*(m_parc)+carry;
				if(carry>0) m_parc=m_parc->prev;
				else flg=false;
			}
		else
			if(m_parc==NULL && tmp==NULL) 
			{
				if(carry>0) putr(carry);
				flg=false;
			}
	}
}

void Cbigint::reset()
{
	m_first=true;
}

void Cbigint::operator-(Cbigint &val)
{
	Cnod *tmp;
	tmp=val.m_end;
	m_parc=m_end;
	bool flg=true;
	char carry=0,carry1;
	if((m_nr==val.m_nr && m_end->m_val>=val.m_end->m_val) || m_nr>val.m_nr)
	{
		while(flg==true)
		{
			if(m_parc!=NULL && tmp!=NULL)
			{
				carry1=*(m_parc)-*tmp;
				carry=carry1+(*(m_parc)-carry);
				tmp=tmp->prev;
				if(m_parc->m_val==0 && m_parc->prev==NULL)
				{
					Cnod *tmp1=m_parc;
					m_beg=m_parc->next;
					m_beg->prev=NULL;
					m_parc=m_beg;
					m_nr--;
					delete tmp1;
				}
				m_parc=m_parc->prev;
			}
			else if(m_parc==NULL && tmp!=NULL)
			{
				putr(-tmp->m_val-carry);
				tmp=tmp->prev;
			}
			else if(m_parc!=NULL && tmp==NULL)
			{
				carry=*(m_parc)-carry;
				if(m_parc->m_val==0 && m_parc->prev==NULL)
				{
					Cnod *tmp1=m_parc;
					m_beg=m_parc->next;
					m_beg->prev=NULL;
					m_parc=m_beg;
					m_nr--;
					delete tmp1;
				}
				if(carry>0) m_parc=m_parc->prev;
				else flg=false;
			}
			else if(m_parc==NULL && tmp==NULL) 
			{
				if(carry!=0) putr(-carry);
				flg=false;
			}
		}
		reorganize();
	}
	else
	{
		Cbigint *temp=new Cbigint(val);
		char tmp;
		bool flg;
		*temp-*(this);
		erase();
		temp->reset();
		tmp=temp->get(flg);
		while(flg==true)
		{
			put(tmp);
			tmp=temp->get(flg);
		}
		m_beg->m_val=-m_beg->m_val;
		delete temp;
	}
}

void Cbigint::reorganize()
{
	m_parc=m_beg;
	while(m_parc->m_val==0 && m_parc->prev==NULL)
	{
		if(m_parc->next!=NULL)
		{
			Cnod *tmp1=m_parc;
			m_beg=m_parc->next;
			m_beg->prev=NULL;
			m_parc=m_beg;
			m_nr--;
			delete tmp1;
		}
		else return;
	}
}
