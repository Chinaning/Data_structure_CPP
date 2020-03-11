#include <iostream>
#include <list> //列表
#include <stack>//栈
#include <queue>//队列
#include"BiTree.h"//引用自定义头文件

using namespace std;


/*主函数*/
int main() {
	BiTree<int>* biTree = new BiTree<int>();
	/*
	构建二叉树：
	3
	6   2
	8 9
	*/
	biTree->insert_left(biTree->root, 3);
	biTree->insert_left(biTree->root, 6);
	biTree->insert_right(biTree->root, 2);
	biTree->insert_left(biTree->root->left, 8);
	biTree->insert_right(biTree->root->left, 9);
	list<int> l;
	list<int>::iterator iter;
	//先序遍历
	biTree->preorderR(biTree->root, &l);
	cout << endl << "先序遍历(递归)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->preorderI(biTree->root, &l);
	cout << endl << "先序遍历(迭代)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//中序遍历
	biTree->inorderR(biTree->root, &l);
	cout << endl << "中序遍历(递归)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->inorderI(biTree->root, &l);
	cout << endl << "中序遍历(迭代)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//后序遍历
	biTree->postorderR(biTree->root, &l);
	cout << endl << "后序遍历(递归)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->postorderI(biTree->root, &l);
	cout << endl << "后序遍历(迭代)：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//层次遍历
	biTree->level(biTree->root, &l);
	cout << endl << "层次遍历：";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	cout << endl << biTree->height(biTree->root);
	delete biTree;
	system("pause");//对于程序功能无实际作用，放在末尾用来显示VS的运行结果，否则运行结果会一闪而过，无法看到。
}