// heap_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//函数实现最大堆功能

#include <iostream>
using namespace std;

void adjust_heap(int* a, int node, int size)
{
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	int max = node;
	if (left < size && a[left] > a[max])
		max = left;
	if (right < size && a[right] > a[max])
		max = right;
	if (max != node)
	{
		swap(a[max], a[node]);
		adjust_heap(a, max, size);
	}
}

void make_heap(int* a, int len)
{
	for (int i = len/2-1; i>=0;i--)
	{
		adjust_heap(a, i, len);
	}
}

void heap_sort(int* a, int len)		//每次将根节点与待排堆的最后一个节点交换位置
{
	for (int i = len - 1;i >= 0;i--)
	{
		swap(a[0], a[i]);
		adjust_heap(a, 0, i);
	}
}

int main()
{

	int a1[10] = { 3, 2, 7, 4, 2, -999, -21, 99, 0, 9 };
	int len = sizeof(a1) / sizeof(int);

	for (int i = 0;i < len;++i)
		cout << a1[i] << " ";
	cout << endl;

	make_heap(a1, len);
	for (int i = 0;i < len;++i)
		cout << a1[i] << " ";
	cout << endl;

	heap_sort(a1, len);

	for (int i = 0;i < len;++i)
		cout << a1[i] << " ";
	cout << endl;

	return 0;
}
