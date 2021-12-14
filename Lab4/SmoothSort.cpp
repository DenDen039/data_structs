#include <bits/stdc++.h>
using namespace std;

int *LeonardoNums(int size)
{
    int limit_size = size;
    int *nums = new int[limit_size];
    nums[0] = 1;
    if (size > 1)
        nums[1] = 1;
    int i = 1;
    while (nums[i++] < size)
    {
        if (limit_size >= i)
        {
            limit_size += 10;
            int *temp = new int[limit_size];
            for (int i = 0; i < limit_size - 10; i++)
            {
                temp[i] = nums[i];
            }
            delete nums;
            nums = temp;
        }
        nums[i] = nums[i - 1] + nums[i - 2] + 1;
    }
    // for(int i = 0; i < limit_size;i++)
    //     cout << nums[i] << " ";
    // cout << endl;
    return nums;
}
void RestoreHeap(int heap_size, int *heap, int i, int *arr, int arr_size, int *leo_nums)
{
    int current = heap_size - 1;
    int k = heap[current];
    while (current > 0)
    {
        int j = i - leo_nums[k];
        if (arr[j] > arr[i] &&
            (k < 2 || arr[j] > arr[i - 1] && arr[j] > arr[i - 2]))
        {
            swap(arr[j], arr[i]);
            i = j;
            current--;
            k = heap[current];
        }
        else
            break;
    }
    while (k >= 2)
    {
        int t_r = i - 1, k_r = k - 2;
        int t_l = t_r - leo_nums[k_r], k_l = k - 1;
        if (arr[i] < arr[t_r] || arr[i] < arr[t_l])
            if (arr[t_r] > arr[t_l])
            {
                swap(arr[i], arr[t_r]);
                i = t_r;
                k = k_r;
            }
            else
            {
                swap(arr[i], arr[t_l]);
                i = t_l;
                k = k_l;
            }
        else
            break;
    }
}
void SmoothSort(int *arr, int size)
{
    int *leonardo_nums = LeonardoNums(size);
    int *heap = new int[2 * size];
    int cur_heap = 0;

    for (int i = 0; i < size; i++)
    {
        if (cur_heap >= 2 && heap[cur_heap - 1] + 1 == heap[cur_heap - 2])
        {
            cur_heap--;
            heap[cur_heap - 1]++;
        }
        else
        {
            if (cur_heap >= 1 && heap[cur_heap - 1] == 1)
            {
                heap[cur_heap++] = 0;
            }
            else
                heap[cur_heap++] = 1;
        }
        RestoreHeap(cur_heap, heap, i, arr, size, leonardo_nums);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if (heap[cur_heap - 1] < 2)
            cur_heap--;
        else
        {
            int k = heap[--cur_heap];
            int t_r = i - 1, k_r = k - 2;
            int t_l = t_r - leonardo_nums[k_r], k_l = k - 1;
            heap[cur_heap++] = k_l;
            RestoreHeap(cur_heap, heap, t_l, arr, size, leonardo_nums);
            heap[cur_heap++] = k_r;
            RestoreHeap(cur_heap, heap, t_r, arr, size, leonardo_nums);
        }
    }
}
int main()
{
    srand(time(0));
    system("clear");
    int size = 20;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size + 1;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SmoothSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}