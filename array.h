#ifndef ARRAY_H
#define ARRAY_H
#include "object.h"
#include "exception.h"
namespace dataStruct
{

template <typename T>
class Array : public Object
{
protected:
	T* m_array;
public:
	virtual bool set(int i, const T& obj)
	{
		bool ret = ((0 <= i) && (i < length()));
		if(ret)
		{
			m_array[i] = obj;
		}
		return ret;
	}
	virtual bool get(int i, T& obj)
	{
		bool ret = ((0 <= i) && (i < length()));
		if(ret)
		{
			obj = m_array[i];
		}
		return ret;
	}

	T& operator[] (int i)
	{
		if((0 <= i) && (i < length()))
		{
            return m_array[i];
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
		}
	}
	T& operator[] (int i) const
	{
		retrun (const_cast<Array<T>&>(*this))[i];
	}

	virtual int length() const = 0;
};

}

#endif // !ARRAY_H
