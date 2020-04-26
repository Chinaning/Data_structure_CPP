#ifndef SEARCH_H
#define SEARCH_H
#include<vector>
using namespace std;

/********************************  顺序查找  *************************************/
class Sequential {

public:
	int Sequential_search(vector<int> &a, int value, int n)
	{

		for (int i = 0; i < n; i++)
			if (a[i] == value)
				return i;
		return -1;
	}
};



/********************************  二分查找（折半查找）  *************************************/
class Binary {
public:
	int Binary_search(vector<int>& a, int value, int n) {
		int low, high, mid;
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] == value)
				return mid;
			if (a[mid] > value)
				high = mid - 1;
			if (a[mid] < value)
				low = mid + 1;
		}
		return -1;

	}
};

/********************************  插值查找  *************************************/
class Interpolation {
public:
	int Interpolation_search(vector<int>&b, int value, int n) {
		int low = 0;//低位下标
		int high = n - 1;//高位下标
		int mid;//中间值下标
		while (low <= high)
		{
			mid = (high - low)*(value - b[low]) / (b[high] -b[low]);
			//插值(根据数组元素的线性增长关系定mid），等于一种更加智能的二分查找
			if (value < b[mid])
			{
				high = mid - 1;
			}
			else if (value > b[mid])
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}
};


/********************************  斐波那契查找  *************************************/
class FibonacciSearch {
public:
	const int max_size = 20;
public:
	void Fibonacci(vector<int>& F,int size)
	{
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i<size; ++i)
			F[i] = F[i - 1] + F[i - 2];
	}

	int Fibonacci_search(vector<int>&a, int value, int n)
	{
		
		int low = 0, k = 0;
		int high = n - 1;
		vector<int>F(max_size);
		Fibonacci(F,max_size);       //构造一个斐波那契数组F 
		while (n > F[k] - 1)   //计算n位于斐波那契数列的位置
			++k;

		//int* temp = new int[F[k] - 1];    //将数组a扩展到F[k]-1的长度
	//	memcpy(temp, a, n * sizeof(int));

		for (int i = n; i < F[k] - 1; ++i)
			a.push_back( a[n - 1]);//补充所查数组元素的个数n至F[k] - 1个

		while (low <= high)
		{
			int mid = low + F[k - 1] - 1;
			if (value < a[mid])
			{
				high = mid - 1;
				k -= 1;
			}
			else if (value > a[mid])
			{
				low = mid + 1;
				k -= 2;
			}
			else
			{
				if (mid < n) return mid; //若相等则说明mid即为查找到的位置
				else        return n - 1; //若mid>=n则说明是扩展的数值,返回n-1
			}
		}
		return -1;
	}
	
};

/********************************  分块查找  *************************************/
class Block {
public:
	struct blocking//结构体用来给数组分块
	{
		int key;
		int start;
		int end;
	}blocking[2];

	int Block_search(vector<int>&a,int key,int n)
	{
		int j=0;
		for (int i = 0; i<2; i++)
		{
			blocking[i].start = j ;//确定每个块的起始位置
			blocking[i].end = j+3 ;//确定每个块的结束位置
			blocking[i].key = a[j+3];//确定每个块范围中的元素最大值
			j = j + 4;
		}
		int num = 0;
		while (num<2 && key>blocking[num].key)//确定在哪个块中
			num++;
		if (num >= 2)//大于分得的块数返回-1
			return -1;
		j = blocking[num].start;//j等于块范围的起始值
		while (j <= blocking[num].end && a[j] != key)//在确定的块内进行查找
			j++;
		if (j>blocking[num].end)//如果大于块范围的结束值 则说明没有要查找的数 j置0
			j= -1;
		return j;
		
	}
};


#endif // !SEARCH_H
