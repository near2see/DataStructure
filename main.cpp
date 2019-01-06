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
	//josephus(41, 1, 3);
	LinkStack<Test> st;
	for(int i=0; i<5; i++)
	{
		st.push(Test());
	}
}
