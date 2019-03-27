#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int N = 10;

int main()
{
	int a[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % N;
		cout << a[i] << " ";
	}
	cout << endl;

	for (int j = 2; j < N; j++)
	{
		int key = a[j];
		for (int i = j - 1; i >= 0; i--)
		{
			if (a[i] > a[i+1])		//每次比较相邻两项，如果左边较大，则交换值
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
