#include <iostream>
using namespace std;

void merge(int *data, int start, int end, int *result)
{
	int left_index = start;
	int right_index = (start + end) / 2 + 1;
	int result_index = start;
	while (left_index < (start + end) / 2 + 1 && right_index <= end)
	{
		if (data[left_index] <= data[right_index])
			result[result_index++] = data[left_index++];
		else
			result[result_index++] = data[right_index++];
	}
		while (left_index < (start + end) / 2 + 1)
			result[result_index++] = data[left_index++];
		while (right_index <= end)
			result[result_index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result)
{
	if (end - start == 1)
	{
		if (data[start] > data[end])
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if (end == start)
		return;
	else
	{
		merge_sort(data, start, (start + end) / 2, result);
		merge_sort(data, (start + end) / 2 + 1, end, result);
		merge(data, start, end, result);
		for (int i = start; i <= end; i++)
		{
			data[i] = result[i];
		}
	}
}

int main()
{
	int data1[] = { 9,6,7,22,20,33,16,20 };
	const int length = 8;
	int result1[length];
	cout << "Before sorted:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << data1[i] << " ";
	}
	cout << endl;
	cout << "After sorted:" << endl;
	merge_sort(data1, 0, length-1, result1);
	for (int i = 0; i < length; i++)
	{
		cout << data1[i] << " ";
	}
	cout << endl;

	return 0;
}
