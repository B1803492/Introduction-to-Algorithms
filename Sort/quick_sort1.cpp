//快速排序均是递归实现，进行一次快排找出key值，算法有多种。
//左右指针法；挖坑法；前后指针法

#include "pch.h"
#include <iostream>
using namespace std;

int dig_hole(int* p, int left, int right)
{
	int key = p[right];
	while (left < right)
	{
		while (left < right && p[left] <= key)
		{
			left++;
		}
		p[right] = p[left];
		while (right > left && p[right] >= key)
		{
			right--;
		}
		p[left] = p[right];
	}
	p[right] = key;

	return right;
}

int left_right_pointer(int* p, int left, int right)
{
	int &key = p[right];	//为什么要加&，不加&输出错误
	while (left < right)
	{
		while (left < right && p[left] <= key)
		{
			left++;
		}
		while (left < right && p[right] >= key)
		{
			right--;
		}
		swap(p[left], p[right]);
	}
	swap(p[left], key);
	return left;
}

int front_back_pointer(int* p, int left, int right)
{
	if (left < right)
	{
		int &key = p[right];
		int cur = left;
		int pre = cur - 1;
		while (cur < right)
		{
			while (p[cur] <= key && ++pre != cur)
			{
				swap(p[cur], p[pre]);
			}
			++cur;
		}
		swap(p[++pre], key);
		return pre;
	}
	return -1;

}



void quick_sort(int* p, int a, int b)
{
	if (a < b)
	{
		//int q = dig_hole(p, a, b);
		//int q = left_right_pointer(p, a, b);
		int q = front_back_pointer(p, a, b);

		quick_sort(p, a, q - 1);
		quick_sort(p, q + 1, b);
	}
}

int main()
{
	int num[] = { 4,1,7,6,9,2,8,0,3,5 };
	for (auto c : num)
		cout << c << " ";
	cout << endl;

	quick_sort(num, 0, 9);

	for (auto c : num)
		cout << c << " ";
	cout << endl;

	return 0;
}
