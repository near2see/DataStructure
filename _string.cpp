#include "_string.h"
#include <cstdlib>
#include <cstring>
#include "exception.h"
#include "pattern_match.h"
namespace dataStruct
{

void String::init(const char* s)
{
	m_str = strdup(s);
	if(m_str)
	{
		m_length = strlen(m_str);
	}
	else
	{
		THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create String object ...");
	}
}

bool String::equal(const char* l, const char* r, int len) const
{
	bool ret = true;
	for(int i=0; i<len; i++)
	{
		ret = ret && (l[i] == r[i]);
	}
	return ret;
}

String::String()
{
	init("");
}
String::String(const char* s)
{
	init(s ? s : "");
}
String::String(const String& s)
{
	init(s.m_str);
}
String::String(char c)
{
	char s[] = {c, '\0'};
	init(s);
}
int String::length() const
{
	return m_length;
}
const char* String::str() const
{
	return m_str;
}


bool String::operator== (const String& s) const
{
	return (strcmp(m_str, s.m_str) == 0);
}
bool String::operator== (const char* s) const
{
	return (strcmp(m_str, s ? s : "") == 0);
}
bool String::operator!= (const String& s) const
{
	return !(*this == s);
}
bool String::operator!= (const char* s) const
{
	return !(*this == s);
}
bool String::operator> (const String& s) const
{
	return (strcmp(m_str, s.m_str) > 0);
}
bool String::operator> (const char* s) const
{
		return (strcmp(m_str, s ? s : "") > 0);
}
bool String::operator< (const String& s) const
{
		return (strcmp(m_str, s.m_str) < 0);
}
bool String::operator< (const char* s) const
{
		return (strcmp(m_str, s ? s : "") > 0);
}
bool String::operator>= (const String& s) const
{
		return (strcmp(m_str, s.m_str) >= 0);
}
bool String::operator>= (const char* s) const
{
		return (strcmp(m_str, s ? s : "") >= 0);
}
bool String::operator<= (const String& s) const
{
		return (strcmp(m_str, s.m_str) <= 0);
}
bool String::operator<= (const char* s) const
{
		return (strcmp(m_str, s ? s : "") <= 0);
}

String String::operator+ (const String& s) const
{
	return (*this + s.m_str);
}
String String::operator+ (const char* s) const
{
	String ret;
	int len = m_length + strlen(s ? s : "");
	char* str = reinterpret_cast<char*>(malloc(len+1));
	if(str)
	{
		strcpy(str, m_str);
		strcat(str, s ? s : "");
		free(ret.m_str);
		ret.m_str = str;
		ret.m_length = len;
	}
	else
	{
		THROW_EXCEPTION(NoEnoughMemoryException, "No memory to add String ...");
	}
	return ret;
}

String& String::operator+= (const String& s)
{
	return (*this = *this + s);
}
String& String::operator+= (const char* s)
{
	return (*this = *this + s);
}

String& String::operator= (const String& s)
{
	return(*this = s.m_str);
}
String& String::operator= (const char* s)
{
	if(m_str != s)
	{
		char* str = strdup(s ? s : "");
		if(str)
		{
			free(m_str);
			m_str = str;
			m_length = strlen(m_str);
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign new String ...");
		}
	}
}
String& String::operator= (const char c)
{
	char s[] = {c, '\0'};
	return (*this = s);
}

char& String::operator[] (int i)
{
	if( (0<=i) && (i<m_length) )
	{
		return m_str[i];
	}
	else
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
	}
}
char String::operator[] (int i) const
{
	return (const_cast<String&>(*this)[i]);
}

bool String::startWith(const char* s) const
{
	bool ret = (s != nullptr);
	if(ret)
	{
		int len = strlen(s);
		ret = (len <= m_length) && equal(m_str, s, len);
		
	}
	return ret;
}
bool String::startWith(const String& s) const
{
	return startWith(s.m_str);
}
bool String::endOf(const char* s) const
{
	bool ret = (s != nullptr);
	if(ret)
	{
		int len = strlen(s);
		char* str = m_str + (m_length - len);
		ret = (len <= m_length) && equal(m_str, s, len);	
	}
	return ret;
}
bool String::endOf(const String& s) const
{
	return endOf(s.m_str);
}

