#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "pointer.h"
/*智能指针：
 *重载->与*，使用对象代替指针
 *对象离开作用域就会被析构，用于避免内存泄漏
 *智能指针只用于指向堆空间的单个对象或变量
*/
namespace dataStruct
{

template <typename T>
class SmartPointer : public Pointer<T>
{
public:
	SmartPointer(T* p = nullptr) : Pointer<T>(p)
	{
	}

	SmartPointer(const SmartPointer<T>& obj)
	{
		this->m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
	}

	SmartPointer<T>& operator= (const SmartPointer<T>& obj)
	{
		if(this != &obj)
		{
			T* temp = this->m_pointer;
			this->m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
			delete temp;
		}
		return *this;
	}
	~SmartPointer()
	{
		delete this->m_pointer;
	}
};



}

#endif