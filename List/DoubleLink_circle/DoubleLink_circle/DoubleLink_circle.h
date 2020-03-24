/* content: 循环双向链表*/

# ifndef _DOUBLELINK_H
# define _DOUBLELINK_H

/*双向链表的结点定义*/
template <typename T>
class Node
{
public:
	Node() {//默认无参构造函数
		prev = nullptr;
		next = nullptr;
	}
	Node(T _value, Node<T>* _prev, Node<T>* _next)
		:value(_value), prev(_prev), next(_next) {}//含参构造函进行初始化对象

public:
	T value;//数据域
	Node<T>* prev;//前驱指针域
	Node<T>* next;//后继指针域
};

/*双向链表类*/
template<typename T>
class DoubleLink
{
public:
	typedef Node<T>* pointer;//对Node<T>*进行类型重定义，可以用pointer来什么定义Node<T>* 类型的对象 
public:
	DoubleLink();
	~DoubleLink() {};
public:
	Node<T>* insert(int index, T value);
	Node<T>* insert_front(T value);
	Node<T>* insert_last(T value);

	Node<T>* del(int index);
	Node<T>* delete_front();
	Node<T>* delete_last();

	bool isEmpty();
	int size();

	T get(int index);
	T get_front();
	T get_last();
	Node<T>* getHead();

private:
	Node<T>* head;
	int count;
private:
	Node<T>* getNode(int index);
};

/* 构造函数（创建只含有头结点的空表）*/
template <typename T>
DoubleLink<T>::DoubleLink()
{
	head = new Node<T>;//调用Node的默认无参构造函数为头结点head开辟内存空间
	head->next = head;//空表头结点前驱和后继均是自己
	head->prev = head;
	count = 0;//结点数为零
};

/*获取头结点*/
template<typename T>
Node<T>* DoubleLink<T>::getHead()
{
	return head;
}

/*返回链表长度*/
template <typename T>
int DoubleLink<T>::size()
{
	return count;
}

/*查找结点（指定下标）*/
template <typename T>
Node<T>* DoubleLink<T>::getNode(int index)
{
	if (index >= count || index < 0)
		return nullptr;

	if (index <= count / 2) //如果在前半部分就从头结点往后找快速
	{
		Node<T>* node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
		return node;
	}			//在后半部分就从头结点往前找快速

	index = count - index - 1;
	Node<T>* node = head->prev;
	while (index)
	{
		node = node->prev;
		index--;
	}
	return node;//返回指定下标的结点
};

/*将新节点插到第一个位置*/
template <typename T>
Node<T>* DoubleLink<T>::insert_front(T value)
{
	Node<T>* newNode = new Node<int>(value, head, head->next);//新建一个结点，前驱指针指向头结点，后继指针指向头结点的后继节点
	head->next->prev = newNode;
	head->next = newNode;//指针调整顺序不可调换，因为若先执行phead->next_ptr = newNode建立起phead和newNode之间的连接,则phead->next_ptr ->pre_ptr即为newNode->pre_ptr=phead仍然表达的是phead和newNode之间的连接，并没有在newNode和原phead->next_ptr之间建立连接。
	count++;//结点数增加一个
	return newNode;
};

/*将新节点插到链表尾部*/
template <typename T>
Node<T>* DoubleLink<T>::insert_last(T value)
{
	Node<T> * newNode = new Node<int>(value, head->prev, head);
	head->prev->next = newNode;
	head->prev = newNode;//顺序不可换，理由同上
	count++;
	return newNode;
};

/*将节点位置插到index位置之前*/
template <typename T>
Node<T>* DoubleLink<T>::insert(int index, T value)
{
	if (index == 0)
		return insert_front(value);

	Node<T>* node = getNode(index);
	if (node == nullptr)
		return nullptr;
	Node<T>* newNode = new Node<T>(value, node->prev, node);
	node->prev->next = newNode;
	node->prev = newNode;//顺序不可换，理由同上
	count++;

	return newNode;
};

/*删除链表第一个节点并返回删除后链表第一个节点*/
template<typename T>
Node<T>* DoubleLink<T>::delete_front()
{
	if (count == 0)		//空树，返回nullptr
	{
		return nullptr;
	}
	Node<T>* node = head->next;
	head->next = node->next;
	node->next->prev = head;
	delete node;//释放指针pnode指向的内存
	count--;
	return head->next;
};

/*删除链表的末尾节点并返回删除后链表尾部元素*/
template<typename T>
Node<T>* DoubleLink<T>::delete_last()
{
	if (count == 0)
	{
		return nullptr;
	}
	Node<T>*node = head->prev;
	node->prev->next = head;
	head->prev = node->prev;
	delete node;
	count--;
	return head->prev;
}

/*删除指定位置的元素*/
template <typename T>
Node<T>* DoubleLink<T>::del(int index)
{
	if (index == 0)
		return delete_front();
	if (index == count - 1)
		return delete_last();
	if (index >= count)
		return nullptr;
	Node<T>* node = getNode(index);
	node->prev->next = node->next;
	node->next->prev = node->prev;

	Node<T>* temp = node->prev;
	delete node;
	count--;
	return temp;
};

/*判断链表是否为空*/
template <typename T>
bool DoubleLink<T>::isEmpty()
{
	return count == 0;
};

/*获取第一个节点的值*/
template<typename T>
T DoubleLink<T>::get_front()
{
	return head->next->value;
};

/*获取最后一个节点的值*/
template <typename T>
T DoubleLink<T>::get_last()
{
	return head->prev->value;
};

/*获取指定位置节点的值*/
template <typename T>
T DoubleLink<T>::get(int index)
{
	Node<T>  node = getNode(index);
	return node->value;
};
# endif