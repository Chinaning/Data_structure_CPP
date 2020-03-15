#ifndef DOUBLELINK_H
#define DOUBLELINK_H
#include <iostream>

/********** 结点定义 *************/

template <typename T>
class Node
{
public://函数
	Node() = default;
	Node(T _data, Node<T>*_prev, Node<T>* _next)//含参构造函数初始化对象
		:value(_data), prev(_prev), next(_next) { }
public://数据
	T value;//值
	Node<T> *prev;//指向直接前驱的指针（前驱指针）
	Node<T> *next;//指向直接后继的指针（后继指针）
};





/********* 链表定义（接口） ***********/

template <class T>
class DoubleLink
{
public:
	DoubleLink();//默认构造函数
	DoubleLink(const DoubleLink& ln);//拷贝构造函数
	~DoubleLink();//析构函数
	void add_front(T e);//向链表最前面插入值value的结点
	void add_last(T e);//向链表最后插入值value的结点
	void addin(int index, T value);//向链表下标index前插入值value的结点
	void ascSort();//升序排序
	void remove(T index);//删除某个结点
	Node<T>* pfind(int index);//查找结点并返回结点指针
	T find(int index);//查找结点并返回结点的value
	bool isEmpty();//判断是否为空
	int size();//链表长度
	void show();//输出链表
	void resShow();//反向输出链表
	void removeAll();//删除全部结点
private:
	Node<T> *head;//头结点
	Node<T> *tail;//尾结点
	int count;//链表长度
};





/******** 默认构造函数（生成只含有头结点和尾结点的链表） **************/

template <typename T>
DoubleLink<T>::DoubleLink()
{
	head = new Node<T>(0, nullptr, nullptr);//为头结点申请内存空间
	tail = new Node<T>(0, nullptr, nullptr);//为尾结点申请内存空间
	//空的双向链表需要头结点和尾结点的四个指针关系
	head->next = tail;//头结点后继是尾结点
	head->prev = nullptr;//头结点的前驱指针为空
	tail->next = nullptr;//尾结点的后继指针为空
	tail->prev = head;//尾结点前驱是头结点
	count = 0;//空的双向链表长度为0
}





/********* 拷贝构造函数（已有对象给新对象赋值）**********/

template <typename T>
DoubleLink<T>::DoubleLink(const DoubleLink &ln)
{
	head = new Node<T>;
	head->prev = nullptr;
	tail = new Node<T>;
	head->next = tail;
	tail->prev = head;
	count = 0;
	Node<T>* temp = ln.head;
	while (temp->next != ln.tail)
	{
		//将尾结点赋值后新建尾结点
		temp = temp->next;
		tail->value = temp->value;
		Node<T> *node = new Node<T>;
		node->prev = tail;
		tail->next = node;
		tail = node;
		count++;
	}
	tail->next = nullptr;
}




/************ 插入 ********************/

//向链表前端添加数据value
template<typename T>
void DoubleLink<T>::add_front(T value)
{
	Node<T>*node = new Node<T>(value, head, head->next);
	head->next->prev = node;
	head->next = node;
	count++;
	return;
}
//向链表末尾添加数据value
template <typename T>
void DoubleLink<T>::add_last(T value)
{
	Node<T>* node = new Node<T>(value, tail->prev, tail);
	/*新建指针并且需要为指针所指的对象执行操作必须要为其分配内存空间，
	在分配空间的同时可以对空间内容进行初始化。
	插入结点node总共需要确定四个指针关系和结点的value值，四个指针关系分别是：
	node->prev,node->prev->next,node->next,node->next->prev,
	初始化过程中value值和node->prev和node->next两个指针已经确定，剩余两个指针通过下列
	语句执行*/
	//等同于：Node<T> node (VALUE, tail->prev, tail);
	tail->prev->next = node;
	tail->prev = node;
	count++;

}
//在下标为intex结点之前插入VALUE
template<typename T>
void DoubleLink<T>::addin(int index, T VALUE) {
	if (index >= count || index < 0) return;
	Node<T>* index_node = pfind(index);
	Node<T>* node = new Node<T>(VALUE, index_node->prev, index_node);
	index_node->prev->next = node;
	index_node->prev = node;
	count++;
	return;
}



