#include "object.h"
#include "list.h"
#include "seqlist.h"
#include "staticList.h"
#include "dynamicList.h"
#include "sataticArray.h"
#include "dynamicArray.h"
#include "linkList.h"
#include "staticLinkList.h"
#include "sharedPointer.h"
#include "smartPointer.h"
#include "circleLinkList.h"
#include "dualLinkList.h"
#include "dualCircleList.h"
#include "staticStack.h"
#include "linkStack.h"
#include "staticQueue.h"
#include "linkQueue.h"
#include "_string.h"
#include <iostream>

using namespace std;
using namespace dataStruct;
class Test : public Object
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test() 
	{
		cout << "~Test()" << endl;
	}
};
int main()
{
	String st = "hello";
	st += "world";
	cout << ":" << st.str() << ":" << st.length();
	cout << st.startWith("hello");
	st.insert(4, "jjjjjjjjj");
	cout << st.str();
}
