/*
*Chinaning
*20200324
*/
#include<iostream>
#include<string>
#include "LinkQueue.h"
using namespace std;

int main()
{
	LinkQueue<string> lqueue;
	lqueue.push("one");
	lqueue.push("two");
	lqueue.push("three");
	lqueue.push("four");
	lqueue.push("five");
	cout << "队列的大小" << lqueue.size() << endl;
	while (!lqueue.isEmpty())
	{
		cout << lqueue.front() << endl;
		lqueue.pop();
	}
	getchar();
	return 0;
}