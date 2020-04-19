#ifndef MINHEAP_H
#define MINHEAP_H

/************  小顶堆定义  **************/
template <typename T>
class MinHeap {
public:
	MinHeap(int cap = 10);//构造函数
	~MinHeap();//析构函数

	bool insert(T val);//插入val元素
	bool remove(T val);//删除val元素
	void print();//打印堆
	T getTop();//获取堆顶元素
	bool (createMinHeap(T a[], int length));//根据指定数组生成最小堆

private:
	int capacity;//堆的容量，即静态数组的大小
	int size;//堆的实际大小，即数组中的有效元素个数
	T* heap;//底层存储结构为数组

private:
	void filterUp(int index);//向上渗透，即从下标为index的结点向根节点调整堆（用于插入）
	void filterDown(int begin, int end);//向下渗透，即从下标为begin的结点向end方向调整堆（用于删除）

};



/********** 构造函数 ******************/
template<typename T>
MinHeap<T>::MinHeap(int cap = 10) :capacity(cap), size(0), heap(nullptr) {//基于数组的堆容量需要提前确定
	heap = new T[capacity];
};





/************  析构函数  *******************/
template<typename T>
MinHeap<T>::~MinHeap() {
	delete[]heap;//释放数组内存空间
};



/************** 打印小顶堆  *******************/
template <typename T>
void MinHeap<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << heap[i] << "  ";//数组的元素存储顺序是按照从上到下层次遍历小顶堆来排序的
	}
};



/*************  获取堆顶元素  ***************/
template<typename T>
T MinHeap<T>::getTop() {
	if (size != 0)
		return heap[0];
};




/*************  插入元素  ***************/
template<typename T>
bool MinHeap<T>::insert(T val) {
	if (size == capacity)
		return false;
	heap[size] = val;//先将待插入的元素放在数组的尾部
	filterUp(size);//然后向上渗透找到合适位置
	size++;
	return true;
};



/******  向上渗透  **************/
template<typename T>
void MinHeap<T>::filterUp(int index) {
	T value = heap[index];//保存向上渗透开始的下标为index的点的值
	while (index > 0) {
		int indexParent = (index - 1) / 2;//找到该点的双亲
		if (value >= heap[indexParent])//直到该点的值大于双亲的值就符合要求了
			break;
		else {
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;//将值value存入新的index的下标的点处
};



/****************  删除元素  ***********/
template<typename T>
bool MinHeap<T>::remove(T val){
	if (size == 0)
		return false;
	int index;
	for (index = 0; index < size; index++) {
		if (heap[index] == val)
			break;
	}
	if (index == size)
		return false;
	heap[index] = heap[size - 1];
	filterDown(index, size--);
	return true;
};




/************ 向下渗透  ****************/
template<typename T>
void MinHeap<T>::filterDown(int current, int end) {
	int child = current * 2 - 1;
	T value = heap[current];
	while (child <= end) {
		if (child<end && heap[child]>heap[child + 1])
			child++;
		if (value < heap[child])
			break;
		else {
			heap[current] = heap[child];
			current = child;
			child = child * 2 + 1;

		}
	 }
	heap[current] = value;
};



/**************** 根据指定数组创建最小堆  **************/
template<typename T>
bool MinHeap<T>::createMinHeap(T a[], int length) {
	if (length > capacity)
		return false;
	for (int i = 0; i < length; i++) {
		insert(a[i]);
	}
	return true;
};




#endif
