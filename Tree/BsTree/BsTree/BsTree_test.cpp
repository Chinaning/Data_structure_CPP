/*数据结构：二叉查找树*/

#include <iostream>
#include"BsTree.h"
#include <queue>
using namespace std;

int main() {
	BSTree<int, char> tree;
	tree.put(3, 'a');
	tree.put(2, 'b');
	tree.put(9, 'c');
	tree.put(1, 'd');
	tree.put(7, 'e');
	tree.inorder();
	cout << endl << tree.min();
	cout << endl << tree.max();
	cout << endl << tree.floor(6);
	cout << endl << tree.ceiling(6);
	cout << endl << tree.select(0);
	cout << endl << tree.rank(8);
	tree.Delete(3);
	tree.deleteMax();
	cout << endl;
	tree.inorder();
	cout << endl;
	queue<int> q = tree.keys(2, 7);
	while (q.size()>0) {
		cout << q.front() << " ";
		q.pop();
	}
	q = tree.keys();
	cout << endl;
	while (q.size()>0) {
		cout << q.front() << " ";
		q.pop();
	}
	system("pause");
}
