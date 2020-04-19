/*
 Chinaning
 20200325
*/
#include "MinHeap.h"
#include<iostream>
using namespace std;

int main( )
{
	MinHeap<int> heap(11);
	//逐个元素构建小顶堆
	for (int i = 0; i < 10; i++)
	{
		heap.insert(i);
	}
	heap.print();
	cout << endl;
	heap.remove(8);
	heap.print();
	cout << endl;

	//根据指定的数组创建大顶堆
	MinHeap<int> heap2(11);
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[9] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
	heap2.createMinHeap(b, 9);
	heap2.print();
	getchar();

	return 0;
}