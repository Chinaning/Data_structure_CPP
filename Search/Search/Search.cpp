#include <iostream>
#include<vector>
#include"Search.h"
using namespace  std;

int main() {
	int temp[] = { 1,2,3,4,5,6,7,8 };
	vector<int> vec1(temp,temp+8);//用数组给向量赋值
	vector<int> vec2(vec1);//用vec1给vec2赋值
	vector<int> vec3(vec1);//用vec1给vec3赋值
	vector<int> vec4(vec1);//用vec1给vec4赋值
	int n = vec1.size();
	int key;

	//顺序查找
	cout << "请输入需要顺序查找的值：" << endl;
	cin >> key;
	Sequential sequence;
	int num1 =sequence.Sequential_search(vec1, key, n);
	cout << num1<<endl;



	//二分查找
	cout << "请输入需要二分查找的值：" << endl;
	cin >> key;
	Binary binary;
	int num2 = binary.Binary_search(vec1, key, n);
	cout << num2<<endl;



	//插值查找
	cout << "请输入需要插值查找的值：" << endl;
	cin >> key;
	Interpolation interpolation;
	int num3 = interpolation.Interpolation_search(vec2, key, n);
	cout << num3 << endl;



	//斐波那契查找
	cout << "请输入需要斐波那契查找的值：" << endl;
	cin >> key;
	FibonacciSearch fibonacci;
	int num4 = fibonacci.Fibonacci_search(vec3, key, n);
	cout << num4 << endl;


	//分块查找
	cout << "请输入需要分块查找的值：" << endl;
	cin >> key;
	Block block;
	int num5 = block.Block_search(vec4, key,n);
	cout << num5 << endl;


	system("pause");
}