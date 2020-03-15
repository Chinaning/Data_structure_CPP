#include <iostream>
#include "DoubleLink.h"
using namespace std;

int main()
{
	DoubleLink<float> ls1;
	ls1.add_last(2);
	ls1.add_last(3);
	ls1.add_last(6);
	ls1.add_last(3);
	ls1.addin(2, 9);
	ls1.add_front(7);
	ls1.show();
	float a=ls1.find(1);
	cout << a << endl;
	ls1.remove(6);
	ls1.show();
	DoubleLink<float> ls2(ls1);
	ls2.resShow();
	std::cout << ls2.size() << std::endl;
	std::cout << ls2.find(00) << std::endl;
	ls2.remove(6);
	ls1.resShow();
        ls2.show();
        system("pause");
        return 0;
}
