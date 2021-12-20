#include <bits/stdc++.h>
using namespace std;
void quick_sort3(int *arr, int l, int r)
{

    int temp = arr[(l + r) / 2], i = l, j = r;
    do
    {
        while (arr[i] < temp)
            i++;
        while (arr[j] > temp)
            j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r)
        quick_sort3(arr, i, r);
    if (l < j)
        quick_sort3(arr, l, j);
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