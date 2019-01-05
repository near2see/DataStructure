#ifndef DUALCIRCLELIST_H
#define DUALCIRCLELIST_H
#include "dualLinkList.h"
namespace dataStruct
{

template <typename T>
class DualCircleList : public DualLinkList<T>
{
typedef typename DualLinkList<T>::Node Node;
protected:
	int mod(int i) const
	{
		return ((this->m_length == 0) ? 0 : i%(this->m_length + 1));
	}
	Node* last()
	{
		return this->at(this->length()-1);
	}
	void last_to_first()
	{
		last()->next = this->m_header.next;
		this->m_header.next->pre = last();
	}
public:
	DualCircleList() : DualLinkList<T>()
	{
	}

	Node* at(int i) const
	{		
		i = mod(i);
		return DualLinkList<T>::at(i);
	}

	bool insert(int i, const T& obj)
	{
		bool ret = true;
		i = mod(i);
		ret = DualLinkList<T>::insert(i, obj);
		if(ret && (i==0))
		{
			last_to_first();
		}
		return ret;
	}
	
	bool insert(const T& obj)
	{
		return insert(this->m_length, obj);
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
			ret = DualLinkList<T>::remove(i);
		}
		return ret;
	}
	bool set(int i, const T& obj)
	{
		i = mod(i);
		return DualLinkList<T>::set(i, obj);
	}
	virtual bool get(int i, T& obj) const
	{
		i = mod(i);
		return DualLinkList<T>::get(i, obj);
	}

	T get(int i) const
	{
		T ret;
		if(get(i, ret))
		{
			return ret;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
		}
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
			remove(0);
		}
	}

	bool move(int i, int step = 1)
	{
		i = mod(i);
		return DualLinkList<T>::move(i, step);
	}
	bool isEnd()
	{
		return (this->m_length == 0) || (this->m_iter = nullptr);
	}
	~DualCircleList()
	{
		clear();
	}

};


}
#endif // !DUALCIRCLELIST_H
