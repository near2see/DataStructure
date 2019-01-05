#include "exception.h"
#include <cstring>
#include <cstdlib>
using namespace std;

namespace dataStruct
{

void Exception::init(const char* message, const char* file, int line)
{
	m_message = (message == nullptr) ? nullptr : _strdup(message); //message来历不明，先拷贝到堆中
	if(file != nullptr)
	{
		char sline[16] = {0};
		itoa(line, sline, 10);

		m_location = static_cast<char*>(malloc(strlen(file) + strlen(sline) + 2));
		if(m_location != nullptr)
		{
			m_location = strcpy(m_location, file);
			m_location = strcat(m_location, ":");
			m_location = strcat(m_location, sline);
		}
	}
	else
	{
		m_location = nullptr;
	}
}

Exception::Exception(const char* message)
{
	init(message, nullptr, 0);
}
Exception::Exception(const char* file, int line)
{
	init(nullptr, file, line);
}
Exception::Exception(const char* message, const char* file, int line)
{
	init(message, file, line);
}
Exception::Exception(const Exception& e)
{
	m_message = (e.m_message == nullptr) ? nullptr : _strdup(e.m_message);
	m_location = strdup(e.m_location);
}
Exception& Exception::operator= (const Exception& e)
{
	if(this != &e)
	{
		free(m_message);
		free(m_location);

		m_message = strdup(e.m_message);
		m_location = strdup(e.m_location);
	}
	return *this;
}
const char* Exception::message() const
{
	return m_message;
}
const char* Exception::location() const
{
	return m_location;
}
Exception::~Exception()
{
	free(m_message);
	free(m_location);
}

}