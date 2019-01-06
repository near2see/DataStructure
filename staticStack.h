#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "stack.h"
#include "exception.h"
namespace dataStruct
{

template <typename T, int N>
class StaticStack : public Stack<T>
{
protected:
	T m_space[N];
	int m_top;
	int m_size;
public:
	StaticStack()
	{
		m_top = -1;
		m_size = 0;
	}
	int capcity() const
	{
		return N;
	}
	void push(const T& obj)
	{
		if(m_size < N)
		{
			m_space[m_top+1] = obj;
			m_top++;
			m_size++;
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "no space to push ...");
		}
	}

	void pop()
	{
		if(m_size > 0)
		{
			m_top --;
			m_size --;
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "no element to pop ...");
		}
	}

	T top() const
	{
		if(m_size > 0)
		{
			return m_space[m_top];
		}
		else
		{
			THROW_EXCEPTION(InvalidOperationException, "the stack is empty ...");
		}
	}
	void clear()
	{
		m_top = -1;
		m_size = 0;
	}
	int size() const
	{
		return m_size;
	}
};


}

#endif // !STATICSTACK_H
