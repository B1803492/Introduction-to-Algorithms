#include <iostream>
using namespace std;
const int N = 9;

void bubble_sort(int *p, int n)
{
	for (int i = 0;i < n;++i)
	{
		for (int j = n-1;j >0;--j)
		{
			if (p[j] < p[j - 1])
			{
				int temp = p[j - 1];
				p[j - 1] = p[j];
				p[j] = temp;
			}
		}
	}
}

int main()
{
	int a[N] = { 1,34,53,123,52,52,6,62,23 };

	bubble_sort(a, N);

	for (auto c : a)
		cout << c << " ";

	cout << endl;
	return 0;

}
