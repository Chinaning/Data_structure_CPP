#include <iostream>
#include"AVLTree.h"
using namespace std;

int main() {
	AVLTree<int>*avltree = new AVLTree<int>();
	/*
	¹¹½¨AVLÊ÷£º
	*/
	avltree->insert(3);
	avltree->insert(6);
	avltree->insert(4);
	avltree->insert(8);
	avltree->insert(7);
	avltree->insert(1);
	avltree->traversal();
	getchar();
	
}