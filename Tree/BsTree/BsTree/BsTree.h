/*数据结构：二叉查找树*/
#ifndef BSTREE_H
#define BSTREE_H
#include<queue>

/*树结点*/
template <typename K, typename V>
class Node {
public:
	K key;
	V val;
	Node<K, V>* left;
	Node<K, V>* right;
	int N;//以该结点为根的子树的结点数
		  //构造函数
	Node(K key, V val, int N) {
		this->key = key;
		this->val = val;
		this->N = N;
		this->left = NULL;
		this->right = NULL;
	}
	//拷贝构造函数
	Node(const Node<K, V>& node) {
		this->key = node.key;
		this->val = node.val;
		this->N = node.N;
		this->left = node.left;
		this->right = node.right;
	}
};




/*二叉查找树*/
template <typename K, typename V>
class BSTree {
private:
	Node<K, V>* root = NULL;
	/*返回以x为根结点的子树中的结点数*/
	int size(Node<K, V>* x);
	/*返回以x为根结点，键值key对应的val值*/
	V get(Node<K, V>* x, K key);
	/*将<key,val>插入以x为根结点的二叉查找树中，并返回插入后的树的根结点*/
	Node<K, V>* put(Node<K, V>* x, K key, V val);
	/*中序遍历以node为根结点的二叉树*/
	void inorder(Node<K, V>* x);
	/*返回以x为根结点的二叉查找树中key值最小的结点*/
	Node<K, V>* min(Node<K, V>* x);
	/*返回以x为根结点的二叉查找树中key值最大的结点*/
	Node<K, V>* max(Node<K, V>* x);
	/*返回以x为根结点的二叉查找树中所有小于key的键中最大的键的结点*/
	Node<K, V>* floor(Node<K, V>* x, K key);
	/*返回以x为根结点的二叉查找树中所有大于key的键中最小的键的结点*/
	Node<K, V>* ceiling(Node<K, V>* x, K key);
	/*返回以x为根结点的二叉查找树中键值排名为r的结点*/
	Node<K, V>* select(Node<K, V>* x, int r);
	/*返回以x为根结点的二叉查找树中键值key的排名*/
	int rank(Node<K, V>* x, K key);
	/*从以x为根结点的二叉查找树中删除键值最小的结点，并返回删除结点后的二叉查找树的根结点*/
	Node<K, V>* deleteMin(Node<K, V>* x);
	/*从以x为根结点的二叉查找树中删除键值最大的结点，并返回删除结点后的二叉查找树的根结点*/
	Node<K, V>* deleteMax(Node<K, V>* x);
	/*从以x为根结点的二叉查找树中删除键值为key的结点，并返回删除结点后的二叉查找树的根结点*/
	Node<K, V>* Delete(Node<K, V>* x, K key);
	/*将以x为根结点的二叉查找树中键值在区间[lo,hi]的所有键值加入到队列q中*/
	void keys(Node<K, V>* x, queue<K>& q, K lo, K hi);
public:
	/*返回整颗二叉查找树中的结点数*/
	int size();
	/*返回整颗二叉查找树中，键值key对应的val值*/
	V get(K key);
	/*将<key,val>插入到二叉查找树中*/
	void put(K key, V val);
	/*中序遍历二叉查找树*/
	void inorder();
	/*返回二叉查找树中最小的key值*/
	K min();
	/*返回二叉查找树中最大的key值*/
	K max();
	/*返回二叉查找树中所有小于key的键中最大的键值*/
	K floor(K key);
	/*返回二叉查找树中所有大于key的键中最小的键值*/
	K ceiling(K key);
	/*返回二叉查找树中键值排名为r的键值*/
	K select(int r);
	/*返回二叉查找树中键值key的排名*/
	int rank(K key);
	/*从二叉查找树中删除键值最小的结点*/
	void deleteMin();
	/*从二叉查找树中删除键值最大的结点*/
	void deleteMax();
	/*从二叉查找树中删除键值为key的结点*/
	void Delete(K key);
	/*将二叉查找树中键值在区间[lo,hi]的所有键值加入到队列q中*/
	queue<K> keys(K lo, K hi);
	/*返回二叉查找树中的所有键值*/
	queue<K> keys();
};

template <typename K, typename V>
int BSTree<K, V>::size(Node<K, V>* x) {
	if (x == NULL)return 0;
	else return x->N;
}
template <typename K, typename V>
int BSTree<K, V>::size() {
	return size(root);
}

/*查找：按key进行查找，如果命中返回对应的val，否则返回NULL;*/
template <typename K, typename V>
V BSTree<K, V>::get(Node<K, V>* x, K key) {
	if (x == NULL)
		return NULL;
	if (key>x->key)return get(x->right, key);
	else if (key<x->key)return get(x->left, key);
	else return x->val;
}
template <typename K, typename V>
V BSTree<K, V>::get(K key) {
	return get(root, key);
}

