#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include "pointer.h"
#include "exception.h"
#include <cstdlib>
namespace dataStruct
{

template <typename T>
class SharedPointer : public Pointer<T>
{
protected:
	int* m_ref;
public:
	void assign(const SharedPointer<T>& obj)
	{
		this->m_ref = obj.m_ref;
		this->m_pointer = obj.m_pointer;
		if(this->m_ref)
		{
			(*this->m_ref)++;
		}
	}
	SharedPointer(T* p=nullptr) : m_ref(nullptr)
	{
		if(p)
		{
			this->m_ref = static_cast<int*>(std::malloc(sizeof(int)));
			if(this->m_ref)
			{
				*(this->m_ref) = 1;
				this->m_pointer = p;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memeory to create SharedPointer object ...");
			}
		}
	}
	SharedPointer(const SharedPointer<T>& obj) : Pointer<T>(nullptr)
	{
		assign(obj);
	}
	SharedPointer<T>& operator= (const SharedPointer<T>& obj)
	{
		if(this != &obj)
		{
			clear();
			assign(obj);
		}
		return *this;
	}
	void clear()
	{
		T* toDel = this->m_pointer;
		int* ref = this->m_ref;
		this->m_pointer = nullptr;
		this->m_ref = nullptr;
		if(ref)
		{
			(*ref)--;
			if(*ref == 0)
			{
				free(ref);
				delete toDel;
			}
		}
	}
	~SharedPointer()
	{
		clear();
	}
};
template <typename T>
bool operator== (const SharedPointer<T>& l, const SharedPointer<T>& r)
{
	return (l.get() == r.get());
}
template <typename T>
bool operator!= (const SharedPointer<T>& l, const SharedPointer<T>& r)
{
	return !(l.get() == r.get());
}


}
#endif // !SHAREDPOINTER_H
