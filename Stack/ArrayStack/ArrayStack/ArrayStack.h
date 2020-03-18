/*

*Author :Chinaning
*date：2020/03/18
*基于数组的栈实现

*/


# ifndef ARRAYSTACK_H
# define ARRAYSTACK_H

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s = 10);	//声明构造函数，默认的栈容量为10
	~ArrayStack();//声明析构函数

public:
	T top();		//获取栈顶元素
	void push(T t);		//压栈操作
	T pop();		//弹栈操作
	bool isEmpty();		//判空操作
	int size();		//求栈的大小

private:
	int count;			//栈的元素数量
	int capacity;		//栈的容量
	T * array;			//底层为数组
};





/******************  构造函数  *******************/
template <typename T>
ArrayStack<T>::ArrayStack(int s = 10)
	:count(0), capacity(s), array(nullptr)
{
	array = new T[capacity];//为数组指针指向的数组对象分配内存空间并初始化数组容量
};




/****************  析构函数  *********************/
template<typename T>
ArrayStack<T>::~ArrayStack()
{
	if (array)
	{
		delete[]array;
		//释放new分配的数组指针指向的数组内存
		//针对简单类型，等同于：delete array;
		array = nullptr;
	}
};






/***************  栈的判空操作  *********************/
template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0; //栈元素为0时为栈空
};






/*****************  返回栈的大小  **********************/
template <typename  T>
int ArrayStack<T>::size()
{
	return count;
};






/***************  插入元素  ****************************/
template <typename T>
void ArrayStack<T>::push(T t)
{
	if (count != capacity)	//先判断是否栈满
	{
		array[count++] = t;
	}
};






/***************  弹栈  ***********************/
template <typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)	//先判断是否是空栈
	{
		return array[--count];
	}
};






/****************  获取栈顶元素  ******************/
template <typename T>
T ArrayStack<T>::top()
{
	if (count != 0)
	{
		return array[count - 1];
	}
};



# endif 

