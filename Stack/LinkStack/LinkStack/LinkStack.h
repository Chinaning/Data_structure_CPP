#ifndef LINKSTACK_H
#define LINKSTACK_H

/*链表节点结构*/
template <typename T>
class Node {
public:
	T value;
	Node<T>*next;
public:
	Node() {//默认无参构造函数
		next = nullptr;
	}
	Node(T _value, Node<T>* _next) :value(_value), next(_next) {};//含参构造函数
};



/*栈的抽象数据结构*/
template <typename T>
class LinkStack
{
public:
	LinkStack();	//声明构造函数，默认的栈容量为10
	T top();		//获取栈顶元素
	void push(T t);		//压栈操作
	T pop();		//弹栈操作
	bool isEmpty();		//判空操作
	int size();
private:
	int count;			//栈的元素数量
	Node<T>* head;			//底层为链表
};


/*构造函数（生成只含有一个空的头结点的空栈）*/
template<typename T>
LinkStack<T>::LinkStack() {
	head = new Node<T>;//调用Node的默认无参构造函数
	count = 0;
}



/*返回栈的大小*/
template <typename T>
int LinkStack<T>::size()
{
	return count;
};



/*栈的判空操作*/
template <typename T>
bool LinkStack<T>::isEmpty()
{
	return count == 0;
};



/*插入元素(始终在head后面插入）*/
template<typename T>
void LinkStack<T>::push(T VALUE)
{
	Node <T> *node = new  Node<T>(VALUE, head->next);
	head->next = node;
	count++;
};


/*弹栈*/
template <typename T>
T LinkStack<T>::pop()
{
	if (head->next != nullptr) //栈空判断
	{
		Node<T>* node = head->next;//栈顶要弹出的结点
		head->next = node->next;
		T value = node->value;
		delete node;
		node = nullptr;
		count--;
		return value;
	}
	else return nullptr;
};



/*获取栈顶元素*/
template <typename T>
T LinkStack<T>::top()
{
	if (head->next != nullptr)
		return head->next->value;
	else return nullptr;
};



#endif


