#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H
#include "linkList.h"


namespace dataStruct
{

template <typename T>
class CircleLinkList : public LinkList<T>
{
typedef typename LinkList<T>::Node Node;
protected:

	void last_to_first()
	{
		last()->next = this->m_header.next;
	}
public:
	Node* last() const
	{
		return this->at(this->length()-1);
	}
	int mod(int i) const
	{
		return (this->m_length == 0) ? 0 : i%(this->m_length + 1);
	}
	bool insert(const T& obj)
	{
		return insert(this->length(), obj);
	}
	bool insert(int i, const T& obj)
	{
		bool ret = true;
		i = mod(i);
		ret = LinkList<T>::insert(i, obj);
		if(ret && (i==0))
		{
			last_to_first();
		}
		return ret;
	}

	bool remove(int i)
	{
		bool ret = true;
		i = mod(i);
		if(i == 0)
		{
			Node* toDel = this->m_header.next;
			if(toDel != nullptr)
			{
				this->m_header.next = toDel->next;
				this->m_length--;
				if(this->m_length > 0)
				{
					last_to_first();
					if(this->m_iter == toDel)
					{
						this->m_iter = toDel->next;
					}
				}
				else
				{
					this->m_header.next = nullptr;
					this->m_iter = nullptr;
				}
				this->destory(toDel);
			}
			else
			{
				ret = false;
			}
		}
		else
		{
			ret = LinkList<T>::remove(i);
		}
		return ret;
	}
	bool set(int i, const T& obj)
	{
		i = mod(i);
		return LinkList<T>::set(i, obj);
	}
	bool get(int i, const T& obj) const
	{
		i = mod(i);
		return LinkList<T>::get(i, obj);
	}

	int find(const T& obj) const
	{
		int ret = -1;
		Node* slider = this->m_header.next;
		for(int i=0; i<this->m_length; i++)
		{
			if(slider->value == obj)
			{
				ret = i;
				break;
			}
			slider = slider->next;
		}
		return ret;
	}

	void clear()
	{
		while(this->m_length > 1)
		{
			remove(1);
		}
		if(this->m_length == 1)
		{
			Node* toDel = this->m_header.next;
			this->m_header.next = nullptr;
			this->m_length = 0;
			this->m_iter = nullptr;
			this->destory(toDel);
		}
	}

	virtual bool move(int i, int step)
	{
		return LinkList<T>::move(mod(i), step);
	}
	virtual bool isEnd()
	{
		return (this->m_length == 0) || (this->m_iter == nullptr);
	}
	~CircleLinkList()
	{
		clear();
	}
};



}
#endif // !CIRCLELINKLIST_H
