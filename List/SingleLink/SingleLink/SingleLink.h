#ifndef SINGLELINK_H
#define SINGLELINK_H
#include<vector>

using namespace std;

/****************** 结点定义 ********************/

template<typename T>
class Node {
public:
	T value;//值
	Node<T>*next;//指针
public:
	Node() { next = nullptr; };
	Node(T _value, Node<T>*_next) :value(_value), next(_next) {}
};



/***************** 链表定义（接口） **********************/

template<typename T>
class SingleLink {
private://私有成员只能成员函数调用
	Node<T>*head;
	int count;
public:
	SingleLink();//构造函数（生成空表）
	Node<T>*find_index(int index);//查找下标为index的结点并返回指向结点的指针
	vector<int>*find_value(T value);//查找值为value的结点并返回指向结点向量的指针
	int find_value_aid(T VALUE);//查找值为value的结点并返回个数
	void add_front(T value);//前插
	void add_last(int index, T value);//后插
	void add(int index, T value);//下标index后插入
	void del_index(int index);//删除下标index的结点
	void del_value(T VALUE);//删除值为VALUE的结点
	int size();//链表长度
	bool isEmpty();//是否为空
	void show();//输出链表
	
};





/***************  构造函数（生成空表）  ******************/

template<typename T>
SingleLink<T>::SingleLink() {
	head = new Node<T>;//调用Node类的默认无参构造函数，只给指针赋值nullptr
	count = 0;
}





/***************************  查找  *******************************/

//查找下标为index的结点并返回指向该结点指针
template<typename T>
Node<T>*SingleLink<T>::find_index(int index) {
	if (index < 0 || index >= count) return nullptr;
	Node<T>*node = head->next;
	while (index) {
		node = node->next;
		index--;
	}
	return node;
}

//查找值为VALUE的结点并返回结点的index向量指针
template<typename T>
vector<int>* SingleLink<T>::find_value(T VALUE) {
	vector<int> *VECTOR = new vector<int>();
	Node<T>*node = head->next;
	int index = 0;
	int num = 0;
	while (node != nullptr) {
		if (node->value = VALUE) {
			VECTOR->push_back(index);
			num++;
		};
		node = node->next;
		index++;
	}
	return VECTOR;
}

//查找值为VALUE的结点并返回结点个数
template<typename T>
int SingleLink<T>::find_value_aid(T VALUE) {
	vector<int> VECTOR;
	Node<T>*node = head->next;
	int index = 0;
	int num = 0;
	while (node != nullptr) {
		if (node->value = VALUE) {
			VECTOR.push_back(index);
			num++;
		};
		node = node->next;
		index++;
	}
	return num;
}








/*****************  插入  ********************************/

//最前面插入值为value的结点
template<typename T>
void SingleLink<T>::add_front(T value) {
	Node<T>* node = new Node<T>(value, head->next);
	head->next = node;
	count++;
	return;
}

//下标index的结点后插入值为value的结点(index=count-1)
template<typename T>
void SingleLink<T>::add(int index, T value) {
	if (index < 0 || index >= count) return;
	Node<T>*index_node = find_index(index);//注意是在index结点后插入，如果是index结点前插入需要find(index-1)操作需要改变
	Node<T>*node = new Node<T>(value, index_node->next);
	index_node->next = node;
	count++;
	return;
}

//最后面插入值为value的结点
template<typename T>
void SingleLink<T>::add_last(int index, T value) {
	add(index, value);
	return;
}






/***********************  删除  ***************************************/

//删除下标为index的结点
template<typename T>
void SingleLink<T>::del_index(int index) {
	if (index < 0 || index >= count) return;
	if (index == 0) {
		Node<T>*temp = head->next;//新建一个临时节点存储未改变的head->next将其删除
		head->next = head->next->next;
		delete temp;
		temp = nullptr;
		count--;
		return;
	}
	Node<T>*node = find_index(index);//找到下标为index的结点
	Node<T>*node_front = find_index(index - 1);//找到下标为index-1的结点
	node_front->next = node->next;//将index-1结点的指针指向index->next
	delete node;
	node = nullptr;
	count--;
	return;

}

//删除值为value的结点（可能不止一个节点的值为VALUE）
template <typename T>
void SingleLink<T>::del_value(T VALUE) {
	if (isEmpty()) return;
	Node<T>*node_front = head;
	Node<T>*node = node_front->next;
	while (node != nullptr) {
		Node<T>*temp = node;//新建一个临时节点存储未改变的node将其删除
		if (node->value == VALUE) {
			node_front->next = node->next;
			node = node->next;
			delete temp;
			temp = nullptr;
			count--;

		}
		else {
			node_front = node_front->next;
			node = node->next;
		}


	}
	return;

}







/***********************  输出列表的value  *************************/

//顺序输出列表值并输出结点个数
template<typename T>
void SingleLink<T>::show() {
	Node<T>*node = head->next;
	while (node != nullptr) {
		cout << node->value << "  ";
		node = node->next;
	}
	cout << endl << count << endl;
	return;
}






/***************   判断链表是否为空  **********************************/
template<typename T>
bool SingleLink<T>::isEmpty() {
	if (count == 0) {
		cout << "空链表" << endl;
		return true;
	}
	else {
		cout << "不是空链表" << endl;
		return false;
	}
}




/***********************  链表长度  ************************************/

template<typename T>
int SingleLink<T>::size() {
	return count;
}


#endif


