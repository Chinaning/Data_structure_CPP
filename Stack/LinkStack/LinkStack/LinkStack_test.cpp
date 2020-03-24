#include<iostream>
#include<string>
#include"LinkStack.h"
using namespace std;


int main()
{
	LinkStack <string> lstack;
	lstack.push("hello");
	lstack.push("to");
	lstack.push("you");
	int SIZE = lstack.size();
	string TOP = lstack.top();
	cout << "栈的大小:" << SIZE << endl;
	cout << "栈顶元素:" << TOP << endl;

	while (!lstack.isEmpty())
	{
		lstack.pop();
	}


	getchar();
	return 0;
}
