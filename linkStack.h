#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "stack.h"
#include "linkList.h"
namespace dataStruct
{

template <typename T>
class LinkStack : public Stack<T>
{
protected:
	LinkList<T> m_list;
public:
	void push(const T& obj)
	{
		m_list.insert(obj);
	}
	virtual void pop()
	{
		if(m_list.length() > 0)
		{
			m_list.remove(m_list.length()-1);
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "the stack is empty ...");
		}
	}
	T top() const
	{
		if(m_list.length() > 0)
		{
			return m_list.at(m_list.length()-1)->value;
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "the stack is empty ...");
		}

	}
	void clear()
	{
		m_list.clear();
	}
	int size() const
	{
		return m_list.length();
	}
};

}

#endif