String& String::insert(int i, const char* s)
{
	if( (0<=i) && (i<m_length) )
	{
		if((s != nullptr) && (s[0] != '\0'))
		{
			int len = strlen(s);
			char* str = reinterpret_cast<char*>(malloc(m_length + len + 1));
			if(str != nullptr)
			{
				strncpy(str, m_str, i);
				strncpy(str+i, s, len);
				strncpy(str+i+len, m_str+i, m_length-i);
				str[m_length+len] = '\0';
				free(m_str);
				m_str = str;
				m_length = m_length + len;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign String object ...");
			}
		}
	}
	else
	{
		THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
	}
	return *this;
}
String& String::insert(int i, const String& s)
{
	return insert(i, s.m_str);
}

int String::indexOf(const char* s) const
{
	int ret = -1;
	if(s != nullptr)
	{
		if(*this == s)
		{
			ret = 0;
		}
		else
		{
			ret = sunday(m_str, s);
		}
	}
	return ret;
}

int String::indexOf(const String& s) const
{
	return indexOf(s.m_str);
}
int String::indexOf(const char c) const
{
	char s[] = {c, '\0'};
	return indexOf(s);
}

int* String::findAll(const char* s) const
{
	int* ret = nullptr;
	if((s != nullptr))
	{
		int size = strlen(m_str)/strlen(s)+1;
		ret = static_cast<int*>(malloc(size*sizeof(int)));
		if(ret != nullptr)
		{	
			for(int i=0; i<size; i++)
			{
				ret[i] = -1;
			}
			ret[0] = 0;
			int index = 1;
			ret[index] = sunday(m_str, s, 0);
			while(ret[index++] >= 0 && index <= size)
			{
				ret[index] = sunday(m_str, s, ret[index-1]+1);
				ret[0] ++;
			}
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign String object ...");
		}
		
	}
	else
	{

	}	
	return ret;
}

int* String::findAll(const String& s) const
{
	return findAll(s.m_str);
}

int* String::findAll(const char c) const
{
	char s[] = {c, '\0'};
	return findAll(s);
}

String& String::replace(const char* s, const char* d)
{
	int* index_tab = findAll(s);
	if((index_tab != nullptr) && (index_tab[0] > 0))
	{
		int size = strlen(m_str) + (strlen(d) - strlen(s))*index_tab[0] + 1;
		char* after_del = static_cast<char*>(malloc(size*sizeof(char)));
		if(after_del != nullptr)
		{	
			int n=0;
			for(int i=1; i<=index_tab[0]; i++)
			{
				if((i==1) && (index_tab[i] == 0))
				{
					;
				}
				else if((i==1) && (index_tab[i] > 0))
				{
					strncpy(after_del, m_str, index_tab[i]);
					n += index_tab[i];
				}
				else
				{
					strncpy(after_del+n, m_str+index_tab[i-1]+1, index_tab[i]-index_tab[i-1]-1);
					n += index_tab[i] - index_tab[i-1] -1;
				}
				strncpy(after_del+n, d, strlen(d));
				n += strlen(d);
			}
			if((index_tab[index_tab[0]]+1) < strlen(m_str))
			{
				strncpy(after_del+n, m_str+index_tab[index_tab[0]]+1, strlen(m_str)-index_tab[index_tab[0]]);
			}
			after_del[size-1] = '\0';
			free(m_str);
			m_str = after_del;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign String object ...");
		}
	}
	return *this;
}

String& String::replace(const String& s, const char* d)
{
	return replace(s.m_str, d);
}
String& String::replace(const char c, const char* d)
{
	char s[] = {c, '\0'};
	return replace(s, d);
}
String& String::remove(const char* s)
{
	return replace(s, "");
}
String& String::remove(const String& s)
{
	return remove(s.m_str);
}
String& String::remove(const char c)
{
	char s[] = {c, '\0'};
	return remove(s);
}

String& String::trim()
{
	return remove(" ");
}

String String::sub(int i, int len) const
{
	String ret;
	ret.m_str = nullptr;
	if((i>=0) && (i+len<=m_length))
	{
		char* str = static_cast<char*>(malloc(len+1));
		if(str != nullptr)
		{
			strncpy(str, m_str+i, len);
			str[len] = '\0';
			ret.m_str = str;
			ret.m_length = len;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to assign String object ...");
		}
	}
	return ret;
}

String::~String()
{
	free(m_str);
}
}