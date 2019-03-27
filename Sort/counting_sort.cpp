// 计数排序，输入为整数。选择的辅助数组长度为max-min+1。
//似乎存在问题
#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<int>& arr)
{
	int len = arr.size();
	if (len == 0)
		return;

	//原始数组拷贝
	vector<int> tempArr(arr.begin(), arr.end());

	//查找min,max
	int min = tempArr[0], max = min;
	for (int i = 1; i < len; i++)
	{
		if (min > tempArr[i])
			min = tempArr[i];
		if (max < tempArr[i])
			max = tempArr[i];
	}

	//计算k值
	int k = max - min + 1;
	int count[] = { 0 };
	for (int i = 0; i < len; i++)
		++count[tempArr[i] - min];		//减去min，得到偏移量
	for (int i = 0; i < len; i++)
		count[i] += count[i - 1];		//表示小于等于每个数的个数
	for (int i = len - 1; i >= 0; i--)
		arr[--count[tempArr[i] - min]] = tempArr[i];

}

int main()
{
	vector<int> arr{ -1,3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6 };
	count_sort(arr);
	for (auto c : arr)
		cout << c << " ";
	cout << endl;

	return 0;
}
