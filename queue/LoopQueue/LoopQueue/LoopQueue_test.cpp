/*
* Chinaning
* 20200324
*/


#include<iostream>
#include"LoopQueue.h"
#include<string>
using namespace std;
int main()
{
	LoopQueue<string> queue(6);
	queue.push("one");
	queue.push("two");
	queue.push("three");
	queue.push("four");
	queue.push("five");
	cout << "队列长度" << queue.size() << endl;
	while (!queue.isEmpty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	getchar();//避免VS一闪而过的方法之一
	return 0;

}