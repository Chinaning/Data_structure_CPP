/*
* 循环队列
* Chinaning
* date: 2020/03/23
*
*/
#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H

template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);//队列的最大长度一定（因为基于静态数组）
	~LoopQueue();
public:
	bool isEmpty();		//队列的判空
	int size();			//队列的大小
	bool push(T t);		//入队
	bool pop();			//出队
	T front();			//队首元素

private:
	int capacity;//队列容量
	int begin;//队首索引
	int end;//队尾索引
	T*  queue;
};





/***********************  构造函数（生成容量一定的空队列）  **********************************/
template<typename T>
LoopQueue<T>::LoopQueue(int c = 10)//调用含参构造函数
	: capacity(c), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];//采用存储结构为静态数组（数组的大小需要大于0）
};






/***********************  析构函数（删除队列指针及为队列分配的内存空间）  **********************************/
template<typename T>
LoopQueue<T>::~LoopQueue()
{
	delete[]queue;
	queue = nullptr;
}







/***********************  判断队列是否为空  **********************************/
template <typename T>
bool LoopQueue<T>::isEmpty()
{
	if (begin == end)
		return true;
	return false;
};




/***********************  队列长度  **********************************/
template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity; //计算队列长度
};






/***********************  入队  **********************************/
template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin) //判断队列是否已满
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};





/***********************  出队  **********************************/
template <typename T>
bool LoopQueue<T>::pop()
{
	if (end == begin) //判断队列是否为空
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
};




/***********************  返回队首元素  **********************************/
template <typename T>
T LoopQueue<T>::front()
{
	if (end == begin)
	{
		return false;
	}
	return queue[begin];
};

# endif


