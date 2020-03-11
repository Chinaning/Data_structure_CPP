#ifndef _BITREE_H_
#define _BITREE_H_

using namespace std;

/*结点定义*/
template <typename T>   /*template为函数模板，将参数类型作为函数参数，可以定义一类函数族*/
class BiTreeNode {
public:
	T data;
	BiTreeNode<T>* left; /*左孩子指针*/
	BiTreeNode<T>* right;/*右孩子指针*/
	BiTreeNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
/*接口定义*/
template <typename T>
class BiTree {
private:
	int size;  /*树中结点的个数*/
public:
	BiTreeNode<T>* root;/*根结点的指针*/

	BiTree() { size = 0; root = NULL; };
	~BiTree() { remove(root); };   /*析构函数~，释放空间，还原变量*/

	bool insert_left(BiTreeNode<T>* node, T data); /*将data插入到node的左孩子*/
	bool insert_right(BiTreeNode<T>* node, T data); /*将data插入到node的右孩子*/
	bool remove(BiTreeNode<T>* &node); /*删除以node为根的子树*/
	bool preorderR(BiTreeNode<T>* node, list<T>* l); /*递归实现：先序遍历以node为根的树，并将遍历结果保存到l中*/
	bool preorderI(BiTreeNode<T>* node, list<T>* l); /*迭代实现：先序遍历以node为根的树，并将遍历结果保存到l中*/
	bool inorderR(BiTreeNode<T>* node, list<T>* l);/*递归实现：中序遍历以node为根的树，并将遍历结果保存到l中*/
	bool inorderI(BiTreeNode<T>* node, list<T>* l);/*迭代实现：中序遍历以node为根的树，并将遍历结果保存到l中*/
	bool postorderR(BiTreeNode<T>* node, list<T>* l);/*递归实现：后序遍历以node为根的树，并将遍历结果保存到l中*/
	bool postorderI(BiTreeNode<T>* node, list<T>* l);/*迭代实现：后序遍历以node为根的树，并将遍历结果保存到l中*/
	bool level(BiTreeNode<T>* node, list<T>* l);/*层次遍历以node为根的树，并将变量结果保存到l中*/
	int height(BiTreeNode<T>* node);/*以node为根的树的高度*/
};

/**************************************************************************
Function:insert_left
Description:将data插入到node的左孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_left(BiTreeNode<T>* node, T data) {
	if (node == NULL) {//允许空树插入结点
		if (size>0)
			return false;
		else
			root = new BiTreeNode<T>(data);//空树时插入的data成为根节点
	}
	else {
		if (node->left != NULL)
			return false;
		else
			node->left = new BiTreeNode<T>(data);//将data插入到node的左孩子
	}
	size++;//二叉树上节点的数量+1
	return true;
}
/**************************************************************************
Function:insert_right
Description:将data插入到node的右孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_right(BiTreeNode<T>* node, T data) {
	if (node == NULL) {
		if (size>0)
			return false;
		else
			root = new BiTreeNode<T>(data);
	}
	else {
		if (node->right != NULL)
			return false;
		else
			node->right = new BiTreeNode<T>(data);
	}
	size++;
	return true;
}

/**************************************************************************
Function:remove（类似于析构类的功能）
Description:删除以node为根的子树（包括node）
Input:二叉树结点node的引用
Output:删除是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::remove(BiTreeNode<T>* &node) {
	/*之所以要传入指针的引用，是因为不但要释放node指向的空间，
	同样也需要将node内保存的地址更改为NULL*/
	if (node == NULL)
		return false;
	if (remove(node->left) && remove(node->right)) {
		delete node;//释放p内地址指向的内存空间，即将其占用的内存归还给内存池
		node = NULL;//清空p内的地址
		size--;
		return true;
	}
	else
		return false;
}

/**************************************************************************
Function:preorderR、preorderI
Description:先序遍历以node为根的数，并将遍历结果保存到l中（上左右）
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/

//递归方法（先node，再node->left，最后node->right）
template <typename T>
bool BiTree<T>::preorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;//树或者列表的地址为空时出错
	l->push_back(node->data);//基本操作
	preorderR(node->left, l);//递归找到以node->left为根节点的树执行preorderR函数
	preorderR(node->right, l);
	return true;
}



//迭代方法（先node，再node->left，最后node->right）
template <typename T>
bool BiTree<T>::preorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;//定义栈s
	BiTreeNode<T>* p = node;
	while (p != NULL || !s.empty()) {
		if (p != NULL) {
			//压入栈时输出
			l->push_back(p->data);
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	return true;
}

/**************************************************************************
Function:inorderR、inorderI
Description:中序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/

//递归方法（先node->left，再node，最后node->right）
template <typename T>
bool BiTree<T>::inorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	inorderR(node->left, l);
	l->push_back(node->data);
	inorderR(node->right, l);
	return true;
}

//迭代方法（先node->left，再node，最后node->right）
template <typename T>
bool BiTree<T>::inorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = node;
	while (!s.empty() || p != NULL) {
		if (p != NULL) {
			s.push(p);
			p = p->left;//下一个该访问的结点
		}
		else {
			p = s.top();
			s.pop();//要访问就弹出
			l->push_back(p->data);//弹出栈时输出
			p = p->right;//下一个该访问的结点
		}
	}
	return true;
}

/**************************************************************************
Function:postorderR、postorderI
Description:后序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/

//递归方法（先node->right，再node->left，最后node）
template <typename T>
bool BiTree<T>::postorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	postorderR(node->left, l);
	postorderR(node->right, l);
	l->push_back(node->data);
	return true;
}

//迭代方法（先node->right，再node->left，最后node）
template <typename T>
bool BiTree<T>::postorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = node;
	BiTreeNode<T>* pre = NULL;//用于标记先前访问过的结点
	while (!s.empty() || p != NULL) {
		if (p != NULL) {
			s.push(p);
			p = p->left;
		}
		else {
			BiTreeNode<T>* right = s.top()->right;
			if (right != NULL&&right != pre) {
				p = right;
			}
			else {
				//在p==NULL且right!=NULL&&right!=pre时，说明要访问栈顶结点了
				pre = s.top();
				l->push_back(pre->data);
				s.pop();
			}
		}
	}
	return true;
}

/**************************************************************************
Function:level
Description:层次遍历以node为根的树，并将变量结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::level(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	queue<BiTreeNode<T>*> q;//借助队列
	q.push(node);
	BiTreeNode<T>* p = NULL;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		l->push_back(p->data);
		if (p->left != NULL)q.push(p->left);
		if (p->right != NULL)q.push(p->right);
	}
	return true;
}

/**************************************************************************
Function:height
Description:以node为根的树的高度
Input:二叉树结点node
Output:树的高度
***************************************************************************/
template <typename T>
int BiTree<T>::height(BiTreeNode<T>* node) {
	if (node == NULL)
		return 0;
	int left_height = height(node->left);
	int right_height = height(node->right);
	return max(left_height, right_height) + 1;
}
#endif