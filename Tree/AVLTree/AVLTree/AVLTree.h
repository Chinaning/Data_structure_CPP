#ifndef AVLTree_H
#define AVLTree_H

/********************** AVL树结点定义 ***************************/
template<typename T>
class TreeNode
{
public:
	T data;//值
	int height;//高度
	unsigned int freq;//频率
	TreeNode* left;//指向左儿子的地址
	TreeNode* right;//指向右儿子的地址
public:
	TreeNode() :left(NULL), right(NULL), freq(1), height(0) {}
};





/*******************  AVL树类的属性和方法声明(接口）***********************/
template<typename T>
class AVLTree
{
private://实现方法定义私有成员函数，只能由本类的成员函数访问，不可被外部成员访问，也不可被类的对象直接访问
	TreeNode<T>* root;//根节点
	void insertpri(TreeNode<T>* &node, T x);//插入（在以node结点为根节点的AVL树中插入值为x的结点）
	TreeNode<T>* findpri(TreeNode<T>* node, T x);//查找（在以node结点为根节点的AVL树中查找值为x的结点）
	void insubtree(TreeNode<T>* node);//中序遍历
	void Deletepri(TreeNode<T>* &node, T x);//删除
	int height(TreeNode<T>* node);//求树的高度
	void LL(TreeNode<T>* &k2);//左左情况下的旋转
	void RR(TreeNode<T>* &k2);//右右情况下的旋转
	void LR(TreeNode<T>* &k3);//左右情况下的旋转
	void RL(TreeNode<T>* &k3);//右左情况下的旋转
	int Max(int cmpa, int cmpb);//求最大值

public://将各种操作的实现方法封装后用public接口供外部和类的对象访问
	AVLTree() :root(NULL) {}
	void insert(T x);//插入接口
	TreeNode<T>* find(T x);//查找接口
	void Delete(T x);//删除接口
	void traversal();//遍历接口

};




/*******************  AVL树类的方法定义 ***********************/

//计算节点的高度
template<typename T>
int AVLTree<T>::height(TreeNode<T>* node)
{
	if (node != NULL)
		return node->height;
	return -1;
}



//求最大值
template<typename T>
int AVLTree<T>::Max(int cmpa, int cmpb)
{
	return cmpa>cmpb ? cmpa : cmpb;
}


//左左情况下的旋转
template<typename T>
void AVLTree<T>::LL(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->left;//找到根节点k2的左孩子结点

	k2->left = k1->right;
	k1->right = k2;//调整

	k2->height = Max(height(k2->left), height(k2->right)) + 1;
	k1->height = Max(height(k1->left), k2->height) + 1;
}




//右右情况下的旋转
template<typename T>
void AVLTree<T>::RR(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->right;

	k2->right = k1->left;
	k1->left = k2;

	k2->height = Max(height(k2->left), height(k2->right)) + 1;
	k1->height = Max(height(k1->right), k2->height) + 1;
}



//左右情况的旋转
template<typename T>
void AVLTree<T>::LR(TreeNode<T>* &k3)
{
	RR(k3->left);
	LL(k3);
}



//右左情况的旋转
template<typename T>
void AVLTree<T>::RL(TreeNode<T>* &k3)
{
	LL(k3->right);
	RR(k3);
}



//插入
template<typename T>
void AVLTree<T>::insertpri(TreeNode<T>* &node, T x)
{
	if (node == NULL)//如果节点为空,就在此节点处加入x信息
	{
		node = new TreeNode<T>();
		node->data = x;
		return;
	}
	if (node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
	{
		insertpri(node->left, x);
		if (2 == height(node->left) - height(node->right))//如果高度之差为2的话就失去了平衡,需要旋转
			if (x<node->left->data)
				LL(node);
			else
				LR(node);
	}
	else if (node->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
	{
		insertpri(node->right, x);
		if (2 == height(node->right) - height(node->left))//如果高度之差为2的话就失去了平衡,需要旋转
			if (x>node->right->data)
				RR(node);
			else
				RL(node);
	}
	else ++(node->freq);//如果相等,就把频率加1
	node->height = Max(height(node->left), height(node->right));
}
//插入接口
template<typename T>
void AVLTree<T>::insert(T x)
{
	insertpri(root, x);
}


//查找
template<typename T>
TreeNode<T>* AVLTree<T>::findpri(TreeNode<T>* node, T x)
{
	if (node == NULL)//如果节点为空说明没找到,返回NULL
	{
		return NULL;
	}
	if (node->data>x)//如果x小于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->left, x);
	}
	else if (node->data<x)//如果x大于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->right, x);
	}
	else return node;//如果相等,就找到了此节点
}
//查找接口
template<class T>
TreeNode<T>* AVLTree<T>::find(T x)
{
	return findpri(root, x);
}



//删除
template<typename T>
void AVLTree<T>::Deletepri(TreeNode<T>* &node, T x)
{
	if (node == NULL) return;//没有找到值是x的节点
	if (x < node->data)
	{
		Deletepri(node->left, x);//如果x小于节点的值,就继续在节点的左子树中删除x
		if (2 == height(node->right) - height(node->left))//如果高度之差为2的话就失去了平衡,需要旋转
			if (node->right->left != NULL && (height(node->right->left)>height(node->right->right)))
				RL(node);
			else
				RR(node);
	}

	else if (x > node->data)
	{
		Deletepri(node->right, x);//如果x大于节点的值,就继续在节点的右子树中删除x
		if (2 == height(node->left) - height(node->right))
			if (node->left->right != NULL && (height(node->left->right)>height(node->left->left)))
				LR(node);
			else
				LL(node);
	}

	else//如果相等,此节点就是要删除的节点
	{
		if (node->left&&node->right)//此节点有两个儿子
		{
			TreeNode<T>* temp = node->right;//temp指向节点的右儿子
			while (temp->left != NULL) temp = temp->left;//找到右子树中值最小的节点
														 //把右子树中最小节点的值赋值给本节点
			node->data = temp->data;
			node->freq = temp->freq;
			Deletepri(node->right, temp->data);//删除右子树中最小值的节点
			if (2 == height(node->left) - height(node->right))
			{
				if (node->left->right != NULL && (height(node->left->right)>height(node->left->left)))
					LR(node);
				else
					LL(node);
			}
		}
		else//此节点有1个或0个儿子
		{
			TreeNode<T>* temp = node;
			if (node->left == NULL)//有右儿子或者没有儿子
				node = node->right;
			else if (node->right == NULL)//有左儿子
				node = node->left;
			delete(temp);
			temp = NULL;
		}
	}
	if (node == NULL) return;
	node->height = Max(height(node->left), height(node->right)) + 1;
	return;
}
//删除接口
template<typename T>
void AVLTree<T>::Delete(T x)
{
	Deletepri(root, x);
}


//中序遍历函数
template<typename T>
void AVLTree<T>::insubtree(TreeNode<T>* node)
{
	if (node == NULL) return;
	insubtree(node->left);//先遍历左子树
	cout << node->data << " ";//输出根节点
	insubtree(node->right);//再遍历右子树
}
//中序遍历接口
template<typename T>
void AVLTree<T>::traversal()
{
	insubtree(root);
}

#endif
