#include <bits/stdc++.h>
using namespace std;
void quick_sort3(int *arr, int l, int r)
{
    r++;
    if (r-l <= 1)
        return;

    int i = l, j = r-1,pivot = rand()%(r-l)+l;

    while (i < j)
    {
        while (i < r && arr[i] <= arr[pivot])
        {
            i++;
        }
        while (arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            if (pivot == i || pivot == j)
                pivot = i + j - pivot;
        }
    }

    swap(arr[pivot], arr[j]);

    quick_sort3(arr, l, j);
    quick_sort3(arr, i, r-1);
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    quick_sort3(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}