/*插入：将key,val插入树中*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::put(Node<K, V>* x, K key, V val) {
	if (x == NULL)return new Node<K, V>(key, val, 1);
	if (key>x->key)x->right = put(x->right, key, val);//将key插入右子树
	else if (key<x->key)x->left = put(x->left, key, val);//将key插入左子树
	else x->val = val;//覆盖原始值
	x->N = size(x->left) + size(x->right) + 1;//维护N值
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::put(K key, V val) {
	root = put(root, key, val);
}
/*中序遍历*/
template <typename K, typename V>
void BSTree<K, V>::inorder(Node<K, V>* x) {
	if (x == NULL)
		return;
	inorder(x->left);
	cout << x->key << " ";
	inorder(x->right);
}
template <typename K, typename V>
void BSTree<K, V>::inorder() {
	inorder(root);
}
/*最小值与最大值*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::min(Node<K, V>* x) {
	if (x->left == NULL)return x;
	return min(x->left);
}
template <typename K, typename V>
K BSTree<K, V>::min() {
	return min(root)->key;
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::max(Node<K, V>* x) {
	if (x->right == NULL)return x;
	return max(x->right);
}
template <typename K, typename V>
K BSTree<K, V>::max() {
	return max(root)->key;
}
/*下取整与上取整*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::floor(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key == x->key)return x;
	if (key<x->key)return floor(x->left, key);
	//当key>x->key时，floor有可能在x->right子树中，也有可能就是x
	Node<K, V>* t = floor(x->right, key);
	if (t != NULL)return t;
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::floor(K key) {
	Node<K, V>* x = floor(root, key);
	if (x == NULL)return NULL;
	return x->key;
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::ceiling(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key == x->key)return x;
	if (key>x->key)return ceiling(x->right, key);
	//当key<x->key时，ceiling有可能在x->left子树中，也有可能就是x
	Node<K, V>* t = ceiling(x->left, key);
	if (t != NULL)return t;
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::ceiling(K key) {
	Node<K, V>* x = ceiling(root, key);
	if (x == NULL)return NULL;
	return x->key;
}
/*选择*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::select(Node<K, V>* x, int r) {
	if (x == NULL)return NULL;
	int t = size(x->left);
	if (r<t)return select(x->left, r);
	else if (r>t)return select(x->right, r - t - 1);
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::select(int r) {
	return select(root, r)->key;
}
/*排名*/
template <typename K, typename V>
int BSTree<K, V>::rank(Node<K, V>* x, K key) {
	//小于键值key的键的数量
	if (x == NULL)return 0;
	if (key<x->key)return rank(x->left, key);
	else if (key>x->key)return size(x->left) + 1 + rank(x->right, key);
	else return size(x->left);
}
template <typename K, typename V>
int BSTree<K, V>::rank(K key) {
	return rank(root, key);
}
/*删除最小值与最大值*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::deleteMin(Node<K, V>* x) {
	if (x == NULL)return NULL;
	Node<K, V>* right = NULL;
	if (x->left == NULL) {
		right = x->right;
		delete x;
		return right;
	}
	x->left = deleteMin(x->left);
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::deleteMin() {
	root = deleteMin(root);
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::deleteMax(Node<K, V>* x) {
	if (x == NULL)return NULL;
	Node<K, V>* left = NULL;
	if (x->right == NULL) {
		left = x->left;
		delete x;
		return left;
	}
	x->right = deleteMax(x->right);
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::deleteMax() {
	root = deleteMax(root);
}
/*删除任意结点*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::Delete(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key<x->key)x->left = Delete(x->left, key);
	else if (key>x->key)x->right = Delete(x->right, key);
	else {
		if (x->right == NULL)return x->left;
		if (x->left == NULL)return x->right;
		//x->right!=NULL&x->left!=NULL
		Node<K, V>* t = x;
		x = new Node<K, V>(*min(t->right));
		x->right = deleteMin(t->right);
		x->left = t->left;
		delete t;
	}
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::Delete(K key) {
	root = Delete(root, key);
}
/*返回指定区间的键值*/
template <typename K, typename V>
void BSTree<K, V>::keys(Node<K, V>* x, queue<K>& q, K lo, K hi) {
	if (x == NULL)return;
	//如果lo<x->key，说明有遍历左子树的必要
	if (x->key>lo)keys(x->left, q, lo, hi);
	//扫描当前结点
	if (x->key >= lo&&x->key <= hi)q.push(x->key);
	//如果x->key<hi，说明有遍历右子树的必要
	if (x->key<hi)keys(x->right, q, lo, hi);
}
template <typename K, typename V>
queue<K> BSTree<K, V>::keys(K lo, K hi) {
	queue<K> q;
	keys(root, q, lo, hi);
	return q;
}

template <typename K, typename V>
queue<K> BSTree<K, V>::keys() {
	return keys(min(), max());
}
#endif