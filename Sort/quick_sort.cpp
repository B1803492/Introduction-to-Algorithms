//只移动一端，从左向右移动
//一般用第一个或最后一个数作为key值，这里用第一个

#include <iostream>
using namespace std;

int partition(int* p, int a, int b)
{
	int x = p[b];
	int i = a - 1;
	for (int j = a; j < b; j++)
	{
		if (p[j] <= x)
		{
			i++;
			swap(p[i], p[j]);
		}
	}
	swap(p[i + 1], p[b]);

	return (i + 1);
}

void quick_sort(int* p, int a, int b)
{
	if (a < b)
	{
		int q = partition(p, a, b);
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
