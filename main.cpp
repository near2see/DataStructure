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
#include <iostream>

using namespace std;
using namespace dataStruct;
void josephus(int n, int s, int m)
{
	CircleLinkList<int> cl;
	for(int i=1; i<=n; i++)
	{
		cl.insert(i);
	}
	cl.move(s-1, m-1);
	while(cl.length() > 0)
	{
		cl.next();
		cout << cl.current() << "\t";
		cl.remove(cl.find(cl.current()));
	}
	cout << endl << cl.length();
}
int main()
{
	//josephus(41, 1, 3);
	DualLinkList<int> dl;
	for(int i=0; i<5; i++)
	{
		dl.insert(i);
	}

	for(dl.move(4); !dl.isEnd(); dl.pre())
	{
		cout << dl.current();
	}

}
