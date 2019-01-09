#ifndef _STRING_H
#define _STRING_H
#include "object.h"

namespace dataStruct
{
class String : public Object
{
protected:
	char* m_str;
	int m_length;
	void init(const char* s);
	bool equal(const char* l, const char* r, int len) const;
public:
	String();
	String(char c);
	String(const char* s);
	String(const String& s);
	int length() const;
	const char* str() const;

	bool operator== (const String& s) const;
	bool operator== (const char* s) const;
	bool operator!= (const String& s) const;
	bool operator!= (const char* s) const;
	bool operator> (const String& s) const;
	bool operator> (const char* s) const;
	bool operator< (const String& s) const;
	bool operator< (const char* s) const;
	bool operator>= (const String& s) const;
	bool operator>= (const char* s) const;
	bool operator<= (const String& s) const;
	bool operator<= (const char* s) const;

	String operator+ (const String& s) const;
	String operator+ (const char* s) const;
	String& operator+= (const String& s);
	String& operator+= (const char* c);

	String& operator= (const String& s);
	String& operator= (const char* s);
	String& operator= (const char c);

	char& operator[] (int i);
	char operator[] (int i) const;

	bool startWith(const char* s) const;
	bool startWith(const String& s) const;
	bool endOf(const char* s) const;
	bool endOf(const String& s) const;

	String& insert(int i, const char* s);
	String& insert(int i, const String& s);

	int indexOf(const char* s) const;
	int indexOf(const String& s) const;
	int indexOf(const char c) const;

	int* findAll(const char* s) const;
	int* findAll(const String& s) const;
	int* findAll(const char c) const;

	String& replace(const char* s, const char* d) ;
	String& replace(const String& s, const char* d) ;
	String& replace(const char c, const char* d) ;

	String& remove(const char* s) ;
	String& remove(const String& s) ;
	String& remove(const char c) ;

	String& trim();

	String sub(int i, int len) const;
	~String();
};


}
#endif