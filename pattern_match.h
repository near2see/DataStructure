#ifndef PATTERN_MATCH_H
#define PATTERN_MATCH_H
#include <cstring>
#include <cstdlib>
//////////////////////////////////////////////////////////////
// KMP algorithm
namespace dataStruct
{


inline int* get_pmt(const char* p)
{
	int len = strlen(p);
	int* ret = static_cast<int*>(malloc(len*sizeof(int)));
	if(ret)
	{
		int match_value = 0;
		ret[0] = 0;
		for(int i=1; i<len; i++)
		{
			while( (p[match_value]!=p[i]) && (match_value>0))
			{
				match_value = ret[match_value-1];
			}
			if(p[match_value] == p[i])
			{
				match_value++;
			}
			ret[i] = match_value;
		}
	}
	else
	{

	}
	return ret;
}
/**
 * @brief 
 * 
 * @param T 
 * @param P 
 * @return int 
 */
inline int kmp(const char* T, const char* P)
{
	int ret = -1;
	int T_length = strlen(T);
	int P_length = strlen(P);
	int* pmt = get_pmt(P);
	if( (pmt != nullptr) && (T_length >= P_length) )
	{
		for(int i=0, j=0; i<T_length; i++)
		{
			while( (j>0) && (T[i]!=P[j]) )
			{
				j = pmt[j-1];
			}
			if(T[i] == P[j])
			{
				j++;
			}
			if(j == P_length)
			{
				ret = i+1 - P_length;
				break;
			}
		}
	}
	free(pmt);
	return ret;
}

//////////////////////////////////////////////////////////////
//sunday algorithm
inline int get_shift(const char* p, char c)
{
	int len = strlen(p);
	int ret = len;
	for(int i=0; i<len; i++)
	{
		if(p[i] == c)
		{
			ret = len -i;
			break;
		}
	}
	return ret;
}
inline int sunday(const char* T, const char* P, int i=0)
{
	int ret = -1;
	int T_length = strlen(T);
	int P_length = strlen(P);
	if(T_length >= P_length)
	{
		for(int j=0; i<T_length; i++)
		{
			while( (T[i] != P[j]) && (i<=T_length))
			{
				i += get_shift(P, T[i+P_length-j]);
				j=0;
			}
			if(T[i] == P[j])
			{
				j++;
			}
			if(j == P_length)
			{
				ret = i+1-P_length;
				break;
			}
		}
	}
	return ret;
}


}
#endif // !PATTERN_MATCH_H