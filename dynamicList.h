#ifndef DYNAMICLSIT_H
#define DYNAMICLIST_H
#include "seqlist.h"

namespace dataStruct
{

template <typename T>
class DynamicList : public Seqlist<T>
{
protected:
	int m_capacity;
public:
	DynamicList(int capacity)
	{
		this->m_array = new T[capacity];
		if(this->m_array != nullptr)
		{
			this->m_length = 0;
			m_capacity = capacity;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object ...");
		}
	}
	int capacity() const
	{
		return m_capacity;
	}

	void resize(int capacity)
	{
		if(capacity != m_capacity)
		{
			T* array = new T[capacity];
			if(array != nullptr)
			{
				int length = (this->m_length < capacity ? this->m_length : capacity);
				for(int i=0; i<length; i++)
				{
					array[i] = this->m_array[i];
				}

				T* temp = this->m_array;
				this->m_array = array;
				this->m_length = length;
				this->m_capacity = capacity;

				delete[] temp;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize DynamicList object ...");
			}
		}
	}

	~DynamicList()
	{
		delete[] this->m_array;
	}
};

}
#endif // !DYNAMICLSIT_H
