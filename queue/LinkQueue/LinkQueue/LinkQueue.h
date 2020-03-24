/*
*基于单链表实现的队列
*Chinaning
*2020/03/24
*/

# ifndef LINKQUEUE_H
# define LINKQUEUE_H



/*****************  定义链表结点  ********************/
template<typename T>
class Node
{
public:
	Node(T t) :value(t), next(nullptr) {}//自定义含参构造函数
	Node()=default;//声明默认无参构造函数并定义为default,不然如有自定义的构造函数，系统就不会自动生成默认构造函数
public:
	T value;
	Node<T> * next;
};


/*****************  定义单链表队列  ********************/
template<typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();

	bool isEmpty();
	int size();
	bool pop();
	void push(T t);
	T front();

private:
	Node<T>* head;//指向头结点的指针（头结点不存储元素，作为标点）
	Node<T>* pend;//指向尾结点的指针（尾结点是存储元素的实际最后一个结点）
	int count;
};


/*****************  构造函数  ********************/
template<typename T>
LinkQueue<T>::LinkQueue()
	:head(nullptr), pend(nullptr), count(0)
{
	head = new Node<T>();
	pend = head;//头指针和尾指针都指向同一个结点
	count = 0;
};






/*****************  析构函数  ********************/
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	while (head->next != nullptr)
	{
		Node<T> * pnode = head;
		head = head->next;
	}
};





/*****************  判断队列是否为空  ********************/
template <typename T>
bool LinkQueue<T>::isEmpty()
{
	return count == 0;
};



/*****************  队列大小  ********************/
template <typename T>
int LinkQueue<T>::size()
{
	return count;
};






/*****************  队尾入队  ********************/
template <typename T>
void LinkQueue<T>::push(T t)
{
	Node<T>* pnode = new Node<T>(t);
	pend->next = pnode;
	pend = pnode;//新入队的结点作为尾结点
	count++;
};





/*****************  队首出队  ********************/
template <typename T>
bool LinkQueue<T>::pop()
{
	if (count == 0)
		return false;
	Node<T>* pnode = head->next;
	head->next = head->next->next;
	delete pnode;
	pnode = nullptr;
	count--;
	return true;
};

/*****************  获取队首元素  ********************/
template<typename T>
T LinkQueue<T>::front()
{
	return head->next->value;
};

# endif