/***************** 查找 *********************/

//查找结点(返回指针）
template <typename T>
Node<T>* DoubleLink<T>::pfind(int index)
{
	Node<T> *node = new Node<T>;
	if (count == 0)
	{
		cout << "List is empty";
		return nullptr;
	}
	if (index >= count || index < 0)
	{
		cout << "Out of bounds";
		return nullptr;
	}


	if (index <= count / 2)
	{
		node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
	}
	else {
		index = count - index - 1;
		node = tail->prev;
		while (index)
		{
			node = node->prev;
		}
	}
	return node;
}


//查找结点(返回结点的值）
template <typename T>
T DoubleLink<T>::find(int index)
{
	Node<T> *node = new Node<T>;
	if (count == 0)
	{
		cout << "List is empty";
		return NULL;
	}
	if (index >= count || index < 0)
	{
		cout << "Out of bounds";
		return NULL;
	}


	if (index <= count / 2)
	{
		node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
	}
	else {
		index = count - index - 1;
		node = tail->prev;
		while (index)
		{
			node = node->prev;
		}
	}
	return node->value;
	//return (*node).value;
}




/***************** 删除*********************/

//删除结点(指定VALUE)
template <typename T>
void DoubleLink<T>::remove(T VALUE)
{
	if (count == 0)
	{
		cout << "List is empty";
		return;
	}
	Node<T> *node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		if (node->value == VALUE)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;

			delete node;
			node = nullptr;
			count--;
			return;
		}
	}
}
//删除所有结点(最终只剩头结点head和尾结点tail)
template <typename T>
void DoubleLink<T>::removeAll()
{
	if (count == 0)
	{
		return;
	}
	Node<T> *node = head->next;
	while (node != tail)
	{
		Node<T>* temp = node;
		node = node->next;
		delete temp;//释放指针temp指向的内存空间
		temp = nullptr;//删除指针变量内容
	}
	head->next = tail;
	tail->prev = head;
	count = 0;
}




/*************** 排序 *********************/

//升序排序（只将value排序，选择排序思想）
template <typename T>
void DoubleLink<T>::ascSort()
{
	if (count <= 1) return;
	Node<T> *node = head->next;
	for (int i = 0; i < count - 1; i++)
	{
		Node<T> *comp = node->next;
		for (int j = i + 1; j < count; j++)
		{
			if (node->value > comp->value)
			{
				T temp = temp->value;//交换
				temp->value = node->value;
				node->value = temp;
			}
			comp = comp->next;
		}
		node = node->next;
	}
}





/*******************  判断是否为空 **********************/
template <typename T>
bool DoubleLink<T>::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else {
		return false;
	}
}





/***********************  链表长度  ***********************/
template <typename T>
int DoubleLink<T>::size()
{
	return count;
}






/********************  输出链表  ************************/
//顺序输出链表
template <typename T>
void DoubleLink<T>::show()
{
	if (count == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node<T> *node = head->next;
	while (node != tail)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
	std::cout << std::endl;
}
//反向输出链表
template <typename T>
void DoubleLink<T>::resShow()
{
	if (count == 0) return;
	Node<T> *node = tail->prev;
	while (node != head)
	{
		std::cout << node->value << " ";
		node = node->prev;
	}
	std::cout << std::endl;
}





/*************************  析构函数  ***************************/
template <typename T>
DoubleLink<T>::~DoubleLink()
{
	if (count == 0)
	{
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr)
	{
		Node<T> *node = head;
		head = head->next;
		delete node;
	}
	delete head;
	head = nullptr;
}



#endif 
