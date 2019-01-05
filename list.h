#ifndef LIST_H
#define LIST_H
#include "object.h"
namespace dataStruct
{

template <typename T>
class List : public Object
{
protected:
	List(const List& );
	List& operator= (const List& );
public:
	List(){}
	virtual bool insert(int i, const T& obj) = 0;
	virtual bool insert(const T& obj) = 0;
	virtual bool remove(int i) = 0;
	virtual bool set(int i, const T& obj) = 0;
	virtual bool get(int i, T& obj) const = 0;
	virtual int find(const T& obj) const = 0;
	virtual int length() const = 0;
	virtual void clear() = 0;
};

}

#endif // !LIST_H
