#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "queue.h"
#include "linkList.h"
#include "exception.h"
namespace dataStruct
{

template <typename T> 
class LinkQueue : public Queue<T>
{
protected:
	LinkList<T> m_list;
public:
	LinkQueue()
	{

	}

	void add(const T& obj)
	{
		m_list.insert(obj);
	}
	void remove()
	{
		if(m_list.length() > 0)
		{
			m_list.remove(0);
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "No element in this queue");
		}
	}

	T front() const
	{
		if(m_list.length() > 0)
		{
			return m_list.get(0);
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "No element in this queue");
		}
	}
	void clear()
	{
		m_list.clear();
	}
	int length() const
	{
		return m_list.length();
	}
};

}

#endif // !LINKQUEUE_H
