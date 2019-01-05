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
	josephus(41, 1, 3);
#if 0
	LinkList<int> ll;
	for(int i=1; i<10; i++)
	{
		ll.insert(i);
	}
	ll.move(0, 2);
	ll.next();
	cout << ll.current() << "\t";
	ll.remove(ll.currentLocation());
	ll.next();
	cout << ll.current() << "\t";
	ll.remove(ll.currentLocation());
	for(int i=0; i<ll.length(); i++)
	{
		cout << ll.position(i)->value;
	}
#endif

}
