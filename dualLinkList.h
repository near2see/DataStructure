#ifndef DUALLINKLIST_H
#define DUALLINKLIST_H
#include "list.h"
namespace dataStruct
{

template <typename T>
class DualLinkList : public List<T>
{
protected:
	struct Node : public Object
	{
		T value;
		Node* next;
		Node* pre;
	};

	mutable struct : public Object
	{
		char reserved[sizeof(T)];
		Node* next;
		Node* pre;
	}m_header;

	int m_length;
	int m_step;
	Node* m_iter;
public:
	DualLinkList()
	{
		m_header.next = nullptr;
		m_header.pre = nullptr;
		m_length = 0;
		m_step = 1;
		m_iter = nullptr;
	}

	virtual Node* at(int i) const
	{
		Node* ret = reinterpret_cast<Node*>(&m_header);
		if(((0 <= i) && (i < m_length)))
		{
			for(int j=0; j<=i; j++)
			{
				ret = ret->next;
			}
		}
		return ret;
	}

	virtual Node* create()
	{
		return new Node();
	}

	virtual void destory(Node* pn)
	{
		delete pn;
	}

	bool insert(int i, const T& obj)
	{
		bool ret = ((0 <= i) && (i <= m_length));
		if(ret)
		{
			Node* node = create();
			if(node != nullptr)
			{
				Node* current = at(i-1);
				node->value = obj;
				node->pre = (current == reinterpret_cast<Node*>(&m_header)) ? nullptr : current;
				node->next = current->next;
				current->next = node;
				m_length++;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create Node ...");
			}
		}
		return ret;
	}
	
	bool insert(const T& obj)
	{
		return insert(m_length, obj);
	}
	
	bool remove(int i)
	{
		bool ret = ((0 <= i) && (i < m_length));
		if(ret)
		{

			Node* current = at(i-1);
			Node* toDel = at(i);
			if(m_iter = toDel)
			{
				m_iter = toDel->next;
			}
			current->next = toDel->next;
			if(toDel->next != nullptr)
			{
				toDel->next->pre = current;
			}
			m_length--;
			destory(toDel);
		}
		return ret;
	}
	bool set(int i, const T& obj)
	{
		bool ret = ((0 <= i) && (i < m_length));
		if(ret)
		{
			at(i)->value = obj;
		}
		return ret;
	}
	virtual bool get(int i, T& obj) const
	{
		bool ret = ((0 <= i) && (i < m_length));
		if(ret)
		{
			obj = at(i)->value;
		}
		return ret;
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
		int i = 0;
		Node* node = m_header.next;
		while(node)
		{
			if(node->value == obj)
			{
				ret = i;
				break;
			}
			else
			{
				node = node->next;
				i++;
			}
		}
		return ret;
	}

	int length() const
	{
		return m_length;
	}
	void clear()
	{
		while(m_length > 0)
		{
			remove(0);
		}
	}

	bool move(int i, int step = 1)
	{
		bool ret = ((0 <= i) && (i < m_length) && (1 <= step));
		if(ret)
		{
			m_iter = at(i);
			m_step = step;
		}
		return ret;
	}
	bool isEnd()
	{
		return (m_iter == nullptr);
	}
	T current()
	{
		if(!isEnd())
			return m_iter->value;
		else
			THROW_EXCEPTION(InvalidOperationException, "No value at current position ...");
	}
	int currentLocation()
	{
		return find(m_iter->value);
	}
	virtual bool next()
	{
		int i=0;
		while((i<m_step) && !isEnd())
		{
			m_iter = m_iter->next;
			i++;
		}
		return (i==m_step);
	}
	virtual bool pre()
	{
		int i=0;
		while((i<m_step) && !isEnd())
		{
			m_iter = m_iter->pre;
			i++;
		}
		return (i==m_step);
	}
	~DualLinkList()
	{
		clear();
	}


};


}

#endif // !DUALLINKLIST_H
