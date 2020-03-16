#include<iostream>
#include"SingleLink.h"
using namespace std;

int main() {
	SingleLink<int> list;
	list.isEmpty();
	list.add_front(2);
	list.isEmpty();
	list.add_front(1);
	list.add_front(2);
	list.add_front(2);
	list.add_front(3);
	list.add_front(4);
	list.add_front(2);
	list.add_last(0, 9);
	list.add(1, 5);
	list.del_index(0);
	list.del_value(2);
	list.show();
	getchar();
	return 0;

}




