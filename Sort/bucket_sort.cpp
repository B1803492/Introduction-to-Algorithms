#include <iostream>
#include <cstring>
using namespace std;

void bucket_sort(int* A, int Max, int arr_size)
{
    int B[Max+1];
    memset(B,0,sizeof(int)*(Max+1));
    for (int i = 0; i < arr_size; i++)
    {
        B[A[i]]++;
    }
    for (int i=0, j=0; i<=Max; i++)
    {
        while ((B[i]--) > 0)
            A[j++] = i;
    }
}

int main()
{
    int a[] = {8,2,3,4,3,1,6,7,9};

    int len = sizeof(a) / sizeof(a[0]);

    int max_a = a[0];

    for (int i = 1; i < len; i++)
    {
        if (max_a < a[i])
            max_a = a[i];
    }

    cout << "Before sort: ";
    for (auto c:a)
        cout << c << " ";
    cout << endl;

    bucket_sort(a,max_a,len);

    cout << "After sort:";
    for (auto c:a)
        cout << c << " ";
    cout << endl;

    return 0;
}
