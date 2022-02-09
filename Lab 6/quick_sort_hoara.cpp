#include <bits/stdc++.h>
using namespace std;
int partition2(int *arr, int l, int r)
{
    int pivot = arr[l],i = l-1,j = r+1;
    while(true){
        do{
            i++;
        }while(pivot > arr[i]);
        do{
            j--;
        }while(pivot < arr[j]);
        if(i  >=j)
            return j;
        swap(arr[i],arr[j]);
    }
}
void quick_sort2(int *arr, int l, int r)
{

    if (l < r)
    {
        int m = partition2(arr, l, r);
        quick_sort2(arr, l, m);
        quick_sort2(arr, m + 1, r);
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    quick_sort2(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}