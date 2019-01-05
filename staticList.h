#ifndef STATICLSIT_H
#define STATICLSIT_H
#include "seqlist.h"

namespace dataStruct
{

template <typename T, int N>
class StaticList : public Seqlist<T>
{
protected:
	T m_space[N];
public:
	StaticList()
	{
		this->m_array = m_space;
		this->m_length = 0;
	}

	int capacity() const
	{
		return N;
	}
};


}

#endif // !STATICLSIT_H

